// Ghidra pseudocode; not original source or compilable C.
// ev_2cc125c970fe6b41fd702c67a1d7e64fe1a0a51d463a345713ffa0b9a539876f

void ExposureUnnoticed2_Object3D_InteractArea_InteractAreaController__OnTriggerEnter__06001183
               (longlong param_1,longlong param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  code *pcVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  uint uVar9;
  bool bVar10;
  
  if (cRam0000000182eb77e0 == '\0') {
    FUN_1802f2810(0x182d5ab80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb77e0 = '\x01';
  }
  if (*(char *)(param_1 + 0x31) != '\0') {
    return;
  }
  if (param_2 != 0) {
    pcVar5 = DAT_182ec1088;
    if ((DAT_182ec1088 == (code *)0x0) &&
       (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
       pcVar5 == (code *)0x0)) {
      uVar8 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar8,0);
    }
    DAT_182ec1088 = pcVar5;
    lVar6 = (*DAT_182ec1088)(param_2);
    if ((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
       (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 != 0)) {
      lVar7 = *(longlong *)(lVar7 + 0x28);
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
      if (lVar6 != 0 || lVar7 != 0) {
        if (lVar7 == 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (lVar6 == 0) goto DAT_1804537a2;
          bVar10 = *(longlong *)(lVar6 + 0x10) == 0;
        }
        else if (lVar6 == 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          bVar10 = *(longlong *)(lVar7 + 0x10) == 0;
        }
        else {
          bVar10 = lVar6 == lVar7;
        }
        if (!bVar10) {
          return;
        }
      }
      uVar3 = *(undefined4 *)(param_1 + 0x20);
      *(undefined1 *)(param_1 + 0x31) = 1;
      if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (cRam0000000182eb7abc == '\0') {
        FUN_1802f2810(0x182d5ab80);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5f5e8);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5f5e0);
        LOCK();
        UNLOCK();
        cRam0000000182eb7abc = '\x01';
      }
      if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar6 = **(longlong **)(lRam0000000182d5ab80 + 0xb8);
      lVar7 = FUN_1802c43a0(uRam0000000182d5f5e8);
      if (lVar7 != 0) {
        bVar10 = DAT_182eb5d50 != 0;
        *(undefined4 *)(lVar7 + 0x10) = uVar3;
        *(longlong *)(lVar7 + 0x18) = param_1;
        if (bVar10) {
          uVar9 = (uint)(lVar7 + 0x18U >> 0xc);
          puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
          do {
            uVar4 = *puVar1;
            LOCK();
            uVar2 = *puVar1;
            if (uVar4 == uVar2) {
              *puVar1 = uVar4 | 1L << (uVar9 & 0x3f);
            }
            UNLOCK();
          } while (uVar4 != uVar2);
        }
        if (lVar6 != 0) {
          FUN_180006a10(lVar6,lVar7);
          return;
        }
      }
    }
  }
DAT_1804537a2:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

