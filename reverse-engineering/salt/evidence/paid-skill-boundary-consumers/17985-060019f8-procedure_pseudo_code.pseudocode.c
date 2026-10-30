// Ghidra pseudocode; not original source or compilable C.
// ev_aa8129c3f8176e46a80cecd210eccc459272e1375864a2511497e2c6fc329695

undefined4
ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelView__CanEquipByMaxCount__060019f8
          (undefined8 param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  
  if (cRam0000000182eb7c53 == '\0') {
    FUN_1802f2810(0x182d62d38);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c53 = '\x01';
  }
  iVar2 = ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelView__CalcEquipCount__060019f9
                    (param_1,0);
  uVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529(0xb,0);
  lVar4 = ExposureUnnoticed2_Master_Skill_SkillMaxAccessoryNum_MSkillMaxAccessoryNum__Get__06001247
                    (uVar3,0);
  if (lVar4 != 0) {
    if (iVar2 < *(int *)(lVar4 + 0x1c)) {
      return 1;
    }
    uVar1 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d62d38,0);
    ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
              (uVar1,0,0);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

