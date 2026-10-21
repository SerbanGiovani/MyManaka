// Ghidra pseudocode; not original source or compilable C.
// ev_bb83b5bc4fa3efd6cd80ca7dcb4d6ecaa21ef96f6984d925a1f8d0cbde7c9e39

void ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationEventReceiver___OnAnimBaretaSound_b__4_0__06000fb5
               (longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong *plVar5;
  char cVar6;
  undefined8 uVar7;
  uint uVar8;
  bool bVar9;
  longlong alStackX_8 [4];
  
  if (cRam0000000182eb771c == '\0') {
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    cRam0000000182eb771c = '\x01';
  }
  if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d58080);
  }
  lVar3 = *(longlong *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x28);
  if ((*(longlong *)(param_1 + 0x20) == 0) || (lVar3 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  bVar9 = DAT_182eb5d50 != 0;
  *(undefined8 *)(lVar3 + 0x10) = *(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0x38);
  if (bVar9) {
    uVar8 = (uint)(lVar3 + 0x10U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8);
    do {
      uVar4 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar4 == uVar2) {
        *puVar1 = uVar4 | 1L << (ulonglong)(uVar8 & 0x3f);
      }
      UNLOCK();
    } while (uVar4 != uVar2);
  }
  plVar5 = *(longlong **)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x28);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182eb7a98 == '\0') {
    FUN_1802f2810(&DAT_182d5f9b8,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    DAT_182eb7a98 = '\x01';
  }
  alStackX_8[0] = 0;
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d583a0);
  }
  lVar3 = **(longlong **)(DAT_182d583a0 + 0xb8);
  if ((plVar5 != (longlong *)0x0) && (uVar7 = FUN_1802c5ac0(*plVar5 + 0x20), lVar3 != 0)) {
    cVar6 = FUN_180ebb4c0(lVar3,uVar7,alStackX_8,DAT_182d5f9b8);
    if (cVar6 != '\0') {
      if (alStackX_8[0] == 0) goto LAB_1804b2038;
      (**(code **)(alStackX_8[0] + 0x18))
                (*(undefined8 *)(alStackX_8[0] + 0x40),plVar5,*(undefined8 *)(alStackX_8[0] + 0x28))
      ;
    }
    return;
  }
LAB_1804b2038:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

