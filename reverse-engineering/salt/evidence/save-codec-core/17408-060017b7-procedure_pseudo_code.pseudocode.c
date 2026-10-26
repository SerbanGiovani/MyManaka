// Ghidra pseudocode; not original source or compilable C.
// ev_2432dc110aa969c088dd3ef38cdfdf0c631830238a2bf533907ac5e0d5b64acb

ulonglong ExposureUnnoticed2_Scripts_Base_SaveRapper__IsExistSaveData__060017b7
                    (int param_1,int param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  byte extraout_var;
  code *pcVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 uVar9;
  uint uVar10;
  bool bVar11;
  
  if (DAT_182eb7ad7 == '\0') {
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    DAT_182eb7ad7 = '\x01';
  }
  if (((param_1 == 1) || (param_1 == 3)) && (param_2 == -1)) {
    uVar5 = thunk_FUN_1802f2810(&DAT_182d53398);
    uVar5 = thunk_FUN_1802c43a0(uVar5);
    uVar9 = thunk_FUN_1802f2810(&DAT_182d5f498);
    FUN_18165bfb0(uVar5,uVar9,0);
    uVar9 = thunk_FUN_1802f2810(&DAT_182d5f490);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar5,uVar9);
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar7 = ExposureUnnoticed2_Scripts_Base_SaveRapper__GetSpecifiedSaveDataPath__060017b6
                    (param_1,param_2,0);
  if (DAT_182eb74df == '\0') {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    DAT_182eb74df = '\x01';
  }
  lVar8 = FUN_1802c43a0(DAT_182d534a8);
  ES3Settings___ctor__060001ba(lVar8,1,0);
  if ((lVar7 != 0) && (bVar11 = DAT_182eb5d50 != 0, *(longlong *)(lVar8 + 0x18) = lVar7, bVar11)) {
    uVar10 = (uint)(lVar8 + 0x18U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8);
    do {
      uVar2 = *puVar1;
      LOCK();
      uVar4 = *puVar1;
      if (uVar2 == uVar4) {
        *puVar1 = uVar2 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (uVar2 != uVar4);
  }
  if (DAT_182eb74e1 == '\0') {
    FUN_1802f2810(&DAT_182d53490);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53488);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182eb74e1 = '\x01';
  }
  if (lVar8 != 0) {
    iVar3 = ES3Settings__get_location__060001b2(lVar8,0);
    if (iVar3 == 0) {
      uVar5 = ES3Settings__get_FullPath__060001b4(lVar8,0);
      if (*(int *)(DAT_182d53488 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar4 = System_IO_File__Exists__06002a8a(uVar5,0);
      return uVar4;
    }
    iVar3 = ES3Settings__get_location__060001b2();
    if (iVar3 == 1) {
      uVar5 = ES3Settings__get_FullPath__060001b4(lVar8,0);
      pcVar6 = DAT_182ec0f98;
      if ((DAT_182ec0f98 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.PlayerPrefs::HasKey(System.String)"),
         pcVar6 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.PlayerPrefs::HasKey(System.String)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec0f98 = pcVar6;
                    /* WARNING: Could not recover jumptable at 0x0001803c329f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar4 = (*DAT_182ec0f98)(uVar5);
      return uVar4;
    }
    iVar3 = ES3Settings__get_location__060001b2();
    if (iVar3 != 4) {
      uVar4 = ES3Settings__get_location__060001b2(lVar8,0);
      if ((int)uVar4 != 3) {
        return uVar4 & 0xffffffffffffff00;
      }
      uVar5 = ES3Settings__get_FullPath__060001b4(lVar8,0);
      lVar7 = UnityEngine_Resources__Load__060008e7(uVar5,0);
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182ec12f4 == '\0') {
        FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        DAT_182ec12f4 = '\x01';
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
      if (lVar7 == 0) {
        return 0;
      }
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      return (ulonglong)(*(longlong *)(lVar7 + 0x10) != 0);
    }
    if (*(int *)(DAT_182d53490 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182eb7523 == '\0') {
      FUN_1802f2810(&DAT_182d52d38);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d53490);
      LOCK();
      UNLOCK();
      DAT_182eb7523 = '\x01';
    }
    if (*(int *)(DAT_182d53490 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (**(longlong **)(DAT_182d53490 + 0xb8) != 0) {
      FUN_180e9f040(**(longlong **)(DAT_182d53490 + 0xb8),*(undefined8 *)(lVar8 + 0x18),
                    *(undefined8 *)
                     (*(longlong *)(*(longlong *)(DAT_182d52d38 + 0x20) + 0xc0) + 0xf8));
      return (ulonglong)(extraout_var >> 7) ^ 1;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

