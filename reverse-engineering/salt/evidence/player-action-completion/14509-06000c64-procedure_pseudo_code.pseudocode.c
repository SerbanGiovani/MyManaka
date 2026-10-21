// Ghidra pseudocode; not original source or compilable C.
// ev_65033ccbe50fcdb875817dec9cbe116448fd9a1bebb8d88247a6ecc03d69f809

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationReceiver__OnEndSitDown__06000c64
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
  
  if (cRam0000000182eb8386 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f380);
    LOCK();
    UNLOCK();
    cRam0000000182eb8386 = '\x01';
  }
  uVar6 = FUN_1802c43a0(DAT_182d58368);
  FUN_1814df680(uVar6,param_1,uRam0000000182d6f380,0);
  if (DAT_182eb7aa1 == '\0') {
    FUN_1802f2810(&DAT_182d5f910,4,0);
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
    *(undefined4 *)(lVar5 + 0x18) = 4;
    if (lVar4 != 0) {
      FUN_1800068f0(lVar4,lVar5);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

