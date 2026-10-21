// Ghidra pseudocode; not original source or compilable C.
// ev_2340cf99b7d9aa59e131ef04f01ec3bef4df9a3057035b19b8a641399d7ad2ed

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController___OnFoundStrangerEvent_g__Action_39_0__06000d69
               (void)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  bool bVar7;
  
  if (cRam0000000182eb83e8 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3e688);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3e690);
    LOCK();
    UNLOCK();
    cRam0000000182eb83e8 = '\x01';
  }
  if (*(int *)(lRam0000000182d3e690 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d3e690 + 0xb8) + 8);
  if (lVar4 == 0) {
    if (*(int *)(lRam0000000182d3e690 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar3 = **(undefined8 **)(lRam0000000182d3e690 + 0xb8);
    lVar4 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(lVar4,uVar3,uRam0000000182d3e688,0);
    *(longlong *)(*(longlong *)(lRam0000000182d3e690 + 0xb8) + 8) = lVar4;
    if (DAT_182eb5d50 != 0) {
      uVar6 = (uint)(*(longlong *)(lRam0000000182d3e690 + 0xb8) + 8U >> 0xc);
      uVar5 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
        LOCK();
        bVar7 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
        if (bVar7) {
          *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8) = uVar1 | 1L << (uVar6 & 0x3f);
        }
        UNLOCK();
      } while (!bVar7);
    }
  }
  if (DAT_182eb7aa3 == '\0') {
    FUN_1802f2810(&DAT_182d5f900,0x3f4ccccd,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f8f8);
    LOCK();
    UNLOCK();
    DAT_182eb7aa3 = '\x01';
  }
  lVar2 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
  if (lVar2 != 0) {
    lVar2 = *(longlong *)(lVar2 + 0x38);
    uVar3 = FUN_1802c43a0(DAT_182d5f900);
    DelayTimeModel___ctor__06001753(uVar3,lVar4,0x3f4ccccd,0,0);
    if (lVar2 != 0) {
      FUN_180006950(lVar2,uVar3);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

