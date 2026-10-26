// Ghidra pseudocode; not original source or compilable C.
// ev_d97713269ff70b9b28d946ebf3a2ebdd74e9ee8d6dc07d70bf30f5a97233fe6c

ulonglong ExposureUnnoticed2_Object3D_Camera_InventoryCameraController__Initialize__06001206
                    (longlong param_1,longlong param_2)

{
  ulonglong *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  bool bVar11;
  
  if (cRam0000000182eb7821 == '\0') {
    FUN_1802f2810(&DAT_182d58298);
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
    cRam0000000182eb7821 = '\x01';
  }
  uVar10 = DAT_182d53648;
  pcVar8 = DAT_182ec1198;
  if ((DAT_182ec1198 == (code *)0x0) &&
     (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
     pcVar8 == (code *)0x0)) {
    uVar10 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar10,0);
  }
  DAT_182ec1198 = pcVar8;
  bVar4 = (*DAT_182ec1198)(uVar10);
  uVar10 = DAT_182d58290;
  pcVar8 = DAT_182ec1198;
  if ((DAT_182ec1198 == (code *)0x0) &&
     (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
     pcVar8 == (code *)0x0)) {
    uVar10 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar10,0);
  }
  DAT_182ec1198 = pcVar8;
  uVar5 = (*DAT_182ec1198)(uVar10);
  uVar10 = DAT_182d5c830;
  pcVar8 = DAT_182ec1198;
  if ((DAT_182ec1198 == (code *)0x0) &&
     (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
     pcVar8 == (code *)0x0)) {
    uVar10 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar10,0);
  }
  DAT_182ec1198 = pcVar8;
  uVar6 = (*DAT_182ec1198)(uVar10);
  uVar10 = DAT_182d58298;
  pcVar8 = DAT_182ec1198;
  if ((DAT_182ec1198 == (code *)0x0) &&
     (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
     pcVar8 == (code *)0x0)) {
    uVar10 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar10,0);
  }
  DAT_182ec1198 = pcVar8;
  uVar7 = (*DAT_182ec1198)(uVar10);
  *(int *)(param_1 + 0x30) =
       1 << (bVar4 & 0x1f) | 1 << (uVar5 & 0x1f) | 1 << (uVar6 & 0x1f) | 1 << (uVar7 & 0x1f);
  if (((param_2 != 0) && (*(longlong *)(param_2 + 0x40) != 0)) &&
     (lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x40) + 0x70), lVar2 != 0)) {
    bVar11 = DAT_182eb5d50 != 0;
    uVar9 = *(ulonglong *)(lVar2 + 0x68);
    *(ulonglong *)(param_1 + 0x28) = uVar9;
    if (bVar11) {
      uVar5 = (uint)(param_1 + 0x28U >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
      do {
        uVar3 = *puVar1;
        LOCK();
        uVar9 = *puVar1;
        bVar11 = uVar3 == uVar9;
        if (bVar11) {
          *puVar1 = uVar3 | 1L << (uVar5 & 0x3f);
          uVar9 = uVar3;
        }
        UNLOCK();
      } while (!bVar11);
    }
    return uVar9;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

