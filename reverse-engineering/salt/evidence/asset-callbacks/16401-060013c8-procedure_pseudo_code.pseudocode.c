// Ghidra pseudocode; not original source or compilable C.
// ev_e246da175663afcefcc54a0baa4c3e4e5bf985960e40665e814d990fff6d81d0

longlong *
ExposureUnnoticed2_Scripts_UI_TitleSceneView___Awake_b__30_25__060013c8
          (longlong param_1,longlong *param_2)

{
  ulonglong *puVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb78d2 == '\0') {
    FUN_1802f2810(0x182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d55b08);
    LOCK();
    UNLOCK();
    cRam0000000182eb78d2 = '\x01';
  }
  *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;
  lVar2 = **(longlong **)(lRam0000000182d58238 + 0xb8);
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  plVar3 = (longlong *)0x0;
  if (param_2 == (longlong *)0x0) {
    *(undefined8 *)(lVar2 + 0x350) = 0;
  }
  else {
    plVar4 = plVar3;
    if (*param_2 == lRam0000000182d55b08) {
      plVar4 = param_2;
    }
    if (plVar4 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(param_2);
    }
    *(longlong **)(lVar2 + 0x350) = plVar4;
    if (*param_2 == lRam0000000182d55b08) {
      plVar3 = param_2;
    }
    if (plVar3 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(param_2);
    }
  }
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(lVar2 + 0x350U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
    do {
      plVar4 = (longlong *)*puVar1;
      LOCK();
      plVar3 = (longlong *)*puVar1;
      bVar6 = plVar4 == plVar3;
      if (bVar6) {
        *puVar1 = (ulonglong)plVar4 | 1L << (uVar5 & 0x3f);
        plVar3 = plVar4;
      }
      UNLOCK();
    } while (!bVar6);
  }
  return plVar3;
}

