// Ghidra pseudocode; not original source or compilable C.
// ev_9fb753be4015372257a6c31d6e87fa77c52e1a8c188e664b6b56c0ad941edf92

ulonglong ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAction__Initialize__06000c33
                    (longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  iVar5 = DAT_182eb5d50;
  *(longlong *)(param_1 + 0x30) = param_2;
  if (iVar5 != 0) {
    uVar4 = (uint)(param_1 + 0x30U >> 0xc);
    lVar1 = (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar7 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar4 & 0x3f);
      }
      UNLOCK();
      iVar5 = DAT_182eb5d50;
    } while (!bVar7);
  }
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(param_2 + 0x48);
  iVar6 = 0;
  if (iVar5 != 0) {
    uVar4 = (uint)(param_1 + 0x20U >> 0xc);
    lVar1 = (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar7 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar4 & 0x3f);
      }
      UNLOCK();
      iVar6 = DAT_182eb5d50;
    } while (!bVar7);
  }
  uVar3 = *(ulonglong *)(param_2 + 0x60);
  *(ulonglong *)(param_1 + 0x28) = uVar3;
  if (iVar6 != 0) {
    uVar4 = (uint)(param_1 + 0x28U >> 0xc);
    lVar1 = (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      bVar7 = uVar2 == uVar3;
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar4 & 0x3f);
        uVar3 = uVar2;
      }
      UNLOCK();
    } while (!bVar7);
  }
  return uVar3;
}

