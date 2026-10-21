// Ghidra pseudocode; not original source or compilable C.
// ev_5539594bd72be40dd76d8b51714109715cdbdd3466aafda9948653a8e4c25e31

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__OnTimeStopEvent__06001067
               (longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar3;
  longlong lVar4;
  undefined4 uVar5;
  
  if (cRam0000000182eb7760 == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7760 = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar4 != 0)) {
    lVar1 = *(longlong *)(param_1 + 0x30);
    if (lVar1 != 0) {
      if (*(char *)(lVar4 + 0x14) == '\0') {
        if (*(longlong *)(lVar1 + 0x90) != 0) {
          FUN_181eeaba0(*(longlong *)(lVar1 + 0x90),*(undefined4 *)(param_1 + 0x74),0);
          if ((*(longlong *)(param_1 + 0x30) != 0) &&
             (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x30), lVar4 != 0)) {
            UNRECOVERED_JUMPTABLE = pcRam0000000182ebf6f8;
            if ((pcRam0000000182ebf6f8 == (code *)0x0) &&
               (UNRECOVERED_JUMPTABLE = (code *)FUN_1802cf0c0("UnityEngine.AudioSource::UnPause()"),
               UNRECOVERED_JUMPTABLE == (code *)0x0)) {
              uVar3 = FUN_1802ced60("UnityEngine.AudioSource::UnPause()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar3,0);
            }
            pcRam0000000182ebf6f8 = UNRECOVERED_JUMPTABLE;
            (*pcRam0000000182ebf6f8)(lVar4);
            if (((*(longlong *)(param_1 + 0x30) != 0) &&
                (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x50), lVar4 != 0)) &&
               (lVar4 = *(longlong *)(lVar4 + 0x20), lVar4 != 0)) {
              UNRECOVERED_JUMPTABLE = pcRam0000000182ebf6f8;
              if ((pcRam0000000182ebf6f8 == (code *)0x0) &&
                 (UNRECOVERED_JUMPTABLE =
                       (code *)FUN_1802cf0c0("UnityEngine.AudioSource::UnPause()"),
                 UNRECOVERED_JUMPTABLE == (code *)0x0)) {
                uVar3 = FUN_1802ced60("UnityEngine.AudioSource::UnPause()");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar3,0);
              }
              pcRam0000000182ebf6f8 = UNRECOVERED_JUMPTABLE;
              (*pcRam0000000182ebf6f8)(lVar4);
              if ((*(longlong *)(param_1 + 0x30) != 0) &&
                 (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xc0), lVar4 != 0)) {
                lVar4 = *(longlong *)(lVar4 + 0xd0);
                if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                if (DAT_182ec12f4 == '\0') {
                  FUN_1802f2810(&DAT_182d53aa8);
                  LOCK();
                  UNLOCK();
                  DAT_182ec12f4 = '\x01';
                }
                if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                if (DAT_182ec129b == '\0') {
                  FUN_1802f2810(&DAT_182d53aa8);
                  LOCK();
                  UNLOCK();
                  DAT_182ec129b = '\x01';
                }
                if (lVar4 == 0) {
                  return;
                }
                if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                if (*(longlong *)(lVar4 + 0x10) == 0) {
                  return;
                }
                if (((*(longlong *)(param_1 + 0x30) != 0) &&
                    (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xc0), lVar4 != 0)) &&
                   (lVar4 = *(longlong *)(lVar4 + 0xd0), lVar4 != 0)) {
                  UNRECOVERED_JUMPTABLE = pcRam0000000182ec2648;
                  pcVar2 = pcRam0000000182ec2648;
                  if ((pcRam0000000182ec2648 == (code *)0x0) &&
                     (UNRECOVERED_JUMPTABLE =
                           (code *)FUN_1802cf0c0("UnityEngine.ParticleSystem::Play(System.Boolean)")
                     , pcVar2 = UNRECOVERED_JUMPTABLE, UNRECOVERED_JUMPTABLE == (code *)0x0)) {
                    uVar3 = FUN_1802ced60("UnityEngine.ParticleSystem::Play(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar3,0);
                  }
code_r0x00018042a95e:
                  pcRam0000000182ec2648 = pcVar2;
                  (*UNRECOVERED_JUMPTABLE)(lVar4,1);
                  return;
                }
              }
            }
          }
        }
      }
      else {
        lVar4 = *(longlong *)(lVar1 + 0x90);
        if (lVar4 != 0) {
          UNRECOVERED_JUMPTABLE = pcRam0000000182ebf2e8;
          if ((pcRam0000000182ebf2e8 == (code *)0x0) &&
             (UNRECOVERED_JUMPTABLE = (code *)FUN_1802cf0c0("UnityEngine.Animator::get_speed()"),
             UNRECOVERED_JUMPTABLE == (code *)0x0)) {
            uVar3 = FUN_1802ced60("UnityEngine.Animator::get_speed()");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar3,0);
          }
          pcRam0000000182ebf2e8 = UNRECOVERED_JUMPTABLE;
          uVar5 = (*pcRam0000000182ebf2e8)(lVar4);
          *(undefined4 *)(param_1 + 0x74) = uVar5;
          if ((*(longlong *)(param_1 + 0x30) != 0) &&
             (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x90), lVar4 != 0)) {
            UNRECOVERED_JUMPTABLE = DAT_182ebf2f0;
            if ((DAT_182ebf2f0 == (code *)0x0) &&
               (UNRECOVERED_JUMPTABLE =
                     (code *)FUN_1802cf0c0("UnityEngine.Animator::set_speed(System.Single)"),
               UNRECOVERED_JUMPTABLE == (code *)0x0)) {
              uVar3 = FUN_1802ced60("UnityEngine.Animator::set_speed(System.Single)");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar3,0);
            }
            DAT_182ebf2f0 = UNRECOVERED_JUMPTABLE;
            (*DAT_182ebf2f0)(lVar4,0);
            if ((*(longlong *)(param_1 + 0x30) != 0) &&
               (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x30), lVar4 != 0)) {
              UNRECOVERED_JUMPTABLE = pcRam0000000182ebf6f0;
              if ((pcRam0000000182ebf6f0 == (code *)0x0) &&
                 (UNRECOVERED_JUMPTABLE = (code *)FUN_1802cf0c0("UnityEngine.AudioSource::Pause()"),
                 UNRECOVERED_JUMPTABLE == (code *)0x0)) {
                uVar3 = FUN_1802ced60("UnityEngine.AudioSource::Pause()");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar3,0);
              }
              pcRam0000000182ebf6f0 = UNRECOVERED_JUMPTABLE;
              (*pcRam0000000182ebf6f0)(lVar4);
              if (((*(longlong *)(param_1 + 0x30) != 0) &&
                  (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x50), lVar4 != 0)) &&
                 (lVar4 = *(longlong *)(lVar4 + 0x20), lVar4 != 0)) {
                UNRECOVERED_JUMPTABLE = pcRam0000000182ebf6f0;
                if ((pcRam0000000182ebf6f0 == (code *)0x0) &&
                   (UNRECOVERED_JUMPTABLE =
                         (code *)FUN_1802cf0c0("UnityEngine.AudioSource::Pause()"),
                   UNRECOVERED_JUMPTABLE == (code *)0x0)) {
                  uVar3 = FUN_1802ced60("UnityEngine.AudioSource::Pause()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar3,0);
                }
                pcRam0000000182ebf6f0 = UNRECOVERED_JUMPTABLE;
                (*pcRam0000000182ebf6f0)(lVar4);
                if ((*(longlong *)(param_1 + 0x30) != 0) &&
                   (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xc0), lVar4 != 0)) {
                  lVar4 = *(longlong *)(lVar4 + 0xd0);
                  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  if (DAT_182ec12f4 == '\0') {
                    FUN_1802f2810(&DAT_182d53aa8);
                    LOCK();
                    UNLOCK();
                    DAT_182ec12f4 = '\x01';
                  }
                  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  if (DAT_182ec129b == '\0') {
                    FUN_1802f2810(&DAT_182d53aa8);
                    LOCK();
                    UNLOCK();
                    DAT_182ec129b = '\x01';
                  }
                  if (lVar4 == 0) {
                    return;
                  }
                  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  if (*(longlong *)(lVar4 + 0x10) == 0) {
                    return;
                  }
                  if (((*(longlong *)(param_1 + 0x30) != 0) &&
                      (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xc0), lVar4 != 0)) &&
                     (lVar4 = *(longlong *)(lVar4 + 0xd0), lVar4 != 0)) {
                    UNRECOVERED_JUMPTABLE = pcRam0000000182ec2650;
                    pcVar2 = pcRam0000000182ec2648;
                    if (pcRam0000000182ec2650 == (code *)0x0) {
                      UNRECOVERED_JUMPTABLE =
                           (code *)FUN_1802cf0c0("UnityEngine.ParticleSystem::Pause(System.Boolean)"
                                                );
                      if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                        pcRam0000000182ec2650 = UNRECOVERED_JUMPTABLE;
                    /* WARNING: Could not recover jumptable at 0x00018042abaf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                        (*UNRECOVERED_JUMPTABLE)(lVar4,1);
                        return;
                      }
                      uVar3 = FUN_1802ced60("UnityEngine.ParticleSystem::Pause(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar3,0);
                    }
                    goto code_r0x00018042a95e;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

