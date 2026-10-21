// Ghidra pseudocode; not original source or compilable C.
// ev_d5027f05ccb78c5fea613a11a65cdc2bcd9c9f726f4dd5a9db31bc2f23f7ebd8

void ExposureUnnoticed2_Scripts_Base_Scheduler__Update__0600174f(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  char cVar7;
  uint uVar8;
  bool bVar9;
  undefined8 uStack_a8;
  longlong *plStack_a0;
  undefined8 uStack_98;
  longlong lStack_90;
  longlong lStack_88;
  longlong lStack_80;
  longlong lStack_78;
  longlong lStack_70;
  longlong lStack_68;
  undefined8 uStack_60;
  undefined4 uStack_58;
  undefined4 uStack_54;
  longlong lStack_50;
  
  if (cRam0000000182eb7aa5 == '\0') {
    FUN_1802f2810(0x182d5f8d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f8c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f8d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f8b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f8b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f8a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f8a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f898);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f890);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f888);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f880);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f878);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f908);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f8f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f8e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f870);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f868);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f858);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f850);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f840);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f838);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f830);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f820);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f818);
    LOCK();
    UNLOCK();
    cRam0000000182eb7aa5 = '\x01';
  }
  lStack_90 = 0;
  lStack_88 = 0;
  lStack_80 = 0;
  lStack_78 = 0;
  lStack_70 = 0;
  lStack_68 = 0;
  lVar3 = *(longlong *)(param_1 + 0x28);
  if (lVar3 != 0) {
    *(int *)(lVar3 + 0x1c) = *(int *)(lVar3 + 0x1c) + 1;
    iVar2 = *(int *)(lVar3 + 0x18);
    *(undefined4 *)(lVar3 + 0x18) = 0;
    if (0 < iVar2) {
      FUN_181646f50(*(undefined8 *)(lVar3 + 0x10),0,iVar2,0);
    }
    uVar4 = *(undefined8 *)(param_1 + 0x20);
    uVar5 = *(undefined8 *)(param_1 + 0x30);
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    FUN_18099d9d0(uVar4,uVar5,uRam0000000182d5f880);
    lVar3 = *(longlong *)(param_1 + 0x30);
    if (lVar3 != 0) {
      if (DAT_182eb5d50 != 0) {
        uVar8 = (uint)((ulonglong)&uStack_a8 >> 0xc);
        lVar1 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
        do {
          uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
          LOCK();
          bVar9 = uVar6 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
          if (bVar9) {
            *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar6 | 1L << (uVar8 & 0x3f);
          }
          UNLOCK();
        } while (!bVar9);
      }
      uStack_54 = *(undefined4 *)(lVar3 + 0x1c);
      uStack_98 = 0;
      uStack_a8._0_4_ = (undefined4)lVar3;
      uStack_a8._4_4_ = (undefined4)((ulonglong)lVar3 >> 0x20);
      uStack_60._0_4_ = (undefined4)uStack_a8;
      uStack_60._4_4_ = uStack_a8._4_4_;
      uStack_58 = 0;
      lStack_50 = 0;
      uStack_a8 = 0;
      plStack_a0 = &uStack_60;
      while (cVar7 = FUN_180f72b70(&uStack_60,uRam0000000182d5f8b0), lVar3 = lStack_50,
            cVar7 != '\0') {
        if (lStack_50 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        cVar7 = DelayFrameModel__CountdownAndInvokeIfNeed__06001752(lStack_50,0);
        if (cVar7 != '\0') {
          if (*(longlong *)(param_1 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          FUN_1800068f0(*(longlong *)(param_1 + 0x28),lVar3);
        }
      }
      lVar3 = *(longlong *)(param_1 + 0x28);
      if (lVar3 != 0) {
        if (DAT_182eb5d50 != 0) {
          uVar8 = (uint)((ulonglong)&uStack_a8 >> 0xc);
          lVar1 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
          do {
            uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
            LOCK();
            bVar9 = uVar6 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
            if (bVar9) {
              *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar6 | 1L << (uVar8 & 0x3f);
            }
            UNLOCK();
          } while (!bVar9);
        }
        uStack_54 = *(undefined4 *)(lVar3 + 0x1c);
        uStack_98 = 0;
        uStack_a8._0_4_ = (undefined4)lVar3;
        uStack_a8._4_4_ = (undefined4)((ulonglong)lVar3 >> 0x20);
        uStack_60._0_4_ = (undefined4)uStack_a8;
        uStack_60._4_4_ = uStack_a8._4_4_;
        uStack_58 = 0;
        lStack_50 = 0;
        uStack_a8 = 0;
        plStack_a0 = &uStack_60;
        while (cVar7 = FUN_180f72b70(&uStack_60,uRam0000000182d5f8b0), cVar7 != '\0') {
          if (*(longlong *)(param_1 + 0x20) == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          FUN_181274e50(*(longlong *)(param_1 + 0x20),lStack_50,uRam0000000182d5f820);
        }
        lVar3 = *(longlong *)(param_1 + 0x40);
        if (lVar3 != 0) {
          *(int *)(lVar3 + 0x1c) = *(int *)(lVar3 + 0x1c) + 1;
          iVar2 = *(int *)(lVar3 + 0x18);
          *(undefined4 *)(lVar3 + 0x18) = 0;
          if (0 < iVar2) {
            FUN_181646f50(*(undefined8 *)(lVar3 + 0x10),0,iVar2,0);
          }
          uVar4 = *(undefined8 *)(param_1 + 0x38);
          uVar5 = *(undefined8 *)(param_1 + 0x48);
          if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
            FUN_18035c820();
          }
          FUN_18099d9d0(uVar4,uVar5,uRam0000000182d5f878);
          lVar3 = *(longlong *)(param_1 + 0x48);
          if (lVar3 != 0) {
            if (DAT_182eb5d50 != 0) {
              uVar8 = (uint)((ulonglong)&uStack_a8 >> 0xc);
              lVar1 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
              do {
                uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
                LOCK();
                bVar9 = uVar6 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
                if (bVar9) {
                  *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar6 | 1L << (uVar8 & 0x3f);
                }
                UNLOCK();
              } while (!bVar9);
            }
            uStack_98 = 0;
            lStack_88 = (ulonglong)*(uint *)(lVar3 + 0x1c) << 0x20;
            lStack_80 = 0;
            uStack_a8 = 0;
            plStack_a0 = &lStack_90;
            lStack_90 = lVar3;
            while (cVar7 = FUN_180f72b70(&lStack_90,uRam0000000182d5f8a8), lVar3 = lStack_80,
                  cVar7 != '\0') {
              if (lStack_80 == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              cVar7 = DelayTimeModel__InvokeIfNeed__06001754(lStack_80,0);
              if (cVar7 != '\0') {
                if (*(longlong *)(param_1 + 0x40) == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                FUN_180006950(*(longlong *)(param_1 + 0x40),lVar3);
              }
            }
            lVar3 = *(longlong *)(param_1 + 0x40);
            if (lVar3 != 0) {
              if (DAT_182eb5d50 != 0) {
                uVar8 = (uint)((ulonglong)&uStack_a8 >> 0xc);
                lVar1 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
                do {
                  uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
                  LOCK();
                  bVar9 = uVar6 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
                  if (bVar9) {
                    *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar6 | 1L << (uVar8 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar9);
              }
              uStack_98 = 0;
              lStack_88 = (ulonglong)*(uint *)(lVar3 + 0x1c) << 0x20;
              lStack_80 = 0;
              uStack_a8 = 0;
              plStack_a0 = &lStack_90;
              lStack_90 = lVar3;
              while (cVar7 = FUN_180f72b70(&lStack_90,uRam0000000182d5f8a8), cVar7 != '\0') {
                if (*(longlong *)(param_1 + 0x38) == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                FUN_181274e50(*(longlong *)(param_1 + 0x38),lStack_80,uRam0000000182d5f830);
              }
              lVar3 = *(longlong *)(param_1 + 0x58);
              if (lVar3 != 0) {
                *(int *)(lVar3 + 0x1c) = *(int *)(lVar3 + 0x1c) + 1;
                iVar2 = *(int *)(lVar3 + 0x18);
                *(undefined4 *)(lVar3 + 0x18) = 0;
                if (0 < iVar2) {
                  FUN_181646f50(*(undefined8 *)(lVar3 + 0x10),0,iVar2,0);
                }
                uVar4 = *(undefined8 *)(param_1 + 0x50);
                uVar5 = *(undefined8 *)(param_1 + 0x60);
                if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                FUN_18099d9d0(uVar4,uVar5,uRam0000000182d5f888);
                lVar3 = *(longlong *)(param_1 + 0x60);
                if (lVar3 != 0) {
                  if (DAT_182eb5d50 != 0) {
                    uVar8 = (uint)((ulonglong)&uStack_a8 >> 0xc);
                    lVar1 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
                    do {
                      uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
                      LOCK();
                      bVar9 = uVar6 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
                      if (bVar9) {
                        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar6 | 1L << (uVar8 & 0x3f);
                      }
                      UNLOCK();
                    } while (!bVar9);
                  }
                  uStack_98 = 0;
                  lStack_70 = (ulonglong)*(uint *)(lVar3 + 0x1c) << 0x20;
                  lStack_68 = 0;
                  uStack_a8 = 0;
                  plStack_a0 = &lStack_78;
                  lStack_78 = lVar3;
                  while (cVar7 = FUN_180f72b70(&lStack_78,uRam0000000182d5f8b8), lVar3 = lStack_68,
                        cVar7 != '\0') {
                    if (lStack_68 == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    cVar7 = DelayConditionModel__InvokeIfNeed__06001756(lStack_68,0);
                    if (cVar7 != '\0') {
                      if (*(longlong *)(param_1 + 0x58) == 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      FUN_1800069b0(*(longlong *)(param_1 + 0x58),lVar3);
                    }
                  }
                  lVar3 = *(longlong *)(param_1 + 0x58);
                  if (lVar3 != 0) {
                    if (DAT_182eb5d50 != 0) {
                      uVar8 = (uint)((ulonglong)&uStack_a8 >> 0xc);
                      lVar1 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
                      do {
                        uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
                        LOCK();
                        bVar9 = uVar6 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
                        if (bVar9) {
                          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar6 | 1L << (uVar8 & 0x3f);
                        }
                        UNLOCK();
                      } while (!bVar9);
                    }
                    uStack_98 = 0;
                    lStack_70 = (ulonglong)*(uint *)(lVar3 + 0x1c) << 0x20;
                    lStack_68 = 0;
                    uStack_a8 = 0;
                    plStack_a0 = &lStack_78;
                    lStack_78 = lVar3;
                    while( true ) {
                      cVar7 = FUN_180f72b70(&lStack_78,uRam0000000182d5f8b8);
                      if (cVar7 == '\0') {
                        return;
                      }
                      if (*(longlong *)(param_1 + 0x50) == 0) break;
                      FUN_181274e50(*(longlong *)(param_1 + 0x50),lStack_68,uRam0000000182d5f818);
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
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

