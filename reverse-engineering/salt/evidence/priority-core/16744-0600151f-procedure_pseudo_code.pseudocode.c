// Ghidra pseudocode; not original source or compilable C.
// ev_1bc841677e732f8c26c782bea6eb01ef36605bced2b97dd3f3f8f45b4b057ecc

void ExposureUnnoticed2_Scripts_InGame_GameStateApplier__OnLateUpdate__0600151f
               (longlong param_1,char param_2)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  bool bVar5;
  float fVar6;
  undefined4 uVar7;
  undefined8 local_18;
  undefined8 uStack_10;
  
  if (DAT_182eb7986 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb7986 = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x18) != 0) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x30), lVar1 != 0)) {
    if (*(char *)(lVar1 + 0x10) != '\0') {
      return;
    }
    if (param_2 == '\0') {
      pcVar2 = DAT_182ec14e0;
      if ((DAT_182ec14e0 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_unscaledTime()"),
         pcVar2 == (code *)0x0)) {
        uVar4 = FUN_1802ced60("UnityEngine.Time::get_unscaledTime()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      DAT_182ec14e0 = pcVar2;
      fVar6 = (float)(*DAT_182ec14e0)();
      if (fVar6 - *(float *)(param_1 + 0x20) < 1.0) {
        return;
      }
    }
    pcVar2 = DAT_182ec14e0;
    if ((DAT_182ec14e0 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_unscaledTime()"),
       pcVar2 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Time::get_unscaledTime()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec14e0 = pcVar2;
    uVar7 = (*DAT_182ec14e0)();
    *(undefined4 *)(param_1 + 0x20) = uVar7;
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((*(longlong *)(param_1 + 0x10) != 0) &&
       (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x30), lVar3 != 0)) {
      pcVar2 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar2 == (code *)0x0)) {
        uVar4 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      DAT_182ec1080 = pcVar2;
      lVar3 = (*DAT_182ec1080)(lVar3);
      if (lVar3 != 0) {
        local_18 = 0;
        uStack_10 = uStack_10 & 0xffffffff00000000;
        pcVar2 = DAT_182ec1698;
        if ((DAT_182ec1698 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                          ), pcVar2 == (code *)0x0)) {
          uVar4 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar4,0);
        }
        DAT_182ec1698 = pcVar2;
        (*DAT_182ec1698)(lVar3,&local_18);
        if (lVar1 != 0) {
          *(undefined8 *)(lVar1 + 0x180) = local_18;
          *(undefined4 *)(lVar1 + 0x188) = (undefined4)uStack_10;
          lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if ((*(longlong *)(param_1 + 0x10) != 0) &&
             (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x30), lVar3 != 0)) {
            pcVar2 = DAT_182ec1080;
            if ((DAT_182ec1080 == (code *)0x0) &&
               (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
               pcVar2 == (code *)0x0)) {
              uVar4 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar4,0);
            }
            DAT_182ec1080 = pcVar2;
            lVar3 = (*DAT_182ec1080)(lVar3);
            if (lVar3 != 0) {
              local_18 = 0;
              uStack_10 = 0;
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
              (*DAT_182ec16b8)(lVar3,&local_18);
              if (lVar1 != 0) {
                bVar5 = DAT_182eb548c == '\0';
                *(undefined4 *)(lVar1 + 0x18c) = (undefined4)local_18;
                *(undefined4 *)(lVar1 + 400) = local_18._4_4_;
                *(undefined4 *)(lVar1 + 0x194) = (undefined4)uStack_10;
                *(undefined4 *)(lVar1 + 0x198) = uStack_10._4_4_;
                if (bVar5) {
                  FUN_1802f2810(&DAT_182d57a70);
                  LOCK();
                  UNLOCK();
                  DAT_182eb548c = '\x01';
                }
                if (**(longlong **)(DAT_182d57a70 + 0xb8) != 0) {
                  ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__ApplyGameState__060010a5
                            (**(longlong **)(DAT_182d57a70 + 0xb8),0);
                  return;
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

