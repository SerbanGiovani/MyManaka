// Ghidra pseudocode; not original source or compilable C.
// ev_69f4bcefb57c507ca3af22d29d9c9be6d164fffdb00ba58f0c4ef6eb4302a199

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
               (undefined8 param_1,int param_2)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  float fVar5;
  float fVar6;
  int aiStackX_20 [2];
  
  if (cRam0000000182eb7ca9 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fa80);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ca9 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182eb54a5 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb54a5 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (*(char *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 8) == '\0') {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
  }
  else if ((param_2 - 0x3faU < 3) || (param_2 == 0x3fd)) {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar2 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x22,0);
    if (cVar2 == '\0') {
      return false;
    }
    if (param_2 == 0x3fa) {
      param_2 = 8;
    }
    else if (param_2 == 0x3fb) {
      param_2 = 7;
    }
    else if (param_2 == 0x3fc) {
      param_2 = 3;
    }
    else {
      if (param_2 != 0x3fd) {
        aiStackX_20[0] = param_2;
        uVar4 = il2cpp_value_box(_DAT_182d5fa80,aiStackX_20);
                    /* WARNING: Subroutine does not return */
        _PrivateImplementationDetails___ThrowSwitchExpressionException__06001e66(uVar4,0);
      }
      param_2 = 6;
    }
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
  }
  else if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182eb7a91 == '\0') {
    FUN_1802f2810(&DAT_182d5fa90,10,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a91 = '\x01';
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
  if (lVar1 != 0) {
    iVar3 = *(int *)(lVar1 + 0x7c);
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    fVar5 = ((float)iVar3 * 0.1 * 10.0 * 0.016) /
            *(float *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x38);
    fVar6 = 1.0;
    if (1.0 <= fVar5) {
      fVar6 = fVar5;
    }
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x28);
    if (lVar1 != 0) {
      iVar3 = FUN_180e71cd0(lVar1,param_2,DAT_182d5fa90);
      return (int)fVar6 <= iVar3;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

