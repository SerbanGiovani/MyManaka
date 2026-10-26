// Ghidra pseudocode; not original source or compilable C.
// ev_a09cd1303f3a3399f4304bd7dc22731f1559d1985f62d56fb5dc1228f8fbbefe

void ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__OnEnter__06001078(longlong param_1)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  
  if (DAT_182eb5480 == '\0') {
    FUN_1802f2810(&DAT_182d522a8);
    LOCK();
    UNLOCK();
    DAT_182eb5480 = '\x01';
  }
  puVar2 = *(undefined8 **)(DAT_182d522a8 + 0xb8);
  uVar1 = *(undefined4 *)(puVar2 + 1);
  *(undefined8 *)(param_1 + 0x2c) = *puVar2;
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__SetActiveNavAgent__0600107d
            (param_1,CONCAT71((int7)((ulonglong)puVar2 >> 8),1),0);
  return;
}

