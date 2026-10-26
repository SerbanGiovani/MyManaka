// Ghidra pseudocode; not original source or compilable C.
// ev_6d40b90e09b06dc1f6c0dc848f2ddbd848eb1afa8e141014c1e485c59c9b098f

undefined8 *
ES3Internal_ES3Reflection__GetES3ReflectedProperty__06000660
          (undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if (cRam0000000182eb808f == '\0') {
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    cRam0000000182eb808f = '\x01';
  }
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar1 = ES3Internal_ES3Reflection__GetProperty__06000674(param_2,param_3,0);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  ES3ReflectedMember___ctor__06000685(param_1,uVar1,0);
  return param_1;
}

