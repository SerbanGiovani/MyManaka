// Ghidra pseudocode; not original source or compilable C.
// ev_1c2f90224ced994714cb5b2a4e5eba4c3292239c7399d06fdbd5dd9a38917a3c

void ExposureUnnoticed2_Object3D_ScenePlops_Elevator_ElevatorController__Awake__06000ad3
               (longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  undefined1 *puVar12;
  longlong lVar13;
  longlong lVar14;
  undefined8 *puVar15;
  uint uVar16;
  int iVar17;
  longlong lVar18;
  uint uVar19;
  uint uVar20;
  bool bVar21;
  
  if (cRam0000000182eb8295 == '\0') {
    FUN_1802f2810(0x182d61b70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ae40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61940);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e128);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ca38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aca0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bef0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bee8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bee0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bed8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bed0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ae38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5ac98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ca18);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bec8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bec0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6beb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6beb0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bf10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bf08);
    LOCK();
    UNLOCK();
    cRam0000000182eb8295 = '\x01';
  }
  if (DAT_182eb5490 == '\0') {
    FUN_1802f2810(&DAT_182d59260);
    LOCK();
    UNLOCK();
    DAT_182eb5490 = '\x01';
  }
  lVar9 = **(longlong **)(DAT_182d59260 + 0xb8);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12f4 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f4 = '\x01';
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
  if (lVar9 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar9 + 0x10) != 0) {
      return;
    }
  }
  FUN_18060d2b0(param_1);
  lVar9 = *(longlong *)(param_1 + 0x28);
  lVar18 = *(longlong *)(param_1 + 0x20);
  if (lVar9 != 0) {
    uVar5 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(uVar5,param_1,uRam0000000182d6bed8,0);
    uVar6 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(uVar6,param_1,uRam0000000182d6bed0,0);
    uVar7 = FUN_1802c43a0(uRam0000000182d61b70);
    FUN_180006b30(uVar7,param_1,uRam0000000182d6bee0);
    uVar8 = FUN_1802c43a0(uRam0000000182d61940);
    FUN_180006cd0(uVar8,param_1,uRam0000000182d6bee8);
    if (lVar18 != 0) {
      uVar19 = 0;
      ExposureUnnoticed2_Object3D_ScenePlops_Elevator_ElevatorBoxController__Initialize__06000ab6
                (lVar18,param_1,*(undefined4 *)(lVar9 + 0x18),uVar5,uVar6,uVar7,uVar8,0);
      if (*(longlong *)(param_1 + 0x90) != 0) {
        ExposureUnnoticed2_Object3D_ScenePlops_Elevator_ElevatorSoundController__Initialize__06000af8
                  (*(longlong *)(param_1 + 0x90),*(undefined8 *)(param_1 + 0x20),0);
        if (*(longlong *)(param_1 + 0x28) != 0) {
          uVar5 = FUN_1802c36c0(uRam0000000182d5e128,
                                *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x18));
          bVar21 = DAT_182eb5d50 != 0;
          *(undefined8 *)(param_1 + 0x78) = uVar5;
          if (bVar21) {
            uVar20 = (uint)(param_1 + 0x78U >> 0xc);
            lVar9 = (ulonglong)((uVar20 & 0x1fffff) >> 6) * 8;
            do {
              uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar9);
              LOCK();
              bVar21 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar9);
              if (bVar21) {
                *(ulonglong *)(&DAT_182f0c920 + lVar9) = uVar4 | 1L << (uVar20 & 0x3f);
              }
              UNLOCK();
            } while (!bVar21);
          }
          if (*(longlong *)(param_1 + 0x28) != 0) {
            uVar5 = FUN_1802c36c0(uRam0000000182d5e128,
                                  *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x18));
            bVar21 = DAT_182eb5d50 != 0;
            *(undefined8 *)(param_1 + 0x80) = uVar5;
            if (bVar21) {
              uVar20 = (uint)(param_1 + 0x80U >> 0xc);
              lVar9 = (ulonglong)((uVar20 & 0x1fffff) >> 6) * 8;
              do {
                uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar9);
                LOCK();
                bVar21 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar9);
                if (bVar21) {
                  *(ulonglong *)(&DAT_182f0c920 + lVar9) = uVar4 | 1L << (uVar20 & 0x3f);
                }
                UNLOCK();
              } while (!bVar21);
            }
            lVar9 = *(longlong *)(param_1 + 0x28);
            if (lVar9 != 0) {
              lVar18 = 0x20;
              uVar20 = uVar19;
              do {
                if (*(int *)(lVar9 + 0x18) <= (int)uVar20) {
                  lVar9 = *(longlong *)(param_1 + 0x40);
                  if (lVar9 != 0) {
                    puVar15 = (undefined8 *)(lVar9 + 0x20);
                    goto code_r0x000180600fe0;
                  }
                  break;
                }
                lVar9 = FUN_1802c43a0(uRam0000000182d6beb0);
                if (lVar9 == 0) break;
                bVar21 = DAT_182eb5d50 != 0;
                *(longlong *)(lVar9 + 0x18) = param_1;
                if (bVar21) {
                  uVar16 = (uint)(lVar9 + 0x18U >> 0xc);
                  lVar1 = (ulonglong)((uVar16 & 0x1fffff) >> 6) * 8;
                  do {
                    uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
                    LOCK();
                    bVar21 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
                    if (bVar21) {
                      *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar16 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar21);
                }
                lVar1 = *(longlong *)(param_1 + 0x28);
                if (lVar1 == 0) break;
                if (*(uint *)(lVar1 + 0x18) <= uVar20) goto code_r0x0001806010f6;
                if (*(longlong *)(lVar18 + lVar1) == 0) break;
                ExposureUnnoticed2_Object3D_ScenePlops_Elevator_ElevatorEntranceController__Initialize__06000aed
                          (*(longlong *)(lVar18 + lVar1),param_1,0);
                lVar1 = *(longlong *)(param_1 + 0x28);
                if (lVar1 == 0) break;
                if (*(uint *)(lVar1 + 0x18) <= uVar20) goto code_r0x0001806010f6;
                if (*(longlong *)(lVar18 + lVar1) == 0) break;
                lVar10 = FUN_180735980(*(longlong *)(lVar18 + lVar1),uRam0000000182d5ca38);
                *(uint *)(lVar9 + 0x10) = uVar20;
                lVar11 = FUN_1802c43a0(DAT_182d58368);
                lVar1 = lRam0000000182d5ca18;
                bVar21 = DAT_182eb5d50 != 0;
                *(undefined8 *)(lVar11 + 0x10) = *(undefined8 *)(lRam0000000182d5ca18 + 8);
                *(longlong *)(lVar11 + 0x28) = lVar1;
                *(undefined8 *)(lVar11 + 0x20) = 0;
                if (bVar21) {
                  uVar16 = (uint)(lVar11 + 0x20U >> 0xc);
                  lVar14 = (ulonglong)((uVar16 & 0x1fffff) >> 6) * 8;
                  do {
                    uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar14);
                    LOCK();
                    bVar21 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar14);
                    if (bVar21) {
                      *(ulonglong *)(&DAT_182f0c920 + lVar14) = uVar4 | 1L << (uVar16 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar21);
                }
                cVar3 = *(char *)(lVar1 + 0x52);
                *(longlong *)(lVar11 + 0x40) = lVar11;
                if ((*(byte *)(lVar1 + 0x4c) & 0x10) == 0) {
                  uVar5 = FUN_18031daf0();
                    /* WARNING: Subroutine does not return */
                  FUN_18031da90(uVar5,0);
                }
                if (cVar3 == '\0') {
                  puVar12 = &LAB_1800c7840;
                }
                else {
                  *(undefined8 *)(lVar11 + 0x40) = *(undefined8 *)(lVar11 + 0x20);
                  puVar12 = *(undefined1 **)(lVar11 + 0x10);
                }
                *(undefined1 **)(lVar11 + 0x18) = puVar12;
                *(code **)(lVar11 + 0x38) = FUN_1801e91e0;
                if (lVar10 == 0) break;
                ExposureUnnoticed2_Object3D_InteractArea_InteractAreaController__Initialize__06001180
                          (lVar10,lVar11,0,0);
                lVar1 = *(longlong *)(lVar10 + 0x40);
                lVar11 = FUN_1802c43a0(DAT_182d5ac98);
                if (lVar11 == 0) break;
                bVar21 = DAT_182eb5d50 != 0;
                *(undefined8 *)(lVar11 + 0x18) = uRam0000000182d6bf08;
                if (bVar21) {
                  uVar16 = (uint)(lVar11 + 0x18U >> 0xc);
                  lVar14 = (ulonglong)((uVar16 & 0x1fffff) >> 6) * 8;
                  do {
                    uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar14);
                    LOCK();
                    bVar21 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar14);
                    if (bVar21) {
                      *(ulonglong *)(&DAT_182f0c920 + lVar14) = uVar4 | 1L << (uVar16 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar21);
                }
                lVar13 = FUN_1802c43a0(DAT_182d58368);
                iVar17 = DAT_182eb5d50;
                lVar14 = lRam0000000182d6bec0;
                *(undefined8 *)(lVar13 + 0x10) = *(undefined8 *)(lRam0000000182d6bec0 + 8);
                *(longlong *)(lVar13 + 0x28) = lVar14;
                *(longlong *)(lVar13 + 0x20) = lVar9;
                if (iVar17 != 0) {
                  uVar16 = (uint)(lVar13 + 0x20U >> 0xc);
                  lVar2 = (ulonglong)((uVar16 & 0x1fffff) >> 6) * 8;
                  do {
                    uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
                    LOCK();
                    bVar21 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
                    if (bVar21) {
                      *(ulonglong *)(&DAT_182f0c920 + lVar2) =
                           uVar4 | 1L << (ulonglong)(uVar16 & 0x3f);
                    }
                    UNLOCK();
                    iVar17 = DAT_182eb5d50;
                  } while (!bVar21);
                }
                cVar3 = *(char *)(lVar14 + 0x52);
                *(longlong *)(lVar13 + 0x40) = lVar13;
                if (((*(byte *)(lVar14 + 0x4c) & 0x10) == 0) || (cVar3 != '\0')) {
                  *(undefined8 *)(lVar13 + 0x40) = *(undefined8 *)(lVar13 + 0x20);
                  puVar12 = *(undefined1 **)(lVar13 + 0x10);
                }
                else {
                  puVar12 = &LAB_1800c7840;
                }
                *(undefined1 **)(lVar13 + 0x18) = puVar12;
                *(code **)(lVar13 + 0x38) = FUN_1801e91e0;
                *(longlong *)(lVar11 + 0x10) = lVar13;
                if (iVar17 != 0) {
                  uVar16 = (uint)(lVar11 + 0x10U >> 0xc);
                  lVar14 = (ulonglong)((uVar16 & 0x1fffff) >> 6) * 8;
                  do {
                    uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar14);
                    LOCK();
                    bVar21 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar14);
                    if (bVar21) {
                      *(ulonglong *)(&DAT_182f0c920 + lVar14) = uVar4 | 1L << (uVar16 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar21);
                }
                if (lVar1 == 0) break;
                FUN_180e545f0(lVar1,0,lVar11,2,
                              *(undefined8 *)
                               (*(longlong *)(*(longlong *)(DAT_182d5aca0 + 0x20) + 0xc0) + 0x100));
                lVar1 = *(longlong *)(lVar10 + 0x40);
                lVar10 = FUN_1802c43a0(DAT_182d5ac98);
                if (lVar10 == 0) break;
                bVar21 = DAT_182eb5d50 != 0;
                *(undefined8 *)(lVar10 + 0x18) = uRam0000000182d6bf10;
                if (bVar21) {
                  uVar16 = (uint)(lVar10 + 0x18U >> 0xc);
                  lVar11 = (ulonglong)((uVar16 & 0x1fffff) >> 6) * 8;
                  do {
                    uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar11);
                    LOCK();
                    bVar21 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar11);
                    if (bVar21) {
                      *(ulonglong *)(&DAT_182f0c920 + lVar11) = uVar4 | 1L << (uVar16 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar21);
                }
                lVar14 = FUN_1802c43a0(DAT_182d58368);
                lVar11 = lRam0000000182d6beb8;
                *(undefined8 *)(lVar14 + 0x10) = *(undefined8 *)(lRam0000000182d6beb8 + 8);
                iVar17 = DAT_182eb5d50;
                *(longlong *)(lVar14 + 0x28) = lVar11;
                *(longlong *)(lVar14 + 0x20) = lVar9;
                if (iVar17 != 0) {
                  uVar16 = (uint)(lVar14 + 0x20U >> 0xc);
                  lVar9 = (ulonglong)((uVar16 & 0x1fffff) >> 6) * 8;
                  do {
                    uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar9);
                    LOCK();
                    bVar21 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar9);
                    if (bVar21) {
                      *(ulonglong *)(&DAT_182f0c920 + lVar9) =
                           uVar4 | 1L << (ulonglong)(uVar16 & 0x3f);
                    }
                    UNLOCK();
                    iVar17 = DAT_182eb5d50;
                  } while (!bVar21);
                }
                cVar3 = *(char *)(lVar11 + 0x52);
                *(longlong *)(lVar14 + 0x40) = lVar14;
                if (((*(byte *)(lVar11 + 0x4c) & 0x10) == 0) || (cVar3 != '\0')) {
                  *(undefined8 *)(lVar14 + 0x40) = *(undefined8 *)(lVar14 + 0x20);
                  puVar12 = *(undefined1 **)(lVar14 + 0x10);
                }
                else {
                  puVar12 = &LAB_1800c7840;
                }
                *(undefined1 **)(lVar14 + 0x18) = puVar12;
                *(code **)(lVar14 + 0x38) = FUN_1801e91e0;
                *(longlong *)(lVar10 + 0x10) = lVar14;
                if (iVar17 != 0) {
                  uVar16 = (uint)(lVar10 + 0x10U >> 0xc);
                  lVar9 = (ulonglong)((uVar16 & 0x1fffff) >> 6) * 8;
                  do {
                    uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar9);
                    LOCK();
                    bVar21 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar9);
                    if (bVar21) {
                      *(ulonglong *)(&DAT_182f0c920 + lVar9) = uVar4 | 1L << (uVar16 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar21);
                }
                if (lVar1 == 0) break;
                FUN_180e545f0(lVar1,1,lVar10,2,
                              *(undefined8 *)
                               (*(longlong *)(*(longlong *)(DAT_182d5aca0 + 0x20) + 0xc0) + 0x100));
                lVar9 = *(longlong *)(param_1 + 0x28);
                uVar20 = uVar20 + 1;
                lVar18 = lVar18 + 8;
              } while (lVar9 != 0);
            }
          }
        }
      }
    }
  }
DAT_1806010e0:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
code_r0x000180600fe0:
  lVar18 = lRam0000000182d6bec8;
  if (*(int *)(lVar9 + 0x18) <= (int)uVar19) {
    uVar5 = FUN_1802c43a0(uRam0000000182d5ae40);
    FUN_180665bb0(uVar5,param_1,uRam0000000182d6bef0,0);
    if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
      FUN_18035c820();
    }
    FUN_180993250(uVar5,0,uRam0000000182d5ae38);
    return;
  }
  if (*(uint *)(lVar9 + 0x18) <= uVar19) {
code_r0x0001806010f6:
                    /* WARNING: Subroutine does not return */
    FUN_18031dae0();
  }
  lVar1 = *(longlong *)(param_1 + 0xa0);
  uVar5 = *puVar15;
  if (lVar1 == 0) goto DAT_1806010e0;
  *(int *)(lVar1 + 0x1c) = *(int *)(lVar1 + 0x1c) + 1;
  lVar10 = *(longlong *)(lVar1 + 0x10);
  if (lVar10 == 0) goto DAT_1806010e0;
  uVar20 = *(uint *)(lVar1 + 0x18);
  if (uVar20 < *(uint *)(lVar10 + 0x18)) {
    *(uint *)(lVar1 + 0x18) = uVar20 + 1;
    FUN_180002cd0(lVar10,(longlong)(int)uVar20,uVar5);
    uVar19 = uVar19 + 1;
    puVar15 = puVar15 + 1;
  }
  else {
    FUN_1812741c0(lVar1,uVar5,
                  *(undefined8 *)(*(longlong *)(*(longlong *)(lVar18 + 0x20) + 0xc0) + 0x70));
    uVar19 = uVar19 + 1;
    puVar15 = puVar15 + 1;
  }
  goto code_r0x000180600fe0;
}

