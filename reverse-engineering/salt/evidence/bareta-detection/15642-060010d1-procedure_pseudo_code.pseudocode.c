// Ghidra pseudocode; not original source or compilable C.
// ev_3eacc45f0de189b726dd63fda7b3c31b5c2a3794517062a8a268b2f3de776e95

ulonglong ExposureUnnoticed2_Object3D_NPC_Script_PlayerSearcher__Initialize__060010d1
                    (longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  code *pcVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  uint uVar13;
  longlong *plVar14;
  bool bVar15;
  
  if (DAT_182eb7796 == '\0') {
    FUN_1802f2810(&DAT_182d582a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5ae10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5ae08);
    LOCK();
    UNLOCK();
    DAT_182eb7796 = '\x01';
  }
  uVar5 = DAT_182eb5d50;
  *(longlong *)(param_1 + 0x88) = param_2;
  if (uVar5 != 0) {
    uVar6 = (uint)(param_1 + 0x88U >> 0xc);
    lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar12 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
      uVar5 = DAT_182eb5d50;
    } while (!bVar15);
  }
  if (param_2 != 0) {
    *(undefined8 *)(param_1 + 0x70) = *(undefined8 *)(param_2 + 0x70);
    if (uVar5 != 0) {
      uVar5 = (uint)(param_1 + 0x70U >> 0xc);
      lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
      do {
        uVar12 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
        if (bVar15) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar12 | 1L << (uVar5 & 0x3f);
        }
        UNLOCK();
      } while (!bVar15);
    }
    uVar11 = DAT_182d5ae08;
    pcVar10 = DAT_182ec1198;
    if ((DAT_182ec1198 == (code *)0x0) &&
       (pcVar10 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
       pcVar10 == (code *)0x0)) {
      uVar11 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar11,0);
    }
    DAT_182ec1198 = pcVar10;
    bVar4 = (*DAT_182ec1198)(uVar11);
    uVar11 = DAT_182d5ae10;
    pcVar10 = DAT_182ec1198;
    if ((DAT_182ec1198 == (code *)0x0) &&
       (pcVar10 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
       pcVar10 == (code *)0x0)) {
      uVar11 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar11,0);
    }
    DAT_182ec1198 = pcVar10;
    uVar5 = (*DAT_182ec1198)(uVar11);
    if (*(int *)(DAT_182d582a0 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar6 = ExposureUnnoticed2_Scripts_Base_LayerAccessor__get_PlayerBlocker__060017a4(0);
    uVar7 = ExposureUnnoticed2_Scripts_Base_LayerAccessor__get_SpermCollider__060017a6(0);
    uVar8 = ExposureUnnoticed2_Scripts_Base_LayerAccessor__get_XRayLevel__060017a8(0);
    uVar9 = ExposureUnnoticed2_Scripts_Base_LayerAccessor__get_IgnorePeeParticle__060017aa(0);
    lVar1 = *(longlong *)(param_1 + 0x50);
    uVar13 = 0;
    *(int *)(param_1 + 0x78) =
         1 << (bVar4 & 0x1f) | 1 << (uVar5 & 0x1f) | 1 << (uVar6 & 0x1f) | 1 << (uVar7 & 0x1f) |
         1 << (uVar8 & 0x1f) | 1 << (uVar9 & 0x1f);
    if (lVar1 != 0) {
      uVar12 = (ulonglong)DAT_182eb5d50;
      plVar14 = (longlong *)(lVar1 + 0x20);
      for (; (int)uVar13 < *(int *)(lVar1 + 0x18); uVar13 = uVar13 + 1) {
        if (*(uint *)(lVar1 + 0x18) <= uVar13) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dae0();
        }
        lVar2 = *plVar14;
        if (lVar2 == 0) goto LAB_18043727d;
        *(longlong *)(lVar2 + 0x38) = param_2;
        if ((int)uVar12 != 0) {
          uVar5 = (uint)(lVar2 + 0x38U >> 0xc);
          uVar12 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
          do {
            uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
            LOCK();
            bVar15 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
            if (bVar15) {
              *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar3 | 1L << (uVar5 & 0x3f);
            }
            UNLOCK();
          } while (!bVar15);
          uVar12 = (ulonglong)DAT_182eb5d50;
        }
        plVar14 = plVar14 + 1;
      }
      lVar1 = *(longlong *)(param_1 + 0x58);
      if (lVar1 != 0) {
        *(longlong *)(lVar1 + 0x38) = param_2;
        if ((int)uVar12 != 0) {
          uVar5 = (uint)(lVar1 + 0x38U >> 0xc);
          lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
          do {
            uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
            LOCK();
            uVar12 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
            bVar15 = uVar3 == uVar12;
            if (bVar15) {
              *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar5 & 0x3f);
              uVar12 = uVar3;
            }
            UNLOCK();
          } while (!bVar15);
        }
        return uVar12;
      }
    }
  }
LAB_18043727d:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

