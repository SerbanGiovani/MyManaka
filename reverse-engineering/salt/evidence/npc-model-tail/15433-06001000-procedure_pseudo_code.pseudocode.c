// Ghidra pseudocode; not original source or compilable C.
// ev_1309f52bebce0bcf98a15d2384c51b174f7de5b08ddeaf04e3559321fa24058a

void ExposureUnnoticed2_Object3D_NPC_Script_NpcAvatarComponent___Initialize_b__64_0__06001000
               (longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  longlong *plVar7;
  
  if (cRam0000000182eb774d == '\0') {
    FUN_1802f2810(&DAT_182d59b60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb774d = '\x01';
  }
  lVar1 = *(longlong *)(param_1 + 0xa0);
  uVar6 = 0;
  if (lVar1 != 0) {
    plVar7 = (longlong *)(lVar1 + 0x20);
    do {
      if (*(int *)(lVar1 + 0x18) <= (int)uVar6) {
        return;
      }
      if (*(uint *)(lVar1 + 0x18) <= uVar6) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      lVar2 = *plVar7;
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
      if (lVar2 != 0) {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (*(longlong *)(lVar2 + 0x10) != 0) {
          lVar3 = *(longlong *)(param_1 + 0x118);
          uVar5 = FUN_181f0db90(lVar2,0);
          if (lVar3 == 0) break;
          uVar4 = *(undefined8 *)(*(longlong *)(*(longlong *)(DAT_182d59b60 + 0x20) + 0xc0) + 0x100)
          ;
          FUN_180eba640(lVar3,lVar2,uVar5,CONCAT71((int7)((ulonglong)uVar4 >> 8),2),uVar4);
        }
      }
      uVar6 = uVar6 + 1;
      plVar7 = plVar7 + 1;
    } while( true );
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

