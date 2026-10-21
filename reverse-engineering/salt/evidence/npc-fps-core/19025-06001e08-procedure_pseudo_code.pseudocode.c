// Ghidra pseudocode; not original source or compilable C.
// ev_740cd192a5fc2d29db1a4f3c112072136950e94c3ebcbcf9ea456c1965e087d9

void Common_Scripts_Util_AnimatorFPSController__Active__06001e08(longlong param_1,int param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if (param_2 != -1) {
    *(int *)(param_1 + 0x14) = param_2;
    *(float *)(param_1 + 0x20) = 1.0 / (float)param_2;
  }
  if (*(char *)(param_1 + 0x10) == '\0') {
    lVar1 = *(longlong *)(param_1 + 0x18);
    *(undefined1 *)(param_1 + 0x10) = 1;
    if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    pcVar2 = DAT_182ec1060;
    if ((DAT_182ec1060 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Behaviour::set_enabled(System.Boolean)"),
       pcVar2 == (code *)0x0)) {
      uVar3 = FUN_1802ced60("UnityEngine.Behaviour::set_enabled(System.Boolean)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar3,0);
    }
    DAT_182ec1060 = pcVar2;
    (*DAT_182ec1060)(lVar1,0);
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(float *)(param_1 + 0x20) = 1.0 / (float)*(int *)(param_1 + 0x14);
  }
  return;
}

