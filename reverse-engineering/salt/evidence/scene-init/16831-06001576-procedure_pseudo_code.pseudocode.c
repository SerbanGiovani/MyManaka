// Ghidra pseudocode; not original source or compilable C.
// ev_d42b4db73690fa4cabd9dcf0fb51b40654909d24768defca9b57a8a742bbe102

/* WARNING: Removing unreachable block (ram,0x00018050c4c7) */
/* WARNING: Removing unreachable block (ram,0x00018050c4dd) */

void __c___OnCompleteTransitionStageEvent_b__3_0__06001576(void)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (cRam0000000182eb79d4 == '\0') {
    FUN_1802f2810(0x182d5d7c8);
    LOCK();
    UNLOCK();
    cRam0000000182eb79d4 = '\x01';
  }
  uVar2 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d5d7c8,0);
  if (DAT_182eb7ce7 == '\0') {
    FUN_1802f2810(&DAT_182d58398,1,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d647e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    DAT_182eb7ce7 = '\x01';
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
  if (lVar1 == 0) {
LAB_18050c506:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (*(char *)(lVar1 + 0x36) != '\0') {
    if (**(longlong **)(DAT_182d647e0 + 0xb8) == 0) goto LAB_18050c506;
    ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessageInstance__06001b13
              (**(longlong **)(DAT_182d647e0 + 0xb8),uVar2,1,0);
  }
  return;
}

