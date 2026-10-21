// Ghidra pseudocode; not original source or compilable C.
// ev_efeb9e401e8dd4f5b2cda9c6ecba77b7d79e7a7389c90af453c348d60b2d01d6

ulonglong ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__Initialize__06000c74
                    (longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  int iVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (param_2 != 0) {
    *(undefined8 *)(param_1 + 0x38) = *(undefined8 *)(param_2 + 0x60);
    if (DAT_182eb5d50 != 0) {
      uVar5 = (uint)(param_1 + 0x38U >> 0xc);
      uVar3 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
      do {
        uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
        LOCK();
        bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
        if (bVar6) {
          *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8) = uVar4 | 1L << (ulonglong)(uVar5 & 0x3f);
        }
        UNLOCK();
      } while (!bVar6);
    }
    iVar2 = DAT_182eb5d50;
    *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)(param_2 + 0x10);
    if (iVar2 != 0) {
      uVar5 = (uint)(param_1 + 0x30U >> 0xc);
      uVar3 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
      do {
        uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
        LOCK();
        bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
        if (bVar6) {
          *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8) = uVar4 | 1L << (ulonglong)(uVar5 & 0x3f);
        }
        UNLOCK();
        iVar2 = DAT_182eb5d50;
      } while (!bVar6);
    }
    if (*(longlong *)(param_1 + 0x60) != 0) {
      *(undefined4 *)(*(longlong *)(param_1 + 0x60) + 0x1c) = 0x3f800000;
      uVar3 = *(ulonglong *)(param_1 + 0xb8);
      if (uVar3 != 0) {
        *(undefined4 *)(uVar3 + 0x10) = 0x3f800000;
        *(undefined4 *)(param_1 + 0x24) = 0x3f800000;
        *(longlong *)(param_1 + 0x40) = param_2;
        if (iVar2 != 0) {
          uVar5 = (uint)(param_1 + 0x40U >> 0xc);
          uVar4 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
          do {
            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
            LOCK();
            uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
            bVar6 = uVar1 == uVar3;
            if (bVar6) {
              *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
              uVar3 = uVar1;
            }
            UNLOCK();
          } while (!bVar6);
        }
        return uVar3;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

