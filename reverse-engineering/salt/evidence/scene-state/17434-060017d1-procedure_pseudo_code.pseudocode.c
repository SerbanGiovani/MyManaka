// Ghidra pseudocode; not original source or compilable C.
// ev_44cafe426eabe7d97ce20f0a2c10a0d73817c6ba637f6bdff5a6fe8a3365b238

void ExposureUnnoticed2_Scripts_Base_SystemManager__Awake__060017d1(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  code *pcVar6;
  undefined8 uVar7;
  longlong lVar8;
  ulonglong uVar9;
  uint uVar10;
  bool bVar11;
  
  if (cRam0000000182eb7ae8 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5bfa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d57e50);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ae8 = '\x01';
  }
  if (*(int *)(DAT_182d5bfa0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d5bfa0);
  }
  lVar8 = *(longlong *)(*(longlong *)(DAT_182d5bfa0 + 0xb8) + 8);
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
  if (lVar8 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar8 + 0x10) != 0) {
      pcVar6 = DAT_182ec1088;
      if ((DAT_182ec1088 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
         pcVar6 == (code *)0x0)) {
        uVar7 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar7,0);
      }
      DAT_182ec1088 = pcVar6;
      uVar7 = (*DAT_182ec1088)(param_1);
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182ec12b0 == '\0') {
        FUN_1802f2810(&DAT_182d53aa8,0);
        LOCK();
        UNLOCK();
        DAT_182ec12b0 = '\x01';
      }
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      pcVar6 = DAT_182ec12a8;
      if ((DAT_182ec12a8 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)"
                                        ), pcVar6 == (code *)0x0)) {
        uVar7 = FUN_1802ced60("UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar7,0);
      }
      DAT_182ec12a8 = pcVar6;
                    /* WARNING: Could not recover jumptable at 0x000181f43eee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*DAT_182ec12a8)(uVar7,0);
      return;
    }
  }
  pcVar6 = DAT_182ec1088;
  if ((DAT_182ec1088 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
     pcVar6 == (code *)0x0)) {
    uVar7 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar7,0);
  }
  DAT_182ec1088 = pcVar6;
  uVar7 = (*DAT_182ec1088)(param_1);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar6 = DAT_182ec12d8;
  if ((DAT_182ec12d8 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Object::DontDestroyOnLoad(UnityEngine.Object)"),
     pcVar6 == (code *)0x0)) {
    uVar7 = FUN_1802ced60("UnityEngine.Object::DontDestroyOnLoad(UnityEngine.Object)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar7,0);
  }
  DAT_182ec12d8 = pcVar6;
  (*DAT_182ec12d8)(uVar7);
  if (*(int *)(DAT_182d5bfa0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d5bfa0);
  }
  *(longlong *)(*(longlong *)(DAT_182d5bfa0 + 0xb8) + 8) = param_1;
  if (DAT_182eb5d50 != 0) {
    uVar10 = (uint)(*(longlong *)(DAT_182d5bfa0 + 0xb8) + 8U >> 0xc);
    uVar9 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar11) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar1 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar11);
  }
  lVar8 = FUN_1802c43a0(DAT_182d57e50);
  if (cRam0000000182eb7af0 == '\0') {
    FUN_1802f2810(0x182d5f400);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f3f8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7af0 = '\x01';
  }
  uVar7 = FUN_1802c43a0(uRam0000000182d5f3f8);
  FUN_180003c90(uVar7,uRam0000000182d5f400);
  iVar5 = DAT_182eb5d50;
  *(undefined8 *)(lVar8 + 0x10) = uVar7;
  if (iVar5 != 0) {
    uVar10 = (uint)(lVar8 + 0x10U >> 0xc);
    uVar9 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar11) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar1 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
      iVar5 = DAT_182eb5d50;
    } while (!bVar11);
  }
  *(longlong *)(param_1 + 0x20) = lVar8;
  if (iVar5 != 0) {
    uVar10 = (uint)(param_1 + 0x20U >> 0xc);
    uVar9 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      LOCK();
      bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
      if (bVar11) {
        *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar1 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar11);
  }
  lVar8 = *(longlong *)(param_1 + 0x20);
  if (lVar8 != 0) {
    if (cRam0000000182eb7aeb == '\0') {
      FUN_1802f2810(0x182d5f418);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d57e50);
      LOCK();
      UNLOCK();
      cRam0000000182eb7aeb = '\x01';
    }
    **(longlong **)(DAT_182d57e50 + 0xb8) = lVar8;
    if (DAT_182eb5d50 != 0) {
      uVar10 = (uint)(*(ulonglong *)(DAT_182d57e50 + 0xb8) >> 0xc);
      uVar9 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
        LOCK();
        bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
        if (bVar11) {
          *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar1 | 1L << (uVar10 & 0x3f);
        }
        UNLOCK();
      } while (!bVar11);
    }
    lVar4 = lRam0000000182d5f418;
    lVar2 = *(longlong *)(lVar8 + 0x10);
    if (lVar2 == 0) goto DAT_1804bb84e;
    *(int *)(lVar2 + 0x1c) = *(int *)(lVar2 + 0x1c) + 1;
    lVar3 = *(longlong *)(lVar2 + 0x10);
    if (lVar3 == 0) goto DAT_1804bb84e;
    uVar10 = *(uint *)(lVar2 + 0x18);
    if (uVar10 < *(uint *)(lVar3 + 0x18)) {
      *(uint *)(lVar2 + 0x18) = uVar10 + 1;
      if (*(uint *)(lVar3 + 0x18) <= uVar10) goto DAT_1804bb899;
      *(undefined1 *)((longlong)(int)uVar10 + 0x20 + lVar3) = 0;
    }
    else {
      FUN_18121ef70(lVar2,0,*(undefined8 *)
                             (*(longlong *)(*(longlong *)(lVar4 + 0x20) + 0xc0) + 0x70));
    }
    lVar4 = lRam0000000182d5f418;
    lVar2 = *(longlong *)(lVar8 + 0x10);
    if (lVar2 != 0) {
      *(int *)(lVar2 + 0x1c) = *(int *)(lVar2 + 0x1c) + 1;
      lVar3 = *(longlong *)(lVar2 + 0x10);
      if (lVar3 != 0) {
        uVar10 = *(uint *)(lVar2 + 0x18);
        if (uVar10 < *(uint *)(lVar3 + 0x18)) {
          *(uint *)(lVar2 + 0x18) = uVar10 + 1;
          if (*(uint *)(lVar3 + 0x18) <= uVar10) {
DAT_1804bb899:
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
          *(undefined1 *)((longlong)(int)uVar10 + 0x20 + lVar3) = 0;
        }
        else {
          FUN_18121ef70(lVar2,0,*(undefined8 *)
                                 (*(longlong *)(*(longlong *)(lVar4 + 0x20) + 0xc0) + 0x70));
        }
        *(undefined4 *)(lVar8 + 0x18) = 0x3f800000;
        return;
      }
    }
  }
DAT_1804bb84e:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

