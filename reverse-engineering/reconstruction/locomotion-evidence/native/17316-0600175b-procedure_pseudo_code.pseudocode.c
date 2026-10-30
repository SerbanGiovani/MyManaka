// Ghidra pseudocode; not original source or compilable C.
// ev_efc6fdda40ead40460b3fca5e8dd2435d0807a8882b3b057260e58815e379c56

void ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
               (longlong param_1,float param_2,float param_3,undefined4 param_4,undefined1 param_5,
               undefined1 param_6,float param_7)

{
  if (DAT_182eb7aa8 == '\0') {
    FUN_1802f2810(&DAT_182d52288);
    LOCK();
    UNLOCK();
    DAT_182eb7aa8 = '\x01';
  }
  *(undefined1 *)(param_1 + 0x20) = param_5;
  *(float *)(param_1 + 0x24) = param_3;
  *(float *)(param_1 + 0x28) = param_2;
  if (*(int *)(DAT_182d52288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (ABS(param_7 - -1.0) < 0.001) {
    param_7 = param_2;
  }
  *(float *)(param_1 + 0x2c) = param_7;
  *(undefined1 *)(param_1 + 0x30) = param_6;
  *(float *)(param_1 + 0x18) = param_3 / *(float *)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x10) = param_4;
  *(float *)(param_1 + 0x14) = param_3 / param_2;
  return;
}

