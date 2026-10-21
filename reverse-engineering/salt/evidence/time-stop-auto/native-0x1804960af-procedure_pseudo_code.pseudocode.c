// Ghidra pseudocode; not original source or compilable C.
// ev_dfe8ad25ef3ffcccba678472a094b40f94c7a7c0d8b11799eda7c764e105288b

void native_only_1804960af__00000000(void)

{
  ulonglong uVar1;
  undefined4 *puVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  code *in_RAX;
  code *pcVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  longlong unaff_RDI;
  bool bVar13;
  undefined4 extraout_XMM0_Da;
  undefined4 extraout_XMM0_Da_00;
  undefined4 uVar14;
  undefined4 uVar15;
  ulonglong in_stack_00000020;
  undefined8 in_stack_00000040;
  undefined4 in_stack_00000048;
  undefined4 uStack0000000000000050;
  undefined4 uStack0000000000000054;
  undefined4 uStack0000000000000058;
  undefined4 uStack000000000000005c;
  undefined4 in_stack_00000060;
  undefined4 in_stack_00000068;
  
  (*in_RAX)();
  *(undefined1 *)(*(longlong *)(DAT_182d53c48 + 0xb8) + 8) = 1;
  **(longlong **)(DAT_182d53c48 + 0xb8) = unaff_RDI;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(ulonglong *)(DAT_182d53c48 + 0xb8) >> 0xc);
    uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
      LOCK();
      bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
      if (bVar13) {
        *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar13);
  }
  if (**(char **)(DAT_182d5e268 + 0xb8) == '\0') {
    ExposureUnnoticed2_Scripts_InGame_SaveManager__Load__06001602(5,0,0);
  }
  lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
  if (lVar8 != 0) {
    uVar15 = *(undefined4 *)(lVar8 + 0x90);
    if (*(int *)(DAT_182d53a48 + 0xe0) == 0) {
      FUN_18035c820();
    }
    pcVar6 = DAT_182ebf9e0;
    if ((DAT_182ebf9e0 == (code *)0x0) &&
       (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Application::set_targetFrameRate(System.Int32)")
       , pcVar6 == (code *)0x0)) {
      uVar7 = FUN_1802ced60("UnityEngine.Application::set_targetFrameRate(System.Int32)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar7,0);
    }
    DAT_182ebf9e0 = pcVar6;
    (*DAT_182ebf9e0)(uVar15);
    if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar7 = FUN_1802c43a0(DAT_182d5d6b0);
    bVar13 = DAT_182eb5d50 != 0;
    *(undefined8 *)(unaff_RDI + 0x60) = uVar7;
    if (bVar13) {
      uVar5 = (uint)(unaff_RDI + 0x60U >> 0xc);
      uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
        LOCK();
        bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
        if (bVar13) {
          *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
        }
        UNLOCK();
      } while (!bVar13);
    }
    lVar8 = FUN_1802c43a0(DAT_182d5bcb8);
    if (DAT_182eb796c == '\0') {
      FUN_1802f2810(&DAT_182d5dfe0);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d5dfd8);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d5dfd0);
      LOCK();
      UNLOCK();
      DAT_182eb796c = '\x01';
    }
    uVar7 = FUN_1802c43a0(DAT_182d5dfd8);
    FUN_180e686d0(uVar7,DAT_182d5dfe0);
    bVar13 = DAT_182eb5d50 != 0;
    *(undefined8 *)(lVar8 + 0x10) = uVar7;
    if (bVar13) {
      uVar5 = (uint)(lVar8 + 0x10U >> 0xc);
      uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
        LOCK();
        bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
        if (bVar13) {
          *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
        }
        UNLOCK();
      } while (!bVar13);
    }
    lVar9 = FUN_1802c36c0(DAT_182d5dfd0,2);
    if (lVar9 != 0) {
      if (*(uint *)(lVar9 + 0x18) < 2) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined4 *)(lVar9 + 0x24) = 1;
      *(longlong *)(lVar8 + 0x18) = lVar9;
      if (bVar13) {
        uVar5 = (uint)(lVar8 + 0x18U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      FUN_180498e50(lVar8);
      ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__ActiveDroppedItemIfNeed__0600150e
                (lVar8,0);
      bVar13 = DAT_182eb5d50 != 0;
      *(longlong *)(unaff_RDI + 0x20) = lVar8;
      if (bVar13) {
        uVar5 = (uint)(unaff_RDI + 0x20U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      uVar7 = FUN_1802c43a0(DAT_182d5d6d8);
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined8 *)(unaff_RDI + 0x80) = uVar7;
      if (bVar13) {
        uVar5 = (uint)(unaff_RDI + 0x80U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      uVar7 = FUN_1802c43a0(DAT_182d5d6e8);
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined8 *)(unaff_RDI + 0x68) = uVar7;
      if (bVar13) {
        uVar5 = (uint)(unaff_RDI + 0x68U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      uVar7 = FUN_1802c43a0(DAT_182d5d6a0);
      ExposureUnnoticed2_Scripts_InGame_TemporaryInGameState___ctor__0600167f(uVar7,0);
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined8 *)(unaff_RDI + 0x30) = uVar7;
      if (bVar13) {
        uVar5 = (uint)(unaff_RDI + 0x30U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      uVar7 = FUN_1802c43a0(DAT_182d5d6c8);
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined8 *)(unaff_RDI + 0x88) = uVar7;
      if (bVar13) {
        uVar5 = (uint)(unaff_RDI + 0x88U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      uVar7 = FUN_1802c43a0(DAT_182d5ab80);
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined8 *)(unaff_RDI + 0x90) = uVar7;
      if (bVar13) {
        uVar5 = (uint)(unaff_RDI + 0x90U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      lVar8 = FUN_1802c43a0(DAT_182d5e190);
      if (DAT_182eb7927 == '\0') {
        FUN_1802f2810(&DAT_182d5e140);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d5e138);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d5e1b0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d5e1a8);
        LOCK();
        UNLOCK();
        DAT_182eb7927 = '\x01';
      }
      uVar7 = FUN_1802c43a0(DAT_182d5e1a8);
      FUN_1811cf4f0(uVar7,DAT_182d5e1b0);
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined8 *)(lVar8 + 0x10) = uVar7;
      if (bVar13) {
        uVar5 = (uint)(lVar8 + 0x10U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      uVar7 = FUN_1802c43a0(DAT_182d5e138);
      FUN_180e686d0(uVar7,DAT_182d5e140);
      iVar4 = DAT_182eb5d50;
      *(undefined8 *)(lVar8 + 0x18) = uVar7;
      if (iVar4 != 0) {
        uVar5 = (uint)(lVar8 + 0x18U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
          iVar4 = DAT_182eb5d50;
        } while (!bVar13);
      }
      *(longlong *)(unaff_RDI + 0x38) = lVar8;
      if (iVar4 != 0) {
        uVar5 = (uint)(unaff_RDI + 0x38U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      lVar8 = FUN_1802c43a0(DAT_182d5a8f0);
      if (DAT_182eb7a53 == '\0') {
        FUN_1802f2810(&DAT_182d583b8);
        LOCK();
        UNLOCK();
        DAT_182eb7a53 = '\x01';
      }
      uVar7 = FUN_1802c43a0(DAT_182d583b8);
      ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
                (uVar7,0x3f000000,0x3f800000,0,in_stack_00000020 & 0xffffffffffffff00);
      iVar4 = DAT_182eb5d50;
      *(undefined8 *)(lVar8 + 0x10) = uVar7;
      if (iVar4 != 0) {
        uVar5 = (uint)(lVar8 + 0x10U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
          iVar4 = DAT_182eb5d50;
        } while (!bVar13);
      }
      *(longlong *)(unaff_RDI + 0x48) = lVar8;
      if (iVar4 != 0) {
        uVar5 = (uint)(unaff_RDI + 0x48U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      lVar8 = FUN_1802c43a0(DAT_182d5e258);
      if (DAT_182eb7969 == '\0') {
        FUN_1802f2810(&DAT_182d5dff0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d5dfe8);
        LOCK();
        UNLOCK();
        DAT_182eb7969 = '\x01';
      }
      uVar7 = FUN_1802c43a0(DAT_182d5dfe8);
      FUN_180e2cdf0(uVar7,DAT_182d5dff0);
      iVar4 = DAT_182eb5d50;
      *(undefined8 *)(lVar8 + 0x10) = uVar7;
      if (iVar4 != 0) {
        uVar5 = (uint)(lVar8 + 0x10U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
          iVar4 = DAT_182eb5d50;
        } while (!bVar13);
      }
      *(longlong *)(unaff_RDI + 0x50) = lVar8;
      if (iVar4 != 0) {
        uVar5 = (uint)(unaff_RDI + 0x50U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      lVar8 = FUN_1802c43a0(DAT_182d5e260);
      if (DAT_182eb79f7 == '\0') {
        FUN_1802f2810(&DAT_182d5e1b0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d5e1a8);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d60288);
        LOCK();
        UNLOCK();
        DAT_182eb79f7 = '\x01';
      }
      uVar7 = FUN_1802c43a0(DAT_182d5e1a8);
      FUN_1811cf4f0(uVar7,DAT_182d5e1b0);
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined8 *)(lVar8 + 0x18) = uVar7;
      if (bVar13) {
        uVar5 = (uint)(lVar8 + 0x18U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      uVar7 = FUN_1802c43a0(DAT_182d60288);
      *(undefined8 *)(lVar8 + 0x28) = uVar7;
      if (DAT_182eb5d50 != 0) {
        uVar5 = (uint)(lVar8 + 0x28U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      iVar4 = DAT_182eb5d50;
      *(longlong *)(unaff_RDI + 0x58) = lVar8;
      if (iVar4 != 0) {
        uVar5 = (uint)(unaff_RDI + 0x58U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      lVar8 = FUN_1802c43a0(DAT_182d5d6b8);
      if (DAT_182eb8224 == '\0') {
        FUN_1802f2810(&DAT_182d6c298);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d6c290);
        LOCK();
        UNLOCK();
        DAT_182eb8224 = '\x01';
      }
      uVar7 = FUN_1802c43a0(DAT_182d6c290);
      FUN_1811cf4f0(uVar7,DAT_182d6c298);
      iVar4 = DAT_182eb5d50;
      *(undefined8 *)(lVar8 + 0x10) = uVar7;
      if (iVar4 != 0) {
        uVar5 = (uint)(lVar8 + 0x10U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
          iVar4 = DAT_182eb5d50;
        } while (!bVar13);
      }
      *(longlong *)(unaff_RDI + 0x98) = lVar8;
      if (iVar4 != 0) {
        uVar5 = (uint)(unaff_RDI + 0x98U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      uVar7 = FUN_1802c43a0(DAT_182d5d6a8);
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined8 *)(unaff_RDI + 0xa0) = uVar7;
      if (bVar13) {
        uVar5 = (uint)(unaff_RDI + 0xa0U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      uVar7 = FUN_180735660(extraout_XMM0_Da,DAT_182d5d700);
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined8 *)(unaff_RDI + 0x28) = uVar7;
      if (bVar13) {
        uVar5 = (uint)(unaff_RDI + 0x28U >> 0xc);
        uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          LOCK();
          bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      lVar8 = *(longlong *)(unaff_RDI + 0x28);
      if (lVar8 != 0) {
        if (DAT_182eb79e2 == '\0') {
          FUN_1802f2810(&DAT_182d60358);
          LOCK();
          UNLOCK();
          DAT_182eb79e2 = '\x01';
        }
        if (*(longlong *)(lVar8 + 0x38) != 0) {
          uVar7 = FUN_180735660(*(longlong *)(lVar8 + 0x38),DAT_182d60358);
          bVar13 = DAT_182eb5d50 != 0;
          *(undefined8 *)(lVar8 + 0xa8) = uVar7;
          if (bVar13) {
            uVar5 = (uint)(lVar8 + 0xa8U >> 0xc);
            uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
            do {
              uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
              LOCK();
              bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
              if (bVar13) {
                *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
              }
              UNLOCK();
            } while (!bVar13);
          }
          lVar8 = *(longlong *)(unaff_RDI + 0x28);
          if (**(longlong **)(DAT_182d58238 + 0xb8) != 0) {
            uVar7 = *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x348);
            pcVar6 = DAT_182ec1080;
            if ((DAT_182ec1080 == (code *)0x0) &&
               (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
               pcVar6 == (code *)0x0)) {
              uVar7 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar7,0);
            }
            DAT_182ec1080 = pcVar6;
            uVar10 = (*DAT_182ec1080)();
            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            lVar9 = FUN_1809f1050(uVar7,uVar10,DAT_182d54d90);
            if ((lVar9 != 0) && (uVar7 = FUN_1809a08f0(lVar9,DAT_182d5abb8), lVar8 != 0)) {
              bVar13 = DAT_182eb5d50 != 0;
              *(undefined8 *)(lVar8 + 0x30) = uVar7;
              if (bVar13) {
                uVar5 = (uint)(lVar8 + 0x30U >> 0xc);
                uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
                do {
                  uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                  LOCK();
                  bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                  if (bVar13) {
                    *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar13);
              }
              uVar7 = FUN_180735660(extraout_XMM0_Da_00,DAT_182d5d710);
              bVar13 = DAT_182eb5d50 != 0;
              *(undefined8 *)(unaff_RDI + 0x78) = uVar7;
              if (bVar13) {
                uVar5 = (uint)(unaff_RDI + 0x78U >> 0xc);
                uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
                do {
                  uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                  LOCK();
                  bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                  if (bVar13) {
                    *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar13);
              }
              if ((*(longlong *)(unaff_RDI + 0x78) != 0) &&
                 (ExposureUnnoticed2_Scripts_InGame_EventMethodManager__Initialize__06001515
                            (*(longlong *)(unaff_RDI + 0x78),*(undefined8 *)(unaff_RDI + 0x28),0),
                 *(longlong *)(unaff_RDI + 0x48) != 0)) {
                FUN_1804c20d0();
                lVar8 = *(longlong *)(unaff_RDI + 0x90);
                if (lVar8 != 0) {
                  if (DAT_182eb7ab9 == '\0') {
                    FUN_1802f2810(&DAT_182d5abb0);
                    LOCK();
                    UNLOCK();
                    FUN_1802f2810(&DAT_182d5aba8);
                    LOCK();
                    UNLOCK();
                    FUN_1802f2810(&DAT_182d583a0);
                    LOCK();
                    UNLOCK();
                    FUN_1802f2810(&DAT_182d5f610);
                    LOCK();
                    UNLOCK();
                    DAT_182eb7ab9 = '\x01';
                  }
                  uVar7 = FUN_1802c43a0(DAT_182d5abb0);
                  FUN_180665bb0(uVar7,lVar8,DAT_182d5f610,0);
                  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  FUN_180993250(uVar7,1,DAT_182d5aba8);
                  if (*(longlong *)(unaff_RDI + 0x38) != 0) {
                    ExposureUnnoticed2_Scripts_Mission_MissionManager__Initialize__06001466
                              (*(longlong *)(unaff_RDI + 0x38),0);
                    if (*(longlong *)(unaff_RDI + 0x88) != 0) {
                      ExposureUnnoticed2_Scripts_InGame_InGameEventListener__Initialize__0600156e
                                (*(longlong *)(unaff_RDI + 0x88),*(undefined8 *)(unaff_RDI + 0x68),0
                                );
                      lVar8 = *(longlong *)(unaff_RDI + 0x68);
                      if (lVar8 != 0) {
                        *(undefined8 *)(lVar8 + 0x10) = *(undefined8 *)(unaff_RDI + 0x28);
                        if (DAT_182eb5d50 != 0) {
                          uVar5 = (uint)(lVar8 + 0x10U >> 0xc);
                          uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
                          do {
                            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                            LOCK();
                            bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                            if (bVar13) {
                              *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) =
                                   uVar1 | 1L << (uVar5 & 0x3f);
                            }
                            UNLOCK();
                          } while (!bVar13);
                        }
                        iVar4 = DAT_182eb5d50;
                        *(longlong *)(lVar8 + 0x18) = unaff_RDI;
                        if (iVar4 != 0) {
                          uVar5 = (uint)(lVar8 + 0x18U >> 0xc);
                          uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
                          do {
                            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                            LOCK();
                            bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                            if (bVar13) {
                              *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) =
                                   uVar1 | 1L << (uVar5 & 0x3f);
                            }
                            UNLOCK();
                          } while (!bVar13);
                        }
                        if (((*(longlong *)(unaff_RDI + 0x28) != 0) &&
                            (lVar8 = *(longlong *)(*(longlong *)(unaff_RDI + 0x28) + 0x28),
                            lVar8 != 0)) && (lVar8 = *(longlong *)(lVar8 + 0x68), lVar8 != 0)) {
                          if (DAT_182eb7ce5 == '\0') {
                            FUN_1802f2810(&DAT_182d58288);
                            LOCK();
                            UNLOCK();
                            FUN_1802f2810(&DAT_182d647e0);
                            LOCK();
                            UNLOCK();
                            DAT_182eb7ce5 = '\x01';
                          }
                          lVar9 = *(longlong *)(lVar8 + 0x48);
                          if (lVar9 != 0) {
                            pcVar6 = DAT_182ec1080;
                            if ((DAT_182ec1080 == (code *)0x0) &&
                               (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_transform()"),
                               pcVar6 == (code *)0x0)) {
                              uVar7 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar7,0);
                            }
                            DAT_182ec1080 = pcVar6;
                            uVar7 = (*DAT_182ec1080)(lVar9);
                            if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
                              FUN_18035c820();
                            }
                            ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DestroyChildren__0600172c
                                      (uVar7,0);
                            bVar13 = DAT_182eb5d50 != 0;
                            **(longlong **)(DAT_182d647e0 + 0xb8) = lVar8;
                            if (bVar13) {
                              uVar5 = (uint)(*(ulonglong *)(DAT_182d647e0 + 0xb8) >> 0xc);
                              uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
                              do {
                                uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                                LOCK();
                                bVar13 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                                if (bVar13) {
                                  *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) =
                                       uVar1 | 1L << (uVar5 & 0x3f);
                                }
                                UNLOCK();
                              } while (!bVar13);
                            }
                            lVar8 = *(longlong *)(unaff_RDI + 0x28);
                            if (((lVar8 != 0) && (*(longlong *)(lVar8 + 0x30) != 0)) &&
                               (lVar9 = *(longlong *)(*(longlong *)(lVar8 + 0x30) + 0x30),
                               lVar9 != 0)) {
                              ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__Initialize__06000d5b
                                        (*(undefined8 *)(lVar8 + 0x30),*(undefined8 *)(lVar8 + 0x98)
                                         ,*(undefined8 *)(lVar8 + 0x40),
                                         *(undefined8 *)(lVar9 + 0x78),*(undefined8 *)(lVar8 + 0x38)
                                        );
                              if ((*(longlong *)(unaff_RDI + 0x28) != 0) &&
                                 (lVar8 = *(longlong *)(*(longlong *)(unaff_RDI + 0x28) + 0x90),
                                 lVar8 != 0)) {
                                pcVar6 = DAT_182ec1120;
                                if ((DAT_182ec1120 == (code *)0x0) &&
                                   (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::get_transform()"),
                                   pcVar6 == (code *)0x0)) {
                                  uVar7 = FUN_1802ced60("UnityEngine.GameObject::get_transform()");
                    /* WARNING: Subroutine does not return */
                                  FUN_1802cca90(uVar7,0);
                                }
                                DAT_182ec1120 = pcVar6;
                                lVar8 = (*DAT_182ec1120)(lVar8);
                                if ((((*(longlong *)(unaff_RDI + 0x28) != 0) &&
                                     (lVar9 = *(longlong *)(*(longlong *)(unaff_RDI + 0x28) + 0x30),
                                     lVar9 != 0)) &&
                                    (lVar9 = *(longlong *)(lVar9 + 0x40), lVar9 != 0)) &&
                                   (lVar8 != 0)) {
                                  FUN_181f4c9c0(lVar8,*(undefined8 *)(lVar9 + 0x18),0);
                                  if ((*(longlong *)(unaff_RDI + 0x28) != 0) &&
                                     (lVar8 = *(longlong *)(*(longlong *)(unaff_RDI + 0x28) + 0x90),
                                     lVar8 != 0)) {
                                    lVar8 = FUN_181f3e980(lVar8,0);
                                    if (DAT_182eb5480 == '\0') {
                                      FUN_1802f2810(&DAT_182d522a8);
                                      LOCK();
                                      UNLOCK();
                                      DAT_182eb5480 = '\x01';
                                    }
                                    if (lVar8 != 0) {
                                      in_stack_00000040 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
                                      in_stack_00000048 =
                                           *(undefined4 *)
                                            (*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
                                      pcVar6 = DAT_182ec16b0;
                                      if ((DAT_182ec16b0 == (code *)0x0) &&
                                         (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localPosition_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar6 == (code *)0x0)) {
                                        uVar7 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_localPosition_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                        FUN_1802cca90(uVar7,0);
                                      }
                                      DAT_182ec16b0 = pcVar6;
                                      (*DAT_182ec16b0)(lVar8,&stack0x00000040);
                                      if ((*(longlong *)(unaff_RDI + 0x28) != 0) &&
                                         (lVar8 = *(longlong *)
                                                   (*(longlong *)(unaff_RDI + 0x28) + 0x90),
                                         lVar8 != 0)) {
                                        lVar8 = FUN_181f3e980(lVar8,0);
                                        if (DAT_182eb547f == '\0') {
                                          FUN_1802f2810(&DAT_182d52290);
                                          LOCK();
                                          UNLOCK();
                                          DAT_182eb547f = '\x01';
                                        }
                                        puVar2 = *(undefined4 **)(DAT_182d52290 + 0xb8);
                                        if (lVar8 != 0) {
                                          uStack0000000000000050 = *puVar2;
                                          uStack0000000000000054 = puVar2[1];
                                          uStack0000000000000058 = puVar2[2];
                                          uStack000000000000005c = puVar2[3];
                                          pcVar6 = DAT_182ec16d0;
                                          if ((DAT_182ec16d0 == (code *)0x0) &&
                                             (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localRotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar6 == (code *)0x0)) {
                                            uVar7 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_localRotation_Injected(UnityEngine.Quaternion&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                            FUN_1802cca90(uVar7,0);
                                          }
                                          DAT_182ec16d0 = pcVar6;
                                          (*DAT_182ec16d0)(lVar8,&stack0x00000050);
                                          if ((*(longlong *)(unaff_RDI + 0x28) != 0) &&
                                             (lVar8 = *(longlong *)
                                                       (*(longlong *)(unaff_RDI + 0x28) + 0x98),
                                             lVar8 != 0)) {
                                            ExposureUnnoticed2_Object3D_Camera_FaceCameraController__Initialize__060011f6
                                                      (lVar8,0);
                                            lVar8 = *(longlong *)(unaff_RDI + 0x28);
                                            if ((lVar8 != 0) && (*(longlong *)(lVar8 + 0x28) != 0))
                                            {
                                              ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Initialize__06001198
                                                        (*(longlong *)(lVar8 + 0x28),
                                                         *(undefined8 *)(lVar8 + 0x30),0);
                                              lVar8 = *(longlong *)(unaff_RDI + 0x28);
                                              if ((((lVar8 != 0) &&
                                                   (*(longlong *)(lVar8 + 0x30) != 0)) &&
                                                  (lVar9 = *(longlong *)
                                                            (*(longlong *)(lVar8 + 0x30) + 0x40),
                                                  lVar9 != 0)) &&
                                                 ((lVar3 = *(longlong *)
                                                            (*(longlong *)(lVar8 + 0x30) + 0x30),
                                                  lVar3 != 0 && (*(longlong *)(lVar8 + 0x38) != 0)))
                                                 ) {
                                                ExposureUnnoticed2_Object3D_Camera_BaseCameraController__Initialize__060011e5
                                                          (*(longlong *)(lVar8 + 0x38),
                                                           *(undefined8 *)(lVar8 + 0x30),
                                                           *(undefined8 *)(lVar9 + 0x60),
                                                           *(undefined8 *)(lVar8 + 0x40),
                                                           *(undefined8 *)(lVar3 + 0x78));
                                                lVar8 = *(longlong *)(unaff_RDI + 0x28);
                                                if ((lVar8 != 0) &&
                                                   (lVar9 = *(longlong *)(lVar8 + 0x50), lVar9 != 0)
                                                   ) {
                                                  *(undefined8 *)(lVar9 + 0x48) =
                                                       *(undefined8 *)(lVar8 + 0x30);
                                                  FUN_18031d480(lVar9 + 0x48);
                                                  FUN_180436590(lVar9);
                                                  *(undefined1 *)(lVar9 + 100) = 1;
                                                  if ((*(longlong *)(unaff_RDI + 0x28) != 0) &&
                                                     (lVar8 = *(longlong *)
                                                               (*(longlong *)(unaff_RDI + 0x28) +
                                                               0x60), lVar8 != 0)) {
                                                    if (DAT_182eb7957 == '\0') {
                                                      FUN_1802f2810(&DAT_182d5e0d0);
                                                      LOCK();
                                                      UNLOCK();
                                                      FUN_1802f2810(&DAT_182d53c58);
                                                      LOCK();
                                                      UNLOCK();
                                                      FUN_1802f2810(&DAT_182d5e0c8);
                                                      LOCK();
                                                      UNLOCK();
                                                      FUN_1802f2810(&DAT_182d583a0);
                                                      LOCK();
                                                      UNLOCK();
                                                      FUN_1802f2810(&DAT_182d5e0c0);
                                                      LOCK();
                                                      UNLOCK();
                                                      DAT_182eb7957 = '\x01';
                                                    }
                                                    uVar7 = FUN_1802c43a0(DAT_182d5e0d0);
                                                    FUN_180665bb0(uVar7,lVar8,DAT_182d5e0c0,0);
                                                    if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                                                      FUN_18035c820();
                                                    }
                                                    FUN_180993250(uVar7,0,DAT_182d5e0c8);
                                                    uVar7 = FUN_180735660(lVar8,DAT_182d53c58);
                                                    *(undefined8 *)(lVar8 + 0x50) = uVar7;
                                                    FUN_18031d480(lVar8 + 0x50);
                                                    if ((*(longlong *)(unaff_RDI + 0x28) != 0) &&
                                                       (lVar8 = *(longlong *)
                                                                 (*(longlong *)(unaff_RDI + 0x28) +
                                                                 0x70), lVar8 != 0)) {
                                                                                                            
                                                  ExposureUnnoticed2_Scripts_InGame_SlowAssistManager__Initialize__06001640
                                                            (lVar8,0);
                                                  if ((*(longlong *)(unaff_RDI + 0x28) != 0) &&
                                                     (lVar8 = *(longlong *)
                                                               (*(longlong *)(unaff_RDI + 0x28) +
                                                               0x78), lVar8 != 0)) {
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_UIPlayer_UiPlayerController__Initialize__060009cd
                                                            (lVar8,0);
                                                  if (*(longlong *)(unaff_RDI + 0x50) != 0) {
                                                                                                        
                                                  ExposureUnnoticed2_Scripts_InGame_DroneManager__Initialize__060014ee
                                                            (*(longlong *)(unaff_RDI + 0x50),0);
                                                  lVar8 = *(longlong *)(unaff_RDI + 0x58);
                                                  if (lVar8 != 0) {
                                                    if (DAT_182eb79e1 == '\0') {
                                                      FUN_1802f2810(&DAT_182d5e260);
                                                      LOCK();
                                                      UNLOCK();
                                                      DAT_182eb79e1 = '\x01';
                                                    }
                                                    **(longlong **)(DAT_182d5e260 + 0xb8) = lVar8;
                                                    FUN_18031d480(*(undefined8 *)
                                                                   (DAT_182d5e260 + 0xb8));
                                                    lVar8 = *(longlong *)(unaff_RDI + 0x98);
                                                    if (lVar8 != 0) {
                                                      if (DAT_182eb821f == '\0') {
                                                        FUN_1802f2810(&DAT_182d5ae40);
                                                        LOCK();
                                                        UNLOCK();
                                                        FUN_1802f2810(&DAT_182d58138);
                                                        LOCK();
                                                        UNLOCK();
                                                        FUN_1802f2810(&DAT_182d5ae38);
                                                        LOCK();
                                                        UNLOCK();
                                                        FUN_1802f2810(&DAT_182d58130);
                                                        LOCK();
                                                        UNLOCK();
                                                        FUN_1802f2810(&DAT_182d583a0);
                                                        LOCK();
                                                        UNLOCK();
                                                        FUN_1802f2810(&DAT_182d6c2f0);
                                                        LOCK();
                                                        UNLOCK();
                                                        FUN_1802f2810(&DAT_182d6c2e8);
                                                        LOCK();
                                                        UNLOCK();
                                                        DAT_182eb821f = '\x01';
                                                      }
                                                      lVar9 = FUN_180498cf0();
                                                      if (lVar9 == 0) {
                                                        FUN_18060d0d0(lVar8);
                                                        uVar7 = FUN_1802c43a0(DAT_182d5ae40);
                                                        FUN_180665bb0(uVar7,lVar8,DAT_182d6c2f0,0);
                                                        if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                                                          FUN_18035c820();
                                                        }
                                                        FUN_180993250(uVar7,0,DAT_182d5ae38);
                                                        uVar7 = FUN_1802c43a0(DAT_182d58138);
                                                        FUN_180665bb0(uVar7,lVar8,DAT_182d6c2e8,0);
                                                        FUN_180993250(uVar7,0,DAT_182d58130);
                                                      }
                                                      if (*(longlong *)(unaff_RDI + 0x28) != 0) {
                                                        lVar8 = *(longlong *)
                                                                 (*(longlong *)(unaff_RDI + 0x28) +
                                                                 0x80);
                                                        lVar9 = *(longlong *)
                                                                 (*(longlong *)(unaff_RDI + 0x28) +
                                                                 0x98);
                                                        if (lVar9 != 0) {
                                                          uVar7 = 
                                                  ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                                                            (lVar9,0);
                                                  if ((*(longlong *)(unaff_RDI + 0x28) != 0) &&
                                                     (uVar10 = *(undefined8 *)
                                                                (*(longlong *)(unaff_RDI + 0x28) +
                                                                0xa0), lVar8 != 0)) {
                                                    if (DAT_182eb7a49 == '\0') {
                                                      FUN_1802f2810(&DAT_182d58370);
                                                      LOCK();
                                                      UNLOCK();
                                                      FUN_1802f2810(&DAT_182d58348);
                                                      LOCK();
                                                      UNLOCK();
                                                      FUN_1802f2810(&DAT_182d583a0);
                                                      LOCK();
                                                      UNLOCK();
                                                      FUN_1802f2810(&DAT_182d5fdf8);
                                                      LOCK();
                                                      UNLOCK();
                                                      DAT_182eb7a49 = '\x01';
                                                    }
                                                    uVar11 = FUN_1802c43a0(DAT_182d58370);
                                                    FUN_180665bb0(uVar11,lVar8,DAT_182d5fdf8,0);
                                                    if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                                                      FUN_18035c820();
                                                    }
                                                    FUN_180993250(uVar11,0,DAT_182d58348);
                                                    *(undefined8 *)(lVar8 + 0x20) = uVar7;
                                                    FUN_18031d480(lVar8 + 0x20);
                                                    *(undefined8 *)(lVar8 + 0x28) = uVar10;
                                                    FUN_18031d480(lVar8 + 0x28);
                                                                                                        
                                                  ExposureUnnoticed2_Scripts_InGame_UiOptionApplyer__OnChange__06001682
                                                            (lVar8,0,0);
                                                  if (((*(longlong *)(unaff_RDI + 0x28) != 0) &&
                                                      (lVar8 = *(longlong *)
                                                                (*(longlong *)(unaff_RDI + 0x28) +
                                                                0x88), lVar8 != 0)) &&
                                                     (
                                                  ExposureUnnoticed2_Scripts_InGame_InGameGraphicsOptionApplyer__Initialize__06001578
                                                            (lVar8,0),
                                                  *(longlong *)(unaff_RDI + 0x70) != 0)) {
                                                    FUN_1804c1f90();
                                                    if ((*(longlong *)(unaff_RDI + 0x28) != 0) &&
                                                       (lVar8 = *(longlong *)(unaff_RDI + 0x80),
                                                       lVar8 != 0)) {
                                                      *(undefined8 *)(lVar8 + 0x10) =
                                                           *(undefined8 *)
                                                            (*(longlong *)(unaff_RDI + 0x28) + 0x50)
                                                      ;
                                                      FUN_18031d480(lVar8 + 0x10);
                                                      if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
                                                        FUN_18035c820(DAT_182d58080);
                                                      }
                                                      lVar8 = *(longlong *)
                                                               (*(longlong *)(DAT_182d58080 + 0xb8)
                                                               + 0x10);
                                                      if (lVar8 != 0) {
                                                        *(undefined1 *)(lVar8 + 0x10) = 0;
                                                        uVar7 = *(undefined8 *)
                                                                 (*(longlong *)
                                                                   (DAT_182d58080 + 0xb8) + 0x10);
                                                        if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                                                          FUN_18035c820();
                                                        }
                                                                                                                
                                                  ExposureUnnoticed2_Scripts_Base_EventManager__Broadcast__06001716
                                                            (uVar7,0);
                                                  lVar8 = FUN_181f3f030(DAT_182d5d688,0);
                                                  if (((lVar8 != 0) &&
                                                      (lVar8 = FUN_1809a08f0(lVar8,DAT_182d5d6f0),
                                                      lVar8 != 0)) &&
                                                     (lVar9 = *(longlong *)
                                                               (*(longlong *)(DAT_182d58398 + 0xb8)
                                                               + 0x48), lVar9 != 0)) {
                                                    if (*(int *)(lVar8 + 0x20) ==
                                                        *(int *)(lVar9 + 0x10)) {
                                                      if (*(longlong *)(unaff_RDI + 0x28) == 0)
                                                      goto LAB_180497e68;
                                                      lVar8 = *(longlong *)
                                                               (*(longlong *)(unaff_RDI + 0x28) +
                                                               0x30);
                                                      lVar9 = *(longlong *)
                                                               (*(longlong *)(DAT_182d58398 + 0xb8)
                                                               + 0x48);
                                                      if (lVar8 == 0) goto LAB_180497e68;
                                                      uStack0000000000000050 =
                                                           *(undefined4 *)(lVar9 + 0x18c);
                                                      uStack0000000000000054 =
                                                           *(undefined4 *)(lVar9 + 400);
                                                      uStack0000000000000058 =
                                                           *(undefined4 *)(lVar9 + 0x194);
                                                      uStack000000000000005c =
                                                           *(undefined4 *)(lVar9 + 0x198);
                                                      in_stack_00000048 =
                                                           *(undefined4 *)(lVar9 + 0x188);
                                                      in_stack_00000040 =
                                                           *(undefined8 *)(lVar9 + 0x180);
                                                                                                            
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__Warp__06000d62
                                                            (lVar8,&stack0x00000040,&stack0x00000050
                                                             ,0);
                                                  }
                                                  else {
                                                    lVar8 = *(longlong *)
                                                             (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                             0x48);
                                                    lVar9 = FUN_181f3f030(DAT_182d5d688,0);
                                                    if (((lVar9 == 0) ||
                                                        (lVar9 = FUN_1809a08f0(lVar9,DAT_182d5d6f0),
                                                        lVar9 == 0)) || (lVar8 == 0))
                                                    goto LAB_180497e68;
                                                    *(undefined4 *)(lVar8 + 0x10) =
                                                         *(undefined4 *)(lVar9 + 0x20);
                                                  }
                                                  if ((*(longlong *)(unaff_RDI + 0x28) != 0) &&
                                                     (lVar8 = *(longlong *)
                                                               (*(longlong *)(unaff_RDI + 0x28) +
                                                               0x40), lVar8 != 0)) {
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_Camera_TPCameraController__ResetToPlayerDirect__06001219
                                                            (lVar8,0);
                                                  uVar7 = FUN_1802c43a0(DAT_182d58368);
                                                  FUN_1814df680(uVar7);
                                                  ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b
                                                            (uVar7,2,0);
                                                  lVar8 = FUN_180498ef0();
                                                  if (lVar8 != 0) {
                                                                                                        
                                                  ExposureUnnoticed2_Scripts_Base_InputRebindSaveManager__Load__06001792
                                                            (lVar8,0);
                                                  if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  ExposureUnnoticed2_Scripts_InGame_DebugController__Initialize__060014e9
                                                            (0);
                                                  if (**(longlong **)(DAT_182d58238 + 0xb8) != 0) {
                                                    lVar8 = *(longlong *)
                                                             (**(longlong **)(DAT_182d58238 + 0xb8)
                                                             + 0x300);
                                                    if (*(int *)(DAT_182d5bfa0 + 0xe0) == 0) {
                                                      FUN_18035c820(DAT_182d5bfa0);
                                                    }
                                                    uVar15 = 0x3c23d70a;
                                                    if (*(char *)(*(longlong *)
                                                                   (DAT_182d5bfa0 + 0xb8) + 3) ==
                                                        '\0') {
                                                      uVar14 = 0x3be21965;
                                                    }
                                                    else {
                                                      uVar14 = 0x3c23d70a;
                                                    }
                                                    if (lVar8 != 0) {
                                                      FUN_181f11730(lVar8,DAT_182d5d698,uVar14,0);
                                                      if (**(longlong **)(DAT_182d58238 + 0xb8) != 0
                                                         ) {
                                                        lVar8 = *(longlong *)
                                                                 (**(longlong **)
                                                                    (DAT_182d58238 + 0xb8) + 0x308);
                                                        if (*(int *)(DAT_182d5bfa0 + 0xe0) == 0) {
                                                          FUN_18035c820(DAT_182d5bfa0);
                                                        }
                                                        if (*(char *)(*(longlong *)
                                                                       (DAT_182d5bfa0 + 0xb8) + 3)
                                                            == '\0') {
                                                          uVar15 = 0x3b8ce704;
                                                        }
                                                        if (lVar8 != 0) {
                                                          FUN_181f11730(lVar8,DAT_182d5d698,uVar15,0
                                                                       );
                                                          if (*(int *)(DAT_182d5bfa0 + 0xe0) == 0) {
                                                            FUN_18035c820(DAT_182d5bfa0);
                                                          }
                                                          if (*(char *)(*(longlong *)
                                                                         (DAT_182d5bfa0 + 0xb8) + 3)
                                                              != '\0') {
                                                            if (((*(longlong *)(unaff_RDI + 0x28) ==
                                                                  0) || (lVar8 = *(longlong *)
                                                                                  (*(longlong *)
                                                                                    (unaff_RDI +
                                                                                    0x28) + 0xa0),
                                                                        lVar8 == 0)) ||
                                                               (lVar8 = FUN_1809a08f0(lVar8,
                                                  DAT_182d5d6f8), lVar8 == 0)) goto LAB_180497e56;
                                                  uVar5 = FUN_181efb420(lVar8,0);
                                                  if (*(int *)(DAT_182d582a0 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  if (DAT_182eb7ace == '\0') {
                                                    FUN_1802f2810(&DAT_182d582a0);
                                                    LOCK();
                                                    UNLOCK();
                                                    FUN_1802f2810(&DAT_182d5f560);
                                                    LOCK();
                                                    UNLOCK();
                                                    DAT_182eb7ace = '\x01';
                                                  }
                                                  if (*(int *)(DAT_182d582a0 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  if (*(int *)(*(longlong *)(DAT_182d582a0 + 0xb8) +
                                                              0x34) == -1) {
                                                    uVar15 = FUN_181f3f150(DAT_182d5f560,0);
                                                    if (*(int *)(DAT_182d582a0 + 0xe0) == 0) {
                                                      FUN_18035c820();
                                                    }
                                                    *(undefined4 *)
                                                     (*(longlong *)(DAT_182d582a0 + 0xb8) + 0x34) =
                                                         uVar15;
                                                  }
                                                  if (*(int *)(DAT_182d582a0 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  FUN_181efb470(lVar8,uVar5 | 1 << (*(uint *)(*(
                                                  longlong *)(DAT_182d582a0 + 0xb8) + 0x34) & 0x1f),
                                                  0);
                                                  }
                                                  return;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
LAB_180497e56:
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
                    /* WARNING: Subroutine does not return */
                                        FUN_18031dad0();
                                      }
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
                }
              }
            }
          }
        }
      }
    }
  }
LAB_180497e68:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

