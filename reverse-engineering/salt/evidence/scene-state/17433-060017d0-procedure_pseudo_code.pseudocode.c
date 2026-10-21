// Ghidra pseudocode; not original source or compilable C.
// ev_2ad409f55cbdeb11ff830f29326419c69c22918aead3b20ccfd9679b99601354

longlong ExposureUnnoticed2_Scripts_Base_SystemManager__CreateIfNoExist__060017d0(void)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong *plVar9;
  
  if (cRam0000000182eb7ae7 == '\0') {
    FUN_1802f2810(&DAT_182d55b08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f428);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5bfa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f420);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ae7 = '\x01';
  }
  if (*(int *)(DAT_182d5bfa0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d5bfa0);
  }
  lVar1 = *(longlong *)(DAT_182d5bfa0 + 0xb8);
  lVar5 = *(longlong *)(lVar1 + 8);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    lVar1 = FUN_18035c820();
  }
  if (DAT_182ec12f4 == '\0') {
    lVar1 = FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f4 = '\x01';
  }
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    lVar1 = FUN_18035c820();
  }
  if (DAT_182ec129b == '\0') {
    lVar1 = FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec129b = '\x01';
  }
  if (lVar5 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      lVar1 = FUN_18035c820();
    }
    if (*(longlong *)(lVar5 + 0x10) != 0) {
      return lVar1;
    }
  }
  plVar2 = (longlong *)UnityEngine_Resources__Load__060008e7(uRam0000000182d5f420,0);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar1 = lRam0000000182d5f428;
  plVar9 = (longlong *)0x0;
  if (plVar2 != (longlong *)0x0) {
    if (*plVar2 == DAT_182d55b08) {
      plVar9 = plVar2;
    }
    if (plVar9 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(plVar2);
    }
  }
  if (*(longlong *)(lRam0000000182d5f428 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d3aeb8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar1 + 0x38) == 0) {
      FUN_1803204f0(lVar1);
    }
  }
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar7 = DAT_182d3aeb8;
  if (plVar9 == (longlong *)0x0) {
    uVar8 = thunk_FUN_1802f2810(&DAT_182d53468);
    uVar8 = thunk_FUN_1802c43a0(uVar8);
    FUN_1815c6590(uVar8,uVar7,0);
    uVar7 = thunk_FUN_1802f2810(&DAT_182d65700);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar8,uVar7);
  }
  pcVar3 = DAT_182ec1300;
  if ((DAT_182ec1300 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Object::Internal_CloneSingle(UnityEngine.Object)")
     , pcVar3 == (code *)0x0)) {
    uVar7 = FUN_1802ced60("UnityEngine.Object::Internal_CloneSingle(UnityEngine.Object)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar7,0);
  }
  DAT_182ec1300 = pcVar3;
  lVar4 = (*DAT_182ec1300)(plVar9);
  lVar5 = **(longlong **)(lVar1 + 0x38);
  if ((*(byte *)(lVar5 + 0x135) & 1) == 0) {
    lVar5 = FUN_180320470(lVar5);
  }
  if (lVar4 == 0) {
    lVar6 = 0;
  }
  else {
    lVar6 = FUN_1802c42e0(lVar4,lVar5);
    if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(lVar4,lVar5);
    }
  }
  if (DAT_182ec12f3 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f3 = '\x01';
  }
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec129b == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec129b = '\x01';
  }
  if (lVar6 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar6 + 0x10) != 0) {
      return lVar6;
    }
  }
  uVar7 = thunk_FUN_1802f2810(&DAT_182d5e168);
  uVar7 = thunk_FUN_1802c43a0(uVar7);
  uVar8 = thunk_FUN_1802f2810(&DAT_182d3ae60);
  FUN_181f41b50(uVar7,uVar8,0);
                    /* WARNING: Subroutine does not return */
  FUN_18031da90(uVar7,lVar1);
}

