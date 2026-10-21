// Ghidra pseudocode; not original source or compilable C.
// ev_a5d00f37522402ef5953159378225a2a291976a04ab1b22b6bfbd6cf2907b6fa

ulonglong ExposureUnnoticed2_Scripts_Base_InteractManager__Register__06001797
                    (undefined4 param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined8 unaff_RDI;
  uint uVar9;
  bool bVar10;
  
  if (cRam0000000182eb7abc == '\0') {
    FUN_1802f2810(0x182d5ab80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f5e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f5e0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7abc = '\x01';
  }
  if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5ab80);
  }
  lVar4 = **(longlong **)(lRam0000000182d5ab80 + 0xb8);
  lVar7 = FUN_1802c43a0(uRam0000000182d5f5e8);
  if (lVar7 != 0) {
    bVar10 = DAT_182eb5d50 != 0;
    *(undefined4 *)(lVar7 + 0x10) = param_1;
    *(undefined8 *)(lVar7 + 0x18) = param_2;
    if (bVar10) {
      uVar9 = (uint)(lVar7 + 0x18U >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
      do {
        uVar5 = *puVar1;
        LOCK();
        uVar8 = *puVar1;
        if (uVar5 == uVar8) {
          *puVar1 = uVar5 | 1L << (uVar9 & 0x3f);
        }
        UNLOCK();
      } while (uVar5 != uVar8);
    }
    lVar6 = lRam0000000182d5f5e0;
    if (lVar4 != 0) {
      lVar3 = *(longlong *)(lVar4 + 0x10);
      *(int *)(lVar4 + 0x1c) = *(int *)(lVar4 + 0x1c) + 1;
      if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uVar9 = *(uint *)(lVar4 + 0x18);
      if (uVar9 < *(uint *)(lVar3 + 0x18)) {
        uVar8 = (ulonglong)(uVar9 + 1);
        *(uint *)(lVar4 + 0x18) = uVar9 + 1;
        if (*(uint *)(lVar3 + 0x18) <= uVar9) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dae0();
        }
        bVar10 = DAT_182eb5d50 != 0;
        *(longlong *)(lVar3 + 0x20 + (longlong)(int)uVar9 * 8) = lVar7;
        if (bVar10) {
          uVar9 = (uint)((ulonglong)(lVar3 + ((longlong)(int)uVar9 + 4) * 8) >> 0xc);
          puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
          do {
            uVar5 = *puVar1;
            LOCK();
            uVar8 = *puVar1;
            bVar10 = uVar5 == uVar8;
            if (bVar10) {
              *puVar1 = uVar5 | 1L << (uVar9 & 0x3f);
              uVar8 = uVar5;
            }
            UNLOCK();
          } while (!bVar10);
        }
        return uVar8;
      }
      iVar2 = *(int *)(lVar4 + 0x18);
      FUN_18010dcd0(lVar4,iVar2 + 1,
                    *(undefined8 *)
                     (*(longlong *)
                       (*(longlong *)
                         (*(longlong *)(*(longlong *)(*(longlong *)(lVar6 + 0x20) + 0xc0) + 0x70) +
                         0x20) + 0xc0) + 0x78),lVar3,unaff_RDI);
      *(int *)(lVar4 + 0x18) = iVar2 + 1;
      if (*(longlong *)(lVar4 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uVar8 = FUN_180002cd0(*(longlong *)(lVar4 + 0x10),(longlong)iVar2,lVar7);
      return uVar8;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

