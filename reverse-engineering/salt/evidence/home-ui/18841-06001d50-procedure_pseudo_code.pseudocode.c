// Ghidra pseudocode; not original source or compilable C.
// ev_89f8b3652c8b3b5ed5b20e58810d829ef3e274a2bc08084a6abfc1744e4a47d4

void ExposureUnnoticed2_ObjectUI_ChooseHandcuffsPanel_SleepSelectPanelView__Open__06001d50(void)

{
  code *UNRECOVERED_JUMPTABLE;
  longlong lVar1;
  char cVar2;
  longlong *plVar3;
  undefined8 uVar4;
  longlong *plVar5;
  
  if (cRam0000000182eb7e5b == '\0') {
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65520);
    LOCK();
    UNLOCK();
    cRam0000000182eb7e5b = '\x01';
  }
  if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d58380);
  }
  if ((**(longlong **)(DAT_182d58238 + 0xb8) != 0) && (**(longlong **)(DAT_182d58380 + 0xb8) != 0))
  {
    plVar3 = (longlong *)
             ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
                       (**(longlong **)(DAT_182d58380 + 0xb8),
                        *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 400),0,0);
    if (plVar3 != (longlong *)0x0) {
      if ((*(byte *)(lRam0000000182d65520 + 0x130) <= *(byte *)(*plVar3 + 0x130)) &&
         (lVar1 = *(longlong *)(*plVar3 + 200),
         *(longlong *)(lVar1 + -8 + (ulonglong)*(byte *)(lRam0000000182d65520 + 0x130) * 8) ==
         lRam0000000182d65520)) {
        plVar5 = (longlong *)0x0;
        if (*(longlong *)(lVar1 + -8 + (ulonglong)*(byte *)(lRam0000000182d65520 + 0x130) * 8) ==
            lRam0000000182d65520) {
          plVar5 = plVar3;
        }
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
            plVar3 = (longlong *)plVar5[0xc];
            uVar4 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar4,0);
            if (plVar3 != (longlong *)0x0) {
              (**(code **)(*plVar3 + 0x558))(plVar3,uVar4,*(undefined8 *)(*plVar3 + 0x560));
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
              if ((((int)plVar5[0xe] == 0) || ((int)plVar5[0xe] != 1)) ||
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
                  uVar4 = DAT_182d52e20;
                  if (cVar2 != '\0') {
                    uVar4 = DAT_182d65548;
                  }
                  uVar4 = System_String__Concat__0600021b(DAT_182d65540,uVar4,0);
                  plVar3 = (longlong *)plVar5[0xb];
                  uVar4 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar4,0);
                  if (plVar3 != (longlong *)0x0) {
                    UNRECOVERED_JUMPTABLE = *(code **)(*plVar3 + 0x558);
                    /* WARNING: Could not recover jumptable at 0x00018053dd9f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    (*UNRECOVERED_JUMPTABLE)
                              (plVar3,uVar4,*(undefined8 *)(*plVar3 + 0x560),UNRECOVERED_JUMPTABLE);
                    return;
                  }
                }
              }
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

