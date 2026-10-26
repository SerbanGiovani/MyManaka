// Ghidra pseudocode; not original source or compilable C.
// ev_f3819329f5ba3d285baac81f4e29275451a3f3efa59ca063c6a2c7b878b4854d

void ExposureUnnoticed2_Scripts_Mission_MissionStopElevatorNaked__Reset__0600148c(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  ExposureUnnoticed2_Scripts_Mission_MissionBase__Reset__06001426(param_1,0);
  lVar1 = *(longlong *)(param_1 + 0x58);
  uVar4 = 0;
  *(undefined8 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0xffffffff;
  uVar3 = uVar4;
  while (lVar1 != 0) {
    uVar2 = (uint)uVar3;
    if (*(int *)(lVar1 + 0x18) <= (int)uVar2) {
      return;
    }
    lVar1 = *(longlong *)(param_1 + 0x58);
    if (lVar1 == 0) break;
    if (*(uint *)(lVar1 + 0x18) <= uVar2) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    *(undefined1 *)(uVar4 + 0x20 + lVar1) = 0;
    uVar4 = uVar4 + 1;
    uVar3 = (ulonglong)(uVar2 + 1);
    lVar1 = *(longlong *)(param_1 + 0x58);
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

