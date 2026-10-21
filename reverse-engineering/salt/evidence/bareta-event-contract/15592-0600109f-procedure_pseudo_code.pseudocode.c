// Ghidra pseudocode; not original source or compilable C.
// ev_30a45ff1fff439793ee4afe68e709453a28b8edb697856452c3e1cc42ebf9bfb

void ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__OnGameOverEvent__0600109f(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  code *pcVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  bool bVar8;
  undefined8 uStack_40;
  undefined4 *puStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  longlong lStack_18;
  
  if (cRam0000000182eb7775 == '\0') {
    FUN_1802f2810(&DAT_182d595a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59598);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59590);
    LOCK();
    UNLOCK();
    FUN_1802f2810();
    LOCK();
    UNLOCK();
    cRam0000000182eb7775 = '\x01';
  }
  lVar1 = *(longlong *)(param_1 + 0x38);
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)((ulonglong)&uStack_40 >> 0xc);
    uVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
      LOCK();
      bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar2 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
  uStack_1c = *(undefined4 *)(lVar1 + 0x1c);
  uStack_30 = 0;
  uStack_40._0_4_ = (undefined4)lVar1;
  uStack_40._4_4_ = (undefined4)((ulonglong)lVar1 >> 0x20);
  uStack_28 = (undefined4)uStack_40;
  uStack_24 = uStack_40._4_4_;
  uStack_20 = 0;
  lStack_18 = 0;
  uStack_40 = 0;
  puStack_38 = &uStack_28;
  while( true ) {
    cVar3 = FUN_180f72b70(&uStack_28,DAT_182d59598);
    if (cVar3 == '\0') {
      return;
    }
    if (lStack_18 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(longlong *)(lStack_18 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    lVar1 = *(longlong *)(*(longlong *)(lStack_18 + 0x30) + 0x90);
    if (lVar1 == 0) break;
    pcVar4 = DAT_182ebf2f0;
    if ((DAT_182ebf2f0 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Animator::set_speed(System.Single)"),
       pcVar4 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Animator::set_speed(System.Single)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ebf2f0 = pcVar4;
    (*DAT_182ebf2f0)(lVar1,0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

