// Ghidra pseudocode; not original source or compilable C.
// ev_2b5bb2e9a5cbee065772db3a7444b9207c4cde712b67b78af22f39c69be2ab88

ulonglong ExposureUnnoticed2_Object3D_NPC_Script_NpcFoundStrangerState__Initialize__06001072
                    (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar4 = DAT_182eb5d50;
  *(undefined8 *)(param_1 + 0x18) = param_2;
  if (uVar4 != 0) {
    uVar5 = (uint)(param_1 + 0x18U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
      uVar4 = DAT_182eb5d50;
    } while (!bVar6);
  }
  uVar3 = (ulonglong)uVar4;
  *(undefined8 *)(param_1 + 0x20) = param_3;
  if (uVar4 != 0) {
    uVar4 = (uint)(param_1 + 0x20U >> 0xc);
    lVar1 = (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      bVar6 = uVar2 == uVar3;
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar4 & 0x3f);
        uVar3 = uVar2;
      }
      UNLOCK();
    } while (!bVar6);
  }
  return uVar3;
}

