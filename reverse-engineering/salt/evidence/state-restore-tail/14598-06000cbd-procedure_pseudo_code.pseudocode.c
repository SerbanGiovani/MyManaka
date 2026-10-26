// Ghidra pseudocode; not original source or compilable C.
// ev_2e9c53f129bb0ecae9996b1c3c12a6ba0b864c4e79488185ec1f9907f7868f2d

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyCustomizeAdjuster__Initialize__06000cbd
               (longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  code *pcVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  uint uVar11;
  longlong *plVar12;
  uint uVar13;
  longlong lVar14;
  longlong lVar15;
  bool bVar16;
  undefined8 uStack_48;
  ulonglong uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  
  if (cRam0000000182eb83a8 == '\0') {
    FUN_1802f2810(&DAT_182d58300);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d582c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d536a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3eac8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59f58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ead0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3eab8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d582e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d582b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3eac0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3eaa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3eab0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ea98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d57d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3eaa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ea88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ea90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ea78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ea80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ea70);
    LOCK();
    UNLOCK();
    cRam0000000182eb83a8 = '\x01';
  }
  bVar16 = DAT_182eb5d50 != 0;
  *(longlong *)(param_1 + 0x40) = param_2;
  if (bVar16) {
    uVar11 = (uint)(param_1 + 0x40U >> 0xc);
    uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
      LOCK();
      bVar16 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
      if (bVar16) {
        *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar1 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar16);
  }
  uVar2 = FUN_1802c43a0(DAT_182d58300);
  FUN_180665bb0(uVar2,param_1,uRam0000000182d3eaa0,0);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_180993250(uVar2,0,DAT_182d582e8);
  if ((param_2 != 0) && (*(longlong *)(param_2 + 0x70) != 0)) {
    bVar16 = DAT_182eb5d50 != 0;
    *(undefined8 *)(param_1 + 0x58) = *(undefined8 *)(*(longlong *)(param_2 + 0x70) + 0x208);
    if (bVar16) {
      uVar11 = (uint)(param_1 + 0x58U >> 0xc);
      uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
        LOCK();
        bVar16 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
        if (bVar16) {
          *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar1 | 1L << (uVar11 & 0x3f);
        }
        UNLOCK();
      } while (!bVar16);
    }
    lVar4 = *(longlong *)(param_2 + 0x168);
    if (lVar4 != 0) {
      pcVar3 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar3 == (code *)0x0)) {
        uVar2 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar2,0);
      }
      DAT_182ec1080 = pcVar3;
      uVar2 = (*DAT_182ec1080)(lVar4);
      bVar16 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x50) = uVar2;
      if (bVar16) {
        uVar11 = (uint)(param_1 + 0x50U >> 0xc);
        uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
          LOCK();
          bVar16 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
          if (bVar16) {
            *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar1 | 1L << (uVar11 & 0x3f);
          }
          UNLOCK();
        } while (!bVar16);
      }
      lVar4 = *(longlong *)(param_1 + 0x50);
      if (lVar4 != 0) {
        uStack_48 = 0;
        uStack_40 = uStack_40 & 0xffffffff00000000;
        pcVar3 = DAT_182ec16d8;
        if ((DAT_182ec16d8 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_localScale_Injected(UnityEngine.Vector3&)"
                                          ), pcVar3 == (code *)0x0)) {
          uVar2 = FUN_1802ced60(
                               "UnityEngine.Transform::get_localScale_Injected(UnityEngine.Vector3&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar2,0);
        }
        DAT_182ec16d8 = pcVar3;
        (*DAT_182ec16d8)(lVar4,&uStack_48);
        *(undefined4 *)(param_1 + 0x4c) = (undefined4)uStack_48;
        if ((*(longlong *)(param_2 + 0x70) != 0) &&
           (lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x70) + 0xc0), lVar4 != 0)) {
          uStack_38 = 0;
          uStack_30 = uStack_30 & 0xffffffff00000000;
          pcVar3 = DAT_182ec16d8;
          if ((DAT_182ec16d8 == (code *)0x0) &&
             (pcVar3 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_localScale_Injected(UnityEngine.Vector3&)"
                                            ), pcVar3 == (code *)0x0)) {
            uVar2 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_localScale_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar2,0);
          }
          DAT_182ec16d8 = pcVar3;
          (*DAT_182ec16d8)(lVar4,&uStack_38);
          *(undefined4 *)(param_1 + 0x48) = (undefined4)uStack_38;
          if ((*(longlong *)(param_2 + 0x70) != 0) &&
             (lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x70) + 0x208), lVar4 != 0)) {
            lVar4 = FUN_180735660(lVar4,DAT_182d536a8);
            plVar8 = (longlong *)0x0;
            if (lVar4 != 0) {
              lVar15 = 0x20;
              lVar14 = 0x20;
              plVar12 = plVar8;
              while( true ) {
                pcVar3 = DAT_182ec01b0;
                if ((DAT_182ec01b0 == (code *)0x0) &&
                   (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()"),
                   pcVar3 == (code *)0x0)) {
                  uVar2 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar2,0);
                }
                DAT_182ec01b0 = pcVar3;
                lVar5 = (*DAT_182ec01b0)(lVar4);
                if (lVar5 == 0) goto code_r0x000180632ae3;
                uVar11 = (uint)plVar12;
                if (*(int *)(lVar5 + 0x18) <= (int)uVar11) {
                  if (((*(longlong *)(param_2 + 0x70) == 0) ||
                      (lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x70) + 0x218), lVar4 == 0)) ||
                     (lVar4 = FUN_180735660(lVar4,DAT_182d536a8), plVar12 = plVar8, lVar4 == 0))
                  goto code_r0x000180632ae3;
                  goto code_r0x000180632290;
                }
                pcVar3 = DAT_182ec01b0;
                if ((DAT_182ec01b0 == (code *)0x0) &&
                   (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()"),
                   pcVar3 == (code *)0x0)) {
                  uVar2 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar2,0);
                }
                DAT_182ec01b0 = pcVar3;
                lVar5 = (*DAT_182ec01b0)(lVar4);
                pcVar3 = DAT_182ec01b0;
                if ((DAT_182ec01b0 == (code *)0x0) &&
                   (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()"),
                   pcVar3 == (code *)0x0)) {
                  uVar2 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar2,0);
                }
                DAT_182ec01b0 = pcVar3;
                lVar6 = (*DAT_182ec01b0)(lVar4);
                if (lVar6 == 0) goto code_r0x000180632ae3;
                if (*(uint *)(lVar6 + 0x18) <= uVar11) break;
                uVar2 = *(undefined8 *)(lVar14 + lVar6);
                if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                lVar6 = FUN_1809f0e30(uVar2);
                if (lVar5 == 0) goto code_r0x000180632ae3;
                if ((lVar6 != 0) && (lVar7 = FUN_1802c42e0(lVar6), lVar7 == 0)) {
                  uVar2 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                  FUN_18031da90(uVar2,0);
                }
                if (*(uint *)(lVar5 + 0x18) <= uVar11) break;
                bVar16 = DAT_182eb5d50 != 0;
                *(longlong *)(lVar14 + lVar5) = lVar6;
                if (bVar16) {
                  uVar13 = (uint)((ulonglong)(lVar5 + ((longlong)(int)uVar11 + 4) * 8) >> 0xc);
                  uVar10 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                  do {
                    uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                    LOCK();
                    bVar16 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                    if (bVar16) {
                      *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar1 | 1L << (uVar13 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar16);
                }
                if (uVar11 == 1) {
                  lVar5 = FUN_181f0db90(lVar4);
                  if (lVar5 == 0) goto code_r0x000180632ae3;
                  if (*(uint *)(lVar5 + 0x18) < 2) break;
                  *(undefined8 *)(param_1 + 0x60) = *(undefined8 *)(lVar14 + lVar5);
                  FUN_18031d480(param_1 + 0x60);
                }
                plVar12 = (longlong *)(ulonglong)(uVar11 + 1);
                lVar14 = lVar14 + 8;
              }
              goto code_r0x000180632bd8;
            }
          }
        }
      }
    }
  }
code_r0x000180632ae3:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
code_r0x000180632290:
  pcVar3 = DAT_182ec01b0;
  if ((DAT_182ec01b0 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()"),
     pcVar3 == (code *)0x0)) {
    uVar2 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  DAT_182ec01b0 = pcVar3;
  lVar14 = (*DAT_182ec01b0)(lVar4);
  if (lVar14 == 0) goto code_r0x000180632ae3;
  uVar11 = (uint)plVar12;
  if (*(int *)(lVar14 + 0x18) <= (int)uVar11) {
    uVar2 = FUN_1802c43a0(uRam0000000182d582c0);
    FUN_180665bb0(uVar2,param_1,uRam0000000182d3ea88,0);
    if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
      FUN_18035c820();
    }
    FUN_180993250(uVar2,0,uRam0000000182d582b0);
    lVar4 = lRam0000000182d3ea90;
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ebb9aa == '\0') {
      FUN_1802f2810(&DAT_182d535d8);
      LOCK();
      UNLOCK();
      DAT_182ebb9aa = '\x01';
    }
    if (lVar4 != 0) {
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar4 = FUN_1803613f0(lVar4,1);
      plVar8 = (longlong *)FUN_1802c5ac0(lVar4 + 0x20);
    }
    if (*(int *)(DAT_182d59f58 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ebba98 == '\0') {
      FUN_1802f2810(&DAT_182d535d8);
      LOCK();
      UNLOCK();
      DAT_182ebba98 = '\x01';
    }
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (plVar8 == (longlong *)0x0) {
      uVar2 = thunk_FUN_1802f2810(&DAT_182d528c8);
      uVar2 = thunk_FUN_1802c43a0(uVar2);
      uVar9 = thunk_FUN_1802f2810(&DAT_182d27920);
      FUN_1815c6a10(uVar2,uVar9,0);
      uVar9 = thunk_FUN_1802f2810(&DAT_182d28d98);
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar2,uVar9);
    }
    uVar2 = (**(code **)(*plVar8 + 0x898))(plVar8,*(undefined8 *)(*plVar8 + 0x8a0));
    uVar2 = FUN_18093ca00(uVar2,uRam0000000182d3ead0);
    if (*(int *)(lRam0000000182d3ea70 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d3ea70);
    }
    lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d3ea70 + 0xb8) + 8);
    if (lVar4 == 0) {
      if (*(int *)(lRam0000000182d3ea70 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d3ea70);
      }
      uVar9 = **(undefined8 **)(lRam0000000182d3ea70 + 0xb8);
      lVar4 = FUN_1802c43a0(uRam0000000182d3eac0);
      FUN_1810d47d0(lVar4,uVar9,uRam0000000182d3ea78,0);
      *(longlong *)(*(longlong *)(lRam0000000182d3ea70 + 0xb8) + 8) = lVar4;
      if (DAT_182eb5d50 != 0) {
        uVar11 = (uint)(*(longlong *)(lRam0000000182d3ea70 + 0xb8) + 8U >> 0xc);
        uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
          LOCK();
          bVar16 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
          if (bVar16) {
            *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar1 | 1L << (uVar11 & 0x3f);
          }
          UNLOCK();
        } while (!bVar16);
      }
    }
    if (*(int *)(lRam0000000182d3ea70 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d3ea70);
    }
    lVar14 = *(longlong *)(*(longlong *)(lRam0000000182d3ea70 + 0xb8) + 0x10);
    if (lVar14 == 0) {
      if (*(int *)(lRam0000000182d3ea70 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d3ea70);
      }
      uVar9 = **(undefined8 **)(lRam0000000182d3ea70 + 0xb8);
      lVar14 = FUN_1802c43a0(uRam0000000182d3eaa8);
      FUN_1810d42f0(lVar14,uVar9,uRam0000000182d3ea80,0);
      *(longlong *)(*(longlong *)(lRam0000000182d3ea70 + 0xb8) + 0x10) = lVar14;
      if (DAT_182eb5d50 != 0) {
        uVar11 = (uint)(*(longlong *)(lRam0000000182d3ea70 + 0xb8) + 0x10U >> 0xc);
        uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
          LOCK();
          bVar16 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
          if (bVar16) {
            *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar1 | 1L << (uVar11 & 0x3f);
          }
          UNLOCK();
        } while (!bVar16);
      }
    }
    lVar15 = lRam0000000182d3eab8;
    if (*(longlong *)(lRam0000000182d3eab8 + 0x38) == 0) {
      FUN_1803204f0(lRam0000000182d3eab8);
    }
    uVar2 = FUN_18098a970(uVar2,lVar4,lVar14,0,*(undefined8 *)(*(longlong *)(lVar15 + 0x38) + 0x18))
    ;
    bVar16 = DAT_182eb5d50 != 0;
    *(undefined8 *)(param_1 + 0xb8) = uVar2;
    if (bVar16) {
      uVar11 = (uint)(param_1 + 0xb8U >> 0xc);
      uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
        LOCK();
        bVar16 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
        if (bVar16) {
          *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar1 | 1L << (uVar11 & 0x3f);
        }
        UNLOCK();
      } while (!bVar16);
    }
    if (*(longlong *)(param_1 + 0xb8) != 0) {
      uVar2 = FUN_180e0d2d0(*(longlong *)(param_1 + 0xb8),uRam0000000182d3eac8);
      uVar9 = FUN_1802c43a0(uRam0000000182d3ea98);
      FUN_181257f90(uVar9,uVar2,uRam0000000182d3eab0);
      bVar16 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0xc0) = uVar9;
      if (bVar16) {
        uVar11 = (uint)(param_1 + 0xc0U >> 0xc);
        uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
          LOCK();
          bVar16 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
          if (bVar16) {
            *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar1 | 1L << (uVar11 & 0x3f);
          }
          UNLOCK();
        } while (!bVar16);
      }
      if ((*(longlong *)(param_2 + 0x70) != 0) &&
         (lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x70) + 0xd0), lVar4 != 0)) {
        uStack_38 = 0;
        uStack_30 = 0;
        pcVar3 = DAT_182ec16c8;
        if ((DAT_182ec16c8 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_localRotation_Injected(UnityEngine.Quaternion&)"
                                          ), pcVar3 == (code *)0x0)) {
          uVar2 = FUN_1802ced60(
                               "UnityEngine.Transform::get_localRotation_Injected(UnityEngine.Quaternion&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar2,0);
        }
        DAT_182ec16c8 = pcVar3;
        (*DAT_182ec16c8)(lVar4,&uStack_38);
        *(undefined4 *)(param_1 + 200) = (undefined4)uStack_38;
        *(undefined4 *)(param_1 + 0xcc) = uStack_38._4_4_;
        *(undefined4 *)(param_1 + 0xd0) = (undefined4)uStack_30;
        *(undefined4 *)(param_1 + 0xd4) = uStack_30._4_4_;
        if ((*(longlong *)(param_2 + 0x70) != 0) &&
           (lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x70) + 0xd8), lVar4 != 0)) {
          uStack_48 = 0;
          uStack_40 = 0;
          pcVar3 = DAT_182ec16c8;
          if ((DAT_182ec16c8 == (code *)0x0) &&
             (pcVar3 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_localRotation_Injected(UnityEngine.Quaternion&)"
                                            ), pcVar3 == (code *)0x0)) {
            uVar2 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_localRotation_Injected(UnityEngine.Quaternion&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar2,0);
          }
          DAT_182ec16c8 = pcVar3;
          (*DAT_182ec16c8)(lVar4,&uStack_48);
          *(undefined8 *)(param_1 + 0xd8) = uStack_48;
          *(ulonglong *)(param_1 + 0xe0) = uStack_40;
          return;
        }
      }
    }
    goto code_r0x000180632ae3;
  }
  pcVar3 = DAT_182ec01b0;
  if ((DAT_182ec01b0 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()"),
     pcVar3 == (code *)0x0)) {
    uVar2 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  DAT_182ec01b0 = pcVar3;
  lVar14 = (*DAT_182ec01b0)(lVar4);
  pcVar3 = DAT_182ec01b0;
  if ((DAT_182ec01b0 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()"),
     pcVar3 == (code *)0x0)) {
    uVar2 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  DAT_182ec01b0 = pcVar3;
  lVar5 = (*DAT_182ec01b0)(lVar4);
  if (lVar5 == 0) goto code_r0x000180632ae3;
  if (uVar11 < *(uint *)(lVar5 + 0x18)) {
    uVar2 = *(undefined8 *)(lVar15 + lVar5);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar5 = FUN_1809f0e30(uVar2);
    if (lVar14 == 0) goto code_r0x000180632ae3;
    if ((lVar5 != 0) && (lVar6 = FUN_1802c42e0(lVar5), lVar6 == 0)) {
      uVar2 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar2,0);
    }
    if (*(uint *)(lVar14 + 0x18) <= uVar11) goto code_r0x000180632bd8;
    bVar16 = DAT_182eb5d50 != 0;
    *(longlong *)(lVar15 + lVar14) = lVar5;
    if (bVar16) {
      uVar13 = (uint)((ulonglong)(lVar14 + ((longlong)(int)uVar11 + 4) * 8) >> 0xc);
      uVar10 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
        LOCK();
        bVar16 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
        if (bVar16) {
          *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar1 | 1L << (uVar13 & 0x3f);
        }
        UNLOCK();
      } while (!bVar16);
    }
    if (uVar11 == 0) {
      lVar14 = FUN_181f0db90(lVar4);
      if (lVar14 == 0) goto code_r0x000180632ae3;
      if (*(int *)(lVar14 + 0x18) == 0) goto code_r0x000180632bd8;
      *(undefined8 *)(param_1 + 0x70) = *(undefined8 *)(lVar15 + lVar14);
      FUN_18031d480(param_1 + 0x70);
      lVar15 = lVar15 + 8;
      plVar12 = (longlong *)0x1;
    }
    else if (uVar11 == 1) {
      lVar14 = FUN_181f0db90(lVar4);
      if (lVar14 == 0) goto code_r0x000180632ae3;
      if (*(uint *)(lVar14 + 0x18) < 2) goto code_r0x000180632bd8;
      *(undefined8 *)(param_1 + 0x88) = *(undefined8 *)(lVar15 + lVar14);
      FUN_18031d480(param_1 + 0x88);
      lVar15 = lVar15 + 8;
      plVar12 = (longlong *)0x2;
    }
    else if (uVar11 == 2) {
      lVar14 = FUN_181f0db90(lVar4);
      if (lVar14 == 0) goto code_r0x000180632ae3;
      if (*(uint *)(lVar14 + 0x18) < 3) goto code_r0x000180632bd8;
      *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)(lVar15 + lVar14);
      FUN_18031d480(param_1 + 0x68);
      lVar15 = lVar15 + 8;
      plVar12 = (longlong *)0x3;
    }
    else if (uVar11 == 3) {
      lVar14 = FUN_181f0db90(lVar4);
      if (lVar14 == 0) goto code_r0x000180632ae3;
      if (*(uint *)(lVar14 + 0x18) < 4) goto code_r0x000180632bd8;
      *(undefined8 *)(param_1 + 0x90) = *(undefined8 *)(lVar15 + lVar14);
      FUN_18031d480(param_1 + 0x90);
      lVar15 = lVar15 + 8;
      plVar12 = (longlong *)0x4;
    }
    else if (uVar11 == 4) {
      lVar14 = FUN_181f0db90(lVar4);
      if (lVar14 == 0) goto code_r0x000180632ae3;
      if (*(uint *)(lVar14 + 0x18) < 5) goto code_r0x000180632bd8;
      *(undefined8 *)(param_1 + 0x80) = *(undefined8 *)(lVar15 + lVar14);
      FUN_18031d480(param_1 + 0x80);
      lVar15 = lVar15 + 8;
      plVar12 = (longlong *)0x5;
    }
    else if (uVar11 == 5) {
      lVar14 = FUN_181f0db90(lVar4);
      if (lVar14 == 0) goto code_r0x000180632ae3;
      if (*(uint *)(lVar14 + 0x18) < 6) goto code_r0x000180632bd8;
      *(undefined8 *)(param_1 + 0x78) = *(undefined8 *)(lVar15 + lVar14);
      FUN_18031d480(param_1 + 0x78);
      lVar15 = lVar15 + 8;
      plVar12 = (longlong *)0x6;
    }
    else {
      if (uVar11 == 6) {
        lVar14 = FUN_181f0db90(lVar4);
        if (lVar14 == 0) goto code_r0x000180632ae3;
        if (*(uint *)(lVar14 + 0x18) < 7) goto code_r0x000180632bd8;
        *(undefined8 *)(param_1 + 0x98) = *(undefined8 *)(lVar15 + lVar14);
        FUN_18031d480(param_1 + 0x98);
      }
      lVar15 = lVar15 + 8;
      plVar12 = (longlong *)(ulonglong)(uVar11 + 1);
    }
    goto code_r0x000180632290;
  }
code_r0x000180632bd8:
                    /* WARNING: Subroutine does not return */
  FUN_18031dae0();
}

