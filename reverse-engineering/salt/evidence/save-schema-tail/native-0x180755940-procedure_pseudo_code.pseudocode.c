// Ghidra pseudocode; not original source or compilable C.
// ev_61c95f1f487bc803fe92269e8ac616e4bbd619f60f0af925a5276e59505b5f08

void native_only_180755940__00000000(longlong *param_1,undefined8 param_2,longlong param_3)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lStack_28;
  longlong lStack_20;
  undefined8 uStack_18;
  
  if (*(longlong *)(param_3 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_3 + 0x38) == 0) {
      FUN_1803204f0(param_3);
    }
  }
  cVar1 = (**(code **)(*param_1 + 0x2d8))(param_1,param_2,*(undefined8 *)(*param_1 + 0x2e0));
  if (cVar1 != '\0') {
    uVar3 = native_only_180759550__00000000(param_1,**(undefined8 **)(param_3 + 0x38));
    if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar3 = ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(uVar3,1,0);
    lVar2 = *(longlong *)(*(longlong *)(param_3 + 0x38) + 8);
    lStack_28 = *(longlong *)(*param_1 + ((ulonglong)*(ushort *)(lVar2 + 0x50) + 0x14) * 0x10);
    lStack_20 = 0;
    if ((*(byte *)(lStack_28 + 0x53) & 2) != 0) {
      lStack_20 = (*(longlong **)(lStack_28 + 0x40))[1];
      lStack_28 = **(longlong **)(lStack_28 + 0x40);
    }
    uStack_18 = *(undefined8 *)(*(longlong *)(lVar2 + 0x40) + 0x10);
    lVar2 = FUN_180306310(&lStack_28,1);
    (**(code **)(lVar2 + 8))(param_1,uVar3,lVar2);
    return;
  }
  uVar3 = thunk_FUN_1802f2810(&DAT_182d531f8);
  uVar3 = FUN_18031d8c0(uVar3,5);
  FUN_1800039f0(uVar3);
  uVar4 = thunk_FUN_1802f2810(0x182d52df8);
  FUN_180002cd0(uVar3,0,uVar4);
  FUN_1800039f0(uVar3);
  FUN_180002cd0(uVar3,1,param_2);
  FUN_1800039f0(uVar3);
  uVar4 = thunk_FUN_1802f2810(0x182d31df0);
  FUN_180002cd0(uVar3,2,uVar4);
  lVar2 = param_1[2];
  FUN_1800039f0(lVar2);
  uVar4 = ES3Settings__get_FullPath__060001b4(lVar2,0);
  FUN_1800039f0(uVar3);
  FUN_180002cd0(uVar3,3,uVar4);
  FUN_1800039f0(uVar3);
  uVar4 = thunk_FUN_1802f2810(0x182d31dc8);
  FUN_180002cd0(uVar3,4,uVar4);
  uVar3 = System_String__Concat__0600021e(uVar3,0);
  uVar4 = thunk_FUN_1802f2810(&DAT_182d52df0);
  uVar4 = thunk_FUN_1802c43a0(uVar4);
  FUN_1815b4070(uVar4,uVar3,0);
                    /* WARNING: Subroutine does not return */
  FUN_18031da90(uVar4,param_3);
}

