// Ghidra pseudocode; not original source or compilable C.
// ev_a821afd5ae342b8418df50c0a2fd7a2349534868b65df37efa4f84f44c4d285c

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__OnCompleteTransitionStageEvent__06000def
               (longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  
  if (cRam0000000182eb8424 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb8424 = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x78) != 0) &&
     (lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48), lVar1 != 0)) {
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0xd8);
    uVar5 = 7;
    if (*(int *)(lVar1 + 0x10) == 10) {
      uVar5 = 0xe;
    }
    if (lVar2 != 0) {
      pcVar3 = DAT_182ebee88;
      if ((DAT_182ebee88 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.AI.NavMeshAgent::set_areaMask(System.Int32)"),
         pcVar3 == (code *)0x0)) {
        uVar4 = FUN_1802ced60("UnityEngine.AI.NavMeshAgent::set_areaMask(System.Int32)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      DAT_182ebee88 = pcVar3;
      (*DAT_182ebee88)(lVar2,uVar5);
      *(undefined4 *)(param_1 + 0x14) = 10;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

