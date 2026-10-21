// Ghidra pseudocode; not original source or compilable C.
// ev_c378f89574938fb0a75eb3cc8378f19454ce784af78f568d9df739a601d3b047

undefined8 ExposureUnnoticed2_Master_Stage_MStage__Get__06001229(undefined4 param_1)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 local_res18 [2];
  
  if (DAT_182eb7835 == '\0') {
    FUN_1802f2810(&DAT_182d5c720);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594e8);
    LOCK();
    UNLOCK();
    DAT_182eb7835 = '\x01';
  }
  local_res18[0] = 0;
  if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  ExposureUnnoticed2_Master_Stage_MStage__CheckInitialize__06001228(0);
  if (**(longlong **)(DAT_182d594e8 + 0xb8) != 0) {
    cVar1 = FUN_180e77740(**(longlong **)(DAT_182d594e8 + 0xb8),param_1,local_res18,DAT_182d5c720);
    uVar2 = 0;
    if (cVar1 != '\0') {
      uVar2 = local_res18[0];
    }
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

