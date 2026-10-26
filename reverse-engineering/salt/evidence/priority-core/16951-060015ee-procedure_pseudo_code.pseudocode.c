// Ghidra pseudocode; not original source or compilable C.
// ev_ac78ffc24b98a6551fb9b364652d907cf9adbb46668c0a43fa3e71055fefec9e

ulonglong ExposureUnnoticed2_Scripts_InGame_RandomMissionManager__StartMission__060015ee
                    (longlong param_1,undefined4 param_2,int param_3,char param_4)

{
  ulonglong *puVar1;
  int iVar2;
  ulonglong uVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  code *pcVar12;
  ulonglong uVar13;
  uint uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  bool bVar17;
  undefined4 uVar18;
  longlong lStack_38;
  undefined *puStack_30;
  
  if (cRam0000000182eb79f3 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60300);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d602f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d602f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d602e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e108);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d602e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d55000);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d602d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d602d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60310);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d602c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d602c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d602b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d602b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d602a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d602a0);
    LOCK();
    UNLOCK();
    cRam0000000182eb79f3 = '\x01';
  }
  lVar5 = FUN_1802c43a0(uRam0000000182d602a0);
  puStack_30 = (undefined *)lVar5;
  if (lVar5 != 0) {
    bVar17 = DAT_182eb5d50 != 0;
    *(longlong *)(lVar5 + 0x10) = param_1;
    if (bVar17) {
      uVar14 = (uint)(lVar5 + 0x10U >> 0xc);
      uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
      do {
        uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
        LOCK();
        bVar17 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
        if (bVar17) {
          *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) = uVar3 | 1L << (uVar14 & 0x3f);
        }
        UNLOCK();
      } while (!bVar17);
    }
    *(undefined4 *)(lVar5 + 0x18) = param_2;
    *(undefined4 *)(param_1 + 0x30) = param_2;
    if (param_4 != '\0') {
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
    plVar4 = *(longlong **)(param_1 + 0x28);
    if (plVar4 != (longlong *)0x0) {
      (**(code **)(*plVar4 + 0x1d8))(plVar4,*(undefined8 *)(*plVar4 + 0x1e0));
      *(undefined1 *)(param_1 + 0x10) = 1;
      uVar15 = 2;
      uVar16 = 1;
      if (param_3 == -1) {
        *(undefined4 *)(param_1 + 0x14) = 0x1e;
        uVar18 = 2;
      }
      else if (param_3 == 10) {
        *(undefined4 *)(param_1 + 0x14) = 10;
        uVar18 = 0;
      }
      else {
        if (param_3 != 0x14) {
          lStack_38 = CONCAT44(lStack_38._4_4_,param_3);
          uVar15 = il2cpp_value_box(DAT_182d55000,&lStack_38);
                    /* WARNING: Subroutine does not return */
          _PrivateImplementationDetails___ThrowSwitchExpressionException__06001e66(uVar15,0);
        }
        *(undefined4 *)(param_1 + 0x14) = 0x14;
        uVar18 = 1;
      }
      *(undefined4 *)(param_1 + 0x34) = uVar18;
      if ((**(longlong **)(lRam0000000182d5e190 + 0xb8) != 0) &&
         (lVar11 = *(longlong *)(**(longlong **)(lRam0000000182d5e190 + 0xb8) + 0x18), lVar11 != 0))
      {
        uVar6 = FUN_180e75f20(lVar11,*(undefined4 *)(lVar5 + 0x18),uRam0000000182d5e1d8);
        uVar7 = FUN_1802c43a0(uRam0000000182d602e0);
        FUN_1810d6200(uVar7,lVar5,uRam0000000182d602c8,0);
        lVar8 = FUN_18098e920(uVar6,uVar7,uRam0000000182d602f0);
        lVar11 = lRam0000000182d602f8;
        if (*(longlong *)(lRam0000000182d602f8 + 0x38) == 0) {
          FUN_1803204f0(lRam0000000182d602f8);
        }
        if (lVar8 == 0) {
          uVar15 = thunk_FUN_1802f2810(&DAT_182d438a8);
          uVar15 = FUN_1816e95a0(uVar15,0);
                    /* WARNING: Subroutine does not return */
          FUN_18031da90(uVar15,lVar11);
        }
        lVar9 = *(longlong *)(*(longlong *)(lVar11 + 0x38) + 8);
        if ((*(byte *)(lVar9 + 0x135) & 1) == 0) {
          lVar9 = FUN_180320470(lVar9);
        }
        lVar9 = FUN_1802c43a0(lVar9);
        FUN_181273d70(lVar9,lVar8,*(undefined8 *)(*(longlong *)(lVar11 + 0x38) + 0x10));
        if ((**(longlong **)(lRam0000000182d5e190 + 0xb8) != 0) &&
           (lVar11 = *(longlong *)(**(longlong **)(lRam0000000182d5e190 + 0xb8) + 0x18), lVar11 != 0
           )) {
          uVar6 = FUN_180e75f20(lVar11,*(undefined4 *)(lVar5 + 0x18),uRam0000000182d5e1d8);
          uVar7 = FUN_1802c43a0(uRam0000000182d602e0);
          FUN_1810d6200(uVar7,lVar5,uRam0000000182d602c0,0);
          lVar8 = FUN_18098e920(uVar6,uVar7,uRam0000000182d602f0);
          lVar11 = lRam0000000182d602f8;
          if (*(longlong *)(lRam0000000182d602f8 + 0x38) == 0) {
            FUN_1803204f0(lRam0000000182d602f8);
          }
          if (lVar8 == 0) {
            uVar15 = thunk_FUN_1802f2810(&DAT_182d438a8);
            uVar15 = FUN_1816e95a0(uVar15,0);
                    /* WARNING: Subroutine does not return */
            FUN_18031da90(uVar15,lVar11);
          }
          lVar10 = *(longlong *)(*(longlong *)(lVar11 + 0x38) + 8);
          if ((*(byte *)(lVar10 + 0x135) & 1) == 0) {
            lVar10 = FUN_180320470(lVar10);
          }
          lStack_38 = FUN_1802c43a0(lVar10);
          FUN_181273d70(lStack_38,lVar8,*(undefined8 *)(*(longlong *)(lVar11 + 0x38) + 0x10));
          if ((**(longlong **)(lRam0000000182d5e190 + 0xb8) != 0) &&
             (lVar11 = *(longlong *)(**(longlong **)(lRam0000000182d5e190 + 0xb8) + 0x18),
             lVar11 != 0)) {
            uVar6 = FUN_180e75f20(lVar11,*(undefined4 *)(lVar5 + 0x18),uRam0000000182d5e1d8);
            uVar7 = FUN_1802c43a0(uRam0000000182d602e0);
            FUN_1810d6200(uVar7,lVar5,uRam0000000182d602b8,0);
            lVar11 = FUN_18098e920(uVar6,uVar7,uRam0000000182d602f0);
            lVar5 = lRam0000000182d602f8;
            if (*(longlong *)(lRam0000000182d602f8 + 0x38) == 0) {
              FUN_1803204f0(lRam0000000182d602f8);
            }
            if (lVar11 == 0) {
              uVar15 = thunk_FUN_1802f2810(&DAT_182d438a8);
              uVar15 = FUN_1816e95a0(uVar15,0);
                    /* WARNING: Subroutine does not return */
              FUN_18031da90(uVar15,lVar5);
            }
            lVar8 = *(longlong *)(*(longlong *)(lVar5 + 0x38) + 8);
            if ((*(byte *)(lVar8 + 0x135) & 1) == 0) {
              lVar8 = FUN_180320470(lVar8);
            }
            lVar8 = FUN_1802c43a0(lVar8);
            FUN_181273d70(lVar8,lVar11,*(undefined8 *)(*(longlong *)(lVar5 + 0x38) + 0x10));
            if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
              FUN_18035c820();
            }
            FUN_18099f300(lVar9,uRam0000000182d602e8);
            lVar5 = lStack_38;
            FUN_18099f300(lStack_38,uRam0000000182d602e8);
            FUN_18099f300(lVar8,uRam0000000182d602e8);
            if (param_3 < 1) {
              lVar11 = *(longlong *)(param_1 + 0x18);
              if (lVar11 != 0) {
                iVar2 = *(int *)(lVar11 + 0x18);
                *(int *)(lVar11 + 0x1c) = *(int *)(lVar11 + 0x1c) + 1;
                *(undefined4 *)(lVar11 + 0x18) = 0;
                if (0 < iVar2) {
                  FUN_181646f50(*(undefined8 *)(lVar11 + 0x10),0,iVar2,0);
                }
                lVar11 = *(longlong *)(param_1 + 0x18);
                if ((lVar9 != 0) &&
                   (uVar15 = FUN_180985fb0(lVar9,*(undefined4 *)(lVar9 + 0x18),uRam0000000182d60300)
                   , lVar11 != 0)) {
                  FUN_181274b10(lVar11,*(undefined4 *)(lVar11 + 0x18),uVar15,
                                *(undefined8 *)
                                 (*(longlong *)(*(longlong *)(lRam0000000182d602d8 + 0x20) + 0xc0) +
                                 0x90));
                  lVar11 = *(longlong *)(param_1 + 0x18);
                  if ((lVar5 != 0) &&
                     (uVar15 = FUN_180985fb0(lVar5,*(undefined4 *)(lVar5 + 0x18),
                                             uRam0000000182d60300), lVar11 != 0)) {
                    FUN_181274b10(lVar11,*(undefined4 *)(lVar11 + 0x18),uVar15,
                                  *(undefined8 *)
                                   (*(longlong *)(*(longlong *)(lRam0000000182d602d8 + 0x20) + 0xc0)
                                   + 0x90));
                    lVar5 = *(longlong *)(param_1 + 0x18);
                    if ((lVar8 != 0) &&
                       (uVar15 = FUN_180985fb0(lVar8,*(undefined4 *)(lVar8 + 0x18),
                                               uRam0000000182d60300), lVar5 != 0)) {
                      lVar11 = *(longlong *)(*(longlong *)(lRam0000000182d602d8 + 0x20) + 0xc0);
code_r0x00018049afda:
                      FUN_181274b10(lVar5,*(undefined4 *)(lVar5 + 0x18),uVar15,
                                    *(undefined8 *)(lVar11 + 0x90));
                      *(undefined4 *)(param_1 + 0x20) = 0;
                      uVar15 = FUN_1802c43a0(DAT_182d58368);
                      FUN_1814df680(uVar15,puStack_30,uRam0000000182d602b0,0);
                      uVar16 = FUN_1802c43a0(uRam0000000182d5e108);
                      FUN_180005c40(uVar16,puStack_30,uRam0000000182d602a8);
                      if (cRam0000000182eb7aa4 == '\0') {
                        FUN_1802f2810(0x182d5f8e8,uVar16,0x41200000,0);
                        LOCK();
                        UNLOCK();
                        FUN_1802f2810(0x182d5f8e0);
                        LOCK();
                        UNLOCK();
                        cRam0000000182eb7aa4 = '\x01';
                      }
                      lVar5 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
                      if (lVar5 != 0) {
                        lVar5 = *(longlong *)(lVar5 + 0x50);
                        lVar11 = FUN_1802c43a0(uRam0000000182d5f8e8);
                        *(undefined8 *)(lVar11 + 0x10) = uVar15;
                        if (DAT_182eb5d50 != 0) {
                          uVar14 = (uint)(lVar11 + 0x10U >> 0xc);
                          uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                          do {
                            uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
                            LOCK();
                            bVar17 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
                            if (bVar17) {
                              *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) =
                                   uVar3 | 1L << (uVar14 & 0x3f);
                            }
                            UNLOCK();
                          } while (!bVar17);
                        }
                        iVar2 = DAT_182eb5d50;
                        *(undefined8 *)(lVar11 + 0x18) = uVar16;
                        if (iVar2 != 0) {
                          uVar14 = (uint)(lVar11 + 0x18U >> 0xc);
                          uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                          do {
                            uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
                            LOCK();
                            bVar17 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
                            if (bVar17) {
                              *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) =
                                   uVar3 | 1L << (uVar14 & 0x3f);
                            }
                            UNLOCK();
                          } while (!bVar17);
                        }
                        pcVar12 = DAT_182ec14c0;
                        if ((DAT_182ec14c0 == (code *)0x0) &&
                           (pcVar12 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"),
                           pcVar12 == (code *)0x0)) {
                          uVar15 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar15,0);
                        }
                        DAT_182ec14c0 = pcVar12;
                        uVar18 = (*DAT_182ec14c0)();
                        *(undefined4 *)(lVar11 + 0x24) = uVar18;
                        *(undefined4 *)(lVar11 + 0x20) = 0x41200000;
                        lVar8 = lRam0000000182d5f8e0;
                        if (lVar5 != 0) {
                          lVar9 = *(longlong *)(lVar5 + 0x10);
                          *(int *)(lVar5 + 0x1c) = *(int *)(lVar5 + 0x1c) + 1;
                          if (lVar9 == 0) {
                    /* WARNING: Subroutine does not return */
                            puStack_30 = &UNK_180006a0d;
                            FUN_18031dad0();
                          }
                          uVar14 = *(uint *)(lVar5 + 0x18);
                          if (uVar14 < *(uint *)(lVar9 + 0x18)) {
                            uVar13 = (ulonglong)(uVar14 + 1);
                            *(uint *)(lVar5 + 0x18) = uVar14 + 1;
                            if (*(uint *)(lVar9 + 0x18) <= uVar14) {
                    /* WARNING: Subroutine does not return */
                              puStack_30 = &UNK_180002d3b;
                              FUN_18031dae0();
                            }
                            bVar17 = DAT_182eb5d50 != 0;
                            *(longlong *)(lVar9 + 0x20 + (longlong)(int)uVar14 * 8) = lVar11;
                            if (bVar17) {
                              uVar14 = (uint)((ulonglong)(lVar9 + ((longlong)(int)uVar14 + 4) * 8)
                                             >> 0xc);
                              puVar1 = (ulonglong *)
                                       (&DAT_182f0c920 + (ulonglong)((uVar14 & 0x1fffff) >> 6) * 8);
                              do {
                                uVar3 = *puVar1;
                                LOCK();
                                uVar13 = *puVar1;
                                bVar17 = uVar3 == uVar13;
                                if (bVar17) {
                                  *puVar1 = uVar3 | 1L << (uVar14 & 0x3f);
                                  uVar13 = uVar3;
                                }
                                UNLOCK();
                              } while (!bVar17);
                            }
                            return uVar13;
                          }
                          iVar2 = *(int *)(lVar5 + 0x18);
                          puStack_30 = (undefined *)0x1812741f0;
                          FUN_18010dcd0(lVar5,iVar2 + 1,
                                        *(undefined8 *)
                                         (*(longlong *)
                                           (*(longlong *)
                                             (*(longlong *)
                                               (*(longlong *)(*(longlong *)(lVar8 + 0x20) + 0xc0) +
                                               0x70) + 0x20) + 0xc0) + 0x78));
                          *(int *)(lVar5 + 0x18) = iVar2 + 1;
                          if (*(longlong *)(lVar5 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
                            puStack_30 = &UNK_18127421e;
                            FUN_18031dad0();
                          }
                          uVar13 = FUN_180002cd0(*(longlong *)(lVar5 + 0x10),(longlong)iVar2,lVar11)
                          ;
                          return uVar13;
                        }
                      }
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                  }
                }
              }
            }
            else {
              if (param_3 < 0xb) {
                if (param_3 == 5) {
                  uVar6 = 2;
                }
                else {
                  if (param_3 != 10) goto code_r0x00018049b071;
                  uVar16 = 3;
                  uVar15 = 4;
                  uVar6 = 3;
                }
              }
              else if (param_3 == 0xf) {
                uVar6 = 5;
                uVar16 = 4;
                uVar15 = 6;
              }
              else {
                if (param_3 != 0x14) {
code_r0x00018049b071:
                  lStack_38 = CONCAT44(lStack_38._4_4_,param_3);
                  uVar15 = il2cpp_value_box(DAT_182d55000,&lStack_38);
                    /* WARNING: Subroutine does not return */
                  _PrivateImplementationDetails___ThrowSwitchExpressionException__06001e66(uVar15,0)
                  ;
                }
                uVar6 = 7;
                uVar16 = 5;
                uVar15 = 8;
              }
              lVar11 = *(longlong *)(param_1 + 0x18);
              if (lVar11 != 0) {
                iVar2 = *(int *)(lVar11 + 0x18);
                *(int *)(lVar11 + 0x1c) = *(int *)(lVar11 + 0x1c) + 1;
                *(undefined4 *)(lVar11 + 0x18) = 0;
                if (0 < iVar2) {
                  FUN_181646f50(*(undefined8 *)(lVar11 + 0x10),0,iVar2,0);
                }
                lVar11 = *(longlong *)(param_1 + 0x18);
                uVar16 = FUN_180985fb0(lVar9,uVar16,uRam0000000182d60300);
                if (lVar11 != 0) {
                  FUN_181274b10(lVar11,*(undefined4 *)(lVar11 + 0x18),uVar16,
                                *(undefined8 *)
                                 (*(longlong *)(*(longlong *)(lRam0000000182d602d8 + 0x20) + 0xc0) +
                                 0x90));
                  lVar11 = *(longlong *)(param_1 + 0x18);
                  uVar15 = FUN_180985fb0(lVar5,uVar15,uRam0000000182d60300);
                  if (lVar11 != 0) {
                    FUN_181274b10(lVar11,*(undefined4 *)(lVar11 + 0x18),uVar15,
                                  *(undefined8 *)
                                   (*(longlong *)(*(longlong *)(lRam0000000182d602d8 + 0x20) + 0xc0)
                                   + 0x90));
                    lVar5 = *(longlong *)(param_1 + 0x18);
                    uVar15 = FUN_180985fb0(lVar8,uVar6,uRam0000000182d60300);
                    if (lVar5 != 0) {
                      lVar11 = *(longlong *)(*(longlong *)(lRam0000000182d602d8 + 0x20) + 0xc0);
                      goto code_r0x00018049afda;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

