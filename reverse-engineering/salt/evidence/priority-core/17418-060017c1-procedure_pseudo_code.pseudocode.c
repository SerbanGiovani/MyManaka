// Ghidra pseudocode; not original source or compilable C.
// ev_a6fde1e610a69d585d3721f927e6166eed48ab4dc96f5bc5532eec4ff1abcad0

void ExposureUnnoticed2_Scripts_Base_SaveRapper__Save__060017c1
               (undefined8 param_1,undefined4 *param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  bool bVar8;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (cRam0000000182eb7adf == '\0') {
    FUN_1802f2810(0x182d5f460);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    cRam0000000182eb7adf = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d60278);
  }
  lVar5 = lRam0000000182d5f460;
  lVar3 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18);
  if (*(longlong *)(lRam0000000182d5f460 + 0x38) == 0) {
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
  uStack_18 = *param_2;
  uStack_14 = param_2[1];
  uStack_10 = param_2[2];
  uStack_c = param_2[3];
  FUN_180748e40(param_1,&uStack_18,lVar6,*(undefined8 *)(*(longlong *)(lVar5 + 0x38) + 8));
  return;
}

