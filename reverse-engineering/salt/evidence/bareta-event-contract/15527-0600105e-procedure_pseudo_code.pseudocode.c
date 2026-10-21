// Ghidra pseudocode; not original source or compilable C.
// ev_531320cca2fcb3d247bf1ae340b64ee4c804b28e8233da7ecdab7fcd6d7c7358

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__OnLateUpdate__0600105e(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (*(longlong *)(param_1 + 0x48) != 0) {
    if (15.0 < *(float *)(*(longlong *)(param_1 + 0x48) + 0xd8)) {
      return;
    }
    if ((*(longlong *)(param_1 + 0x30) != 0) &&
       (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x48), lVar1 != 0)) {
      ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__OnLateUpdate__06000c16(lVar1,0);
      if ((*(longlong *)(param_1 + 0x30) != 0) &&
         (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x68), lVar1 != 0)) {
        if (cRam0000000182eb779a == '\0') {
          FUN_1802f2810(&DAT_182d53aa8,0);
          LOCK();
          UNLOCK();
          cRam0000000182eb779a = '\x01';
        }
        lVar3 = *(longlong *)(lVar1 + 0x80);
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (DAT_182ec12f3 == '\0') {
          FUN_1802f2810(&DAT_182d53aa8);
          LOCK();
          UNLOCK();
          DAT_182ec12f3 = '\x01';
        }
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (DAT_182ec129b == '\0') {
          FUN_1802f2810(&DAT_182d53aa8);
          LOCK();
          UNLOCK();
          DAT_182ec129b = '\x01';
        }
        if (lVar3 != 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (*(longlong *)(lVar3 + 0x10) != 0) {
            pcVar2 = DAT_182ec1080;
            if ((DAT_182ec1080 == (code *)0x0) &&
               (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
               pcVar2 == (code *)0x0)) {
              uVar4 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar4,0);
            }
            DAT_182ec1080 = pcVar2;
            lVar3 = (*DAT_182ec1080)(lVar1);
            lVar1 = *(longlong *)(lVar1 + 0x80);
            if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            uStack_28 = 0;
            uStack_20 = 0;
            pcVar2 = DAT_182ec16b8;
            if ((DAT_182ec16b8 == (code *)0x0) &&
               (pcVar2 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                              ), pcVar2 == (code *)0x0)) {
              uVar4 = FUN_1802ced60(
                                   "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar4,0);
            }
            DAT_182ec16b8 = pcVar2;
            (*DAT_182ec16b8)(lVar1,&uStack_28);
            if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            uStack_18 = (undefined4)uStack_28;
            uStack_14 = uStack_28._4_4_;
            uStack_10 = (undefined4)uStack_20;
            uStack_c = uStack_20._4_4_;
            pcVar2 = DAT_182ec16c0;
            if ((DAT_182ec16c0 == (code *)0x0) &&
               (pcVar2 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                              ), pcVar2 == (code *)0x0)) {
              uVar4 = FUN_1802ced60(
                                   "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar4,0);
            }
            DAT_182ec16c0 = pcVar2;
            (*DAT_182ec16c0)(lVar3,&uStack_18);
          }
        }
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

