// Ghidra pseudocode; not original source or compilable C.
// ev_4ef27fb318dd3acdbe6b1f6366eb10393573b78c5a40dbd740e7a2e1bffeb20e

ulonglong ExposureUnnoticed2_Object3D_Camera_TPCameraController__Initialize__06001211
                    (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  code *pcVar14;
  ulonglong uVar15;
  undefined8 uVar16;
  bool bVar17;
  
  if (cRam0000000182eb7824 == '\0') {
    FUN_1802f2810(&DAT_182d582a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58298);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c810);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c830);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53648);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58290);
    LOCK();
    UNLOCK();
    cRam0000000182eb7824 = '\x01';
  }
  iVar5 = DAT_182eb5d50;
  *(undefined8 *)(param_1 + 0x38) = param_2;
  if (iVar5 != 0) {
    uVar6 = (uint)(param_1 + 0x38U >> 0xc);
    lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar15 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar17 = uVar15 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar17) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar15 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
      iVar5 = DAT_182eb5d50;
    } while (!bVar17);
  }
  *(undefined8 *)(param_1 + 0x40) = param_3;
  if (iVar5 != 0) {
    uVar6 = (uint)(param_1 + 0x40U >> 0xc);
    lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar15 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar17 = uVar15 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar17) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar15 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar17);
  }
  uVar16 = DAT_182d53648;
  pcVar14 = DAT_182ec1198;
  if ((DAT_182ec1198 == (code *)0x0) &&
     (pcVar14 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
     pcVar14 == (code *)0x0)) {
    uVar16 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar16,0);
  }
  DAT_182ec1198 = pcVar14;
  bVar4 = (*DAT_182ec1198)(uVar16);
  uVar16 = DAT_182d58290;
  pcVar14 = DAT_182ec1198;
  if ((DAT_182ec1198 == (code *)0x0) &&
     (pcVar14 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
     pcVar14 == (code *)0x0)) {
    uVar16 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar16,0);
  }
  DAT_182ec1198 = pcVar14;
  uVar6 = (*DAT_182ec1198)(uVar16);
  if (*(int *)(DAT_182d582a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar7 = ExposureUnnoticed2_Scripts_Base_LayerAccessor__get_SpermCollider__060017a6(0);
  uVar16 = DAT_182d5c830;
  pcVar14 = DAT_182ec1198;
  if ((DAT_182ec1198 == (code *)0x0) &&
     (pcVar14 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
     pcVar14 == (code *)0x0)) {
    uVar16 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar16,0);
  }
  DAT_182ec1198 = pcVar14;
  uVar8 = (*DAT_182ec1198)(uVar16);
  uVar16 = DAT_182d58298;
  pcVar14 = DAT_182ec1198;
  if ((DAT_182ec1198 == (code *)0x0) &&
     (pcVar14 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
     pcVar14 == (code *)0x0)) {
    uVar16 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar16,0);
  }
  DAT_182ec1198 = pcVar14;
  uVar9 = (*DAT_182ec1198)(uVar16);
  uVar16 = uRam0000000182d5c810;
  pcVar14 = DAT_182ec1198;
  if ((DAT_182ec1198 == (code *)0x0) &&
     (pcVar14 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
     pcVar14 == (code *)0x0)) {
    uVar16 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar16,0);
  }
  DAT_182ec1198 = pcVar14;
  uVar10 = (*DAT_182ec1198)(uVar16);
  uVar11 = ExposureUnnoticed2_Scripts_Base_LayerAccessor__get_XRayLevel__060017a8(0);
  if (cRam0000000182eb7acc == '\0') {
    FUN_1802f2810(&DAT_182d582a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f570);
    LOCK();
    UNLOCK();
    cRam0000000182eb7acc = '\x01';
  }
  if (*(int *)(DAT_182d582a0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d582a0);
  }
  uVar16 = uRam0000000182d5f570;
  if (*(int *)(*(longlong *)(DAT_182d582a0 + 0xb8) + 0x2c) == -1) {
    pcVar14 = DAT_182ec1198;
    if ((DAT_182ec1198 == (code *)0x0) &&
       (pcVar14 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
       pcVar14 == (code *)0x0)) {
      uVar16 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar16,0);
    }
    DAT_182ec1198 = pcVar14;
    uVar12 = (*DAT_182ec1198)(uVar16);
    if (*(int *)(DAT_182d582a0 + 0xe0) == 0) {
      FUN_18035c820();
    }
    *(undefined4 *)(*(longlong *)(DAT_182d582a0 + 0xb8) + 0x2c) = uVar12;
  }
  if (*(int *)(DAT_182d582a0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d582a0);
  }
  uVar2 = *(uint *)(*(longlong *)(DAT_182d582a0 + 0xb8) + 0x2c);
  uVar13 = ExposureUnnoticed2_Scripts_Base_LayerAccessor__get_IgnorePeeParticle__060017aa(0);
  *(int *)(param_1 + 0x48) =
       1 << (bVar4 & 0x1f) | 1 << (uVar6 & 0x1f) | 1 << (uVar7 & 0x1f) | 1 << (uVar8 & 0x1f) |
       1 << (uVar9 & 0x1f) | 1 << (uVar10 & 0x1f) | 1 << (uVar11 & 0x1f) | 1 << (uVar2 & 0x1f) |
       1 << (uVar13 & 0x1f);
  if (((*(longlong *)(param_1 + 0x38) != 0) &&
      (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x40), lVar1 != 0)) &&
     (lVar1 = *(longlong *)(lVar1 + 0x70), lVar1 != 0)) {
    bVar17 = DAT_182eb5d50 != 0;
    uVar15 = *(ulonglong *)(lVar1 + 0x68);
    *(ulonglong *)(param_1 + 0x20) = uVar15;
    if (bVar17) {
      uVar6 = (uint)(param_1 + 0x20U >> 0xc);
      lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
      do {
        uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        uVar15 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        bVar17 = uVar3 == uVar15;
        if (bVar17) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar6 & 0x3f);
          uVar15 = uVar3;
        }
        UNLOCK();
      } while (!bVar17);
    }
    return uVar15;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

