// Ghidra pseudocode; not original source or compilable C.
// ev_d5f7d8fce99a2d2349519e2a9e567ebd4b93b1fdb33840d698d6912c02c05e01

void ExposureUnnoticed2_Scripts_Mission_MissionBase__RiseRp__06001423
               (longlong param_1,float param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  float fVar3;
  
  if (cRam0000000182eb78fc == '\0') {
    FUN_1802f2810(0x182d5e218);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb78fc = '\x01';
  }
  ExposureUnnoticed2_Scripts_InGame_GameStateFacade__RiseEarnRp__06001530(param_2,0);
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (((lVar2 != 0) && (*(longlong *)(param_1 + 0x28) != 0)) &&
     (lVar2 = *(longlong *)(lVar2 + 0x110), lVar2 != 0)) {
    uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x50);
    fVar3 = (float)FUN_180005b40(lVar2,uVar1);
    FUN_180e59ff0(lVar2,uVar1,fVar3 + param_2,1,
                  *(undefined8 *)
                   (*(longlong *)(*(longlong *)(lRam0000000182d5e230 + 0x20) + 0xc0) + 0x100));
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

