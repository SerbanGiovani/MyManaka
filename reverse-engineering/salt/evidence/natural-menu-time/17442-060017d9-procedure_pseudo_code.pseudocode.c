// Ghidra pseudocode; not original source or compilable C.
// ev_7979ac1e6c7cefc7de78c60000258c1d2b145860d07e65099a01347a673ae6bf

void ExposureUnnoticed2_Scripts_Base_TimeScaleManager__OnUpdate__060017d9
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  float fVar1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined4 unaff_XMM6_Da;
  undefined4 unaff_XMM6_Db;
  undefined4 unaff_XMM6_Dc;
  undefined4 unaff_XMM6_Dd;
  undefined8 uVar6;
  
  if (cRam0000000182eb7aed == '\0') {
    FUN_1802f2810(0x182d5f410);
    LOCK();
    UNLOCK();
    cRam0000000182eb7aed = '\x01';
  }
  lVar2 = *(longlong *)(param_1 + 0x10);
  uVar5 = CONCAT44(unaff_XMM6_Db,unaff_XMM6_Da);
  uVar6 = CONCAT44(unaff_XMM6_Dd,unaff_XMM6_Dc);
  if (lVar2 != 0) {
    if (*(int *)(lVar2 + 0x18) == 0) {
code_r0x0001804bbf4c:
                    /* WARNING: Subroutine does not return */
      FUN_181640100(0);
    }
    lVar3 = *(longlong *)(lVar2 + 0x10);
    if (lVar3 != 0) {
      if (*(int *)(lVar3 + 0x18) != 0) {
        if (*(char *)(lVar3 + 0x20) == '\0') {
          if (*(uint *)(lVar2 + 0x18) < 2) goto code_r0x0001804bbf4c;
          if (*(uint *)(lVar3 + 0x18) < 2) goto code_r0x0001804bbf46;
          if (*(char *)(lVar3 + 0x21) == '\0') {
            FUN_181f47ed0(*(undefined4 *)(param_1 + 0x18),0,param_3,param_4,uVar5,uVar6);
            fVar1 = *(float *)(param_1 + 0x18);
            pcVar4 = pcRam0000000182ec1500;
            if ((pcRam0000000182ec1500 == (code *)0x0) &&
               (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::set_fixedDeltaTime(System.Single)"
                                               ,0,param_3,param_4,uVar5,uVar6),
               pcVar4 == (code *)0x0)) {
              uVar5 = FUN_1802ced60("UnityEngine.Time::set_fixedDeltaTime(System.Single)");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar5,0);
            }
            pcRam0000000182ec1500 = pcVar4;
                    /* WARNING: Could not recover jumptable at 0x000181f47eac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*pcRam0000000182ec1500)(fVar1 * 0.02);
            return;
          }
          pcVar4 = pcRam0000000182ec1510;
          if ((pcRam0000000182ec1510 == (code *)0x0) &&
             (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::set_timeScale(System.Single)"),
             pcVar4 == (code *)0x0)) {
            uVar5 = FUN_1802ced60("UnityEngine.Time::set_timeScale(System.Single)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar5,0);
          }
          pcRam0000000182ec1510 = pcVar4;
          (*pcRam0000000182ec1510)(0);
          pcVar4 = pcRam0000000182ec1500;
          if ((pcRam0000000182ec1500 == (code *)0x0) &&
             (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::set_fixedDeltaTime(System.Single)"),
             pcVar4 == (code *)0x0)) {
            uVar5 = FUN_1802ced60("UnityEngine.Time::set_fixedDeltaTime(System.Single)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar5,0);
          }
        }
        else {
          pcVar4 = pcRam0000000182ec1510;
          if ((pcRam0000000182ec1510 == (code *)0x0) &&
             (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::set_timeScale(System.Single)"),
             pcVar4 == (code *)0x0)) {
            uVar5 = FUN_1802ced60("UnityEngine.Time::set_timeScale(System.Single)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar5,0);
          }
          pcRam0000000182ec1510 = pcVar4;
          (*pcRam0000000182ec1510)(0);
          pcVar4 = pcRam0000000182ec1500;
          if ((pcRam0000000182ec1500 == (code *)0x0) &&
             (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::set_fixedDeltaTime(System.Single)"),
             pcVar4 == (code *)0x0)) {
            uVar5 = FUN_1802ced60("UnityEngine.Time::set_fixedDeltaTime(System.Single)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar5,0);
          }
        }
        pcRam0000000182ec1500 = pcVar4;
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

