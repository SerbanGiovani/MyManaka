// Ghidra pseudocode; not original source or compilable C.
// ev_c6ee73cfdcb147d478444dd2324ebf5fa92b42ee236d1f358236cd95295b5212

void ExposureUnnoticed2_Scripts_InGame_StageController___Start_b__32_0__0600165e(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  bool bVar8;
  
  if (cRam0000000182eb7a34 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ff08);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a34 = '\x01';
  }
  lVar5 = *(longlong *)(param_1 + 0xc0);
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
  if (lVar5 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar5 + 0x10) != 0) {
      if (*(longlong *)(param_1 + 0xc0) == 0) goto code_r0x0001804a58d2;
      ExposureUnnoticed2_Scripts_InGame_StageRandomPositionManager__Initialize__06001661
                (*(longlong *)(param_1 + 0xc0),0);
    }
  }
  lVar5 = *(longlong *)(param_1 + 200);
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
  if (lVar5 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar5 + 0x10) != 0) {
      if (*(longlong *)(param_1 + 200) == 0) goto code_r0x0001804a58d2;
      ExposureUnnoticed2_Scripts_InGame_StageRandomPositionManager__Initialize__06001661
                (*(longlong *)(param_1 + 200),0);
    }
  }
  lVar5 = *(longlong *)(param_1 + 0xd0);
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
  if (lVar5 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar5 + 0x10) != 0) {
      lVar5 = *(longlong *)(param_1 + 0xd0);
      if (lVar5 == 0) goto code_r0x0001804a58d2;
      if (cRam0000000182eb79ee == '\0') {
        FUN_1802f2810(0x182d60318);
        LOCK();
        UNLOCK();
        cRam0000000182eb79ee = '\x01';
      }
      lVar6 = lRam0000000182d60318;
      if (*(longlong *)(lRam0000000182d60318 + 0x38) == 0) {
        FUN_1803204f0(lRam0000000182d60318);
      }
      uVar4 = FUN_1807366b0(lVar5,0,**(undefined8 **)(lVar6 + 0x38));
      bVar8 = DAT_182eb5d50 != 0;
      *(undefined8 *)(lVar5 + 0x20) = uVar4;
      if (bVar8) {
        uVar7 = (uint)(lVar5 + 0x20U >> 0xc);
        lVar5 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
          LOCK();
          bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
          if (bVar8) {
            *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar2 | 1L << (uVar7 & 0x3f);
          }
          UNLOCK();
        } while (!bVar8);
      }
    }
  }
  ExposureUnnoticed2_Scripts_InGame_StageController__UpdateReleaseFastTravel__06001659(param_1,0);
  lVar5 = **(longlong **)(DAT_182d53c48 + 0xb8);
  if (lVar5 != 0) {
    bVar8 = DAT_182eb5d50 != 0;
    *(longlong *)(lVar5 + 0x40) = param_1;
    if (bVar8) {
      uVar7 = (uint)(lVar5 + 0x40U >> 0xc);
      lVar5 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
        LOCK();
        bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
        if (bVar8) {
          *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar2 | 1L << (ulonglong)(uVar7 & 0x3f);
        }
        UNLOCK();
      } while (!bVar8);
    }
    if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
       (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar5 != 0)) {
      if (*(char *)(lVar5 + 0x12) == '\0') {
        if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d58080);
        }
        lVar5 = *(longlong *)(*(longlong *)(DAT_182d58080 + 0xb8) + 8);
        if (lVar5 == 0) goto code_r0x0001804a58d2;
        bVar8 = DAT_182eb5d50 != 0;
        *(longlong *)(lVar5 + 0x10) = param_1;
        if (bVar8) {
          uVar7 = (uint)(lVar5 + 0x10U >> 0xc);
          lVar5 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
          do {
            uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
            LOCK();
            bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
            if (bVar8) {
              *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar2 | 1L << (ulonglong)(uVar7 & 0x3f);
            }
            UNLOCK();
          } while (!bVar8);
        }
        uVar4 = *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 8);
        if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
          FUN_18035c820();
        }
        ExposureUnnoticed2_Scripts_Base_EventManager__Broadcast__06001716(uVar4,0);
      }
      if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
         (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar5 != 0)) {
        *(undefined1 *)(lVar5 + 0x12) = 0;
        if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
           ((lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar5 != 0 &&
            (lVar5 = *(longlong *)(lVar5 + 0xa8), lVar5 != 0)))) {
          bVar8 = DAT_182eb5d50 != 0;
          *(undefined8 *)(lVar5 + 0xb0) = *(undefined8 *)(param_1 + 0xb8);
          if (bVar8) {
            uVar7 = (uint)(lVar5 + 0xb0U >> 0xc);
            lVar5 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
            do {
              uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
              LOCK();
              bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
              if (bVar8) {
                *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar2 | 1L << (ulonglong)(uVar7 & 0x3f);
              }
              UNLOCK();
            } while (!bVar8);
          }
          if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
              (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar5 != 0)) &&
             (lVar5 = *(longlong *)(lVar5 + 0xa8), lVar5 != 0)) {
            AkilliMum_Standard_Mirror_MirrorManager__InitializeMirror__060008f5(lVar5,0);
            lVar5 = *(longlong *)(param_1 + 0x38);
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
            if (lVar5 != 0) {
              if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              if (*(longlong *)(lVar5 + 0x10) != 0) {
                if (*(longlong *)(param_1 + 0x38) == 0) goto code_r0x0001804a58d2;
                ExposureUnnoticed2_Scripts_Sound_BgmController__Initialize__060013de
                          (*(longlong *)(param_1 + 0x38),0);
              }
            }
            uVar4 = FUN_1802c43a0(DAT_182d58368);
            FUN_1814df680(uVar4,param_1,uRam0000000182d5ff08,0);
            if (DAT_182eb7aa1 == '\0') {
              FUN_1802f2810(&DAT_182d5f910,1,0);
              LOCK();
              UNLOCK();
              FUN_1802f2810(&DAT_182d5f908);
              LOCK();
              UNLOCK();
              DAT_182eb7aa1 = '\x01';
            }
            lVar5 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
            if (lVar5 != 0) {
              lVar5 = *(longlong *)(lVar5 + 0x20);
              lVar6 = FUN_1802c43a0(DAT_182d5f910);
              bVar8 = DAT_182eb5d50 != 0;
              *(undefined8 *)(lVar6 + 0x10) = uVar4;
              if (bVar8) {
                uVar7 = (uint)(lVar6 + 0x10U >> 0xc);
                puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
                do {
                  uVar3 = *puVar1;
                  LOCK();
                  uVar2 = *puVar1;
                  if (uVar3 == uVar2) {
                    *puVar1 = uVar3 | 1L << (uVar7 & 0x3f);
                  }
                  UNLOCK();
                } while (uVar3 != uVar2);
              }
              *(undefined4 *)(lVar6 + 0x18) = 1;
              if (lVar5 != 0) {
                FUN_1800068f0(lVar5,lVar6);
                return;
              }
            }
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
        }
      }
    }
  }
code_r0x0001804a58d2:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

