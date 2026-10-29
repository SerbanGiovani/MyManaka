// Ghidra pseudocode; not original source or compilable C.
// ev_c7c5f573d8c2bafbc3219dde8fa051e0c43481c6ca5e9729aa371d78ce55745e

void ExposureUnnoticed2_ObjectUI_InGame_MissionPanel_MissionPanelView__OnLateUpdate__06001b04
               (longlong param_1)

{
  undefined4 uVar1;
  ulonglong uVar2;
  longlong *plVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined8 uVar9;
  longlong lVar10;
  undefined8 uVar11;
  code *pcVar12;
  ulonglong uVar13;
  uint uVar14;
  bool bVar15;
  undefined8 uStack_60;
  undefined4 *puStack_58;
  undefined8 uStack_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  longlong lStack_38;
  
  if (cRam0000000182eb7cdf == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64848);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64840);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64838);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64830);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e258);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e160);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e158);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e150);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64828);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e148);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e260);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64820);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64818);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64810);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64808);
    LOCK();
    UNLOCK();
    cRam0000000182eb7cdf = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x50) == 0) ||
     (lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x10), lVar10 == 0))
  goto code_r0x00018050b2b6;
  if (DAT_182eb5d50 != 0) {
    uVar14 = (uint)((ulonglong)&uStack_60 >> 0xc);
    uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
      LOCK();
      bVar15 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) = uVar2 | 1L << (uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uStack_3c = *(undefined4 *)(lVar10 + 0x1c);
  uStack_50 = 0;
  uStack_60._0_4_ = (undefined4)lVar10;
  uStack_60._4_4_ = (undefined4)((ulonglong)lVar10 >> 0x20);
  uStack_48 = (undefined4)uStack_60;
  uStack_44 = uStack_60._4_4_;
  uStack_40 = 0;
  lStack_38 = 0;
  uStack_60 = 0;
  puStack_58 = &uStack_48;
  while (cVar4 = FUN_180f72b70(&uStack_48,uRam0000000182d5e158), lVar10 = lStack_38, cVar4 != '\0')
  {
    if (lStack_38 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    cVar4 = ExposureUnnoticed2_Scripts_Mission_MissionBase__get_IsCreatePanel__0600140f(lStack_38,0)
    ;
    if (cVar4 == '\0') {
code_r0x00018050a73b:
      cVar4 = ExposureUnnoticed2_Scripts_Mission_MissionBase__get_IsOverDestroyTime__0600140e
                        (lVar10,0);
      if ((cVar4 != '\0') ||
         (cVar4 = ExposureUnnoticed2_Scripts_Mission_MissionBase__get_IsCreatePanel__0600140f
                            (lVar10,0), cVar4 == '\0')) {
        if (*(longlong *)(lVar10 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        uVar1 = *(undefined4 *)(*(longlong *)(lVar10 + 0x28) + 0x50);
        if (*(longlong *)(param_1 + 0x58) == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0(0,uVar1);
        }
        iVar5 = FUN_180e51ac0(*(longlong *)(param_1 + 0x58),uVar1,
                              *(undefined8 *)
                               (*(longlong *)(*(longlong *)(lRam0000000182d64840 + 0x20) + 0xc0) +
                               0xf8));
        if (-1 < iVar5) {
          if (*(longlong *)(lVar10 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          if (*(longlong *)(param_1 + 0x58) == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          lVar6 = FUN_180e51260(*(longlong *)(param_1 + 0x58),
                                *(undefined4 *)(*(longlong *)(lVar10 + 0x28) + 0x50),
                                uRam0000000182d64830);
          if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          ExposureUnnoticed2_ObjectUI_InGame_MissionPanel_MissionItemPanelView__DestroyItem__06001afd
                    (lVar6,0);
          if (*(longlong *)(lVar10 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          if (*(longlong *)(param_1 + 0x58) == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          FUN_180e551c0(*(longlong *)(param_1 + 0x58),
                        *(undefined4 *)(*(longlong *)(lVar10 + 0x28) + 0x50),uRam0000000182d64838);
        }
      }
    }
    else {
      if (*(longlong *)(lVar10 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uVar1 = *(undefined4 *)(*(longlong *)(lVar10 + 0x28) + 0x50);
      if (*(longlong *)(param_1 + 0x58) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0(0,uVar1);
      }
      iVar5 = FUN_180e51ac0(*(longlong *)(param_1 + 0x58),uVar1,
                            *(undefined8 *)
                             (*(longlong *)(*(longlong *)(lRam0000000182d64840 + 0x20) + 0xc0) +
                             0xf8));
      if (-1 < iVar5) goto code_r0x00018050a73b;
      uVar9 = *(undefined8 *)(param_1 + 0x28);
      uVar7 = *(undefined8 *)(param_1 + 0x40);
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar6 = FUN_1809f1050(uVar9,uVar7,DAT_182d54d90);
      if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      lVar6 = FUN_1809a08f0(lVar6,uRam0000000182d64828);
      uVar9 = *(undefined8 *)(param_1 + 0x20);
      if (*(longlong *)(param_1 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uVar7 = FUN_181d769d0(*(longlong *)(param_1 + 0x48),0);
      lVar8 = FUN_1809f1050(uVar9,uVar7,DAT_182d54d90);
      if (lVar8 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uVar9 = FUN_181f3e980(lVar8,0);
      if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      ExposureUnnoticed2_ObjectUI_InGame_MissionPanel_MissionItemPanelView__Initialize__06001afa
                (lVar6,lVar10,uVar9,0);
      if (*(longlong *)(lVar10 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uVar1 = *(undefined4 *)(*(longlong *)(lVar10 + 0x28) + 0x50);
      if (*(longlong *)(param_1 + 0x58) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0(0,uVar1);
      }
      FUN_180e545f0(*(longlong *)(param_1 + 0x58),uVar1,lVar6,2,
                    *(undefined8 *)
                     (*(longlong *)(*(longlong *)(lRam0000000182d64848 + 0x20) + 0xc0) + 0x100));
    }
  }
  if (**(longlong **)(lRam0000000182d5e258 + 0xb8) == 0) goto code_r0x00018050b2b6;
  if (cRam0000000182eb7962 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb7962 = '\x01';
  }
  lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar10 == 0) goto code_r0x00018050b2b6;
  if (*(int *)(lVar10 + 0xbc) == -1) {
    lVar10 = *(longlong *)(param_1 + 0x60);
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
    if (lVar10 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar10 + 0x10) != 0) goto code_r0x00018050a924;
    }
  }
  else {
code_r0x00018050a924:
    if (**(longlong **)(lRam0000000182d5e258 + 0xb8) == 0) goto code_r0x00018050b2b6;
    uVar9 = ExposureUnnoticed2_Scripts_InGame_DroneManager__GetActiveMission__060014ef
                      (**(longlong **)(lRam0000000182d5e258 + 0xb8),0);
    lVar10 = *(longlong *)(param_1 + 0x60);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec12f3 == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec12f3 = '\x01';
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
    if (lVar10 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar10 + 0x10) != 0) {
        if (**(longlong **)(lRam0000000182d5e258 + 0xb8) == 0) goto code_r0x00018050b2b6;
        if (cRam0000000182eb7962 == '\0') {
          FUN_1802f2810(&DAT_182d58398);
          LOCK();
          UNLOCK();
          cRam0000000182eb7962 = '\x01';
        }
        lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar10 == 0) goto code_r0x00018050b2b6;
        if (*(int *)(lVar10 + 0xbc) == -1) {
          lVar10 = *(longlong *)(param_1 + 0x60);
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
          if (lVar10 != 0) {
            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (*(longlong *)(lVar10 + 0x10) != 0) {
              lVar10 = FUN_1802c43a0(uRam0000000182d64818);
              if (lVar10 == 0) goto code_r0x00018050b2b6;
              *(undefined8 *)(lVar10 + 0x10) = *(undefined8 *)(param_1 + 0x60);
              if (DAT_182eb5d50 != 0) {
                uVar14 = (uint)(lVar10 + 0x10U >> 0xc);
                uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                do {
                  uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
                  LOCK();
                  bVar15 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
                  if (bVar15) {
                    *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) = uVar2 | 1L << (uVar14 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar15);
              }
              uVar9 = FUN_1802c43a0(DAT_182d58368);
              FUN_1814df680(uVar9,lVar10,uRam0000000182d64820,0);
              ExposureUnnoticed2_Scripts_Base_Scheduler__DelayUnscaledTime__0600174c
                        (uVar9,0x40000000,0);
              *(undefined8 *)(param_1 + 0x60) = 0;
              if (DAT_182eb5d50 != 0) {
                uVar14 = (uint)(param_1 + 0x60U >> 0xc);
                uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                do {
                  uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
                  LOCK();
                  bVar15 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
                  if (bVar15) {
                    *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) = uVar2 | 1L << (uVar14 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar15);
              }
            }
          }
        }
        goto code_r0x00018050ad93;
      }
    }
    uVar7 = *(undefined8 *)(param_1 + 0x30);
    uVar11 = *(undefined8 *)(param_1 + 0x40);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar10 = FUN_1809f1050(uVar7,uVar11,DAT_182d54d90);
    if (lVar10 == 0) goto code_r0x00018050b2b6;
    lVar6 = FUN_1809a08f0(lVar10,uRam0000000182d64828);
    uVar7 = *(undefined8 *)(param_1 + 0x20);
    lVar10 = *(longlong *)(param_1 + 0x48);
    if (lVar10 == 0) goto code_r0x00018050b2b6;
    pcVar12 = DAT_182ec1080;
    if ((DAT_182ec1080 == (code *)0x0) &&
       (pcVar12 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
       pcVar12 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec1080 = pcVar12;
    uVar11 = (*DAT_182ec1080)(lVar10);
    lVar10 = FUN_1809f1050(uVar7,uVar11,DAT_182d54d90);
    if (lVar10 == 0) goto code_r0x00018050b2b6;
    pcVar12 = DAT_182ec1120;
    if ((DAT_182ec1120 == (code *)0x0) &&
       (pcVar12 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_transform()"),
       pcVar12 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.GameObject::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec1120 = pcVar12;
    lVar8 = (*DAT_182ec1120)(lVar10);
    if (lVar8 == 0) goto code_r0x00018050b2b6;
    pcVar12 = pcRam0000000182ec1640;
    if ((pcRam0000000182ec1640 == (code *)0x0) &&
       (pcVar12 = (code *)FUN_1802cf0c0("UnityEngine.Transform::SetAsFirstSibling()"),
       pcVar12 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.Transform::SetAsFirstSibling()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    pcRam0000000182ec1640 = pcVar12;
    (*pcRam0000000182ec1640)(lVar8);
    pcVar12 = DAT_182ec1120;
    if ((DAT_182ec1120 == (code *)0x0) &&
       (pcVar12 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_transform()"),
       pcVar12 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.GameObject::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec1120 = pcVar12;
    uVar7 = (*DAT_182ec1120)(lVar10);
    if (lVar6 == 0) goto code_r0x00018050b2b6;
    ExposureUnnoticed2_ObjectUI_InGame_MissionPanel_MissionItemPanelView__Initialize__06001afa
              (lVar6,uVar9,uVar7,0);
    *(longlong *)(param_1 + 0x60) = lVar6;
    if (DAT_182eb5d50 != 0) {
      uVar14 = (uint)(param_1 + 0x60U >> 0xc);
      uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
        LOCK();
        bVar15 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
        if (bVar15) {
          *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) = uVar2 | 1L << (uVar14 & 0x3f);
        }
        UNLOCK();
      } while (!bVar15);
    }
  }
code_r0x00018050ad93:
  if (**(longlong **)(lRam0000000182d5e260 + 0xb8) == 0) goto code_r0x00018050b2b6;
  if (*(char *)(**(longlong **)(lRam0000000182d5e260 + 0xb8) + 0x10) == '\0') {
    lVar10 = *(longlong *)(param_1 + 0x68);
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
    if (lVar10 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar10 + 0x10) != 0) goto code_r0x00018050ae50;
    }
  }
  else {
code_r0x00018050ae50:
    lVar10 = *(longlong *)(param_1 + 0x68);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec12f3 == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec12f3 = '\x01';
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
    if (lVar10 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar10 + 0x10) != 0) {
        if (**(longlong **)(lRam0000000182d5e260 + 0xb8) == 0) goto code_r0x00018050b2b6;
        if (*(char *)(**(longlong **)(lRam0000000182d5e260 + 0xb8) + 0x10) == '\0') {
          lVar10 = *(longlong *)(param_1 + 0x68);
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
          if (lVar10 != 0) {
            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (*(longlong *)(lVar10 + 0x10) != 0) {
              lVar10 = FUN_1802c43a0(uRam0000000182d64808);
              if (lVar10 == 0) goto code_r0x00018050b2b6;
              *(undefined8 *)(lVar10 + 0x10) = *(undefined8 *)(param_1 + 0x68);
              if (DAT_182eb5d50 != 0) {
                uVar14 = (uint)(lVar10 + 0x10U >> 0xc);
                uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                do {
                  uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
                  LOCK();
                  bVar15 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
                  if (bVar15) {
                    *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) = uVar2 | 1L << (uVar14 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar15);
              }
              uVar9 = FUN_1802c43a0(DAT_182d58368);
              FUN_1814df680(uVar9,lVar10,uRam0000000182d64810,0);
              ExposureUnnoticed2_Scripts_Base_Scheduler__DelayUnscaledTime__0600174c
                        (uVar9,0x40000000,0);
              *(undefined8 *)(param_1 + 0x68) = 0;
              if (DAT_182eb5d50 != 0) {
                uVar14 = (uint)(param_1 + 0x68U >> 0xc);
                uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                do {
                  uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
                  LOCK();
                  bVar15 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
                  if (bVar15) {
                    *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) = uVar2 | 1L << (uVar14 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar15);
              }
            }
          }
        }
        goto code_r0x00018050b25b;
      }
    }
    uVar9 = *(undefined8 *)(param_1 + 0x38);
    uVar7 = *(undefined8 *)(param_1 + 0x40);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar10 = FUN_1809f1050(uVar9,uVar7,DAT_182d54d90);
    if (lVar10 == 0) goto code_r0x00018050b2b6;
    lVar6 = FUN_1809a08f0(lVar10,uRam0000000182d64828);
    uVar9 = *(undefined8 *)(param_1 + 0x20);
    lVar10 = *(longlong *)(param_1 + 0x48);
    if (lVar10 == 0) goto code_r0x00018050b2b6;
    pcVar12 = DAT_182ec1080;
    if ((DAT_182ec1080 == (code *)0x0) &&
       (pcVar12 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
       pcVar12 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec1080 = pcVar12;
    uVar7 = (*DAT_182ec1080)(lVar10);
    lVar10 = FUN_1809f1050(uVar9,uVar7,DAT_182d54d90);
    if (lVar10 == 0) goto code_r0x00018050b2b6;
    pcVar12 = DAT_182ec1120;
    if ((DAT_182ec1120 == (code *)0x0) &&
       (pcVar12 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_transform()"),
       pcVar12 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.GameObject::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec1120 = pcVar12;
    lVar8 = (*DAT_182ec1120)(lVar10);
    if (lVar8 == 0) goto code_r0x00018050b2b6;
    pcVar12 = pcRam0000000182ec1640;
    if ((pcRam0000000182ec1640 == (code *)0x0) &&
       (pcVar12 = (code *)FUN_1802cf0c0("UnityEngine.Transform::SetAsFirstSibling()"),
       pcVar12 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.Transform::SetAsFirstSibling()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    pcRam0000000182ec1640 = pcVar12;
    (*pcRam0000000182ec1640)(lVar8);
    if (**(longlong **)(lRam0000000182d5e260 + 0xb8) == 0) goto code_r0x00018050b2b6;
    uVar9 = *(undefined8 *)(**(longlong **)(lRam0000000182d5e260 + 0xb8) + 0x28);
    pcVar12 = DAT_182ec1120;
    if ((DAT_182ec1120 == (code *)0x0) &&
       (pcVar12 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_transform()"),
       pcVar12 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.GameObject::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec1120 = pcVar12;
    uVar7 = (*DAT_182ec1120)(lVar10);
    if (lVar6 == 0) goto code_r0x00018050b2b6;
    ExposureUnnoticed2_ObjectUI_InGame_MissionPanel_MissionItemPanelView__Initialize__06001afa
              (lVar6,uVar9,uVar7,0);
    *(longlong *)(param_1 + 0x68) = lVar6;
    if (DAT_182eb5d50 != 0) {
      uVar14 = (uint)(param_1 + 0x68U >> 0xc);
      uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
        LOCK();
        bVar15 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
        if (bVar15) {
          *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) = uVar2 | 1L << (uVar14 & 0x3f);
        }
        UNLOCK();
      } while (!bVar15);
    }
  }
code_r0x00018050b25b:
  plVar3 = *(longlong **)(param_1 + 0x48);
  if (plVar3 != (longlong *)0x0) {
    (**(code **)(*plVar3 + 0x308))(plVar3,*(undefined8 *)(*plVar3 + 0x310));
    plVar3 = *(longlong **)(param_1 + 0x48);
    if (plVar3 != (longlong *)0x0) {
      (**(code **)(*plVar3 + 0x398))(plVar3,*(undefined8 *)(*plVar3 + 0x3a0));
      return;
    }
  }
code_r0x00018050b2b6:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

