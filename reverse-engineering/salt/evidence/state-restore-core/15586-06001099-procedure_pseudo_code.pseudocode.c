// Ghidra pseudocode; not original source or compilable C.
// ev_31d9fb2f12f6b71f449513457c1c91a0d2fd4e9fd55e2da9066db48ab50bdd2b

void ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__RegisterDestroy__06001099
               (longlong param_1,undefined8 param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  if (cRam0000000182eb7770 == '\0') {
    FUN_1802f2810(&DAT_182d594c0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7770 = '\x01';
  }
  lVar4 = DAT_182d594c0;
  lVar3 = *(longlong *)(param_1 + 0x78);
  if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  lVar2 = *(longlong *)(lVar3 + 0x10);
  *(int *)(lVar3 + 0x1c) = *(int *)(lVar3 + 0x1c) + 1;
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar1 = *(uint *)(lVar3 + 0x18);
  if (*(uint *)(lVar2 + 0x18) <= uVar1) {
    FUN_1812741c0(lVar3,param_2,
                  *(undefined8 *)(*(longlong *)(*(longlong *)(lVar4 + 0x20) + 0xc0) + 0x70));
    return;
  }
  *(uint *)(lVar3 + 0x18) = uVar1 + 1;
  FUN_180002cd0(lVar2,(longlong)(int)uVar1,param_2);
  return;
}

