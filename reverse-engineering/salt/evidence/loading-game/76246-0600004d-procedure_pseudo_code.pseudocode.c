// Ghidra pseudocode; not original source or compilable C.
// ev_ef960b3db8c3cf8cedc32ccfe0caf231458a999f24ece3889ed0ce2b6c286ccd

ulonglong IKA9nt_Encrypter_BridgeAssetBundleRequest___ctor__0600004d
                    (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  code *pcVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  uint uVar12;
  bool bVar13;
  
  if (cRam0000000182ebaa8c == '\0') {
    FUN_1802f2810(0x182d64d48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64d40);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa8c = '\x01';
  }
  iVar5 = DAT_182eb5d50;
  *(undefined8 *)(param_1 + 0x28) = param_3;
  if (iVar5 != 0) {
    uVar12 = (uint)(param_1 + 0x28U >> 0xc);
    lVar1 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar13 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar13) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar10 | 1L << (uVar12 & 0x3f);
      }
      UNLOCK();
      iVar5 = DAT_182eb5d50;
    } while (!bVar13);
  }
  *(undefined8 *)(param_1 + 0x30) = param_4;
  iVar6 = 0;
  if (iVar5 != 0) {
    uVar12 = (uint)(param_1 + 0x30U >> 0xc);
    lVar1 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar13 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar13) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar10 | 1L << (uVar12 & 0x3f);
      }
      UNLOCK();
      iVar6 = DAT_182eb5d50;
    } while (!bVar13);
  }
  *(undefined8 *)(param_1 + 0x10) = param_2;
  if (iVar6 != 0) {
    uVar12 = (uint)(param_1 + 0x10U >> 0xc);
    lVar1 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
    do {
      uVar10 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar13 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar13) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar10 | 1L << (uVar12 & 0x3f);
      }
      UNLOCK();
    } while (!bVar13);
  }
  lVar1 = *(longlong *)(param_1 + 0x10);
  lVar7 = FUN_1802c43a0(uRam0000000182d64d48);
  FUN_180665bb0(lVar7,param_1,uRam0000000182d64d40,0);
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (cRam0000000182ec1048 == '\0') {
    FUN_1802f2810(0x182d64d48,lVar7,0);
    LOCK();
    UNLOCK();
    cRam0000000182ec1048 = '\x01';
  }
  pcVar8 = pcRam0000000182ec1038;
  if ((pcRam0000000182ec1038 == (code *)0x0) &&
     (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.AsyncOperation::get_isDone()"),
     pcVar8 == (code *)0x0)) {
    uVar11 = func_0x0001802ced60("UnityEngine.AsyncOperation::get_isDone()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar11,0);
  }
  pcRam0000000182ec1038 = pcVar8;
  cVar4 = (*pcRam0000000182ec1038)(lVar1);
  if (cVar4 != '\0') {
    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
                    /* WARNING: Could not recover jumptable at 0x000181f37eaf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar10 = (**(code **)(lVar7 + 0x18))
                       (*(undefined8 *)(lVar7 + 0x40),lVar1,*(undefined8 *)(lVar7 + 0x28));
    return uVar10;
  }
  lVar7 = FUN_1816791b0(*(undefined8 *)(lVar1 + 0x18),lVar7,0);
  uVar11 = uRam0000000182d64d48;
  if (lVar7 == 0) {
    *(undefined8 *)(lVar1 + 0x18) = 0;
    uVar10 = 0;
  }
  else {
    lVar9 = FUN_1802c42e0(lVar7,uRam0000000182d64d48);
    if (lVar9 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(lVar7,uVar11);
    }
    *(longlong *)(lVar1 + 0x18) = lVar9;
    uVar11 = uRam0000000182d64d48;
    uVar10 = FUN_1802c42e0(lVar7,uRam0000000182d64d48);
    if (uVar10 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(lVar7,uVar11);
    }
  }
  if (DAT_182eb5d50 != 0) {
    uVar12 = (uint)(lVar1 + 0x18U >> 0xc);
    puVar2 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar2;
      LOCK();
      uVar10 = *puVar2;
      bVar13 = uVar3 == uVar10;
      if (bVar13) {
        *puVar2 = uVar3 | 1L << (uVar12 & 0x3f);
        uVar10 = uVar3;
      }
      UNLOCK();
    } while (!bVar13);
  }
  return uVar10;
}

