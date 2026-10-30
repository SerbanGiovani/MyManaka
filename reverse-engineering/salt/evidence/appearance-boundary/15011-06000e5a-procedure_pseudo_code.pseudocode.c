// Ghidra pseudocode; not original source or compilable C.
// ev_2d7537ea5dfc6b8836ae79f7b6a6414c81d84568fd86694934267cb17d74210f

void ExposureUnnoticed2_Object3D_Player_Scripts_Other_BodyPaintController__Initialize__06000e5a
               (longlong param_1,undefined8 param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb7657 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb7657 = '\x01';
  }
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x18) = param_2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x18U >> 0xc);
    uVar4 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      LOCK();
      bVar6 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar2 != 0) {
    if (*(float *)(lVar2 + 0x17c) <= 0.0) {
      *(undefined4 *)(param_1 + 0x20) = 0;
      if (*(longlong *)(param_1 + 0x10) != 0) {
        *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x10) = 0xbf800000;
        return;
      }
    }
    else if (*(float *)(lVar2 + 0x17c) <= 24.0) {
      *(undefined4 *)(param_1 + 0x20) = 4;
      if (*(longlong *)(param_1 + 0x10) != 0) {
        *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x10) = 0;
        return;
      }
    }
    else {
      lVar3 = *(longlong *)(param_1 + 0x10);
      if (*(float *)(lVar2 + 0x17c) <= 60.0) {
        *(undefined4 *)(param_1 + 0x20) = 3;
        if (lVar3 != 0) {
          *(undefined4 *)(lVar3 + 0x10) = 0x3e800000;
          return;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x20) = 2;
        if (lVar3 != 0) {
          *(undefined4 *)(lVar3 + 0x10) = 0x3ecccccd;
          return;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

