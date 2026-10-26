// Ghidra pseudocode; not original source or compilable C.
// ev_1b1fc6a0ab3a27036c5efd9c8416731bac7c405601c6e93d7f697120da811dfc

void ExposureUnnoticed2_Object3D_Camera_BaseCameraController__TransStrafe__060011ea
               (longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if (DAT_182eb7816 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb7816 = '\x01';
  }
  lVar2 = *(longlong *)(param_1 + 0x48);
  if (lVar2 != 0) {
    (**(code **)(lVar2 + 0x18))(*(undefined8 *)(lVar2 + 0x40),*(undefined8 *)(lVar2 + 0x28));
  }
  if (*(longlong *)(param_1 + 0x38) != 0) {
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 0x40) = 0;
    if (*(longlong *)(param_1 + 0x38) != 0) {
      ExposureUnnoticed2_Object3D_Camera_FPCameraController__OnLateUpdate__060011ff
                (*(longlong *)(param_1 + 0x38),0);
      lVar2 = *(longlong *)(param_1 + 0x58);
      uVar1 = *(undefined4 *)(param_1 + 0x54);
      if (lVar2 != 0) {
        pcVar3 = DAT_182ebfae0;
        if ((DAT_182ebfae0 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Camera::set_cullingMask(System.Int32)"),
           pcVar3 == (code *)0x0)) {
          uVar4 = FUN_1802ced60("UnityEngine.Camera::set_cullingMask(System.Int32)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar4,0);
        }
        DAT_182ebfae0 = pcVar3;
        (*DAT_182ebfae0)(lVar2,uVar1);
        if ((*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38) != 0) &&
           (lVar2 = *(longlong *)(param_1 + 0x58), lVar2 != 0)) {
          pcVar3 = DAT_182ebfa30;
          if ((DAT_182ebfa30 == (code *)0x0) &&
             (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Camera::set_fieldOfView(System.Single)"),
             pcVar3 == (code *)0x0)) {
            uVar4 = FUN_1802ced60("UnityEngine.Camera::set_fieldOfView(System.Single)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar4,0);
          }
          DAT_182ebfa30 = pcVar3;
                    /* WARNING: Could not recover jumptable at 0x00018045bb60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*DAT_182ebfa30)(lVar2);
          return;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

