// Ghidra pseudocode; not original source or compilable C.
// ev_fd12debb7b3b25756822059514d9f44cb9aa58167e7b0b0b2647dd348f18e540

void ExposureUnnoticed2_ObjectUI_ChooseHandcuffsPanel_SleepSelectPanelView__RefreshView__06001d4a
               (longlong param_1)

{
  longlong *plVar1;
  code *UNRECOVERED_JUMPTABLE;
  char cVar2;
  undefined8 uVar3;
  
  if (DAT_182eb7e57 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d65548);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d65540);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52e20);
    LOCK();
    UNLOCK();
    DAT_182eb7e57 = '\x01';
  }
  if (((*(int *)(param_1 + 0x70) == 0) || (*(int *)(param_1 + 0x70) != 1)) ||
     (*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48) != 0)) {
    if (DAT_182eb54a2 == '\0') {
      FUN_1802f2810(&DAT_182d5bcb8);
      LOCK();
      UNLOCK();
      DAT_182eb54a2 = '\x01';
    }
    if (**(longlong **)(DAT_182d5bcb8 + 0xb8) != 0) {
      cVar2 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__IsPutSomeDildoAtOutsideHome__0600150a
                        (**(longlong **)(DAT_182d5bcb8 + 0xb8),0);
      uVar3 = DAT_182d52e20;
      if (cVar2 != '\0') {
        uVar3 = DAT_182d65548;
      }
      uVar3 = System_String__Concat__0600021b(DAT_182d65540,uVar3,0);
      plVar1 = *(longlong **)(param_1 + 0x58);
      uVar3 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar3,0);
      if (plVar1 != (longlong *)0x0) {
        UNRECOVERED_JUMPTABLE = *(code **)(*plVar1 + 0x558);
                    /* WARNING: Could not recover jumptable at 0x00018053dd9f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)
                  (plVar1,uVar3,*(undefined8 *)(*plVar1 + 0x560),UNRECOVERED_JUMPTABLE);
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

