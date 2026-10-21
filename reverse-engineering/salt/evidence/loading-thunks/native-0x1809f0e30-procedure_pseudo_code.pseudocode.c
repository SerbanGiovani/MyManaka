// Ghidra pseudocode; not original source or compilable C.
// ev_a53521b50518911c4a24fc82936727a1fb7408a4c7db258054455957dc9de557

longlong native_only_1809f0e30__00000000(longlong param_1,longlong param_2)

{
  code *pcVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  if (*(longlong *)(param_2 + 0x38) == 0) {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3aeb8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_2 + 0x38) == 0) {
      FUN_1803204f0(param_2);
    }
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar5 = uRam0000000182d3aeb8;
  if (param_1 == 0) {
    uVar6 = thunk_FUN_1802f2810(&DAT_182d53468);
    uVar6 = thunk_FUN_1802c43a0(uVar6);
    FUN_1815c6590(uVar6,uVar5,0);
    uVar5 = thunk_FUN_1802f2810(0x182d65700);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar6,uVar5);
  }
  pcVar1 = pcRam0000000182ec1300;
  if ((pcRam0000000182ec1300 == (code *)0x0) &&
     (pcVar1 = (code *)FUN_1802cf0c0("UnityEngine.Object::Internal_CloneSingle(UnityEngine.Object)")
     , pcVar1 == (code *)0x0)) {
    uVar5 = func_0x0001802ced60("UnityEngine.Object::Internal_CloneSingle(UnityEngine.Object)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar5,0);
  }
  pcRam0000000182ec1300 = pcVar1;
  lVar2 = (*pcRam0000000182ec1300)(param_1);
  lVar3 = **(longlong **)(param_2 + 0x38);
  if ((*(byte *)(lVar3 + 0x135) & 1) == 0) {
    lVar3 = FUN_180320470(lVar3);
  }
  if (lVar2 == 0) {
    lVar4 = 0;
  }
  else {
    lVar4 = FUN_1802c42e0(lVar2,lVar3);
    if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(lVar2,lVar3);
    }
  }
  if (cRam0000000182ec12f3 == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec12f3 = '\x01';
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec129b == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec129b = '\x01';
  }
  if (lVar4 != 0) {
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar4 + 0x10) != 0) {
      return lVar4;
    }
  }
  uVar5 = thunk_FUN_1802f2810(0x182d5e168);
  uVar5 = thunk_FUN_1802c43a0(uVar5);
  uVar6 = thunk_FUN_1802f2810(0x182d3ae60);
  FUN_181f41b50(uVar5,uVar6,0);
                    /* WARNING: Subroutine does not return */
  FUN_18031da90(uVar5,param_2);
}

