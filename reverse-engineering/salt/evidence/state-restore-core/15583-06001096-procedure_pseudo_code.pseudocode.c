// Ghidra pseudocode; not original source or compilable C.
// ev_c281194f583fffd9abdef71e12a560d89870827edb9f051e87c4722949c45664

void ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__OnLoadData__06001096(longlong param_1)

{
  ulonglong uVar1;
  int iVar2;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  code *pcVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  uint uVar9;
  bool bVar10;
  undefined8 uVar11;
  undefined8 uStack_68;
  undefined4 uStack_60;
  undefined8 uStack_58;
  undefined4 *puStack_50;
  undefined8 uStack_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined8 uStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  if (cRam0000000182eb776d == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d59578);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d59570);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d59560);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d59550);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d59548);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d59540);
    LOCK();
    UNLOCK();
    cRam0000000182eb776d = '\x01';
  }
  uStack_28 = 0;
  uStack_20 = 0;
  uStack_18 = 0;
  *(undefined1 *)(param_1 + 0x65) = 1;
  lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar4 == 0) || (lVar4 = *(longlong *)(lVar4 + 0x40), lVar4 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (DAT_182eb5d50 != 0) {
    uVar9 = (uint)((ulonglong)&uStack_58 >> 0xc);
    uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
      LOCK();
      bVar10 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
      if (bVar10) {
        *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar1 | 1L << (uVar9 & 0x3f);
      }
      UNLOCK();
    } while (!bVar10);
  }
  uStack_34 = *(undefined4 *)(lVar4 + 0x1c);
  uStack_48 = 0;
  uStack_58._0_4_ = (undefined4)lVar4;
  uStack_58._4_4_ = (undefined4)((ulonglong)lVar4 >> 0x20);
  uStack_40 = (undefined4)uStack_58;
  uStack_3c = uStack_58._4_4_;
  uStack_38 = 0;
  uStack_30 = 0;
  uStack_58 = 0;
  puStack_50 = &uStack_40;
code_r0x00018042f4c0:
  do {
    cVar3 = FUN_180f72b70(&uStack_40,uRam0000000182d59570);
    if (cVar3 == '\0') {
      return;
    }
    lVar4 = FUN_1802c43a0(uRam0000000182d59540);
    if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    *(longlong *)(lVar4 + 0x18) = param_1;
    if (DAT_182eb5d50 != 0) {
      uVar9 = (uint)(lVar4 + 0x18U >> 0xc);
      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        LOCK();
        bVar10 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        if (bVar10) {
          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar1 | 1L << (uVar9 & 0x3f);
        }
        UNLOCK();
      } while (!bVar10);
    }
    iVar2 = DAT_182eb5d50;
    *(undefined8 *)(lVar4 + 0x10) = uStack_30;
    if (iVar2 != 0) {
      uVar9 = (uint)(lVar4 + 0x10U >> 0xc);
      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        LOCK();
        bVar10 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        if (bVar10) {
          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar1 | 1L << (uVar9 & 0x3f);
        }
        UNLOCK();
      } while (!bVar10);
    }
    if (*(longlong *)(lVar4 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  } while (*(char *)(*(longlong *)(lVar4 + 0x10) + 0x2c) == '\0');
  lVar5 = FUN_180436630();
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
  if (lVar5 == 0) {
    bVar10 = false;
  }
  else {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    bVar10 = *(longlong *)(lVar5 + 0x10) != 0;
  }
  if (bVar10) goto code_r0x00018042f642;
  goto code_r0x00018042f6be;
code_r0x00018042f642:
  lVar5 = FUN_180436630();
  if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uStack_28 = *(undefined8 *)(lVar5 + 0x5c);
  uStack_20 = *(undefined8 *)(lVar5 + 100);
  uStack_18 = *(undefined8 *)(lVar5 + 0x6c);
  lVar5 = *(longlong *)(lVar4 + 0x10);
  if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uStack_68 = *(undefined8 *)(lVar5 + 0x10);
  uStack_60 = *(undefined4 *)(lVar5 + 0x18);
  pcVar6 = pcRam0000000182ebfdb8;
  if ((pcRam0000000182ebfdb8 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                    ), pcVar6 == (code *)0x0)) {
    uVar7 = FUN_1802ced60(
                         "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                         );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar7,0);
  }
  pcRam0000000182ebfdb8 = pcVar6;
  cVar3 = (*pcRam0000000182ebfdb8)(&uStack_28,&uStack_68);
  if (cVar3 == '\0') {
code_r0x00018042f6be:
    uVar7 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(uVar7,lVar4,uRam0000000182d59548,0);
    uVar11 = FUN_181f373e0(0);
    ExposureUnnoticed2_Scripts_Base_Scheduler__DelayUnscaledTime__0600174c(uVar7,uVar11,0);
  }
  goto code_r0x00018042f4c0;
}

