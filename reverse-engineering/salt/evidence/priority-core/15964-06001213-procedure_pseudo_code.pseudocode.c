// Ghidra pseudocode; not original source or compilable C.
// ev_24736516f54bba1b73006cd3c241d124ed7a60b0ee4eccaa08a7bdcc9af2f58a

/* WARNING: Removing unreachable block (ram,0x000180993b26) */
/* WARNING: Removing unreachable block (ram,0x000180993c72) */
/* WARNING: Removing unreachable block (ram,0x000180993b2f) */
/* WARNING: Removing unreachable block (ram,0x000180993b67) */
/* WARNING: Removing unreachable block (ram,0x000180993b6c) */
/* WARNING: Removing unreachable block (ram,0x000180993d23) */
/* WARNING: Removing unreachable block (ram,0x000180993b82) */
/* WARNING: Removing unreachable block (ram,0x000180993c79) */
/* WARNING: Removing unreachable block (ram,0x000180993dd7) */
/* WARNING: Removing unreachable block (ram,0x000180993c8d) */
/* WARNING: Removing unreachable block (ram,0x000180993ca2) */
/* WARNING: Removing unreachable block (ram,0x000180993cb1) */
/* WARNING: Removing unreachable block (ram,0x000180993cd3) */
/* WARNING: Removing unreachable block (ram,0x000180993cd8) */
/* WARNING: Removing unreachable block (ram,0x000180993ce7) */

void ExposureUnnoticed2_Object3D_Camera_TPCameraController__OnDestroy__06001213(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 auStackX_10 [3];
  
  if (cRam0000000182eb7826 == '\0') {
    FUN_1802f2810(0x182d57d38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d57d18);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c808);
    LOCK();
    UNLOCK();
    cRam0000000182eb7826 = '\x01';
  }
  uVar4 = FUN_1802c43a0(uRam0000000182d57d38);
  FUN_180665bb0(uVar4,param_1,uRam0000000182d5c808,0);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar2 = lRam0000000182d57d18;
  if (*(longlong *)(lRam0000000182d57d18 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d36a90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d36a70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d36a88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d36a80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f9b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d36a78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar2 + 0x38) == 0) {
      FUN_1803204f0(lVar2);
    }
  }
  auStackX_10[0] = 0;
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d583a0);
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d583a0 + 0xb8) + 8);
  if (lVar1 != 0) {
    cVar3 = FUN_180ebb4c0(lVar1,uVar4,auStackX_10,DAT_182d36a80);
    if (cVar3 == '\0') {
      return;
    }
    if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d583a0);
    }
    lVar1 = **(longlong **)(DAT_182d583a0 + 0xb8);
    uVar5 = *(undefined8 *)(*(longlong *)(lVar2 + 0x38) + 8);
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar5 = FUN_181638ed0(uVar5,0);
    if (lVar1 != 0) {
      cVar3 = FUN_180ebb4c0(lVar1,uVar5,&stack0x00000008,DAT_182d5f9b8);
      if (cVar3 != '\0') {
        if (DAT_182ebbb86 == '\0') {
          FUN_1802f2810(&DAT_182d535d8);
          LOCK();
          UNLOCK();
          DAT_182ebbb86 = '\x01';
        }
        if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d583a0);
        }
        lVar1 = **(longlong **)(DAT_182d583a0 + 0xb8);
        uVar5 = *(undefined8 *)(*(longlong *)(lVar2 + 0x38) + 8);
        if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar5 = FUN_181638ed0(uVar5,0);
        if (lVar1 == 0) goto LAB_180993d1d;
        FUN_180ebb270(lVar1,uVar5,DAT_182d36a88);
      }
      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d583a0);
      }
      lVar2 = *(longlong *)(*(longlong *)(DAT_182d583a0 + 0xb8) + 8);
      if (lVar2 != 0) {
        FUN_180ebb270(lVar2,uVar4,DAT_182d36a70);
        return;
      }
    }
  }
LAB_180993d1d:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

