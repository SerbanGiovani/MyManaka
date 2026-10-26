// Ghidra pseudocode; not original source or compilable C.
// ev_960d444c829f433855487ba478ae66ddffa636b7215555dc555e3a5b137a61ff

undefined8 ExposureUnnoticed2_Scripts_Base_SaveRapper__GetSaveDataPath__060017b5(void)

{
  code *UNRECOVERED_JUMPTABLE;
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  
  if (DAT_182eb7ad5 == '\0') {
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
    DAT_182eb7ad5 = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (**(char **)(DAT_182d60278 + 0xb8) != '\0') {
    return DAT_182d5f4a8;
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (*(char *)(*(longlong *)(DAT_182d60278 + 0xb8) + 1) != '\0') {
    return DAT_182d5f4c8;
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (*(char *)(*(longlong *)(DAT_182d60278 + 0xb8) + 3) == '\0') {
    if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
      FUN_18035c820();
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
        if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar3 = DAT_182d52e20;
        if (*(char *)(*(longlong *)(DAT_182d60278 + 0xb8) + 2) != '\0') {
          uVar3 = DAT_182d5f4d0;
        }
        if (lVar1 != 0) {
          lVar1 = FUN_1816c8bc0(lVar1,uVar3,0);
          if (lVar1 != 0) {
            lVar1 = FUN_1816c8bc0(lVar1,DAT_182d52e20,0);
            if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (lVar1 != 0) {
              lVar1 = FUN_1816c9910(lVar1,*(undefined4 *)(*(longlong *)(DAT_182d60278 + 0xb8) + 8),0
                                   );
              if (lVar1 != 0) {
                plVar2 = (longlong *)FUN_1816c8bc0(lVar1,DAT_182d5f4a0,0);
                if (plVar2 != (longlong *)0x0) {
                  UNRECOVERED_JUMPTABLE = *(code **)(*plVar2 + 0x168);
                    /* WARNING: Could not recover jumptable at 0x0001804b9d71. Too many branches */
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

