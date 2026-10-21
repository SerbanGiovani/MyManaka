// Ghidra pseudocode; not original source or compilable C.
// ev_e91a883ad635171e34f258aae8721c1fa620cecf80c2f9a1b7bfb4b624c5960c

ulonglong ExposureUnnoticed2_Scripts_UI_TitleSceneView___Awake_b__30_2__060013b1
                    (longlong param_1,longlong *param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  longlong *plVar6;
  bool bVar7;
  
  if (cRam0000000182eb78bb == '\0') {
    FUN_1802f2810(0x182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d55b08);
    LOCK();
    UNLOCK();
    cRam0000000182eb78bb = '\x01';
  }
  *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;
  uVar4 = uRam0000000182d58238;
  if ((**(longlong **)(uRam0000000182d58238 + 0xb8) == 0) ||
     (lVar3 = *(longlong *)(**(longlong **)(uRam0000000182d58238 + 0xb8) + 0x328), lVar3 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  plVar6 = (longlong *)0x0;
  if (param_2 != (longlong *)0x0) {
    if (*param_2 == lRam0000000182d55b08) {
      plVar6 = param_2;
    }
    if (plVar6 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(param_2);
    }
  }
  if (*(uint *)(lVar3 + 0x18) < 2) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dae0();
  }
  bVar7 = DAT_182eb5d50 != 0;
  *(longlong **)(lVar3 + 0x28) = plVar6;
  if (bVar7) {
    uVar5 = (uint)(lVar3 + 0x28U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
    do {
      uVar2 = *puVar1;
      LOCK();
      uVar4 = *puVar1;
      bVar7 = uVar2 == uVar4;
      if (bVar7) {
        *puVar1 = uVar2 | 1L << (uVar5 & 0x3f);
        uVar4 = uVar2;
      }
      UNLOCK();
    } while (!bVar7);
  }
  return uVar4;
}

