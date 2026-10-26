// Ghidra pseudocode; not original source or compilable C.
// ev_3d8f2f71148c68be94f24c8f998fdee26b7907972a9bf555f04508d9101d1323

void ExposureUnnoticed2_Object3D_Camera_BaseCameraController__SetInventoryCamera__060011ec
               (longlong param_1,undefined1 param_2,char param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  
  if (DAT_182eb7818 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    DAT_182eb7818 = '\x01';
  }
  *(undefined1 *)(param_1 + 0x69) = param_2;
  if ((*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38) != 0) &&
     (lVar1 = *(longlong *)(param_1 + 0x58), lVar1 != 0)) {
    pcVar4 = DAT_182ebfa30;
    if ((DAT_182ebfa30 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Camera::set_fieldOfView(System.Single)"),
       pcVar4 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Camera::set_fieldOfView(System.Single)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ebfa30 = pcVar4;
    (*DAT_182ebfa30)(lVar1);
    lVar1 = *(longlong *)(param_1 + 0x60);
    if (lVar1 != 0) {
      if (*(char *)(param_1 + 0x69) == '\0') {
        if (*(char *)(lVar1 + 0x1a) != '\0') {
          ExposureUnnoticed2_Object3D_Camera_BaseCameraController__TransStrafe__060011ea(param_1,0);
        }
        if ((((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
             (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 == 0)) ||
            (lVar1 = *(longlong *)(lVar1 + 0x58), lVar1 == 0)) ||
           (lVar1 = *(longlong *)(lVar1 + 0x30), lVar1 == 0)) goto LAB_18045bf3e;
        *(undefined1 *)(lVar1 + 0x18) = 0;
      }
      else {
        if (*(char *)(lVar1 + 0x1a) != '\0') {
          if (*(longlong *)(param_1 + 0x30) == 0) goto LAB_18045bf3e;
          ExposureUnnoticed2_Object3D_Camera_TPCameraController__OnChangeThirdPersonView__06001217
                    (*(longlong *)(param_1 + 0x30),0);
          lVar1 = *(longlong *)(param_1 + 0x30);
          if (((lVar1 == 0) ||
              (*(float *)(lVar1 + 0x2c) = *(float *)(lVar1 + 0x2c) + 180.0,
              *(longlong *)(param_1 + 0x30) == 0)) || (*(longlong *)(param_1 + 0x58) == 0))
          goto LAB_18045bf3e;
          FUN_181efb470(*(longlong *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x50),0);
        }
        lVar1 = *(longlong *)(param_1 + 0x40);
        if (param_3 == '\0') {
          if ((lVar1 == 0) || (lVar2 = *(longlong *)(param_1 + 0x30), lVar2 == 0))
          goto LAB_18045bf3e;
          uVar3 = 0;
          *(undefined4 *)(lVar1 + 0x20) = *(undefined4 *)(lVar2 + 0x2c);
          uVar6 = *(undefined4 *)(lVar2 + 0x30);
        }
        else {
          if (lVar1 == 0) goto LAB_18045bf3e;
          uVar6 = 0x3f800000;
          uVar3 = 1;
          *(undefined4 *)(lVar1 + 0x20) = 0x42b40000;
        }
        *(undefined4 *)(lVar1 + 0x24) = uVar6;
        *(undefined1 *)(lVar1 + 0x34) = uVar3;
        *(undefined4 *)(lVar1 + 0x3c) = 0;
        *(undefined4 *)(lVar1 + 0x38) = 0;
        *(undefined4 *)(lVar1 + 0x44) = 1;
        if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
            (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 == 0)) ||
           ((lVar1 = *(longlong *)(lVar1 + 0x58), lVar1 == 0 ||
            (lVar1 = *(longlong *)(lVar1 + 0x30), lVar1 == 0)))) goto LAB_18045bf3e;
        *(undefined1 *)(lVar1 + 0x18) = 1;
      }
      return;
    }
  }
LAB_18045bf3e:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

