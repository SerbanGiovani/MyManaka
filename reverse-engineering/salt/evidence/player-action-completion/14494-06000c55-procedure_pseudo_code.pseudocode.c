// Ghidra pseudocode; not original source or compilable C.
// ev_ad799a23159216e450a6e00f4f0821948cecff84bf37b9317ac18758cf915055

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationReceiver__CommonOnEndAnim__06000c55
               (longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  uint uVar8;
  bool bVar9;
  
  if (cRam0000000182eb837f == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f438);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f430);
    LOCK();
    UNLOCK();
    cRam0000000182eb837f = '\x01';
  }
  lVar5 = *(longlong *)(param_1 + 0x40);
  if (((lVar5 != 0) && (*(longlong *)(lVar5 + 0x60) != 0)) &&
     (lVar6 = *(longlong *)(*(longlong *)(lVar5 + 0x60) + 0x48), lVar6 != 0)) {
    iVar3 = *(int *)(lVar6 + 0x18);
    if (iVar3 == 0x271a) {
      if ((lVar5 == 0) || (*(longlong *)(lVar5 + 0x48) == 0)) goto DAT_18062b161;
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetHoldInHand__06000c88
                (*(longlong *)(lVar5 + 0x48),1,0);
    }
    else if (iVar3 == 0x271b) {
      lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
      if (lVar5 == 0) goto DAT_18062b161;
      if (*(char *)(lVar5 + 0x11) == '\0') {
        ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551(0,1,0);
        uVar7 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d6f430,0);
        ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                  (uVar7,1,0);
        ExposureUnnoticed2_ObjectUI_TutorialPanel_TutorialPanelView__Open__060017f0(4,0);
      }
    }
    else if (iVar3 == 0x271c) {
      if ((*(longlong *)(lVar5 + 0x70) == 0) ||
         (lVar5 = *(longlong *)(*(longlong *)(lVar5 + 0x70) + 0x200), lVar5 == 0))
      goto DAT_18062b161;
      FUN_181f3ea80(lVar5,0,0);
    }
    uVar7 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(uVar7,param_1,uRam0000000182d6f438,0);
    if (DAT_182eb7aa1 == '\0') {
      FUN_1802f2810(&DAT_182d5f910,2,0);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d5f908);
      LOCK();
      UNLOCK();
      DAT_182eb7aa1 = '\x01';
    }
    lVar5 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
    if (lVar5 != 0) {
      lVar5 = *(longlong *)(lVar5 + 0x20);
      lVar6 = FUN_1802c43a0(DAT_182d5f910);
      bVar9 = DAT_182eb5d50 != 0;
      *(undefined8 *)(lVar6 + 0x10) = uVar7;
      if (bVar9) {
        uVar8 = (uint)(lVar6 + 0x10U >> 0xc);
        puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8);
        do {
          uVar4 = *puVar1;
          LOCK();
          uVar2 = *puVar1;
          if (uVar4 == uVar2) {
            *puVar1 = uVar4 | 1L << (uVar8 & 0x3f);
          }
          UNLOCK();
        } while (uVar4 != uVar2);
      }
      *(undefined4 *)(lVar6 + 0x18) = 2;
      if (lVar5 != 0) {
        FUN_1800068f0(lVar5,lVar6);
        return;
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
DAT_18062b161:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

