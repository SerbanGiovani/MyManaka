// Ghidra pseudocode; not original source or compilable C.
// ev_a8bc01f3a18c25da8005c3e0ef758e3a0cebc1966165965c461b4938aac3d6dd

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__Destroy__06001063(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  code *pcVar3;
  
  if (DAT_182eb775e == '\0') {
    FUN_1802f2810(&DAT_182d57c08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d57be0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d598e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182eb775e = '\x01';
  }
  if (*(longlong *)(param_1 + 0x30) == 0) {
LAB_18042a2df:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  ExposureUnnoticed2_Object3D_NPC_Script_NpcComponentAccessor__Dispose__06001039
            (*(longlong *)(param_1 + 0x30),0);
  uVar2 = FUN_1802c43a0(DAT_182d57c08);
  FUN_180665bb0(uVar2,param_1,DAT_182d598e8,0);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_180993960(uVar2,DAT_182d57be0);
  lVar1 = *(longlong *)(param_1 + 0x28);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12f4 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f4 = '\x01';
  }
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec129b == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec129b = '\x01';
  }
  if (lVar1 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar1 + 0x10) != 0) {
      lVar1 = *(longlong *)(param_1 + 0x28);
      if (lVar1 == 0) goto LAB_18042a2df;
      pcVar3 = DAT_182ec1088;
      if ((DAT_182ec1088 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
         pcVar3 == (code *)0x0)) {
        uVar2 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar2,0);
      }
      DAT_182ec1088 = pcVar3;
      uVar2 = (*DAT_182ec1088)(lVar1);
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      FUN_181f43e80(uVar2,0);
    }
  }
  return;
}

