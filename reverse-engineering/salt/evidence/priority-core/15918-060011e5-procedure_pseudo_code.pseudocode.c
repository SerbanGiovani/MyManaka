// Ghidra pseudocode; not original source or compilable C.
// ev_0c9ec97bef1ce3757a2580601fecf1bfb0364d5200aec1433ee272ba2906c4ce

void ExposureUnnoticed2_Object3D_Camera_BaseCameraController__Initialize__060011e5
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
               longlong param_5,longlong param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  code *pcVar8;
  bool bVar9;
  
  if (cRam0000000182eb7814 == '\0') {
    FUN_1802f2810(0x182d5c8d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58298);
    LOCK();
    UNLOCK();
    cRam0000000182eb7814 = '\x01';
  }
  iVar3 = DAT_182eb5d50;
  *(undefined8 *)(param_1 + 0x60) = param_3;
  if (iVar3 != 0) {
    uVar5 = (uint)(param_1 + 0x60U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar9 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
      iVar3 = DAT_182eb5d50;
    } while (!bVar9);
  }
  *(longlong *)(param_1 + 0x30) = param_4;
  iVar4 = 0;
  if (iVar3 != 0) {
    uVar5 = (uint)(param_1 + 0x30U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar9 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
      iVar4 = DAT_182eb5d50;
    } while (!bVar9);
  }
  *(longlong *)(param_1 + 0x38) = param_5;
  iVar3 = 0;
  if (iVar4 != 0) {
    uVar5 = (uint)(param_1 + 0x38U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar9 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
      iVar3 = DAT_182eb5d50;
    } while (!bVar9);
  }
  *(longlong *)(param_1 + 0x40) = param_6;
  if (iVar3 != 0) {
    uVar5 = (uint)(param_1 + 0x40U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar9 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar9);
  }
  uVar7 = FUN_180735660(param_1,uRam0000000182d5c8d0);
  bVar9 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x20) = uVar7;
  if (bVar9) {
    uVar5 = (uint)(param_1 + 0x20U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar9 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar9);
  }
  if ((param_4 != 0) &&
     (ExposureUnnoticed2_Object3D_Camera_TPCameraController__Initialize__06001211
                (param_4,param_2,param_1,0), iVar3 = DAT_182eb5d50, param_5 != 0)) {
    *(undefined8 *)(param_5 + 0x48) = param_2;
    if (iVar3 != 0) {
      uVar5 = (uint)(param_5 + 0x48U >> 0xc);
      lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        bVar9 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
        if (bVar9) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
        }
        UNLOCK();
        iVar3 = DAT_182eb5d50;
      } while (!bVar9);
    }
    *(longlong *)(param_5 + 0x68) = param_1;
    if (iVar3 != 0) {
      uVar5 = (uint)(param_5 + 0x68U >> 0xc);
      lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        bVar9 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
        if (bVar9) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
        }
        UNLOCK();
      } while (!bVar9);
    }
    if (param_6 != 0) {
      ExposureUnnoticed2_Object3D_Camera_InventoryCameraController__Initialize__06001206
                (param_6,param_2,0);
      uVar7 = FUN_180735660(param_1,uRam0000000182d5c8d0);
      bVar9 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x58) = uVar7;
      if (bVar9) {
        uVar5 = (uint)(param_1 + 0x58U >> 0xc);
        lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
          LOCK();
          bVar9 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
          if (bVar9) {
            *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
          }
          UNLOCK();
        } while (!bVar9);
      }
      lVar1 = *(longlong *)(param_1 + 0x58);
      if (lVar1 != 0) {
        pcVar8 = pcRam0000000182ebfad8;
        if ((pcRam0000000182ebfad8 == (code *)0x0) &&
           (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.Camera::get_cullingMask()"),
           pcVar8 == (code *)0x0)) {
          uVar7 = FUN_1802ced60("UnityEngine.Camera::get_cullingMask()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar7,0);
        }
        pcRam0000000182ebfad8 = pcVar8;
        uVar5 = (*pcRam0000000182ebfad8)(lVar1);
        *(uint *)(param_1 + 0x50) = uVar5;
        uVar7 = DAT_182d58298;
        pcVar8 = DAT_182ec1198;
        if ((DAT_182ec1198 == (code *)0x0) &&
           (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.LayerMask::NameToLayer(System.String)"),
           pcVar8 == (code *)0x0)) {
          uVar7 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar7,0);
        }
        DAT_182ec1198 = pcVar8;
        uVar6 = (*DAT_182ec1198)(uVar7);
        *(uint *)(param_1 + 0x54) = uVar5 & ~(1 << (uVar6 & 0x1f));
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

