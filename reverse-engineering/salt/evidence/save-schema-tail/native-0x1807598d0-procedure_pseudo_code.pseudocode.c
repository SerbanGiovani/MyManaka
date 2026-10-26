// Ghidra pseudocode; not original source or compilable C.
// ev_cb4e90943aca3ba316df51d1cd7df1e0e05f369c6648fb46c7b45b5554ff05e8

undefined8 native_only_1807598d0__00000000(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (cRam0000000182eb85c7 == '\0') {
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    cRam0000000182eb85c7 = '\x01';
  }
  uVar1 = *(undefined8 *)(param_1 + 0x18);
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar1 = ES3Internal_ES3Reflection__CreateInstance__0600065a(uVar1,0);
  ES3Types_ES3Type__ReadProperties__06000445(param_1,param_2,uVar1,0);
  return uVar1;
}

