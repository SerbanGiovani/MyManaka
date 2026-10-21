// Ghidra pseudocode; not original source or compilable C.
// ev_f6a110d6ed71ce765a713eb09efab82c8970f86a61172e269b1a15b46d7ce361

void __c__DisplayClass42_0___LoadAssetAsync_b__0__060000c9(longlong param_1)

{
  ulonglong *puVar1;
  longlong *plVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  code *pcVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  undefined8 *puVar13;
  ulonglong uVar14;
  bool bVar15;
  
  if (cRam0000000182ebaae0 == '\0') {
    FUN_1802f2810(0x182d26118);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d26120);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d649b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d649a8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaae0 = '\x01';
  }
  lVar7 = *(longlong *)(param_1 + 0x10);
  if (lVar7 != 0) {
    pcVar6 = pcRam0000000182ebf638;
    if ((pcRam0000000182ebf638 == (code *)0x0) &&
       (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.AssetBundleRequest::get_allAssets()"),
       pcVar6 == (code *)0x0)) {
      uVar8 = func_0x0001802ced60("UnityEngine.AssetBundleRequest::get_allAssets()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar8,0);
    }
    pcRam0000000182ebf638 = pcVar6;
    lVar7 = (*pcRam0000000182ebf638)(lVar7);
    if (lVar7 != 0) {
      if (*(int *)(lVar7 + 0x18) < 2) {
        plVar2 = *(longlong **)(param_1 + 0x10);
        lVar7 = *(longlong *)(param_1 + 0x20);
        if ((plVar2 != (longlong *)0x0) &&
           (uVar8 = (**(code **)(*plVar2 + 0x178))(plVar2,*(undefined8 *)(*plVar2 + 0x180)),
           lVar7 != 0)) {
          (**(code **)(lVar7 + 0x18))
                    (*(undefined8 *)(lVar7 + 0x40),uVar8,*(undefined8 *)(lVar7 + 0x28));
          return;
        }
      }
      else {
        lVar7 = FUN_1802c43a0(uRam0000000182d649a8);
        if ((*(longlong *)(param_1 + 0x18) != 0) &&
           (uVar8 = System_String__Split__06000238(*(longlong *)(param_1 + 0x18),0x3e,0,0),
           lVar7 != 0)) {
          bVar15 = DAT_182eb5d50 != 0;
          *(undefined8 *)(lVar7 + 0x10) = uVar8;
          if (bVar15) {
            uVar5 = (uint)(lVar7 + 0x10U >> 0xc);
            puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
            do {
              uVar12 = *puVar1;
              LOCK();
              uVar14 = *puVar1;
              if (uVar12 == uVar14) {
                *puVar1 = uVar12 | 1L << (uVar5 & 0x3f);
              }
              UNLOCK();
            } while (uVar12 != uVar14);
          }
          lVar3 = *(longlong *)(param_1 + 0x20);
          lVar9 = *(longlong *)(param_1 + 0x10);
          if (lVar9 != 0) {
            pcVar6 = pcRam0000000182ebf638;
            if ((pcRam0000000182ebf638 == (code *)0x0) &&
               (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.AssetBundleRequest::get_allAssets()"),
               pcVar6 == (code *)0x0)) {
              uVar8 = func_0x0001802ced60("UnityEngine.AssetBundleRequest::get_allAssets()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar8,0);
            }
            pcRam0000000182ebf638 = pcVar6;
            lVar9 = (*pcRam0000000182ebf638)(lVar9);
            lVar10 = FUN_1802c43a0(uRam0000000182d26120);
            FUN_1810d6200(lVar10,lVar7,uRam0000000182d649b0,0);
            lVar7 = lRam0000000182d26118;
            if (*(longlong *)(lRam0000000182d26118 + 0x38) == 0) {
              FUN_1803204f0(lRam0000000182d26118);
            }
            if (lVar9 == 0) {
              uVar8 = thunk_FUN_1802f2810(&DAT_182d528c8);
              uVar8 = thunk_FUN_1802c43a0(uVar8);
              uVar11 = thunk_FUN_1802f2810(0x182d4cfe8);
              FUN_1815c6a10(uVar8,uVar11,0);
                    /* WARNING: Subroutine does not return */
              FUN_18031da90(uVar8,lVar7);
            }
            if (lVar10 == 0) {
              uVar8 = thunk_FUN_1802f2810(&DAT_182d528c8);
              uVar8 = thunk_FUN_1802c43a0(uVar8);
              uVar11 = thunk_FUN_1802f2810(0x182d4e4f8);
              FUN_1815c6a10(uVar8,uVar11,0);
                    /* WARNING: Subroutine does not return */
              FUN_18031da90(uVar8,lVar7);
            }
            puVar13 = (undefined8 *)(lVar9 + 0x20);
            uVar14 = 0;
            uVar12 = uVar14;
            while (uVar5 = (uint)uVar12, (int)uVar5 < *(int *)(lVar9 + 0x18)) {
              if (*(uint *)(lVar9 + 0x18) <= uVar5) {
code_r0x000181440415:
                    /* WARNING: Subroutine does not return */
                FUN_18031dae0();
              }
              cVar4 = (**(code **)(lVar10 + 0x18))
                                (*(undefined8 *)(lVar10 + 0x40),*puVar13,
                                 *(undefined8 *)(lVar10 + 0x28));
              if (cVar4 != '\0') {
                if (*(uint *)(lVar9 + 0x18) <= uVar5) goto code_r0x000181440415;
                uVar14 = *(ulonglong *)(lVar9 + 0x20 + (longlong)(int)uVar5 * 8);
                break;
              }
              puVar13 = puVar13 + 1;
              uVar12 = (ulonglong)(uVar5 + 1);
            }
            if (lVar3 != 0) {
              (**(code **)(lVar3 + 0x18))
                        (*(undefined8 *)(lVar3 + 0x40),uVar14,*(undefined8 *)(lVar3 + 0x28));
              return;
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

