// Ghidra pseudocode; not original source or compilable C.
// ev_8d5895d7b98770ea3fec28e4bc70783dc4b3ff1c91f5bd00f5ed5b681dd34a00

void ExposureUnnoticed2_ObjectUI_ChooseHandcuffsPanel_SleepSelectPanelView__Initialize__06001d49
               (longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *UNRECOVERED_JUMPTABLE;
  char cVar3;
  undefined8 uVar4;
  
  if (cRam0000000182eb7e56 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65558);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65550);
    LOCK();
    UNLOCK();
    cRam0000000182eb7e56 = '\x01';
  }
  if (**(longlong **)(DAT_182d5aa70 + 0xb8) != 0) {
    ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
              (**(longlong **)(DAT_182d5aa70 + 0xb8),0x31,0xbf800000,0,0);
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar1 != 0) {
      uVar4 = uRam0000000182d65550;
      if (*(char *)(lVar1 + 0x20) != '\0') {
        uVar4 = uRam0000000182d65558;
      }
      plVar2 = *(longlong **)(param_1 + 0x60);
      uVar4 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar4,0);
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 0x558))(plVar2,uVar4,*(undefined8 *)(*plVar2 + 0x560));
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
            cVar3 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__IsPutSomeDildoAtOutsideHome__0600150a
                              (**(longlong **)(DAT_182d5bcb8 + 0xb8),0);
            uVar4 = DAT_182d52e20;
            if (cVar3 != '\0') {
              uVar4 = DAT_182d65548;
            }
            uVar4 = System_String__Concat__0600021b(DAT_182d65540,uVar4,0);
            plVar2 = *(longlong **)(param_1 + 0x58);
            uVar4 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar4,0);
            if (plVar2 != (longlong *)0x0) {
              UNRECOVERED_JUMPTABLE = *(code **)(*plVar2 + 0x558);
                    /* WARNING: Could not recover jumptable at 0x00018053dd9f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              (*UNRECOVERED_JUMPTABLE)
                        (plVar2,uVar4,*(undefined8 *)(*plVar2 + 0x560),UNRECOVERED_JUMPTABLE);
              return;
            }
          }
        }
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

