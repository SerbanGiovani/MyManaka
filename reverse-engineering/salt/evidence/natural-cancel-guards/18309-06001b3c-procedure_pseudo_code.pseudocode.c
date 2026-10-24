// Ghidra pseudocode; not original source or compilable C.
// ev_40353463178d2b8ef0bb4f22b44f53f2b107b4a9f08ca89b5da77bdf807b8bbf

void ExposureUnnoticed2_ObjectUI_FastTravelPanel_FastTravelPanelView__OnClickFastTravel__06001b3c
               (longlong param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  float fVar8;
  ulonglong in_stack_ffffffffffffffe8;
  
  if (cRam0000000182eb7d07 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64640);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64638);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ffc8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64630);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64628);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62878);
    LOCK();
    UNLOCK();
    cRam0000000182eb7d07 = '\x01';
  }
  if (DAT_182eb548c == '\0') {
    FUN_1802f2810(&DAT_182d57a70);
    LOCK();
    UNLOCK();
    DAT_182eb548c = '\x01';
  }
  if (**(longlong **)(DAT_182d57a70 + 0xb8) != 0) {
    fVar8 = (float)ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__GetMinPureStrange__060010a1
                             (**(longlong **)(DAT_182d57a70 + 0xb8),0);
    if (0.0 < fVar8) {
      uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d62878,0);
      ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                (uVar5,0,0);
      return;
    }
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar7 != 0) && (*(longlong *)(param_1 + 0x90) != 0)) {
      lVar3 = **(longlong **)(DAT_182d53c48 + 0xb8);
      if (*(int *)(lVar7 + 0x10) == *(int *)(*(longlong *)(param_1 + 0x90) + 0x20)) {
        if ((lVar3 != 0) && (*(longlong *)(lVar3 + 0x30) != 0)) {
          *(undefined1 *)(*(longlong *)(lVar3 + 0x30) + 0x13) = 1;
          uVar5 = FUN_1802c43a0(uRam0000000182d5ffc8);
          ExposureUnnoticed2_ObjectUI_FadeOutPanel_TimeWaitStarter___ctor__06001b53
                    (uVar5,0x3f800000,0);
          uVar6 = FUN_1802c43a0(DAT_182d58368);
          FUN_1814df680(uVar6,param_1,uRam0000000182d64640,0);
          if (*(int *)(lRam0000000182d64628 + 0xe0) == 0) {
            FUN_18035c820();
          }
          lVar7 = *(longlong *)(*(longlong *)(lRam0000000182d64628 + 0xb8) + 0x10);
          if (lVar7 == 0) {
            if (*(int *)(lRam0000000182d64628 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar4 = **(undefined8 **)(lRam0000000182d64628 + 0xb8);
            lVar7 = FUN_1802c43a0(DAT_182d58368);
            FUN_1814df680(lVar7,uVar4,uRam0000000182d64630,0);
            *(longlong *)(*(longlong *)(lRam0000000182d64628 + 0xb8) + 0x10) = lVar7;
            FUN_18031d480(*(longlong *)(lRam0000000182d64628 + 0xb8) + 0x10);
          }
          if (*(int *)(lRam0000000182d5aa40 + 0xe0) == 0) {
            FUN_18035c820();
          }
          ExposureUnnoticed2_ObjectUI_FadeOutPanel_FadePanelView__Open__06001b4c
                    (uVar5,uVar6,0,lVar7,in_stack_ffffffffffffffe8 & 0xffffffffffffff00,0);
          return;
        }
      }
      else if (lVar3 != 0) {
        lVar7 = *(longlong *)(lVar3 + 0x60);
        uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0x90) + 0x24);
        uVar2 = *(undefined4 *)(*(longlong *)(param_1 + 0x90) + 0x20);
        uVar5 = FUN_1802c43a0(DAT_182d58368);
        FUN_1814df680(uVar5,param_1,uRam0000000182d64638,0);
        if (lVar7 != 0) {
          ExposureUnnoticed2_Scripts_InGame_StageTransController__TransStageIfInCondition__06001668
                    (lVar7,uVar1,uVar2,0,uVar5,0);
          return;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

