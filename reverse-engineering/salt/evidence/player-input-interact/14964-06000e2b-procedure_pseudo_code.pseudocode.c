// Ghidra pseudocode; not original source or compilable C.
// ev_41e5e3af0ac9ad8f80e4946a6dee56ac4acd3d86b11fd5a8b9649f9f99c418ed

ulonglong ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStateModel__Initialize__06000e2b
                    (longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  bool bVar7;
  
  if (cRam0000000182eb8448 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb8448 = '\x01';
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar1 != 0) {
    uVar3 = ExposureUnnoticed2_Master_Clothes_MClothes__Get__06001343
                      (*(undefined4 *)(lVar1 + 0x19c),0);
    bVar7 = DAT_182eb5d50 != 0;
    *(undefined8 *)(param_1 + 0x10) = uVar3;
    if (bVar7) {
      uVar6 = (uint)(param_1 + 0x10U >> 0xc);
      uVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
      do {
        uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
        LOCK();
        bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
        if (bVar7) {
          *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar5 | 1L << (uVar6 & 0x3f);
        }
        UNLOCK();
      } while (!bVar7);
    }
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar1 != 0) {
      uVar4 = ExposureUnnoticed2_Master_Rank_MRank__CalcCurrentRank__06001261
                        ((double)*(int *)(lVar1 + 0x1e8),0);
      bVar7 = DAT_182eb5d50 != 0;
      *(ulonglong *)(param_1 + 0x128) = uVar4;
      if (bVar7) {
        uVar6 = (uint)(param_1 + 0x128U >> 0xc);
        uVar5 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
          LOCK();
          uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
          bVar7 = uVar2 == uVar4;
          if (bVar7) {
            *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8) = uVar2 | 1L << (uVar6 & 0x3f);
            uVar4 = uVar2;
          }
          UNLOCK();
        } while (!bVar7);
      }
      return uVar4;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

