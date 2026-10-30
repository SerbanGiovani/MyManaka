// Ghidra pseudocode; not original source or compilable C.
// ev_a339869ece4e627430974d937a001293e92222c9b588f6589d8733a5618fc4c9

void ExposureUnnoticed2_Scripts_Base_SmoothFloat__SetSecond__0600175e
               (longlong param_1,float param_2)

{
  float fVar1;
  
  if (cRam0000000182eb7aa9 == '\0') {
    FUN_1802f2810(&DAT_182d52288);
    LOCK();
    UNLOCK();
    cRam0000000182eb7aa9 = '\x01';
  }
  if (param_2 == 0.0) {
    param_2 = 0.0001;
  }
  fVar1 = *(float *)(param_1 + 0x2c);
  *(float *)(param_1 + 0x28) = param_2;
  *(float *)(param_1 + 0x14) = *(float *)(param_1 + 0x24) / param_2;
  if (*(int *)(DAT_182d52288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (0.001 <= ABS(fVar1 - -1.0)) {
    param_2 = *(float *)(param_1 + 0x2c);
  }
  *(float *)(param_1 + 0x2c) = param_2;
  *(float *)(param_1 + 0x18) = *(float *)(param_1 + 0x24) / param_2;
  return;
}

