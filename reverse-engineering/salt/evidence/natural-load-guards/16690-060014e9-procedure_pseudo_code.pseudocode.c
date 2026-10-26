// Ghidra pseudocode; not original source or compilable C.
// ev_817e12ba71c839aeb73c3105c0f056fdbf60f8e44ab4319b7572cdbb3b611b2e

void ExposureUnnoticed2_Scripts_InGame_DebugController__Initialize__060014e9(void)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  bool bVar7;
  longlong lStack_108;
  ulonglong uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  longlong lStack_e0;
  ulonglong uStack_d8;
  undefined8 uStack_d0;
  longlong lStack_c8;
  undefined8 uStack_c0;
  longlong lStack_b8;
  ulonglong uStack_b0;
  ulonglong uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  longlong lStack_90;
  ulonglong uStack_88;
  undefined8 uStack_80;
  longlong lStack_78;
  undefined8 uStack_70;
  longlong lStack_68;
  ulonglong uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  
  if (cRam0000000182eb795f == '\0') {
    FUN_1802f2810(&DAT_182d59ac8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c088);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c048);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e098);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e090);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5e088);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c058);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c090);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e0a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e0a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c038);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e078);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e070);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c020);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c078);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e068);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5e220);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e060);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e058);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e050);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e048);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c068);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5bff8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54b40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5e040);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb795f = '\x01';
  }
  lStack_e0 = 0;
  uStack_d8 = 0;
  uStack_d0 = 0;
  lStack_c8 = 0;
  uStack_c0 = 0;
  lStack_b8 = 0;
  uStack_b0 = 0;
  uStack_a8 = 0;
  uStack_a0 = 0;
  uStack_98 = 0;
  lStack_90 = 0;
  uStack_88 = 0;
  uStack_80 = 0;
  lStack_78 = 0;
  uStack_70 = 0;
  lStack_68 = 0;
  uStack_60 = 0;
  uStack_58 = 0;
  uStack_50 = 0;
  uStack_48 = 0;
  if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (**(char **)(DAT_182d59ac8 + 0xb8) == '\0') {
    return;
  }
  if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (*(char *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0xc) != '\0') {
    return;
  }
  if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  *(undefined1 *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0xc) = 1;
  *(undefined1 *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0x10) = 1;
  *(undefined1 *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 9) = 1;
  *(undefined1 *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0x13) = 1;
  *(undefined1 *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0x15) = 1;
  *(undefined1 *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0x16) = 1;
  *(undefined1 *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0x18) = 1;
  *(undefined1 *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0x19) = 1;
  *(undefined1 *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0x1a) = 1;
  if (*(char *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0x19) != '\0') {
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
    if (lVar5 == 0) goto code_r0x0001804878ba;
    *(undefined1 *)(lVar5 + 0x10) = 1;
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
    if (lVar5 == 0) goto code_r0x0001804878ba;
    *(undefined1 *)(lVar5 + 0x11) = 1;
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
    if (lVar5 == 0) goto code_r0x0001804878ba;
    *(undefined1 *)(lVar5 + 0x12) = 1;
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
    if (lVar5 == 0) goto code_r0x0001804878ba;
    *(undefined1 *)(lVar5 + 0x13) = 1;
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
    if (lVar5 == 0) goto code_r0x0001804878ba;
    *(undefined1 *)(lVar5 + 0x14) = 1;
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
    if (lVar5 == 0) goto code_r0x0001804878ba;
    *(undefined1 *)(lVar5 + 0x15) = 1;
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
    if (lVar5 == 0) goto code_r0x0001804878ba;
    *(undefined1 *)(lVar5 + 0x16) = 1;
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
    if (lVar5 == 0) goto code_r0x0001804878ba;
    *(undefined1 *)(lVar5 + 0x17) = 1;
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
    if (lVar5 == 0) goto code_r0x0001804878ba;
    *(undefined1 *)(lVar5 + 0x18) = 1;
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
    if (lVar5 == 0) goto code_r0x0001804878ba;
    *(undefined1 *)(lVar5 + 0x19) = 1;
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
    if (lVar5 == 0) goto code_r0x0001804878ba;
    *(undefined1 *)(lVar5 + 0x1a) = 1;
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
    if (lVar5 == 0) goto code_r0x0001804878ba;
    *(undefined1 *)(lVar5 + 0x1b) = 1;
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
    if (lVar5 == 0) goto code_r0x0001804878ba;
    *(undefined1 *)(lVar5 + 0x1c) = 1;
  }
  if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (*(char *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0x16) != '\0') {
    lVar5 = ExposureUnnoticed2_Master_FastTravel_MFastTravel__GetAll__060012a0(0);
    if (lVar5 == 0) goto code_r0x0001804878ba;
    if (DAT_182eb5d50 != 0) {
      uVar6 = (uint)((ulonglong)&lStack_108 >> 0xc);
      lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        bVar7 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
        if (bVar7) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar6 & 0x3f);
        }
        UNLOCK();
      } while (!bVar7);
    }
    uStack_100 = (ulonglong)*(uint *)(lVar5 + 0x2c);
    uStack_e8 = 2;
    uStack_f8 = 0;
    uStack_f0 = 0;
    uStack_d8 = uStack_100;
    uStack_d0 = 0;
    lStack_c8 = 0;
    uStack_c0 = 2;
    lStack_108 = lVar5;
    lStack_e0 = lVar5;
    while (cVar3 = FUN_180f89450(&lStack_e0,uRam0000000182d5e078), lVar5 = lStack_c8, cVar3 != '\0')
    {
      lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      lVar1 = *(longlong *)(lVar1 + 0x38);
      if (lStack_c8 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0(DAT_182d58398,*(undefined4 *)(lStack_c8 + 0x34));
      }
      if ((*(int *)(lVar1 + 0x18) == 0) ||
         (iVar4 = FUN_1800b27d0(*(undefined8 *)(lVar1 + 0x10),*(undefined4 *)(lStack_c8 + 0x34),0,
                                *(undefined4 *)(lVar1 + 0x18),
                                *(undefined8 *)
                                 (*(longlong *)
                                   (*(longlong *)
                                     (*(longlong *)
                                       (*(longlong *)(*(longlong *)(DAT_182d5e040 + 0x20) + 0xc0) +
                                       0xd0) + 0x20) + 0xc0) + 0x148)), iVar4 == -1)) {
        lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        lVar1 = *(longlong *)(lVar1 + 0x38);
        if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        FUN_180004430(lVar1,*(undefined4 *)(lVar5 + 0x34));
      }
    }
  }
  if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (*(char *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0x17) != '\0') {
    if (cRam0000000182eb783e == '\0') {
      FUN_1802f2810(0x182d5c668);
      LOCK();
      UNLOCK();
      cRam0000000182eb783e = '\x01';
    }
    ExposureUnnoticed2_Master_Skill_MSkill__CheckInitialize__06001231(0);
    lVar5 = **(longlong **)(lRam0000000182d5c668 + 0xb8);
    if (lVar5 == 0) goto code_r0x0001804878ba;
    if (DAT_182eb5d50 != 0) {
      uVar6 = (uint)((ulonglong)&lStack_108 >> 0xc);
      lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        bVar7 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
        if (bVar7) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar6 & 0x3f);
        }
        UNLOCK();
      } while (!bVar7);
    }
    uStack_100 = (ulonglong)*(uint *)(lVar5 + 0x2c);
    uStack_e8 = 2;
    uStack_f8 = 0;
    uStack_f0 = 0;
    uStack_b0 = uStack_100;
    uStack_a8 = 0;
    uStack_a0 = 0;
    uStack_98 = 2;
    lStack_108 = lVar5;
    lStack_b8 = lVar5;
    while (cVar3 = FUN_180f89450(&lStack_b8,uRam0000000182d5e080), uVar2 = uStack_a8, cVar3 != '\0')
    {
      lVar5 = ExposureUnnoticed2_Master_Skill_MSkill__Get__06001232(uStack_a8 & 0xffffffff,0);
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
      if (lVar5 != 0) {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if ((*(longlong *)(lVar5 + 0x10) != 0) && (*(int *)(lVar5 + 0x40) == 1)) {
          lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          lVar5 = *(longlong *)(lVar5 + 0x1f8);
          if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          iVar4 = FUN_180e71cd0(lVar5,uVar2 & 0xffffffff,DAT_182d5e088);
          if (iVar4 < 1) {
            ExposureUnnoticed2_Scripts_InGame_GameStateFacade__RiseSkillLevel__0600152a
                      (uVar2 & 0xffffffff,0);
          }
        }
      }
    }
  }
  lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar5 != 0) {
    *(undefined4 *)(lVar5 + 0x1c0) = 1;
    *(undefined4 *)(lVar5 + 0x1bc) = 1;
    if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(char *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 9) != '\0') {
      lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if ((lVar5 == 0) || (lVar5 = *(longlong *)(lVar5 + 0x70), lVar5 == 0))
      goto code_r0x0001804878ba;
      if (*(int *)(lVar5 + 0x20) == 0) {
        if (DAT_182eb78a5 == '\0') {
          FUN_1802f2810(&DAT_182d5c0a0);
          LOCK();
          UNLOCK();
          DAT_182eb78a5 = '\x01';
        }
        ExposureUnnoticed2_Master_Achievement_MAchievement__CheckInitialize__0600138f(0);
        lVar5 = **(longlong **)(DAT_182d5c0a0 + 0xb8);
        if (lVar5 == 0) goto code_r0x0001804878ba;
        if (DAT_182eb5d50 != 0) {
          uVar6 = (uint)((ulonglong)&lStack_108 >> 0xc);
          lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
          do {
            uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
            LOCK();
            bVar7 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
            if (bVar7) {
              *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar6 & 0x3f);
            }
            UNLOCK();
          } while (!bVar7);
        }
        uStack_100 = (ulonglong)*(uint *)(lVar5 + 0x2c);
        uStack_e8 = 2;
        uStack_f8 = 0;
        uStack_f0 = 0;
        uStack_88 = uStack_100;
        uStack_80 = 0;
        lStack_78 = 0;
        uStack_70 = 2;
        lStack_108 = lVar5;
        lStack_90 = lVar5;
        while (cVar3 = FUN_180f89450(&lStack_90,DAT_182d5c080), cVar3 != '\0') {
          lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          lVar5 = *(longlong *)(lVar5 + 0x70);
          if (lStack_78 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0(*(longlong *)(DAT_182d58398 + 0xb8),*(undefined4 *)(lStack_78 + 0x40));
          }
          FUN_181104300(lVar5,*(undefined4 *)(lStack_78 + 0x40),
                        *(undefined8 *)
                         (*(longlong *)(*(longlong *)(DAT_182d5e220 + 0x20) + 0xc0) + 0xa8));
        }
      }
    }
    if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(char *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0x15) != '\0') {
      if (DAT_182eb7873 == '\0') {
        FUN_1802f2810(&DAT_182d5c2e0);
        LOCK();
        UNLOCK();
        DAT_182eb7873 = '\x01';
      }
      ExposureUnnoticed2_Master_DroneMission_MDroneMission__CheckInitialize__060012a5(0);
      lVar5 = **(longlong **)(DAT_182d5c2e0 + 0xb8);
      if (lVar5 == 0) goto code_r0x0001804878ba;
      if (DAT_182eb5d50 != 0) {
        uVar6 = (uint)((ulonglong)&lStack_108 >> 0xc);
        lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
          LOCK();
          bVar7 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
          if (bVar7) {
            *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar6 & 0x3f);
          }
          UNLOCK();
        } while (!bVar7);
      }
      uStack_100 = (ulonglong)*(uint *)(lVar5 + 0x2c);
      uStack_e8 = 2;
      uStack_f8 = 0;
      uStack_f0 = 0;
      uStack_60 = uStack_100;
      uStack_58 = 0;
      uStack_50 = 0;
      uStack_48 = 2;
      lStack_108 = lVar5;
      lStack_68 = lVar5;
      while (cVar3 = FUN_180f89450(&lStack_68,DAT_182d5c038), cVar3 != '\0') {
        ExposureUnnoticed2_Scripts_InGame_GameStateFacade__AddOneDroneMissionAchieveCount__06001550
                  (uStack_50,0);
      }
    }
    if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(char *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 10) != '\0') {
      lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if ((lVar5 == 0) || (lVar5 = *(longlong *)(lVar5 + 0x70), lVar5 == 0))
      goto code_r0x0001804878ba;
      if (0 < *(int *)(lVar5 + 0x24)) {
        FUN_181646f50(*(undefined8 *)(lVar5 + 0x18),0,*(undefined4 *)(lVar5 + 0x24),0);
        if (*(longlong *)(lVar5 + 0x10) == 0) goto code_r0x0001804878ba;
        FUN_181646f50(*(undefined8 *)(lVar5 + 0x10),0,
                      *(undefined4 *)(*(longlong *)(lVar5 + 0x10) + 0x18),0);
        *(undefined8 *)(lVar5 + 0x20) = 0;
        *(undefined4 *)(lVar5 + 0x28) = 0xffffffff;
      }
      *(int *)(lVar5 + 0x38) = *(int *)(lVar5 + 0x38) + 1;
    }
    if (DAT_182eb799e == '\0') {
      FUN_1802f2810(&DAT_182d5dc98);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d58398);
      LOCK();
      UNLOCK();
      DAT_182eb799e = '\x01';
    }
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar5 != 0) && (lVar5 = *(longlong *)(lVar5 + 0x208), lVar5 != 0)) {
      iVar4 = FUN_180e6c800(lVar5,2,*(undefined8 *)
                                     (*(longlong *)(*(longlong *)(DAT_182d5dc98 + 0x20) + 0xc0) +
                                     0xf8));
      if (-1 < iVar4) {
        return;
      }
      ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551(0,10,0);
      ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551(99999,1,0);
      ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551(0x186a1,1,0);
      ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551(0x186a2,1,0);
      ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551(0x186a3,1,0);
      ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551(100000,1,0);
      return;
    }
  }
code_r0x0001804878ba:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

