// Ghidra pseudocode; not original source or compilable C.
// ev_a480f164aee4a9758bad5ffd4f743dc9ed786901ec32c75f8e2cef4f14e24028

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__OnEndAction__06000dee
               (longlong param_1)

{
  ulonglong uVar1;
  ulonglong *puVar2;
  code *pcVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uStack_68;
  undefined4 uStack_60;
  ulonglong uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 uStack_38;
  undefined8 uStack_30;
  
  if (cRam0000000182eb8423 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    cRam0000000182eb8423 = '\x01';
  }
  if (*(longlong *)(param_1 + 0x68) != 0) {
    if (*(char *)(*(longlong *)(param_1 + 0x68) + 0x1a) == '\0') {
      return;
    }
    if ((*(longlong *)(param_1 + 0x40) != 0) &&
       (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x38), lVar4 != 0)) {
      puVar2 = (ulonglong *)FUN_181f4c360(&uStack_48,lVar4,0);
      uStack_58 = *puVar2;
      uVar1 = puVar2[1];
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182eb547c == '\0') {
        FUN_1802f2810(&DAT_182d522a8);
        LOCK();
        UNLOCK();
        DAT_182eb547c = '\x01';
      }
      uStack_68 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
      uStack_60 = *(undefined4 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
      uStack_58 = uStack_58 & 0xffffffff;
      uStack_38 = 0;
      uStack_30 = 0;
      pcVar3 = DAT_182ec0ea8;
      uStack_50 = (int)uVar1;
      if ((DAT_182ec0ea8 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                        ), pcVar3 == (code *)0x0)) {
        uVar5 = FUN_1802ced60(
                             "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec0ea8 = pcVar3;
      (*DAT_182ec0ea8)(&uStack_58,&uStack_68,&uStack_38);
      lVar4 = *(longlong *)(param_1 + 0x60);
      if (lVar4 != 0) {
        pcVar3 = DAT_182ec1120;
        if ((DAT_182ec1120 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_transform()"),
           pcVar3 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.GameObject::get_transform()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ec1120 = pcVar3;
        lVar4 = (*DAT_182ec1120)(lVar4);
        if (lVar4 != 0) {
          uStack_48 = (undefined4)uStack_38;
          uStack_44 = uStack_38._4_4_;
          uStack_40 = (undefined4)uStack_30;
          uStack_3c = uStack_30._4_4_;
          pcVar3 = DAT_182ec16c0;
          if ((DAT_182ec16c0 == (code *)0x0) &&
             (pcVar3 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                            ), pcVar3 == (code *)0x0)) {
            uVar5 = FUN_1802ced60(
                                 "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar5,0);
          }
          DAT_182ec16c0 = pcVar3;
          (*DAT_182ec16c0)(lVar4,&uStack_48);
          return;
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

