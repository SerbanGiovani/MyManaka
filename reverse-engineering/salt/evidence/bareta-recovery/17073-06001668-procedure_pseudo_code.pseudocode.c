// Ghidra pseudocode; not original source or compilable C.
// ev_fbbeeae0772a6b801f27c0f7e9faf840b770d1f1a8b1dee735bbeb07d3f87d38

void ExposureUnnoticed2_Scripts_InGame_StageTransController__TransStageIfInCondition__06001668
               (longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined8 param_5)

{
  ulonglong uVar1;
  undefined8 uVar2;
  char cVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  uint uVar8;
  bool bVar9;
  undefined8 uStack_78;
  undefined8 uStack_70;
  longlong lStack_68;
  undefined8 uStack_58;
  undefined8 uStack_50;
  longlong alStack_48 [2];
  undefined8 uStack_38;
  undefined8 uStack_30;
  longlong lStack_28;
  
  if (cRam0000000182eb7a3a == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e258);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fed0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fec8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fec0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5feb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5feb0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fea8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fea0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52e20);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a3a = '\x01';
  }
  lVar4 = FUN_1802c43a0(uRam0000000182d5fec0);
  if (lVar4 != 0) {
    bVar9 = DAT_182eb5d50 != 0;
    *(undefined8 *)(lVar4 + 0x18) = param_5;
    *(undefined4 *)(lVar4 + 0x10) = param_2;
    *(undefined4 *)(lVar4 + 0x14) = param_3;
    if (bVar9) {
      uVar8 = (uint)(lVar4 + 0x18U >> 0xc);
      lVar7 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar7);
        LOCK();
        bVar9 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar7);
        if (bVar9) {
          *(ulonglong *)(&DAT_182f0c920 + lVar7) = uVar1 | 1L << (uVar8 & 0x3f);
        }
        UNLOCK();
      } while (!bVar9);
    }
    cVar3 = ExposureUnnoticed2_Scripts_InGame_StageTransController__IsAbleTransStage__06001667
                      (param_1,0);
    if (cVar3 == '\0') {
      return;
    }
    *(undefined4 *)(param_1 + 0x10) = param_4;
    if (**(longlong **)(lRam0000000182d5e258 + 0xb8) != 0) {
      if (cRam0000000182eb7962 == '\0') {
        FUN_1802f2810(&DAT_182d58398);
        LOCK();
        UNLOCK();
        cRam0000000182eb7962 = '\x01';
      }
      lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar7 != 0) {
        if ((*(int *)(lVar7 + 0xbc) != -1) && (*(int *)(lVar4 + 0x14) == 0)) {
          uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(DAT_182d52e20,0);
          uVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d5fea8,0)
          ;
          uStack_50 = uRam0000000182d5fea0;
          uStack_58 = 0;
          alStack_48[0] = 0;
          if (DAT_182eb5d50 != 0) {
            uVar8 = (uint)((ulonglong)&uStack_50 >> 0xc);
            lVar7 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
            do {
              uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar7);
              LOCK();
              bVar9 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar7);
              if (bVar9) {
                *(ulonglong *)(&DAT_182f0c920 + lVar7) = uVar1 | 1L << (uVar8 & 0x3f);
              }
              UNLOCK();
            } while (!bVar9);
          }
          if (*(int *)(lRam0000000182d5feb8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          lVar7 = *(longlong *)(*(longlong *)(lRam0000000182d5feb8 + 0xb8) + 8);
          if (lVar7 == 0) {
            if (*(int *)(lRam0000000182d5feb8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar2 = **(undefined8 **)(lRam0000000182d5feb8 + 0xb8);
            lVar7 = FUN_1802c43a0(DAT_182d58368);
            FUN_1814df680(lVar7,uVar2,uRam0000000182d5fed0,0);
            *(longlong *)(*(longlong *)(lRam0000000182d5feb8 + 0xb8) + 8) = lVar7;
            FUN_18031d480(*(longlong *)(lRam0000000182d5feb8 + 0xb8) + 8);
          }
          alStack_48[0] = lVar7;
          FUN_18031d480(alStack_48);
          lStack_68 = alStack_48[0];
          uStack_78 = uStack_58;
          uStack_58 = 0;
          uStack_70 = uStack_50;
          uStack_50 = uRam0000000182d5feb0;
          alStack_48[0] = 0;
          if (DAT_182eb5d50 != 0) {
            uVar8 = (uint)((ulonglong)&uStack_50 >> 0xc);
            lVar7 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
            do {
              uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar7);
              LOCK();
              bVar9 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar7);
              if (bVar9) {
                *(ulonglong *)(&DAT_182f0c920 + lVar7) = uVar1 | 1L << (uVar8 & 0x3f);
              }
              UNLOCK();
            } while (!bVar9);
          }
          lVar7 = FUN_1802c43a0(DAT_182d58368);
          FUN_1814df680(lVar7,lVar4,uRam0000000182d5fec8,0);
          if (DAT_182eb5d50 != 0) {
            uVar8 = (uint)((ulonglong)alStack_48 >> 0xc);
            lVar4 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
            do {
              uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
              LOCK();
              bVar9 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
              if (bVar9) {
                *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar1 | 1L << (uVar8 & 0x3f);
              }
              UNLOCK();
            } while (!bVar9);
          }
          uStack_38 = uStack_58;
          uStack_30 = uStack_50;
          alStack_48[0] = lVar7;
          lStack_28 = lVar7;
          ExposureUnnoticed2_ObjectUI_CommonPopup_CommonPopupView__Open__06001dc2
                    (uVar5,uVar6,&uStack_78,&uStack_38,0,0);
          return;
        }
        __c__DisplayClass5_0___TransStageIfInCondition_g__TransStageProcess_0__06001671(lVar4,0);
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

