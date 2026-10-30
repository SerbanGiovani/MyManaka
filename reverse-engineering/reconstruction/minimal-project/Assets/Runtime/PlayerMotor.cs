using UnityEngine;

namespace ReconstructedManaka {
    [RequireComponent(typeof(CharacterController))]
    public sealed class PlayerMotor : MonoBehaviour {
        public float speed = 2.2f, sprintMultiplier = 1.7f, gravity = -18f, jumpHeight = .7f;
        public Transform cameraBasis;
        public bool InputEnabled { get; set; }
        public bool GroundedSeen { get; private set; }
        public int InputSamples { get; private set; }
        public int BelowCollisions { get; private set; }
        public int SideCollisions { get; private set; }
        public float TravelledDistance { get; private set; }
        public CollisionFlags LastCollisionFlags { get; private set; }
        CharacterController controller;
        bool simulated, simulatedJump, simulatedSprint;
        Vector2 simulatedAxes;
        float vertical;
        void Awake() { controller = GetComponent<CharacterController>(); }
        public void SetSimulatedInput(bool enabled, Vector2 axes, bool jump = false, bool sprint = false) { simulated = enabled; simulatedAxes = axes; simulatedJump = jump; simulatedSprint = sprint; }
        void Update() {
            if (!InputEnabled || !controller.enabled) return;
            Vector2 axes = simulated ? simulatedAxes : new Vector2(Input.GetAxisRaw("Horizontal"), Input.GetAxisRaw("Vertical"));
            bool jump = simulated ? simulatedJump : Input.GetKeyDown(KeyCode.Space);
            bool sprint = simulated ? simulatedSprint : Input.GetKey(KeyCode.LeftShift);
            StepFromInput(axes, jump, sprint, Mathf.Min(Time.deltaTime, .05f));
        }
        // Hardware and acceptance axes both enter this exact CharacterController path.
        public void StepFromInput(Vector2 axes, bool jump, bool sprint, float deltaTime) {
            if (deltaTime <= 0 || !controller.enabled) return;
            axes = Vector2.ClampMagnitude(axes, 1f); InputSamples++;
            bool grounded = controller.isGrounded;
            if (grounded) { GroundedSeen = true; if (vertical < 0) vertical = -2f; }
            if (jump && grounded) vertical = Mathf.Sqrt(jumpHeight * -2f * gravity);
            Vector3 forward = cameraBasis ? Vector3.ProjectOnPlane(cameraBasis.forward, Vector3.up).normalized : Vector3.forward;
            Vector3 right = cameraBasis ? Vector3.ProjectOnPlane(cameraBasis.right, Vector3.up).normalized : Vector3.right;
            Vector3 motion = forward * axes.y + right * axes.x;
            if (motion.sqrMagnitude > .0001f) transform.rotation = Quaternion.RotateTowards(transform.rotation, Quaternion.LookRotation(motion), 420f * deltaTime);
            vertical += gravity * deltaTime;
            Vector3 before = transform.position;
            LastCollisionFlags = controller.Move((motion * speed * (sprint ? sprintMultiplier : 1f) + Vector3.up * vertical) * deltaTime);
            if ((LastCollisionFlags & CollisionFlags.Below) != 0) { GroundedSeen = true; BelowCollisions++; if (vertical < 0) vertical = -2f; }
            if ((LastCollisionFlags & CollisionFlags.Sides) != 0) SideCollisions++;
            TravelledDistance += Vector3.ProjectOnPlane(transform.position - before, Vector3.up).magnitude;
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
