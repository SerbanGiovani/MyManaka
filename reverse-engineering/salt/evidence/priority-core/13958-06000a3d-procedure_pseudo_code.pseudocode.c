// Ghidra pseudocode; not original source or compilable C.
// ev_1f5574112105051e977a1dbe2745fcea12e5a0950b3a48608cabc40ff3d34659

void ExposureUnnoticed2_Object3D_ScenePlops_WasherMachine_WasherMachineController__StartWash__06000a3d
               (longlong param_1,undefined4 param_2,char param_3)

{
  undefined4 uVar1;
  longlong lVar2;
  char cVar3;
  longlong lVar4;
  undefined8 uVar5;
  code *pcVar6;
  
  if (DAT_182eb8244 == '\0') {
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6c188);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6c180);
    LOCK();
    UNLOCK();
    DAT_182eb8244 = '\x01';
  }
  if (param_3 != '\0') {
    lVar4 = *(longlong *)(param_1 + 0x58);
    if (*(int *)(DAT_182d6c188 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d6c188);
    }
    if (lVar4 == 0) goto LAB_1805f670a;
    uVar1 = *(undefined4 *)(*(longlong *)(DAT_182d6c188 + 0xb8) + 8);
    pcVar6 = DAT_182ebf348;
    if ((DAT_182ebf348 == (code *)0x0) &&
       (pcVar6 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)"
                                      ), pcVar6 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ebf348 = pcVar6;
    (*DAT_182ebf348)(lVar4,uVar1,1);
LAB_1805f6651:
    lVar4 = *(longlong *)(param_1 + 0x58);
    if (*(int *)(DAT_182d6c188 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d6c188);
    }
    if (lVar4 != 0) {
      uVar1 = **(undefined4 **)(DAT_182d6c188 + 0xb8);
      pcVar6 = DAT_182ebf348;
      if ((DAT_182ebf348 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)"
                                        ), pcVar6 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ebf348 = pcVar6;
      (*DAT_182ebf348)(lVar4,uVar1,1);
      lVar4 = *(longlong *)(param_1 + 0x38);
      if ((*(longlong *)(param_1 + 0x70) != 0) &&
         (*(undefined4 *)(*(longlong *)(param_1 + 0x70) + 0x10) = 0x3f800000, lVar4 != 0)) {
        pcVar6 = DAT_182ebf6b8;
        if ((DAT_182ebf6b8 == (code *)0x0) &&
           (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.AudioSource::set_volume(System.Single)"),
           pcVar6 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.AudioSource::set_volume(System.Single)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ebf6b8 = pcVar6;
        (*DAT_182ebf6b8)(lVar4,0x3f800000);
        *(undefined4 *)(param_1 + 0x7c) = param_2;
        return;
      }
    }
LAB_1805f670a:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (*(char *)(param_1 + 0x48) != '\0') {
    uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(DAT_182d6c180,0);
    goto LAB_1805f65b7;
  }
  lVar4 = **(longlong **)(DAT_182d58230 + 0xb8);
  if (lVar4 == 0) goto LAB_1805f670a;
  if (DAT_182eb83fe == '\0') {
    FUN_1802f2810(&DAT_182d3e668);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d3e660);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5e118);
    LOCK();
    UNLOCK();
    DAT_182eb83fe = '\x01';
  }
  cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsAttachSomeHandcuffs__0600155d(0);
  uVar5 = DAT_182d3e660;
  if (cVar3 == '\0') {
    if ((*(longlong *)(lVar4 + 0x10) == 0) ||
       (lVar2 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x60), lVar2 == 0)) goto LAB_1805f670a;
    uVar5 = DAT_182d3e668;
    if (*(char *)(lVar2 + 0x1b) == '\0') {
      if (*(longlong *)(lVar2 + 0x48) == 0) goto LAB_1805f670a;
      uVar5 = DAT_182d5e118;
      if (((*(int *)(*(longlong *)(lVar2 + 0x48) + 0x18) == -1) &&
          (lVar4 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x60), *(int *)(lVar4 + 0x5c) == 0))
         && (*(char *)(lVar4 + 0x50) == '\0')) {
        lVar4 = FUN_180436330();
        if (lVar4 == 0) goto LAB_1805f670a;
        uVar5 = DAT_182d5e118;
        if (*(char *)(lVar4 + 0x10) == '\0') {
          *(undefined1 *)(param_1 + 0x49) = 1;
          lVar4 = **(longlong **)(DAT_182d58230 + 0xb8);
          if ((*(longlong *)(param_1 + 0x20) == 0) ||
             (uVar5 = FUN_181d769d0(*(longlong *)(param_1 + 0x20),0), lVar4 == 0))
          goto LAB_1805f670a;
          ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__SmoothMoveTo__06000d95
                    (lVar4,uVar5,0);
          if ((**(longlong **)(DAT_182d58230 + 0xb8) == 0) ||
             ((lVar4 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar4 == 0 ||
              (lVar4 = *(longlong *)(lVar4 + 0x60), lVar4 == 0)))) goto LAB_1805f670a;
          *(undefined4 *)(lVar4 + 0x234) = 0x2719;
          if ((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
             ((lVar4 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar4 == 0 ||
              (lVar4 = *(longlong *)(lVar4 + 0x60), lVar4 == 0)))) goto LAB_1805f670a;
          *(undefined8 *)(lVar4 + 0x240) = *(undefined8 *)(param_1 + 0x28);
          FUN_18031d480(lVar4 + 0x240);
          lVar4 = *(longlong *)(param_1 + 0x58);
          if (*(int *)(DAT_182d6c188 + 0xe0) == 0) {
            FUN_18035c820(DAT_182d6c188);
          }
          if (lVar4 == 0) goto LAB_1805f670a;
          FUN_181eea680(lVar4,*(undefined4 *)(*(longlong *)(DAT_182d6c188 + 0xb8) + 8),0,0);
          goto LAB_1805f6651;
        }
      }
    }
  }
  uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar5,0);
LAB_1805f65b7:
  ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14(uVar5,0,0);
  return;
}

