// Ghidra pseudocode; not original source or compilable C.
// ev_6452c0e4269d68fde83596f649c1524b7c1bf35ab998dfcd331d4a40304beb14

void ExposureUnnoticed2_Object3D_Camera_BaseCameraController__SetTpsCullingMask__060011e9
               (longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x58);
  uVar1 = *(undefined4 *)(param_1 + 0x50);
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  pcVar3 = DAT_182ebfae0;
  if ((DAT_182ebfae0 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Camera::set_cullingMask(System.Int32)"),
     pcVar3 == (code *)0x0)) {
    uVar4 = FUN_1802ced60("UnityEngine.Camera::set_cullingMask(System.Int32)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  DAT_182ebfae0 = pcVar3;
                    /* WARNING: Could not recover jumptable at 0x00018045ba29. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_182ebfae0)(lVar2,uVar1);
  return;
}

