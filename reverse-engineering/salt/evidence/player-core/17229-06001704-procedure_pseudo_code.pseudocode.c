// Ghidra pseudocode; not original source or compilable C.
// ev_4a1d8a0c94dcdcd551003976d3b3224d3a62e8bc7d7695976d75cddd0ee0d5cb

undefined8 ExposureUnnoticed2_Scripts_Base_InputManager__GetVector2__06001704(int param_1)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  int local_res8 [2];
  float local_res18;
  float fStackX_1c;
  
  if (DAT_182eb7a8c == '\0') {
    FUN_1802f2810(&DAT_182d5fac8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fa70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fa60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fa58);
    LOCK();
    UNLOCK();
    DAT_182eb7a8c = '\x01';
  }
  if (param_1 == 1) {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar1 = FUN_180477d40();
    if (cVar1 != '\0') {
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d5aa88);
      }
      lVar3 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x18);
      if (((lVar3 != 0) && (lVar3 = *(longlong *)(lVar3 + 0x90), lVar3 != 0)) &&
         (lVar3 = FUN_181952d80(lVar3,DAT_182d5fa70,0), lVar3 != 0)) {
        uVar4 = FUN_1800067d0(lVar3);
        local_res18 = (float)uVar4;
        fStackX_1c = (float)((ulonglong)uVar4 >> 0x20);
        iVar2 = 1;
        iVar7 = -1;
        if (local_res18 <= 0.0) {
          iVar2 = -1;
        }
        if (0.0 < fStackX_1c) {
          iVar7 = 1;
        }
        return CONCAT44(fStackX_1c * fStackX_1c * (float)iVar7,
                        (float)iVar2 * local_res18 * local_res18);
      }
      goto LAB_1804b13dc;
    }
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d5aa88);
    }
    lVar3 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x18);
    if (lVar3 == 0) goto LAB_1804b13dc;
    lVar3 = *(longlong *)(lVar3 + 0x90);
    uVar4 = DAT_182d5fa70;
  }
  else if (param_1 == 0x3ed) {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d5aa88);
    }
    lVar3 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x18);
    if (lVar3 == 0) goto LAB_1804b13dc;
    lVar3 = *(longlong *)(lVar3 + 0x90);
    uVar4 = DAT_182d5fa58;
  }
  else {
    if (param_1 != 0x3ee) {
      local_res8[0] = param_1;
      uVar4 = thunk_FUN_1802f2810(&DAT_182d5fa80);
      uVar4 = il2cpp_value_box(uVar4,local_res8);
      uVar5 = thunk_FUN_1802f2810(&DAT_182d54bf8);
      uVar5 = thunk_FUN_1802c43a0(uVar5);
      uVar6 = thunk_FUN_1802f2810(&DAT_182d5c530);
      FUN_1815c6ba0(uVar5,uVar6,uVar4,0,0);
      uVar4 = thunk_FUN_1802f2810(&DAT_182d5fa50);
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar5,uVar4);
    }
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d5aa88);
    }
    lVar3 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x18);
    if (lVar3 == 0) goto LAB_1804b13dc;
    lVar3 = *(longlong *)(lVar3 + 0x90);
    uVar4 = DAT_182d5fa60;
  }
  if ((lVar3 != 0) && (lVar3 = FUN_181952d80(lVar3,uVar4,0), lVar3 != 0)) {
    uVar4 = FUN_1800067d0(lVar3);
    return uVar4;
  }
LAB_1804b13dc:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

