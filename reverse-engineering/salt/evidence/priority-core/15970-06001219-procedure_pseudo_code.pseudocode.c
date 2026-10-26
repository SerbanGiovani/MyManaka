// Ghidra pseudocode; not original source or compilable C.
// ev_216df7c2a3d71c8db7082997c99134c0383581266c80bd46a522fbd0fa3bee21

void ExposureUnnoticed2_Object3D_Camera_TPCameraController__ResetToPlayerDirect__06001219
               (undefined8 param_1)

{
  undefined8 uVar1;
  
  if (DAT_182eb7829 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c800);
    LOCK();
    UNLOCK();
    DAT_182eb7829 = '\x01';
  }
  uVar1 = FUN_1802c43a0(DAT_182d58368);
  FUN_1814df680(uVar1,param_1,DAT_182d5c800,0);
  ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(uVar1,1,0);
  return;
}

