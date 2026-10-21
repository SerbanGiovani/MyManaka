// Ghidra pseudocode; not original source or compilable C.
// ev_1a5a924def37ca4c0ff73527b5e63adaf0b20edf61147a30e5c396d816785ad9

void __c___OnClickLoad_b__8_0__0600195d(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  bool bVar10;
  
  if (cRam0000000182eb7bfc == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d6a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63700);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63720);
    LOCK();
    UNLOCK();
    cRam0000000182eb7bfc = '\x01';
  }
  if (DAT_182eb54a2 == '\0') {
    FUN_1802f2810(&DAT_182d5bcb8);
    LOCK();
    UNLOCK();
    DAT_182eb54a2 = '\x01';
  }
  if (**(longlong **)(DAT_182d5bcb8 + 0xb8) != 0) {
    uVar5 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__CollectAll__06001509
                      (**(longlong **)(DAT_182d5bcb8 + 0xb8),0);
    **(undefined1 **)(lRam0000000182d5d6a0 + 0xb8) = uVar5;
    lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar8 != 0) {
      *(undefined4 *)(lVar8 + 0x1c4) = 0;
      lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar8 != 0) {
        *(undefined4 *)(lVar8 + 0x1c8) = 10;
        ExposureUnnoticed2_Scripts_InGame_SaveManager__Save__06001601(3,0xffffffff,0,0);
        if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
           (lVar8 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar8 != 0)) {
          *(undefined1 *)(lVar8 + 0x10) = 1;
          ExposureUnnoticed2_Scripts_InGame_SaveManager__Load__06001602
                    (3,**(undefined4 **)(lRam0000000182d60190 + 0xb8),0);
          if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
            FUN_18035c820(DAT_182d58080);
          }
          uVar3 = *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x18);
          if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
            FUN_18035c820();
          }
          ExposureUnnoticed2_Scripts_Base_EventManager__Broadcast__06001716(uVar3,0);
          if (*(int *)(lRam0000000182d63720 + 0xe0) == 0) {
            FUN_18035c820();
          }
          lVar8 = *(longlong *)(*(longlong *)(lRam0000000182d63720 + 0xb8) + 8);
          if (lVar8 == 0) {
            if (*(int *)(lRam0000000182d63720 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar3 = **(undefined8 **)(lRam0000000182d63720 + 0xb8);
            lVar8 = FUN_1802c43a0(DAT_182d58368);
            FUN_1814df680(lVar8,uVar3,uRam0000000182d63700,0);
            *(longlong *)(*(longlong *)(lRam0000000182d63720 + 0xb8) + 8) = lVar8;
            if (DAT_182eb5d50 != 0) {
              uVar9 = (uint)(*(longlong *)(lRam0000000182d63720 + 0xb8) + 8U >> 0xc);
              puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
              do {
                uVar4 = *puVar1;
                LOCK();
                uVar2 = *puVar1;
                if (uVar4 == uVar2) {
                  *puVar1 = uVar4 | 1L << (uVar9 & 0x3f);
                }
                UNLOCK();
              } while (uVar4 != uVar2);
            }
          }
          if (DAT_182eb7aa1 == '\0') {
            FUN_1802f2810(&DAT_182d5f910,1,0);
            LOCK();
            UNLOCK();
            FUN_1802f2810(&DAT_182d5f908);
            LOCK();
            UNLOCK();
            DAT_182eb7aa1 = '\x01';
          }
          lVar6 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
          if (lVar6 != 0) {
            lVar6 = *(longlong *)(lVar6 + 0x20);
            lVar7 = FUN_1802c43a0(DAT_182d5f910);
            bVar10 = DAT_182eb5d50 != 0;
            *(longlong *)(lVar7 + 0x10) = lVar8;
            if (bVar10) {
              uVar9 = (uint)(lVar7 + 0x10U >> 0xc);
              puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
              do {
                uVar4 = *puVar1;
                LOCK();
                uVar2 = *puVar1;
                if (uVar4 == uVar2) {
                  *puVar1 = uVar4 | 1L << (uVar9 & 0x3f);
                }
                UNLOCK();
              } while (uVar4 != uVar2);
            }
            *(undefined4 *)(lVar7 + 0x18) = 1;
            if (lVar6 != 0) {
              FUN_1800068f0(lVar6,lVar7);
              return;
            }
          }
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

