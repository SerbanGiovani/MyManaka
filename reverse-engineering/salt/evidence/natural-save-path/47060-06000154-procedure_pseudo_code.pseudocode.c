// Ghidra pseudocode; not original source or compilable C.
// ev_97cfafd979125c8df4c0f9ba536de37980fdcb57f2c3f7bb72e071f3748d45e2

void UnityEngine_Application__get_persistentDataPath__06000154(void)

{
  code *pcVar1;
  undefined8 uVar2;
  
  pcVar1 = pcRam0000000182ebf9c0;
  if ((pcRam0000000182ebf9c0 == (code *)0x0) &&
     (pcVar1 = (code *)FUN_1802cf0c0("UnityEngine.Application::get_persistentDataPath()"),
     pcVar1 == (code *)0x0)) {
    uVar2 = FUN_1802ced60("UnityEngine.Application::get_persistentDataPath()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  pcRam0000000182ebf9c0 = pcVar1;
                    /* WARNING: Could not recover jumptable at 0x000181ef97cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000182ebf9c0)();
  return;
}

