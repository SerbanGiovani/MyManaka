// Ghidra pseudocode; not original source or compilable C.
// ev_72f94617512424b1858238b27fe45c4e17d292a9890f02c211f709ffd6db7857

void ExposureUnnoticed2_Object3D_Camera_BaseCameraController__SetDirectCameraFOV__060011e8
               (longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x58);
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  pcVar2 = DAT_182ebfa30;
  if ((DAT_182ebfa30 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Camera::set_fieldOfView(System.Single)"),
     pcVar2 == (code *)0x0)) {
    uVar3 = FUN_1802ced60("UnityEngine.Camera::set_fieldOfView(System.Single)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  DAT_182ebfa30 = pcVar2;
                    /* WARNING: Could not recover jumptable at 0x00018045b9bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_182ebfa30)(lVar1);
  return;
}

