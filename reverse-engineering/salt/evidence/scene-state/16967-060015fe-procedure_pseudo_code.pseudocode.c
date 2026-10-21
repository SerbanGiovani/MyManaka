// Ghidra pseudocode; not original source or compilable C.
// ev_1306aab55eb559278f4b9b190edbb437e6fe3c583280e573bb0cfcff424bcb8d

void ExposureUnnoticed2_Scripts_InGame_SaveManager__IsExistSaveData__060015fe
               (int param_1,int param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint uVar8;
  bool bVar9;
  
  if (DAT_182eb79fb == '\0') {
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    DAT_182eb79fb = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182eb7ad7 == '\0') {
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    DAT_182eb7ad7 = '\x01';
  }
  if (((param_1 == 1) || (param_1 == 3)) && (param_2 == -1)) {
    uVar6 = thunk_FUN_1802f2810(&DAT_182d53398);
    uVar6 = thunk_FUN_1802c43a0(uVar6);
    uVar7 = thunk_FUN_1802f2810(&DAT_182d5f498);
    FUN_18165bfb0(uVar6,uVar7,0);
    uVar7 = thunk_FUN_1802f2810(&DAT_182d5f490);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar6,uVar7);
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar4 = ExposureUnnoticed2_Scripts_Base_SaveRapper__GetSpecifiedSaveDataPath__060017b6
                    (param_1,param_2,0);
  if (DAT_182eb74df == '\0') {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    DAT_182eb74df = '\x01';
  }
  lVar5 = FUN_1802c43a0(DAT_182d534a8);
  ES3Settings___ctor__060001ba(lVar5,1,0);
  if ((lVar4 != 0) && (bVar9 = DAT_182eb5d50 != 0, *(longlong *)(lVar5 + 0x18) = lVar4, bVar9)) {
    uVar8 = (uint)(lVar5 + 0x18U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  ES3__FileExists__060000f3(lVar5,0);
  return;
}

