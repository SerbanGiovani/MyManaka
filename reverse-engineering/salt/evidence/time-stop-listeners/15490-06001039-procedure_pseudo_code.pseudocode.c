// Ghidra pseudocode; not original source or compilable C.
// ev_3bf0dd79c7f1711a019ee5abd6e680186943e43bc9ab0bcf43543544de246c19

void ExposureUnnoticed2_Object3D_NPC_Script_NpcComponentAccessor__Dispose__06001039
               (longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  code *pcVar3;
  
  if (DAT_182eb7756 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182eb7756 = '\x01';
  }
  lVar1 = *(longlong *)(param_1 + 0x60);
  if (lVar1 == 0) {
LAB_180426071:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (DAT_182eb7788 == '\0') {
    FUN_1802f2810(&DAT_182d59320);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d592f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59300);
    LOCK();
    UNLOCK();
    DAT_182eb7788 = '\x01';
  }
  uVar2 = FUN_1802c43a0(DAT_182d59320);
  FUN_180665bb0(uVar2,lVar1,DAT_182d59300,0);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_180993960(uVar2,DAT_182d592f0);
  lVar1 = *(longlong *)(param_1 + 0x68);
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
      lVar1 = *(longlong *)(param_1 + 0x68);
      if (lVar1 == 0) goto LAB_180426071;
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

