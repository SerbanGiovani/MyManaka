// Ghidra pseudocode; not original source or compilable C.
// ev_e235b9a2d95c7070a35afd7a397e92b39009957d624696da1ca23db8a9fcc114

void ES3Settings__CopyInto__060001bd(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined1 *)(param_2 + 0x38) = *(undefined1 *)(param_1 + 0x38);
  iVar3 = DAT_182eb5d50;
  *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(param_1 + 0x18);
  if (iVar3 != 0) {
    uVar5 = (uint)(param_2 + 0x18U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
      iVar3 = DAT_182eb5d50;
    } while (!bVar6);
  }
  *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined8 *)(param_2 + 0x28) = *(undefined8 *)(param_1 + 0x28);
  iVar4 = 0;
  if (iVar3 != 0) {
    uVar5 = (uint)(param_2 + 0x28U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
      iVar4 = DAT_182eb5d50;
    } while (!bVar6);
  }
  *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined8 *)(param_2 + 0x40) = *(undefined8 *)(param_1 + 0x40);
  iVar3 = 0;
  if (iVar4 != 0) {
    uVar5 = (uint)(param_2 + 0x40U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
      iVar3 = DAT_182eb5d50;
    } while (!bVar6);
  }
  *(undefined1 *)(param_2 + 0x4a) = *(undefined1 *)(param_1 + 0x4a);
  *(undefined1 *)(param_2 + 0x4b) = *(undefined1 *)(param_1 + 0x4b);
  *(undefined4 *)(param_2 + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_2 + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined8 *)(param_2 + 0x58) = *(undefined8 *)(param_1 + 0x58);
  if (iVar3 != 0) {
    uVar5 = (uint)(param_2 + 0x58U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  *(undefined1 *)(param_2 + 0x48) = *(undefined1 *)(param_1 + 0x48);
  *(undefined4 *)(param_2 + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined1 *)(param_2 + 0x49) = *(undefined1 *)(param_1 + 0x49);
  return;
}

