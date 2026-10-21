// Ghidra pseudocode; not original source or compilable C.
// ev_05da9d025f9f33c90bab014782b52626f92f4639e39bc3fe19d5d90367f0843b

void UnityEngine_AssetBundle__LoadAssetAsync__0600000d(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 unaff_RDI;
  
  if (cRam0000000182ebf5f0 == '\0') {
    FUN_1802f2810(0x182d561c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    cRam0000000182ebf5f0 = '\x01';
  }
  lVar1 = lRam0000000182d561c0;
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar1 = FUN_1803613f0(lVar1,1);
    lVar1 = FUN_1802c5ac0(lVar1 + 0x20);
  }
  if (cRam0000000182ebf5f1 == '\0') {
    FUN_1802f2810(&DAT_182d535d8,param_2,lVar1,0,unaff_RDI);
    LOCK();
    UNLOCK();
    cRam0000000182ebf5f1 = '\x01';
  }
  if (param_2 == 0) {
    uVar3 = thunk_FUN_1802f2810(0x182d52778);
    uVar3 = thunk_FUN_1802c43a0(uVar3);
    uVar4 = thunk_FUN_1802f2810(0x182d5cb38);
    FUN_1815c4d30(uVar3,uVar4,0);
    uVar4 = thunk_FUN_1802f2810(0x182d5cb20);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar3,uVar4);
  }
  if (*(int *)(param_2 + 0x10) == 0) {
    uVar3 = thunk_FUN_1802f2810(&DAT_182d53468);
    uVar3 = thunk_FUN_1802c43a0(uVar3);
    uVar4 = thunk_FUN_1802f2810(0x182d5cb28);
    FUN_1815c6590(uVar3,uVar4,0);
    uVar4 = thunk_FUN_1802f2810(0x182d5cb20);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar3,uVar4);
  }
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (lVar1 == 0) {
    uVar3 = thunk_FUN_1802f2810(0x182d52778);
    uVar3 = thunk_FUN_1802c43a0(uVar3);
    uVar4 = thunk_FUN_1802f2810(0x182d5cb40);
    FUN_1815c4d30(uVar3,uVar4,0);
    uVar4 = thunk_FUN_1802f2810(0x182d5cb20);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar3,uVar4);
  }
  pcVar2 = pcRam0000000182ebf5f8;
  if ((pcRam0000000182ebf5f8 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.AssetBundle::LoadAssetAsync_Internal(System.String,System.Type)"
                                    ), pcVar2 == (code *)0x0)) {
    uVar3 = func_0x0001802ced60(
                               "UnityEngine.AssetBundle::LoadAssetAsync_Internal(System.String,System.Type)"
                               );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  pcRam0000000182ebf5f8 = pcVar2;
                    /* WARNING: Could not recover jumptable at 0x000181ef2792. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000182ebf5f8)(param_1,param_2,lVar1);
  return;
}

