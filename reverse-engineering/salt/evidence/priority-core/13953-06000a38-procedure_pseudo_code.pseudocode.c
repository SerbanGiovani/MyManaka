// Ghidra pseudocode; not original source or compilable C.
// ev_fd5de987f885859b8c2a6e300bab3b326d44fbf2ed8c7518db2c4166cedebd71

/* WARNING: Removing unreachable block (ram,0x0001809936a3) */
/* WARNING: Removing unreachable block (ram,0x0001809936ab) */
/* WARNING: Removing unreachable block (ram,0x0001809936ba) */
/* WARNING: Removing unreachable block (ram,0x0001809936db) */
/* WARNING: Removing unreachable block (ram,0x0001809936e0) */
/* WARNING: Removing unreachable block (ram,0x0001809936fb) */
/* WARNING: Removing unreachable block (ram,0x000180993712) */
/* WARNING: Removing unreachable block (ram,0x00018099377e) */
/* WARNING: Removing unreachable block (ram,0x000180993717) */
/* WARNING: Removing unreachable block (ram,0x00018099371c) */
/* WARNING: Removing unreachable block (ram,0x000180993749) */
/* WARNING: Removing unreachable block (ram,0x00018099374e) */
/* WARNING: Removing unreachable block (ram,0x00018099389e) */
/* WARNING: Removing unreachable block (ram,0x00018099375a) */
/* WARNING: Removing unreachable block (ram,0x000180993781) */
/* WARNING: Removing unreachable block (ram,0x000180993775) */
/* WARNING: Removing unreachable block (ram,0x00018099378d) */
/* WARNING: Removing unreachable block (ram,0x000180993952) */
/* WARNING: Removing unreachable block (ram,0x0001809937a4) */
/* WARNING: Removing unreachable block (ram,0x0001809937a9) */
/* WARNING: Removing unreachable block (ram,0x0001809935d9) */
/* WARNING: Removing unreachable block (ram,0x0001809935de) */
/* WARNING: Removing unreachable block (ram,0x00018099360b) */
/* WARNING: Removing unreachable block (ram,0x000180993610) */
/* WARNING: Removing unreachable block (ram,0x0001809937de) */
/* WARNING: Removing unreachable block (ram,0x00018099361c) */
/* WARNING: Removing unreachable block (ram,0x000180993637) */

void ExposureUnnoticed2_Object3D_ScenePlops_WasherMachine_WasherMachineController__Start__06000a38
               (longlong param_1)

{
  ulonglong *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  char cVar6;
  int iVar7;
  undefined8 uVar8;
  code *pcVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  uint uVar14;
  undefined8 uVar15;
  undefined7 uVar16;
  bool bVar17;
  
  if (cRam0000000182eb8240 == '\0') {
    FUN_1802f2810(0x182d5ae40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d57c08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aca0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ae38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d57bf8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5ac98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c1d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c1c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c1c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c1b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c1b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c1a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c1a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c198);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c190);
    LOCK();
    UNLOCK();
    cRam0000000182eb8240 = '\x01';
  }
  lVar2 = *(longlong *)(param_1 + 0x20);
  if (lVar2 != 0) {
    uVar8 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(uVar8,param_1,uRam0000000182d6c1c8,0);
    ExposureUnnoticed2_Object3D_InteractArea_InteractAreaController__Initialize__06001180
              (lVar2,uVar8,0,0);
  }
  if (*(longlong *)(param_1 + 0x30) != 0) {
    ExposureUnnoticed2_Scripts_Sound_LoopSoundPlayer__Initailize__060013f8
              (*(longlong *)(param_1 + 0x30),0);
    uVar8 = FUN_180735660(param_1,DAT_182d53c58);
    bVar17 = DAT_182eb5d50 != 0;
    *(undefined8 *)(param_1 + 0x58) = uVar8;
    if (bVar17) {
      uVar14 = (uint)(param_1 + 0x58U >> 0xc);
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
    lVar2 = *(longlong *)(param_1 + 0x38);
    lVar10 = *(longlong *)(param_1 + 0x70);
    if (((*(longlong *)(param_1 + 0x68) != 0) &&
        (*(undefined4 *)(*(longlong *)(param_1 + 0x68) + 0x10) = 0x3f800000, lVar10 != 0)) &&
       (*(undefined4 *)(lVar10 + 0x10) = 0x3f800000, lVar2 != 0)) {
      pcVar9 = DAT_182ebf6b8;
      if ((DAT_182ebf6b8 == (code *)0x0) &&
         (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.AudioSource::set_volume(System.Single)"),
         pcVar9 == (code *)0x0)) {
        uVar8 = FUN_1802ced60("UnityEngine.AudioSource::set_volume(System.Single)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar8,0);
      }
      DAT_182ebf6b8 = pcVar9;
      (*DAT_182ebf6b8)(lVar2,0x3f800000);
      if (*(longlong *)(param_1 + 0x20) != 0) {
        lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x40);
        lVar10 = FUN_1802c43a0(DAT_182d5ac98);
        if (lVar10 != 0) {
          bVar17 = DAT_182eb5d50 != 0;
          *(undefined8 *)(lVar10 + 0x18) = uRam0000000182d6c1a0;
          if (bVar17) {
            uVar14 = (uint)(lVar10 + 0x18U >> 0xc);
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
          uVar8 = FUN_1802c43a0(DAT_182d58368);
          FUN_1814df680(uVar8,param_1,uRam0000000182d6c1b8,0);
          bVar17 = DAT_182eb5d50 != 0;
          *(undefined8 *)(lVar10 + 0x10) = uVar8;
          if (bVar17) {
            uVar14 = (uint)(lVar10 + 0x10U >> 0xc);
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
          if (lVar2 != 0) {
            FUN_180e545f0(lVar2,0,lVar10,2,
                          *(undefined8 *)
                           (*(longlong *)(*(longlong *)(DAT_182d5aca0 + 0x20) + 0xc0) + 0x100));
            if (*(longlong *)(param_1 + 0x20) != 0) {
              lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x40);
              lVar10 = FUN_1802c43a0(DAT_182d5ac98);
              if (lVar10 != 0) {
                bVar17 = DAT_182eb5d50 != 0;
                *(undefined8 *)(lVar10 + 0x18) = uRam0000000182d6c190;
                if (bVar17) {
                  uVar14 = (uint)(lVar10 + 0x18U >> 0xc);
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
                uVar8 = FUN_1802c43a0(DAT_182d58368);
                FUN_1814df680(uVar8,param_1,uRam0000000182d6c1b0,0);
                bVar17 = DAT_182eb5d50 != 0;
                *(undefined8 *)(lVar10 + 0x10) = uVar8;
                if (bVar17) {
                  uVar14 = (uint)(lVar10 + 0x10U >> 0xc);
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
                if (lVar2 != 0) {
                  FUN_180e545f0(lVar2,1,lVar10,2,
                                *(undefined8 *)
                                 (*(longlong *)(*(longlong *)(DAT_182d5aca0 + 0x20) + 0xc0) + 0x100)
                               );
                  if (*(longlong *)(param_1 + 0x20) != 0) {
                    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x40);
                    lVar10 = FUN_1802c43a0(DAT_182d5ac98);
                    if (lVar10 != 0) {
                      bVar17 = DAT_182eb5d50 != 0;
                      *(undefined8 *)(lVar10 + 0x18) = uRam0000000182d6c198;
                      if (bVar17) {
                        uVar14 = (uint)(lVar10 + 0x18U >> 0xc);
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
                      uVar8 = FUN_1802c43a0(DAT_182d58368);
                      FUN_1814df680(uVar8,param_1,uRam0000000182d6c1a8,0);
                      bVar17 = DAT_182eb5d50 != 0;
                      *(undefined8 *)(lVar10 + 0x10) = uVar8;
                      if (bVar17) {
                        uVar14 = (uint)(lVar10 + 0x10U >> 0xc);
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
                      if (lVar2 != 0) {
                        FUN_180e545f0(lVar2,2,lVar10,2,
                                      *(undefined8 *)
                                       (*(longlong *)(*(longlong *)(DAT_182d5aca0 + 0x20) + 0xc0) +
                                       0x100));
                        uVar8 = FUN_1802c43a0(uRam0000000182d5ae40);
                        FUN_180665bb0(uVar8,param_1,uRam0000000182d6c1d0,0);
                        if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                          FUN_18035c820();
                        }
                        FUN_180993250(uVar8,0,uRam0000000182d5ae38);
                        uVar8 = FUN_1802c43a0(DAT_182d57c08);
                        FUN_180665bb0(uVar8,param_1,uRam0000000182d6c1c0,0);
                        lVar2 = DAT_182d57bf8;
                        if (*(longlong *)(DAT_182d57bf8 + 0x38) == 0) {
                          FUN_1802f2810(&DAT_182d36a90);
                          LOCK();
                          UNLOCK();
                          FUN_1802f2810(&DAT_182d36aa0);
                          LOCK();
                          UNLOCK();
                          FUN_1802f2810(&DAT_182d5f9b8);
                          LOCK();
                          UNLOCK();
                          FUN_1802f2810(&DAT_182d36a98);
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
                        lVar12 = 0;
                        lVar10 = **(longlong **)(lVar2 + 0x38);
                        if ((*(byte *)(lVar10 + 0x135) & 1) == 0) {
                          lVar10 = FUN_180320470(lVar10);
                        }
                        lVar10 = FUN_1802c43a0(lVar10);
                        if (lVar10 != 0) {
                          bVar17 = DAT_182eb5d50 != 0;
                          *(undefined8 *)(lVar10 + 0x10) = uVar8;
                          if (bVar17) {
                            uVar14 = (uint)(lVar10 + 0x10U >> 0xc);
                            puVar1 = (ulonglong *)
                                     (&DAT_182f0c920 + (ulonglong)((uVar14 & 0x1fffff) >> 6) * 8);
                            do {
                              uVar3 = *puVar1;
                              LOCK();
                              uVar13 = *puVar1;
                              if (uVar3 == uVar13) {
                                *puVar1 = uVar3 | 1L << (uVar14 & 0x3f);
                              }
                              UNLOCK();
                            } while (uVar3 != uVar13);
                          }
                          if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                            FUN_18035c820(DAT_182d583a0);
                          }
                          lVar11 = *(longlong *)(*(longlong *)(DAT_182d583a0 + 0xb8) + 8);
                          if (lVar11 != 0) {
                            iVar7 = FUN_180e9f040(lVar11,*(undefined8 *)(lVar10 + 0x10),
                                                  *(undefined8 *)
                                                   (*(longlong *)
                                                     (*(longlong *)(DAT_182d36aa0 + 0x20) + 0xc0) +
                                                   0xf8));
                            if (-1 < iVar7) {
                              return;
                            }
                            lVar11 = FUN_1802c43a0(DAT_182d36a90);
                            FUN_180665bb0(lVar11,lVar10,
                                          *(undefined8 *)(*(longlong *)(lVar2 + 0x38) + 0x18),0);
                            if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                              FUN_18035c820(DAT_182d583a0);
                            }
                            lVar4 = *(longlong *)(*(longlong *)(DAT_182d583a0 + 0xb8) + 8);
                            if (lVar4 != 0) {
                              FUN_180eba640(lVar4,*(undefined8 *)(lVar10 + 0x10),lVar11,1,
                                            *(undefined8 *)
                                             (*(longlong *)
                                               (*(longlong *)(DAT_182d36a98 + 0x20) + 0xc0) + 0x100)
                                           );
                              uVar8 = *(undefined8 *)(*(longlong *)(lVar2 + 0x38) + 0x20);
                              lVar10 = **(longlong **)(DAT_182d583a0 + 0xb8);
                              if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
                                FUN_18035c820();
                              }
                              uVar8 = FUN_181638ed0(uVar8,0);
                              if (lVar10 != 0) {
                                uVar15 = DAT_182d5f9b8;
                                cVar6 = FUN_180ebb4c0(lVar10,uVar8,&stack0x00000008,DAT_182d5f9b8);
                                if (cVar6 == '\0') {
                                  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                                    FUN_18035c820(DAT_182d583a0);
                                  }
                                  lVar10 = **(longlong **)(DAT_182d583a0 + 0xb8);
                                  uVar8 = *(undefined8 *)(*(longlong *)(lVar2 + 0x38) + 0x20);
                                  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
                                    FUN_18035c820();
                                  }
                                  uVar8 = FUN_181638ed0(uVar8,0);
                                  if (lVar10 != 0) {
                                    uVar16 = (undefined7)((ulonglong)uVar15 >> 8);
                                    uVar15 = *(undefined8 *)
                                              (*(longlong *)
                                                (*(longlong *)(DAT_182d36a78 + 0x20) + 0xc0) + 0x100
                                              );
                                    lVar12 = lVar11;
LAB_180993542:
                                    FUN_180eba640(lVar10,uVar8,lVar12,CONCAT71(uVar16,1),uVar15);
                                    return;
                                  }
                                }
                                else {
                                  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                                    FUN_18035c820(DAT_182d583a0);
                                  }
                                  lVar10 = **(longlong **)(DAT_182d583a0 + 0xb8);
                                  uVar8 = *(undefined8 *)(*(longlong *)(lVar2 + 0x38) + 0x20);
                                  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
                                    FUN_18035c820();
                                  }
                                  uVar8 = FUN_181638ed0(uVar8,0);
                                  if (DAT_182ebbb85 == '\0') {
                                    FUN_1802f2810(&DAT_182d535d8);
                                    LOCK();
                                    UNLOCK();
                                    DAT_182ebbb85 = '\x01';
                                  }
                                  uVar5 = DAT_182d36a90;
                                  if ((lVar11 != 0) &&
                                     (lVar12 = FUN_1802c42e0(lVar11,DAT_182d36a90), lVar12 == 0)) {
                    /* WARNING: Subroutine does not return */
                                    FUN_18031e210(lVar11,uVar5);
                                  }
                                  if (lVar10 != 0) {
                                    uVar16 = (undefined7)((ulonglong)uVar15 >> 8);
                                    uVar15 = *(undefined8 *)
                                              (*(longlong *)
                                                (*(longlong *)(DAT_182d36a78 + 0x20) + 0xc0) + 0x100
                                              );
                                    goto LAB_180993542;
                                  }
                                }
                              }
                            }
                          }
                        }
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
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
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

