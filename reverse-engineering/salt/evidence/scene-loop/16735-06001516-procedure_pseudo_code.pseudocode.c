// Ghidra pseudocode; not original source or compilable C.
// ev_4a82d6bc8484d66560fd08634599963e4c63b60a233c217caed16e2260cf2d4c

void ExposureUnnoticed2_Scripts_InGame_EventMethodManager__OnStart__06001516(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong *plVar5;
  char cVar6;
  ushort uVar7;
  undefined8 *puVar8;
  uint uVar9;
  undefined8 uStack_40;
  undefined4 *puStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  longlong *plStack_18;
  
  if (cRam0000000182eb797f == '\0') {
    FUN_1802f2810(0x182d5df18);
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
  lVar3 = *(longlong *)(param_1 + 0x20);
  if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (DAT_182eb5d50 != 0) {
    uVar9 = (uint)((ulonglong)&uStack_40 >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
    do {
      uVar4 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar4 == uVar2) {
        *puVar1 = uVar4 | 1L << (uVar9 & 0x3f);
      }
      UNLOCK();
    } while (uVar4 != uVar2);
  }
  uStack_1c = *(undefined4 *)(lVar3 + 0x1c);
  uStack_30 = 0;
  uStack_40._0_4_ = (undefined4)lVar3;
  uStack_40._4_4_ = (undefined4)((ulonglong)lVar3 >> 0x20);
  uStack_28 = (undefined4)uStack_40;
  uStack_24 = uStack_40._4_4_;
  uStack_20 = 0;
  plStack_18 = (longlong *)0x0;
  uStack_40 = 0;
  puStack_38 = &uStack_28;
  do {
    cVar6 = FUN_180f72b70(&uStack_28,uRam0000000182d5df10);
    plVar5 = plStack_18;
    if (cVar6 == '\0') {
      return;
    }
    if (plStack_18 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    lVar3 = *plStack_18;
    uVar7 = 0;
    if (*(ushort *)(lVar3 + 0x12e) != 0) {
      do {
        if (*(longlong *)(*(longlong *)(lVar3 + 0xb0) + (ulonglong)uVar7 * 0x10) ==
            lRam0000000182d5df00) {
          puVar8 = (undefined8 *)
                   ((longlong)*(int *)(*(longlong *)(lVar3 + 0xb0) + 8 + (ulonglong)uVar7 * 0x10) *
                    0x10 + 0x138 + lVar3);
          goto code_r0x00018048b369;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(ushort *)(lVar3 + 0x12e));
    }
    puVar8 = (undefined8 *)FUN_180320910(plStack_18,lRam0000000182d5df00,0);
code_r0x00018048b369:
    (*(code *)*puVar8)(plVar5,puVar8[1]);
  } while( true );
}

