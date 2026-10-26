// Ghidra pseudocode; not original source or compilable C.
// ev_4066aa3dd835ae5643ff92c1753f4bf149fb07dfa1d58a53dd66a7100b539640

void native_only_1807537f0__00000000(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lStack_28;
  longlong lStack_20;
  undefined8 uStack_18;
  
  if (*(longlong *)(param_2 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_2 + 0x38) == 0) {
      FUN_1803204f0(param_2);
    }
  }
  lVar1 = **(longlong **)(param_2 + 0x38);
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  uVar2 = 0;
  if (lVar1 != 0) {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar1 = FUN_1803613f0(lVar1,1);
    uVar2 = FUN_1802c5ac0(lVar1 + 0x20);
  }
  if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar2 = ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(uVar2,1,0);
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x38) + 8);
  lStack_28 = *(longlong *)(*param_1 + ((ulonglong)*(ushort *)(lVar1 + 0x50) + 0x14) * 0x10);
  lStack_20 = 0;
  if ((*(byte *)(lStack_28 + 0x53) & 2) != 0) {
    lStack_20 = (*(longlong **)(lStack_28 + 0x40))[1];
    lStack_28 = **(longlong **)(lStack_28 + 0x40);
  }
  uStack_18 = *(undefined8 *)(*(longlong *)(lVar1 + 0x40) + 0x10);
  lVar1 = FUN_180306310(&lStack_28,1);
  (**(code **)(lVar1 + 8))(param_1,uVar2,lVar1);
  return;
}

