// Ghidra pseudocode; not original source or compilable C.
// ev_52fccb872ca9945e4691f86012574cadd6171b324bbbbf72cf7e2dcad1f754db

void ExposureUnnoticed2_Scripts_InGame_InGameManager___Start_b__52_0__0600159b(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  if (cRam0000000182eb79de == '\0') {
    FUN_1802f2810(0x182d59ac8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d594e8);
    LOCK();
    UNLOCK();
    cRam0000000182eb79de = '\x01';
  }
  if (*(int *)(lRam0000000182d59ac8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d59ac8);
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x50);
    if (*(char *)(*(longlong *)(lRam0000000182d59ac8 + 0xb8) + 0xb) == '\0') {
      if (lVar2 == 0) goto code_r0x000180498c9c;
      FUN_18042f310(lVar2,0);
    }
    else {
      if (lVar2 == 0) goto code_r0x000180498c9c;
      *(undefined4 *)(lVar2 + 0x68) = 0;
      FUN_18042f810(lVar2,0);
    }
    if (*(longlong *)(param_1 + 0x40) != 0) {
      uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0x20);
      if (*(int *)(lRam0000000182d594e8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar4 = FUN_1804643d0(uVar1,0);
      FUN_1804fb990(uVar4,0);
      lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar2 != 0) {
        if (*(int *)(lVar2 + 0x10) != 0) {
          return;
        }
        if ((((**(longlong **)(lRam0000000182d53c48 + 0xb8) != 0) &&
             (lVar2 = *(longlong *)(**(longlong **)(lRam0000000182d53c48 + 0xb8) + 0x28), lVar2 != 0
             )) && (lVar2 = *(longlong *)(lVar2 + 0x30), lVar2 != 0)) &&
           ((lVar2 = *(longlong *)(lVar2 + 0x40), lVar2 != 0 &&
            (lVar2 = *(longlong *)(lVar2 + 200), lVar2 != 0)))) {
          if (cRam0000000182eb8367 == '\0') {
            FUN_1802f2810(&DAT_182d58398);
            LOCK();
            UNLOCK();
            cRam0000000182eb8367 = '\x01';
          }
          lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar3 != 0) {
            *(undefined4 *)(lVar3 + 0x16c) = *(undefined4 *)(lVar2 + 0x10);
            *(undefined1 *)(lVar2 + 0x30) = 0;
            *(undefined1 *)(lVar2 + 0x14) = 0;
            return;
          }
        }
      }
    }
  }
code_r0x000180498c9c:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

