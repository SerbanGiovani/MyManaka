using System;
using UnityEngine;

namespace ReconstructedManaka {
    [Serializable] public sealed class KeyboardButtons {
        public bool w, a, s, d, shift, c, f5, f6;
        public static KeyboardButtons Read(int edge) {
            return new KeyboardButtons { w = Read(KeyCode.W, edge), a = Read(KeyCode.A, edge), s = Read(KeyCode.S, edge), d = Read(KeyCode.D, edge), shift = Read(KeyCode.LeftShift, edge), c = Read(KeyCode.C, edge), f5 = Read(KeyCode.F5, edge), f6 = Read(KeyCode.F6, edge) };
        }
        static bool Read(KeyCode key, int edge) { return edge < 0 ? Input.GetKeyUp(key) : edge > 0 ? Input.GetKeyDown(key) : Input.GetKey(key); }
    }
    [Serializable] public sealed class LocomotionInput {
        public string inputSource, inputProvenance;
        public bool simulated, focused;
        public Vector2 axes, unityAxes;
        public KeyboardButtons keys, keyDown, keyUp;
        public bool sprint, crouch;
    }

    [RequireComponent(typeof(CharacterController))]
    public sealed class PlayerMotor : MonoBehaviour {
        // Original serialized base speeds; acceleration/rotation/gravity remain explicit
        // reconstruction choices because the complete native integrator is not recovered.
        public float walkSpeed = 1.1f, jogSpeed = 2.4f, crouchSpeed = .6f;
        public float acceleration = 6f, deceleration = 8f, turnDegreesPerSecond = 420f, gravity = -18f;
        public Transform cameraBasis;
        public string InputProvenance = "undeclared_keyboard_device";
        public bool InputEnabled { get; set; }
        public bool GroundedSeen { get; private set; }
        public int InputSamples { get; private set; }
        public int BelowCollisions { get; private set; }
        public int SideCollisions { get; private set; }
        public float TravelledDistance { get; private set; }
        public float CurrentSpeed { get; private set; }
        public float TargetSpeed { get; private set; }
        public float AnimationSpeed { get; private set; }
        public bool SprintActive { get; private set; }
        public bool IsCrouch { get; private set; }
        public Vector3 PositionBeforeStep { get; private set; }
        public Vector3 PositionAfterStep { get; private set; }
        public Vector3 MotionDirection { get; private set; }
        public float LastDeltaTime { get; private set; }
        public LocomotionInput CurrentInput { get; private set; }
        public CollisionFlags LastCollisionFlags { get; private set; }
        CharacterController controller;
        bool simulated, simulatedSprint, simulatedCrouch;
        Vector2 simulatedAxes;
        float vertical;
        void Awake() { controller = GetComponent<CharacterController>(); PositionBeforeStep = PositionAfterStep = transform.position; }
        public void SetSimulatedInput(bool enabled, Vector2 axes, bool jump = false, bool sprint = false, bool crouch = false) {
            simulated = enabled; simulatedAxes = axes; simulatedSprint = sprint; simulatedCrouch = crouch;
            // jump is retained for source compatibility. Original input has no Jump action.
        }
        void Update() {
            Vector2 unityAxes = new Vector2(Input.GetAxisRaw("Horizontal"), Input.GetAxisRaw("Vertical"));
            var keys = KeyboardButtons.Read(0); var down = KeyboardButtons.Read(1); var up = KeyboardButtons.Read(-1);
            if (!simulated && down.c && InputEnabled) IsCrouch = !IsCrouch;
            if (simulated) IsCrouch = simulatedCrouch;
            CurrentInput = new LocomotionInput {
                inputSource = simulated ? "simulated-axes" : "unity-legacy", inputProvenance = simulated ? "internal_acceptance_axes" : InputProvenance,
                simulated = simulated, focused = Application.isFocused, axes = simulated ? simulatedAxes : unityAxes, unityAxes = unityAxes,
                keys = keys, keyDown = down, keyUp = up, sprint = simulated ? simulatedSprint : keys.shift, crouch = IsCrouch
            };
            if (!InputEnabled || !controller.enabled) { PositionBeforeStep = PositionAfterStep = transform.position; return; }
            StepFromInput(CurrentInput.axes, false, CurrentInput.sprint, Mathf.Min(Time.deltaTime, .05f));
        }
        public void StepFromInput(Vector2 axes, bool jump, bool sprint, float deltaTime) {
            if (deltaTime <= 0 || !controller.enabled) return;
            // Original Resolve normalizes when squared magnitude >= .5, preserving
            // smaller analog values. Keyboard diagonal axes therefore stay unit length.
            if (axes.sqrMagnitude >= .5f) axes.Normalize(); InputSamples++; LastDeltaTime = deltaTime;
            bool grounded = controller.isGrounded;
            if (grounded) { GroundedSeen = true; if (vertical < 0) vertical = -2f; }
            Vector3 forward = cameraBasis ? Vector3.ProjectOnPlane(cameraBasis.forward, Vector3.up).normalized : Vector3.forward;
            Vector3 right = cameraBasis ? Vector3.ProjectOnPlane(cameraBasis.right, Vector3.up).normalized : Vector3.right;
            Vector3 motion = forward * axes.y + right * axes.x;
            SprintActive = sprint && !IsCrouch && motion.sqrMagnitude > .0001f;
            float baseSpeed = IsCrouch ? crouchSpeed : SprintActive ? jogSpeed : walkSpeed;
            TargetSpeed = baseSpeed * Mathf.Clamp01(axes.magnitude);
            CurrentSpeed = Mathf.MoveTowards(CurrentSpeed, TargetSpeed, (TargetSpeed > CurrentSpeed ? acceleration : deceleration) * deltaTime);
            if (motion.sqrMagnitude > .0001f) {
                MotionDirection = motion.normalized;
                transform.rotation = Quaternion.RotateTowards(transform.rotation, Quaternion.LookRotation(MotionDirection), turnDegreesPerSecond * deltaTime);
            }
            AnimationSpeed = CurrentSpeed;
            vertical += gravity * deltaTime;
            PositionBeforeStep = transform.position;
            LastCollisionFlags = controller.Move((MotionDirection * CurrentSpeed + Vector3.up * vertical) * deltaTime);
            PositionAfterStep = transform.position;
            if ((LastCollisionFlags & CollisionFlags.Below) != 0) { GroundedSeen = true; BelowCollisions++; if (vertical < 0) vertical = -2f; }
            if ((LastCollisionFlags & CollisionFlags.Sides) != 0) SideCollisions++;
            TravelledDistance += Vector3.ProjectOnPlane(PositionAfterStep - PositionBeforeStep, Vector3.up).magnitude;
        }
    }

    public sealed class FollowCamera : MonoBehaviour {
        public Transform target;
        public float distance = 2.6f;
        float yaw, pitch = 18f;
        public void Bind(Transform actor) { target = actor; yaw = actor.eulerAngles.y; }
        void LateUpdate() {
            if (!target) return;
            if (Input.GetMouseButton(1)) { yaw += Input.GetAxisRaw("Mouse X") * 2.8f; pitch = Mathf.Clamp(pitch - Input.GetAxisRaw("Mouse Y") * 2.8f, -10f, 60f); }
            Vector3 pivot = target.position + Vector3.up * 1.35f;
            Vector3 direction = Quaternion.Euler(pitch, yaw, 0) * Vector3.back;
            float actualDistance = distance;
            if (Physics.SphereCast(pivot, .1f, direction, out RaycastHit hit, distance, ~0, QueryTriggerInteraction.Ignore)) actualDistance = Mathf.Max(.25f, hit.distance - .1f);
            transform.position = pivot + direction * actualDistance; transform.LookAt(pivot);
        }
    }
}
