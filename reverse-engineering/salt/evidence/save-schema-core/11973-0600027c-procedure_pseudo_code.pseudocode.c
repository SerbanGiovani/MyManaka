// Ghidra pseudocode; not original source or compilable C.
// ev_17f5b714b8848124be5a85adb7ae9fed0017264c6e4412fe87b556883dc2a29a

void ES3Writer__WriteType__0600027c(longlong *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (cRam0000000182eb75b6 == '\0') {
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d55f40);
    LOCK();
    UNLOCK();
    cRam0000000182eb75b6 = '\x01';
  }
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar1 = ES3Internal_ES3Reflection__GetTypeString__0600067d(param_2,0);
                    /* WARNING: Could not recover jumptable at 0x0001803d7ef9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x408))
            (param_1,uRam0000000182d55f40,uVar1,*(undefined8 *)(*param_1 + 0x410));
  return;
}

