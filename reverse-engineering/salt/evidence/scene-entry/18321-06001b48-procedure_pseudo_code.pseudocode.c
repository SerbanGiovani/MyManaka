// Ghidra pseudocode; not original source or compilable C.
// ev_6d6b728a22a408f3984e5eb516b1c205c8d6996ba8e6765862722a9a106a4f5f

ulonglong ExposureUnnoticed2_ObjectUI_FadeOutPanel_FadePanelView__Initialize__06001b48
                    (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 param_5,undefined1 param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  code *pcVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  
  if (cRam0000000182eb7d12 == '\0') {
    FUN_1802f2810(0x182d53c58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa40);
    LOCK();
    UNLOCK();
    cRam0000000182eb7d12 = '\x01';
  }
  if (*(int *)(lRam0000000182d5aa40 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_180525220(param_1);
  iVar6 = DAT_182eb5d50;
  *(undefined8 *)(param_1 + 0x40) = param_2;
  if (iVar6 != 0) {
    uVar8 = (uint)(param_1 + 0x40U >> 0xc);
    lVar1 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar9 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
      iVar6 = DAT_182eb5d50;
    } while (!bVar9);
  }
  *(undefined8 *)(param_1 + 0x28) = param_3;
  iVar7 = 0;
  if (iVar6 != 0) {
    uVar8 = (uint)(param_1 + 0x28U >> 0xc);
    lVar1 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar9 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
      iVar7 = DAT_182eb5d50;
    } while (!bVar9);
  }
  *(undefined8 *)(param_1 + 0x30) = param_4;
  iVar6 = 0;
  if (iVar7 != 0) {
    uVar8 = (uint)(param_1 + 0x30U >> 0xc);
    lVar1 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar9 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
      iVar6 = DAT_182eb5d50;
    } while (!bVar9);
  }
  *(undefined8 *)(param_1 + 0x38) = param_5;
  if (iVar6 != 0) {
    uVar8 = (uint)(param_1 + 0x38U >> 0xc);
    lVar1 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar9 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
    } while (!bVar9);
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  pcVar3 = DAT_182ec1138;
  if ((DAT_182ec1138 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
     pcVar3 == (code *)0x0)) {
    uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar5,0);
  }
  DAT_182ec1138 = pcVar3;
  (*DAT_182ec1138)(lVar1,param_6);
  uVar4 = FUN_180735660(param_1,uRam0000000182d53c58);
  bVar9 = DAT_182eb5d50 != 0;
  *(ulonglong *)(param_1 + 0x50) = uVar4;
  if (bVar9) {
    uVar8 = (uint)(param_1 + 0x50U >> 0xc);
    lVar1 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      bVar9 = uVar2 == uVar4;
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar8 & 0x3f);
        uVar4 = uVar2;
      }
      UNLOCK();
    } while (!bVar9);
  }
  return uVar4;
}

