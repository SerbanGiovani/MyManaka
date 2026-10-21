// Ghidra pseudocode; not original source or compilable C.
// ev_0e256d8a6ad93171eff112cf0c97d2a10b93822e664a16919253eecf6268196c

void ExposureUnnoticed2_Scripts_UI_TitleSceneView__OnClickNewGame__060013a8(longlong param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  if (cRam0000000182eb78b4 == '\0') {
    FUN_1802f2810(0x182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bf40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bf38);
    LOCK();
    UNLOCK();
    cRam0000000182eb78b4 = '\x01';
  }
  *(undefined1 *)(param_1 + 0xb0) = 1;
  lVar5 = *(longlong *)(*(longlong *)(lRam0000000182d58398 + 0xb8) + 0x38);
  if (lVar5 == 0) {
code_r0x00018046fee3:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (*(char *)(lVar5 + 0xbd) == '\0') {
    if (*(int *)(lRam0000000182d5bfa0 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d5bfa0);
    }
    if (**(char **)(lRam0000000182d5bfa0 + 0xb8) == '\0') {
      uVar1 = *(undefined8 *)(param_1 + 0x38);
      uVar3 = FUN_1802c43a0(uRam0000000182d58368);
      FUN_1814df680(uVar3,param_1,uRam0000000182d5bf38,0);
      uVar4 = FUN_1802c43a0(uRam0000000182d58368);
      FUN_1814df680(uVar4,param_1,uRam0000000182d5bf40,0);
      if (cRam0000000182eb7b3f == '\0') {
        FUN_1802f2810(0x182d58238);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d61b40);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d61b38);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d53aa8);
        LOCK();
        UNLOCK();
        cRam0000000182eb7b3f = '\x01';
      }
      if (**(longlong **)(lRam0000000182d58238 + 0xb8) != 0) {
        uVar2 = *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x218);
        if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar5 = FUN_1809f1050(uVar2,uVar1,uRam0000000182d61b38);
        if ((lVar5 != 0) && (lVar5 = FUN_180735660(lVar5,uRam0000000182d61b40), lVar5 != 0)) {
          FUN_1804c4a70(lVar5,uVar3,uVar4,0);
          return;
        }
      }
      goto code_r0x00018046fee3;
    }
  }
  uVar1 = *(undefined8 *)(param_1 + 0x38);
  uVar3 = FUN_1802c43a0(uRam0000000182d58368);
  FUN_1814df680(uVar3,param_1,uRam0000000182d5bf40,0);
  FUN_1804c62c0(uVar1,0,0,uVar3,0);
  return;
}

