// Ghidra pseudocode; not original source or compilable C.
// ev_d89386b14d13974788fcbd9ccb78d34a386e2ade44fd9cc6e7eba17a66f883dc

void ExposureUnnoticed2_Object3D_NPC_Script_NpcAvatarComponent__Initialize__06000ff8
               (longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  char cVar6;
  longlong lVar7;
  longlong lVar8;
  code *pcVar9;
  undefined8 uVar10;
  undefined1 *puVar11;
  ulonglong uVar12;
  uint uVar13;
  longlong *plVar14;
  bool bVar15;
  float fVar16;
  float fVar17;
  undefined8 local_28;
  float local_20;
  
  if (DAT_182eb7746 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59b60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59b58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59b50);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182eb7746 = '\x01';
  }
  *(longlong *)(param_1 + 0x138) = param_2;
  FUN_18031d480(param_1 + 0x138);
  if ((param_2 != 0) && (*(longlong *)(param_2 + 0xc0) != 0)) {
    uVar10 = *(undefined8 *)(*(longlong *)(param_2 + 0xc0) + 0x80);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar6 = FUN_181f44560(uVar10,0,0);
    if (cVar6 != '\0') {
      if (((*(longlong *)(param_2 + 0xc0) == 0) ||
          (lVar7 = *(longlong *)(*(longlong *)(param_2 + 0xc0) + 0x80), lVar7 == 0)) ||
         (lVar7 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                            (lVar7,0), lVar7 == 0)) goto LAB_1804203fd;
      FUN_181f3ea80(lVar7,0,0);
    }
    lVar7 = *(longlong *)(param_2 + 0x40);
    lVar8 = FUN_181d769d0(param_1,0);
    if (lVar8 != 0) {
      local_28 = 0;
      local_20 = 0.0;
      pcVar9 = DAT_182ec16d8;
      if ((DAT_182ec16d8 == (code *)0x0) &&
         (pcVar9 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_localScale_Injected(UnityEngine.Vector3&)"
                                        ), pcVar9 == (code *)0x0)) {
        uVar10 = FUN_1802ced60(
                              "UnityEngine.Transform::get_localScale_Injected(UnityEngine.Vector3&)"
                              );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar10,0);
      }
      DAT_182ec16d8 = pcVar9;
      (*DAT_182ec16d8)(lVar8,&local_28);
      fVar16 = (float)FUN_181f373e0(0);
      if (lVar7 != 0) {
        *(float *)(lVar7 + 0x5c) = (fVar16 * 0.1 + (float)local_28) - 0.05;
        if (*(longlong *)(param_2 + 0x40) != 0) {
          iVar2 = *(int *)(*(longlong *)(param_2 + 0x40) + 0x58);
          if ((iVar2 == 10) || (iVar2 == 9)) {
            if (*(longlong *)(param_2 + 0x40) == 0) goto LAB_1804203fd;
            *(undefined4 *)(*(longlong *)(param_2 + 0x40) + 0x5c) = 0x3f800000;
          }
          else {
            uVar10 = *(undefined8 *)(param_1 + 0x80);
            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            FUN_181f43e80(uVar10,0);
          }
          lVar7 = FUN_181d769d0(param_1,0);
          if (DAT_182eb548b == '\0') {
            FUN_1802f2810(&DAT_182d522a8);
            LOCK();
            UNLOCK();
            DAT_182eb548b = '\x01';
          }
          if (*(longlong *)(param_2 + 0x40) != 0) {
            fVar16 = *(float *)(*(longlong *)(param_2 + 0x40) + 0x5c);
            local_28 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0xc);
            fVar17 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x14) * fVar16;
            if (lVar7 != 0) {
              local_28 = CONCAT44((float)((ulonglong)local_28 >> 0x20) * fVar16,
                                  (float)local_28 * fVar16);
              pcVar9 = DAT_182ec16e0;
              local_20 = fVar17;
              if ((DAT_182ec16e0 == (code *)0x0) &&
                 (pcVar9 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                ), pcVar9 == (code *)0x0)) {
                uVar10 = FUN_1802ced60(
                                      "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                      );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar10,0);
              }
              DAT_182ec16e0 = pcVar9;
              (*DAT_182ec16e0)(lVar7,&local_28);
              lVar7 = *(longlong *)(param_2 + 0x40);
              fVar16 = (float)FUN_181f373e0(0);
              if (lVar7 != 0) {
                *(bool *)(lVar7 + 0x54) = 0.9 <= fVar16;
                lVar7 = *(longlong *)(param_2 + 0x40);
                if (lVar7 != 0) {
                  if (*(int *)(lVar7 + 0x58) == 10) {
                    *(undefined1 *)(lVar7 + 0x54) = 0;
                  }
                  if (*(longlong *)(param_2 + 0x40) == 0) goto LAB_1804203fd;
                  iVar2 = *(int *)(*(longlong *)(param_2 + 0x40) + 0x4c);
                  if ((iVar2 == 0) || (iVar2 == 1)) {
                    ExposureUnnoticed2_Object3D_NPC_Script_NpcAvatarComponent__InitializeNewYoung__06000ffa
                              (param_1,0);
                  }
                  else if ((iVar2 == 3) || (iVar2 == 2)) {
                    if (DAT_182eb7749 == '\0') {
                      FUN_1802f2810(&DAT_182d536a8);
                      LOCK();
                      UNLOCK();
                      DAT_182eb7749 = '\x01';
                    }
                    if ((*(longlong *)(param_1 + 0x138) == 0) ||
                       (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x138) + 0x40), lVar7 == 0))
                    goto LAB_1804203fd;
                    *(undefined1 *)(lVar7 + 0x54) = 0;
                    lVar7 = *(longlong *)(param_1 + 0x48);
                    if (lVar7 == 0) goto LAB_1804203fd;
                    if (*(int *)(lVar7 + 0x18) == 0) {
LAB_180420476:
                    /* WARNING: Subroutine does not return */
                      FUN_18031dae0();
                    }
                    if (*(longlong *)(lVar7 + 0x20) == 0) goto LAB_1804203fd;
                    uVar10 = FUN_180735660(*(longlong *)(lVar7 + 0x20),DAT_182d536a8);
                    ExposureUnnoticed2_Object3D_NPC_Script_NpcAvatarComponent__set_BodyRenderer__06000fe9
                              (param_1,uVar10);
                    lVar7 = *(longlong *)(param_1 + 0x58);
                    if (lVar7 == 0) goto LAB_1804203fd;
                    if (*(int *)(lVar7 + 0x18) == 0) goto LAB_180420476;
                    if (*(longlong *)(lVar7 + 0x20) == 0) goto LAB_1804203fd;
                    uVar10 = FUN_180735660(*(longlong *)(lVar7 + 0x20),DAT_182d536a8);
                    ExposureUnnoticed2_Object3D_NPC_Script_NpcAvatarComponent__set_FaceRenderer__06000fed
                              (param_1,uVar10);
                  }
                  else if ((iVar2 == 4) || (iVar2 == 5)) {
                    ExposureUnnoticed2_Object3D_NPC_Script_NpcAvatarComponent__InitializePrevious__06000ffc
                              (param_1,0);
                  }
                  lVar7 = *(longlong *)(param_1 + 0xa8);
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
                  if (lVar7 != 0) {
                    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                      FUN_18035c820();
                    }
                    if (*(longlong *)(lVar7 + 0x10) != 0) {
                      if (*(longlong *)(param_1 + 0xa8) == 0) goto LAB_1804203fd;
                      uVar10 = FUN_1809a08f0(*(longlong *)(param_1 + 0xa8),DAT_182d59b58);
                      *(undefined8 *)(param_1 + 0xd0) = uVar10;
                      FUN_18031d480(param_1 + 0xd0);
                    }
                  }
                  if ((*(longlong *)(param_2 + 0x50) != 0) && (*(longlong *)(param_2 + 0xc0) != 0))
                  {
                    lVar7 = *(longlong *)(*(longlong *)(param_2 + 0x50) + 0x70);
                    uVar10 = *(undefined8 *)(*(longlong *)(param_2 + 0xc0) + 0x38);
                    if (lVar7 != 0) {
                      pcVar9 = DAT_182ec1628;
                      if ((DAT_182ec1628 == (code *)0x0) &&
                         (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::SetParent(UnityEngine.Transform,System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                        uVar10 = FUN_1802ced60(
                                              "UnityEngine.Transform::SetParent(UnityEngine.Transform,System.Boolean)"
                                              );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar10,0);
                      }
                      DAT_182ec1628 = pcVar9;
                      (*DAT_182ec1628)(lVar7,uVar10,0);
                      if ((*(longlong *)(param_2 + 0x50) != 0) &&
                         (*(longlong *)(param_2 + 0xc0) != 0)) {
                        lVar7 = *(longlong *)(*(longlong *)(param_2 + 0x50) + 0x60);
                        uVar10 = *(undefined8 *)(*(longlong *)(param_2 + 0xc0) + 0x40);
                        if (lVar7 != 0) {
                          pcVar9 = DAT_182ec1628;
                          if ((DAT_182ec1628 == (code *)0x0) &&
                             (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::SetParent(UnityEngine.Transform,System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                            uVar10 = FUN_1802ced60(
                                                  "UnityEngine.Transform::SetParent(UnityEngine.Transform,System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar10,0);
                          }
                          DAT_182ec1628 = pcVar9;
                          (*DAT_182ec1628)(lVar7,uVar10,0);
                          lVar7 = *(longlong *)(param_1 + 0x88);
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
                          if (lVar7 != 0) {
                            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                              FUN_18035c820();
                            }
                            if (*(longlong *)(lVar7 + 0x10) != 0) {
                              if (*(longlong *)(param_1 + 0x88) == 0) goto LAB_1804203fd;
                              FUN_181f3ea80(*(longlong *)(param_1 + 0x88),0,0);
                            }
                          }
                          lVar7 = *(longlong *)(param_1 + 0x90);
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
                          if (lVar7 != 0) {
                            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                              FUN_18035c820();
                            }
                            if (*(longlong *)(lVar7 + 0x10) != 0) {
                              if (*(longlong *)(param_1 + 0x90) == 0) goto LAB_1804203fd;
                              FUN_181f3ea80(*(longlong *)(param_1 + 0x90),0,0);
                              lVar7 = *(longlong *)(param_1 + 0x98);
                              uVar13 = 0;
                              if (lVar7 == 0) goto LAB_1804203fd;
                              plVar14 = (longlong *)(lVar7 + 0x20);
                              for (; (int)uVar13 < *(int *)(lVar7 + 0x18); uVar13 = uVar13 + 1) {
                                if (*(uint *)(lVar7 + 0x18) <= uVar13) goto LAB_180420476;
                                lVar8 = *plVar14;
                                lVar3 = *(longlong *)(param_1 + 0x120);
                                if (lVar8 == 0) goto LAB_1804203fd;
                                pcVar9 = DAT_182ec01b0;
                                if ((DAT_182ec01b0 == (code *)0x0) &&
                                   (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::GetMaterialArray()"),
                                   pcVar9 == (code *)0x0)) {
                                  uVar10 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()")
                                  ;
                    /* WARNING: Subroutine does not return */
                                  FUN_1802cca90(uVar10,0);
                                }
                                DAT_182ec01b0 = pcVar9;
                                uVar10 = (*DAT_182ec01b0)(lVar8);
                                if (lVar3 == 0) goto LAB_1804203fd;
                                uVar4 = *(undefined8 *)
                                         (*(longlong *)(*(longlong *)(DAT_182d59b60 + 0x20) + 0xc0)
                                         + 0x100);
                                FUN_180eba640(lVar3,lVar8,uVar10,
                                              CONCAT71((int7)((ulonglong)uVar4 >> 8),2),uVar4);
                                plVar14 = plVar14 + 1;
                              }
                            }
                          }
                          lVar7 = *(longlong *)(param_1 + 0xa8);
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
                          if (lVar7 != 0) {
                            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                              FUN_18035c820();
                            }
                            if (*(longlong *)(lVar7 + 0x10) != 0) {
                              lVar7 = *(longlong *)(param_1 + 0xa8);
                              if (lVar7 == 0) goto LAB_1804203fd;
                              pcVar9 = DAT_182ec1138;
                              if ((DAT_182ec1138 == (code *)0x0) &&
                                 (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                                uVar10 = FUN_1802ced60(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                FUN_1802cca90(uVar10,0);
                              }
                              DAT_182ec1138 = pcVar9;
                              (*DAT_182ec1138)(lVar7,0);
                            }
                          }
                          lVar7 = *(longlong *)(param_1 + 0xd8);
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
                          if (lVar7 != 0) {
                            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                              FUN_18035c820();
                            }
                            if (*(longlong *)(lVar7 + 0x10) != 0) {
                              lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                              if (lVar7 == 0) goto LAB_1804203fd;
                              lVar8 = *(longlong *)(param_1 + 0xd8);
                              uVar1 = *(undefined1 *)(lVar7 + 0x20);
                              if (lVar8 == 0) goto LAB_1804203fd;
                              pcVar9 = DAT_182ec01f0;
                              if ((DAT_182ec01f0 == (code *)0x0) &&
                                 (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::set_receiveShadows(System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                                uVar10 = FUN_1802ced60(
                                                  "UnityEngine.Renderer::set_receiveShadows(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                FUN_1802cca90(uVar10,0);
                              }
                              DAT_182ec01f0 = pcVar9;
                              (*DAT_182ec01f0)(lVar8,uVar1);
                              lVar7 = *(longlong *)(param_1 + 0xd8);
                              if (lVar7 == 0) goto LAB_1804203fd;
                              pcVar9 = DAT_182ec0198;
                              if ((DAT_182ec0198 == (code *)0x0) &&
                                 (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::GetMaterial()"),
                                 pcVar9 == (code *)0x0)) {
                                uVar10 = FUN_1802ced60("UnityEngine.Renderer::GetMaterial()");
                    /* WARNING: Subroutine does not return */
                                FUN_1802cca90(uVar10,0);
                              }
                              DAT_182ec0198 = pcVar9;
                              uVar10 = (*DAT_182ec0198)(lVar7);
                              bVar15 = DAT_182eb5d50 != 0;
                              *(undefined8 *)(param_1 + 0xf0) = uVar10;
                              if (bVar15) {
                                uVar13 = (uint)(param_1 + 0xf0U >> 0xc);
                                uVar12 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                do {
                                  uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                                  LOCK();
                                  bVar15 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                                  if (bVar15) {
                                    *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) =
                                         uVar5 | 1L << (uVar13 & 0x3f);
                                  }
                                  UNLOCK();
                                } while (!bVar15);
                              }
                            }
                          }
                          lVar7 = *(longlong *)(param_1 + 0xe0);
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
                          if (lVar7 != 0) {
                            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                              FUN_18035c820();
                            }
                            if (*(longlong *)(lVar7 + 0x10) != 0) {
                              lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                              if (lVar7 == 0) goto LAB_1804203fd;
                              lVar8 = *(longlong *)(param_1 + 0xe0);
                              uVar1 = *(undefined1 *)(lVar7 + 0x20);
                              if (lVar8 == 0) goto LAB_1804203fd;
                              pcVar9 = DAT_182ec01f0;
                              if ((DAT_182ec01f0 == (code *)0x0) &&
                                 (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::set_receiveShadows(System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                                uVar10 = FUN_1802ced60(
                                                  "UnityEngine.Renderer::set_receiveShadows(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                FUN_1802cca90(uVar10,0);
                              }
                              DAT_182ec01f0 = pcVar9;
                              (*DAT_182ec01f0)(lVar8,uVar1);
                              lVar7 = *(longlong *)(param_1 + 0xe0);
                              if (lVar7 == 0) goto LAB_1804203fd;
                              pcVar9 = DAT_182ec0198;
                              if ((DAT_182ec0198 == (code *)0x0) &&
                                 (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::GetMaterial()"),
                                 pcVar9 == (code *)0x0)) {
                                uVar10 = FUN_1802ced60("UnityEngine.Renderer::GetMaterial()");
                    /* WARNING: Subroutine does not return */
                                FUN_1802cca90(uVar10,0);
                              }
                              DAT_182ec0198 = pcVar9;
                              uVar10 = (*DAT_182ec0198)(lVar7);
                              bVar15 = DAT_182eb5d50 != 0;
                              *(undefined8 *)(param_1 + 0xf8) = uVar10;
                              if (bVar15) {
                                uVar13 = (uint)(param_1 + 0xf8U >> 0xc);
                                uVar12 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                do {
                                  uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                                  LOCK();
                                  bVar15 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                                  if (bVar15) {
                                    *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) =
                                         uVar5 | 1L << (uVar13 & 0x3f);
                                  }
                                  UNLOCK();
                                } while (!bVar15);
                              }
                            }
                          }
                          lVar7 = *(longlong *)(param_1 + 0xe8);
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
                          if (lVar7 != 0) {
                            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                              FUN_18035c820();
                            }
                            if (*(longlong *)(lVar7 + 0x10) != 0) {
                              lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                              if (lVar7 == 0) goto LAB_1804203fd;
                              lVar8 = *(longlong *)(param_1 + 0xe8);
                              uVar1 = *(undefined1 *)(lVar7 + 0x20);
                              if (lVar8 == 0) goto LAB_1804203fd;
                              pcVar9 = DAT_182ec01f0;
                              if ((DAT_182ec01f0 == (code *)0x0) &&
                                 (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::set_receiveShadows(System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                                uVar10 = FUN_1802ced60(
                                                  "UnityEngine.Renderer::set_receiveShadows(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                FUN_1802cca90(uVar10,0);
                              }
                              DAT_182ec01f0 = pcVar9;
                              (*DAT_182ec01f0)(lVar8,uVar1);
                              lVar7 = *(longlong *)(param_1 + 0xe8);
                              if (lVar7 == 0) goto LAB_1804203fd;
                              pcVar9 = DAT_182ec0198;
                              if ((DAT_182ec0198 == (code *)0x0) &&
                                 (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::GetMaterial()"),
                                 pcVar9 == (code *)0x0)) {
                                uVar10 = FUN_1802ced60("UnityEngine.Renderer::GetMaterial()");
                    /* WARNING: Subroutine does not return */
                                FUN_1802cca90(uVar10,0);
                              }
                              DAT_182ec0198 = pcVar9;
                              uVar10 = (*DAT_182ec0198)(lVar7);
                              bVar15 = DAT_182eb5d50 != 0;
                              *(undefined8 *)(param_1 + 0x100) = uVar10;
                              if (bVar15) {
                                uVar13 = (uint)(param_1 + 0x100U >> 0xc);
                                uVar12 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                do {
                                  uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                                  LOCK();
                                  bVar15 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                                  if (bVar15) {
                                    *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) =
                                         uVar5 | 1L << (uVar13 & 0x3f);
                                  }
                                  UNLOCK();
                                } while (!bVar15);
                              }
                            }
                          }
                          lVar7 = *(longlong *)(param_1 + 0x60);
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
                          if (lVar7 != 0) {
                            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                              FUN_18035c820();
                            }
                            if (*(longlong *)(lVar7 + 0x10) != 0) {
                              lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                              if (lVar7 == 0) goto LAB_1804203fd;
                              lVar8 = *(longlong *)(param_1 + 0x60);
                              uVar1 = *(undefined1 *)(lVar7 + 0x20);
                              if (lVar8 == 0) goto LAB_1804203fd;
                              pcVar9 = DAT_182ec01f0;
                              if ((DAT_182ec01f0 == (code *)0x0) &&
                                 (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::set_receiveShadows(System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                                uVar10 = FUN_1802ced60(
                                                  "UnityEngine.Renderer::set_receiveShadows(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                FUN_1802cca90(uVar10,0);
                              }
                              DAT_182ec01f0 = pcVar9;
                              (*DAT_182ec01f0)(lVar8,uVar1);
                              lVar7 = *(longlong *)(param_1 + 0x60);
                              if (lVar7 == 0) goto LAB_1804203fd;
                              pcVar9 = DAT_182ec0198;
                              if ((DAT_182ec0198 == (code *)0x0) &&
                                 (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::GetMaterial()"),
                                 pcVar9 == (code *)0x0)) {
                                uVar10 = FUN_1802ced60("UnityEngine.Renderer::GetMaterial()");
                    /* WARNING: Subroutine does not return */
                                FUN_1802cca90(uVar10,0);
                              }
                              DAT_182ec0198 = pcVar9;
                              uVar10 = (*DAT_182ec0198)(lVar7);
                              bVar15 = DAT_182eb5d50 != 0;
                              *(undefined8 *)(param_1 + 0x110) = uVar10;
                              if (bVar15) {
                                uVar13 = (uint)(param_1 + 0x110U >> 0xc);
                                uVar12 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                do {
                                  uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                                  LOCK();
                                  bVar15 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                                  if (bVar15) {
                                    *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) =
                                         uVar5 | 1L << (uVar13 & 0x3f);
                                  }
                                  UNLOCK();
                                } while (!bVar15);
                              }
                            }
                          }
                          lVar7 = *(longlong *)(param_1 + 0x78);
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
                          if (lVar7 != 0) {
                            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                              FUN_18035c820();
                            }
                            if (*(longlong *)(lVar7 + 0x10) != 0) {
                              lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                              if (lVar7 != 0) {
                                lVar8 = *(longlong *)(param_1 + 0x78);
                                uVar1 = *(undefined1 *)(lVar7 + 0x20);
                                if (lVar8 != 0) {
                                  pcVar9 = DAT_182ec01f0;
                                  if ((DAT_182ec01f0 == (code *)0x0) &&
                                     (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::set_receiveShadows(System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                                    uVar10 = FUN_1802ced60(
                                                  "UnityEngine.Renderer::set_receiveShadows(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                    FUN_1802cca90(uVar10,0);
                                  }
                                  DAT_182ec01f0 = pcVar9;
                                  (*DAT_182ec01f0)(lVar8,uVar1);
                                  lVar7 = *(longlong *)(param_1 + 0x78);
                                  if (lVar7 != 0) {
                                    pcVar9 = DAT_182ec0198;
                                    if ((DAT_182ec0198 == (code *)0x0) &&
                                       (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::GetMaterial()"),
                                       pcVar9 == (code *)0x0)) {
                                      uVar10 = FUN_1802ced60("UnityEngine.Renderer::GetMaterial()");
                    /* WARNING: Subroutine does not return */
                                      FUN_1802cca90(uVar10,0);
                                    }
                                    DAT_182ec0198 = pcVar9;
                                    uVar10 = (*DAT_182ec0198)(lVar7);
                                    bVar15 = DAT_182eb5d50 != 0;
                                    *(undefined8 *)(param_1 + 0x108) = uVar10;
                                    if (bVar15) {
                                      uVar13 = (uint)(param_1 + 0x108U >> 0xc);
                                      uVar12 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                      do {
                                        uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                                        LOCK();
                                        bVar15 = uVar5 == *(ulonglong *)
                                                           (&DAT_182f0c920 + uVar12 * 8);
                                        if (bVar15) {
                                          *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) =
                                               uVar5 | 1L << (uVar13 & 0x3f);
                                        }
                                        UNLOCK();
                                      } while (!bVar15);
                                    }
                                    goto LAB_18042032b;
                                  }
                                }
                              }
                              goto LAB_1804203fd;
                            }
                          }
LAB_18042032b:
                          lVar8 = FUN_1802c43a0(DAT_182d58368);
                          lVar7 = DAT_182d59b50;
                          bVar15 = DAT_182eb5d50 != 0;
                          *(undefined8 *)(lVar8 + 0x10) = *(undefined8 *)(DAT_182d59b50 + 8);
                          *(longlong *)(lVar8 + 0x28) = lVar7;
                          *(longlong *)(lVar8 + 0x20) = param_1;
                          if (bVar15) {
                            uVar13 = (uint)(lVar8 + 0x20U >> 0xc);
                            uVar12 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                            do {
                              uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                              LOCK();
                              bVar15 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                              if (bVar15) {
                                *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) =
                                     uVar5 | 1L << (uVar13 & 0x3f);
                              }
                              UNLOCK();
                            } while (!bVar15);
                          }
                          cVar6 = *(char *)(lVar7 + 0x52);
                          *(longlong *)(lVar8 + 0x40) = lVar8;
                          if (((*(byte *)(lVar7 + 0x4c) & 0x10) == 0) || (cVar6 != '\0')) {
                            *(undefined8 *)(lVar8 + 0x40) = *(undefined8 *)(lVar8 + 0x20);
                            puVar11 = *(undefined1 **)(lVar8 + 0x10);
                          }
                          else {
                            puVar11 = &LAB_1800c7840;
                          }
                          *(undefined1 **)(lVar8 + 0x18) = puVar11;
                          *(code **)(lVar8 + 0x38) = FUN_1801e91e0;
                          ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(lVar8,1,0)
                          ;
                          return;
                        }
                      }
                    }
                  }
                  goto LAB_1804203fd;
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
LAB_1804203fd:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

