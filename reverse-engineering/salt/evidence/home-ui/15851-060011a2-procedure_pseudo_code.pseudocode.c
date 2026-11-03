// Ghidra pseudocode; not original source or compilable C.
// ev_df33b71f474ca973037a865a16f37c08f5fe80f9a6f39023a96e4aa08de5aefc

ulonglong ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__PushBasePanel__060011a2
                    (longlong param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined8 unaff_RDI;
  uint uVar8;
  bool bVar9;
  
  if (cRam0000000182eb77f2 == '\0') {
    FUN_1802f2810(0x182d5a998);
    LOCK();
    UNLOCK();
    cRam0000000182eb77f2 = '\x01';
  }
  lVar6 = lRam0000000182d5a998;
  lVar4 = *(longlong *)(param_1 + 0x178);
  if (lVar4 != 0) {
    *(int *)(lVar4 + 0x1c) = *(int *)(lVar4 + 0x1c) + 1;
    lVar5 = *(longlong *)(lVar4 + 0x10);
    if (lVar5 != 0) {
      uVar8 = *(uint *)(lVar4 + 0x18);
      if (uVar8 < *(uint *)(lVar5 + 0x18)) {
        uVar7 = (ulonglong)(uVar8 + 1);
        *(uint *)(lVar4 + 0x18) = uVar8 + 1;
        if (*(uint *)(lVar5 + 0x18) <= uVar8) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dae0();
        }
        bVar9 = DAT_182eb5d50 != 0;
        *(undefined8 *)(lVar5 + 0x20 + (longlong)(int)uVar8 * 8) = param_2;
        if (bVar9) {
          uVar8 = (uint)((ulonglong)(lVar5 + ((longlong)(int)uVar8 + 4) * 8) >> 0xc);
          puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8);
          do {
            uVar3 = *puVar1;
            LOCK();
            uVar7 = *puVar1;
            bVar9 = uVar3 == uVar7;
            if (bVar9) {
              *puVar1 = uVar3 | 1L << (uVar8 & 0x3f);
              uVar7 = uVar3;
            }
            UNLOCK();
          } while (!bVar9);
        }
        return uVar7;
      }
      iVar2 = *(int *)(lVar4 + 0x18);
      FUN_18010dcd0(lVar4,iVar2 + 1,
                    *(undefined8 *)
                     (*(longlong *)
                       (*(longlong *)
                         (*(longlong *)(*(longlong *)(*(longlong *)(lVar6 + 0x20) + 0xc0) + 0x70) +
                         0x20) + 0xc0) + 0x78),lVar5,unaff_RDI);
      *(int *)(lVar4 + 0x18) = iVar2 + 1;
      if (*(longlong *)(lVar4 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uVar7 = FUN_180002cd0(*(longlong *)(lVar4 + 0x10),(longlong)iVar2,param_2);
      return uVar7;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

