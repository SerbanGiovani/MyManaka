// Ghidra pseudocode; not original source or compilable C.
// ev_605c02f0fff57f436c20b0e5eb755b04d800ea13bb51a920f7b5c6f498075e9c

undefined8 ES3Internal_ES3Stream__CreateStream__060006e5(longlong param_1,int param_2)

{
  undefined4 uVar1;
  ulonglong uVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  longlong *plVar8;
  code *pcVar9;
  longlong lVar10;
  longlong *plVar11;
  uint uVar12;
  bool bVar13;
  
  if (DAT_182eb80b8 == '\0') {
    FUN_1802f2810(&DAT_182d6a330);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53488);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a320);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a318);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a310);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53408);
    LOCK();
    UNLOCK();
    DAT_182eb80b8 = '\x01';
  }
  plVar11 = (longlong *)0x0;
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar5 = ES3Settings__get_FullPath__060001b4(param_1,0);
  uVar6 = FUN_1802c43a0(DAT_182d6a310);
  FUN_1815ee000(uVar6,uVar5,0,0,0,0);
  iVar4 = ES3Settings__get_location__060001b2(param_1,0);
  if (iVar4 == 2) {
    if (param_2 == 0) {
      return 0;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x3c);
    plVar7 = (longlong *)FUN_1802c43a0(DAT_182d53408);
    System_IO_MemoryStream___ctor__0600297d(plVar7,uVar1,0);
    goto LAB_1805a3d84;
  }
  iVar4 = ES3Settings__get_location__060001b2(param_1,0);
  if (iVar4 == 0) {
    if (param_2 == 0) {
      uVar5 = ES3Settings__get_FullPath__060001b4(param_1,0);
      if (*(int *)(DAT_182d53488 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = System_IO_File__Exists__06002a8a(uVar5,0);
      if (cVar3 == '\0') {
        return 0;
      }
    }
    uVar5 = ES3Settings__get_FullPath__060001b4(param_1,0);
    uVar1 = *(undefined4 *)(param_1 + 0x3c);
    plVar7 = (longlong *)FUN_1802c43a0(DAT_182d6a330);
    ES3Internal_ES3FileStream___ctor__060006d8(plVar7,uVar5,param_2,uVar1,0,0);
    goto LAB_1805a3d84;
  }
  iVar4 = ES3Settings__get_location__060001b2(param_1,0);
  if (iVar4 == 1) {
    lVar10 = ES3Settings__get_FullPath__060001b4(param_1,0);
    if (param_2 == 0) {
      cVar3 = FUN_181f36e00(lVar10,0);
      if (cVar3 == '\0') {
        return 0;
      }
      lVar10 = ES3Settings__get_FullPath__060001b4(param_1,0);
      plVar7 = (longlong *)FUN_1802c43a0(DAT_182d6a320);
      uVar5 = ES3Internal_ES3PlayerPrefsStream__GetData__060006df(lVar10,0,0);
      System_IO_MemoryStream___ctor__0600297f(plVar7,uVar5,1,0);
      plVar7[10] = lVar10;
      if (DAT_182eb5d50 != 0) {
        uVar12 = (uint)((ulonglong)(plVar7 + 10) >> 0xc);
        lVar10 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar10);
          LOCK();
          bVar13 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar10);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + lVar10) = uVar2 | 1L << (uVar12 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      *(undefined1 *)(plVar7 + 0xb) = 0;
    }
    else {
      uVar1 = *(undefined4 *)(param_1 + 0x3c);
      plVar7 = (longlong *)FUN_1802c43a0(DAT_182d6a320);
      System_IO_MemoryStream___ctor__0600297d(plVar7,uVar1,0);
      plVar7[10] = lVar10;
      if (DAT_182eb5d50 != 0) {
        uVar12 = (uint)((ulonglong)(plVar7 + 10) >> 0xc);
        lVar10 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar10);
          LOCK();
          bVar13 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar10);
          if (bVar13) {
            *(ulonglong *)(&DAT_182f0c920 + lVar10) = uVar2 | 1L << (uVar12 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      *(bool *)(plVar7 + 0xb) = param_2 == 2;
      *(undefined1 *)((longlong)plVar7 + 0x59) = 1;
    }
    goto LAB_1805a3d84;
  }
  iVar4 = ES3Settings__get_location__060001b2();
  plVar7 = plVar11;
  if (iVar4 != 3) goto LAB_1805a3d84;
  if (param_2 != 0) {
    lVar10 = FUN_1802f2810(&DAT_182d53a48);
    if (*(int *)(lVar10 + 0xe0) == 0) {
      FUN_18035c820(lVar10);
    }
    uVar5 = thunk_FUN_1802f2810(&DAT_182d53260);
    uVar5 = thunk_FUN_1802c43a0(uVar5);
    uVar6 = thunk_FUN_1802f2810(&DAT_182d6a300);
    FUN_18161d3f0(uVar5,uVar6,0);
    uVar6 = thunk_FUN_1802f2810(&DAT_182d6a308);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar5,uVar6);
  }
  uVar5 = ES3Settings__get_FullPath__060001b4(param_1,0);
  plVar7 = (longlong *)FUN_1802c43a0(DAT_182d6a318);
  if (DAT_182eb80b7 == '\0') {
    FUN_1802f2810(&DAT_182d53428);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d69238);
    LOCK();
    UNLOCK();
    DAT_182eb80b7 = '\x01';
  }
  plVar8 = (longlong *)UnityEngine_Resources__Load__060008e7(uVar5,0);
  if (plVar8 != (longlong *)0x0) {
    if ((*(byte *)(*plVar8 + 0x130) < *(byte *)(DAT_182d69238 + 0x130)) ||
       (bVar13 = true,
       *(longlong *)
        (*(longlong *)(*plVar8 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d69238 + 0x130) * 8) !=
       DAT_182d69238)) {
      bVar13 = false;
    }
    if (bVar13) {
      plVar11 = plVar8;
    }
  }
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
  if (plVar11 == (longlong *)0x0) {
LAB_1805a3b20:
    uVar5 = FUN_1802c36c0(DAT_182d53428,0);
  }
  else {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (plVar11[2] == 0) goto LAB_1805a3b20;
    pcVar9 = DAT_182ec1270;
    if ((DAT_182ec1270 == (code *)0x0) &&
       (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.TextAsset::get_bytes()"), pcVar9 == (code *)0x0)
       ) {
      uVar5 = FUN_1802ced60("UnityEngine.TextAsset::get_bytes()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ec1270 = pcVar9;
    uVar5 = (*DAT_182ec1270)(plVar11);
  }
  System_IO_MemoryStream___ctor__0600297f(plVar7,uVar5,1,0);
  if (plVar7 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  lVar10 = (**(code **)(*plVar7 + 0x1d8))(plVar7,*(undefined8 *)(*plVar7 + 0x1e0));
  if (lVar10 < 1) {
    (**(code **)(*plVar7 + 0x218))(plVar7,*(undefined8 *)(*plVar7 + 0x220));
    return 0;
  }
LAB_1805a3d84:
  uVar5 = ES3Internal_ES3Stream__CreateStream__060006e6(plVar7,param_1,param_2,0);
  return uVar5;
}

