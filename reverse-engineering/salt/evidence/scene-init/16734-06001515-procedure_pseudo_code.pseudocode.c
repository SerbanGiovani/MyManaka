// Ghidra pseudocode; not original source or compilable C.
// ev_ec904a81f2aed5405b91c9857ed05b53ea5d472f175006c1df1a41068761dc1e

void ExposureUnnoticed2_Scripts_InGame_EventMethodManager__Initialize__06001515
               (longlong param_1,longlong param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  char cVar8;
  ushort uVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  uint uVar12;
  bool bVar13;
  undefined8 uStack_40;
  undefined1 *puStack_38;
  undefined *puStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  longlong *plStack_18;
  
  if (cRam0000000182eb797e == '\0') {
    puStack_30 = &UNK_18048b025;
    FUN_1802f2810(0x182d5df30);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_18048b036;
    FUN_1802f2810(0x182d5df28);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_18048b047;
    FUN_1802f2810(0x182d5df20);
    LOCK();
    UNLOCK();
    cRam0000000182eb797e = '\x01';
  }
  bVar13 = DAT_182eb5d50 != 0;
  *(longlong *)(param_1 + 0x38) = param_2;
  if (bVar13) {
    uVar12 = (uint)(param_1 + 0x38U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar12 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  lVar6 = lRam0000000182d5df20;
  lVar4 = *(longlong *)(param_1 + 0x20);
  if ((param_2 != 0) && (uVar10 = *(undefined8 *)(param_2 + 0x40), lVar4 != 0)) {
    *(int *)(lVar4 + 0x1c) = *(int *)(lVar4 + 0x1c) + 1;
    lVar5 = *(longlong *)(lVar4 + 0x10);
    if (lVar5 != 0) {
      uVar12 = *(uint *)(lVar4 + 0x18);
      if (uVar12 < *(uint *)(lVar5 + 0x18)) {
        *(uint *)(lVar4 + 0x18) = uVar12 + 1;
        puStack_30 = &UNK_18048b10f;
        FUN_180002cd0(lVar5,(longlong)(int)uVar12,uVar10);
      }
      else {
        puStack_30 = &UNK_18048b0f8;
        FUN_1812741c0(lVar4,uVar10,
                      *(undefined8 *)(*(longlong *)(*(longlong *)(lVar6 + 0x20) + 0xc0) + 0x70));
      }
      lVar4 = *(longlong *)(param_1 + 0x28);
      puStack_30 = &UNK_18048b11a;
      uVar10 = ExposureUnnoticed2_Scripts_Base_CursorController__get_Instance__06001766(0);
      if (lVar4 != 0) {
        puStack_30 = &UNK_18048b12e;
        FUN_180005dd0(lVar4,uVar10);
        if (*(longlong *)(param_1 + 0x28) != 0) {
          puStack_30 = &UNK_18048b144;
          FUN_180005dd0(*(longlong *)(param_1 + 0x28),*(undefined8 *)(param_2 + 0x20));
          if (*(longlong *)(param_1 + 0x28) != 0) {
            puStack_30 = &UNK_18048b15a;
            FUN_180005dd0(*(longlong *)(param_1 + 0x28),*(undefined8 *)(param_2 + 0x30));
            if (*(longlong *)(param_1 + 0x28) != 0) {
              puStack_30 = &UNK_18048b16c;
              FUN_180005dd0(*(longlong *)(param_1 + 0x28),*(undefined8 *)(param_2 + 0x50));
              if (*(longlong *)(param_1 + 0x28) != 0) {
                puStack_30 = &UNK_18048b17e;
                FUN_180005dd0(*(longlong *)(param_1 + 0x28),*(undefined8 *)(param_2 + 0x70));
                if (*(longlong *)(param_1 + 0x30) != 0) {
                  puStack_30 = &UNK_18048b190;
                  FUN_180005e30(*(longlong *)(param_1 + 0x30),*(undefined8 *)(param_2 + 0x30));
                  if (*(longlong *)(param_1 + 0x30) != 0) {
                    puStack_30 = &UNK_18048b1a2;
                    FUN_180005e30(*(longlong *)(param_1 + 0x30),*(undefined8 *)(param_2 + 0x50));
                    if (*(longlong *)(param_1 + 0x30) != 0) {
                      puStack_30 = &UNK_18048b1b4;
                      FUN_180005e30(*(longlong *)(param_1 + 0x30),*(undefined8 *)(param_2 + 0x28));
                      if (*(longlong *)(param_1 + 0x30) != 0) {
                        puStack_30 = &UNK_18048b1c6;
                        FUN_180005e30(*(longlong *)(param_1 + 0x30),*(undefined8 *)(param_2 + 0x20))
                        ;
                        if (cRam0000000182eb797f == '\0') {
                          FUN_1802f2810(0x182d5df18,0);
                          LOCK();
                          UNLOCK();
                          FUN_1802f2810(0x182d5df10);
                          LOCK();
                          UNLOCK();
                          FUN_1802f2810(0x182d5df08);
                          LOCK();
                          UNLOCK();
                          FUN_1802f2810(0x182d5df00);
                          LOCK();
                          UNLOCK();
                          FUN_1802f2810(0x182d5def8);
                          LOCK();
                          UNLOCK();
                          cRam0000000182eb797f = '\x01';
                        }
                        lVar4 = *(longlong *)(param_1 + 0x20);
                        if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
                          FUN_18031dad0();
                        }
                        if (DAT_182eb5d50 != 0) {
                          uVar12 = (uint)((ulonglong)&uStack_40 >> 0xc);
                          puVar1 = (ulonglong *)
                                   (&DAT_182f0c920 + (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8);
                          do {
                            uVar3 = *puVar1;
                            LOCK();
                            uVar2 = *puVar1;
                            if (uVar3 == uVar2) {
                              *puVar1 = uVar3 | 1L << (uVar12 & 0x3f);
                            }
                            UNLOCK();
                          } while (uVar3 != uVar2);
                        }
                        uStack_1c = *(undefined4 *)(lVar4 + 0x1c);
                        puStack_30 = (undefined *)0x0;
                        uStack_40._0_4_ = (undefined4)lVar4;
                        uStack_40._4_4_ = (undefined4)((ulonglong)lVar4 >> 0x20);
                        uStack_28 = (undefined4)uStack_40;
                        uStack_24 = uStack_40._4_4_;
                        uStack_20 = 0;
                        plStack_18 = (longlong *)0x0;
                        uStack_40 = 0;
                        puStack_38 = (undefined1 *)&uStack_28;
                        do {
                          cVar8 = FUN_180f72b70(&uStack_28,uRam0000000182d5df10);
                          plVar7 = plStack_18;
                          if (cVar8 == '\0') {
                            return;
                          }
                          if (plStack_18 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                            FUN_18031dad0();
                          }
                          lVar4 = *plStack_18;
                          uVar9 = 0;
                          if (*(ushort *)(lVar4 + 0x12e) != 0) {
                            do {
                              if (*(longlong *)
                                   (*(longlong *)(lVar4 + 0xb0) + (ulonglong)uVar9 * 0x10) ==
                                  lRam0000000182d5df00) {
                                puVar11 = (undefined8 *)
                                          ((longlong)
                                           *(int *)(*(longlong *)(lVar4 + 0xb0) + 8 +
                                                   (ulonglong)uVar9 * 0x10) * 0x10 + 0x138 + lVar4);
                                goto code_r0x00018048b369;
                              }
                              uVar9 = uVar9 + 1;
                            } while (uVar9 < *(ushort *)(lVar4 + 0x12e));
                          }
                          puVar11 = (undefined8 *)FUN_180320910(plStack_18,lRam0000000182d5df00,0);
code_r0x00018048b369:
                          (*(code *)*puVar11)(plVar7,puVar11[1]);
                        } while( true );
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
  puStack_30 = &UNK_18048b1e4;
  FUN_18031dad0();
}

