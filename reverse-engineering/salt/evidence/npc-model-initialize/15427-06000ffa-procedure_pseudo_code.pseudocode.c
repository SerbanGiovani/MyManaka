// Ghidra pseudocode; not original source or compilable C.
// ev_3524e03b3145c6a8e5bf66252264f1505c305fb75c0495c6f91ba74f2b83d41f

void ExposureUnnoticed2_Object3D_NPC_Script_NpcAvatarComponent__InitializeNewYoung__06000ffa
               (longlong param_1)

{
  undefined1 uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined8 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong lVar8;
  int iVar9;
  uint uVar10;
  longlong lVar11;
  uint uVar12;
  bool bVar13;
  float fVar14;
  
  if (DAT_182eb7748 == '\0') {
    FUN_1802f2810(&DAT_182d536a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182eb7748 = '\x01';
  }
  if (((*(longlong *)(param_1 + 0x138) != 0) &&
      (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x138) + 0x40), lVar6 != 0)) &&
     (*(longlong *)(param_1 + 0x48) != 0)) {
    iVar9 = *(int *)(*(longlong *)(param_1 + 0x48) + 0x18);
    if (*(int *)(lVar6 + 0x4c) == 0) {
      iVar9 = iVar9 + -1;
    }
    pcVar4 = DAT_182ec0fd0;
    if ((DAT_182ec0fd0 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Random::RandomRangeInt(System.Int32,System.Int32)"
                                      ), pcVar4 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Random::RandomRangeInt(System.Int32,System.Int32)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ec0fd0 = pcVar4;
    uVar3 = (*DAT_182ec0fd0)(0,iVar9);
    *(undefined4 *)(param_1 + 0x128) = uVar3;
    if (*(longlong *)(param_1 + 0x50) != 0) {
      uVar3 = *(undefined4 *)(*(longlong *)(param_1 + 0x50) + 0x18);
      pcVar4 = DAT_182ec0fd0;
      if ((DAT_182ec0fd0 == (code *)0x0) &&
         (pcVar4 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Random::RandomRangeInt(System.Int32,System.Int32)"
                                        ), pcVar4 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Random::RandomRangeInt(System.Int32,System.Int32)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec0fd0 = pcVar4;
      uVar3 = (*DAT_182ec0fd0)(0,uVar3);
      *(undefined4 *)(param_1 + 300) = uVar3;
      if (*(longlong *)(param_1 + 0x58) != 0) {
        uVar3 = *(undefined4 *)(*(longlong *)(param_1 + 0x58) + 0x18);
        pcVar4 = DAT_182ec0fd0;
        if ((DAT_182ec0fd0 == (code *)0x0) &&
           (pcVar4 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Random::RandomRangeInt(System.Int32,System.Int32)"
                                          ), pcVar4 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.Random::RandomRangeInt(System.Int32,System.Int32)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ec0fd0 = pcVar4;
        uVar3 = (*DAT_182ec0fd0)(0,uVar3);
        uVar12 = 0;
        *(undefined4 *)(param_1 + 0x130) = uVar3;
        lVar6 = *(longlong *)(param_1 + 0x48);
        if (lVar6 != 0) {
          lVar11 = 0x20;
          lVar8 = 0x20;
          uVar10 = uVar12;
          do {
            if (*(int *)(lVar6 + 0x18) <= (int)uVar10) {
              lVar6 = *(longlong *)(param_1 + 0x50);
              if (lVar6 != 0) {
                lVar8 = 0x20;
                uVar10 = uVar12;
                goto LAB_180420e96;
              }
              break;
            }
            if (uVar10 != *(uint *)(param_1 + 0x128)) {
              lVar6 = *(longlong *)(param_1 + 0x48);
              if (lVar6 == 0) break;
              if (*(uint *)(lVar6 + 0x18) <= uVar10) goto LAB_1804216db;
              if (*(longlong *)(lVar8 + lVar6) == 0) break;
              uVar5 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                                ();
              if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              FUN_181f43e80(uVar5);
            }
            lVar6 = *(longlong *)(param_1 + 0x48);
            uVar10 = uVar10 + 1;
            lVar8 = lVar8 + 8;
          } while (lVar6 != 0);
        }
      }
    }
  }
  goto LAB_180421726;
  while( true ) {
    if (uVar10 != *(uint *)(param_1 + 300)) {
      lVar6 = *(longlong *)(param_1 + 0x50);
      if (lVar6 == 0) break;
      if (*(uint *)(lVar6 + 0x18) <= uVar10) goto LAB_1804216db;
      if (*(longlong *)(lVar8 + lVar6) == 0) break;
      uVar5 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                        ();
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      FUN_181f43e80(uVar5);
      lVar6 = *(longlong *)(param_1 + 0xb0);
      if (lVar6 == 0) break;
      if (*(uint *)(lVar6 + 0x18) <= uVar10) goto LAB_1804216db;
      lVar6 = *(longlong *)(lVar8 + lVar6);
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
      if (lVar6 != 0) {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (*(longlong *)(lVar6 + 0x10) != 0) {
          lVar6 = *(longlong *)(param_1 + 0xb0);
          if (lVar6 == 0) break;
          if (*(uint *)(lVar6 + 0x18) <= uVar10) goto LAB_1804216db;
          lVar6 = *(longlong *)(lVar8 + lVar6);
          if (lVar6 == 0) break;
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          FUN_181f43e80(lVar6);
        }
      }
    }
    lVar6 = *(longlong *)(param_1 + 0x50);
    uVar10 = uVar10 + 1;
    lVar8 = lVar8 + 8;
    if (lVar6 == 0) break;
LAB_180420e96:
    if (*(int *)(lVar6 + 0x18) <= (int)uVar10) {
      lVar6 = *(longlong *)(param_1 + 0x58);
      if (lVar6 != 0) goto LAB_180421000;
      break;
    }
  }
  goto LAB_180421726;
  while( true ) {
    if (uVar12 != *(uint *)(param_1 + 0x130)) {
      lVar6 = *(longlong *)(param_1 + 0x58);
      if (lVar6 == 0) break;
      if (*(uint *)(lVar6 + 0x18) <= uVar12) goto LAB_1804216db;
      if (*(longlong *)(lVar11 + lVar6) == 0) break;
      uVar5 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                        ();
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      FUN_181f43e80(uVar5);
    }
    lVar6 = *(longlong *)(param_1 + 0x58);
    uVar12 = uVar12 + 1;
    lVar11 = lVar11 + 8;
    if (lVar6 == 0) break;
LAB_180421000:
    if (*(int *)(lVar6 + 0x18) <= (int)uVar12) {
      if ((*(longlong *)(param_1 + 0x138) == 0) ||
         (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x138) + 0x40), lVar6 == 0)) break;
      if (*(int *)(lVar6 + 0x4c) == 0) {
        if (*(int *)(param_1 + 0x128) == 10) {
          *(undefined1 *)(lVar6 + 0x1e) = 1;
          if ((*(longlong *)(param_1 + 0x138) == 0) ||
             (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x138) + 0x40), lVar6 == 0)) break;
          *(undefined1 *)(lVar6 + 0x54) = 0;
        }
        if ((*(longlong *)(param_1 + 0x138) == 0) ||
           (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x138) + 0x40), lVar6 == 0)) break;
        lVar8 = *(longlong *)(param_1 + 200);
        uVar1 = *(undefined1 *)(lVar6 + 0x1e);
        if (lVar8 == 0) break;
        pcVar4 = DAT_182ec1138;
        if ((DAT_182ec1138 == (code *)0x0) &&
           (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
           pcVar4 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ec1138 = pcVar4;
        (*DAT_182ec1138)(lVar8,uVar1);
      }
      lVar6 = *(longlong *)(param_1 + 0x48);
      if (lVar6 != 0) {
        if (*(uint *)(lVar6 + 0x18) <= *(uint *)(param_1 + 0x128)) goto LAB_1804216db;
        lVar6 = *(longlong *)(lVar6 + 0x20 + (longlong)(int)*(uint *)(param_1 + 0x128) * 8);
        if (lVar6 != 0) {
          uVar5 = FUN_180735660(lVar6,DAT_182d536a8);
          bVar13 = DAT_182eb5d50 != 0;
          *(undefined8 *)(param_1 + 0xd8) = uVar5;
          if (bVar13) {
            uVar12 = (uint)(param_1 + 0xd8U >> 0xc);
            uVar7 = (ulonglong)((uVar12 & 0x1fffff) >> 6);
            do {
              uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
              LOCK();
              bVar13 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
              if (bVar13) {
                *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) = uVar2 | 1L << (uVar12 & 0x3f);
              }
              UNLOCK();
            } while (!bVar13);
          }
          lVar6 = *(longlong *)(param_1 + 0x50);
          if (lVar6 == 0) break;
          if (*(uint *)(lVar6 + 0x18) <= *(uint *)(param_1 + 300)) {
LAB_1804216db:
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
          lVar6 = *(longlong *)(lVar6 + 0x20 + (longlong)(int)*(uint *)(param_1 + 300) * 8);
          if (lVar6 != 0) {
            uVar5 = FUN_180735660(lVar6,DAT_182d536a8);
            bVar13 = DAT_182eb5d50 != 0;
            *(undefined8 *)(param_1 + 0xe0) = uVar5;
            if (bVar13) {
              uVar12 = (uint)(param_1 + 0xe0U >> 0xc);
              uVar7 = (ulonglong)((uVar12 & 0x1fffff) >> 6);
              do {
                uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
                LOCK();
                bVar13 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
                if (bVar13) {
                  *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) = uVar2 | 1L << (uVar12 & 0x3f);
                }
                UNLOCK();
              } while (!bVar13);
            }
            lVar6 = *(longlong *)(param_1 + 0x58);
            if (lVar6 != 0) {
              if (*(uint *)(lVar6 + 0x18) <= *(uint *)(param_1 + 0x130)) goto LAB_1804216db;
              lVar6 = *(longlong *)(lVar6 + 0x20 + (longlong)(int)*(uint *)(param_1 + 0x130) * 8);
              if (lVar6 != 0) {
                uVar5 = FUN_180735660(lVar6,DAT_182d536a8);
                bVar13 = DAT_182eb5d50 != 0;
                *(undefined8 *)(param_1 + 0xe8) = uVar5;
                if (bVar13) {
                  uVar12 = (uint)(param_1 + 0xe8U >> 0xc);
                  uVar7 = (ulonglong)((uVar12 & 0x1fffff) >> 6);
                  do {
                    uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
                    LOCK();
                    bVar13 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
                    if (bVar13) {
                      *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) = uVar2 | 1L << (uVar12 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar13);
                }
                if (*(longlong *)(param_1 + 0x138) != 0) {
                  lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x138) + 0x40);
                  pcVar4 = DAT_182ec0fd8;
                  if ((DAT_182ec0fd8 == (code *)0x0) &&
                     (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Random::get_value()"),
                     pcVar4 == (code *)0x0)) {
                    uVar5 = FUN_1802ced60("UnityEngine.Random::get_value()");
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar5,0);
                  }
                  DAT_182ec0fd8 = pcVar4;
                  fVar14 = (float)(*DAT_182ec0fd8)();
                  if (lVar6 != 0) {
                    *(bool *)(lVar6 + 0x55) = 0.8 <= fVar14;
                    lVar6 = *(longlong *)(param_1 + 0x60);
                    if (lVar6 != 0) {
                      pcVar4 = DAT_182ec1088;
                      if ((DAT_182ec1088 == (code *)0x0) &&
                         (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
                         pcVar4 == (code *)0x0)) {
                        uVar5 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar5,0);
                      }
                      DAT_182ec1088 = pcVar4;
                      lVar6 = (*DAT_182ec1088)(lVar6);
                      if (((*(longlong *)(param_1 + 0x138) != 0) &&
                          (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x138) + 0x40), lVar8 != 0)
                          ) && (uVar1 = *(undefined1 *)(lVar8 + 0x55), lVar6 != 0)) {
                        pcVar4 = DAT_182ec1138;
                        if ((DAT_182ec1138 == (code *)0x0) &&
                           (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar4 == (code *)0x0)) {
                          uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)")
                          ;
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar5,0);
                        }
                        DAT_182ec1138 = pcVar4;
                        (*DAT_182ec1138)(lVar6,uVar1);
                        lVar6 = *(longlong *)(param_1 + 0x78);
                        if (lVar6 != 0) {
                          pcVar4 = DAT_182ec1088;
                          if ((DAT_182ec1088 == (code *)0x0) &&
                             (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_gameObject()"),
                             pcVar4 == (code *)0x0)) {
                            uVar5 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar5,0);
                          }
                          DAT_182ec1088 = pcVar4;
                          lVar6 = (*DAT_182ec1088)(lVar6);
                          if (((*(longlong *)(param_1 + 0x138) != 0) &&
                              (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x138) + 0x40),
                              lVar8 != 0)) && (uVar1 = *(undefined1 *)(lVar8 + 0x54), lVar6 != 0)) {
                            pcVar4 = DAT_182ec1138;
                            if ((DAT_182ec1138 == (code *)0x0) &&
                               (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar4 == (code *)0x0)) {
                              uVar5 = FUN_1802ced60(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar5,0);
                            }
                            DAT_182ec1138 = pcVar4;
                            (*DAT_182ec1138)(lVar6,uVar1);
                            if ((*(longlong *)(param_1 + 0x138) != 0) &&
                               (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x138) + 0x40),
                               lVar6 != 0)) {
                              if (*(int *)(lVar6 + 0x58) == 10) {
                                uVar5 = *(undefined8 *)(param_1 + 0xd8);
                                if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                  FUN_18035c820();
                                }
                                if (DAT_182ec12b0 == '\0') {
                                  FUN_1802f2810(&DAT_182d53aa8);
                                  LOCK();
                                  UNLOCK();
                                  DAT_182ec12b0 = '\x01';
                                }
                                if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                  FUN_18035c820();
                                }
                                pcVar4 = DAT_182ec12a8;
                                if ((DAT_182ec12a8 == (code *)0x0) &&
                                   (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)"
                                                  ), pcVar4 == (code *)0x0)) {
                                  uVar5 = FUN_1802ced60(
                                                  "UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                  FUN_1802cca90(uVar5,0);
                                }
                                DAT_182ec12a8 = pcVar4;
                                (*DAT_182ec12a8)(uVar5,0);
                                bVar13 = DAT_182eb5d50 != 0;
                                *(undefined8 *)(param_1 + 0xd8) = *(undefined8 *)(param_1 + 0x70);
                                if (bVar13) {
                                  uVar12 = (uint)(param_1 + 0xd8U >> 0xc);
                                  uVar7 = (ulonglong)((uVar12 & 0x1fffff) >> 6);
                                  do {
                                    uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
                                    LOCK();
                                    bVar13 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
                                    if (bVar13) {
                                      *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) =
                                           uVar2 | 1L << (uVar12 & 0x3f);
                                    }
                                    UNLOCK();
                                  } while (!bVar13);
                                }
                              }
                              else {
                                uVar5 = *(undefined8 *)(param_1 + 0x70);
                                if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                  FUN_18035c820();
                                }
                                if (DAT_182ec12b0 == '\0') {
                                  FUN_1802f2810(&DAT_182d53aa8);
                                  LOCK();
                                  UNLOCK();
                                  DAT_182ec12b0 = '\x01';
                                }
                                if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                  FUN_18035c820();
                                }
                                pcVar4 = DAT_182ec12a8;
                                if ((DAT_182ec12a8 == (code *)0x0) &&
                                   (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)"
                                                  ), pcVar4 == (code *)0x0)) {
                                  uVar5 = FUN_1802ced60(
                                                  "UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                  FUN_1802cca90(uVar5,0);
                                }
                                DAT_182ec12a8 = pcVar4;
                                (*DAT_182ec12a8)(uVar5,0);
                              }
                              lVar6 = *(longlong *)(param_1 + 0xc0);
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
                              if (lVar6 != 0) {
                                if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                  FUN_18035c820();
                                }
                                if ((*(longlong *)(lVar6 + 0x10) != 0) &&
                                   (1 < *(int *)(param_1 + 300))) {
                                  lVar6 = *(longlong *)(param_1 + 0xc0);
                                  if (lVar6 == 0) break;
                                  pcVar4 = DAT_182ec1138;
                                  if ((DAT_182ec1138 == (code *)0x0) &&
                                     (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar4 == (code *)0x0)) {
                                    uVar5 = FUN_1802ced60(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                    FUN_1802cca90(uVar5,0);
                                  }
                                  DAT_182ec1138 = pcVar4;
                                  (*DAT_182ec1138)(lVar6,0);
                                }
                              }
                              return;
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
      }
      break;
    }
  }
LAB_180421726:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

