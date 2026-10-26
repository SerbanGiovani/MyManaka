// Ghidra pseudocode; not original source or compilable C.
// ev_0c6b100f3ce28d6d177676e7ce0db87f432fdf383c3d5d1f1ceccc93f87c1545

void ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__ApplyReserveDropIfNeed__060014fe
               (undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  longlong lVar8;
  
  if (cRam0000000182eb796e == '\0') {
    FUN_1802f2810(0x182d5dfa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5df98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5df90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb796e = '\x01';
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar1 != 0) {
    lVar1 = *(longlong *)(lVar1 + 0x28);
    lVar5 = FUN_1802c43a0(uRam0000000182d5df90);
    FUN_1810d6200(lVar5,param_1,uRam0000000182d5dfa0,0);
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar3 = lRam0000000182d5df98;
    if (*(longlong *)(lRam0000000182d5df98 + 0x38) == 0) {
      FUN_1803204f0(lRam0000000182d5df98);
    }
    uVar7 = 0;
    if (lVar1 != 0) {
      lVar8 = 0x20;
      while( true ) {
        if (*(int *)(lVar1 + 0x18) <= (int)uVar7) {
          return;
        }
        if (*(uint *)(lVar1 + 0x18) <= uVar7) {
                    /* WARNING: Subroutine does not return */
          FUN_181640100(0);
        }
        lVar2 = *(longlong *)(lVar1 + 0x10);
        if (lVar2 == 0) break;
        if (*(uint *)(lVar2 + 0x18) <= uVar7) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dae0();
        }
        if (lVar5 == 0) break;
        cVar4 = (**(code **)(lVar5 + 0x18))
                          (*(undefined8 *)(lVar5 + 0x40),*(undefined8 *)(lVar8 + lVar2),
                           *(undefined8 *)(lVar5 + 0x28));
        if (cVar4 == '\0') {
          uVar7 = uVar7 + 1;
          lVar8 = lVar8 + 8;
        }
        else {
          uVar6 = FUN_180002d60(lVar1,uVar7);
          FUN_181274e50(lVar1,uVar6,*(undefined8 *)(*(longlong *)(lVar3 + 0x38) + 0x28));
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

