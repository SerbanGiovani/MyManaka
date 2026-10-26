// Ghidra pseudocode; not original source or compilable C.
// ev_fb2706a8cd177542fe07e6fd739b9d298bf50f03962bebba0926ac11e7c5b1ac

ulonglong ES3Settings___ctor__060001ba(longlong param_1,char param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  if (DAT_182eb7556 == '\0') {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d531f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52728);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52720);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52718);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52710);
    LOCK();
    UNLOCK();
    DAT_182eb7556 = '\x01';
  }
  iVar5 = DAT_182eb5d50;
  *(undefined8 *)(param_1 + 0x18) = DAT_182d52718;
  if (iVar5 != 0) {
    uVar6 = (uint)(param_1 + 0x18U >> 0xc);
    lVar3 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar3);
      LOCK();
      bVar7 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar3);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar3) = uVar4 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
      iVar5 = DAT_182eb5d50;
    } while (!bVar7);
  }
  *(undefined8 *)(param_1 + 0x28) = DAT_182d52710;
  if (iVar5 != 0) {
    uVar6 = (uint)(param_1 + 0x28U >> 0xc);
    lVar3 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar3);
      LOCK();
      bVar7 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar3);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar3) = uVar4 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  *(undefined1 *)(param_1 + 0x38) = 1;
  *(undefined4 *)(param_1 + 0x3c) = 0x800;
  uVar2 = FUN_1816df430(0);
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x40) = uVar2;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0x40U >> 0xc);
    lVar3 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar3);
      LOCK();
      bVar7 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar3);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar3) = uVar4 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  *(undefined1 *)(param_1 + 0x48) = 1;
  *(undefined2 *)(param_1 + 0x4a) = 0x101;
  *(undefined4 *)(param_1 + 0x50) = 2;
  *(undefined4 *)(param_1 + 0x54) = 0x40;
  lVar3 = FUN_1802c36c0(DAT_182d531f8,2);
  if (lVar3 == 0) {
LAB_1803cd2dd:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  FUN_180002cd0(lVar3,0,DAT_182d52728);
  uVar4 = FUN_180002cd0(lVar3,1,DAT_182d52720);
  bVar7 = DAT_182eb5d50 != 0;
  *(longlong *)(param_1 + 0x58) = lVar3;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0x58U >> 0xc);
    lVar3 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar3);
      LOCK();
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar3);
      bVar7 = uVar1 == uVar4;
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar3) = uVar1 | 1L << (uVar6 & 0x3f);
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar7);
  }
  if (param_2 != '\0') {
    if (*(int *)(DAT_182d534a8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar3 = ES3Settings__get_defaultSettings__060001b0(0);
    uVar4 = 0;
    if (lVar3 != 0) {
      if (*(int *)(DAT_182d534a8 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d534a8);
      }
      if (**(longlong **)(DAT_182d534a8 + 0xb8) == 0) goto LAB_1803cd2dd;
      uVar4 = ES3Settings__CopyInto__060001bd(**(longlong **)(DAT_182d534a8 + 0xb8),param_1,0);
    }
  }
  return uVar4;
}

