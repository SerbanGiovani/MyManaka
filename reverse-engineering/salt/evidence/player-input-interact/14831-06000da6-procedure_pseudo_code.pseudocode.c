// Ghidra pseudocode; not original source or compilable C.
// ev_3ae558357c6f0ef8b5ef8836bea5e98b9817f1890201c4c603de39801b0996ec

undefined8
ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__CanUseHand__06000da6
          (longlong param_1,char param_2,char param_3,undefined8 param_4,char param_5,char param_6)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  
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
  if ((param_3 != '\0') ||
     (cVar1 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsAttachSomeHandcuffs__0600155d(0),
     uVar3 = DAT_182d3e660, cVar1 == '\0')) {
    if (param_6 == '\0') {
      if ((*(longlong *)(param_1 + 0x10) == 0) ||
         (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar2 == 0))
      goto code_r0x00018064976a;
      uVar3 = DAT_182d3e668;
      if (*(char *)(lVar2 + 0x1b) != '\0') goto joined_r0x0001806496bb;
    }
    if (((*(longlong *)(param_1 + 0x10) == 0) ||
        (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar2 == 0)) ||
       (lVar2 = *(longlong *)(lVar2 + 0x48), lVar2 == 0)) {
code_r0x00018064976a:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uVar3 = DAT_182d5e118;
    if (((*(int *)(lVar2 + 0x18) == -1) || (param_5 != '\0')) &&
       ((*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60) + 0x5c) == 0 &&
        (*(char *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60) + 0x50) == '\0')))) {
      lVar2 = FUN_180436330();
      if (lVar2 == 0) goto code_r0x00018064976a;
      uVar3 = DAT_182d5e118;
      if (*(char *)(lVar2 + 0x10) == '\0') {
        return 1;
      }
    }
  }
joined_r0x0001806496bb:
  if (param_2 != '\0') {
    uVar3 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar3,0);
    ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
              (uVar3,0,0);
  }
  return 0;
}

