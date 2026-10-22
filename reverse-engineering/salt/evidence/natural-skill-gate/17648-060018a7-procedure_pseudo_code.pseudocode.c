// Ghidra pseudocode; not original source or compilable C.
// ev_cb499ac71321c0b58ff04a142d9195580aa67c4dccbdab772b508a12fe3c6faa

void ExposureUnnoticed2_ObjectUI_PcMenuPanel_SkillSwitchPanel_SkillSwitchPanelView__OnClickItem__060018a7
               (longlong param_1,longlong param_2)

{
  longlong *plVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  if (cRam0000000182eb7b8d == '\0') {
    FUN_1802f2810(&DAT_182d5f500);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61838);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52e20);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b8d = '\x01';
  }
  plVar1 = *(longlong **)(param_1 + 0x68);
  if ((param_2 != 0) &&
     (uVar2 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                        (*(undefined8 *)(param_2 + 0x18),0), plVar1 != (longlong *)0x0)) {
    (**(code **)(*plVar1 + 0x558))(plVar1,uVar2,*(undefined8 *)(*plVar1 + 0x560));
    lVar3 = DAT_182d52e20;
    if (0 < *(int *)(param_2 + 0x48)) {
      lVar3 = FUN_181618010(param_2 + 0x48,0);
      uVar2 = DAT_182d5f500;
      if (lVar3 == 0) {
        lVar3 = DAT_182d52e20;
      }
      uVar4 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0
                        (uRam0000000182d61838,lVar3,0);
      lVar3 = System_String__Concat__0600021b(uVar2,uVar4,0);
    }
    plVar1 = *(longlong **)(param_1 + 0x70);
    uVar2 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                      (*(undefined8 *)(param_2 + 0x20),0);
    uVar2 = System_String__Concat__0600021b(uVar2,lVar3,0);
    if (plVar1 != (longlong *)0x0) {
      UNRECOVERED_JUMPTABLE = *(code **)(*plVar1 + 0x558);
                    /* WARNING: Could not recover jumptable at 0x0001804cfbf5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(plVar1,uVar2,*(undefined8 *)(*plVar1 + 0x560),UNRECOVERED_JUMPTABLE);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

