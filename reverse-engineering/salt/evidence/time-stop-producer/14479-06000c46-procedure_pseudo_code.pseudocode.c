// Ghidra pseudocode; not original source or compilable C.
// ev_9f214ac55619ac5992c9a845ce69187057c92445b19d2edc9d0063161bfc1335

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationReceiver__OnChangeTimeStop__06000c46
               (void)

{
  longlong lVar1;
  longlong *plVar2;
  char cVar3;
  undefined8 uVar4;
  longlong alStackX_8 [4];
  
  if (cRam0000000182eb8374 == '\0') {
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb8374 = '\x01';
  }
  if (DAT_182eb548c == '\0') {
    FUN_1802f2810(&DAT_182d57a70);
    LOCK();
    UNLOCK();
    DAT_182eb548c = '\x01';
  }
  if (**(longlong **)(DAT_182d57a70 + 0xb8) != 0) {
    if (*(char *)(**(longlong **)(DAT_182d57a70 + 0xb8) + 0x5a) != '\0') {
      cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                        (0x15,0);
      if (cVar3 == '\0') {
        cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                          (0x16,0);
        if (cVar3 == '\0') {
          return;
        }
      }
    }
    if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
       (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar1 != 0)) {
      *(bool *)(lVar1 + 0x14) = *(char *)(lVar1 + 0x14) == '\0';
      if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d58080);
      }
      plVar2 = *(longlong **)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xa0);
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
      lVar1 = **(longlong **)(DAT_182d583a0 + 0xb8);
      if (plVar2 != (longlong *)0x0) {
        uVar4 = FUN_1802c5ac0(*plVar2 + 0x20);
        if (lVar1 != 0) {
          cVar3 = FUN_180ebb4c0(lVar1,uVar4,alStackX_8,DAT_182d5f9b8);
          if (cVar3 != '\0') {
            if (alStackX_8[0] == 0) goto LAB_1804b2038;
            (**(code **)(alStackX_8[0] + 0x18))
                      (*(undefined8 *)(alStackX_8[0] + 0x40),plVar2,
                       *(undefined8 *)(alStackX_8[0] + 0x28));
          }
          return;
        }
      }
LAB_1804b2038:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

