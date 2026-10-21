// Ghidra pseudocode; not original source or compilable C.
// ev_426d3efbc7183582881e75bb5c2dd4366b6ac87c6ab6350befaeca325de7690d

void __c___OnClickLoad_b__8_1__0600195f(void)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (cRam0000000182eb7bfe == '\0') {
    FUN_1802f2810(0x182d5d6a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d636f8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7bfe = '\x01';
  }
  if (**(char **)(lRam0000000182d5d6a0 + 0xb8) != '\0') {
    uVar2 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d636f8,0);
    if (DAT_182eb7ce7 == '\0') {
      FUN_1802f2810(&DAT_182d58398);
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
code_r0x0001804e29d5:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(char *)(lVar1 + 0x36) != '\0') {
      if (**(longlong **)(DAT_182d647e0 + 0xb8) == 0) goto code_r0x0001804e29d5;
      ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessageInstance__06001b13
                (**(longlong **)(DAT_182d647e0 + 0xb8),uVar2,1,0);
    }
  }
  **(undefined1 **)(lRam0000000182d5d6a0 + 0xb8) = 0;
  return;
}

