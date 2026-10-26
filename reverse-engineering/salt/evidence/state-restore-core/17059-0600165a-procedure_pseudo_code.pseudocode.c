// Ghidra pseudocode; not original source or compilable C.
// ev_9683112c5e4f50ec537f5fbda8cc803131141ea97dfb1ecd5961cbc7b894a59c

undefined8
ExposureUnnoticed2_Scripts_InGame_StageController__GetSpawnPoint__0600165a
          (longlong param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  longlong *plVar5;
  
  if (cRam0000000182eb7a32 == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a32 = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x60), lVar1 != 0)) {
    if (*(longlong *)(param_1 + 0xd0) != 0) {
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0xd0) + 0x20);
      uVar4 = 0;
      if (lVar2 != 0) {
        plVar5 = (longlong *)(lVar2 + 0x20);
        while( true ) {
          if ((int)*(uint *)(lVar2 + 0x18) <= (int)uVar4) {
            return 0;
          }
          if (*(uint *)(lVar2 + 0x18) <= uVar4) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
          lVar3 = *plVar5;
          if (lVar3 == 0) break;
          if ((*(int *)(lVar3 + 0x20) == param_2) &&
             (*(int *)(lVar3 + 0x30) == *(int *)(lVar1 + 0x10))) {
            return *(undefined8 *)(lVar3 + 0x28);
          }
          uVar4 = uVar4 + 1;
          plVar5 = plVar5 + 1;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

