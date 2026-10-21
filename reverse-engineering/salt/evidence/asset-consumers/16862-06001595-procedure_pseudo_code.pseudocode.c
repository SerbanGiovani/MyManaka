// Ghidra pseudocode; not original source or compilable C.
// ev_b99f603049900a7a375e4b4105d5e447e6cbc7838d78d3c2904b2fd51e2ec841

void ExposureUnnoticed2_Scripts_InGame_InGameManager__Start__06001595(longlong param_1)

{
  ulonglong uVar1;
  undefined4 *puVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  bool bVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  ulonglong in_stack_ffffffffffffffa8;
  ulonglong in_stack_ffffffffffffffb0;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 uStack_38;
  undefined *puStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  if (cRam0000000182eb79da == '\0') {
    FUN_1802f2810(0x182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53a48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d710);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d700);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d59ac8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e258);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bcb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d58080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d6f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5abb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d6f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d6e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d6d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d6c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d6c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ab80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d582a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d54d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e260);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d6b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e268);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d6b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d6a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d6a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5a8f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d698);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d688);
    LOCK();
    UNLOCK();
    cRam0000000182eb79da = '\x01';
  }
  if (*(char *)(*(longlong *)(lRam0000000182d53c48 + 0xb8) + 8) != '\0') {
    pcVar6 = pcRam0000000182ec1088;
    if ((pcRam0000000182ec1088 == (code *)0x0) &&
       (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
       pcVar6 == (code *)0x0)) {
      uVar7 = func_0x0001802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar7,0);
    }
    pcRam0000000182ec1088 = pcVar6;
    uVar7 = (*pcRam0000000182ec1088)(param_1);
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (cRam0000000182ec12b0 == '\0') {
      puStack_30 = &UNK_181f43e9e;
      FUN_1802f2810(0x182d53aa8,0);
      LOCK();
      UNLOCK();
      cRam0000000182ec12b0 = '\x01';
    }
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      puStack_30 = &UNK_181f43ebf;
      FUN_18035c820();
    }
    pcVar6 = pcRam0000000182ec12a8;
    if (pcRam0000000182ec12a8 == (code *)0x0) {
      puStack_30 = &UNK_181f43ed7;
      pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)"
                                    );
      if (pcVar6 == (code *)0x0) {
        puStack_30 = &UNK_181f43efd;
        uVar7 = func_0x0001802ced60("UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)")
        ;
                    /* WARNING: Subroutine does not return */
        puStack_30 = &UNK_181f43f07;
        FUN_1802cca90(uVar7,0);
      }
    }
    pcRam0000000182ec12a8 = pcVar6;
                    /* WARNING: Could not recover jumptable at 0x000181f43eee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*pcRam0000000182ec12a8)(uVar7,0);
    return;
  }
  pcVar6 = pcRam0000000182ec1088;
  if ((pcRam0000000182ec1088 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
     pcVar6 == (code *)0x0)) {
    uVar7 = func_0x0001802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar7,0);
  }
  pcRam0000000182ec1088 = pcVar6;
  uVar7 = (*pcRam0000000182ec1088)(param_1);
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar6 = pcRam0000000182ec12d8;
  if ((pcRam0000000182ec12d8 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Object::DontDestroyOnLoad(UnityEngine.Object)"),
     pcVar6 == (code *)0x0)) {
    uVar7 = func_0x0001802ced60("UnityEngine.Object::DontDestroyOnLoad(UnityEngine.Object)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar7,0);
  }
  pcRam0000000182ec12d8 = pcVar6;
  (*pcRam0000000182ec12d8)(uVar7);
  *(undefined1 *)(*(longlong *)(lRam0000000182d53c48 + 0xb8) + 8) = 1;
  **(longlong **)(lRam0000000182d53c48 + 0xb8) = param_1;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(ulonglong *)(lRam0000000182d53c48 + 0xb8) >> 0xc);
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
  if (**(char **)(lRam0000000182d5e268 + 0xb8) == '\0') {
    FUN_18049d380(5,0,0);
  }
  lVar8 = *(longlong *)(*(longlong *)(lRam0000000182d58398 + 0xb8) + 0x38);
  if (lVar8 != 0) {
    uVar14 = *(undefined4 *)(lVar8 + 0x90);
    if (*(int *)(lRam0000000182d53a48 + 0xe0) == 0) {
      FUN_18035c820();
    }
    pcVar6 = pcRam0000000182ebf9e0;
    if ((pcRam0000000182ebf9e0 == (code *)0x0) &&
       (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Application::set_targetFrameRate(System.Int32)")
       , pcVar6 == (code *)0x0)) {
      uVar7 = func_0x0001802ced60("UnityEngine.Application::set_targetFrameRate(System.Int32)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar7,0);
    }
    pcRam0000000182ebf9e0 = pcVar6;
    (*pcRam0000000182ebf9e0)(uVar14);
    if (*(int *)(lRam0000000182d59ac8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar7 = FUN_1802c43a0(uRam0000000182d5d6b0);
    bVar13 = DAT_182eb5d50 != 0;
    *(undefined8 *)(param_1 + 0x60) = uVar7;
    if (bVar13) {
      uVar5 = (uint)(param_1 + 0x60U >> 0xc);
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
    lVar8 = FUN_1802c43a0(uRam0000000182d5bcb8);
    if (cRam0000000182eb796c == '\0') {
      FUN_1802f2810(0x182d5dfe0);
      LOCK();
      UNLOCK();
      FUN_1802f2810(0x182d5dfd8);
      LOCK();
      UNLOCK();
      FUN_1802f2810(0x182d5dfd0);
      LOCK();
      UNLOCK();
      cRam0000000182eb796c = '\x01';
    }
    uVar7 = FUN_1802c43a0(uRam0000000182d5dfd8);
    FUN_180e686d0(uVar7,uRam0000000182d5dfe0);
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
    lVar9 = FUN_1802c36c0(uRam0000000182d5dfd0,2);
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
      FUN_18048aa90(lVar8,0);
      bVar13 = DAT_182eb5d50 != 0;
      *(longlong *)(param_1 + 0x20) = lVar8;
      if (bVar13) {
        uVar5 = (uint)(param_1 + 0x20U >> 0xc);
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
      uVar7 = FUN_1802c43a0(uRam0000000182d5d6d8);
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x80) = uVar7;
      if (bVar13) {
        uVar5 = (uint)(param_1 + 0x80U >> 0xc);
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
      uVar7 = FUN_1802c43a0(uRam0000000182d5d6e8);
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x68) = uVar7;
      if (bVar13) {
        uVar5 = (uint)(param_1 + 0x68U >> 0xc);
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
      uVar7 = FUN_1802c43a0(uRam0000000182d5d6a0);
      FUN_1804a8510(uVar7,0);
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x30) = uVar7;
      if (bVar13) {
        uVar5 = (uint)(param_1 + 0x30U >> 0xc);
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
      uVar7 = FUN_1802c43a0(uRam0000000182d5d6c8);
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x88) = uVar7;
      if (bVar13) {
        uVar5 = (uint)(param_1 + 0x88U >> 0xc);
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
      uVar7 = FUN_1802c43a0(uRam0000000182d5ab80);
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x90) = uVar7;
      if (bVar13) {
        uVar5 = (uint)(param_1 + 0x90U >> 0xc);
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
      lVar8 = FUN_1802c43a0(uRam0000000182d5e190);
      if (cRam0000000182eb7927 == '\0') {
        FUN_1802f2810(0x182d5e140);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5e138);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5e1b0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5e1a8);
        LOCK();
        UNLOCK();
        cRam0000000182eb7927 = '\x01';
      }
      uVar7 = FUN_1802c43a0(uRam0000000182d5e1a8);
      FUN_1811cf4f0(uVar7,uRam0000000182d5e1b0);
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
      uVar7 = FUN_1802c43a0(uRam0000000182d5e138);
      FUN_180e686d0(uVar7,uRam0000000182d5e140);
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
      *(longlong *)(param_1 + 0x38) = lVar8;
      if (iVar4 != 0) {
        uVar5 = (uint)(param_1 + 0x38U >> 0xc);
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
      lVar8 = FUN_1802c43a0(uRam0000000182d5a8f0);
      if (cRam0000000182eb7a53 == '\0') {
        FUN_1802f2810(0x182d583b8);
        LOCK();
        UNLOCK();
        cRam0000000182eb7a53 = '\x01';
      }
      uVar7 = FUN_1802c43a0(uRam0000000182d583b8);
      FUN_1804b5410(uVar7,0x3f000000,0x3f800000,0,in_stack_ffffffffffffffa8 & 0xffffffffffffff00,
                    in_stack_ffffffffffffffb0 & 0xffffffffffffff00,CONCAT44(uVar15,0xbf800000),0);
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
      *(longlong *)(param_1 + 0x48) = lVar8;
      if (iVar4 != 0) {
        uVar5 = (uint)(param_1 + 0x48U >> 0xc);
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
      lVar8 = FUN_1802c43a0(uRam0000000182d5e258);
      if (cRam0000000182eb7969 == '\0') {
        FUN_1802f2810(0x182d5dff0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5dfe8);
        LOCK();
        UNLOCK();
        cRam0000000182eb7969 = '\x01';
      }
      uVar7 = FUN_1802c43a0(uRam0000000182d5dfe8);
      FUN_180e2cdf0(uVar7,uRam0000000182d5dff0);
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
      *(longlong *)(param_1 + 0x50) = lVar8;
      if (iVar4 != 0) {
        uVar5 = (uint)(param_1 + 0x50U >> 0xc);
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
      lVar8 = FUN_1802c43a0(lRam0000000182d5e260);
      if (cRam0000000182eb79f7 == '\0') {
        FUN_1802f2810(0x182d5e1b0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5e1a8);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d60288);
        LOCK();
        UNLOCK();
        cRam0000000182eb79f7 = '\x01';
      }
      uVar7 = FUN_1802c43a0(uRam0000000182d5e1a8);
      FUN_1811cf4f0(uVar7,uRam0000000182d5e1b0);
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
      uVar7 = FUN_1802c43a0(uRam0000000182d60288);
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
      *(longlong *)(param_1 + 0x58) = lVar8;
      if (iVar4 != 0) {
        uVar5 = (uint)(param_1 + 0x58U >> 0xc);
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
      lVar8 = FUN_1802c43a0(uRam0000000182d5d6b8);
      if (cRam0000000182eb8224 == '\0') {
        FUN_1802f2810(0x182d6c298);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d6c290);
        LOCK();
        UNLOCK();
        cRam0000000182eb8224 = '\x01';
      }
      uVar7 = FUN_1802c43a0(uRam0000000182d6c290);
      FUN_1811cf4f0(uVar7,uRam0000000182d6c298);
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
      *(longlong *)(param_1 + 0x98) = lVar8;
      if (iVar4 != 0) {
        uVar5 = (uint)(param_1 + 0x98U >> 0xc);
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
      uVar7 = FUN_1802c43a0(uRam0000000182d5d6a8);
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0xa0) = uVar7;
      if (bVar13) {
        uVar5 = (uint)(param_1 + 0xa0U >> 0xc);
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
      uVar7 = FUN_180735660(param_1,uRam0000000182d5d700);
      bVar13 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x28) = uVar7;
      if (bVar13) {
        uVar5 = (uint)(param_1 + 0x28U >> 0xc);
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
      lVar8 = *(longlong *)(param_1 + 0x28);
      if (lVar8 != 0) {
        if (cRam0000000182eb79e2 == '\0') {
          FUN_1802f2810(0x182d60358);
          LOCK();
          UNLOCK();
          cRam0000000182eb79e2 = '\x01';
        }
        if (*(longlong *)(lVar8 + 0x38) != 0) {
          uVar7 = FUN_180735660(*(longlong *)(lVar8 + 0x38),uRam0000000182d60358);
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
          lVar8 = *(longlong *)(param_1 + 0x28);
          if (**(longlong **)(lRam0000000182d58238 + 0xb8) != 0) {
            uVar7 = *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x348);
            pcVar6 = pcRam0000000182ec1080;
            if ((pcRam0000000182ec1080 == (code *)0x0) &&
               (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
               pcVar6 == (code *)0x0)) {
              uVar7 = func_0x0001802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar7,0);
            }
            pcRam0000000182ec1080 = pcVar6;
            uVar10 = (*pcRam0000000182ec1080)(param_1);
            if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            lVar9 = FUN_1809f1050(uVar7,uVar10,uRam0000000182d54d90);
            if ((lVar9 != 0) && (uVar7 = FUN_1809a08f0(lVar9,uRam0000000182d5abb8), lVar8 != 0)) {
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
              uVar7 = FUN_180735660(param_1,uRam0000000182d5d710);
              bVar13 = DAT_182eb5d50 != 0;
              *(undefined8 *)(param_1 + 0x78) = uVar7;
              if (bVar13) {
                uVar5 = (uint)(param_1 + 0x78U >> 0xc);
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
              if ((*(longlong *)(param_1 + 0x78) != 0) &&
                 (FUN_18048b000(*(longlong *)(param_1 + 0x78),*(undefined8 *)(param_1 + 0x28),0),
                 *(longlong *)(param_1 + 0x48) != 0)) {
                FUN_1804c20d0();
                lVar8 = *(longlong *)(param_1 + 0x90);
                if (lVar8 != 0) {
                  if (cRam0000000182eb7ab9 == '\0') {
                    FUN_1802f2810(0x182d5abb0);
                    LOCK();
                    UNLOCK();
                    FUN_1802f2810(0x182d5aba8);
                    LOCK();
                    UNLOCK();
                    FUN_1802f2810(0x182d583a0);
                    LOCK();
                    UNLOCK();
                    FUN_1802f2810(0x182d5f610);
                    LOCK();
                    UNLOCK();
                    cRam0000000182eb7ab9 = '\x01';
                  }
                  uVar7 = FUN_1802c43a0(uRam0000000182d5abb0);
                  FUN_180665bb0(uVar7,lVar8,uRam0000000182d5f610,0);
                  if (*(int *)(lRam0000000182d583a0 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  FUN_180993250(uVar7,1,uRam0000000182d5aba8);
                  if (*(longlong *)(param_1 + 0x38) != 0) {
                    FUN_18047d430(*(longlong *)(param_1 + 0x38),0);
                    if (*(longlong *)(param_1 + 0x88) != 0) {
                      FUN_180493f40(*(longlong *)(param_1 + 0x88),*(undefined8 *)(param_1 + 0x68),0)
                      ;
                      lVar8 = *(longlong *)(param_1 + 0x68);
                      if (lVar8 != 0) {
                        *(undefined8 *)(lVar8 + 0x10) = *(undefined8 *)(param_1 + 0x28);
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
                        *(longlong *)(lVar8 + 0x18) = param_1;
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
                        if (((*(longlong *)(param_1 + 0x28) != 0) &&
                            (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x28), lVar8 != 0
                            )) && (lVar8 = *(longlong *)(lVar8 + 0x68), lVar8 != 0)) {
                          if (cRam0000000182eb7ce5 == '\0') {
                            FUN_1802f2810(0x182d58288);
                            LOCK();
                            UNLOCK();
                            FUN_1802f2810(0x182d647e0);
                            LOCK();
                            UNLOCK();
                            cRam0000000182eb7ce5 = '\x01';
                          }
                          lVar9 = *(longlong *)(lVar8 + 0x48);
                          if (lVar9 != 0) {
                            pcVar6 = pcRam0000000182ec1080;
                            if ((pcRam0000000182ec1080 == (code *)0x0) &&
                               (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_transform()"),
                               pcVar6 == (code *)0x0)) {
                              uVar7 = func_0x0001802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar7,0);
                            }
                            pcRam0000000182ec1080 = pcVar6;
                            uVar7 = (*pcRam0000000182ec1080)(lVar9);
                            if (*(int *)(lRam0000000182d58288 + 0xe0) == 0) {
                              FUN_18035c820();
                            }
                            FUN_1804b2c70(uVar7,0);
                            bVar13 = DAT_182eb5d50 != 0;
                            **(longlong **)(lRam0000000182d647e0 + 0xb8) = lVar8;
                            if (bVar13) {
                              uVar5 = (uint)(*(ulonglong *)(lRam0000000182d647e0 + 0xb8) >> 0xc);
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
                            lVar8 = *(longlong *)(param_1 + 0x28);
                            if (((lVar8 != 0) && (*(longlong *)(lVar8 + 0x30) != 0)) &&
                               (lVar9 = *(longlong *)(*(longlong *)(lVar8 + 0x30) + 0x30),
                               lVar9 != 0)) {
                              FUN_180643550(*(undefined8 *)(lVar8 + 0x30),
                                            *(undefined8 *)(lVar8 + 0x98),
                                            *(undefined8 *)(lVar8 + 0x40),
                                            *(undefined8 *)(lVar9 + 0x78),
                                            *(undefined8 *)(lVar8 + 0x38),
                                            *(undefined8 *)(param_1 + 0x20),0);
                              if ((*(longlong *)(param_1 + 0x28) != 0) &&
                                 (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x90),
                                 lVar8 != 0)) {
                                pcVar6 = pcRam0000000182ec1120;
                                if ((pcRam0000000182ec1120 == (code *)0x0) &&
                                   (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::get_transform()"),
                                   pcVar6 == (code *)0x0)) {
                                  uVar7 = func_0x0001802ced60(
                                                  "UnityEngine.GameObject::get_transform()");
                    /* WARNING: Subroutine does not return */
                                  FUN_1802cca90(uVar7,0);
                                }
                                pcRam0000000182ec1120 = pcVar6;
                                lVar8 = (*pcRam0000000182ec1120)(lVar8);
                                if ((((*(longlong *)(param_1 + 0x28) != 0) &&
                                     (lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x30),
                                     lVar9 != 0)) &&
                                    (lVar9 = *(longlong *)(lVar9 + 0x40), lVar9 != 0)) &&
                                   (lVar8 != 0)) {
                                  FUN_181f4c9c0(lVar8,*(undefined8 *)(lVar9 + 0x18),0);
                                  if ((*(longlong *)(param_1 + 0x28) != 0) &&
                                     (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x90),
                                     lVar8 != 0)) {
                                    lVar8 = FUN_181f3e980(lVar8,0);
                                    if (cRam0000000182eb5480 == '\0') {
                                      FUN_1802f2810(0x182d522a8);
                                      LOCK();
                                      UNLOCK();
                                      cRam0000000182eb5480 = '\x01';
                                    }
                                    if (lVar8 != 0) {
                                      uStack_38 = **(undefined8 **)(lRam0000000182d522a8 + 0xb8);
                                      puStack_30 = (undefined *)
                                                   CONCAT44(puStack_30._4_4_,
                                                            *(undefined4 *)
                                                             (*(undefined8 **)
                                                               (lRam0000000182d522a8 + 0xb8) + 1));
                                      pcVar6 = pcRam0000000182ec16b0;
                                      if ((pcRam0000000182ec16b0 == (code *)0x0) &&
                                         (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localPosition_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar6 == (code *)0x0)) {
                                        uVar7 = func_0x0001802ced60(
                                                  "UnityEngine.Transform::set_localPosition_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                        FUN_1802cca90(uVar7,0);
                                      }
                                      pcRam0000000182ec16b0 = pcVar6;
                                      (*pcRam0000000182ec16b0)(lVar8,&uStack_38);
                                      if ((*(longlong *)(param_1 + 0x28) != 0) &&
                                         (lVar8 = *(longlong *)
                                                   (*(longlong *)(param_1 + 0x28) + 0x90),
                                         lVar8 != 0)) {
                                        lVar8 = FUN_181f3e980(lVar8,0);
                                        if (cRam0000000182eb547f == '\0') {
                                          FUN_1802f2810(0x182d52290);
                                          LOCK();
                                          UNLOCK();
                                          cRam0000000182eb547f = '\x01';
                                        }
                                        puVar2 = *(undefined4 **)(lRam0000000182d52290 + 0xb8);
                                        if (lVar8 != 0) {
                                          uStack_28 = *puVar2;
                                          uStack_24 = puVar2[1];
                                          uStack_20 = puVar2[2];
                                          uStack_1c = puVar2[3];
                                          pcVar6 = pcRam0000000182ec16d0;
                                          if ((pcRam0000000182ec16d0 == (code *)0x0) &&
                                             (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localRotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar6 == (code *)0x0)) {
                                            uVar7 = func_0x0001802ced60(
                                                  "UnityEngine.Transform::set_localRotation_Injected(UnityEngine.Quaternion&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                            FUN_1802cca90(uVar7,0);
                                          }
                                          pcRam0000000182ec16d0 = pcVar6;
                                          (*pcRam0000000182ec16d0)(lVar8,&uStack_28);
                                          if ((*(longlong *)(param_1 + 0x28) != 0) &&
                                             (lVar8 = *(longlong *)
                                                       (*(longlong *)(param_1 + 0x28) + 0x98),
                                             lVar8 != 0)) {
                                            FUN_18045c740(lVar8,0);
                                            lVar8 = *(longlong *)(param_1 + 0x28);
                                            if ((lVar8 != 0) && (*(longlong *)(lVar8 + 0x28) != 0))
                                            {
                                              FUN_180454870(*(longlong *)(lVar8 + 0x28),
                                                            *(undefined8 *)(lVar8 + 0x30),0);
                                              lVar8 = *(longlong *)(param_1 + 0x28);
                                              if ((((lVar8 != 0) &&
                                                   (*(longlong *)(lVar8 + 0x30) != 0)) &&
                                                  (lVar9 = *(longlong *)
                                                            (*(longlong *)(lVar8 + 0x30) + 0x40),
                                                  lVar9 != 0)) &&
                                                 ((lVar3 = *(longlong *)
                                                            (*(longlong *)(lVar8 + 0x30) + 0x30),
                                                  lVar3 != 0 && (*(longlong *)(lVar8 + 0x38) != 0)))
                                                 ) {
                                                FUN_18045ae80(*(longlong *)(lVar8 + 0x38),
                                                              *(undefined8 *)(lVar8 + 0x30),
                                                              *(undefined8 *)(lVar9 + 0x60),
                                                              *(undefined8 *)(lVar8 + 0x40),
                                                              *(undefined8 *)(lVar3 + 0x78),
                                                              *(undefined8 *)(lVar8 + 0x48),0);
                                                lVar8 = *(longlong *)(param_1 + 0x28);
                                                if ((lVar8 != 0) &&
                                                   (lVar9 = *(longlong *)(lVar8 + 0x50), lVar9 != 0)
                                                   ) {
                                                  *(undefined8 *)(lVar9 + 0x48) =
                                                       *(undefined8 *)(lVar8 + 0x30);
                                                  FUN_18031d480(lVar9 + 0x48);
                                                  FUN_180436590(lVar9);
                                                  *(undefined1 *)(lVar9 + 100) = 1;
                                                  if ((*(longlong *)(param_1 + 0x28) != 0) &&
                                                     (lVar8 = *(longlong *)
                                                               (*(longlong *)(param_1 + 0x28) + 0x60
                                                               ), lVar8 != 0)) {
                                                    if (cRam0000000182eb7957 == '\0') {
                                                      FUN_1802f2810(0x182d5e0d0);
                                                      LOCK();
                                                      UNLOCK();
                                                      FUN_1802f2810(0x182d53c58);
                                                      LOCK();
                                                      UNLOCK();
                                                      FUN_1802f2810(0x182d5e0c8);
                                                      LOCK();
                                                      UNLOCK();
                                                      FUN_1802f2810(0x182d583a0);
                                                      LOCK();
                                                      UNLOCK();
                                                      FUN_1802f2810(0x182d5e0c0);
                                                      LOCK();
                                                      UNLOCK();
                                                      cRam0000000182eb7957 = '\x01';
                                                    }
                                                    uVar7 = FUN_1802c43a0(uRam0000000182d5e0d0);
                                                    FUN_180665bb0(uVar7,lVar8,uRam0000000182d5e0c0,0
                                                                 );
                                                    if (*(int *)(lRam0000000182d583a0 + 0xe0) == 0)
                                                    {
                                                      FUN_18035c820();
                                                    }
                                                    FUN_180993250(uVar7,0,uRam0000000182d5e0c8);
                                                    uVar7 = FUN_180735660(lVar8,uRam0000000182d53c58
                                                                         );
                                                    *(undefined8 *)(lVar8 + 0x50) = uVar7;
                                                    FUN_18031d480(lVar8 + 0x50);
                                                    if ((*(longlong *)(param_1 + 0x28) != 0) &&
                                                       (lVar8 = *(longlong *)
                                                                 (*(longlong *)(param_1 + 0x28) +
                                                                 0x70), lVar8 != 0)) {
                                                      FUN_1804a2700(lVar8,0);
                                                      if ((*(longlong *)(param_1 + 0x28) != 0) &&
                                                         (lVar8 = *(longlong *)
                                                                   (*(longlong *)(param_1 + 0x28) +
                                                                   0x78), lVar8 != 0)) {
                                                        FUN_1805eb800(lVar8,0);
                                                        if (*(longlong *)(param_1 + 0x50) != 0) {
                                                          FUN_180487ac0(*(longlong *)
                                                                         (param_1 + 0x50),0);
                                                          lVar8 = *(longlong *)(param_1 + 0x58);
                                                          if (lVar8 != 0) {
                                                            if (cRam0000000182eb79e1 == '\0') {
                                                              FUN_1802f2810(0x182d5e260);
                                                              LOCK();
                                                              UNLOCK();
                                                              cRam0000000182eb79e1 = '\x01';
                                                            }
                                                            **(longlong **)
                                                              (lRam0000000182d5e260 + 0xb8) = lVar8;
                                                            FUN_18031d480(*(undefined8 *)
                                                                           (lRam0000000182d5e260 +
                                                                           0xb8));
                                                            lVar8 = *(longlong *)(param_1 + 0x98);
                                                            if (lVar8 != 0) {
                                                              if (cRam0000000182eb821f == '\0') {
                                                                FUN_1802f2810(0x182d5ae40);
                                                                LOCK();
                                                                UNLOCK();
                                                                FUN_1802f2810(0x182d58138);
                                                                LOCK();
                                                                UNLOCK();
                                                                FUN_1802f2810(0x182d5ae38);
                                                                LOCK();
                                                                UNLOCK();
                                                                FUN_1802f2810(0x182d58130);
                                                                LOCK();
                                                                UNLOCK();
                                                                FUN_1802f2810(0x182d583a0);
                                                                LOCK();
                                                                UNLOCK();
                                                                FUN_1802f2810(0x182d6c2f0);
                                                                LOCK();
                                                                UNLOCK();
                                                                FUN_1802f2810(0x182d6c2e8);
                                                                LOCK();
                                                                UNLOCK();
                                                                cRam0000000182eb821f = '\x01';
                                                              }
                                                              lVar9 = FUN_180498cf0();
                                                              if (lVar9 == 0) {
                                                                FUN_18060d0d0(lVar8);
                                                                uVar7 = FUN_1802c43a0(
                                                  uRam0000000182d5ae40);
                                                  FUN_180665bb0(uVar7,lVar8,uRam0000000182d6c2f0,0);
                                                  if (*(int *)(lRam0000000182d583a0 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  FUN_180993250(uVar7,0,uRam0000000182d5ae38);
                                                  uVar7 = FUN_1802c43a0(uRam0000000182d58138);
                                                  FUN_180665bb0(uVar7,lVar8,uRam0000000182d6c2e8,0);
                                                  FUN_180993250(uVar7,0,uRam0000000182d58130);
                                                  }
                                                  if (*(longlong *)(param_1 + 0x28) != 0) {
                                                    lVar8 = *(longlong *)
                                                             (*(longlong *)(param_1 + 0x28) + 0x80);
                                                    lVar9 = *(longlong *)
                                                             (*(longlong *)(param_1 + 0x28) + 0x98);
                                                    if (lVar9 != 0) {
                                                      uVar7 = FUN_1804aade0(lVar9,0);
                                                      if ((*(longlong *)(param_1 + 0x28) != 0) &&
                                                         (uVar10 = *(undefined8 *)
                                                                    (*(longlong *)(param_1 + 0x28) +
                                                                    0xa0), lVar8 != 0)) {
                                                        if (cRam0000000182eb7a49 == '\0') {
                                                          FUN_1802f2810(0x182d58370);
                                                          LOCK();
                                                          UNLOCK();
                                                          FUN_1802f2810(0x182d58348);
                                                          LOCK();
                                                          UNLOCK();
                                                          FUN_1802f2810(0x182d583a0);
                                                          LOCK();
                                                          UNLOCK();
                                                          FUN_1802f2810(0x182d5fdf8);
                                                          LOCK();
                                                          UNLOCK();
                                                          cRam0000000182eb7a49 = '\x01';
                                                        }
                                                        uVar11 = FUN_1802c43a0(uRam0000000182d58370)
                                                        ;
                                                        FUN_180665bb0(uVar11,lVar8,
                                                                      uRam0000000182d5fdf8,0);
                                                        if (*(int *)(lRam0000000182d583a0 + 0xe0) ==
                                                            0) {
                                                          FUN_18035c820();
                                                        }
                                                        FUN_180993250(uVar11,0,uRam0000000182d58348)
                                                        ;
                                                        *(undefined8 *)(lVar8 + 0x20) = uVar7;
                                                        FUN_18031d480(lVar8 + 0x20);
                                                        *(undefined8 *)(lVar8 + 0x28) = uVar10;
                                                        FUN_18031d480(lVar8 + 0x28);
                                                        FUN_1804a8950(lVar8,0,0);
                                                        if (((*(longlong *)(param_1 + 0x28) != 0) &&
                                                            (lVar8 = *(longlong *)
                                                                      (*(longlong *)(param_1 + 0x28)
                                                                      + 0x88), lVar8 != 0)) &&
                                                           (FUN_180494dc0(lVar8,0),
                                                           *(longlong *)(param_1 + 0x70) != 0)) {
                                                          FUN_1804c1f90();
                                                          if ((*(longlong *)(param_1 + 0x28) != 0)
                                                             && (lVar8 = *(longlong *)
                                                                          (param_1 + 0x80),
                                                                lVar8 != 0)) {
                                                            *(undefined8 *)(lVar8 + 0x10) =
                                                                 *(undefined8 *)
                                                                  (*(longlong *)(param_1 + 0x28) +
                                                                  0x50);
                                                            FUN_18031d480(lVar8 + 0x10);
                                                            if (*(int *)(lRam0000000182d58080 + 0xe0
                                                                        ) == 0) {
                                                              FUN_18035c820(lRam0000000182d58080);
                                                            }
                                                            lVar8 = *(longlong *)
                                                                     (*(longlong *)
                                                                       (lRam0000000182d58080 + 0xb8)
                                                                     + 0x10);
                                                            if (lVar8 != 0) {
                                                              *(undefined1 *)(lVar8 + 0x10) = 0;
                                                              uVar7 = *(undefined8 *)
                                                                       (*(longlong *)
                                                                         (lRam0000000182d58080 +
                                                                         0xb8) + 0x10);
                                                              if (*(int *)(lRam0000000182d583a0 +
                                                                          0xe0) == 0) {
                                                                FUN_18035c820();
                                                              }
                                                              FUN_1804b1f70(uVar7,0);
                                                              lVar8 = FUN_181f3f030(
                                                  uRam0000000182d5d688,0);
                                                  if (((lVar8 != 0) &&
                                                      (lVar8 = FUN_1809a08f0(lVar8,
                                                  uRam0000000182d5d6f0), lVar8 != 0)) &&
                                                  (lVar9 = *(longlong *)
                                                            (*(longlong *)
                                                              (lRam0000000182d58398 + 0xb8) + 0x48),
                                                  lVar9 != 0)) {
                                                    if (*(int *)(lVar8 + 0x20) ==
                                                        *(int *)(lVar9 + 0x10)) {
                                                      if (*(longlong *)(param_1 + 0x28) == 0)
                                                      goto code_r0x000180497e68;
                                                      lVar8 = *(longlong *)
                                                               (*(longlong *)(param_1 + 0x28) + 0x30
                                                               );
                                                      lVar9 = *(longlong *)
                                                               (*(longlong *)
                                                                 (lRam0000000182d58398 + 0xb8) +
                                                               0x48);
                                                      if (lVar8 == 0) goto code_r0x000180497e68;
                                                      uStack_28 = *(undefined4 *)(lVar9 + 0x18c);
                                                      uStack_24 = *(undefined4 *)(lVar9 + 400);
                                                      uStack_20 = *(undefined4 *)(lVar9 + 0x194);
                                                      uStack_1c = *(undefined4 *)(lVar9 + 0x198);
                                                      uStack_38 = *(undefined8 *)(lVar9 + 0x180);
                                                      puStack_30 = (undefined *)
                                                                   CONCAT44(puStack_30._4_4_,
                                                                            *(undefined4 *)
                                                                             (lVar9 + 0x188));
                                                      FUN_1806455f0(lVar8,&uStack_38,&uStack_28,0);
                                                    }
                                                    else {
                                                      lVar8 = *(longlong *)
                                                               (*(longlong *)
                                                                 (lRam0000000182d58398 + 0xb8) +
                                                               0x48);
                                                      lVar9 = FUN_181f3f030(uRam0000000182d5d688,0);
                                                      if (((lVar9 == 0) ||
                                                          (lVar9 = FUN_1809a08f0(lVar9,
                                                  uRam0000000182d5d6f0), lVar9 == 0)) ||
                                                  (lVar8 == 0)) goto code_r0x000180497e68;
                                                  *(undefined4 *)(lVar8 + 0x10) =
                                                       *(undefined4 *)(lVar9 + 0x20);
                                                  }
                                                  if ((*(longlong *)(param_1 + 0x28) != 0) &&
                                                     (lVar8 = *(longlong *)
                                                               (*(longlong *)(param_1 + 0x28) + 0x40
                                                               ), lVar8 != 0)) {
                                                    FUN_180462600(lVar8,0);
                                                    uVar7 = FUN_1802c43a0(uRam0000000182d58368);
                                                    FUN_1814df680(uVar7,param_1,uRam0000000182d5d6c0
                                                                  ,0);
                                                    FUN_1804b3c60(uVar7,2,0);
                                                    lVar8 = FUN_180498ef0();
                                                    if (lVar8 != 0) {
                                                      FUN_1804b75c0(lVar8,0);
                                                      if (*(int *)(lRam0000000182d59ac8 + 0xe0) == 0
                                                         ) {
                                                        FUN_18035c820();
                                                      }
                                                      FUN_1804869f0(0);
                                                      if (**(longlong **)
                                                            (lRam0000000182d58238 + 0xb8) != 0) {
                                                        lVar8 = *(longlong *)
                                                                 (**(longlong **)
                                                                    (lRam0000000182d58238 + 0xb8) +
                                                                 0x300);
                                                        if (*(int *)(lRam0000000182d5bfa0 + 0xe0) ==
                                                            0) {
                                                          FUN_18035c820(lRam0000000182d5bfa0);
                                                        }
                                                        uVar15 = 0x3c23d70a;
                                                        if (*(char *)(*(longlong *)
                                                                       (lRam0000000182d5bfa0 + 0xb8)
                                                                     + 3) == '\0') {
                                                          uVar14 = 0x3be21965;
                                                        }
                                                        else {
                                                          uVar14 = 0x3c23d70a;
                                                        }
                                                        if (lVar8 != 0) {
                                                          FUN_181f11730(lVar8,uRam0000000182d5d698,
                                                                        uVar14,0);
                                                          if (**(longlong **)
                                                                (lRam0000000182d58238 + 0xb8) != 0)
                                                          {
                                                            lVar8 = *(longlong *)
                                                                     (**(longlong **)
                                                                        (lRam0000000182d58238 + 0xb8
                                                                        ) + 0x308);
                                                            if (*(int *)(lRam0000000182d5bfa0 + 0xe0
                                                                        ) == 0) {
                                                              FUN_18035c820(lRam0000000182d5bfa0);
                                                            }
                                                            if (*(char *)(*(longlong *)
                                                                           (lRam0000000182d5bfa0 +
                                                                           0xb8) + 3) == '\0') {
                                                              uVar15 = 0x3b8ce704;
                                                            }
                                                            if (lVar8 != 0) {
                                                              FUN_181f11730(lVar8,
                                                  uRam0000000182d5d698,uVar15,0);
                                                  if (*(int *)(lRam0000000182d5bfa0 + 0xe0) == 0) {
                                                    FUN_18035c820(lRam0000000182d5bfa0);
                                                  }
                                                  if (*(char *)(*(longlong *)
                                                                 (lRam0000000182d5bfa0 + 0xb8) + 3)
                                                      != '\0') {
                                                    if (((*(longlong *)(param_1 + 0x28) == 0) ||
                                                        (lVar8 = *(longlong *)
                                                                  (*(longlong *)(param_1 + 0x28) +
                                                                  0xa0), lVar8 == 0)) ||
                                                       (lVar8 = FUN_1809a08f0(lVar8,
                                                  uRam0000000182d5d6f8), lVar8 == 0))
                                                  goto DAT_180497e56;
                                                  uVar5 = FUN_181efb420(lVar8,0);
                                                  if (*(int *)(lRam0000000182d582a0 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  if (cRam0000000182eb7ace == '\0') {
                                                    FUN_1802f2810(0x182d582a0);
                                                    LOCK();
                                                    UNLOCK();
                                                    FUN_1802f2810(0x182d5f560);
                                                    LOCK();
                                                    UNLOCK();
                                                    cRam0000000182eb7ace = '\x01';
                                                  }
                                                  if (*(int *)(lRam0000000182d582a0 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  if (*(int *)(*(longlong *)
                                                                (lRam0000000182d582a0 + 0xb8) + 0x34
                                                              ) == -1) {
                                                    uVar15 = FUN_181f3f150(uRam0000000182d5f560,0);
                                                    if (*(int *)(lRam0000000182d582a0 + 0xe0) == 0)
                                                    {
                                                      FUN_18035c820();
                                                    }
                                                    *(undefined4 *)
                                                     (*(longlong *)(lRam0000000182d582a0 + 0xb8) +
                                                     0x34) = uVar15;
                                                  }
                                                  if (*(int *)(lRam0000000182d582a0 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  FUN_181efb470(lVar8,uVar5 | 1 << (*(uint *)(*(
                                                  longlong *)(lRam0000000182d582a0 + 0xb8) + 0x34) &
                                                  0x1f),0);
                                                  }
                                                  return;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
DAT_180497e56:
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
code_r0x000180497e68:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

