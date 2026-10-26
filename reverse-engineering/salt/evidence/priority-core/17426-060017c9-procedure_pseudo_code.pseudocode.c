// Ghidra pseudocode; not original source or compilable C.
// ev_1e0e8dad78d494de84f978473212101f39f64d96fb4baf81d0783a41f6a3b6a8

undefined8 *
ExposureUnnoticed2_Scripts_Base_SaveRapper__Load__060017c9
          (undefined8 *param_1,undefined8 param_2,undefined8 *param_3)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  bool bVar8;
  undefined8 uStack_38;
  undefined4 uStack_30;
  undefined8 uStack_28;
  undefined4 uStack_20;
  
  if (cRam0000000182eb7ae4 == '\0') {
    FUN_1802f2810(0x182d5f438);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ae4 = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d60278);
  }
  lVar5 = lRam0000000182d5f438;
  lVar3 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18);
  if (*(longlong *)(lRam0000000182d5f438 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar5 + 0x38) == 0) {
      FUN_1803204f0(lVar5);
    }
  }
  lVar6 = FUN_1802c43a0(DAT_182d534a8);
  ES3Settings___ctor__060001ba(lVar6,1,0);
  if ((lVar3 != 0) && (bVar8 = DAT_182eb5d50 != 0, *(longlong *)(lVar6 + 0x18) = lVar3, bVar8)) {
    uVar7 = (uint)(lVar6 + 0x18U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
    do {
      uVar4 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar4 == uVar2) {
        *puVar1 = uVar4 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (uVar4 != uVar2);
  }
  uStack_30 = *(undefined4 *)(param_3 + 1);
  uStack_38 = *param_3;
  FUN_180746c20(&uStack_28,param_2,&uStack_38,lVar6,*(undefined8 *)(*(longlong *)(lVar5 + 0x38) + 8)
               );
  *param_1 = uStack_28;
  *(undefined4 *)(param_1 + 1) = uStack_20;
  return param_1;
}

