// Ghidra pseudocode; not original source or compilable C.
// ev_b15f28c2008724e8ec6b73dce0b6a575269d72b8c02a4329ac9237b5f58a7464

ulonglong ExposureUnnoticed2_Scripts_UI_TitleSceneView__OnClickContinue__060013a9(longlong param_1)

{
  ulonglong *puVar1;
  longlong lVar2;
  char cVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  undefined *puVar11;
  longlong *plVar12;
  longlong *plVar13;
  undefined8 uVar14;
  int iVar16;
  undefined8 unaff_RDI;
  uint uVar17;
  int iVar18;
  bool bVar19;
  ulonglong uVar15;
  
  if (cRam0000000182eb78b5 == '\0') {
    FUN_1802f2810(0x182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bf30);
    LOCK();
    UNLOCK();
    cRam0000000182eb78b5 = '\x01';
  }
  *(undefined1 *)(param_1 + 0xb0) = 1;
  uVar6 = FUN_1802c43a0(uRam0000000182d58368);
  FUN_1814df680(uVar6,param_1,uRam0000000182d5bf30,0);
  lVar7 = *(longlong *)(param_1 + 0x38);
  if (cRam0000000182eb7c13 == '\0') {
    FUN_1802f2810(0x182d58238,lVar7,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63648);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63640);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c13 = '\x01';
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec12f3 == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec12f3 = '\x01';
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec129b == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec129b = '\x01';
  }
  if (lVar7 == 0) {
DAT_1804e587d:
    if (*(int *)(lRam0000000182d58380 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d58380);
    }
    if ((**(longlong **)(lRam0000000182d58238 + 0xb8) == 0) ||
       (**(longlong **)(lRam0000000182d58380 + 0xb8) == 0)) goto code_r0x0001804e5a2a;
    plVar13 = (longlong *)
              FUN_180457a40(**(longlong **)(lRam0000000182d58380 + 0xb8),
                            *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x120),1,
                            0);
    plVar12 = (longlong *)0x0;
    if (plVar13 != (longlong *)0x0) {
      if ((*(byte *)(*plVar13 + 0x130) < *(byte *)(lRam0000000182d63640 + 0x130)) ||
         (bVar19 = true,
         *(longlong *)
          (*(longlong *)(*plVar13 + 200) + -8 +
          (ulonglong)*(byte *)(lRam0000000182d63640 + 0x130) * 8) != lRam0000000182d63640)) {
        bVar19 = false;
      }
      if (bVar19) {
        plVar12 = plVar13;
      }
    }
  }
  else {
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar7 + 0x10) == 0) goto DAT_1804e587d;
    if (**(longlong **)(lRam0000000182d58238 + 0xb8) == 0) goto code_r0x0001804e5a2a;
    uVar14 = *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x120);
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    plVar12 = (longlong *)FUN_1809f1050(uVar14,lVar7,uRam0000000182d61b38);
  }
  if (plVar12 != (longlong *)0x0) {
    uVar14 = FUN_180735980(plVar12,uRam0000000182d63648);
    **(undefined8 **)(lRam0000000182d63640 + 0xb8) = uVar14;
    if (DAT_182eb5d50 != 0) {
      uVar17 = (uint)(*(ulonglong *)(lRam0000000182d63640 + 0xb8) >> 0xc);
      lVar7 = (ulonglong)((uVar17 & 0x1fffff) >> 6) * 8;
      do {
        uVar15 = *(ulonglong *)(&DAT_182f0c920 + lVar7);
        LOCK();
        bVar19 = uVar15 == *(ulonglong *)(&DAT_182f0c920 + lVar7);
        if (bVar19) {
          *(ulonglong *)(&DAT_182f0c920 + lVar7) = uVar15 | 1L << (uVar17 & 0x3f);
        }
        UNLOCK();
      } while (!bVar19);
    }
    iVar18 = DAT_182eb5d50;
    lVar7 = **(longlong **)(lRam0000000182d63640 + 0xb8);
    if (lVar7 != 0) {
      *(undefined8 *)(lVar7 + 0x30) = uVar6;
      if (iVar18 != 0) {
        uVar17 = (uint)(lVar7 + 0x30U >> 0xc);
        lVar8 = (ulonglong)((uVar17 & 0x1fffff) >> 6) * 8;
        do {
          uVar15 = *(ulonglong *)(&DAT_182f0c920 + lVar8);
          LOCK();
          bVar19 = uVar15 == *(ulonglong *)(&DAT_182f0c920 + lVar8);
          if (bVar19) {
            *(ulonglong *)(&DAT_182f0c920 + lVar8) = uVar15 | 1L << (uVar17 & 0x3f);
          }
          UNLOCK();
        } while (!bVar19);
      }
      if (cRam0000000182eb7c11 == '\0') {
        FUN_1802f2810(0x182d636d0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d58368);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d58288);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d636c8);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d636c0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d54d90);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d53aa8);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d63658);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d63650);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5bfa0);
        LOCK();
        UNLOCK();
        cRam0000000182eb7c11 = '\x01';
      }
      uVar6 = *(undefined8 *)(lVar7 + 0x60);
      if (*(int *)(lRam0000000182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      FUN_1804b2c70(uVar6,0);
      if (*(int *)(lRam0000000182d5bfa0 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d5bfa0);
      }
      iVar18 = 1;
      if (**(char **)(lRam0000000182d5bfa0 + 0xb8) == '\0') {
        iVar18 = 0x14;
      }
      iVar16 = 0;
      do {
        uVar6 = *(undefined8 *)(lVar7 + 0x58);
        uVar14 = *(undefined8 *)(lVar7 + 0x60);
        if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar8 = FUN_1809f1050(uVar6,uVar14,uRam0000000182d54d90);
        if (lVar8 == 0) goto code_r0x0001804e567d;
        lVar9 = FUN_1809a08f0(lVar8,uRam0000000182d636c8);
        lVar10 = FUN_1802c43a0(uRam0000000182d636d0);
        lVar8 = lRam0000000182d63658;
        bVar19 = DAT_182eb5d50 != 0;
        *(undefined8 *)(lVar10 + 0x10) = *(undefined8 *)(lRam0000000182d63658 + 8);
        *(longlong *)(lVar10 + 0x28) = lVar8;
        *(longlong *)(lVar10 + 0x20) = lVar7;
        if (bVar19) {
          uVar17 = (uint)(lVar10 + 0x20U >> 0xc);
          lVar2 = (ulonglong)((uVar17 & 0x1fffff) >> 6) * 8;
          do {
            uVar15 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
            LOCK();
            bVar19 = uVar15 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
            if (bVar19) {
              *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar15 | 1L << (uVar17 & 0x3f);
            }
            UNLOCK();
          } while (!bVar19);
        }
        cVar3 = *(char *)(lVar8 + 0x52);
        *(longlong *)(lVar10 + 0x40) = lVar10;
        if (((*(byte *)(lVar8 + 0x4c) & 0x10) == 0) || (cVar3 != '\x02')) {
          *(undefined8 *)(lVar10 + 0x40) = *(undefined8 *)(lVar10 + 0x20);
          puVar11 = *(undefined **)(lVar10 + 0x10);
        }
        else {
          puVar11 = &UNK_18006eea0;
        }
        *(undefined **)(lVar10 + 0x18) = puVar11;
        *(code **)(lVar10 + 0x38) = FUN_18007bc70;
        if (lVar9 == 0) goto code_r0x0001804e567d;
        FUN_1804e5d00(lVar9,3,lVar10,iVar16,1,0);
        lVar10 = lRam0000000182d636c0;
        lVar8 = *(longlong *)(lVar7 + 0x80);
        if (lVar8 == 0) goto code_r0x0001804e567d;
        *(int *)(lVar8 + 0x1c) = *(int *)(lVar8 + 0x1c) + 1;
        lVar2 = *(longlong *)(lVar8 + 0x10);
        if (lVar2 == 0) goto code_r0x0001804e567d;
        uVar17 = *(uint *)(lVar8 + 0x18);
        if (uVar17 < *(uint *)(lVar2 + 0x18)) {
          *(uint *)(lVar8 + 0x18) = uVar17 + 1;
          FUN_180002cd0(lVar2,(longlong)(int)uVar17,lVar9);
        }
        else {
          FUN_1812741c0(lVar8,lVar9,
                        *(undefined8 *)(*(longlong *)(*(longlong *)(lVar10 + 0x20) + 0xc0) + 0x70));
        }
        iVar16 = iVar16 + 1;
      } while (iVar16 < iVar18);
      if (*(longlong *)(lVar7 + 0x68) != 0) {
        FUN_18057d140(*(longlong *)(lVar7 + 0x68),0,0,0);
        lVar9 = FUN_1802c43a0(uRam0000000182d58368);
        lVar8 = lRam0000000182d63650;
        bVar19 = DAT_182eb5d50 != 0;
        *(undefined8 *)(lVar9 + 0x10) = *(undefined8 *)(lRam0000000182d63650 + 8);
        *(longlong *)(lVar9 + 0x28) = lVar8;
        *(longlong *)(lVar9 + 0x20) = lVar7;
        if (bVar19) {
          uVar17 = (uint)(lVar9 + 0x20U >> 0xc);
          lVar7 = (ulonglong)((uVar17 & 0x1fffff) >> 6) * 8;
          do {
            uVar15 = *(ulonglong *)(&DAT_182f0c920 + lVar7);
            LOCK();
            bVar19 = uVar15 == *(ulonglong *)(&DAT_182f0c920 + lVar7);
            if (bVar19) {
              *(ulonglong *)(&DAT_182f0c920 + lVar7) = uVar15 | 1L << (uVar17 & 0x3f);
            }
            UNLOCK();
          } while (!bVar19);
        }
        cVar3 = *(char *)(lVar8 + 0x52);
        *(longlong *)(lVar9 + 0x40) = lVar9;
        if (((*(byte *)(lVar8 + 0x4c) & 0x10) == 0) || (cVar3 != '\0')) {
          *(undefined8 *)(lVar9 + 0x40) = *(undefined8 *)(lVar9 + 0x20);
          puVar11 = *(undefined **)(lVar9 + 0x10);
        }
        else {
          puVar11 = &UNK_1800c7840;
        }
        *(undefined **)(lVar9 + 0x18) = puVar11;
        *(code **)(lVar9 + 0x38) = FUN_1801e91e0;
        if (cRam0000000182eb7aa1 == '\0') {
          FUN_1802f2810(0x182d5f910,1,0,lVar9,unaff_RDI);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d5f908);
          LOCK();
          UNLOCK();
          cRam0000000182eb7aa1 = '\x01';
        }
        lVar7 = FUN_1804b3a30(0);
        if (lVar7 != 0) {
          lVar7 = *(longlong *)(lVar7 + 0x20);
          lVar8 = FUN_1802c43a0(uRam0000000182d5f910);
          bVar19 = DAT_182eb5d50 != 0;
          *(longlong *)(lVar8 + 0x10) = lVar9;
          if (bVar19) {
            uVar17 = (uint)(lVar8 + 0x10U >> 0xc);
            puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar17 & 0x1fffff) >> 6) * 8);
            do {
              uVar4 = *puVar1;
              LOCK();
              uVar15 = *puVar1;
              if (uVar4 == uVar15) {
                *puVar1 = uVar4 | 1L << (uVar17 & 0x3f);
              }
              UNLOCK();
            } while (uVar4 != uVar15);
          }
          *(undefined4 *)(lVar8 + 0x18) = 1;
          lVar9 = lRam0000000182d5f908;
          if (lVar7 != 0) {
            lVar10 = *(longlong *)(lVar7 + 0x10);
            *(int *)(lVar7 + 0x1c) = *(int *)(lVar7 + 0x1c) + 1;
            if (lVar10 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            uVar17 = *(uint *)(lVar7 + 0x18);
            if (uVar17 < *(uint *)(lVar10 + 0x18)) {
              uVar5 = uVar17 + 1;
              *(uint *)(lVar7 + 0x18) = uVar5;
            }
            else {
              uVar17 = *(uint *)(lVar7 + 0x18);
              FUN_18010dcd0(lVar7,uVar17 + 1,
                            *(undefined8 *)
                             (*(longlong *)
                               (*(longlong *)
                                 (*(longlong *)
                                   (*(longlong *)(*(longlong *)(lVar9 + 0x20) + 0xc0) + 0x70) + 0x20
                                 ) + 0xc0) + 0x78),lVar10,unaff_RDI);
              lVar10 = *(longlong *)(lVar7 + 0x10);
              uVar5 = uVar17 + 1;
              *(uint *)(lVar7 + 0x18) = uVar5;
              if (lVar10 == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
            }
            uVar15 = (ulonglong)uVar5;
            if (*(uint *)(lVar10 + 0x18) <= uVar17) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dae0();
            }
            bVar19 = DAT_182eb5d50 != 0;
            *(longlong *)(lVar10 + 0x20 + (longlong)(int)uVar17 * 8) = lVar8;
            if (bVar19) {
              uVar17 = (uint)((ulonglong)(lVar10 + ((longlong)(int)uVar17 + 4) * 8) >> 0xc);
              puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar17 & 0x1fffff) >> 6) * 8);
              do {
                uVar4 = *puVar1;
                LOCK();
                uVar15 = *puVar1;
                bVar19 = uVar4 == uVar15;
                if (bVar19) {
                  *puVar1 = uVar4 | 1L << (uVar17 & 0x3f);
                  uVar15 = uVar4;
                }
                UNLOCK();
              } while (!bVar19);
            }
            return uVar15;
          }
        }
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
code_r0x0001804e567d:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
code_r0x0001804e5a2a:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

