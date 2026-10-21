// Ghidra pseudocode; not original source or compilable C.
// ev_59ac7a3262b1b2e45893f12c5e5ee8107513c3398caf8b63b91a86a18b5ea8e4

longlong UnityEngine_Object__Instantiate__060009fb
                   (longlong param_1,longlong param_2,undefined1 param_3)

{
  code *pcVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  if (cRam0000000182ec12a0 == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3aeb8);
    LOCK();
    UNLOCK();
    cRam0000000182ec12a0 = '\x01';
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
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
  if (param_2 != 0) {
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(param_2 + 0x10) != 0) {
      if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar3 = uRam0000000182d3aeb8;
      if (param_1 != 0) {
        pcVar1 = pcRam0000000182ec1308;
        if ((pcRam0000000182ec1308 == (code *)0x0) &&
           (pcVar1 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Object::Internal_CloneSingleWithParent(UnityEngine.Object,UnityEngine.Transform,System.Boolean)"
                                          ), pcVar1 == (code *)0x0)) {
          uVar3 = func_0x0001802ced60(
                                     "UnityEngine.Object::Internal_CloneSingleWithParent(UnityEngine.Object,UnityEngine.Transform,System.Boolean)"
                                     );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar3,0);
        }
        pcRam0000000182ec1308 = pcVar1;
        lVar2 = (*pcRam0000000182ec1308)(param_1,param_2,param_3);
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
        if (lVar2 != 0) {
          if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (*(longlong *)(lVar2 + 0x10) != 0) {
            return lVar2;
          }
        }
        uVar3 = thunk_FUN_1802f2810(0x182d5e168);
        uVar3 = thunk_FUN_1802c43a0(uVar3);
        uVar4 = thunk_FUN_1802f2810(0x182d3ae60);
        FUN_181f41b50(uVar3,uVar4,0);
        uVar4 = thunk_FUN_1802f2810(0x182d65788);
                    /* WARNING: Subroutine does not return */
        FUN_18031da90(uVar3,uVar4);
      }
      uVar4 = thunk_FUN_1802f2810(&DAT_182d53468);
      uVar4 = thunk_FUN_1802c43a0(uVar4);
      FUN_1815c6590(uVar4,uVar3,0);
      uVar3 = thunk_FUN_1802f2810(0x182d65700);
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar4,uVar3);
    }
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec129f == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3aeb8);
    LOCK();
    UNLOCK();
    cRam0000000182ec129f = '\x01';
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar3 = uRam0000000182d3aeb8;
  if (param_1 != 0) {
    pcVar1 = pcRam0000000182ec1300;
    if ((pcRam0000000182ec1300 == (code *)0x0) &&
       (pcVar1 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Object::Internal_CloneSingle(UnityEngine.Object)"
                                      ), pcVar1 == (code *)0x0)) {
      uVar3 = func_0x0001802ced60("UnityEngine.Object::Internal_CloneSingle(UnityEngine.Object)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar3,0);
    }
    pcRam0000000182ec1300 = pcVar1;
    lVar2 = (*pcRam0000000182ec1300)(param_1);
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
    if (lVar2 != 0) {
      if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar2 + 0x10) != 0) {
        return lVar2;
      }
    }
    uVar3 = thunk_FUN_1802f2810(0x182d5e168);
    uVar3 = thunk_FUN_1802c43a0(uVar3);
    uVar4 = thunk_FUN_1802f2810(0x182d3ae60);
    FUN_181f41b50(uVar3,uVar4,0);
    uVar4 = thunk_FUN_1802f2810(0x182d65760);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar3,uVar4);
  }
  uVar4 = thunk_FUN_1802f2810(&DAT_182d53468);
  uVar4 = thunk_FUN_1802c43a0(uVar4);
  FUN_1815c6590(uVar4,uVar3,0);
  uVar3 = thunk_FUN_1802f2810(0x182d65700);
                    /* WARNING: Subroutine does not return */
  FUN_18031da90(uVar4,uVar3);
}

