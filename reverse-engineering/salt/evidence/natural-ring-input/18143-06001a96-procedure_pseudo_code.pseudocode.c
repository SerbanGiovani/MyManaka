// Ghidra pseudocode; not original source or compilable C.
// ev_8f6445ea0405da37bd4919157cb1b4e02c1f1474cf67d24bb53d68af7e55cb99

void ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__Initialize__06001a96
               (longlong param_1)

{
  ulonglong uVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined1 *puVar9;
  longlong *plVar10;
  ulonglong uVar11;
  int iVar12;
  uint uVar13;
  bool bVar14;
  longlong lStackX_8;
  longlong lStack_78;
  longlong *plStack_70;
  undefined8 uStack_68;
  longlong lStack_58;
  longlong lStack_50;
  undefined8 uStack_48;
  
  lStackX_8 = param_1;
  if (cRam0000000182eb7ca6 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62540);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62560);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62530);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62520);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e108);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62510);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62508);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d624f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d624f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d624e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d624e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d624d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d624c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d624a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d624a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62490);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62480);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62470);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62460);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62448);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62430);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62420);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62410);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62400);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d623e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d623d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d623c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d623b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d623a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62388);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62348);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62330);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62318);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62300);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d622e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d622d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d622d0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ca6 = '\x01';
  }
  lStack_58 = 0;
  lStack_50 = 0;
  uStack_48 = 0;
  if (cRam0000000182eb7cb0 == '\0') {
    FUN_1802f2810(0x182d625a8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7cb0 = '\x01';
  }
  **(longlong **)(lRam0000000182d625a8 + 0xb8) = param_1;
  FUN_18031d480(*(undefined8 *)(lRam0000000182d625a8 + 0xb8));
  uVar7 = *(undefined8 *)(param_1 + 0x48);
  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DestroyChildren__0600172c(uVar7,0);
  lVar3 = *(longlong *)(param_1 + 0x50);
  if (*(longlong *)(param_1 + 200) != 0) {
    iVar12 = 0;
    *(undefined4 *)(*(longlong *)(param_1 + 200) + 0x10) = 0;
    if (lVar3 != 0) {
      FUN_1822053d0(lVar3,0,0);
      lVar3 = *(longlong *)(param_1 + 0x58);
      if ((*(longlong *)(param_1 + 0xd0) != 0) &&
         (*(undefined4 *)(*(longlong *)(param_1 + 0xd0) + 0x10) = 0, lVar3 != 0)) {
        FUN_1822053d0(lVar3,0,0);
        lVar3 = FUN_1802c43a0(uRam0000000182d624e8);
        FUN_1811cf4f0(lVar3,uRam0000000182d624f0);
        do {
          lVar4 = FUN_1802c43a0(uRam0000000182d62378);
          lVar5 = ExposureUnnoticed2_Master_Skill_MSkill__GetByIndex__06001233(iVar12,0);
          if ((lVar5 == 0) || (lVar4 == 0)) goto code_r0x00018050033a;
          *(undefined4 *)(lVar4 + 0x10) = *(undefined4 *)(lVar5 + 0x3c);
          lVar6 = FUN_1802c43a0(uRam0000000182d624d0);
          if (lVar6 == 0) goto code_r0x00018050033a;
          *(int *)(lVar6 + 0x30) = iVar12 + 8;
          *(int *)(lVar6 + 0x14) = iVar12 + 10000;
          uVar7 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                            (*(undefined8 *)(lVar5 + 0x18),0);
          *(undefined8 *)(lVar6 + 0x20) = uVar7;
          FUN_18031d480(lVar6 + 0x20);
          lVar8 = FUN_1802c43a0(uRam0000000182d5e108);
          lVar5 = lRam0000000182d62388;
          *(undefined8 *)(lVar8 + 0x10) = *(undefined8 *)(lRam0000000182d62388 + 8);
          *(longlong *)(lVar8 + 0x28) = lVar5;
          *(longlong *)(lVar8 + 0x20) = lVar4;
          FUN_18031d480(lVar8 + 0x20);
          cVar2 = *(char *)(lVar5 + 0x52);
          *(longlong *)(lVar8 + 0x40) = lVar8;
          if (((*(byte *)(lVar5 + 0x4c) & 0x10) == 0) || (cVar2 != '\0')) {
            *(undefined8 *)(lVar8 + 0x40) = *(undefined8 *)(lVar8 + 0x20);
            puVar9 = *(undefined1 **)(lVar8 + 0x10);
          }
          else {
            puVar9 = &LAB_1800c7840;
          }
          *(undefined1 **)(lVar8 + 0x18) = puVar9;
          *(code **)(lVar8 + 0x38) = FUN_1800c77e0;
          *(longlong *)(lVar6 + 0x28) = lVar8;
          FUN_18031d480(lVar6 + 0x28);
          if (lVar3 == 0) goto code_r0x00018050033a;
          FUN_1803d4be0(lVar3,lVar6,lRam0000000182d62510);
          iVar12 = iVar12 + 1;
        } while (iVar12 < 0x17);
        lVar4 = FUN_18098da40(*(undefined8 *)(param_1 + 0xe8),uRam0000000182d62540);
        plStack_70 = (longlong *)0x0;
        uStack_68 = 0;
        lStack_78 = lVar3;
        FUN_18031d480(&lStack_78);
        uStack_68 = 0;
        lStack_58 = lStack_78;
        lStack_50 = (ulonglong)*(uint *)(lVar3 + 0x1c) << 0x20;
        uStack_48 = 0;
        lStack_78 = 0;
        plStack_70 = &lStack_58;
        while (cVar2 = FUN_180f72b70(&lStack_58,uRam0000000182d62530), lVar3 = lRam0000000182d62510,
              cVar2 != '\0') {
          if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          *(int *)(lVar4 + 0x1c) = *(int *)(lVar4 + 0x1c) + 1;
          lVar5 = *(longlong *)(lVar4 + 0x10);
          uVar13 = *(uint *)(lVar4 + 0x18);
          if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          if (uVar13 < *(uint *)(lVar5 + 0x18)) {
            *(uint *)(lVar4 + 0x18) = uVar13 + 1;
            FUN_180002cd0(lVar5,(longlong)(int)uVar13,uStack_48);
          }
          else {
            FUN_1812741c0(lVar4,uStack_48,
                          *(undefined8 *)(*(longlong *)(*(longlong *)(lVar3 + 0x20) + 0xc0) + 0x70))
            ;
          }
        }
        if (lVar4 != 0) {
          uVar7 = FUN_1811d1d70(lVar4,uRam0000000182d624f8);
          *(undefined8 *)(param_1 + 0xe8) = uVar7;
          if (DAT_182eb5d50 != 0) {
            uVar13 = (uint)(param_1 + 0xe8U >> 0xc);
            uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
            do {
              uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
              LOCK();
              bVar14 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
              if (bVar14) {
                *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar1 | 1L << (uVar13 & 0x3f);
              }
              UNLOCK();
            } while (!bVar14);
          }
          if (*(longlong *)(param_1 + 0xe8) != 0) {
            iVar12 = *(int *)(*(longlong *)(param_1 + 0xe8) + 0x18) + -1;
            *(int *)(param_1 + 0xdc) = (int)(iVar12 + (iVar12 >> 0x1f & 7U)) >> 3;
            plVar10 = (longlong *)FUN_1802c36c0(uRam0000000182d624e0,6);
            lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
            uVar7 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                              (uRam0000000182d62348,0);
            if (lVar3 != 0) {
              *(undefined8 *)(lVar3 + 0x20) = uVar7;
              if (DAT_182eb5d50 != 0) {
                uVar13 = (uint)(lVar3 + 0x20U >> 0xc);
                uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                do {
                  uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                  LOCK();
                  bVar14 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                  if (bVar14) {
                    *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar1 | 1L << (uVar13 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar14);
              }
              if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                FUN_18035c820();
              }
              lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d62368 + 0xb8) + 8);
              if (lVar4 == 0) {
                if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                uVar7 = **(undefined8 **)(lRam0000000182d62368 + 0xb8);
                lVar4 = FUN_1802c43a0(DAT_182d58368);
                FUN_1814df680(lVar4,uVar7,uRam0000000182d62430,0);
                *(longlong *)(*(longlong *)(lRam0000000182d62368 + 0xb8) + 8) = lVar4;
                FUN_18031d480(*(longlong *)(lRam0000000182d62368 + 0xb8) + 8);
              }
              *(longlong *)(lVar3 + 0x18) = lVar4;
              if (DAT_182eb5d50 != 0) {
                uVar13 = (uint)(lVar3 + 0x18U >> 0xc);
                uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                do {
                  uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                  LOCK();
                  bVar14 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                  if (bVar14) {
                    *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar1 | 1L << (uVar13 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar14);
              }
              if (plVar10 != (longlong *)0x0) {
                lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)(*plVar10 + 0x40));
                if (lVar4 == 0) {
                  uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                  FUN_18031da90(uVar7,0);
                }
                FUN_180002cd0(plVar10,0,lVar3);
                lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
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
                lStack_78 = 0;
                plStack_70 = (longlong *)0x0;
                uVar7 = FUN_18161e8f0(1,&lStack_78,0,0);
                uVar7 = System_String__Concat__0600021b(uRam0000000182d62300,uVar7,0);
                uVar7 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar7,0);
                if (lVar3 != 0) {
                  *(undefined8 *)(lVar3 + 0x20) = uVar7;
                  if (DAT_182eb5d50 != 0) {
                    uVar13 = (uint)(lVar3 + 0x20U >> 0xc);
                    uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                    do {
                      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                      LOCK();
                      bVar14 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                      if (bVar14) {
                        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar1 | 1L << (uVar13 & 0x3f);
                      }
                      UNLOCK();
                    } while (!bVar14);
                  }
                  if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x10);
                  if (lVar4 == 0) {
                    if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                      FUN_18035c820();
                    }
                    uVar7 = **(undefined8 **)(lRam0000000182d62368 + 0xb8);
                    lVar4 = FUN_1802c43a0(DAT_182d58368);
                    FUN_1814df680(lVar4,uVar7,uRam0000000182d62420,0);
                    *(longlong *)(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x10) = lVar4;
                    FUN_18031d480(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x10);
                  }
                  *(longlong *)(lVar3 + 0x18) = lVar4;
                  if (DAT_182eb5d50 != 0) {
                    uVar13 = (uint)(lVar3 + 0x18U >> 0xc);
                    uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                    do {
                      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                      LOCK();
                      bVar14 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                      if (bVar14) {
                        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar1 | 1L << (uVar13 & 0x3f);
                      }
                      UNLOCK();
                    } while (!bVar14);
                  }
                  lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)(*plVar10 + 0x40));
                  if (lVar4 == 0) {
                    uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                    FUN_18031da90(uVar7,0);
                  }
                  FUN_180002cd0(plVar10,1,lVar3);
                  lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
                  lStackX_8 = CONCAT44(lStackX_8._4_4_,2);
                  uVar7 = FUN_181618010(&lStackX_8,0);
                  uVar7 = System_String__Concat__0600021b(uRam0000000182d62300,uVar7,0);
                  uVar7 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar7,0);
                  if (lVar3 != 0) {
                    UB_ThreadAction__set_GroupName__060007fa(lVar3,uVar7);
                    if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                      FUN_18035c820(lRam0000000182d62368);
                    }
                    lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x18);
                    if (lVar4 == 0) {
                      if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                        FUN_18035c820(lRam0000000182d62368);
                      }
                      uVar7 = **(undefined8 **)(lRam0000000182d62368 + 0xb8);
                      lVar4 = FUN_1802c43a0(DAT_182d58368);
                      FUN_1814df680(lVar4,uVar7,uRam0000000182d62410,0);
                      *(longlong *)(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x18) = lVar4;
                      FUN_18031d480(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x18);
                    }
                    AkilliMum_Standard_Mirror_RenderTextureManager__set_LeftOrCenterRT1__0600091f
                              (lVar3,lVar4);
                    lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)(*plVar10 + 0x40));
                    if (lVar4 == 0) {
                      uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                      FUN_18031da90(uVar7,0);
                    }
                    FUN_180002cd0(plVar10,2,lVar3);
                    lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
                    lStackX_8 = CONCAT44(lStackX_8._4_4_,3);
                    uVar7 = FUN_181618010(&lStackX_8,0);
                    uVar7 = System_String__Concat__0600021b(uRam0000000182d62300,uVar7,0);
                    uVar7 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar7,0);
                    if (lVar3 != 0) {
                      UB_ThreadAction__set_GroupName__060007fa(lVar3,uVar7);
                      if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                        FUN_18035c820(lRam0000000182d62368);
                      }
                      lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x20);
                      if (lVar4 == 0) {
                        if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                          FUN_18035c820(lRam0000000182d62368);
                        }
                        uVar7 = **(undefined8 **)(lRam0000000182d62368 + 0xb8);
                        lVar4 = FUN_1802c43a0(DAT_182d58368);
                        FUN_1814df680(lVar4,uVar7,uRam0000000182d62400,0);
                        *(longlong *)(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x20) = lVar4;
                        FUN_18031d480(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x20);
                      }
                      AkilliMum_Standard_Mirror_RenderTextureManager__set_LeftOrCenterRT1__0600091f
                                (lVar3,lVar4);
                      lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)(*plVar10 + 0x40));
                      if (lVar4 == 0) {
                        uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                        FUN_18031da90(uVar7,0);
                      }
                      FUN_180002cd0(plVar10,3,lVar3);
                      lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
                      lStackX_8 = CONCAT44(lStackX_8._4_4_,4);
                      uVar7 = FUN_181618010(&lStackX_8,0);
                      uVar7 = System_String__Concat__0600021b(uRam0000000182d62300,uVar7,0);
                      uVar7 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar7,0);
                      if (lVar3 != 0) {
                        UB_ThreadAction__set_GroupName__060007fa(lVar3,uVar7);
                        if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                          FUN_18035c820(lRam0000000182d62368);
                        }
                        lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x28);
                        if (lVar4 == 0) {
                          if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                            FUN_18035c820(lRam0000000182d62368);
                          }
                          uVar7 = **(undefined8 **)(lRam0000000182d62368 + 0xb8);
                          lVar4 = FUN_1802c43a0(DAT_182d58368);
                          FUN_1814df680(lVar4,uVar7,uRam0000000182d623e8,0);
                          *(longlong *)(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x28) = lVar4;
                          FUN_18031d480(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x28);
                        }
                        AkilliMum_Standard_Mirror_RenderTextureManager__set_LeftOrCenterRT1__0600091f
                                  (lVar3,lVar4);
                        lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)(*plVar10 + 0x40));
                        if (lVar4 == 0) {
                          uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                          FUN_18031da90(uVar7,0);
                        }
                        FUN_180002cd0(plVar10,4,lVar3);
                        lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
                        lStackX_8 = CONCAT44(lStackX_8._4_4_,5);
                        uVar7 = FUN_181618010(&lStackX_8,0);
                        uVar7 = System_String__Concat__0600021b(uRam0000000182d62300,uVar7,0);
                        uVar7 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar7,0);
                        if (lVar3 != 0) {
                          UB_ThreadAction__set_GroupName__060007fa(lVar3,uVar7);
                          if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                            FUN_18035c820(lRam0000000182d62368);
                          }
                          lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x30);
                          if (lVar4 == 0) {
                            if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                              FUN_18035c820(lRam0000000182d62368);
                            }
                            uVar7 = **(undefined8 **)(lRam0000000182d62368 + 0xb8);
                            lVar4 = FUN_1802c43a0(DAT_182d58368);
                            FUN_1814df680(lVar4,uVar7,uRam0000000182d623d0,0);
                            *(longlong *)(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x30) = lVar4
                            ;
                            FUN_18031d480(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x30);
                          }
                          AkilliMum_Standard_Mirror_RenderTextureManager__set_LeftOrCenterRT1__0600091f
                                    (lVar3,lVar4);
                          lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)(*plVar10 + 0x40));
                          if (lVar4 == 0) {
                            uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                            FUN_18031da90(uVar7,0);
                          }
                          FUN_180002cd0(plVar10,5,lVar3);
                          *(longlong **)(param_1 + 0xf8) = plVar10;
                          FUN_18031d480(param_1 + 0xf8);
                          plVar10 = (longlong *)FUN_1802c36c0(uRam0000000182d624e0,6);
                          lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
                          uVar7 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                            (uRam0000000182d62348,0);
                          if (lVar3 != 0) {
                            UB_ThreadAction__set_GroupName__060007fa(lVar3,uVar7);
                            if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                              FUN_18035c820(lRam0000000182d62368);
                            }
                            lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x38)
                            ;
                            if (lVar4 == 0) {
                              if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                FUN_18035c820(lRam0000000182d62368);
                              }
                              uVar7 = **(undefined8 **)(lRam0000000182d62368 + 0xb8);
                              lVar4 = FUN_1802c43a0(DAT_182d58368);
                              FUN_1814df680(lVar4,uVar7,uRam0000000182d623c0,0);
                              *(longlong *)(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x38) =
                                   lVar4;
                              FUN_18031d480(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x38);
                            }
                            AkilliMum_Standard_Mirror_RenderTextureManager__set_LeftOrCenterRT1__0600091f
                                      (lVar3,lVar4);
                            if (plVar10 != (longlong *)0x0) {
                              lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)(*plVar10 + 0x40));
                              if (lVar4 == 0) {
                                uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                                FUN_18031da90(uVar7,0);
                              }
                              FUN_180002cd0(plVar10,0,lVar3);
                              lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
                              lStackX_8 = CONCAT44(lStackX_8._4_4_,1);
                              uVar7 = FUN_181618010(&lStackX_8,0);
                              uVar7 = System_String__Concat__0600021b(uRam0000000182d62300,uVar7,0);
                              uVar7 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                (uVar7,0);
                              if (lVar3 != 0) {
                                UB_ThreadAction__set_GroupName__060007fa(lVar3,uVar7);
                                if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                  FUN_18035c820(lRam0000000182d62368);
                                }
                                lVar4 = *(longlong *)
                                         (*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x40);
                                if (lVar4 == 0) {
                                  if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                    FUN_18035c820(lRam0000000182d62368);
                                  }
                                  uVar7 = **(undefined8 **)(lRam0000000182d62368 + 0xb8);
                                  lVar4 = FUN_1802c43a0(DAT_182d58368);
                                  FUN_1814df680(lVar4,uVar7,uRam0000000182d623b0,0);
                                  *(longlong *)(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x40) =
                                       lVar4;
                                  FUN_18031d480(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x40);
                                }
                                AkilliMum_Standard_Mirror_RenderTextureManager__set_LeftOrCenterRT1__0600091f
                                          (lVar3,lVar4);
                                lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)(*plVar10 + 0x40));
                                if (lVar4 == 0) {
                                  uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                                  FUN_18031da90(uVar7,0);
                                }
                                FUN_180002cd0(plVar10,1,lVar3);
                                lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
                                lStackX_8 = CONCAT44(lStackX_8._4_4_,2);
                                uVar7 = FUN_181618010(&lStackX_8,0);
                                uVar7 = System_String__Concat__0600021b
                                                  (uRam0000000182d62300,uVar7,0);
                                uVar7 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                  (uVar7,0);
                                if (lVar3 != 0) {
                                  UB_ThreadAction__set_GroupName__060007fa(lVar3,uVar7);
                                  if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                    FUN_18035c820(lRam0000000182d62368);
                                  }
                                  lVar4 = *(longlong *)
                                           (*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x48);
                                  if (lVar4 == 0) {
                                    if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                      FUN_18035c820(lRam0000000182d62368);
                                    }
                                    uVar7 = **(undefined8 **)(lRam0000000182d62368 + 0xb8);
                                    lVar4 = FUN_1802c43a0(DAT_182d58368);
                                    FUN_1814df680(lVar4,uVar7,uRam0000000182d623a0,0);
                                    *(longlong *)(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x48)
                                         = lVar4;
                                    FUN_18031d480(*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x48)
                                    ;
                                  }
                                  AkilliMum_Standard_Mirror_RenderTextureManager__set_LeftOrCenterRT1__0600091f
                                            (lVar3,lVar4);
                                  lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)(*plVar10 + 0x40));
                                  if (lVar4 == 0) {
                                    uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                                    FUN_18031da90(uVar7,0);
                                  }
                                  FUN_180002cd0(plVar10,2,lVar3);
                                  lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
                                  lStackX_8 = CONCAT44(lStackX_8._4_4_,3);
                                  uVar7 = FUN_181618010(&lStackX_8,0);
                                  uVar7 = System_String__Concat__0600021b
                                                    (uRam0000000182d62300,uVar7,0);
                                  uVar7 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                    (uVar7,0);
                                  if (lVar3 != 0) {
                                    UB_ThreadAction__set_GroupName__060007fa(lVar3,uVar7);
                                    if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                      FUN_18035c820(lRam0000000182d62368);
                                    }
                                    lVar4 = *(longlong *)
                                             (*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x50);
                                    if (lVar4 == 0) {
                                      if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                        FUN_18035c820(lRam0000000182d62368);
                                      }
                                      uVar7 = **(undefined8 **)(lRam0000000182d62368 + 0xb8);
                                      lVar4 = FUN_1802c43a0(DAT_182d58368);
                                      FUN_1814df680(lVar4,uVar7,uRam0000000182d624c0,0);
                                      *(longlong *)
                                       (*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x50) = lVar4;
                                      FUN_18031d480(*(longlong *)(lRam0000000182d62368 + 0xb8) +
                                                    0x50);
                                    }
                                    AkilliMum_Standard_Mirror_RenderTextureManager__set_LeftOrCenterRT1__0600091f
                                              (lVar3,lVar4);
                                    lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)(*plVar10 + 0x40));
                                    if (lVar4 == 0) {
                                      uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                                      FUN_18031da90(uVar7,0);
                                    }
                                    FUN_180002cd0(plVar10,3,lVar3);
                                    lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
                                    if (DAT_182ebb869 == '\0') {
                                      FUN_1802f2810(&DAT_182d24690);
                                      LOCK();
                                      UNLOCK();
                                      FUN_1802f2810(&DAT_182d39ea8);
                                      LOCK();
                                      UNLOCK();
                                      DAT_182ebb869 = '\x01';
                                    }
                                    if ((*(byte *)(*(longlong *)(DAT_182d39ea8 + 0x20) + 0x135) & 1)
                                        == 0) {
                                      FUN_180320470();
                                    }
                                    if (*(int *)(DAT_182d24690 + 0xe0) == 0) {
                                      FUN_18035c820();
                                    }
                                    lStack_78 = 0;
                                    plStack_70 = (longlong *)0x0;
                                    uVar7 = FUN_18161e8f0(4,&lStack_78,0,0);
                                    uVar7 = System_String__Concat__0600021b
                                                      (uRam0000000182d62300,uVar7,0);
                                    uVar7 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                      (uVar7,0);
                                    if (lVar3 != 0) {
                                      *(undefined8 *)(lVar3 + 0x20) = uVar7;
                                      if (DAT_182eb5d50 != 0) {
                                        uVar13 = (uint)(lVar3 + 0x20U >> 0xc);
                                        uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                        do {
                                          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                                          LOCK();
                                          bVar14 = uVar1 == *(ulonglong *)
                                                             (&DAT_182f0c920 + uVar11 * 8);
                                          if (bVar14) {
                                            *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) =
                                                 uVar1 | 1L << (uVar13 & 0x3f);
                                          }
                                          UNLOCK();
                                        } while (!bVar14);
                                      }
                                      if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                        FUN_18035c820();
                                      }
                                      lVar4 = *(longlong *)
                                               (*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x58);
                                      if (lVar4 == 0) {
                                        if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                          FUN_18035c820();
                                        }
                                        uVar7 = **(undefined8 **)(lRam0000000182d62368 + 0xb8);
                                        lVar4 = FUN_1802c43a0(DAT_182d58368);
                                        FUN_1814df680(lVar4,uVar7,uRam0000000182d624a8,0);
                                        *(longlong *)
                                         (*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x58) = lVar4
                                        ;
                                        FUN_18031d480(*(longlong *)(lRam0000000182d62368 + 0xb8) +
                                                      0x58);
                                      }
                                      *(longlong *)(lVar3 + 0x18) = lVar4;
                                      if (DAT_182eb5d50 != 0) {
                                        uVar13 = (uint)(lVar3 + 0x18U >> 0xc);
                                        uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                        do {
                                          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                                          LOCK();
                                          bVar14 = uVar1 == *(ulonglong *)
                                                             (&DAT_182f0c920 + uVar11 * 8);
                                          if (bVar14) {
                                            *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) =
                                                 uVar1 | 1L << (uVar13 & 0x3f);
                                          }
                                          UNLOCK();
                                        } while (!bVar14);
                                      }
                                      lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)(*plVar10 + 0x40));
                                      if (lVar4 == 0) {
                                        uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                                        FUN_18031da90(uVar7,0);
                                      }
                                      FUN_180002cd0(plVar10,4,lVar3);
                                      lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
                                      if (DAT_182ebb869 == '\0') {
                                        FUN_1802f2810(&DAT_182d24690);
                                        LOCK();
                                        UNLOCK();
                                        FUN_1802f2810(&DAT_182d39ea8);
                                        LOCK();
                                        UNLOCK();
                                        DAT_182ebb869 = '\x01';
                                      }
                                      if ((*(byte *)(*(longlong *)(DAT_182d39ea8 + 0x20) + 0x135) &
                                          1) == 0) {
                                        FUN_180320470();
                                      }
                                      if (*(int *)(DAT_182d24690 + 0xe0) == 0) {
                                        FUN_18035c820();
                                      }
                                      lStack_78 = 0;
                                      plStack_70 = (longlong *)0x0;
                                      uVar7 = FUN_18161e8f0(5,&lStack_78,0,0);
                                      uVar7 = System_String__Concat__0600021b
                                                        (uRam0000000182d62300,uVar7,0);
                                      uVar7 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                        (uVar7,0);
                                      if (lVar3 != 0) {
                                        *(undefined8 *)(lVar3 + 0x20) = uVar7;
                                        if (DAT_182eb5d50 != 0) {
                                          uVar13 = (uint)(lVar3 + 0x20U >> 0xc);
                                          uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                          do {
                                            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                                            LOCK();
                                            bVar14 = uVar1 == *(ulonglong *)
                                                               (&DAT_182f0c920 + uVar11 * 8);
                                            if (bVar14) {
                                              *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) =
                                                   uVar1 | 1L << (uVar13 & 0x3f);
                                            }
                                            UNLOCK();
                                          } while (!bVar14);
                                        }
                                        if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                          FUN_18035c820();
                                        }
                                        lVar4 = *(longlong *)
                                                 (*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x60)
                                        ;
                                        if (lVar4 == 0) {
                                          if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                            FUN_18035c820();
                                          }
                                          uVar7 = **(undefined8 **)(lRam0000000182d62368 + 0xb8);
                                          lVar4 = FUN_1802c43a0(DAT_182d58368);
                                          FUN_1814df680(lVar4,uVar7,uRam0000000182d624a0,0);
                                          *(longlong *)
                                           (*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x60) =
                                               lVar4;
                                          FUN_18031d480(*(longlong *)(lRam0000000182d62368 + 0xb8) +
                                                        0x60);
                                        }
                                        *(longlong *)(lVar3 + 0x18) = lVar4;
                                        if (DAT_182eb5d50 != 0) {
                                          uVar13 = (uint)(lVar3 + 0x18U >> 0xc);
                                          uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                          do {
                                            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                                            LOCK();
                                            bVar14 = uVar1 == *(ulonglong *)
                                                               (&DAT_182f0c920 + uVar11 * 8);
                                            if (bVar14) {
                                              *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) =
                                                   uVar1 | 1L << (uVar13 & 0x3f);
                                            }
                                            UNLOCK();
                                          } while (!bVar14);
                                        }
                                        lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)(*plVar10 + 0x40)
                                                             );
                                        if (lVar4 == 0) {
                                          uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                                          FUN_18031da90(uVar7,0);
                                        }
                                        FUN_180002cd0(plVar10,5,lVar3);
                                        *(longlong **)(param_1 + 0x100) = plVar10;
                                        if (DAT_182eb5d50 != 0) {
                                          uVar13 = (uint)(param_1 + 0x100U >> 0xc);
                                          uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                          do {
                                            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                                            LOCK();
                                            bVar14 = uVar1 == *(ulonglong *)
                                                               (&DAT_182f0c920 + uVar11 * 8);
                                            if (bVar14) {
                                              *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) =
                                                   uVar1 | 1L << (uVar13 & 0x3f);
                                            }
                                            UNLOCK();
                                          } while (!bVar14);
                                        }
                                        plVar10 = (longlong *)FUN_1802c36c0(uRam0000000182d624e0,5);
                                        lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
                                        uVar7 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                          (uRam0000000182d622e8,0);
                                        if (lVar3 != 0) {
                                          *(undefined8 *)(lVar3 + 0x20) = uVar7;
                                          if (DAT_182eb5d50 != 0) {
                                            uVar13 = (uint)(lVar3 + 0x20U >> 0xc);
                                            uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                            do {
                                              uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                                              LOCK();
                                              bVar14 = uVar1 == *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar11 * 8);
                                              if (bVar14) {
                                                *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) =
                                                     uVar1 | 1L << (uVar13 & 0x3f);
                                              }
                                              UNLOCK();
                                            } while (!bVar14);
                                          }
                                          if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                            FUN_18035c820();
                                          }
                                          lVar4 = *(longlong *)
                                                   (*(longlong *)(lRam0000000182d62368 + 0xb8) +
                                                   0x68);
                                          if (lVar4 == 0) {
                                            if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                              FUN_18035c820();
                                            }
                                            uVar7 = **(undefined8 **)(lRam0000000182d62368 + 0xb8);
                                            lVar4 = FUN_1802c43a0(DAT_182d58368);
                                            FUN_1814df680(lVar4,uVar7,uRam0000000182d62490,0);
                                            *(longlong *)
                                             (*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x68) =
                                                 lVar4;
                                            FUN_18031d480(*(longlong *)(lRam0000000182d62368 + 0xb8)
                                                          + 0x68);
                                          }
                                          *(longlong *)(lVar3 + 0x18) = lVar4;
                                          if (DAT_182eb5d50 != 0) {
                                            uVar13 = (uint)(lVar3 + 0x18U >> 0xc);
                                            uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                            do {
                                              uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                                              LOCK();
                                              bVar14 = uVar1 == *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar11 * 8);
                                              if (bVar14) {
                                                *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) =
                                                     uVar1 | 1L << (uVar13 & 0x3f);
                                              }
                                              UNLOCK();
                                            } while (!bVar14);
                                          }
                                          if (plVar10 != (longlong *)0x0) {
                                            lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)
                                                                         (*plVar10 + 0x40));
                                            if (lVar4 == 0) {
                                              uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                                              FUN_18031da90(uVar7,0);
                                            }
                                            FUN_180002cd0(plVar10,0,lVar3);
                                            lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
                                            uVar7 = 
                                                  ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                            (uRam0000000182d622d0,0);
                                            if (lVar3 != 0) {
                                              *(undefined8 *)(lVar3 + 0x20) = uVar7;
                                              if (DAT_182eb5d50 != 0) {
                                                uVar13 = (uint)(lVar3 + 0x20U >> 0xc);
                                                uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                                do {
                                                  uVar1 = *(ulonglong *)
                                                           (&DAT_182f0c920 + uVar11 * 8);
                                                  LOCK();
                                                  bVar14 = uVar1 == *(ulonglong *)
                                                                     (&DAT_182f0c920 + uVar11 * 8);
                                                  if (bVar14) {
                                                    *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) =
                                                         uVar1 | 1L << (uVar13 & 0x3f);
                                                  }
                                                  UNLOCK();
                                                } while (!bVar14);
                                              }
                                              if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                                FUN_18035c820();
                                              }
                                              lVar4 = *(longlong *)
                                                       (*(longlong *)(lRam0000000182d62368 + 0xb8) +
                                                       0x70);
                                              if (lVar4 == 0) {
                                                if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                                  FUN_18035c820();
                                                }
                                                uVar7 = **(undefined8 **)
                                                          (lRam0000000182d62368 + 0xb8);
                                                lVar4 = FUN_1802c43a0(DAT_182d58368);
                                                FUN_1814df680(lVar4,uVar7,uRam0000000182d62480,0);
                                                *(longlong *)
                                                 (*(longlong *)(lRam0000000182d62368 + 0xb8) + 0x70)
                                                     = lVar4;
                                                FUN_18031d480(*(longlong *)
                                                               (lRam0000000182d62368 + 0xb8) + 0x70)
                                                ;
                                              }
                                              *(longlong *)(lVar3 + 0x18) = lVar4;
                                              if (DAT_182eb5d50 != 0) {
                                                uVar13 = (uint)(lVar3 + 0x18U >> 0xc);
                                                uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                                do {
                                                  uVar1 = *(ulonglong *)
                                                           (&DAT_182f0c920 + uVar11 * 8);
                                                  LOCK();
                                                  bVar14 = uVar1 == *(ulonglong *)
                                                                     (&DAT_182f0c920 + uVar11 * 8);
                                                  if (bVar14) {
                                                    *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) =
                                                         uVar1 | 1L << (uVar13 & 0x3f);
                                                  }
                                                  UNLOCK();
                                                } while (!bVar14);
                                              }
                                              lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)
                                                                           (*plVar10 + 0x40));
                                              if (lVar4 == 0) {
                                                uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                                                FUN_18031da90(uVar7,0);
                                              }
                                              FUN_180002cd0(plVar10,1,lVar3);
                                              lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
                                              uVar7 = 
                                                  ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                            (uRam0000000182d622d8,0);
                                              if (lVar3 != 0) {
                                                *(undefined8 *)(lVar3 + 0x20) = uVar7;
                                                if (DAT_182eb5d50 != 0) {
                                                  uVar13 = (uint)(lVar3 + 0x20U >> 0xc);
                                                  uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                                  do {
                                                    uVar1 = *(ulonglong *)
                                                             (&DAT_182f0c920 + uVar11 * 8);
                                                    LOCK();
                                                    bVar14 = uVar1 == *(ulonglong *)
                                                                       (&DAT_182f0c920 + uVar11 * 8)
                                                    ;
                                                    if (bVar14) {
                                                      *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) =
                                                           uVar1 | 1L << (uVar13 & 0x3f);
                                                    }
                                                    UNLOCK();
                                                  } while (!bVar14);
                                                }
                                                if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                                  FUN_18035c820();
                                                }
                                                lVar4 = *(longlong *)
                                                         (*(longlong *)(lRam0000000182d62368 + 0xb8)
                                                         + 0x78);
                                                if (lVar4 == 0) {
                                                  if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  uVar7 = **(undefined8 **)
                                                            (lRam0000000182d62368 + 0xb8);
                                                  lVar4 = FUN_1802c43a0(DAT_182d58368);
                                                  FUN_1814df680(lVar4,uVar7,uRam0000000182d62470,0);
                                                  *(longlong *)
                                                   (*(longlong *)(lRam0000000182d62368 + 0xb8) +
                                                   0x78) = lVar4;
                                                  FUN_18031d480(*(longlong *)
                                                                 (lRam0000000182d62368 + 0xb8) +
                                                                0x78);
                                                }
                                                *(longlong *)(lVar3 + 0x18) = lVar4;
                                                if (DAT_182eb5d50 != 0) {
                                                  uVar13 = (uint)(lVar3 + 0x18U >> 0xc);
                                                  uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                                  do {
                                                    uVar1 = *(ulonglong *)
                                                             (&DAT_182f0c920 + uVar11 * 8);
                                                    LOCK();
                                                    bVar14 = uVar1 == *(ulonglong *)
                                                                       (&DAT_182f0c920 + uVar11 * 8)
                                                    ;
                                                    if (bVar14) {
                                                      *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) =
                                                           uVar1 | 1L << (uVar13 & 0x3f);
                                                    }
                                                    UNLOCK();
                                                  } while (!bVar14);
                                                }
                                                lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)
                                                                             (*plVar10 + 0x40));
                                                if (lVar4 == 0) {
                                                  uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                                                  FUN_18031da90(uVar7,0);
                                                }
                                                FUN_180002cd0(plVar10,2,lVar3);
                                                lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
                                                uVar7 = 
                                                  ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                            (uRam0000000182d62330,0);
                                                if (lVar3 != 0) {
                                                  *(undefined8 *)(lVar3 + 0x20) = uVar7;
                                                  if (DAT_182eb5d50 != 0) {
                                                    uVar13 = (uint)(lVar3 + 0x20U >> 0xc);
                                                    uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                                    do {
                                                      uVar1 = *(ulonglong *)
                                                               (&DAT_182f0c920 + uVar11 * 8);
                                                      LOCK();
                                                      bVar14 = uVar1 == *(ulonglong *)
                                                                         (&DAT_182f0c920 +
                                                                         uVar11 * 8);
                                                      if (bVar14) {
                                                        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8)
                                                             = uVar1 | 1L << (uVar13 & 0x3f);
                                                      }
                                                      UNLOCK();
                                                    } while (!bVar14);
                                                  }
                                                  if (*(int *)(lRam0000000182d62368 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  lVar4 = *(longlong *)
                                                           (*(longlong *)
                                                             (lRam0000000182d62368 + 0xb8) + 0x80);
                                                  if (lVar4 == 0) {
                                                    if (*(int *)(lRam0000000182d62368 + 0xe0) == 0)
                                                    {
                                                      FUN_18035c820();
                                                    }
                                                    uVar7 = **(undefined8 **)
                                                              (lRam0000000182d62368 + 0xb8);
                                                    lVar4 = FUN_1802c43a0(DAT_182d58368);
                                                    FUN_1814df680(lVar4,uVar7,uRam0000000182d62460,0
                                                                 );
                                                    *(longlong *)
                                                     (*(longlong *)(lRam0000000182d62368 + 0xb8) +
                                                     0x80) = lVar4;
                                                    FUN_18031d480(*(longlong *)
                                                                   (lRam0000000182d62368 + 0xb8) +
                                                                  0x80);
                                                  }
                                                  *(longlong *)(lVar3 + 0x18) = lVar4;
                                                  if (DAT_182eb5d50 != 0) {
                                                    uVar13 = (uint)(lVar3 + 0x18U >> 0xc);
                                                    uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                                    do {
                                                      uVar1 = *(ulonglong *)
                                                               (&DAT_182f0c920 + uVar11 * 8);
                                                      LOCK();
                                                      bVar14 = uVar1 == *(ulonglong *)
                                                                         (&DAT_182f0c920 +
                                                                         uVar11 * 8);
                                                      if (bVar14) {
                                                        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8)
                                                             = uVar1 | 1L << (uVar13 & 0x3f);
                                                      }
                                                      UNLOCK();
                                                    } while (!bVar14);
                                                  }
                                                  lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)
                                                                               (*plVar10 + 0x40));
                                                  if (lVar4 == 0) {
                                                    uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031da90(uVar7,0);
                                                  }
                                                  FUN_180002cd0(plVar10,3,lVar3);
                                                  lVar3 = FUN_1802c43a0(uRam0000000182d624d0);
                                                  uVar7 = 
                                                  ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                            (uRam0000000182d62318,0);
                                                  if (lVar3 != 0) {
                                                    *(undefined8 *)(lVar3 + 0x20) = uVar7;
                                                    if (DAT_182eb5d50 != 0) {
                                                      uVar13 = (uint)(lVar3 + 0x20U >> 0xc);
                                                      uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6)
                                                      ;
                                                      do {
                                                        uVar1 = *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar11 * 8);
                                                        LOCK();
                                                        bVar14 = uVar1 == *(ulonglong *)
                                                                           (&DAT_182f0c920 +
                                                                           uVar11 * 8);
                                                        if (bVar14) {
                                                          *(ulonglong *)
                                                           (&DAT_182f0c920 + uVar11 * 8) =
                                                               uVar1 | 1L << (uVar13 & 0x3f);
                                                        }
                                                        UNLOCK();
                                                      } while (!bVar14);
                                                    }
                                                    if (*(int *)(lRam0000000182d62368 + 0xe0) == 0)
                                                    {
                                                      FUN_18035c820();
                                                    }
                                                    lVar4 = *(longlong *)
                                                             (*(longlong *)
                                                               (lRam0000000182d62368 + 0xb8) + 0x88)
                                                    ;
                                                    if (lVar4 == 0) {
                                                      if (*(int *)(lRam0000000182d62368 + 0xe0) == 0
                                                         ) {
                                                        FUN_18035c820();
                                                      }
                                                      uVar7 = **(undefined8 **)
                                                                (lRam0000000182d62368 + 0xb8);
                                                      lVar4 = FUN_1802c43a0(DAT_182d58368);
                                                      FUN_1814df680(lVar4,uVar7,uRam0000000182d62448
                                                                    ,0);
                                                      *(longlong *)
                                                       (*(longlong *)(lRam0000000182d62368 + 0xb8) +
                                                       0x88) = lVar4;
                                                      FUN_18031d480(*(longlong *)
                                                                     (lRam0000000182d62368 + 0xb8) +
                                                                    0x88);
                                                    }
                                                    *(longlong *)(lVar3 + 0x18) = lVar4;
                                                    if (DAT_182eb5d50 != 0) {
                                                      uVar13 = (uint)(lVar3 + 0x18U >> 0xc);
                                                      uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6)
                                                      ;
                                                      do {
                                                        uVar1 = *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar11 * 8);
                                                        LOCK();
                                                        bVar14 = uVar1 == *(ulonglong *)
                                                                           (&DAT_182f0c920 +
                                                                           uVar11 * 8);
                                                        if (bVar14) {
                                                          *(ulonglong *)
                                                           (&DAT_182f0c920 + uVar11 * 8) =
                                                               uVar1 | 1L << (uVar13 & 0x3f);
                                                        }
                                                        UNLOCK();
                                                      } while (!bVar14);
                                                    }
                                                    lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)
                                                                                 (*plVar10 + 0x40));
                                                    if (lVar4 == 0) {
                                                      uVar7 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031da90(uVar7,0);
                                                    }
                                                    FUN_180002cd0(plVar10,4,lVar3);
                                                    *(longlong **)(param_1 + 0x108) = plVar10;
                                                    if (DAT_182eb5d50 != 0) {
                                                      uVar13 = (uint)(param_1 + 0x108U >> 0xc);
                                                      uVar11 = (ulonglong)((uVar13 & 0x1fffff) >> 6)
                                                      ;
                                                      do {
                                                        uVar1 = *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar11 * 8);
                                                        LOCK();
                                                        bVar14 = uVar1 == *(ulonglong *)
                                                                           (&DAT_182f0c920 +
                                                                           uVar11 * 8);
                                                        if (bVar14) {
                                                          *(ulonglong *)
                                                           (&DAT_182f0c920 + uVar11 * 8) =
                                                               uVar1 | 1L << (uVar13 & 0x3f);
                                                        }
                                                        UNLOCK();
                                                      } while (!bVar14);
                                                    }
                                                    lVar3 = *(longlong *)(param_1 + 0x60);
                                                    if (lVar3 != 0) {
                                                      if (*(int *)(lVar3 + 0x18) == 0) {
code_r0x000180500462:
                    /* WARNING: Subroutine does not return */
                                                        FUN_18031dae0();
                                                      }
                                                      if (*(longlong *)(lVar3 + 0x20) != 0) {
                                                                                                                
                                                  ExposureUnnoticed2_ObjectUI_InGame_RingMenu_ShortcutItemView__Initialize__06001ad9
                                                            (*(longlong *)(lVar3 + 0x20),0,
                                                             *(undefined8 *)(param_1 + 0xe8),0);
                                                  lVar3 = *(longlong *)(param_1 + 0x60);
                                                  if (lVar3 != 0) {
                                                    if (*(uint *)(lVar3 + 0x18) < 2)
                                                    goto code_r0x000180500462;
                                                    if (*(longlong *)(lVar3 + 0x28) != 0) {
                                                                                                            
                                                  ExposureUnnoticed2_ObjectUI_InGame_RingMenu_ShortcutItemView__Initialize__06001ad9
                                                            (*(longlong *)(lVar3 + 0x28),1,
                                                             *(undefined8 *)(param_1 + 0xe8),0);
                                                  lVar3 = *(longlong *)(param_1 + 0x60);
                                                  if (lVar3 != 0) {
                                                    if (*(uint *)(lVar3 + 0x18) < 3)
                                                    goto code_r0x000180500462;
                                                    if (*(longlong *)(lVar3 + 0x30) != 0) {
                                                                                                            
                                                  ExposureUnnoticed2_ObjectUI_InGame_RingMenu_ShortcutItemView__Initialize__06001ad9
                                                            (*(longlong *)(lVar3 + 0x30),2,
                                                             *(undefined8 *)(param_1 + 0xe8),0);
                                                  lVar3 = *(longlong *)(param_1 + 0x60);
                                                  if (lVar3 != 0) {
                                                    if (*(uint *)(lVar3 + 0x18) < 4)
                                                    goto code_r0x000180500462;
                                                    if (*(longlong *)(lVar3 + 0x38) != 0) {
                                                                                                            
                                                  ExposureUnnoticed2_ObjectUI_InGame_RingMenu_ShortcutItemView__Initialize__06001ad9
                                                            (*(longlong *)(lVar3 + 0x38),3,
                                                             *(undefined8 *)(param_1 + 0xe8),0);
                                                  lVar3 = *(longlong *)(param_1 + 0x60);
                                                  if (lVar3 != 0) {
                                                    if (*(uint *)(lVar3 + 0x18) < 5)
                                                    goto code_r0x000180500462;
                                                    if (*(longlong *)(lVar3 + 0x40) != 0) {
                                                                                                            
                                                  ExposureUnnoticed2_ObjectUI_InGame_RingMenu_ShortcutItemView__Initialize__06001ad9
                                                            (*(longlong *)(lVar3 + 0x40),4,
                                                             *(undefined8 *)(param_1 + 0xe8),0);
                                                  lVar3 = *(longlong *)(param_1 + 0x60);
                                                  if (lVar3 != 0) {
                                                    if (*(uint *)(lVar3 + 0x18) < 6)
                                                    goto code_r0x000180500462;
                                                    if (*(longlong *)(lVar3 + 0x48) != 0) {
                                                                                                            
                                                  ExposureUnnoticed2_ObjectUI_InGame_RingMenu_ShortcutItemView__Initialize__06001ad9
                                                            (*(longlong *)(lVar3 + 0x48),5,
                                                             *(undefined8 *)(param_1 + 0xe8),0);
                                                  lVar3 = *(longlong *)(param_1 + 0x60);
                                                  if (lVar3 != 0) {
                                                    if (*(uint *)(lVar3 + 0x18) < 7)
                                                    goto code_r0x000180500462;
                                                    if (*(longlong *)(lVar3 + 0x50) != 0) {
                                                                                                            
                                                  ExposureUnnoticed2_ObjectUI_InGame_RingMenu_ShortcutItemView__Initialize__06001ad9
                                                            (*(longlong *)(lVar3 + 0x50),6,
                                                             *(undefined8 *)(param_1 + 0xe8),0);
                                                  lVar3 = *(longlong *)(param_1 + 0x60);
                                                  if (lVar3 != 0) {
                                                    if (*(uint *)(lVar3 + 0x18) < 8)
                                                    goto code_r0x000180500462;
                                                    if (*(longlong *)(lVar3 + 0x58) != 0) {
                                                                                                            
                                                  ExposureUnnoticed2_ObjectUI_InGame_RingMenu_ShortcutItemView__Initialize__06001ad9
                                                            (*(longlong *)(lVar3 + 0x58),7,
                                                             *(undefined8 *)(param_1 + 0xe8),0);
                                                  lVar3 = *(longlong *)
                                                           (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                           0x48);
                                                  if (lVar3 != 0) {
                                                    if (*(int *)(lVar3 + 0x50) != -1) {
                                                      lVar3 = *(longlong *)(param_1 + 0xe8);
                                                      if (lVar3 == 0) goto code_r0x000180500468;
                                                      uVar13 = *(uint *)(*(longlong *)
                                                                          (*(longlong *)
                                                                            (DAT_182d58398 + 0xb8) +
                                                                          0x48) + 0x50);
                                                      if (*(uint *)(lVar3 + 0x18) <= uVar13)
                                                      goto code_r0x000180500462;
                                                      *(undefined8 *)(param_1 + 0x88) =
                                                           *(undefined8 *)
                                                            (lVar3 + 0x20 +
                                                            (longlong)(int)uVar13 * 8);
                                                      FUN_18031d480(param_1 + 0x88);
                                                    }
                                                    lVar3 = *(longlong *)
                                                             (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                             0x48);
                                                    if (lVar3 != 0) {
                                                      if (*(int *)(lVar3 + 0x54) != -1) {
                                                        lVar3 = *(longlong *)(param_1 + 0xe8);
                                                        if (lVar3 == 0) goto code_r0x000180500468;
                                                        uVar13 = *(uint *)(*(longlong *)
                                                                            (*(longlong *)
                                                                              (DAT_182d58398 + 0xb8)
                                                                            + 0x48) + 0x54);
                                                        if (*(uint *)(lVar3 + 0x18) <= uVar13)
                                                        goto code_r0x000180500462;
                                                        *(undefined8 *)(param_1 + 0x90) =
                                                             *(undefined8 *)
                                                              (lVar3 + 0x20 +
                                                              (longlong)(int)uVar13 * 8);
                                                        FUN_18031d480(param_1 + 0x90);
                                                      }
                                                      lVar3 = *(longlong *)
                                                               (*(longlong *)(DAT_182d58398 + 0xb8)
                                                               + 0x48);
                                                      if (lVar3 != 0) {
                                                        if (*(int *)(lVar3 + 0x58) != -1) {
                                                          lVar3 = *(longlong *)(param_1 + 0xe8);
                                                          if (lVar3 == 0) goto code_r0x000180500468;
                                                          uVar13 = *(uint *)(*(longlong *)
                                                                              (*(longlong *)
                                                                                (DAT_182d58398 +
                                                                                0xb8) + 0x48) + 0x58
                                                                            );
                                                          if (*(uint *)(lVar3 + 0x18) <= uVar13)
                                                          goto code_r0x000180500462;
                                                          *(undefined8 *)(param_1 + 0x98) =
                                                               *(undefined8 *)
                                                                (lVar3 + 0x20 +
                                                                (longlong)(int)uVar13 * 8);
                                                          FUN_18031d480(param_1 + 0x98);
                                                        }
                                                        lVar3 = *(longlong *)
                                                                 (*(longlong *)
                                                                   (DAT_182d58398 + 0xb8) + 0x48);
                                                        if (lVar3 != 0) {
                                                          if (*(int *)(lVar3 + 0x5c) != -1) {
                                                            lVar3 = *(longlong *)(param_1 + 0xe8);
                                                            if (lVar3 == 0)
                                                            goto code_r0x000180500468;
                                                            uVar13 = *(uint *)(*(longlong *)
                                                                                (*(longlong *)
                                                                                  (DAT_182d58398 +
                                                                                  0xb8) + 0x48) +
                                                                              0x5c);
                                                            if (*(uint *)(lVar3 + 0x18) <= uVar13)
                                                            goto code_r0x000180500462;
                                                            *(undefined8 *)(param_1 + 0xa0) =
                                                                 *(undefined8 *)
                                                                  (lVar3 + 0x20 +
                                                                  (longlong)(int)uVar13 * 8);
                                                            FUN_18031d480(param_1 + 0xa0);
                                                          }
                                                          lVar3 = *(longlong *)
                                                                   (*(longlong *)
                                                                     (DAT_182d58398 + 0xb8) + 0x48);
                                                          if (lVar3 != 0) {
                                                            if (*(int *)(lVar3 + 0x60) != -1) {
                                                              lVar3 = *(longlong *)(param_1 + 0xe8);
                                                              if (lVar3 == 0)
                                                              goto code_r0x000180500468;
                                                              uVar13 = *(uint *)(*(longlong *)
                                                                                  (*(longlong *)
                                                                                    (DAT_182d58398 +
                                                                                    0xb8) + 0x48) +
                                                                                0x60);
                                                              if (*(uint *)(lVar3 + 0x18) <= uVar13)
                                                              goto code_r0x000180500462;
                                                              *(undefined8 *)(param_1 + 0xa8) =
                                                                   *(undefined8 *)
                                                                    (lVar3 + 0x20 +
                                                                    (longlong)(int)uVar13 * 8);
                                                              FUN_18031d480(param_1 + 0xa8);
                                                            }
                                                            lVar3 = *(longlong *)
                                                                     (*(longlong *)
                                                                       (DAT_182d58398 + 0xb8) + 0x48
                                                                     );
                                                            if (lVar3 != 0) {
                                                              if (*(int *)(lVar3 + 100) != -1) {
                                                                lVar3 = *(longlong *)
                                                                         (param_1 + 0xe8);
                                                                if (lVar3 == 0)
                                                                goto code_r0x000180500468;
                                                                uVar13 = *(uint *)(*(longlong *)
                                                                                    (*(longlong *)
                                                                                      (DAT_182d58398
                                                                                      + 0xb8) + 0x48
                                                                                    ) + 100);
                                                                if (*(uint *)(lVar3 + 0x18) <=
                                                                    uVar13)
                                                                goto code_r0x000180500462;
                                                                *(undefined8 *)(param_1 + 0xb0) =
                                                                     *(undefined8 *)
                                                                      (lVar3 + 0x20 +
                                                                      (longlong)(int)uVar13 * 8);
                                                                FUN_18031d480(param_1 + 0xb0);
                                                              }
                                                              lVar3 = *(longlong *)
                                                                       (*(longlong *)
                                                                         (DAT_182d58398 + 0xb8) +
                                                                       0x48);
                                                              if (lVar3 != 0) {
                                                                if (*(int *)(lVar3 + 0x68) != -1) {
                                                                  lVar3 = *(longlong *)
                                                                           (param_1 + 0xe8);
                                                                  if (lVar3 == 0)
                                                                  goto code_r0x000180500468;
                                                                  uVar13 = *(uint *)(*(longlong *)
                                                                                      (*(longlong *)
                                                                                        (
                                                  DAT_182d58398 + 0xb8) + 0x48) + 0x68);
                                                  if (*(uint *)(lVar3 + 0x18) <= uVar13)
                                                  goto code_r0x000180500462;
                                                  *(undefined8 *)(param_1 + 0xb8) =
                                                       *(undefined8 *)
                                                        (lVar3 + 0x20 + (longlong)(int)uVar13 * 8);
                                                  FUN_18031d480(param_1 + 0xb8);
                                                  }
                                                  lVar3 = *(longlong *)
                                                           (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                           0x48);
                                                  if (lVar3 != 0) {
                                                    if (*(int *)(lVar3 + 0x6c) != -1) {
                                                      lVar3 = *(longlong *)(param_1 + 0xe8);
                                                      if (lVar3 == 0) goto code_r0x000180500468;
                                                      uVar13 = *(uint *)(*(longlong *)
                                                                          (*(longlong *)
                                                                            (DAT_182d58398 + 0xb8) +
                                                                          0x48) + 0x6c);
                                                      if (*(uint *)(lVar3 + 0x18) <= uVar13)
                                                      goto code_r0x000180500462;
                                                      *(undefined8 *)(param_1 + 0xc0) =
                                                           *(undefined8 *)
                                                            (lVar3 + 0x20 +
                                                            (longlong)(int)uVar13 * 8);
                                                      FUN_18031d480(param_1 + 0xc0);
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
                                                  }
                                                }
                                              }
                                            }
code_r0x000180500468:
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
code_r0x00018050033a:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

