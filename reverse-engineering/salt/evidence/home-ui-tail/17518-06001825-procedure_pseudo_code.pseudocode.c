// Ghidra pseudocode; not original source or compilable C.
// ev_bc87f06f15f8d2372cb3f3c84d66110f9884962686d1564e26b877cf162a2592

void ExposureUnnoticed2_ObjectUI_SleepBlackPanel_SleepBlackPanelView__Initialize__06001825
               (longlong param_1,undefined1 param_2,char param_3)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  
  if (DAT_182eb7b31 == '\0') {
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d61bb0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d61ba8);
    LOCK();
    UNLOCK();
    DAT_182eb7b31 = '\x01';
  }
  *(undefined1 *)(param_1 + 0x60) = param_2;
  *(char *)(param_1 + 0x61) = param_3;
  if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d58080);
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x50);
  if (lVar1 != 0) {
    *(undefined1 *)(lVar1 + 0x10) = 0;
    uVar3 = *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x50);
    if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
      FUN_18035c820();
    }
    ExposureUnnoticed2_Scripts_Base_EventManager__Broadcast__06001716(uVar3,0);
    uVar3 = DAT_182d61ba8;
    if (param_3 != '\0') {
      uVar3 = DAT_182d61bb0;
    }
    plVar2 = *(longlong **)(param_1 + 0x58);
    uVar3 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar3,0);
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 0x558))(plVar2,uVar3,*(undefined8 *)(*plVar2 + 0x560));
      if (DAT_182eb7bed == '\0') {
        FUN_1802f2810(&DAT_182d59250);
        LOCK();
        UNLOCK();
        DAT_182eb7bed = '\x01';
      }
      **(undefined1 **)(DAT_182d59250 + 0xb8) = 1;
      if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
         (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar1 != 0)) {
        *(undefined1 *)(lVar1 + 0x13) = 1;
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

