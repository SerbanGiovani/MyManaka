// Ghidra pseudocode; not original source or compilable C.
// ev_1d3307cab920b2d98ea5168ec9b3d7b46dfd86929e4be542fc52a6850e07ff5e

void ExposureUnnoticed2_Scripts_Base_EventManager__Broadcast__06001716(longlong *param_1)

{
  longlong lVar1;
  char cVar2;
  undefined8 uVar3;
  longlong local_res8;
  
  if (DAT_182eb7a98 == '\0') {
    FUN_1802f2810(&DAT_182d5f9b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    DAT_182eb7a98 = '\x01';
  }
  local_res8 = 0;
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d583a0);
  }
  lVar1 = **(longlong **)(DAT_182d583a0 + 0xb8);
  if (param_1 != (longlong *)0x0) {
    uVar3 = FUN_1802c5ac0(*param_1 + 0x20);
    if (lVar1 != 0) {
      cVar2 = FUN_180ebb4c0(lVar1,uVar3,&local_res8,DAT_182d5f9b8);
      if (cVar2 != '\0') {
        if (local_res8 == 0) goto LAB_1804b2038;
        (**(code **)(local_res8 + 0x18))
                  (*(undefined8 *)(local_res8 + 0x40),param_1,*(undefined8 *)(local_res8 + 0x28));
      }
      return;
    }
  }
LAB_1804b2038:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

