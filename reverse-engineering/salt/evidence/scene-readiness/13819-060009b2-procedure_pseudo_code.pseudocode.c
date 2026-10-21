// Ghidra pseudocode; not original source or compilable C.
// ev_f8ecf45c188882da3e998a09dbb4142bf587f82a69771aedcf73b8f404827461

void ExposureUnnoticed2_ObjectTitle_IntroAnimationController__OnEndFadeInTitle__060009b6
               (longlong param_1)

{
  code *pcVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  pcVar2 = DAT_182ec1088;
  *(undefined1 *)(param_1 + 0x20) = 1;
  pcVar1 = DAT_182ec1088;
  if ((pcVar2 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"), pcVar1 = pcVar2,
     pcVar2 == (code *)0x0)) {
    uVar4 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  DAT_182ec1088 = pcVar1;
  lVar3 = (*pcVar2)(param_1);
  if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  pcVar2 = DAT_182ec1138;
  if ((DAT_182ec1138 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
     pcVar2 == (code *)0x0)) {
    uVar4 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  DAT_182ec1138 = pcVar2;
                    /* WARNING: Could not recover jumptable at 0x0001805ea63c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_182ec1138)(lVar3,0);
  return;
}

