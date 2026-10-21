// Ghidra pseudocode; not original source or compilable C.
// ev_0abd5321e0baffbb595bbecda84cd9ca10a35b08711f53bb0b647e6096ccc601

void UnityEngine_AssetBundle__LoadAssetAsync__0600000f
               (undefined8 param_1,longlong param_2,longlong param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (cRam0000000182ebf5f1 == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    cRam0000000182ebf5f1 = '\x01';
  }
  if (param_2 == 0) {
    uVar2 = thunk_FUN_1802f2810(0x182d52778);
    uVar2 = thunk_FUN_1802c43a0(uVar2);
    uVar3 = thunk_FUN_1802f2810(0x182d5cb38);
    FUN_1815c4d30(uVar2,uVar3,0);
    uVar3 = thunk_FUN_1802f2810(0x182d5cb20);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar2,uVar3);
  }
  if (*(int *)(param_2 + 0x10) == 0) {
    uVar2 = thunk_FUN_1802f2810(&DAT_182d53468);
    uVar2 = thunk_FUN_1802c43a0(uVar2);
    uVar3 = thunk_FUN_1802f2810(0x182d5cb28);
    FUN_1815c6590(uVar2,uVar3,0);
    uVar3 = thunk_FUN_1802f2810(0x182d5cb20);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar2,uVar3);
  }
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (param_3 == 0) {
    uVar2 = thunk_FUN_1802f2810(0x182d52778);
    uVar2 = thunk_FUN_1802c43a0(uVar2);
    uVar3 = thunk_FUN_1802f2810(0x182d5cb40);
    FUN_1815c4d30(uVar2,uVar3,0);
    uVar3 = thunk_FUN_1802f2810(0x182d5cb20);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar2,uVar3);
  }
  pcVar1 = pcRam0000000182ebf5f8;
  if ((pcRam0000000182ebf5f8 == (code *)0x0) &&
     (pcVar1 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.AssetBundle::LoadAssetAsync_Internal(System.String,System.Type)"
                                    ), pcVar1 == (code *)0x0)) {
    uVar2 = func_0x0001802ced60(
                               "UnityEngine.AssetBundle::LoadAssetAsync_Internal(System.String,System.Type)"
                               );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  pcRam0000000182ebf5f8 = pcVar1;
                    /* WARNING: Could not recover jumptable at 0x000181ef2792. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000182ebf5f8)(param_1,param_2,param_3);
  return;
}

