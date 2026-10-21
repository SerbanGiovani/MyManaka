// Ghidra pseudocode; not original source or compilable C.
// ev_efc6e0a62826d5a4f46b70b1b66e8c012f84232c1a820dbb8052e0bd5cbdb89f

void ExposureUnnoticed2_Object3D_Player_Scripts_MentalManager__ReduceByFound__06000c2c(void)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  if (cRam0000000182eb836b == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f6e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f6d8);
    LOCK();
    UNLOCK();
    cRam0000000182eb836b = '\x01';
  }
  if (cRam0000000182eb548f == '\0') {
    FUN_1802f2810(&DAT_182d59250);
    LOCK();
    UNLOCK();
    cRam0000000182eb548f = '\x01';
  }
  if (**(char **)(DAT_182d59250 + 0xb8) == '\0') {
    lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(int *)(lVar3 + 0x10) != 0) {
      if (*(int *)(lRam0000000182d6f6d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar3 = *(longlong *)(*(longlong *)(lRam0000000182d6f6d8 + 0xb8) + 8);
      if (lVar3 == 0) {
        if (*(int *)(lRam0000000182d6f6d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar2 = **(undefined8 **)(lRam0000000182d6f6d8 + 0xb8);
        lVar3 = FUN_1802c43a0(DAT_182d58368);
        FUN_1814df680(lVar3,uVar2,uRam0000000182d6f6e8,0);
        *(longlong *)(*(longlong *)(lRam0000000182d6f6d8 + 0xb8) + 8) = lVar3;
        FUN_18031d480(*(longlong *)(lRam0000000182d6f6d8 + 0xb8) + 8);
      }
      if (DAT_182eb7aa2 == '\0') {
        FUN_1802f2810(&DAT_182d5f900,0x3f4ccccd,0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d5f8f8);
        LOCK();
        UNLOCK();
        DAT_182eb7aa2 = '\x01';
      }
      lVar1 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
      if (lVar1 != 0) {
        lVar1 = *(longlong *)(lVar1 + 0x38);
        uVar2 = FUN_1802c43a0(DAT_182d5f900);
        DelayTimeModel___ctor__06001753(uVar2,lVar3,0x3f4ccccd,1,0);
        if (lVar1 != 0) {
          FUN_180006950(lVar1,uVar2);
          return;
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
  return;
}

