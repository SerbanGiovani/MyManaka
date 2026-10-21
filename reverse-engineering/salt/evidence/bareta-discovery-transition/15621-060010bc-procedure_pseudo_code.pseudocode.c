// Ghidra pseudocode; not original source or compilable C.
// ev_4c0a4ba1ef12f2c92e64b6ab930ffcc6281810a3a26e03c00b8e066c138af51c

void ExposureUnnoticed2_Object3D_NPC_Script_NpcStrangenessManager__Initialize__060010bc
               (longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  ulonglong uVar6;
  uint uVar7;
  bool bVar8;
  
  if (DAT_182eb7787 == '\0') {
    FUN_1802f2810(&DAT_182d59320);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59310);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59300);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59660);
    LOCK();
    UNLOCK();
    DAT_182eb7787 = '\x01';
  }
  iVar4 = DAT_182eb5d50;
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(param_2 + 0x70);
  if (iVar4 != 0) {
    uVar7 = (uint)(param_1 + 0x20U >> 0xc);
    uVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
      LOCK();
      bVar8 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar1 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
      iVar4 = DAT_182eb5d50;
    } while (!bVar8);
  }
  *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(param_2 + 0x68);
  iVar5 = 0;
  if (iVar4 != 0) {
    uVar7 = (uint)(param_1 + 0x18U >> 0xc);
    uVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
      LOCK();
      bVar8 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar1 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
      iVar5 = DAT_182eb5d50;
    } while (!bVar8);
  }
  *(longlong *)(param_1 + 0x28) = param_2;
  if (iVar5 != 0) {
    uVar7 = (uint)(param_1 + 0x28U >> 0xc);
    uVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
      LOCK();
      bVar8 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar1 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
  lVar2 = FUN_1802c43a0(DAT_182d59660);
  bVar8 = DAT_182eb5d50 != 0;
  *(longlong *)(param_1 + 0x10) = lVar2;
  *(undefined4 *)(lVar2 + 0x10) = 0x3e4ccccd;
  if (bVar8) {
    uVar7 = (uint)(param_1 + 0x10U >> 0xc);
    uVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
      LOCK();
      bVar8 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar1 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
  uVar3 = FUN_1802c43a0(DAT_182d59320);
  FUN_180665bb0(uVar3,param_1,DAT_182d59300,0);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_180993250(uVar3,0,DAT_182d59310);
  return;
}

