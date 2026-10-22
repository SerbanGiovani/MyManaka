// Ghidra pseudocode; not original source or compilable C.
// ev_1610f1899c45f448e23c89c73292250de1e4bdab5a65a4d9506e0c6a812c2574

bool ExposureUnnoticed2_Scripts_InGame_ObjectCulling_ObjectCullerManager__IsCulling__060016d4
               (longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  longlong *plVar6;
  bool bVar7;
  
  lVar1 = *(longlong *)(param_1 + 0x20);
  uVar5 = 0;
  bVar7 = false;
  if (lVar1 != 0) {
    plVar6 = (longlong *)(lVar1 + 0x20);
    while( true ) {
      if (*(int *)(lVar1 + 0x18) <= (int)uVar5) {
        return bVar7;
      }
      if (*(uint *)(lVar1 + 0x18) <= uVar5) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      lVar2 = *plVar6;
      if (lVar2 == 0) break;
      if (cRam0000000182eb7a6f == '\0') {
        FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        cRam0000000182eb7a6f = '\x01';
      }
      lVar3 = *(longlong *)(lVar2 + 0x28);
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
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
      if (lVar3 == 0) {
code_r0x0001804ada62:
        bVar7 = false;
      }
      else {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (*(longlong *)(lVar3 + 0x10) == 0) goto code_r0x0001804ada62;
        lVar3 = *(longlong *)(lVar2 + 0x28);
        if (lVar3 == 0) break;
        if (cRam0000000182eb7a6a == '\0') {
          FUN_1802f2810(0x182d5fca0);
          LOCK();
          UNLOCK();
          cRam0000000182eb7a6a = '\x01';
        }
        lVar3 = *(longlong *)(lVar3 + 0x20);
        if (lVar3 == 0) break;
        iVar4 = FUN_180e9f040(lVar3,param_2,
                              *(undefined8 *)
                               (*(longlong *)(*(longlong *)(lRam0000000182d5fca0 + 0x20) + 0xc0) +
                               0xf8));
        if (iVar4 < 0) goto code_r0x0001804ada62;
        bVar7 = *(char *)(lVar2 + 0x38) == '\0';
        if (*(char *)(lVar2 + 0x38) == '\0') {
          return true;
        }
      }
      uVar5 = uVar5 + 1;
      plVar6 = plVar6 + 1;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

