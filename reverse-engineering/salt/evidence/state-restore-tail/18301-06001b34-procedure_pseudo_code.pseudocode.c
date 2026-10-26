// Ghidra pseudocode; not original source or compilable C.
// ev_3db91c7a98f5f688ff65f85a9c7a4e3cac90478f368c6682b986e9382bd15af7

void ExposureUnnoticed2_ObjectUI_InGame_Compass_CompassView__RegisterTarget__06001b34
               (longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  int *piVar9;
  bool bVar10;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 uStack_18;
  
  if (cRam0000000182eb7cfe == '\0') {
    FUN_1802f2810(&DAT_182d646b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d646b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7cfe = '\x01';
  }
  uStack_48 = 0;
  uStack_40 = 0;
  uStack_38 = 0;
  if (DAT_182eb54a2 == '\0') {
    FUN_1802f2810(&DAT_182d5bcb8);
    LOCK();
    UNLOCK();
    DAT_182eb54a2 = '\x01';
  }
  if (param_2 != 0) {
    iVar2 = *(int *)(param_2 + 0x34);
    if (**(longlong **)(DAT_182d5bcb8 + 0xb8) != 0) {
      lVar7 = *(longlong *)(**(longlong **)(DAT_182d5bcb8 + 0xb8) + 0x18);
      uVar6 = 0;
      if (lVar7 != 0) {
        piVar9 = (int *)(lVar7 + 0x20);
        for (; (int)uVar6 < (int)*(uint *)(lVar7 + 0x18); uVar6 = uVar6 + 1) {
          if (*(uint *)(lVar7 + 0x18) <= uVar6) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
          if (*piVar9 == iVar2) goto code_r0x000180511a15;
          piVar9 = piVar9 + 1;
        }
        if ((iVar2 != 5) && (iVar2 != 6)) {
          return;
        }
code_r0x000180511a15:
        uVar3 = *(undefined8 *)(param_1 + 0x58);
        uVar4 = *(undefined8 *)(param_1 + 0x50);
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar7 = FUN_1809f1050(uVar3,uVar4,DAT_182d54d90);
        if ((lVar7 != 0) && (lVar8 = FUN_1809a08f0(lVar7,DAT_182d646b8), lVar8 != 0)) {
          ExposureUnnoticed2_ObjectUI_InGame_Compass_CompassIconView__Initialize__06001b28
                    (lVar8,*(undefined4 *)(param_2 + 0x34),0);
          lVar8 = *(longlong *)(param_1 + 0x70);
          if (DAT_182eb5d50 != 0) {
            uVar6 = (uint)((ulonglong)&uStack_48 >> 0xc);
            lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
            do {
              uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
              LOCK();
              bVar10 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
              if (bVar10) {
                *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar5 | 1L << (uVar6 & 0x3f);
              }
              UNLOCK();
            } while (!bVar10);
          }
          if (DAT_182eb5d50 != 0) {
            uVar6 = (uint)((ulonglong)&uStack_40 >> 0xc);
            lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
            do {
              uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
              LOCK();
              bVar10 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
              if (bVar10) {
                *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar5 | 1L << (uVar6 & 0x3f);
              }
              UNLOCK();
            } while (!bVar10);
          }
          uStack_48 = param_2;
          uStack_40 = lVar7;
          if (lVar8 != 0) {
            uStack_48._0_4_ = (undefined4)param_2;
            uStack_48._4_4_ = (undefined4)((ulonglong)param_2 >> 0x20);
            uStack_40._0_4_ = (undefined4)lVar7;
            uStack_40._4_4_ = (undefined4)((ulonglong)lVar7 >> 0x20);
            uStack_28 = (undefined4)uStack_48;
            uStack_24 = uStack_48._4_4_;
            uStack_20 = (undefined4)uStack_40;
            uStack_1c = uStack_40._4_4_;
            uStack_18 = uStack_38;
            FUN_1800076e0(lVar8,&uStack_28,DAT_182d646b0);
            return;
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

