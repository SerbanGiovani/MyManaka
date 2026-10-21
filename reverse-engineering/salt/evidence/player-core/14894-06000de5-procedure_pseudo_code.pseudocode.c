// Ghidra pseudocode; not original source or compilable C.
// ev_a5e422bc45a847cdf447847f6905fd0ef5ff521ea8ebb37403381522fbc13bae

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

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__Initialize__06000de5
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
               longlong param_5)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  byte bVar6;
  char cVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  code *pcVar11;
  undefined8 uVar12;
  longlong *plVar13;
  longlong *plVar14;
  undefined8 uVar15;
  longlong lVar16;
  longlong lVar17;
  longlong lVar18;
  int iVar19;
  ulonglong uVar20;
  undefined7 uVar21;
  bool bVar22;
  uint in_stack_ffffffffffffffa8;
  
  if (cRam0000000182eb841d == '\0') {
    FUN_1802f2810(0x182d5ae40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d57d38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ae38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d57d30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ef88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ef90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ef80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583b8);
    LOCK();
    UNLOCK();
    cRam0000000182eb841d = '\x01';
  }
  bVar22 = DAT_182eb5d50 != 0;
  *(longlong *)(param_1 + 0x78) = param_5;
  if (bVar22) {
    uVar8 = (uint)(param_1 + 0x78U >> 0xc);
    uVar20 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
      LOCK();
      bVar22 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
      if (bVar22) {
        *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8) = uVar2 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
    } while (!bVar22);
  }
  lVar3 = *(longlong *)(param_1 + 0x88);
  if (lVar3 != 0) {
    if (cRam0000000182eb768a == '\0') {
      FUN_1802f2810(&DAT_182d582a0);
      LOCK();
      UNLOCK();
      FUN_1802f2810(0x182d58148);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d58290);
      LOCK();
      UNLOCK();
      cRam0000000182eb768a = '\x01';
    }
    bVar22 = DAT_182eb5d50 != 0;
    *(longlong *)(lVar3 + 0x10) = param_5;
    if (bVar22) {
      uVar8 = (uint)(lVar3 + 0x10U >> 0xc);
      uVar20 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
        LOCK();
        bVar22 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
        if (bVar22) {
          *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8) = uVar2 | 1L << (uVar8 & 0x3f);
        }
        UNLOCK();
      } while (!bVar22);
    }
    uVar15 = DAT_182d58290;
    pcVar11 = DAT_182ec1198;
    if ((DAT_182ec1198 == (code *)0x0) &&
       (pcVar11 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
       pcVar11 == (code *)0x0)) {
      uVar15 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar15,0);
    }
    DAT_182ec1198 = pcVar11;
    bVar6 = (*DAT_182ec1198)(uVar15);
    if (*(int *)(DAT_182d582a0 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar8 = ExposureUnnoticed2_Scripts_Base_LayerAccessor__get_LevelLayer__060017a3(0);
    uVar15 = uRam0000000182d58148;
    pcVar11 = DAT_182ec1198;
    if ((DAT_182ec1198 == (code *)0x0) &&
       (pcVar11 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
       pcVar11 == (code *)0x0)) {
      uVar15 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar15,0);
    }
    DAT_182ec1198 = pcVar11;
    uVar9 = (*DAT_182ec1198)(uVar15);
    *(int *)(lVar3 + 0x20) = 1 << (bVar6 & 0x1f) | 1 << (uVar8 & 0x1f) | 1 << (uVar9 & 0x1f);
    iVar10 = DAT_182eb5d50;
    if (param_5 != 0) {
      *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)(param_5 + 0x30);
      if (iVar10 != 0) {
        uVar8 = (uint)(param_1 + 0x30U >> 0xc);
        uVar20 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
          LOCK();
          bVar22 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
          if (bVar22) {
            *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8) = uVar2 | 1L << (uVar8 & 0x3f);
          }
          UNLOCK();
          iVar10 = DAT_182eb5d50;
        } while (!bVar22);
      }
      *(undefined8 *)(param_1 + 0x60) = *(undefined8 *)(param_5 + 0x28);
      iVar19 = 0;
      if (iVar10 != 0) {
        uVar8 = (uint)(param_1 + 0x60U >> 0xc);
        uVar20 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
          LOCK();
          bVar22 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
          if (bVar22) {
            *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8) = uVar2 | 1L << (uVar8 & 0x3f);
          }
          UNLOCK();
          iVar19 = DAT_182eb5d50;
        } while (!bVar22);
      }
      *(undefined8 *)(param_1 + 0x38) = param_2;
      iVar10 = 0;
      if (iVar19 != 0) {
        uVar8 = (uint)(param_1 + 0x38U >> 0xc);
        uVar20 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
          LOCK();
          bVar22 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
          if (bVar22) {
            *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8) = uVar2 | 1L << (uVar8 & 0x3f);
          }
          UNLOCK();
          iVar10 = DAT_182eb5d50;
        } while (!bVar22);
      }
      *(undefined8 *)(param_1 + 0x40) = param_3;
      iVar19 = 0;
      if (iVar10 != 0) {
        uVar8 = (uint)(param_1 + 0x40U >> 0xc);
        uVar20 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
          LOCK();
          bVar22 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
          if (bVar22) {
            *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8) = uVar2 | 1L << (uVar8 & 0x3f);
          }
          UNLOCK();
          iVar19 = DAT_182eb5d50;
        } while (!bVar22);
      }
      *(longlong *)(param_1 + 0x48) = param_4;
      iVar10 = 0;
      if (iVar19 != 0) {
        uVar8 = (uint)(param_1 + 0x48U >> 0xc);
        uVar20 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
          LOCK();
          bVar22 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
          if (bVar22) {
            *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8) = uVar2 | 1L << (uVar8 & 0x3f);
          }
          UNLOCK();
          iVar10 = DAT_182eb5d50;
        } while (!bVar22);
      }
      *(undefined8 *)(param_1 + 0x50) = *(undefined8 *)(param_5 + 0x48);
      iVar19 = 0;
      if (iVar10 != 0) {
        uVar8 = (uint)(param_1 + 0x50U >> 0xc);
        uVar20 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
          LOCK();
          bVar22 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
          if (bVar22) {
            *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8) = uVar2 | 1L << (uVar8 & 0x3f);
          }
          UNLOCK();
          iVar19 = DAT_182eb5d50;
        } while (!bVar22);
      }
      *(undefined8 *)(param_1 + 0x58) = *(undefined8 *)(param_5 + 200);
      iVar10 = 0;
      if (iVar19 != 0) {
        uVar8 = (uint)(param_1 + 0x58U >> 0xc);
        uVar20 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
          LOCK();
          bVar22 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
          if (bVar22) {
            *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8) = uVar2 | 1L << (uVar8 & 0x3f);
          }
          UNLOCK();
          iVar10 = DAT_182eb5d50;
        } while (!bVar22);
      }
      *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)(param_5 + 0x60);
      if (iVar10 != 0) {
        uVar8 = (uint)(param_1 + 0x68U >> 0xc);
        uVar20 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
          LOCK();
          bVar22 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
          if (bVar22) {
            *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8) = uVar2 | 1L << (uVar8 & 0x3f);
          }
          UNLOCK();
        } while (!bVar22);
      }
      if (param_4 != 0) {
        uVar15 = *(undefined8 *)(param_4 + 0x48);
        uVar12 = FUN_1802c43a0(DAT_182d58368);
        FUN_1814df680(uVar12,param_1,uRam0000000182d3ef88,0);
        plVar13 = (longlong *)FUN_1816791b0(uVar15,uVar12,0);
        if (plVar13 == (longlong *)0x0) {
          *(undefined8 *)(param_4 + 0x48) = 0;
        }
        else {
          plVar14 = (longlong *)0x0;
          if (*plVar13 == DAT_182d58368) {
            plVar14 = plVar13;
          }
          if (plVar14 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031e210();
          }
          *(longlong **)(param_4 + 0x48) = plVar14;
          plVar14 = (longlong *)0x0;
          if (*plVar13 == DAT_182d58368) {
            plVar14 = plVar13;
          }
          if (plVar14 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031e210();
          }
        }
        if (DAT_182eb5d50 != 0) {
          uVar8 = (uint)(param_4 + 0x48U >> 0xc);
          uVar20 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
          do {
            uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
            LOCK();
            bVar22 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
            if (bVar22) {
              *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8) = uVar2 | 1L << (uVar8 & 0x3f);
            }
            UNLOCK();
          } while (!bVar22);
        }
        lVar3 = *(longlong *)(param_5 + 0xd8);
        if (lVar3 != 0) {
          pcVar11 = DAT_182ebee90;
          if ((DAT_182ebee90 == (code *)0x0) &&
             (pcVar11 = (code *)FUN_1802cf0c0(
                                             "UnityEngine.AI.NavMeshAgent::set_updatePosition(System.Boolean)"
                                             ), pcVar11 == (code *)0x0)) {
            uVar15 = FUN_1802ced60("UnityEngine.AI.NavMeshAgent::set_updatePosition(System.Boolean)"
                                  );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar15,0);
          }
          DAT_182ebee90 = pcVar11;
          (*DAT_182ebee90)(lVar3,0);
          lVar3 = *(longlong *)(param_5 + 0xd8);
          if (lVar3 != 0) {
            pcVar11 = DAT_182ebee98;
            if ((DAT_182ebee98 == (code *)0x0) &&
               (pcVar11 = (code *)FUN_1802cf0c0(
                                               "UnityEngine.AI.NavMeshAgent::set_updateRotation(System.Boolean)"
                                               ), pcVar11 == (code *)0x0)) {
              uVar15 = FUN_1802ced60(
                                    "UnityEngine.AI.NavMeshAgent::set_updateRotation(System.Boolean)"
                                    );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar15,0);
            }
            DAT_182ebee98 = pcVar11;
            (*DAT_182ebee98)(lVar3,0);
            uVar15 = FUN_1802c43a0(DAT_182d583b8);
            ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
                      (uVar15,0x3dcccccd,0x3f800000,0,in_stack_ffffffffffffffa8 & 0xffffff00,0,
                       0xbf800000,0);
            bVar22 = DAT_182eb5d50 != 0;
            *(undefined8 *)(param_1 + 0x28) = uVar15;
            if (bVar22) {
              uVar8 = (uint)(param_1 + 0x28U >> 0xc);
              uVar20 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
              do {
                uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
                LOCK();
                bVar22 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8);
                if (bVar22) {
                  *(ulonglong *)(&DAT_182f0c920 + uVar20 * 8) = uVar2 | 1L << (uVar8 & 0x3f);
                }
                UNLOCK();
              } while (!bVar22);
            }
            uVar15 = FUN_1802c43a0(uRam0000000182d57d38);
            FUN_180665bb0(uVar15,param_1,uRam0000000182d3ef80,0);
            if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
              FUN_18035c820();
            }
            FUN_180993250(uVar15,0,uRam0000000182d57d30);
            uVar15 = FUN_1802c43a0(uRam0000000182d5ae40);
            FUN_180665bb0(uVar15,param_1,uRam0000000182d3ef90,0);
            lVar3 = lRam0000000182d5ae38;
            if (*(longlong *)(lRam0000000182d5ae38 + 0x38) == 0) {
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
              if (*(longlong *)(lVar3 + 0x38) == 0) {
                FUN_1803204f0(lVar3);
              }
            }
            lVar18 = 0;
            lVar16 = **(longlong **)(lVar3 + 0x38);
            if ((*(byte *)(lVar16 + 0x135) & 1) == 0) {
              lVar16 = FUN_180320470(lVar16);
            }
            lVar16 = FUN_1802c43a0(lVar16);
            if (lVar16 != 0) {
              bVar22 = DAT_182eb5d50 != 0;
              *(undefined8 *)(lVar16 + 0x10) = uVar15;
              if (bVar22) {
                uVar8 = (uint)(lVar16 + 0x10U >> 0xc);
                puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8);
                do {
                  uVar2 = *puVar1;
                  LOCK();
                  uVar20 = *puVar1;
                  if (uVar2 == uVar20) {
                    *puVar1 = uVar2 | 1L << (uVar8 & 0x3f);
                  }
                  UNLOCK();
                } while (uVar2 != uVar20);
              }
              if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                FUN_18035c820(DAT_182d583a0);
              }
              lVar17 = *(longlong *)(*(longlong *)(DAT_182d583a0 + 0xb8) + 8);
              if (lVar17 != 0) {
                iVar10 = FUN_180e9f040(lVar17,*(undefined8 *)(lVar16 + 0x10),
                                       *(undefined8 *)
                                        (*(longlong *)(*(longlong *)(DAT_182d36aa0 + 0x20) + 0xc0) +
                                        0xf8));
                if (-1 < iVar10) {
                  return;
                }
                lVar17 = FUN_1802c43a0(DAT_182d36a90);
                FUN_180665bb0(lVar17,lVar16,*(undefined8 *)(*(longlong *)(lVar3 + 0x38) + 0x18),0);
                if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                  FUN_18035c820(DAT_182d583a0);
                }
                lVar4 = *(longlong *)(*(longlong *)(DAT_182d583a0 + 0xb8) + 8);
                if (lVar4 != 0) {
                  FUN_180eba640(lVar4,*(undefined8 *)(lVar16 + 0x10),lVar17,1,
                                *(undefined8 *)
                                 (*(longlong *)(*(longlong *)(DAT_182d36a98 + 0x20) + 0xc0) + 0x100)
                               );
                  uVar15 = *(undefined8 *)(*(longlong *)(lVar3 + 0x38) + 0x20);
                  lVar16 = **(longlong **)(DAT_182d583a0 + 0xb8);
                  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  uVar15 = FUN_181638ed0(uVar15,0);
                  if (lVar16 != 0) {
                    uVar12 = DAT_182d5f9b8;
                    cVar7 = FUN_180ebb4c0(lVar16,uVar15,&stack0x00000008,DAT_182d5f9b8);
                    if (cVar7 == '\0') {
                      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                        FUN_18035c820(DAT_182d583a0);
                      }
                      lVar16 = **(longlong **)(DAT_182d583a0 + 0xb8);
                      uVar15 = *(undefined8 *)(*(longlong *)(lVar3 + 0x38) + 0x20);
                      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
                        FUN_18035c820();
                      }
                      uVar15 = FUN_181638ed0(uVar15,0);
                      if (lVar16 != 0) {
                        uVar21 = (undefined7)((ulonglong)uVar12 >> 8);
                        uVar12 = *(undefined8 *)
                                  (*(longlong *)(*(longlong *)(DAT_182d36a78 + 0x20) + 0xc0) + 0x100
                                  );
                        lVar18 = lVar17;
LAB_180993542:
                        FUN_180eba640(lVar16,uVar15,lVar18,CONCAT71(uVar21,1),uVar12);
                        return;
                      }
                    }
                    else {
                      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                        FUN_18035c820(DAT_182d583a0);
                      }
                      lVar16 = **(longlong **)(DAT_182d583a0 + 0xb8);
                      uVar15 = *(undefined8 *)(*(longlong *)(lVar3 + 0x38) + 0x20);
                      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
                        FUN_18035c820();
                      }
                      uVar15 = FUN_181638ed0(uVar15,0);
                      if (DAT_182ebbb85 == '\0') {
                        FUN_1802f2810(&DAT_182d535d8);
                        LOCK();
                        UNLOCK();
                        DAT_182ebbb85 = '\x01';
                      }
                      uVar5 = DAT_182d36a90;
                      if ((lVar17 != 0) &&
                         (lVar18 = FUN_1802c42e0(lVar17,DAT_182d36a90), lVar18 == 0)) {
                    /* WARNING: Subroutine does not return */
                        FUN_18031e210(lVar17,uVar5);
                      }
                      if (lVar16 != 0) {
                        uVar21 = (undefined7)((ulonglong)uVar12 >> 8);
                        uVar12 = *(undefined8 *)
                                  (*(longlong *)(*(longlong *)(DAT_182d36a78 + 0x20) + 0xc0) + 0x100
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
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

