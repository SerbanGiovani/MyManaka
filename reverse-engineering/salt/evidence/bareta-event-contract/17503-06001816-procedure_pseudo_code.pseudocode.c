// Ghidra pseudocode; not original source or compilable C.
// ev_f29ed6d920add74d55b7f0b32782658512b78ba77e65b65d607d5600872354c6

void ExposureUnnoticed2_ObjectUI_SystemMenu_SystemMenuView___OnClickEmergencyEscape_b__15_1__06001816
               (undefined8 param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  bool bVar8;
  
  if (cRam0000000182eb7b18 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f218);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b18 = '\x01';
  }
  uVar6 = FUN_1802c43a0(DAT_182d58368);
  FUN_1814df680(uVar6,param_1,uRam0000000182d5f218,0);
  if (DAT_182eb7aa1 == '\0') {
    FUN_1802f2810(&DAT_182d5f910,1,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f908);
    LOCK();
    UNLOCK();
    DAT_182eb7aa1 = '\x01';
  }
  lVar4 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
  if (lVar4 != 0) {
    lVar4 = *(longlong *)(lVar4 + 0x20);
    lVar5 = FUN_1802c43a0(DAT_182d5f910);
    bVar8 = DAT_182eb5d50 != 0;
    *(undefined8 *)(lVar5 + 0x10) = uVar6;
    if (bVar8) {
      uVar7 = (uint)(lVar5 + 0x10U >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
      do {
        uVar3 = *puVar1;
        LOCK();
        uVar2 = *puVar1;
        if (uVar3 == uVar2) {
          *puVar1 = uVar3 | 1L << (uVar7 & 0x3f);
        }
        UNLOCK();
      } while (uVar3 != uVar2);
    }
    *(undefined4 *)(lVar5 + 0x18) = 1;
    if (lVar4 != 0) {
      FUN_1800068f0(lVar4,lVar5);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

