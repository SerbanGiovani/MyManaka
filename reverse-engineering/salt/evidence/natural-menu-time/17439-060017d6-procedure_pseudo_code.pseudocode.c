// Ghidra pseudocode; not original source or compilable C.
// ev_c9439c96b6a46ab3780a88cabe45731540777c544018b953646eefcbefc67ecd

void ExposureUnnoticed2_Scripts_Base_TimeScaleManager__get_GetCurrentScale__060017d6(void)

{
  code *pcVar1;
  undefined8 uVar2;
  
  pcVar1 = pcRam0000000182ec1508;
  if ((pcRam0000000182ec1508 == (code *)0x0) &&
     (pcVar1 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_timeScale()"), pcVar1 == (code *)0x0)) {
    uVar2 = FUN_1802ced60("UnityEngine.Time::get_timeScale()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  pcRam0000000182ec1508 = pcVar1;
                    /* WARNING: Could not recover jumptable at 0x0001804bbb5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000182ec1508)();
  return;
}

