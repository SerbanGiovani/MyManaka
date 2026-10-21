// Ghidra pseudocode; not original source or compilable C.
// ev_2d0366baa88f60ea473073a5196275264bbbb2a1ec0f207a59bed5ecd7f429a6

void ExposureUnnoticed2_Scripts_Base_SystemManager__Update__060017d3
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  float fVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  code *pcVar5;
  undefined8 uVar6;
  undefined4 unaff_XMM6_Da;
  undefined4 unaff_XMM6_Db;
  undefined4 unaff_XMM6_Dc;
  undefined4 unaff_XMM6_Dd;
  undefined8 uVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x20);
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (cRam0000000182eb7aed == '\0') {
    FUN_1802f2810(0x182d5f410);
    LOCK();
    UNLOCK();
    cRam0000000182eb7aed = '\x01';
  }
  lVar3 = *(longlong *)(lVar2 + 0x10);
  uVar6 = CONCAT44(unaff_XMM6_Db,unaff_XMM6_Da);
  uVar7 = CONCAT44(unaff_XMM6_Dd,unaff_XMM6_Dc);
  if (lVar3 != 0) {
    if (*(int *)(lVar3 + 0x18) == 0) {
code_r0x0001804bbf4c:
                    /* WARNING: Subroutine does not return */
      FUN_181640100(0);
    }
    lVar4 = *(longlong *)(lVar3 + 0x10);
    if (lVar4 != 0) {
      if (*(int *)(lVar4 + 0x18) != 0) {
        if (*(char *)(lVar4 + 0x20) == '\0') {
          if (*(uint *)(lVar3 + 0x18) < 2) goto code_r0x0001804bbf4c;
          if (*(uint *)(lVar4 + 0x18) < 2) goto code_r0x0001804bbf46;
          if (*(char *)(lVar4 + 0x21) == '\0') {
            FUN_181f47ed0(*(undefined4 *)(lVar2 + 0x18),0,param_3,param_4,uVar6,uVar7);
            fVar1 = *(float *)(lVar2 + 0x18);
            pcVar5 = pcRam0000000182ec1500;
            if ((pcRam0000000182ec1500 == (code *)0x0) &&
               (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::set_fixedDeltaTime(System.Single)"
                                               ,0,param_3,param_4,uVar6,uVar7),
               pcVar5 == (code *)0x0)) {
              uVar6 = FUN_1802ced60("UnityEngine.Time::set_fixedDeltaTime(System.Single)");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar6,0);
            }
            pcRam0000000182ec1500 = pcVar5;
                    /* WARNING: Could not recover jumptable at 0x000181f47eac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*pcRam0000000182ec1500)(fVar1 * 0.02);
            return;
          }
          pcVar5 = pcRam0000000182ec1510;
          if ((pcRam0000000182ec1510 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::set_timeScale(System.Single)"),
             pcVar5 == (code *)0x0)) {
            uVar6 = FUN_1802ced60("UnityEngine.Time::set_timeScale(System.Single)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar6,0);
          }
          pcRam0000000182ec1510 = pcVar5;
          (*pcRam0000000182ec1510)(0);
          pcVar5 = pcRam0000000182ec1500;
          if ((pcRam0000000182ec1500 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::set_fixedDeltaTime(System.Single)"),
             pcVar5 == (code *)0x0)) {
            uVar6 = FUN_1802ced60("UnityEngine.Time::set_fixedDeltaTime(System.Single)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar6,0);
          }
        }
        else {
          pcVar5 = pcRam0000000182ec1510;
          if ((pcRam0000000182ec1510 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::set_timeScale(System.Single)"),
             pcVar5 == (code *)0x0)) {
            uVar6 = FUN_1802ced60("UnityEngine.Time::set_timeScale(System.Single)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar6,0);
          }
          pcRam0000000182ec1510 = pcVar5;
          (*pcRam0000000182ec1510)(0);
          pcVar5 = pcRam0000000182ec1500;
          if ((pcRam0000000182ec1500 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::set_fixedDeltaTime(System.Single)"),
             pcVar5 == (code *)0x0)) {
            uVar6 = FUN_1802ced60("UnityEngine.Time::set_fixedDeltaTime(System.Single)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar6,0);
          }
        }
        pcRam0000000182ec1500 = pcVar5;
                    /* WARNING: Could not recover jumptable at 0x0001804bbee1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*pcRam0000000182ec1500)(0);
        return;
      }
code_r0x0001804bbf46:
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

