// Ghidra pseudocode; not original source or compilable C.
// ev_4abcc45536f44278edc2a600c0928ce8754b8cba1386de301cca5dd37f3b8f2a

ulonglong ExposureUnnoticed2_Scripts_UI_TitleSceneView___Awake_b__30_17__060013c0
                    (longlong param_1,longlong *param_2)

{
  ulonglong *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb78ca == '\0') {
    FUN_1802f2810(0x182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bd80);
    LOCK();
    UNLOCK();
    cRam0000000182eb78ca = '\x01';
  }
  *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;
  uVar4 = uRam0000000182d58238;
  lVar2 = **(longlong **)(uRam0000000182d58238 + 0xb8);
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (param_2 == (longlong *)0x0) {
    *(undefined8 *)(lVar2 + 0x2d0) = 0;
  }
  else {
    if ((*(byte *)(*param_2 + 0x130) < *(byte *)(lRam0000000182d5bd80 + 0x130)) ||
       (*(longlong *)
         (*(longlong *)(*param_2 + 200) + -8 +
         (ulonglong)*(byte *)(lRam0000000182d5bd80 + 0x130) * 8) != lRam0000000182d5bd80)) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(param_2);
    }
    *(longlong **)(lVar2 + 0x2d0) = param_2;
    if ((*(byte *)(*param_2 + 0x130) < *(byte *)(lRam0000000182d5bd80 + 0x130)) ||
       (uVar4 = *(ulonglong *)(*param_2 + 200),
       *(longlong *)((uVar4 - 8) + (ulonglong)*(byte *)(lRam0000000182d5bd80 + 0x130) * 8) !=
       lRam0000000182d5bd80)) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(param_2);
    }
  }
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(lVar2 + 0x2d0U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar4 = *puVar1;
      bVar6 = uVar3 == uVar4;
      if (bVar6) {
        *puVar1 = uVar3 | 1L << (uVar5 & 0x3f);
        uVar4 = uVar3;
      }
      UNLOCK();
    } while (!bVar6);
  }
  return uVar4;
}

