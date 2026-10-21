// Ghidra pseudocode; not original source or compilable C.
// ev_8fa1be6245212b6f5b266a30996e9485d242215a9071a5a75effdebace878790

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__ChangeState__0600105f
               (longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  
  if (*(longlong *)(param_1 + 0x48) == 0) goto LAB_180429cc2;
  switch(*(undefined4 *)(*(longlong *)(param_1 + 0x48) + 0x10)) {
  case 0:
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x48), lVar2 == 0))
    goto LAB_180429cc2;
    ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__DisableLookAt__06000c10(lVar2,2,0);
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (((lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x50), lVar2 == 0 ||
         (lVar2 = *(longlong *)(lVar2 + 0x60), lVar2 == 0)) ||
        (lVar2 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                           (lVar2,0), lVar2 == 0)))) goto LAB_180429cc2;
    FUN_181f3ea80(lVar2,0,0);
    break;
  case 1:
    lVar2 = *(longlong *)(param_1 + 0x50);
    if (((lVar2 == 0) || (*(longlong *)(lVar2 + 0x20) == 0)) ||
       ((lVar1 = *(longlong *)(*(longlong *)(lVar2 + 0x20) + 0x60), lVar1 == 0 ||
        (lVar1 = *(longlong *)(lVar1 + 0x10), lVar1 == 0)))) goto LAB_180429cc2;
    *(undefined4 *)(lVar1 + 0x14) = 0;
    *(undefined4 *)(lVar1 + 0x18) = 0x78;
    if ((*(longlong *)(lVar2 + 0x20) == 0) ||
       (lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x20) + 0xa0), lVar2 == 0)) goto LAB_180429cc2;
    ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__SetFoundStranger__06000fcd
              (lVar2,0,0);
    break;
  case 2:
    if ((((*(longlong *)(param_1 + 0x30) == 0) ||
         (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x78), lVar2 == 0)) ||
        (*(longlong *)(lVar2 + 0x10) == 0)) ||
       (lVar1 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0xa0), lVar1 == 0)) goto LAB_180429cc2;
    ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__SetOverrideIdle__06000fc9(lVar1,0,0)
    ;
    if ((*(longlong *)(lVar2 + 0x10) == 0) ||
       (lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x40), lVar2 == 0)) goto LAB_180429cc2;
    *(undefined8 *)(lVar2 + 0xb8) = 0;
    *(undefined8 *)(lVar2 + 0xc0) = 0;
    break;
  case 5:
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xd0), lVar2 == 0))
    goto LAB_180429cc2;
    ExposureUnnoticed2_Object3D_NPC_Script_NpcInteractState__OnExit__060010f4(lVar2,0);
    break;
  case 7:
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x128), lVar2 == 0))
    goto LAB_180429cc2;
    ExposureUnnoticed2_Object3D_NPC_Script_State_NpcTraceSexPlayerState__OnExit__06001136(lVar2,0);
  }
  lVar2 = *(longlong *)(param_1 + 0x48);
  if (lVar2 != 0) {
    *(undefined4 *)(lVar2 + 0x14) = *(undefined4 *)(lVar2 + 0x10);
    if (*(longlong *)(param_1 + 0x48) != 0) {
      *(undefined4 *)(*(longlong *)(param_1 + 0x48) + 0x10) = param_2;
      lVar2 = *(longlong *)(param_1 + 0x48);
      pcVar3 = DAT_182ec14c0;
      if ((DAT_182ec14c0 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar3 == (code *)0x0)) {
        uVar4 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      DAT_182ec14c0 = pcVar3;
      uVar5 = (*DAT_182ec14c0)();
      if (lVar2 != 0) {
        *(undefined4 *)(lVar2 + 0x28) = uVar5;
        switch(param_2) {
        case 0:
          if ((*(longlong *)(param_1 + 0x30) != 0) &&
             (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x20), lVar2 != 0)) {
            ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__OnEnter__06001078(lVar2,0);
            if ((*(longlong *)(param_1 + 0x30) != 0) &&
               ((lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xa0), lVar2 != 0 &&
                (lVar2 = *(longlong *)(lVar2 + 0x20), lVar2 != 0)))) {
              *(undefined4 *)(lVar2 + 0x1c) = 0x3f800000;
              if ((*(longlong *)(param_1 + 0x30) != 0) &&
                 ((lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x50), lVar2 != 0 &&
                  (lVar2 = *(longlong *)(lVar2 + 0x60), lVar2 != 0)))) {
                lVar2 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                                  (lVar2,0);
                if ((*(longlong *)(param_1 + 0x30) != 0) &&
                   ((lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40), lVar1 != 0 &&
                    (lVar2 != 0)))) {
                  FUN_181f3ea80(lVar2,*(undefined1 *)(lVar1 + 200),0);
                  return;
                }
              }
            }
          }
          break;
        case 1:
          if (((*(longlong *)(param_1 + 0x30) != 0) &&
              (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xa0), lVar2 != 0)) &&
             (lVar2 = *(longlong *)(lVar2 + 0x20), lVar2 != 0)) {
            *(undefined4 *)(lVar2 + 0x1c) = 0;
            if (((*(longlong *)(param_1 + 0x50) != 0) &&
                (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x20), lVar2 != 0)) &&
               (lVar2 = *(longlong *)(lVar2 + 0xa0), lVar2 != 0)) {
              ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__SetFoundStranger__06000fcd
                        (lVar2,1,0);
              return;
            }
          }
          break;
        case 2:
          if ((*(longlong *)(param_1 + 0x30) != 0) &&
             (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x78), lVar2 != 0)) {
            ExposureUnnoticed2_Object3D_NPC_Script_NpcTurnAroundState__OnEnter__060010fc(lVar2,0);
            return;
          }
          break;
        case 3:
          if (*(longlong *)(param_1 + 0x58) != 0) {
            ExposureUnnoticed2_Object3D_NPC_Script_NpcFadeOutState__OnEnter__060010ed
                      (*(longlong *)(param_1 + 0x58),0);
            return;
          }
          break;
        case 4:
          if (((*(longlong *)(param_1 + 0x30) != 0) &&
              (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xa0), lVar2 != 0)) &&
             (lVar2 = *(longlong *)(lVar2 + 0x20), lVar2 != 0)) {
            *(undefined4 *)(lVar2 + 0x1c) = 0;
            if ((*(longlong *)(param_1 + 0x30) != 0) &&
               (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xb8), lVar2 != 0)) {
              *(undefined4 *)(lVar2 + 0x18) = 0x3f800000;
              return;
            }
          }
          break;
        case 5:
          if (((*(longlong *)(param_1 + 0x30) != 0) &&
              (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xa0), lVar2 != 0)) &&
             (lVar2 = *(longlong *)(lVar2 + 0x20), lVar2 != 0)) {
            *(undefined4 *)(lVar2 + 0x1c) = 0;
            if ((*(longlong *)(param_1 + 0x30) != 0) &&
               (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x20), lVar2 != 0)) {
              ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__SetActiveNavAgent__0600107d
                        (lVar2,0,0);
              if ((*(longlong *)(param_1 + 0x30) != 0) &&
                 (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xd0), lVar2 != 0)) {
                ExposureUnnoticed2_Object3D_NPC_Script_NpcInteractState__OnEnter__060010f3(lVar2,0);
                if ((*(longlong *)(param_1 + 0x30) != 0) &&
                   (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40), lVar2 != 0)) {
                  *(undefined1 *)(lVar2 + 0x1c) = 0;
                  return;
                }
              }
            }
          }
          break;
        case 6:
          if (((*(longlong *)(param_1 + 0x30) != 0) &&
              (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xa0), lVar2 != 0)) &&
             (lVar2 = *(longlong *)(lVar2 + 0x20), lVar2 != 0)) {
            *(undefined4 *)(lVar2 + 0x1c) = 0;
            if (((*(longlong *)(param_1 + 0x30) != 0) &&
                (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xe0), lVar2 != 0)) &&
               ((lVar2 = *(longlong *)(lVar2 + 0x10), lVar2 != 0 &&
                ((lVar2 = *(longlong *)(lVar2 + 0xa0), lVar2 != 0 &&
                 (lVar2 = *(longlong *)(lVar2 + 0x20), lVar2 != 0)))))) {
              *(undefined4 *)(lVar2 + 0x1c) = 0;
              return;
            }
          }
          break;
        case 7:
          if ((*(longlong *)(param_1 + 0x30) != 0) &&
             (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x20), lVar2 != 0)) {
            ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__OnEnter__06001078(lVar2,0);
            if ((*(longlong *)(param_1 + 0x30) != 0) &&
               ((lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xa0), lVar2 != 0 &&
                (lVar2 = *(longlong *)(lVar2 + 0x20), lVar2 != 0)))) {
              *(undefined4 *)(lVar2 + 0x1c) = 0x3f800000;
              if ((*(longlong *)(param_1 + 0x30) != 0) &&
                 (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x128), lVar2 != 0)) {
                ExposureUnnoticed2_Object3D_NPC_Script_State_NpcTraceSexPlayerState__OnEnter__06001135
                          (lVar2,0);
                return;
              }
            }
          }
          break;
        default:
          return;
        }
      }
    }
  }
LAB_180429cc2:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

