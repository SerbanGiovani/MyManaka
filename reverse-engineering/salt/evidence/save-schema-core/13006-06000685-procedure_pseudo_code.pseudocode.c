// Ghidra pseudocode; not original source or compilable C.
// ev_35dd16ad7610ecb8e60892ae8b67ad8db90eb03032698c9e0b04fb5d7209f62a

ulonglong ES3ReflectedMember___ctor__06000685(undefined8 *param_1,longlong *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  longlong *plVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  if (DAT_182eb809f == '\0') {
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a598);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a590);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a588);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182eb809f = '\x01';
  }
  uVar7 = DAT_182eb5d50;
  uVar5 = DAT_182d6a590;
  if (param_2 == (longlong *)0x0) {
    param_1[1] = 0;
    if (uVar7 != 0) {
      uVar8 = (uint)((ulonglong)(param_1 + 1) >> 0xc);
      lVar1 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
      do {
        uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        bVar9 = uVar6 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
        if (bVar9) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar6 | 1L << (uVar8 & 0x3f);
        }
        UNLOCK();
        uVar7 = DAT_182eb5d50;
      } while (!bVar9);
    }
    uVar6 = (ulonglong)uVar7;
    *param_1 = 0;
    if (uVar7 != 0) {
      uVar7 = (uint)((ulonglong)param_1 >> 0xc);
      lVar1 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        bVar9 = uVar2 == uVar6;
        if (bVar9) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar7 & 0x3f);
          uVar6 = uVar2;
        }
        UNLOCK();
      } while (!bVar9);
    }
    *(undefined1 *)(param_1 + 2) = 0;
    return uVar6;
  }
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  plVar4 = (longlong *)FUN_181638ed0(uVar5,0);
  uVar5 = FUN_1802c5ac0(*param_2 + 0x20);
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (plVar4 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  cVar3 = (**(code **)(*plVar4 + 0x288))(plVar4,uVar5,*(undefined8 *)(*plVar4 + 0x290));
  *(char *)(param_1 + 2) = cVar3;
  lVar1 = *param_2;
  if (cVar3 == '\0') {
    if ((*(byte *)(lVar1 + 0x130) < *(byte *)(DAT_182d6a598 + 0x130)) ||
       (*(longlong *)
         (*(longlong *)(lVar1 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d6a598 + 0x130) * 8) !=
        DAT_182d6a598)) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(param_2);
    }
    *param_1 = param_2;
    if ((*(byte *)(*param_2 + 0x130) < *(byte *)(DAT_182d6a598 + 0x130)) ||
       (*(longlong *)
         (*(longlong *)(*param_2 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d6a598 + 0x130) * 8) !=
        DAT_182d6a598)) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(param_2);
    }
    if (DAT_182eb5d50 != 0) {
      uVar7 = (uint)((ulonglong)param_1 >> 0xc);
      lVar1 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
      do {
        uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        bVar9 = uVar6 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
        if (bVar9) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar6 | 1L << (uVar7 & 0x3f);
        }
        UNLOCK();
      } while (!bVar9);
    }
    uVar7 = DAT_182eb5d50;
    uVar6 = (ulonglong)DAT_182eb5d50;
    param_1[1] = 0;
    if (uVar7 != 0) {
      uVar7 = (uint)((ulonglong)(param_1 + 1) >> 0xc);
      lVar1 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        bVar9 = uVar2 == uVar6;
        if (bVar9) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar7 & 0x3f);
          uVar6 = uVar2;
        }
        UNLOCK();
      } while (!bVar9);
    }
  }
  else {
    if ((*(byte *)(lVar1 + 0x130) < *(byte *)(DAT_182d6a588 + 0x130)) ||
       (*(longlong *)
         (*(longlong *)(lVar1 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d6a588 + 0x130) * 8) !=
        DAT_182d6a588)) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(param_2);
    }
    param_1[1] = param_2;
    if ((*(byte *)(*param_2 + 0x130) < *(byte *)(DAT_182d6a588 + 0x130)) ||
       (*(longlong *)
         (*(longlong *)(*param_2 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d6a588 + 0x130) * 8) !=
        DAT_182d6a588)) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(param_2);
    }
    if (DAT_182eb5d50 != 0) {
      uVar7 = (uint)((ulonglong)(param_1 + 1) >> 0xc);
      lVar1 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
      do {
        uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        bVar9 = uVar6 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
        if (bVar9) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar6 | 1L << (uVar7 & 0x3f);
        }
        UNLOCK();
      } while (!bVar9);
    }
    uVar7 = DAT_182eb5d50;
    uVar6 = (ulonglong)DAT_182eb5d50;
    *param_1 = 0;
    if (uVar7 != 0) {
      uVar7 = (uint)((ulonglong)param_1 >> 0xc);
      lVar1 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        bVar9 = uVar2 == uVar6;
        if (bVar9) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar7 & 0x3f);
          uVar6 = uVar2;
        }
        UNLOCK();
      } while (!bVar9);
    }
  }
  return uVar6;
}

