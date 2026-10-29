// Ghidra pseudocode; not original source or compilable C.
// ev_2b5e8a1b081b46293e926365de458681da6555cab555bb1af666a7821354b0fc

undefined8 *
ExposureUnnoticed2_Object3D_ScenePlops_Elevator_ElevatorController__get_PushBounds__06000acd
          (undefined8 *param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_2 + 100);
  uVar1 = *(undefined8 *)(param_2 + 0x6c);
  *param_1 = *(undefined8 *)(param_2 + 0x5c);
  param_1[1] = uVar2;
  param_1[2] = uVar1;
  return param_1;
}

