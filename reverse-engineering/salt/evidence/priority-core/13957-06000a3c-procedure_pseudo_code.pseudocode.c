// Ghidra pseudocode; not original source or compilable C.
// ev_26603d44fa9e3582abbcedca5343a911420c88e5641e718cc99ba6f48e8a339e

void ExposureUnnoticed2_Object3D_ScenePlops_WasherMachine_WasherMachineController__Update__06000a3c
               (longlong param_1)

{
  int iVar1;
  longlong lVar2;
  code *pcVar3;
  longlong lVar4;
  undefined8 uVar5;
  float fVar6;
  float fVar7;
  
  if (cRam0000000182eb8243 == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58078);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6c188);
    LOCK();
    UNLOCK();
    cRam0000000182eb8243 = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar4 != 0)) {
    if (*(char *)(lVar4 + 0x14) != '\0') {
      return;
    }
    if (((*(longlong *)(param_1 + 0x70) != 0) && (*(longlong *)(param_1 + 0x68) != 0)) &&
       (*(longlong *)(param_1 + 0x38) != 0)) {
      FUN_181ef43f0(*(longlong *)(param_1 + 0x38),
                    *(float *)(*(longlong *)(param_1 + 0x68) + 0x10) *
                    *(float *)(*(longlong *)(param_1 + 0x70) + 0x10),0);
      if (*(int *)(param_1 + 0x4c) != 1) {
        return;
      }
      if (*(longlong *)(param_1 + 0x40) != 0) {
        if (*(longlong *)(param_1 + 0x68) != 0) {
          ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c
                    (*(longlong *)(param_1 + 0x68),
                     *(undefined1 *)(*(longlong *)(param_1 + 0x40) + 0x20),0);
          if ((*(longlong *)(param_1 + 0x68) != 0) && (*(longlong *)(param_1 + 0x30) != 0)) {
            *(undefined4 *)(*(longlong *)(param_1 + 0x30) + 0x28) =
                 *(undefined4 *)(*(longlong *)(param_1 + 0x68) + 0x10);
            fVar7 = *(float *)(param_1 + 0x78);
            pcVar3 = DAT_182ec14d0;
            if ((DAT_182ec14d0 == (code *)0x0) &&
               (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"),
               pcVar3 == (code *)0x0)) {
              uVar5 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar5,0);
            }
            DAT_182ec14d0 = pcVar3;
            fVar6 = (float)(*DAT_182ec14d0)();
            iVar1 = *(int *)(param_1 + 0x50);
            fVar7 = fVar7 - fVar6;
            *(float *)(param_1 + 0x78) = fVar7;
            if (iVar1 != 0) {
              if (iVar1 == 1) {
                if ((*(longlong *)(param_1 + 0x68) == 0) || (*(longlong *)(param_1 + 0x38) == 0))
                goto code_r0x0001805f62da;
                FUN_181ef43f0(*(longlong *)(param_1 + 0x38),
                              *(float *)(*(longlong *)(param_1 + 0x68) + 0x10) *
                              *(float *)(param_1 + 0x60),0);
                if (*(longlong *)(param_1 + 0x38) == 0) goto code_r0x0001805f62da;
                fVar7 = (float)FUN_181ef4450(*(longlong *)(param_1 + 0x38),0);
                if ((*(longlong *)(param_1 + 0x38) == 0) ||
                   (lVar4 = FUN_181ef4500(*(longlong *)(param_1 + 0x38),0), lVar4 == 0))
                goto code_r0x0001805f62da;
                fVar6 = (float)FUN_181ef3480(lVar4,0);
                if (0.95 <= fVar7 / fVar6) {
                  lVar4 = *(longlong *)(param_1 + 0x30);
                  *(undefined4 *)(param_1 + 0x50) = 2;
                  if ((lVar4 == 0) || (lVar2 = *(longlong *)(lVar4 + 0x30), lVar2 == 0))
                  goto code_r0x0001805f62da;
                  if (*(uint *)(lVar2 + 0x18) <= *(uint *)(lVar4 + 0x38)) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dae0();
                  }
                  lVar2 = *(longlong *)(lVar2 + 0x20 + (longlong)(int)*(uint *)(lVar4 + 0x38) * 8);
                  if (lVar2 == 0) goto code_r0x0001805f62da;
                  pcVar3 = DAT_182ebf698;
                  if ((DAT_182ebf698 == (code *)0x0) &&
                     (pcVar3 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.AudioSource::PlayHelper(UnityEngine.AudioSource,System.UInt64)"
                                                  ), pcVar3 == (code *)0x0)) {
                    uVar5 = FUN_1802ced60(
                                         "UnityEngine.AudioSource::PlayHelper(UnityEngine.AudioSource,System.UInt64)"
                                         );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar5,0);
                  }
                  DAT_182ebf698 = pcVar3;
                  (*DAT_182ebf698)(lVar2,0);
                  *(undefined1 *)(lVar4 + 0x4c) = 1;
                  if (*(longlong *)(lVar4 + 0x40) == 0) goto code_r0x0001805f62da;
                  ExposureUnnoticed2_Scripts_Base_SmoothFloat__SetSecond__0600175e();
                  if (*(longlong *)(lVar4 + 0x40) == 0) goto code_r0x0001805f62da;
                  *(undefined4 *)(*(longlong *)(lVar4 + 0x40) + 0x1c) = 0x3f800000;
                }
              }
              else if (iVar1 == 2) {
                if (*(longlong *)(param_1 + 0x70) == 0) goto code_r0x0001805f62da;
                ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
                if (((*(longlong *)(param_1 + 0x70) == 0) || (*(longlong *)(param_1 + 0x68) == 0))
                   || (*(longlong *)(param_1 + 0x38) == 0)) goto code_r0x0001805f62da;
                FUN_181ef43f0(*(longlong *)(param_1 + 0x38),
                              *(float *)(*(longlong *)(param_1 + 0x70) + 0x10) *
                              *(float *)(param_1 + 0x60) *
                              *(float *)(*(longlong *)(param_1 + 0x68) + 0x10),0);
                if (*(float *)(param_1 + 0x78) <= 5.0) {
                  lVar4 = *(longlong *)(param_1 + 0x30);
                  if ((lVar4 == 0) || (*(longlong *)(lVar4 + 0x40) == 0)) goto code_r0x0001805f62da;
                  ExposureUnnoticed2_Scripts_Base_SmoothFloat__SetSecond__0600175e();
                  if (*(longlong *)(lVar4 + 0x40) == 0) goto code_r0x0001805f62da;
                  *(undefined4 *)(*(longlong *)(lVar4 + 0x40) + 0x1c) = 0;
                  *(undefined4 *)(param_1 + 0x50) = 3;
                }
              }
              else if ((iVar1 == 3) && (fVar7 <= 0.0)) {
                if (*(longlong *)(param_1 + 0x70) == 0) goto code_r0x0001805f62da;
                *(undefined4 *)(*(longlong *)(param_1 + 0x70) + 0x10) = 0x3f800000;
                if (((*(longlong *)(param_1 + 0x70) == 0) || (*(longlong *)(param_1 + 0x68) == 0))
                   || (*(longlong *)(param_1 + 0x38) == 0)) goto code_r0x0001805f62da;
                FUN_181ef43f0(*(longlong *)(param_1 + 0x38),
                              *(float *)(*(longlong *)(param_1 + 0x68) + 0x10) *
                              *(float *)(*(longlong *)(param_1 + 0x70) + 0x10),0);
                if (**(longlong **)(DAT_182d58078 + 0xb8) == 0) goto code_r0x0001805f62da;
                ExposureUnnoticed2_Scripts_Sound_InGameSoundManager__PlayOneShotAudioData__060013ed
                          (**(longlong **)(DAT_182d58078 + 0xb8),*(undefined8 *)(param_1 + 0x38),
                           0x5c,0xbf800000,0);
                *(undefined4 *)(param_1 + 0x50) = 0;
              }
            }
            if (*(float *)(param_1 + 0x78) <= 0.0) {
              *(undefined4 *)(param_1 + 0x4c) = 2;
              lVar4 = *(longlong *)(param_1 + 0x58);
              if (*(int *)(DAT_182d6c188 + 0xe0) == 0) {
                FUN_18035c820(DAT_182d6c188);
              }
              if (lVar4 == 0) goto code_r0x0001805f62da;
              FUN_181eea680(lVar4,**(undefined4 **)(DAT_182d6c188 + 0xb8),0,0);
            }
            return;
          }
        }
      }
    }
  }
code_r0x0001805f62da:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

