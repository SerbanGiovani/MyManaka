// Ghidra pseudocode; not original source or compilable C.
// ev_625dd9c2f267a7979067822e4a9eb28a63bdcf9be45dd77864113ba134c51ec6

undefined8 *
ES3Internal_ES3Reflection__GetES3ReflectedMember__06000661
          (undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if (cRam0000000182eb8090 == '\0') {
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    cRam0000000182eb8090 = '\x01';
  }
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar1 = ES3Internal_ES3Reflection__GetField__06000675(param_2,param_3,0);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  ES3ReflectedMember___ctor__06000685(param_1,uVar1,0);
  return param_1;
}

