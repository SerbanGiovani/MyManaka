// Ghidra pseudocode; not original source or compilable C.
// ev_b52370b3c678475f00bd4bd169ab2abadb392792d035925c3739d64c3c3dcc93

ulonglong ExposureUnnoticed2_Scripts_InGame_PortalManager__GetNearPortal__060015e4(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar9;
  ulonglong *puVar10;
  bool bVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  ulonglong uVar8;
  
  if (cRam0000000182eb79f0 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb79f0 = '\x01';
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  uVar6 = 0;
  if (lVar1 == 0) {
code_r0x00018049a709:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (0 < *(int *)(lVar1 + 0x18)) {
    puVar10 = (ulonglong *)(lVar1 + 0x20);
    bVar11 = *(int *)(lVar1 + 0x18) != 0;
    uVar8 = uVar6;
    uVar9 = uVar6;
    fVar14 = 3.4028235e+38;
    do {
      if (!bVar11) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      uVar6 = *puVar10;
      if (uVar6 == 0) goto code_r0x00018049a709;
      pcVar4 = DAT_182ec1088;
      if ((DAT_182ec1088 == (code *)0x0) &&
         (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
         pcVar4 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec1088 = pcVar4;
      uVar5 = (*DAT_182ec1088)(uVar6);
      if ((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
         (lVar2 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar2 == 0))
      goto code_r0x00018049a709;
      uVar3 = *(undefined8 *)(lVar2 + 0x28);
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      fVar12 = (float)ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DistSqrt__06001726
                                (uVar5,uVar3,0);
      fVar13 = fVar14;
      if (fVar12 < fVar14) {
        fVar13 = fVar12;
      }
      uVar7 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar7;
      puVar10 = puVar10 + 1;
      if (fVar14 <= fVar12) {
        uVar6 = uVar9;
      }
      bVar11 = uVar7 < *(uint *)(lVar1 + 0x18);
      uVar9 = uVar6;
      fVar14 = fVar13;
    } while ((int)uVar7 < (int)*(uint *)(lVar1 + 0x18));
  }
  return uVar6;
}

