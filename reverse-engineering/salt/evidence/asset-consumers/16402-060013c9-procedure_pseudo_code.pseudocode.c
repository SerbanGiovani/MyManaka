// Ghidra pseudocode; not original source or compilable C.
// ev_949e0fe214006c8529ba5738d4d5719e9fcf2441415acd00362ddef842502575

void ExposureUnnoticed2_Scripts_UI_TitleSceneView___OnClickNewGame_b__37_0__060013c9
               (longlong param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (cRam0000000182eb78d3 == '\0') {
    FUN_1802f2810(0x182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bf40);
    LOCK();
    UNLOCK();
    cRam0000000182eb78d3 = '\x01';
  }
  uVar1 = *(undefined8 *)(param_1 + 0x38);
  uVar2 = FUN_1802c43a0(uRam0000000182d58368);
  FUN_1814df680(uVar2,param_1,uRam0000000182d5bf40,0);
  FUN_1804c62c0(uVar1,0,0,uVar2,0);
  return;
}

