// Ghidra pseudocode; not original source or compilable C.
// ev_ad1989255f6ef07743440c0ba65ea0cc5f73ea679f6caa742540393552dbb481

void ExposureUnnoticed2_Object3D_ScenePlops_CommonDoor_CommonDoorController__OpenClose__06000b2c
               (longlong param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  
  if (DAT_182eb82c8 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6bd90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6bd88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6bd80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182eb82c8 = '\x01';
  }
  lVar2 = *(longlong *)(param_1 + 0x28);
  *(bool *)(param_1 + 0x59) = *(char *)(param_1 + 0x59) == '\0';
  if (*(int *)(DAT_182d6bd80 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d6bd80);
  }
  if (lVar2 != 0) {
    FUN_181eea680(lVar2,**(undefined4 **)(DAT_182d6bd80 + 0xb8),*(undefined1 *)(param_1 + 0x59),0);
    lVar2 = *(longlong *)(param_1 + 0x30);
    *(undefined1 *)(param_1 + 0x5a) = 1;
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec12f4 == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec12f4 = '\x01';
    }
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec129b == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec129b = '\x01';
    }
    if (lVar2 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar2 + 0x10) != 0) {
        if (*(char *)(param_1 + 0x59) == '\0') {
          uVar1 = FUN_1802c43a0(DAT_182d58368);
          FUN_1814df680(uVar1,param_1,DAT_182d6bd90,0);
          ExposureUnnoticed2_Scripts_Base_Scheduler__DelayScaledTime__0600174d
                    (uVar1,*(undefined4 *)(param_1 + 0x38),0);
        }
        else {
          if (*(longlong *)(param_1 + 0x30) == 0) goto LAB_1806089fa;
          FUN_181fb8db0(*(longlong *)(param_1 + 0x30),0,0);
        }
      }
    }
    lVar2 = *(longlong *)(param_1 + 0x40);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec12f4 == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec12f4 = '\x01';
    }
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec129b == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec129b = '\x01';
    }
    if (lVar2 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar2 + 0x10) != 0) {
        uVar1 = FUN_1802c43a0(DAT_182d58368);
        FUN_1814df680(uVar1,param_1,DAT_182d6bd88,0);
        lVar2 = 0x50;
        if (*(char *)(param_1 + 0x59) == '\0') {
          lVar2 = 0x54;
        }
        ExposureUnnoticed2_Scripts_Base_Scheduler__DelayScaledTime__0600174d
                  (uVar1,*(undefined4 *)(lVar2 + param_1),0);
      }
    }
    return;
  }
LAB_1806089fa:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

