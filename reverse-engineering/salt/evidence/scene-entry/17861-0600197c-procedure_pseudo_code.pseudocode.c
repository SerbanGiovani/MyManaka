// Ghidra pseudocode; not original source or compilable C.
// ev_aa3a273e479acfaece6d62e6e9693951c7587b37a51269c8e1e0360e3a010f9a

void ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_SaveDataSelectPanelView__OnClickItem__0600197c
               (undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  
  if (cRam0000000182eb7c0f == '\0') {
    FUN_1802f2810(0x182d60190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa70);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c0f = '\x01';
  }
  cVar1 = FUN_18049bf10(param_2,param_3,0);
  if (cVar1 != '\0') {
    **(undefined4 **)(lRam0000000182d60190 + 0xb8) = param_3;
    if (**(longlong **)(lRam0000000182d5aa70 + 0xb8) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    FUN_180477a70(**(longlong **)(lRam0000000182d5aa70 + 0xb8),0x31,0xbf800000,0,0);
    FUN_18049d380(param_2,param_3,0);
    ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_SaveDataSelectPanelView__TransScene__0600197b
              (param_1,0);
  }
  return;
}

