// Ghidra pseudocode; not original source or compilable C.
// ev_7427d8e6d45e571d25afef017031924736a6c02527b592f9573cca364be8c3d5

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__OnLateUpdate__06000d65
               (longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  
  if ((*(longlong *)(param_1 + 0x40) != 0) &&
     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x108), lVar2 != 0)) {
    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerToeHeelController__OnLateUpdate__06000e46
              (lVar2,0);
    if ((*(longlong *)(param_1 + 0x40) != 0) &&
       (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x198), lVar2 != 0)) {
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerKneeAdjuster__OnLateUpdate__06000de2(lVar2,0)
      ;
      if ((*(longlong *)(param_1 + 0x40) != 0) &&
         (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x120), lVar2 != 0)) {
        ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__OnLateUpdate__06000c16(lVar2,0)
        ;
        if (*(longlong *)(param_1 + 0x20) != 0) {
          ExposureUnnoticed2_Object3D_Camera_FaceCameraController__OnLateUpdate__060011f7
                    (*(longlong *)(param_1 + 0x20),0);
          if ((*(longlong *)(param_1 + 0x40) != 0) &&
             (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x128), lVar2 != 0)) {
            ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFaceController__OnLateUpdate__06000db5
                      (lVar2,0);
            if ((*(longlong *)(param_1 + 0x40) != 0) &&
               (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x170), lVar2 != 0)) {
              ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyCustomizeAdjuster__OnLateUpdate__06000cc4
                        (lVar2,0);
              if ((*(longlong *)(param_1 + 0x40) != 0) &&
                 (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x1d8), lVar2 != 0)) {
                ExposureUnnoticed2_Object3D_Player_Scripts_Other_FutanariController__OnLateUpdate__06000e8c
                          (lVar2,0);
                if ((*(longlong *)(param_1 + 0x40) != 0) &&
                   (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x178), lVar2 != 0)) {
                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAvatarOffsetManager__OnLateUpdate__06000c97
                            (lVar2,0);
                  if ((*(longlong *)(param_1 + 0x40) != 0) &&
                     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x1a8), lVar2 != 0)) {
                    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBreathController__OnLateUpdate__06000cee
                              (lVar2,0);
                    if (*(longlong *)(param_1 + 0x40) != 0) {
                      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
                      if (DAT_182eb5480 == '\0') {
                        FUN_1802f2810(&DAT_182d522a8);
                        LOCK();
                        UNLOCK();
                        DAT_182eb5480 = '\x01';
                      }
                      uVar1 = *(undefined4 *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
                      if (lVar2 != 0) {
                        *(undefined8 *)(lVar2 + 0x254) = **(undefined8 **)(DAT_182d522a8 + 0xb8);
                        *(undefined4 *)(lVar2 + 0x25c) = uVar1;
                        return;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

