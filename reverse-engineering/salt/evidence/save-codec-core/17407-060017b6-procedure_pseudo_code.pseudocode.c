// Ghidra pseudocode; not original source or compilable C.
// ev_1141277666128325324ab0adc3c41434a3891006709ab3c6ac166dbcf5b33670

undefined8
ExposureUnnoticed2_Scripts_Base_SaveRapper__GetSpecifiedSaveDataPath__060017b6
          (int param_1,undefined4 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  
  if (DAT_182eb7ad6 == '\0') {
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f4d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f4c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f4c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f4b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f4b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f4a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52e20);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f4a0);
    LOCK();
    UNLOCK();
    DAT_182eb7ad6 = '\x01';
  }
  if (param_1 == 4) {
    return DAT_182d5f4a8;
  }
  if (param_1 == 0) {
    return DAT_182d5f4c8;
  }
  if (param_1 != 2) {
    if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d60278);
    }
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x10);
    if (lVar1 != 0) {
      FUN_1816c83c0(lVar1,0,0);
      uVar3 = DAT_182d5f4c0;
      if (*(char *)(*(longlong *)(DAT_182d60278 + 0xb8) + 4) != '\0') {
        uVar3 = DAT_182d5f4b0;
      }
      lVar1 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x10);
      if (lVar1 != 0) {
        lVar1 = FUN_1816c8bc0(lVar1,uVar3,0);
        uVar3 = DAT_182d52e20;
        if (param_1 == 1) {
          uVar3 = DAT_182d5f4d0;
        }
        if (lVar1 != 0) {
          lVar1 = FUN_1816c8bc0(lVar1,uVar3,0);
          if (lVar1 != 0) {
            lVar1 = FUN_1816c8bc0(lVar1,DAT_182d52e20,0);
            if (lVar1 != 0) {
              lVar1 = FUN_1816c9910(lVar1,param_2,0);
              if (lVar1 != 0) {
                plVar2 = (longlong *)FUN_1816c8bc0(lVar1,DAT_182d5f4a0,0);
                if (plVar2 != (longlong *)0x0) {
                  UNRECOVERED_JUMPTABLE = *(code **)(*plVar2 + 0x168);
                    /* WARNING: Could not recover jumptable at 0x0001804b9f79. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                  uVar3 = (*UNRECOVERED_JUMPTABLE)
                                    (plVar2,*(undefined8 *)(*plVar2 + 0x170),UNRECOVERED_JUMPTABLE);
                  return uVar3;
                }
              }
            }
          }
        }
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  return DAT_182d5f4b8;
}

