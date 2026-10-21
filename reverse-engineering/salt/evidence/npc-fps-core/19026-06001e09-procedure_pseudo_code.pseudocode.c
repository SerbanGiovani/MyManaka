// Ghidra pseudocode; not original source or compilable C.
// ev_95886049c440ac9cc1a653e97dfc1b5fcf27782d23599a027569f9cd6a0c0094

void Common_Scripts_Util_AnimatorFPSController__DeActive__06001e09(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if (*(char *)(param_1 + 0x10) == '\0') {
    return;
  }
  lVar1 = *(longlong *)(param_1 + 0x18);
  *(undefined1 *)(param_1 + 0x10) = 0;
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
                    /* WARNING: Could not recover jumptable at 0x00018057e54e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_182ec1060)(lVar1,1);
  return;
}

