// Ghidra pseudocode; not original source or compilable C.
// ev_56d99ea46c12d3424ee3fe7c17bcd9551a78ea7c3cbdc5c2f0d52d479b6f8b05

void ExposureUnnoticed2_Scripts_Base_InputManager__Awake__060016fc(undefined8 param_1)

{
  int iVar1;
  ulonglong uVar2;
  longlong *plVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  code *pcVar8;
  undefined8 uVar9;
  uint uVar10;
  bool bVar11;
  undefined8 uStack_50;
  undefined4 *puStack_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  int iStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  
  if (cRam0000000182eb7a88 == '\0') {
    FUN_1802f2810(0x182d5fb30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fb28);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fb20);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fb18);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59f58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fb10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fb00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5faf8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fb40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5faf0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fae8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fae0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fad8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fac8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fac0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fab8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fab0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5faa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5faa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fa98);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a88 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (*(char *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0xb) != '\0') {
    pcVar8 = DAT_182ec1088;
    if ((DAT_182ec1088 == (code *)0x0) &&
       (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
       pcVar8 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec1088 = pcVar8;
    uVar4 = (*DAT_182ec1088)(param_1);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    FUN_181f43e80(uVar4,0);
    return;
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  *(undefined1 *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0xb) = 1;
  FUN_1804c23f0(param_1);
  uVar4 = uRam0000000182d5fac0;
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  plVar3 = (longlong *)FUN_181638ed0(uVar4,0);
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
  if (plVar3 == (longlong *)0x0) {
    uVar4 = thunk_FUN_1802f2810(&DAT_182d528c8);
    uVar4 = thunk_FUN_1802c43a0(uVar4);
    uVar9 = thunk_FUN_1802f2810(&DAT_182d27920);
    FUN_1815c6a10(uVar4,uVar9,0);
    uVar9 = thunk_FUN_1802f2810(&DAT_182d28d98);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar4,uVar9);
  }
  uVar4 = (**(code **)(*plVar3 + 0x898))(plVar3,*(undefined8 *)(*plVar3 + 0x8a0));
  uVar4 = FUN_18093ca00(uVar4,uRam0000000182d5fb10);
  if (*(int *)(lRam0000000182d5faa0 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5faa0);
  }
  lVar5 = *(longlong *)(*(longlong *)(lRam0000000182d5faa0 + 0xb8) + 8);
  if (lVar5 == 0) {
    if (*(int *)(lRam0000000182d5faa0 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d5faa0);
    }
    uVar9 = **(undefined8 **)(lRam0000000182d5faa0 + 0xb8);
    lVar5 = FUN_1802c43a0(uRam0000000182d5fad8);
    FUN_1810d47d0(lVar5,uVar9,uRam0000000182d5fab0,0);
    *(longlong *)(*(longlong *)(lRam0000000182d5faa0 + 0xb8) + 8) = lVar5;
    if (DAT_182eb5d50 != 0) {
      uVar10 = (uint)(*(longlong *)(lRam0000000182d5faa0 + 0xb8) + 8U >> 0xc);
      lVar6 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
        LOCK();
        bVar11 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
        if (bVar11) {
          *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar2 | 1L << (uVar10 & 0x3f);
        }
        UNLOCK();
      } while (!bVar11);
    }
  }
  if (*(int *)(lRam0000000182d5faa0 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5faa0);
  }
  lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d5faa0 + 0xb8) + 0x10);
  if (lVar6 == 0) {
    if (*(int *)(lRam0000000182d5faa0 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d5faa0);
    }
    uVar9 = **(undefined8 **)(lRam0000000182d5faa0 + 0xb8);
    lVar6 = FUN_1802c43a0(uRam0000000182d5fae0);
    FUN_1810d4970(lVar6,uVar9,uRam0000000182d5faa8,0);
    *(longlong *)(*(longlong *)(lRam0000000182d5faa0 + 0xb8) + 0x10) = lVar6;
    if (DAT_182eb5d50 != 0) {
      uVar10 = (uint)(*(longlong *)(lRam0000000182d5faa0 + 0xb8) + 0x10U >> 0xc);
      lVar7 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar7);
        LOCK();
        bVar11 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar7);
        if (bVar11) {
          *(ulonglong *)(&DAT_182f0c920 + lVar7) = uVar2 | 1L << (uVar10 & 0x3f);
        }
        UNLOCK();
      } while (!bVar11);
    }
  }
  lVar7 = lRam0000000182d5fb00;
  if (*(longlong *)(lRam0000000182d5fb00 + 0x38) == 0) {
    FUN_1803204f0(lRam0000000182d5fb00);
  }
  uVar4 = FUN_18098ac90(uVar4,lVar5,lVar6,0,*(undefined8 *)(*(longlong *)(lVar7 + 0x38) + 0x18));
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  *(undefined8 *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x10) = uVar4;
  if (DAT_182eb5d50 != 0) {
    uVar10 = (uint)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x10U >> 0xc);
    lVar5 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
      LOCK();
      bVar11 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
      if (bVar11) {
        *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar2 | 1L << (ulonglong)(uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar11);
  }
  uVar4 = FUN_180735660(param_1,uRam0000000182d5fb30);
  *(undefined8 *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x18) = uVar4;
  if (DAT_182eb5d50 != 0) {
    uVar10 = (uint)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x18U >> 0xc);
    lVar5 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
      LOCK();
      bVar11 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
      if (bVar11) {
        *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar2 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar11);
  }
  lVar5 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x18);
  if (((lVar5 != 0) && (lVar5 = *(longlong *)(lVar5 + 0x90), lVar5 != 0)) &&
     (lVar5 = FUN_181952d80(lVar5,DAT_182d5fa98,0), lVar5 != 0)) {
    FUN_1800067d0(lVar5);
    uVar4 = uRam0000000182d5fac0;
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    plVar3 = (longlong *)FUN_181638ed0(uVar4,0);
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
    if (plVar3 == (longlong *)0x0) {
      uVar4 = thunk_FUN_1802f2810(&DAT_182d528c8);
      uVar4 = thunk_FUN_1802c43a0(uVar4);
      uVar9 = thunk_FUN_1802f2810(&DAT_182d27920);
      FUN_1815c6a10(uVar4,uVar9,0);
      uVar9 = thunk_FUN_1802f2810(&DAT_182d28d98);
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar4,uVar9);
    }
    uVar4 = (**(code **)(*plVar3 + 0x898))(plVar3,*(undefined8 *)(*plVar3 + 0x8a0));
    lVar6 = FUN_18093ca00(uVar4,uRam0000000182d5fb10);
    lVar5 = lRam0000000182d5faf8;
    if (*(longlong *)(lRam0000000182d5faf8 + 0x38) == 0) {
      FUN_1803204f0(lRam0000000182d5faf8);
    }
    if (lVar6 == 0) {
      uVar4 = thunk_FUN_1802f2810(&DAT_182d438a8);
      uVar4 = FUN_1816e95a0(uVar4,0);
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar4,lVar5);
    }
    lVar7 = *(longlong *)(*(longlong *)(lVar5 + 0x38) + 8);
    if ((*(byte *)(lVar7 + 0x135) & 1) == 0) {
      lVar7 = FUN_180320470(lVar7);
    }
    uVar4 = FUN_1802c43a0(lVar7);
    FUN_181257f90(uVar4,lVar6,*(undefined8 *)(*(longlong *)(lVar5 + 0x38) + 0x10));
    *(undefined8 *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x20) = uVar4;
    if (DAT_182eb5d50 != 0) {
      uVar10 = (uint)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x20U >> 0xc);
      lVar5 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
        LOCK();
        bVar11 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
        if (bVar11) {
          *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar2 | 1L << (ulonglong)(uVar10 & 0x3f);
        }
        UNLOCK();
      } while (!bVar11);
    }
    uVar4 = FUN_1802c43a0(uRam0000000182d5fb18);
    FUN_180e686d0(uVar4,uRam0000000182d5fb20);
    *(undefined8 *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x28) = uVar4;
    if (DAT_182eb5d50 != 0) {
      uVar10 = (uint)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x28U >> 0xc);
      lVar5 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
        LOCK();
        bVar11 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
        if (bVar11) {
          *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar2 | 1L << (ulonglong)(uVar10 & 0x3f);
        }
        UNLOCK();
      } while (!bVar11);
    }
    uVar4 = FUN_1802c43a0(uRam0000000182d5fb18);
    FUN_180e686d0(uVar4,uRam0000000182d5fb20);
    *(undefined8 *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x30) = uVar4;
    if (DAT_182eb5d50 != 0) {
      uVar10 = (uint)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x30U >> 0xc);
      lVar5 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
        LOCK();
        bVar11 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
        if (bVar11) {
          *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar2 | 1L << (uVar10 & 0x3f);
        }
        UNLOCK();
      } while (!bVar11);
    }
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x20);
    if (lVar5 != 0) {
      if (DAT_182eb5d50 != 0) {
        uVar10 = (uint)((ulonglong)&uStack_50 >> 0xc);
        lVar6 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
          LOCK();
          bVar11 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
          if (bVar11) {
            *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar2 | 1L << (uVar10 & 0x3f);
          }
          UNLOCK();
        } while (!bVar11);
      }
      iStack_2c = *(int *)(lVar5 + 0x1c);
      uStack_40 = 0;
      uStack_3c = 0;
      uStack_50._0_4_ = (undefined4)lVar5;
      uStack_50._4_4_ = (undefined4)((ulonglong)lVar5 >> 0x20);
      uStack_38 = (undefined4)uStack_50;
      uStack_34 = uStack_50._4_4_;
      uStack_30 = 0;
      iStack_28 = 0;
      uStack_24 = 0;
      uStack_50 = 0;
      puStack_48 = &uStack_38;
      do {
        lVar5 = CONCAT44(uStack_34,uStack_38);
        do {
          if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          if ((iStack_2c != *(int *)(lVar5 + 0x1c)) || (*(uint *)(lVar5 + 0x18) <= uStack_30)) {
            if ((*(byte *)(*(longlong *)(DAT_182d5faf0 + 0x20) + 0x135) & 1) == 0) {
              FUN_180320470(*(longlong *)(DAT_182d5faf0 + 0x20));
              lVar5 = CONCAT44(uStack_34,uStack_38);
            }
            if (lVar5 != 0) {
              if (iStack_2c == *(int *)(lVar5 + 0x1c)) {
                return;
              }
                    /* WARNING: Subroutine does not return */
              FUN_18163fef0(0);
            }
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          lVar6 = *(longlong *)(lVar5 + 0x10);
          if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          if (*(uint *)(lVar6 + 0x18) <= uStack_30) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
          iVar1 = *(int *)(lVar6 + 0x20 + (longlong)(int)uStack_30 * 4);
          uStack_30 = uStack_30 + 1;
          iStack_28 = iVar1;
        } while (iVar1 == -1);
        if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d5aa88);
        }
        lVar5 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x28);
        if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        FUN_180e72490(lVar5,iVar1,0,2,
                      *(undefined8 *)
                       (*(longlong *)(*(longlong *)(lRam0000000182d5fb28 + 0x20) + 0xc0) + 0x100));
        lVar5 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x30);
        if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        FUN_180e72490(lVar5,iVar1,0,2,
                      *(undefined8 *)
                       (*(longlong *)(*(longlong *)(lRam0000000182d5fb28 + 0x20) + 0xc0) + 0x100));
      } while( true );
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

