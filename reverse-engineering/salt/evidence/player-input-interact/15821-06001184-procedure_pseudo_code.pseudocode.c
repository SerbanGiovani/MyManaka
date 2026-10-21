// Ghidra pseudocode; not original source or compilable C.
// ev_d8c9ebe17f0cde9fc7a1fbb0f7ebea092ee33ee6b8e9446706eec78b5767f6e9

void ExposureUnnoticed2_Object3D_InteractArea_InteractAreaController__OnTriggerExit__06001184
               (longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  code *pcVar3;
  longlong lVar4;
  undefined8 uVar5;
  bool bVar6;
  
  if (cRam0000000182eb77e1 == '\0') {
    FUN_1802f2810(0x182d5ab80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb77e1 = '\x01';
  }
  if (*(char *)(param_1 + 0x31) == '\0') {
    return;
  }
  if (param_2 != 0) {
    pcVar3 = DAT_182ec1088;
    if ((DAT_182ec1088 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
       pcVar3 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ec1088 = pcVar3;
    lVar4 = (*DAT_182ec1088)(param_2);
    if ((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
       (lVar2 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar2 != 0)) {
      lVar2 = *(longlong *)(lVar2 + 0x28);
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
      if (lVar4 != 0 || lVar2 != 0) {
        if (lVar2 == 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (lVar4 == 0) goto DAT_180453990;
          bVar6 = *(longlong *)(lVar4 + 0x10) == 0;
        }
        else if (lVar4 == 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          bVar6 = *(longlong *)(lVar2 + 0x10) == 0;
        }
        else {
          bVar6 = lVar4 == lVar2;
        }
        if (!bVar6) {
          return;
        }
      }
      uVar1 = *(undefined4 *)(param_1 + 0x20);
      *(undefined1 *)(param_1 + 0x31) = 0;
      if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
        FUN_18035c820();
      }
      ExposureUnnoticed2_Scripts_Base_InteractManager__Unregister__06001798(uVar1,param_1,0);
      return;
    }
  }
DAT_180453990:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

