// Ghidra pseudocode; not original source or compilable C.
// ev_9a99dd450654b3dda8e583fe9f70270644e50c45e8aa9fbc5bfe4f0503370566

ulonglong ExposureUnnoticed2_Scripts_InGame_SaveManager__Load__06001602
                    (int param_1,undefined4 param_2)

{
  ulonglong uVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong lVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  uint uVar14;
  bool bVar15;
  longlong lStack_1c8;
  ulonglong uStack_1c0;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  longlong *plStack_198;
  undefined8 uStack_188;
  longlong *plStack_180;
  longlong lStack_178;
  longlong lStack_170;
  ulonglong uStack_168;
  longlong lStack_160;
  longlong lStack_158;
  longlong lStack_150;
  ulonglong uStack_148;
  undefined8 uStack_140;
  longlong lStack_138;
  undefined8 uStack_130;
  longlong lStack_128;
  ulonglong uStack_120;
  undefined8 uStack_118;
  longlong lStack_110;
  undefined8 uStack_108;
  longlong lStack_100;
  ulonglong uStack_f8;
  undefined8 uStack_f0;
  longlong lStack_e8;
  undefined8 uStack_e0;
  longlong lStack_d8;
  ulonglong uStack_d0;
  undefined8 uStack_c8;
  longlong lStack_c0;
  undefined8 uStack_b8;
  longlong lStack_b0;
  ulonglong uStack_a8;
  ulonglong uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  longlong lStack_88;
  ulonglong uStack_80;
  ulonglong uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  
  if (cRam0000000182eb79ff == '\0') {
    FUN_1802f2810(0x182d5e128);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dc08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60140);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c050);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d60138);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c6f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5d990);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dc00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e090);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e250);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60130);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60120);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60110);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e248);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60100);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d600f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d600f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d600e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d600e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dc10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c700);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c060);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d60158);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e0a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5d9b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d600d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c6e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5d988);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c030);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dbe8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5d980);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dbe0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d600d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c028);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c6d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e068);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d600c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dbd8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53690);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e050);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d600c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d600b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dbc8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c000);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5bff0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5d978);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d910);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52f20);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d940);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52f18);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52f10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d600b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d600a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52f08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d8f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d928);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d600a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60090);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60088);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5bfa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60178);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60168);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60160);
    LOCK();
    UNLOCK();
    cRam0000000182eb79ff = '\x01';
  }
  lStack_178 = 0;
  lStack_170 = 0;
  uStack_168 = 0;
  lStack_160 = 0;
  lStack_158 = 0;
  lStack_150 = 0;
  uStack_148 = 0;
  uStack_140 = 0;
  lStack_138 = 0;
  uStack_130 = 0;
  lStack_128 = 0;
  uStack_120 = 0;
  uStack_118 = 0;
  lStack_110 = 0;
  uStack_108 = 0;
  lStack_100 = 0;
  uStack_f8 = 0;
  uStack_f0 = 0;
  lStack_e8 = 0;
  uStack_e0 = 0;
  lStack_d8 = 0;
  uStack_d0 = 0;
  uStack_c8 = 0;
  lStack_c0 = 0;
  uStack_b8 = 0;
  lStack_b0 = 0;
  uStack_a8 = 0;
  uStack_a0 = 0;
  uStack_98 = 0;
  uStack_90 = 0;
  lStack_88 = 0;
  uStack_80 = 0;
  uStack_78 = 0;
  uStack_70 = 0;
  uStack_68 = 0;
  uVar6 = ExposureUnnoticed2_Scripts_InGame_SaveManager__LoadSystem__06001600(0);
  if (param_1 == 4) {
    return uVar6;
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820();
  }
  ExposureUnnoticed2_Scripts_Base_SaveRapper__PreProcess__060017b8(0,param_2,0,0);
  lVar7 = FUN_1802c43a0(uRam0000000182d600a0);
  if (cRam0000000182eb7985 == '\0') {
    FUN_1802f2810(0x182d5dd40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dd38);
    LOCK();
    UNLOCK();
    cRam0000000182eb7985 = '\x01';
  }
  *(undefined4 *)(lVar7 + 0x10) = 0xfffffc19;
  *(undefined4 *)(lVar7 + 0x104) = 0;
  uVar8 = FUN_1802c43a0(DAT_182d5dd38);
  FUN_180e686d0(uVar8,uRam0000000182d5dd40);
  *(undefined8 *)(lVar7 + 0x108) = uVar8;
  FUN_18031d480(lVar7 + 0x108);
  uVar8 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetDefaultHairCustomDataDict__06001544
                    (0);
  *(undefined8 *)(lVar7 + 0x118) = uVar8;
  FUN_18031d480(lVar7 + 0x118);
  uVar8 = FUN_1809fef00(uRam0000000182d60168,lVar7,uRam0000000182d60088);
  *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60) = uVar8;
  FUN_18031d480(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
  lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
  if (lVar7 != 0) {
    if (*(int *)(lVar7 + 0x10) == -999) {
      ExposureUnnoticed2_Scripts_InGame_GameStateFacade__SetDefaultCustomFace__06001560(0);
      ExposureUnnoticed2_Scripts_InGame_GameStateFacade__SetDefaultCustomBody__0600155f(0);
    }
    uVar8 = FUN_1802c43a0(uRam0000000182d600c8);
    ExposureUnnoticed2_Scripts_InGame_GameStateData___ctor__0600151c(uVar8,0);
    if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar8 = FUN_1809fef00(uRam0000000182d60160,uVar8,uRam0000000182d60090);
    *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48) = uVar8;
    FUN_18031d480(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    uVar3 = ExposureUnnoticed2_Scripts_Base_SaveRapper__Load__060017c5
                      (uRam0000000182d60178,*(undefined4 *)(*(longlong *)(DAT_182d60278 + 0xb8) + 8)
                       ,0);
    *(undefined4 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x50) = uVar3;
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar7 != 0) {
      if (*(longlong *)(lVar7 + 0xa8) == 0) {
        uVar8 = FUN_1802c43a0(uRam0000000182d600e8);
        FUN_180e2cdf0(uVar8,uRam0000000182d600f8);
        *(undefined8 *)(lVar7 + 0xa8) = uVar8;
        FUN_18031d480(lVar7 + 0xa8);
      }
      lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar7 != 0) {
        if (*(longlong *)(lVar7 + 0xb0) == 0) {
          uVar8 = FUN_1802c43a0(uRam0000000182d600e0);
          FUN_180e686d0(uVar8,uRam0000000182d600f0);
          *(undefined8 *)(lVar7 + 0xb0) = uVar8;
          FUN_18031d480(lVar7 + 0xb0);
        }
        lVar7 = ExposureUnnoticed2_Master_AdultGoods_MAdultGoods__GetAll__06001381(0);
        if (lVar7 != 0) {
          plVar9 = (longlong *)FUN_180006230(&lStack_1c8,lVar7);
          lStack_178 = *plVar9;
          lStack_170 = plVar9[1];
          uStack_168 = plVar9[2];
          lStack_160 = plVar9[3];
          lStack_158 = plVar9[4];
          uStack_1a0 = 0;
          plStack_198 = &lStack_178;
          while (cVar2 = FUN_180f89450(&lStack_178,DAT_182d600d8), uVar6 = uStack_168, cVar2 != '\0'
                ) {
            lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            lVar7 = *(longlong *)(lVar7 + 0xb0);
            uVar8 = FUN_1802c36c0(uRam0000000182d5e128,4);
            if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            FUN_180e76960(lVar7,uVar6 & 0xffffffff,uVar8,0,
                          *(undefined8 *)
                           (*(longlong *)(*(longlong *)(lRam0000000182d60100 + 0x20) + 0xc0) + 0x100
                           ));
          }
          if (DAT_182eb787e == '\0') {
            FUN_1802f2810(&DAT_182d5c288);
            LOCK();
            UNLOCK();
            DAT_182eb787e = '\x01';
          }
          ExposureUnnoticed2_Master_Cosplay_MCosplay__CheckInitialize__060012d6(0);
          lVar7 = **(longlong **)(DAT_182d5c288 + 0xb8);
          if (lVar7 != 0) {
            if (DAT_182eb5d50 != 0) {
              uVar14 = (uint)((ulonglong)&lStack_1c8 >> 0xc);
              uVar6 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
              do {
                uVar13 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
                LOCK();
                bVar15 = uVar13 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
                if (bVar15) {
                  *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) =
                       uVar13 | 1L << (ulonglong)(uVar14 & 0x3f);
                }
                UNLOCK();
              } while (!bVar15);
            }
            uStack_1c0 = (ulonglong)*(uint *)(lVar7 + 0x2c);
            uStack_1a8 = 2;
            uStack_1b8 = 0;
            uStack_1b0 = 0;
            uStack_148 = uStack_1c0;
            uStack_140 = 0;
            lStack_138 = 0;
            uStack_130 = 2;
            uStack_1a0 = 0;
            plStack_198 = &lStack_150;
            lStack_1c8 = lVar7;
            lStack_150 = lVar7;
            while (cVar2 = FUN_180f89450(&lStack_150,DAT_182d5d988), cVar2 != '\0') {
              if (lStack_138 == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              lVar7 = *(longlong *)(lStack_138 + 0x28);
              uVar14 = 0;
              if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              for (; (int)uVar14 < (int)*(uint *)(lVar7 + 0x18); uVar14 = uVar14 + 1) {
                if (*(uint *)(lVar7 + 0x18) <= uVar14) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dae0();
                }
                lVar11 = *(longlong *)(lVar7 + 0x20 + (longlong)(int)uVar14 * 8);
                lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                if (lVar10 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                lVar10 = *(longlong *)(lVar10 + 0x230);
                if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                iVar4 = *(int *)(lVar11 + 0xd0);
                iVar5 = *(int *)(lVar11 + 0xcc);
                uVar8 = FUN_1802c36c0(DAT_182d53690,3);
                if (lVar10 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                FUN_180e55490(lVar10,iVar4 * 10000 + iVar5,uVar8,uRam0000000182d60110);
                lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                if (lVar10 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                lVar10 = *(longlong *)(lVar10 + 0xa8);
                iVar4 = *(int *)(lVar11 + 0xd0);
                iVar5 = *(int *)(lVar11 + 0xcc);
                uVar8 = FUN_1802c36c0(uRam0000000182d5e128,4);
                if (lVar10 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                FUN_180e55490(lVar10,iVar4 * 10000 + iVar5,uVar8,uRam0000000182d60120);
              }
            }
            if (DAT_182eb786b == '\0') {
              FUN_1802f2810(&DAT_182d5c370);
              LOCK();
              UNLOCK();
              DAT_182eb786b = '\x01';
            }
            ExposureUnnoticed2_Master_Hair_MHair__CheckInitialize__0600128e(0);
            lVar7 = **(longlong **)(DAT_182d5c370 + 0xb8);
            if (lVar7 != 0) {
              if (DAT_182eb5d50 != 0) {
                uVar14 = (uint)((ulonglong)&lStack_1c8 >> 0xc);
                uVar6 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                do {
                  uVar13 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
                  LOCK();
                  bVar15 = uVar13 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
                  if (bVar15) {
                    *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) =
                         uVar13 | 1L << (ulonglong)(uVar14 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar15);
              }
              uStack_1c0 = (ulonglong)*(uint *)(lVar7 + 0x2c);
              uStack_1a8 = 2;
              uStack_1b8 = 0;
              uStack_1b0 = 0;
              uStack_120 = uStack_1c0;
              uStack_118 = 0;
              lStack_110 = 0;
              uStack_108 = 2;
              uStack_1a0 = 0;
              plStack_198 = &lStack_128;
              lStack_1c8 = lVar7;
              lStack_128 = lVar7;
              while (cVar2 = FUN_180f89450(&lStack_128,DAT_182d5dbe8), lVar7 = lStack_110,
                    cVar2 != '\0') {
                lVar11 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                lVar11 = *(longlong *)(lVar11 + 0x118);
                if (lStack_110 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                iVar4 = FUN_180e76580(lVar11,*(undefined4 *)(lStack_110 + 0x18));
                if (iVar4 < 0) {
                  lVar11 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                  if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  lVar11 = *(longlong *)(lVar11 + 0x118);
                  uVar3 = *(undefined4 *)(lVar7 + 0x18);
                  lVar10 = FUN_1802c43a0(DAT_182d5dbd8);
                  *(undefined4 *)(lVar10 + 0x10) = uVar3;
                  if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  FUN_1800062c0(lVar11,uVar3,lVar10);
                  lVar11 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                  if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  lVar11 = *(longlong *)(lVar11 + 0x118);
                  if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  lVar11 = FUN_180e75f20(lVar11,*(undefined4 *)(lVar7 + 0x18),DAT_182d58190);
                  if (*(longlong *)(lVar7 + 0x40) == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  *(undefined4 *)(lVar11 + 0x14) =
                       *(undefined4 *)(*(longlong *)(lVar7 + 0x40) + 0x14);
                  lVar11 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                  if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  lVar11 = *(longlong *)(lVar11 + 0x118);
                  if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  lVar11 = FUN_180e75f20(lVar11,*(undefined4 *)(lVar7 + 0x18),DAT_182d58190);
                  if (*(longlong *)(lVar7 + 0x40) == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  *(undefined4 *)(lVar11 + 0x18) =
                       *(undefined4 *)(*(longlong *)(lVar7 + 0x40) + 0x18);
                  lVar11 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                  if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  lVar11 = *(longlong *)(lVar11 + 0x118);
                  if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  lVar11 = FUN_180e75f20(lVar11,*(undefined4 *)(lVar7 + 0x18),DAT_182d58190);
                  if (*(longlong *)(lVar7 + 0x40) == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  *(undefined4 *)(lVar11 + 0x1c) =
                       *(undefined4 *)(*(longlong *)(lVar7 + 0x40) + 0x1c);
                  lVar11 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                  if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  lVar11 = *(longlong *)(lVar11 + 0x118);
                  if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  lVar11 = FUN_180e75f20(lVar11,*(undefined4 *)(lVar7 + 0x18));
                  if (*(longlong *)(lVar7 + 0x40) == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  *(undefined4 *)(lVar11 + 0x20) =
                       *(undefined4 *)(*(longlong *)(lVar7 + 0x40) + 0x20);
                }
              }
              if (DAT_182eb785d == '\0') {
                FUN_1802f2810(&DAT_182d5c448);
                LOCK();
                UNLOCK();
                DAT_182eb785d = '\x01';
              }
              ExposureUnnoticed2_Master_Mission_MMission__CheckInitialize__06001266(0);
              lVar7 = **(longlong **)(DAT_182d5c448 + 0xb8);
              if (lVar7 != 0) {
                if (DAT_182eb5d50 != 0) {
                  uVar14 = (uint)((ulonglong)&lStack_1c8 >> 0xc);
                  uVar6 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                  do {
                    uVar13 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
                    LOCK();
                    bVar15 = uVar13 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
                    if (bVar15) {
                      *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) =
                           uVar13 | 1L << (ulonglong)(uVar14 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar15);
                }
                uStack_1c0 = (ulonglong)*(uint *)(lVar7 + 0x2c);
                uStack_1a8 = 2;
                uStack_1b8 = 0;
                uStack_1b0 = 0;
                uStack_f8 = uStack_1c0;
                uStack_f0 = 0;
                lStack_e8 = 0;
                uStack_e0 = 2;
                uStack_188 = 0;
                plStack_180 = &lStack_100;
                lStack_1c8 = lVar7;
                lStack_100 = lVar7;
                while (cVar2 = FUN_180f89450(&lStack_100,DAT_182d5c030), cVar2 != '\0') {
                  if (lStack_e8 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  lVar7 = *(longlong *)(lStack_e8 + 0x28);
                  if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  if (DAT_182eb5d50 != 0) {
                    uVar14 = (uint)((ulonglong)&lStack_1c8 >> 0xc);
                    uVar6 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                    do {
                      uVar13 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
                      LOCK();
                      bVar15 = uVar13 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
                      if (bVar15) {
                        *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) =
                             uVar13 | 1L << (ulonglong)(uVar14 & 0x3f);
                      }
                      UNLOCK();
                    } while (!bVar15);
                  }
                  uStack_1c0 = (ulonglong)*(uint *)(lVar7 + 0x2c);
                  uStack_1a8 = 2;
                  uStack_1b8 = 0;
                  uStack_1b0 = 0;
                  uStack_d0 = uStack_1c0;
                  uStack_c8 = 0;
                  lStack_c0 = 0;
                  uStack_b8 = 2;
                  uStack_1a0 = 0;
                  plStack_198 = &lStack_d8;
                  lStack_1c8 = lVar7;
                  lStack_d8 = lVar7;
                  while (cVar2 = FUN_180f89450(&lStack_d8,uRam0000000182d5e1d0), cVar2 != '\0') {
                    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    lVar7 = *(longlong *)(lVar7 + 0x118);
                    if (lStack_c0 == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    FUN_180005ae0(lVar7,*(undefined4 *)(lStack_c0 + 0x50),0,uRam0000000182d5e248);
                  }
                }
                if (cRam0000000182eb783e == '\0') {
                  FUN_1802f2810(0x182d5c668);
                  LOCK();
                  UNLOCK();
                  cRam0000000182eb783e = '\x01';
                }
                ExposureUnnoticed2_Master_Skill_MSkill__CheckInitialize__06001231(0);
                lVar7 = **(longlong **)(lRam0000000182d5c668 + 0xb8);
                if (lVar7 != 0) {
                  if (DAT_182eb5d50 != 0) {
                    uVar14 = (uint)((ulonglong)&lStack_1c8 >> 0xc);
                    uVar6 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                    do {
                      uVar13 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
                      LOCK();
                      bVar15 = uVar13 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
                      if (bVar15) {
                        *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar13 | 1L << (uVar14 & 0x3f);
                      }
                      UNLOCK();
                    } while (!bVar15);
                  }
                  uStack_1c0 = (ulonglong)*(uint *)(lVar7 + 0x2c);
                  uStack_1a8 = 2;
                  uStack_1b8 = 0;
                  uStack_1b0 = 0;
                  uStack_a8 = uStack_1c0;
                  uStack_a0 = 0;
                  uStack_98 = 0;
                  uStack_90 = 2;
                  uStack_188 = 0;
                  plStack_180 = &lStack_b0;
                  lStack_1c8 = lVar7;
                  lStack_b0 = lVar7;
                  while (cVar2 = FUN_180f89450(&lStack_b0,uRam0000000182d5e080), cVar2 != '\0') {
                    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    lVar7 = *(longlong *)(lVar7 + 0x1f8);
                    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    FUN_180e72490(lVar7,uStack_a0 & 0xffffffff,0,0,
                                  *(undefined8 *)
                                   (*(longlong *)(*(longlong *)(lRam0000000182d60130 + 0x20) + 0xc0)
                                   + 0x100));
                  }
                  while ((lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48),
                         lVar7 != 0 && (lVar7 = *(longlong *)(lVar7 + 0x248), lVar7 != 0))) {
                    if (0x14 < *(int *)(lVar7 + 0x18)) {
                      lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                      goto code_r0x00018049e740;
                    }
                    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                    if (lVar7 == 0) break;
                    lVar7 = *(longlong *)(lVar7 + 0x248);
                    uVar8 = FUN_1802c43a0(uRam0000000182d5d928);
                    ExposureUnnoticed2_ObjectUI_InventoryPanel_LoadoutData___ctor__060019e9(uVar8,0)
                    ;
                    lVar11 = lRam0000000182d5d940;
                    if (lVar7 == 0) break;
                    *(int *)(lVar7 + 0x1c) = *(int *)(lVar7 + 0x1c) + 1;
                    lVar10 = *(longlong *)(lVar7 + 0x10);
                    uVar14 = *(uint *)(lVar7 + 0x18);
                    if (lVar10 == 0) break;
                    if (uVar14 < *(uint *)(lVar10 + 0x18)) {
                      *(uint *)(lVar7 + 0x18) = uVar14 + 1;
                      FUN_180002cd0(lVar10,(longlong)(int)uVar14,uVar8);
                    }
                    else {
                      FUN_1812741c0(lVar7,uVar8,
                                    *(undefined8 *)
                                     (*(longlong *)(*(longlong *)(lVar11 + 0x20) + 0xc0) + 0x70));
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
  goto code_r0x00018049f16a;
code_r0x00018049e740:
  if (*(longlong *)(lVar7 + 0x250) == 0) goto code_r0x00018049f16a;
  if (*(int *)(*(longlong *)(lVar7 + 0x250) + 0x18) < 0x15) {
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar7 == 0) goto code_r0x00018049f16a;
    lVar7 = *(longlong *)(lVar7 + 0x250);
    uVar8 = FUN_1802c43a0(uRam0000000182d5d8f8);
    ExposureUnnoticed2_ObjectUI_ClosetMenu_CustomizeMenu_LoadoutCustomizeData__SaveCurrentCustomize__06001cb8
              (uVar8,0);
    lVar11 = lRam0000000182d5d910;
    if (lVar7 == 0) goto code_r0x00018049f16a;
    *(int *)(lVar7 + 0x1c) = *(int *)(lVar7 + 0x1c) + 1;
    lVar10 = *(longlong *)(lVar7 + 0x10);
    uVar14 = *(uint *)(lVar7 + 0x18);
    if (lVar10 == 0) goto code_r0x00018049f16a;
    if (uVar14 < *(uint *)(lVar10 + 0x18)) {
      *(uint *)(lVar7 + 0x18) = uVar14 + 1;
      FUN_180002cd0(lVar10,(longlong)(int)uVar14,uVar8);
    }
    else {
      FUN_1812741c0(lVar7,uVar8,
                    *(undefined8 *)(*(longlong *)(*(longlong *)(lVar11 + 0x20) + 0xc0) + 0x70));
    }
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar7 == 0) goto code_r0x00018049f16a;
    goto code_r0x00018049e740;
  }
  if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182eb7836 == '\0') {
    FUN_1802f2810(&DAT_182d594e8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7836 = '\x01';
  }
  if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  ExposureUnnoticed2_Master_Stage_MStage__CheckInitialize__06001228(0);
  lVar7 = **(longlong **)(DAT_182d594e8 + 0xb8);
  if (lVar7 == 0) goto code_r0x00018049f16a;
  if (DAT_182eb5d50 != 0) {
    uVar14 = (uint)((ulonglong)&lStack_1c8 >> 0xc);
    uVar6 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar13 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
      LOCK();
      bVar15 = uVar13 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar13 | 1L << (uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uStack_1c0 = (ulonglong)*(uint *)(lVar7 + 0x2c);
  uStack_1a8 = 2;
  uStack_1b8 = 0;
  uStack_1b0 = 0;
  uStack_80 = uStack_1c0;
  uStack_78 = 0;
  uStack_70 = 0;
  uStack_68 = 2;
  uStack_188 = 0;
  plStack_180 = &lStack_88;
  lStack_1c8 = lVar7;
  lStack_88 = lVar7;
  while (cVar2 = FUN_180f89450(&lStack_88,uRam0000000182d5c6e8), cVar2 != '\0') {
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    lVar7 = *(longlong *)(lVar7 + 0xe8);
    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    FUN_180e72490(lVar7,uStack_78 & 0xffffffff,0xffffffff,0,
                  *(undefined8 *)
                   (*(longlong *)(*(longlong *)(lRam0000000182d5e250 + 0x20) + 0xc0) + 0x100));
  }
  if (*(int *)(DAT_182d5bfa0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d5bfa0);
  }
  *(undefined1 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x54) =
       **(undefined1 **)(DAT_182d5bfa0 + 0xb8);
  lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
  if (lVar7 == 0) goto code_r0x00018049f16a;
  *(undefined1 *)(lVar7 + 0x3b) = 1;
  if (DAT_182eb799e == '\0') {
    FUN_1802f2810(&DAT_182d5dc98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb799e = '\x01';
  }
  lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar7 == 0) || (lVar7 = *(longlong *)(lVar7 + 0x208), lVar7 == 0)) goto code_r0x00018049f16a;
  iVar4 = FUN_180e6c800(lVar7,4,*(undefined8 *)
                                 (*(longlong *)(*(longlong *)(DAT_182d5dc98 + 0x20) + 0xc0) + 0xf8))
  ;
  if ((-1 < iVar4) &&
     (cVar2 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsBringItem__06001552(10000,0),
     cVar2 == '\0')) {
    ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551(10000,1,0);
  }
  iVar4 = 1;
  if (DAT_182eb799e == '\0') {
    FUN_1802f2810(&DAT_182d5dc98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb799e = '\x01';
  }
  lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar7 == 0) || (lVar7 = *(longlong *)(lVar7 + 0x208), lVar7 == 0)) goto code_r0x00018049f16a;
  iVar5 = FUN_180e6c800(lVar7,1,*(undefined8 *)
                                 (*(longlong *)(*(longlong *)(DAT_182d5dc98 + 0x20) + 0xc0) + 0xf8))
  ;
  if (iVar5 < 0) {
    if (DAT_182eb799e == '\0') {
      FUN_1802f2810(&DAT_182d5dc98);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d58398);
      LOCK();
      UNLOCK();
      DAT_182eb799e = '\x01';
    }
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar7 == 0) || (lVar7 = *(longlong *)(lVar7 + 0x208), lVar7 == 0))
    goto code_r0x00018049f16a;
    iVar5 = FUN_180e6c800(lVar7,6,*(undefined8 *)
                                   (*(longlong *)(*(longlong *)(DAT_182d5dc98 + 0x20) + 0xc0) + 0xf8
                                   ));
    if (-1 < iVar5) goto code_r0x00018049ec4b;
    if (DAT_182eb799e == '\0') {
      FUN_1802f2810(&DAT_182d5dc98);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d58398);
      LOCK();
      UNLOCK();
      DAT_182eb799e = '\x01';
    }
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar7 == 0) || (lVar7 = *(longlong *)(lVar7 + 0x208), lVar7 == 0))
    goto code_r0x00018049f16a;
    iVar5 = FUN_180e6c800(lVar7,7,*(undefined8 *)
                                   (*(longlong *)(*(longlong *)(DAT_182d5dc98 + 0x20) + 0xc0) + 0xf8
                                   ));
    if (-1 < iVar5) goto code_r0x00018049ec4b;
  }
  else {
code_r0x00018049ec4b:
    cVar2 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsBringItem__06001552(0x2711,0);
    if (cVar2 == '\0') {
      ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551(0x2711,1,0);
    }
  }
  lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar7 != 0) {
    *(undefined4 *)(lVar7 + 0x10) = 0;
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar7 != 0) {
      *(undefined4 *)(lVar7 + 0xbc) = 0xffffffff;
      lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar7 != 0) {
        *(undefined4 *)(lVar7 + 0xc0) = 0;
        lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar7 != 0) {
          if (*(longlong *)(lVar7 + 0x98) == 0) {
            lVar7 = FUN_1802c43a0(DAT_182d52f08);
            FUN_1811cf4f0(lVar7,DAT_182d52f10);
            iVar5 = 1;
            do {
              uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                (uRam0000000182d60080,0);
              if (DAT_182ebb869 == '\0') {
                FUN_1802f2810(&DAT_182d24690);
                LOCK();
                UNLOCK();
                FUN_1802f2810(&DAT_182d39ea8);
                LOCK();
                UNLOCK();
                DAT_182ebb869 = '\x01';
              }
              if ((*(byte *)(*(longlong *)(DAT_182d39ea8 + 0x20) + 0x135) & 1) == 0) {
                FUN_180320470();
              }
              if (*(int *)(DAT_182d24690 + 0xe0) == 0) {
                FUN_18035c820();
              }
              uStack_188 = 0;
              plStack_180 = (longlong *)0x0;
              uVar12 = FUN_18161e8f0(iVar5,&uStack_188,0,0);
              System_String__Concat__0600021b(uVar8,uVar12,0);
              if (lVar7 == 0) goto code_r0x00018049f16a;
              *(int *)(lVar7 + 0x1c) = *(int *)(lVar7 + 0x1c) + 1;
              if (*(longlong *)(lVar7 + 0x10) == 0) goto code_r0x00018049f16a;
              if (*(uint *)(lVar7 + 0x18) < *(uint *)(*(longlong *)(lVar7 + 0x10) + 0x18)) {
                *(uint *)(lVar7 + 0x18) = *(uint *)(lVar7 + 0x18) + 1;
                FUN_180002cd0();
              }
              else {
                FUN_1812741c0(lVar7);
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < 0x15);
            lVar11 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            uVar8 = FUN_1811d1d70(lVar7,DAT_182d52f18);
            if (lVar11 == 0) goto code_r0x00018049f16a;
            *(undefined8 *)(lVar11 + 0x98) = uVar8;
            if (DAT_182eb5d50 != 0) {
              uVar14 = (uint)(lVar11 + 0x98U >> 0xc);
              uVar6 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
              do {
                uVar13 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
                LOCK();
                bVar15 = uVar13 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
                if (bVar15) {
                  *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar13 | 1L << (uVar14 & 0x3f);
                }
                UNLOCK();
              } while (!bVar15);
            }
          }
          uVar6 = *(ulonglong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (uVar6 != 0) {
            if (*(longlong *)(uVar6 + 0xa0) != 0) {
              return uVar6;
            }
            lVar7 = FUN_1802c43a0(DAT_182d52f08);
            FUN_1811cf4f0(lVar7,DAT_182d52f10);
            while( true ) {
              uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                (uRam0000000182d60080,0);
              if (DAT_182ebb869 == '\0') {
                FUN_1802f2810(&DAT_182d24690);
                LOCK();
                UNLOCK();
                FUN_1802f2810(&DAT_182d39ea8);
                LOCK();
                UNLOCK();
                DAT_182ebb869 = '\x01';
              }
              if ((*(byte *)(*(longlong *)(DAT_182d39ea8 + 0x20) + 0x135) & 1) == 0) {
                FUN_180320470();
              }
              if (*(int *)(DAT_182d24690 + 0xe0) == 0) {
                FUN_18035c820();
              }
              uStack_188 = 0;
              plStack_180 = (longlong *)0x0;
              uVar12 = FUN_18161e8f0(iVar4,&uStack_188,0,0);
              System_String__Concat__0600021b(uVar8,uVar12,0);
              if (lVar7 == 0) break;
              *(int *)(lVar7 + 0x1c) = *(int *)(lVar7 + 0x1c) + 1;
              if (*(longlong *)(lVar7 + 0x10) == 0) break;
              if (*(uint *)(lVar7 + 0x18) < *(uint *)(*(longlong *)(lVar7 + 0x10) + 0x18)) {
                *(uint *)(lVar7 + 0x18) = *(uint *)(lVar7 + 0x18) + 1;
                FUN_180002cd0();
              }
              else {
                FUN_1812741c0(lVar7);
              }
              iVar4 = iVar4 + 1;
              if (0x14 < iVar4) {
                lVar11 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                uVar6 = FUN_1811d1d70(lVar7,DAT_182d52f18);
                if (lVar11 != 0) {
                  *(ulonglong *)(lVar11 + 0xa0) = uVar6;
                  if (DAT_182eb5d50 == 0) {
                    return uVar6;
                  }
                  uVar14 = (uint)(lVar11 + 0xa0U >> 0xc);
                  uVar6 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                  do {
                    uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
                    LOCK();
                    uVar13 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
                    bVar15 = uVar1 == uVar13;
                    if (bVar15) {
                      *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar1 | 1L << (uVar14 & 0x3f);
                      uVar13 = uVar1;
                    }
                    UNLOCK();
                  } while (!bVar15);
                  return uVar13;
                }
                break;
              }
            }
          }
        }
      }
    }
  }
code_r0x00018049f16a:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

