// Ghidra pseudocode; not original source or compilable C.
// ev_d47da7098b415123f3d5153148ec02aa4520be1c114b38c5f6e832ea9aa44455

void ExposureUnnoticed2_Object3D_Portal_PortalController__OnTriggerExit__06000bf6
               (longlong param_1,longlong param_2)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  bool bVar5;
  
  if (cRam0000000182eb8346 == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb8346 = '\x01';
  }
  if (param_2 != 0) {
    pcVar2 = DAT_182ec1088;
    if ((DAT_182ec1088 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
       pcVar2 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec1088 = pcVar2;
    lVar3 = (*DAT_182ec1088)(param_2);
    if ((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
       (lVar1 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar1 != 0)) {
      lVar1 = *(longlong *)(lVar1 + 0x28);
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
      if (lVar3 != 0 || lVar1 != 0) {
        if (lVar1 == 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (lVar3 == 0) goto code_r0x00018061e026;
          bVar5 = *(longlong *)(lVar3 + 0x10) == 0;
        }
        else if (lVar3 == 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          bVar5 = *(longlong *)(lVar1 + 0x10) == 0;
        }
        else {
          bVar5 = lVar3 == lVar1;
        }
        if (!bVar5) {
          return;
        }
      }
      if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
         (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar3 != 0)) {
        if (*(char *)(lVar3 + 0x11) == '\0') {
          *(undefined1 *)(param_1 + 0x51) = 0;
        }
        return;
      }
    }
  }
code_r0x00018061e026:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

