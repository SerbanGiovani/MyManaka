// Ghidra pseudocode; not original source or compilable C.
// ev_d9aa9268a111316ce0a28f1d8eb90bec3d6231b8ad0dc2e24414836e72e30374

void ExposureUnnoticed2_Scripts_InGame_SaveManager__Save__06001601
               (int param_1,undefined4 param_2,undefined1 param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  longlong lVar8;
  ulonglong uVar9;
  uint uVar10;
  bool bVar11;
  float fVar12;
  
  if (cRam0000000182eb79fe == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60188);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60180);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60178);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d60170);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60168);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60160);
    LOCK();
    UNLOCK();
    cRam0000000182eb79fe = '\x01';
  }
  if (param_1 == 3) {
    param_2 = **(undefined4 **)(lRam0000000182d60190 + 0xb8);
    ExposureUnnoticed2_Scripts_InGame_SaveManager__SaveSystem__060015ff(3,param_2,0);
  }
  else {
    ExposureUnnoticed2_Scripts_InGame_SaveManager__SaveSystem__060015ff(param_1,param_2,0);
    if (param_1 == 4) {
      return;
    }
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820();
  }
  ExposureUnnoticed2_Scripts_Base_SaveRapper__PreProcess__060017b8(0,param_2,param_3,0);
  if (param_1 == 1) {
    if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar6 = ExposureUnnoticed2_Scripts_Base_SaveRapper__GetSpecifiedSaveDataPath__060017b6(1,1,0);
    uVar7 = ExposureUnnoticed2_Scripts_Base_SaveRapper__GetSpecifiedSaveDataPath__060017b6(1,2,0);
    ES3__CopyFile__060000d9(uVar6,uVar7,0);
    uVar6 = ExposureUnnoticed2_Scripts_Base_SaveRapper__GetSpecifiedSaveDataPath__060017b6(1,0,0);
    uVar7 = ExposureUnnoticed2_Scripts_Base_SaveRapper__GetSpecifiedSaveDataPath__060017b6(1,1,0);
    ES3__CopyFile__060000d9(uVar6,uVar7,0);
  }
  uVar2 = **(undefined4 **)(lRam0000000182d60190 + 0xb8);
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar6 = uRam0000000182d60178;
  if (cRam0000000182eb7ada == '\0') {
    FUN_1802f2810(0x182d5f488);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ada = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar5 = lRam0000000182d5f488;
  lVar3 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18);
  if (*(longlong *)(lRam0000000182d5f488 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar5 + 0x38) == 0) {
      FUN_1803204f0(lVar5);
    }
  }
  lVar8 = FUN_1802c43a0(DAT_182d534a8);
  ES3Settings___ctor__060001ba(lVar8,1,0);
  if ((lVar3 != 0) && (bVar11 = DAT_182eb5d50 != 0, *(longlong *)(lVar8 + 0x18) = lVar3, bVar11)) {
    uVar10 = (uint)(lVar8 + 0x18U >> 0xc);
    uVar9 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar11 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar11) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar4 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar11);
  }
  FUN_1807488d0(uVar6,uVar2,lVar8,*(undefined8 *)(*(longlong *)(lVar5 + 0x38) + 8));
  lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar3 != 0) {
    fVar12 = *(float *)(lVar3 + 0x168);
    if (0.99 <= fVar12) {
      fVar12 = 0.99;
    }
    *(float *)(lVar3 + 0x168) = fVar12;
    lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
          (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar5 != 0)) &&
         (lVar5 = *(longlong *)(lVar5 + 0x30), lVar5 != 0)) &&
        ((lVar5 = *(longlong *)(lVar5 + 0x40), lVar5 != 0 &&
         (lVar5 = *(longlong *)(lVar5 + 0x60), lVar5 != 0)))) &&
       ((lVar5 = *(longlong *)(lVar5 + 0x10), lVar5 != 0 && (lVar3 != 0)))) {
      *(undefined4 *)(lVar3 + 0x19c) = *(undefined4 *)(lVar5 + 0x30);
      FUN_1809ff300(uRam0000000182d60160,*(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48)
                    ,uRam0000000182d60188);
      uVar6 = DAT_182d60170;
      uVar1 = *(undefined1 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x54);
      if (cRam0000000182eb7add == '\0') {
        FUN_1802f2810(0x182d5f470);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d60278);
        LOCK();
        UNLOCK();
        cRam0000000182eb7add = '\x01';
      }
      if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d60278);
      }
      lVar5 = lRam0000000182d5f470;
      lVar3 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18);
      if (*(longlong *)(lRam0000000182d5f470 + 0x38) == 0) {
        FUN_1802f2810(&DAT_182d534a8);
        LOCK();
        UNLOCK();
        if (*(longlong *)(lVar5 + 0x38) == 0) {
          FUN_1803204f0(lVar5);
        }
      }
      lVar8 = FUN_1802c43a0(DAT_182d534a8);
      ES3Settings___ctor__060001ba(lVar8,1,0);
      if ((lVar3 != 0) && (bVar11 = DAT_182eb5d50 != 0, *(longlong *)(lVar8 + 0x18) = lVar3, bVar11)
         ) {
        uVar10 = (uint)(lVar8 + 0x18U >> 0xc);
        uVar9 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
        do {
          uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
          LOCK();
          bVar11 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
          if (bVar11) {
            *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar4 | 1L << (uVar10 & 0x3f);
          }
          UNLOCK();
        } while (!bVar11);
      }
      FUN_180748060(uVar6,uVar1,lVar8,*(undefined8 *)(*(longlong *)(lVar5 + 0x38) + 8));
      FUN_1809ff300(uRam0000000182d60168,*(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60)
                    ,uRam0000000182d60180);
      if (cRam0000000182eb7ad9 == '\0') {
        FUN_1802f2810(&DAT_182d60278);
        LOCK();
        UNLOCK();
        cRam0000000182eb7ad9 = '\x01';
      }
      if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d60278);
      }
      *(undefined1 *)(*(longlong *)(DAT_182d60278 + 0xb8) + 4) = 0;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

