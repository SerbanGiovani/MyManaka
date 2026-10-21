// Ghidra pseudocode; not original source or compilable C.
// ev_5fb218b88f33effb011b674bcb6fff41ff35412e9b168813a698a0dc1bdc5d96

ulonglong ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationReceiver___CommonOnEndAnim_b__22_0__06000c68
                    (longlong param_1)

{
  ulonglong *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  int iVar4;
  ulonglong uVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  
  if ((*(longlong *)(param_1 + 0x40) != 0) &&
     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x68), lVar2 != 0)) {
    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAction__ChangeAction__06000c36
              (lVar2,0xffffffff,0);
    if ((*(longlong *)(param_1 + 0x40) != 0) &&
       (*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x160) != 0)) {
      if (cRam0000000182eb8429 == '\0') {
        FUN_1802f2810(&DAT_182d53aa8,0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d58378);
        LOCK();
        UNLOCK();
        cRam0000000182eb8429 = '\x01';
      }
      if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
          (uVar5 = *(ulonglong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), uVar5 == 0)) ||
         (*(longlong *)(uVar5 + 0x60) == 0)) {
code_r0x000180656a4b:
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      lVar2 = *(longlong *)(*(longlong *)(uVar5 + 0x60) + 0x1a0);
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        uVar5 = FUN_18035c820();
      }
      if (DAT_182ec12f4 == '\0') {
        uVar5 = FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        DAT_182ec12f4 = '\x01';
      }
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        uVar5 = FUN_18035c820();
      }
      if (DAT_182ec129b == '\0') {
        uVar5 = FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        DAT_182ec129b = '\x01';
      }
      if (lVar2 != 0) {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          uVar5 = FUN_18035c820();
        }
        if (*(longlong *)(lVar2 + 0x10) != 0) {
          if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
              (lVar2 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar2 != 0)) &&
             ((lVar2 = *(longlong *)(lVar2 + 0x60), lVar2 != 0 &&
              (lVar2 = *(longlong *)(lVar2 + 0x1a0), lVar2 != 0)))) {
            iVar6 = *(int *)(lVar2 + 0x20) + 1;
            iVar4 = *(int *)(lVar2 + 0x24);
            if (iVar6 <= *(int *)(lVar2 + 0x24)) {
              iVar4 = iVar6;
            }
            *(int *)(lVar2 + 0x20) = iVar4;
            uVar5 = DAT_182d58378;
            if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
                (lVar2 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar2 != 0))
               && (lVar2 = *(longlong *)(lVar2 + 0x60), lVar2 != 0)) {
              bVar8 = DAT_182eb5d50 == 0;
              *(undefined8 *)(lVar2 + 0x1a0) = 0;
              if (bVar8) {
                return uVar5;
              }
              uVar7 = (uint)(lVar2 + 0x1a0U >> 0xc);
              puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
              do {
                uVar3 = *puVar1;
                LOCK();
                uVar5 = *puVar1;
                bVar8 = uVar3 == uVar5;
                if (bVar8) {
                  *puVar1 = uVar3 | 1L << (uVar7 & 0x3f);
                  uVar5 = uVar3;
                }
                UNLOCK();
              } while (!bVar8);
              return uVar5;
            }
          }
          goto code_r0x000180656a4b;
        }
      }
      return uVar5;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

