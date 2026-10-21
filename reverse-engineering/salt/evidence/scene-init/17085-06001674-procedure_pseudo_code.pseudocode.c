// Ghidra pseudocode; not original source or compilable C.
// ev_55e779f71ba6b2a1eb9d4c4039a0f85e5f781aec1bba1006b83e47619d714122

void __c__DisplayClass6_0___TransStage_b__0__06001674(longlong param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  if (cRam0000000182eb7a41 == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535b8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a41 = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar3 != 0)) {
    *(undefined8 *)(lVar3 + 0x54) = 0;
    *(undefined8 *)(lVar3 + 0x5c) = 0;
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar3 = ExposureUnnoticed2_Master_Stage_MStage__Get__06001229(uVar1,0);
    if (lVar3 != 0) {
      uVar2 = *(undefined8 *)(lVar3 + 0x20);
      if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (cRam0000000182ec19a2 == '\0') {
        FUN_1802f2810(&DAT_182d535b8);
        LOCK();
        UNLOCK();
        cRam0000000182ec19a2 = '\x01';
      }
      if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      FUN_181f59470(uVar2,0,0);
      lVar3 = *(longlong *)(param_1 + 0x18);
      if (lVar3 != 0) {
        (**(code **)(lVar3 + 0x18))(*(undefined8 *)(lVar3 + 0x40),*(undefined8 *)(lVar3 + 0x28));
      }
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

