// Ghidra pseudocode; not original source or compilable C.
// ev_e122a7e894e30e23b6e8d603a07bd3d625e789ba5dff6331e3dfbf94ea62cec3

void ExposureUnnoticed2_Scripts_InGame_StageController__GetEscapeTarget__0600165b(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if ((*(longlong *)(param_1 + 0xd0) != 0) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0xd0) + 0x20), lVar1 != 0)) {
    if (*(int *)(lVar1 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    lVar1 = *(longlong *)(lVar1 + 0x20);
    if (lVar1 != 0) {
      pcVar2 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar2 == (code *)0x0)) {
        uVar3 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar3,0);
      }
      DAT_182ec1080 = pcVar2;
                    /* WARNING: Could not recover jumptable at 0x0001804a51a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*DAT_182ec1080)(lVar1);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

