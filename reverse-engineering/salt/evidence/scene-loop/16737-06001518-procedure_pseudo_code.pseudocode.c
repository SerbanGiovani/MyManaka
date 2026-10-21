// Ghidra pseudocode; not original source or compilable C.
// ev_68f69535b042bdbca06d9b824f79f2f07253beec3dc12e5ce7b39c6056c0f183

void ExposureUnnoticed2_Scripts_InGame_EventMethodManager__Update__06001518(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong *plVar5;
  char cVar6;
  undefined8 *puVar7;
  ushort uVar8;
  uint uVar9;
  undefined8 uStack_40;
  undefined4 *puStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  longlong *plStack_18;
  
  if (cRam0000000182eb7981 == '\0') {
    FUN_1802f2810(0x182d5def0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dee8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dee0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ded8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ded0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7981 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182eb54a7 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    cRam0000000182eb54a7 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (**(longlong **)(DAT_182d5aa88 + 0xb8) != 0) {
    ExposureUnnoticed2_Scripts_Base_InputManager__UpdateProcess__06001700
              (**(longlong **)(DAT_182d5aa88 + 0xb8),0);
    lVar3 = *(longlong *)(param_1 + 0x28);
    if (lVar3 != 0) {
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
        cVar6 = FUN_180f72b70(&uStack_28,uRam0000000182d5dee8);
        plVar5 = plStack_18;
        if (cVar6 == '\0') {
          return;
        }
        if (plStack_18 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        lVar3 = *plStack_18;
        uVar8 = 0;
        if (*(ushort *)(lVar3 + 0x12e) != 0) {
          do {
            if (*(longlong *)(*(longlong *)(lVar3 + 0xb0) + (ulonglong)uVar8 * 0x10) ==
                lRam0000000182d5ded8) {
              puVar7 = (undefined8 *)
                       ((longlong)
                        *(int *)(*(longlong *)(lVar3 + 0xb0) + 8 + (ulonglong)uVar8 * 0x10) * 0x10 +
                        0x138 + lVar3);
              goto code_r0x00018048b709;
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < *(ushort *)(lVar3 + 0x12e));
        }
        puVar7 = (undefined8 *)FUN_180320910(plStack_18,lRam0000000182d5ded8,0);
code_r0x00018048b709:
        (*(code *)*puVar7)(plVar5,puVar7[1]);
      } while( true );
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

