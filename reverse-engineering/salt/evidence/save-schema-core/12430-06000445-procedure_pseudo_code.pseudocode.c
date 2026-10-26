// Ghidra pseudocode; not original source or compilable C.
// ev_d8ea2c97ce41246d51a44007e0bf42f8db7d8f4e7f04e39b3e523186235b47f0

longlong *
ES3Types_ES3Type__ReadProperties__06000445(longlong param_1,longlong *param_2,longlong *param_3)

{
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  uint uVar9;
  longlong *plVar10;
  longlong alStack_e8 [2];
  longlong *plStack_d8;
  longlong *plStack_d0;
  longlong lStack_c8;
  longlong lStack_c0;
  longlong lStack_b8;
  longlong *plStack_b0;
  longlong lStack_a8;
  longlong *plStack_a0;
  longlong lStack_98;
  undefined8 uStack_90;
  longlong *plStack_88;
  longlong *plStack_80;
  longlong *plStack_78;
  longlong *plStack_70;
  
  plStack_78 = param_3;
  plStack_70 = param_2;
  if (cRam0000000182eb7ed1 == '\0') {
    FUN_1802f2810(0x182d68bd8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68aa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d56230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68a98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d56220);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68a90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68a88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68a80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53358);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68a78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68a70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68a68);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68bd0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53498);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68c10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52f28);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68c08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d626c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52f00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68a60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68ab8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68a58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68a50);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ed1 = '\x01';
  }
  plVar10 = (longlong *)0x0;
  lStack_b8 = 0;
  lStack_c8 = 0;
  alStack_e8[0] = 0;
  if ((param_2 == (longlong *)0x0) ||
     (lVar2 = (**(code **)(*param_2 + 0x3a8))(param_2,*(undefined8 *)(*param_2 + 0x3b0)), lVar2 == 0
     )) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  lStack_a8 = ES3ReaderPropertyEnumerator__GetEnumerator__0600019e(lVar2,0);
  uStack_90 = 0;
  plStack_88 = &lStack_a8;
  plStack_80 = &lStack_c8;
  do {
    if (lStack_a8 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    cVar1 = FUN_180002c20(0,DAT_182d52f28);
    if (cVar1 == '\0') {
      lVar2 = FUN_1802c42e0(*plStack_88,DAT_182d53498);
      *plStack_80 = lVar2;
      if (lVar2 != 0) {
        FUN_180002c20(0,DAT_182d53498,lVar2);
      }
      return param_3;
    }
    if (lStack_a8 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    plVar3 = (longlong *)FUN_180002c20(1,DAT_182d52f28);
    plVar4 = plVar10;
    if (plVar3 != (longlong *)0x0) {
      if (*plVar3 == DAT_182d52f00) {
        plVar4 = plVar3;
      }
      if (plVar4 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031e210(plVar3);
      }
    }
    lStack_98 = 0;
    plVar3 = plVar10;
    while( true ) {
      lVar2 = *(longlong *)(param_1 + 0x10);
      if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uVar9 = (uint)plVar3;
      if ((int)*(uint *)(lVar2 + 0x18) <= (int)uVar9) goto code_r0x00018055280f;
      if (*(uint *)(lVar2 + 0x18) <= uVar9) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      lVar2 = *(longlong *)(lVar2 + 0x20 + (longlong)(int)uVar9 * 8);
      if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      plVar3 = *(longlong **)(lVar2 + 0x10);
      if ((plVar3 == plVar4) ||
         ((((plVar3 != (longlong *)0x0 && (plVar4 != (longlong *)0x0)) &&
           ((int)plVar3[2] == (int)plVar4[2])) &&
          (cVar1 = FUN_181630ad0((longlong)plVar3 + 0x14,(longlong)plVar4 + 0x14,
                                 (longlong)(int)plVar3[2] * 2,0), cVar1 != '\0')))) break;
      plVar3 = (longlong *)(ulonglong)(uVar9 + 1);
    }
    lVar2 = *(longlong *)(param_1 + 0x10);
    if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(uint *)(lVar2 + 0x18) <= uVar9) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    lStack_98 = *(longlong *)(lVar2 + 0x20 + (longlong)(int)uVar9 * 8);
code_r0x00018055280f:
    if (plVar4 == plRam0000000182d68ab8) {
code_r0x000180552858:
      if (param_3 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      plVar4 = (longlong *)FUN_1802c5ac0(*plStack_78 + 0x20);
      if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (plVar4 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uVar5 = (**(code **)(*plVar4 + 0x818))(plVar4,*(undefined8 *)(*plVar4 + 0x820));
      if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      plVar4 = (longlong *)ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(uVar5,1,0);
      uVar5 = uRam0000000182d68bd0;
      plStack_b0 = plVar4;
      if (plVar4 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      if (*(char *)((longlong)plVar4 + 0x23) == '\0') {
        if (*(char *)((longlong)plVar4 + 0x22) != '\0') {
          lVar2 = FUN_1800036a0(uRam0000000182d68a68,plVar4,param_2);
          uVar5 = uRam0000000182d68c10;
          plVar3 = plVar10;
          if ((lVar2 != 0) &&
             (plVar3 = (longlong *)FUN_1802c42e0(lVar2,uRam0000000182d68c10),
             plVar3 == (longlong *)0x0)) {
                    /* WARNING: Subroutine does not return */
            FUN_18031e210(lVar2,uVar5);
          }
          plStack_a0 = plVar3;
          lVar2 = FUN_1802c5ac0(*plVar4 + 0x20);
          uVar5 = uRam0000000182d68a88;
          lStack_c0 = lVar2;
          if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          lVar6 = FUN_181638ed0(uVar5,0);
          uVar5 = uRam0000000182d68a80;
          if (lVar2 == lVar6) {
            if (plVar3 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            alStack_e8[0] = FUN_180002c20(0,uRam0000000182d68c10,plVar3);
            alStack_e8[1] = 0;
            plStack_d8 = alStack_e8;
            plStack_d0 = &lStack_c8;
            while( true ) {
              if (alStack_e8[0] == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              cVar1 = FUN_180002c20(0,DAT_182d52f28);
              if (cVar1 == '\0') break;
              if (alStack_e8[0] == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              FUN_180002c20(1,DAT_182d52f28);
              uVar5 = uRam0000000182d68c08;
              lVar2 = FUN_1802c42e0(param_3,uRam0000000182d68c08);
              uVar8 = uRam0000000182d68c08;
              if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031e210(param_3,uVar5);
              }
              lVar2 = FUN_1802c42e0(param_3,uRam0000000182d68c08);
              if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031e210(param_3,uVar8);
              }
              FUN_180007ad0(2,uRam0000000182d68c08,lVar2);
            }
            FUN_1803c3ba0(&plStack_d8);
          }
          else {
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            lVar6 = FUN_181638ed0(uVar5,0);
            uVar5 = uRam0000000182d68a78;
            if (lVar2 == lVar6) {
              plVar4 = (longlong *)plVar4[3];
              if (plVar4 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              if (lRam0000000182d68a50 == 0) {
                uVar5 = thunk_FUN_1802f2810(&DAT_182d528c8);
                uVar5 = thunk_FUN_1802c43a0(uVar5);
                uVar8 = thunk_FUN_1802f2810(&DAT_182d67ed0);
                FUN_1815c6a10(uVar5,uVar8,0);
                uVar8 = thunk_FUN_1802f2810(&DAT_182d27848);
                    /* WARNING: Subroutine does not return */
                FUN_18031da90(uVar5,uVar8);
              }
              lVar2 = (**(code **)(*plVar4 + 0x748))
                                (plVar4,lRam0000000182d68a50,0x1c,0,3,0,0,
                                 *(undefined8 *)(*plVar4 + 0x750));
              if (plVar3 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              alStack_e8[0] = FUN_180002c20(0,uRam0000000182d68c10,plVar3);
              alStack_e8[1] = 0;
              plStack_d8 = alStack_e8;
              plStack_d0 = &lStack_c8;
              while( true ) {
                if (alStack_e8[0] == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                cVar1 = FUN_180002c20(0,DAT_182d52f28);
                if (cVar1 == '\0') break;
                if (alStack_e8[0] == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                lVar6 = FUN_180002c20(1,DAT_182d52f28);
                plVar4 = (longlong *)FUN_1802c36c0(DAT_182d626c0,1);
                if (plVar4 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                if ((lVar6 != 0) &&
                   (lVar7 = FUN_1802c42e0(lVar6,*(undefined8 *)(*plVar4 + 0x40)), lVar7 == 0)) {
                  uVar5 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                  FUN_18031da90(uVar5,0);
                }
                FUN_180002cd0(plVar4,0,lVar6);
                if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                FUN_1801ec1a0(0x20,lVar2,param_3,0,0,plVar4,0);
              }
              FUN_1803c3ba0(&plStack_d8);
            }
            else {
              if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              lVar6 = FUN_181638ed0(uVar5,0);
              uVar5 = uRam0000000182d68a90;
              if (lVar2 == lVar6) {
                plVar4 = (longlong *)plVar4[3];
                if (plVar4 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                if (lRam0000000182d68a58 == 0) {
                  uVar5 = thunk_FUN_1802f2810(&DAT_182d528c8);
                  uVar5 = thunk_FUN_1802c43a0(uVar5);
                  uVar8 = thunk_FUN_1802f2810(&DAT_182d67ed0);
                  FUN_1815c6a10(uVar5,uVar8,0);
                  uVar8 = thunk_FUN_1802f2810(&DAT_182d27848);
                    /* WARNING: Subroutine does not return */
                  FUN_18031da90(uVar5,uVar8);
                }
                lVar2 = (**(code **)(*plVar4 + 0x748))
                                  (plVar4,lRam0000000182d68a58,0x1c,0,3,0,0,
                                   *(undefined8 *)(*plVar4 + 0x750));
                if (plVar3 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                alStack_e8[0] = FUN_180002c20(0,uRam0000000182d68c10,plVar3);
                alStack_e8[1] = 0;
                plStack_d8 = alStack_e8;
                plStack_d0 = &lStack_c8;
                while( true ) {
                  if (alStack_e8[0] == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  cVar1 = FUN_180002c20(0,DAT_182d52f28);
                  if (cVar1 == '\0') break;
                  if (alStack_e8[0] == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  lVar6 = FUN_180002c20(1,DAT_182d52f28);
                  plVar4 = (longlong *)FUN_1802c36c0(DAT_182d626c0,1);
                  if (plVar4 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  if ((lVar6 != 0) &&
                     (lVar7 = FUN_1802c42e0(lVar6,*(undefined8 *)(*plVar4 + 0x40)), lVar7 == 0)) {
                    uVar5 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                    FUN_18031da90(uVar5,0);
                  }
                  FUN_180002cd0(plVar4,0,lVar6);
                  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  FUN_1801ec1a0(0x20,lVar2,param_3,0,0,plVar4,0);
                }
                FUN_1803c3ba0(&plStack_d8);
              }
              else {
                if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                lVar6 = FUN_181638ed0(uVar5,0);
                if (lVar2 == lVar6) {
                  plVar4 = (longlong *)plVar4[3];
                  if (plVar4 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  if (lRam0000000182d68a60 == 0) {
                    uVar5 = thunk_FUN_1802f2810(&DAT_182d528c8);
                    uVar5 = thunk_FUN_1802c43a0(uVar5);
                    uVar8 = thunk_FUN_1802f2810(&DAT_182d67ed0);
                    FUN_1815c6a10(uVar5,uVar8,0);
                    uVar8 = thunk_FUN_1802f2810(&DAT_182d27848);
                    /* WARNING: Subroutine does not return */
                    FUN_18031da90(uVar5,uVar8);
                  }
                  lVar2 = (**(code **)(*plVar4 + 0x748))
                                    (plVar4,lRam0000000182d68a60,0x1c,0,3,0,0,
                                     *(undefined8 *)(*plVar4 + 0x750));
                  if (plVar3 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  alStack_e8[0] = FUN_180002c20(0,uRam0000000182d68c10,plVar3);
                  alStack_e8[1] = 0;
                  plStack_d8 = alStack_e8;
                  plStack_d0 = &lStack_c8;
                  while( true ) {
                    if (alStack_e8[0] == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    cVar1 = FUN_180002c20(0,DAT_182d52f28);
                    if (cVar1 == '\0') break;
                    if (alStack_e8[0] == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    lVar6 = FUN_180002c20(1,DAT_182d52f28);
                    plVar4 = (longlong *)FUN_1802c36c0(DAT_182d626c0,1);
                    if (plVar4 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    if ((lVar6 != 0) &&
                       (lVar7 = FUN_1802c42e0(lVar6,*(undefined8 *)(*plVar4 + 0x40)), lVar7 == 0)) {
                      uVar5 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                      FUN_18031da90(uVar5,0);
                    }
                    FUN_180002cd0(plVar4,0,lVar6);
                    if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    FUN_1801ec1a0(0x20,lVar2,param_3,0,0,plVar4,0);
                  }
                  FUN_1803c3ba0(&plStack_d8);
                }
              }
            }
          }
        }
      }
      else {
        lVar2 = FUN_1802c42e0(param_3,uRam0000000182d68bd0);
        if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031e210(param_3,uVar5);
        }
        lVar6 = FUN_1800036a0(uRam0000000182d68a70,plVar4,param_2);
        uVar5 = uRam0000000182d68bd0;
        if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        lVar7 = FUN_1802c42e0(lVar6,uRam0000000182d68bd0);
        uVar8 = uRam0000000182d68bd0;
        if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031e210(lVar6,uVar5);
        }
        lVar7 = FUN_1802c42e0(lVar6,uRam0000000182d68bd0);
        if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031e210(lVar6,uVar8);
        }
        lStack_b8 = FUN_180002c20(8,uRam0000000182d68bd0,lVar7);
        alStack_e8[1] = 0;
        plStack_d8 = &lStack_b8;
        plStack_d0 = &lStack_c8;
        while( true ) {
          if (lStack_b8 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          cVar1 = FUN_180002c20(0,DAT_182d52f28);
          if (cVar1 == '\0') break;
          if (lStack_b8 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          plVar4 = (longlong *)FUN_180002c20(1,DAT_182d52f28);
          if (plVar4 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          if (*(longlong *)(*plVar4 + 0x40) != *(longlong *)(lRam0000000182d68bd8 + 0x40)) {
                    /* WARNING: Subroutine does not return */
            FUN_18031e210(plVar4,lRam0000000182d68bd8);
          }
          FUN_180007dd0(1,uRam0000000182d68bd0,lVar2,plVar4[2],plVar4[3]);
        }
        FUN_1803c3ba0(&plStack_d8);
      }
    }
    else if (((plVar4 != (longlong *)0x0) && (plRam0000000182d68ab8 != (longlong *)0x0)) &&
            ((int)plVar4[2] == (int)plRam0000000182d68ab8[2])) {
      cVar1 = FUN_181630ad0((longlong)plVar4 + 0x14,(longlong)plRam0000000182d68ab8 + 0x14,
                            (longlong)(int)plVar4[2] * 2,0);
      if (cVar1 != '\0') goto code_r0x000180552858;
    }
    lVar2 = lStack_98;
    if (lStack_98 == 0) {
      (**(code **)(*plStack_70 + 0x3c8))(param_2,*(undefined8 *)(*plStack_70 + 0x3d0));
    }
    else {
      uVar5 = *(undefined8 *)(lStack_98 + 0x18);
      if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      plVar4 = (longlong *)ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(uVar5,1,0);
      uVar5 = uRam0000000182d68a98;
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      plVar3 = (longlong *)FUN_181638ed0(uVar5,0);
      if (plVar4 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uVar5 = FUN_1802c5ac0(*plVar4 + 0x20);
      if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (plVar3 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      cVar1 = (**(code **)(*plVar3 + 0x288))(plVar3,uVar5,*(undefined8 *)(*plVar3 + 0x290));
      uVar5 = uRam0000000182d68aa0;
      if (cVar1 == '\0') {
        if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        plVar3 = (longlong *)FUN_181638ed0(uVar5,0);
        uVar5 = FUN_1802c5ac0(*plVar4 + 0x20);
        if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (plVar3 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        cVar1 = (**(code **)(*plVar3 + 0x288))(plVar3,uVar5,*(undefined8 *)(*plVar3 + 0x290));
        if (cVar1 == '\0') {
          uVar5 = FUN_1800036a0(DAT_182d53358,param_2,plVar4);
        }
        else {
          lVar6 = *plVar4;
          if ((*(byte *)(lVar6 + 0x130) < *(byte *)(lRam0000000182d56230 + 0x130)) ||
             (*(longlong *)
               (*(longlong *)(lVar6 + 200) + -8 +
               (ulonglong)*(byte *)(lRam0000000182d56230 + 0x130) * 8) != lRam0000000182d56230)) {
                    /* WARNING: Subroutine does not return */
            FUN_18031e210(plVar4,lRam0000000182d56230);
          }
          uVar5 = (**(code **)(lVar6 + 0x1a8))(plVar4,param_2,*(undefined8 *)(lVar6 + 0x1b0));
        }
      }
      else {
        if ((*(byte *)(*plVar4 + 0x130) < *(byte *)(DAT_182d56220 + 0x130)) ||
           (*(longlong *)
             (*(longlong *)(*plVar4 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d56220 + 0x130) * 8)
            != DAT_182d56220)) {
                    /* WARNING: Subroutine does not return */
          FUN_18031e210(plVar4);
        }
        uVar5 = ES3Types_ES3DictionaryType__Read__060003f9(plVar4,param_2,0);
      }
      ES3ReflectedMember__SetValue__06000686(lVar2 + 0x28,param_3,uVar5);
    }
  } while( true );
}

