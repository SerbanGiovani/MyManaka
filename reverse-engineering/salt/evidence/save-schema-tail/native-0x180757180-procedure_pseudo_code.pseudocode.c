// Ghidra pseudocode; not original source or compilable C.
// ev_f81fbfdf7af5ea21cc323ae01f0bd9e20f429423dd82e5485fd5f8e17779e252

undefined8
native_only_180757180__00000000
          (longlong *param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  char cVar1;
  undefined8 uVar2;
  
  if (*(longlong *)(param_4 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_4 + 0x38) == 0) {
      FUN_1803204f0(param_4);
    }
  }
  cVar1 = (**(code **)(*param_1 + 0x2d8))(param_1,param_2,*(undefined8 *)(*param_1 + 0x2e0));
  if (cVar1 != '\0') {
    uVar2 = native_only_180759550__00000000
                      (param_1,*(undefined8 *)(*(longlong *)(param_4 + 0x38) + 8));
    if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar2 = ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(uVar2,1,0);
    param_3 = FUN_1800036a0(*(undefined8 *)(*(longlong *)(param_4 + 0x38) + 0x10),param_1,uVar2);
  }
  return param_3;
}

