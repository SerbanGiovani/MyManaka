// Ghidra pseudocode; not original source or compilable C.
// ev_dda8738ed6315da8710df7d0f8835fd037c4e03a8845192bd5f14cd0d909c913

void ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__SetMoveZero__0600107b(longlong param_1)

{
  undefined4 uVar1;
  
  if (DAT_182eb5480 == '\0') {
    FUN_1802f2810(&DAT_182d522a8);
    LOCK();
    UNLOCK();
    DAT_182eb5480 = '\x01';
  }
  uVar1 = *(undefined4 *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
  *(undefined8 *)(param_1 + 0x1c) = **(undefined8 **)(DAT_182d522a8 + 0xb8);
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  return;
}

