// Ghidra pseudocode; not original source or compilable C.
// ev_89af7ad0a294ccc632634a9b1d341ba3f6711669ae01441bac49814f2ccd9362

undefined4 ES3Settings__get_location__060001b2(longlong param_1)

{
  int iVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if (DAT_182eb7553 == '\0') {
    FUN_1802f2810(&DAT_182d53a48);
    LOCK();
    UNLOCK();
    DAT_182eb7553 = '\x01';
  }
  if (*(int *)(param_1 + 0x10) != 0) {
LAB_1803cc64f:
    return *(undefined4 *)(param_1 + 0x10);
  }
  if (*(int *)(DAT_182d53a48 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar2 = DAT_182ebf9e8;
  if ((DAT_182ebf9e8 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Application::get_platform()"),
     pcVar2 == (code *)0x0)) {
    uVar3 = FUN_1802ced60("UnityEngine.Application::get_platform()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  DAT_182ebf9e8 = pcVar2;
  iVar1 = (*DAT_182ebf9e8)();
  if (iVar1 != 0x11) {
    if (*(int *)(DAT_182d53a48 + 0xe0) == 0) {
      FUN_18035c820();
    }
    pcVar2 = DAT_182ebf9e8;
    if ((DAT_182ebf9e8 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Application::get_platform()"),
       pcVar2 == (code *)0x0)) {
      uVar3 = FUN_1802ced60("UnityEngine.Application::get_platform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar3,0);
    }
    DAT_182ebf9e8 = pcVar2;
    iVar1 = (*DAT_182ebf9e8)();
    if (iVar1 != 0x1f) goto LAB_1803cc64f;
  }
  return 1;
}

