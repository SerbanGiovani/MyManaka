// Ghidra pseudocode; not original source or compilable C.
// ev_98b092abaf61120bee10047c16e8d5706fb52a14f359ad2e070e3e6c0918d647

void ExposureUnnoticed2_Object3D_Player_Scripts_Other_HairCustomAdjuster__InitializeIfNeed__06000e99
               (longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  char cVar6;
  longlong lVar7;
  undefined8 uVar8;
  uint uVar9;
  longlong *plVar10;
  bool bVar11;
  
  if (DAT_182eb767c == '\0') {
    FUN_1802f2810(&DAT_182d58300);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d581a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58198);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d582e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d581a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182eb767c = '\x01';
  }
  if (*(char *)(param_1 + 0x48) == '\0') {
    *(undefined1 *)(param_1 + 0x48) = 1;
    lVar7 = DAT_182d581a0;
    if (*(longlong *)(DAT_182d581a0 + 0x38) == 0) {
      FUN_1803204f0(DAT_182d581a0);
    }
    lVar7 = FUN_1807366b0(param_1,0,**(undefined8 **)(lVar7 + 0x38));
    uVar9 = 0;
    if (lVar7 == 0) {
LAB_180403a50:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    plVar10 = (longlong *)(lVar7 + 0x20);
    for (; (int)uVar9 < *(int *)(lVar7 + 0x18); uVar9 = uVar9 + 1) {
      if (*(uint *)(lVar7 + 0x18) <= uVar9) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      lVar3 = *plVar10;
      cVar6 = FUN_1809789e0(*(undefined8 *)(param_1 + 0x28),lVar3,DAT_182d58198);
      if (cVar6 == '\0') {
        lVar4 = *(longlong *)(param_1 + 0x40);
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (DAT_182ec12f3 == '\0') {
          FUN_1802f2810(&DAT_182d53aa8);
          LOCK();
          UNLOCK();
          DAT_182ec12f3 = '\x01';
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
        if (lVar4 == 0) {
LAB_180403950:
          if (lVar3 == 0) goto LAB_180403a50;
          uVar8 = FUN_181f0da90(lVar3,0);
          *(undefined8 *)(param_1 + 0x40) = uVar8;
          FUN_18031d480(param_1 + 0x40);
        }
        else {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (*(longlong *)(lVar4 + 0x10) == 0) goto LAB_180403950;
          if (lVar3 == 0) goto LAB_180403a50;
        }
        FUN_181f0db30(lVar3,*(undefined8 *)(param_1 + 0x40),0);
      }
      plVar10 = plVar10 + 1;
    }
    uVar8 = FUN_1802c43a0(DAT_182d58300);
    FUN_180665bb0(uVar8,param_1,DAT_182d581a8,0);
    if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
      FUN_18035c820();
    }
    FUN_180993250(uVar8,0,DAT_182d582e8);
    uVar8 = ExposureUnnoticed2_Master_Hair_MHair__Get__0600128f(*(undefined4 *)(param_1 + 0x30),0);
    bVar11 = DAT_182eb5d50 != 0;
    *(undefined8 *)(param_1 + 0x38) = uVar8;
    if (bVar11) {
      uVar9 = (uint)(param_1 + 0x38U >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
      do {
        uVar5 = *puVar1;
        LOCK();
        uVar2 = *puVar1;
        if (uVar5 == uVar2) {
          *puVar1 = uVar5 | 1L << (uVar9 & 0x3f);
        }
        UNLOCK();
      } while (uVar5 != uVar2);
    }
  }
  return;
}

