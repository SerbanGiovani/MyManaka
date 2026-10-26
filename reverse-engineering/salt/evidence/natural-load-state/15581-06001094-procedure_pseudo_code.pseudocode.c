// Ghidra pseudocode; not original source or compilable C.
// ev_ef6236d9b22da8777f382e1b0bfe775e8d6b35a28785773f3550e8b0ab7113d5

void ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__OnDestroy__06001094(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  char cVar5;
  uint uVar6;
  undefined8 uStack_40;
  undefined4 *puStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  longlong lStack_18;
  
  if (cRam0000000182eb776c == '\0') {
    FUN_1802f2810(&DAT_182d595a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59598);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59590);
    LOCK();
    UNLOCK();
    FUN_1802f2810();
    LOCK();
    UNLOCK();
    cRam0000000182eb776c = '\x01';
  }
  if (*(char *)(param_1 + 100) != '\0') {
    FUN_180436590();
    lVar3 = *(longlong *)(param_1 + 0x38);
    if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (DAT_182eb5d50 != 0) {
      uVar6 = (uint)((ulonglong)&uStack_40 >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8);
      do {
        uVar4 = *puVar1;
        LOCK();
        uVar2 = *puVar1;
        if (uVar4 == uVar2) {
          *puVar1 = uVar4 | 1L << (uVar6 & 0x3f);
        }
        UNLOCK();
      } while (uVar4 != uVar2);
    }
    uStack_1c = *(undefined4 *)(lVar3 + 0x1c);
    uStack_30 = 0;
    uStack_40._0_4_ = (undefined4)lVar3;
    uStack_40._4_4_ = (undefined4)((ulonglong)lVar3 >> 0x20);
    uStack_28 = (undefined4)uStack_40;
    uStack_24 = uStack_40._4_4_;
    uStack_20 = 0;
    lStack_18 = 0;
    uStack_40 = 0;
    puStack_38 = &uStack_28;
    while (cVar5 = FUN_180f72b70(&uStack_28,DAT_182d59598), cVar5 != '\0') {
      if (lStack_18 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      ExposureUnnoticed2_Object3D_NPC_Script_NpcController__Destroy__06001063(lStack_18,0);
    }
  }
  return;
}

