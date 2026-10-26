// Ghidra pseudocode; not original source or compilable C.
// ev_2f6a15e41d2ee3ce5d559f11bfc567696eb7ef51ac841f4b6c9db7a555d5e470

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController___Initialize_b__30_0__06000d68
               (longlong param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (cRam0000000182eb83e7 == '\0') {
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    cRam0000000182eb83e7 = '\x01';
  }
  if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d58080);
  }
  uVar1 = *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x60);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  ExposureUnnoticed2_Scripts_Base_EventManager__Broadcast__06001716(uVar1,0);
  if ((((*(longlong *)(param_1 + 0x40) != 0) &&
       (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x170), lVar2 != 0)) &&
      (*(longlong *)(lVar2 + 0x40) != 0)) &&
     (lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x40) + 0x48), lVar3 != 0)) {
    *(undefined4 *)(lVar3 + 0x24) = *(undefined4 *)(lVar2 + 0xb0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

