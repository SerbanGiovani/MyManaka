// Ghidra pseudocode; not original source or compilable C.
// ev_4df3d3212e53a5b642dd75aad68f0156ec324dbf2162f837785060fd4094425f

ulonglong IKA9nt_Encrypter_BridgeAssetBundleRequest___ctor__0600004f
                    (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  code *pcVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  uint uVar11;
  bool bVar12;
  
  if (cRam0000000182ebaa8d == '\0') {
    FUN_1802f2810(0x182d64d48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64d50);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa8d = '\x01';
  }
  iVar5 = DAT_182eb5d50;
  *(undefined8 *)(param_1 + 0x28) = param_3;
  if (iVar5 != 0) {
    uVar11 = (uint)(param_1 + 0x28U >> 0xc);
    lVar1 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
    do {
      uVar9 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar12 = uVar9 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar9 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
      iVar5 = DAT_182eb5d50;
    } while (!bVar12);
  }
  *(undefined8 *)(param_1 + 0x18) = param_2;
  if (iVar5 != 0) {
    uVar11 = (uint)(param_1 + 0x18U >> 0xc);
    lVar1 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
    do {
      uVar9 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar12 = uVar9 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar9 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  lVar1 = *(longlong *)(param_1 + 0x18);
  lVar6 = FUN_1802c43a0(uRam0000000182d64d48);
  FUN_180665bb0(lVar6,param_1,uRam0000000182d64d50,0);
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (cRam0000000182ec1048 == '\0') {
    FUN_1802f2810(0x182d64d48,lVar6,0);
    LOCK();
    UNLOCK();
    cRam0000000182ec1048 = '\x01';
  }
  pcVar7 = pcRam0000000182ec1038;
  if ((pcRam0000000182ec1038 == (code *)0x0) &&
     (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.AsyncOperation::get_isDone()"),
     pcVar7 == (code *)0x0)) {
    uVar10 = func_0x0001802ced60("UnityEngine.AsyncOperation::get_isDone()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar10,0);
  }
  pcRam0000000182ec1038 = pcVar7;
  cVar4 = (*pcRam0000000182ec1038)(lVar1);
  if (cVar4 != '\0') {
    if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
                    /* WARNING: Could not recover jumptable at 0x000181f37eaf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar9 = (**(code **)(lVar6 + 0x18))
                      (*(undefined8 *)(lVar6 + 0x40),lVar1,*(undefined8 *)(lVar6 + 0x28));
    return uVar9;
  }
  lVar6 = FUN_1816791b0(*(undefined8 *)(lVar1 + 0x18),lVar6,0);
  uVar10 = uRam0000000182d64d48;
  if (lVar6 == 0) {
    *(undefined8 *)(lVar1 + 0x18) = 0;
    uVar9 = 0;
  }
  else {
    lVar8 = FUN_1802c42e0(lVar6,uRam0000000182d64d48);
    if (lVar8 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(lVar6,uVar10);
    }
    *(longlong *)(lVar1 + 0x18) = lVar8;
    uVar10 = uRam0000000182d64d48;
    uVar9 = FUN_1802c42e0(lVar6,uRam0000000182d64d48);
    if (uVar9 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(lVar6,uVar10);
    }
  }
  if (DAT_182eb5d50 != 0) {
    uVar11 = (uint)(lVar1 + 0x18U >> 0xc);
    puVar2 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar2;
      LOCK();
      uVar9 = *puVar2;
      bVar12 = uVar3 == uVar9;
      if (bVar12) {
        *puVar2 = uVar3 | 1L << (uVar11 & 0x3f);
        uVar9 = uVar3;
      }
      UNLOCK();
    } while (!bVar12);
  }
  return uVar9;
}

