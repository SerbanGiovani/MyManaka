// Ghidra pseudocode; not original source or compilable C.
// ev_f63e93759f453af882a7c267c5cc27638dd8f3d0563df0e68030504e967d45c8

undefined8 ES3Settings__get_unencryptedUncompressedSettings__060001b1(void)

{
  ulonglong uVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  bool bVar8;
  undefined4 uStackX_10;
  uint uStackX_14;
  
  if (cRam0000000182eb7552 == '\0') {
    FUN_1802f2810(&DAT_182d52798);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52790);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52d88);
    LOCK();
    UNLOCK();
    cRam0000000182eb7552 = '\x01';
  }
  if (*(int *)(DAT_182d534a8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (*(longlong *)(*(longlong *)(DAT_182d534a8 + 0xb8) + 0x10) != 0) goto code_r0x0001803cc529;
  plVar2 = (longlong *)FUN_1802c36c0(DAT_182d52d88,2);
  lVar4 = DAT_182d52790;
  lVar5 = 0;
  uStackX_10 = 0;
  if (*(int *)(DAT_182d52790 + 0x28) < 0) {
    if ((*(longlong *)(DAT_182d52790 + 0x60) == 0) ||
       (lVar3 = lVar5, (*(byte *)(DAT_182d52790 + 0x135) & 8) == 0)) {
      lVar3 = FUN_1802c43a0(DAT_182d52790);
      FUN_1803a8090(lVar3 + 0x10,&uStackX_10,(longlong)*(int *)(lVar4 + 0xf8) + -0x10);
      if (DAT_182eb5d50 != 0) {
        uVar7 = (uint)(lVar3 + 0x10U >> 0xc);
        lVar4 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
          LOCK();
          bVar8 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
          if (bVar8) {
            *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar1 | 1L << (uVar7 & 0x3f);
          }
          UNLOCK();
        } while (!bVar8);
      }
    }
  }
  else {
    lVar3 = (ulonglong)uStackX_14 << 0x20;
  }
  if (plVar2 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if ((lVar3 != 0) && (lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)(*plVar2 + 0x40)), lVar4 == 0)) {
    uVar6 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar6,0);
  }
  FUN_180002cd0(plVar2,0,lVar3);
  lVar4 = DAT_182d52798;
  uStackX_10 = 0;
  if (*(int *)(DAT_182d52798 + 0x28) < 0) {
    if ((*(longlong *)(DAT_182d52798 + 0x60) == 0) || ((*(byte *)(DAT_182d52798 + 0x135) & 8) == 0))
    {
      lVar5 = FUN_1802c43a0(DAT_182d52798);
      FUN_1803a8090(lVar5 + 0x10,&uStackX_10,(longlong)*(int *)(lVar4 + 0xf8) + -0x10);
      if (DAT_182eb5d50 != 0) {
        uVar7 = (uint)(lVar5 + 0x10U >> 0xc);
        lVar4 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
          LOCK();
          bVar8 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
          if (bVar8) {
            *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar1 | 1L << (uVar7 & 0x3f);
          }
          UNLOCK();
        } while (!bVar8);
      }
      goto code_r0x0001803cc459;
    }
  }
  else {
    lVar5 = (ulonglong)uStackX_14 << 0x20;
code_r0x0001803cc459:
    if ((lVar5 != 0) && (lVar4 = FUN_1802c42e0(lVar5,*(undefined8 *)(*plVar2 + 0x40)), lVar4 == 0))
    {
      uVar6 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar6,0);
    }
  }
  FUN_180002cd0(plVar2,1,lVar5);
  uVar6 = FUN_1802c43a0(DAT_182d534a8);
  ES3Settings___ctor__060001b7(uVar6,plVar2,0);
  if (*(int *)(DAT_182d534a8 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d534a8);
  }
  *(undefined8 *)(*(longlong *)(DAT_182d534a8 + 0xb8) + 0x10) = uVar6;
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)(*(longlong *)(DAT_182d534a8 + 0xb8) + 0x10U >> 0xc);
    lVar5 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
      LOCK();
      bVar8 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar1 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
code_r0x0001803cc529:
  if (*(int *)(DAT_182d534a8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  return *(undefined8 *)(*(longlong *)(DAT_182d534a8 + 0xb8) + 0x10);
}

