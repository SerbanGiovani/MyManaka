// Ghidra pseudocode; not original source or compilable C.
// ev_9822d1a4a7bf067b119779e75b3a8eca0383d0d5500d2fdafe7d9e0078fc9abd

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__OnUpdate__06000c75
               (float param_1,longlong param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong in_RCX;
  
  if (cRam0000000182eb8388 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f340);
    LOCK();
    UNLOCK();
    param_1 = (float)FUN_1802f2810(&DAT_182d57e50);
    LOCK();
    UNLOCK();
    cRam0000000182eb8388 = '\x01';
  }
  lVar3 = *(longlong *)(in_RCX + 0x30);
  if (*(int *)(lRam0000000182d6f340 + 0xe0) == 0) {
    param_1 = (float)FUN_18035c820(lRam0000000182d6f340);
  }
  if ((*(longlong *)(in_RCX + 0x38) == 0) || (lVar3 == 0)) goto code_r0x00018062d638;
  param_1 = (float)FUN_181eea680(lVar3,*(undefined4 *)
                                        (*(longlong *)(lRam0000000182d6f340 + 0xb8) + 0x18),
                                 *(undefined1 *)(*(longlong *)(in_RCX + 0x38) + 0x1b),0);
  if (*(char *)(in_RCX + 0x20) == '\0') {
    if (*(longlong *)(in_RCX + 0x38) == 0) goto code_r0x00018062d638;
    if (*(char *)(*(longlong *)(in_RCX + 0x38) + 0x1a) != '\0') {
      if (param_2 == 0) goto code_r0x00018062d638;
      param_1 = *(float *)(param_2 + 0x14) * *(float *)(param_2 + 0x14);
    }
  }
  if ((((*(longlong *)(in_RCX + 0x58) == 0) ||
       (param_1 = (float)ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c(),
       *(longlong *)(in_RCX + 0x60) == 0)) ||
      (param_1 = (float)ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c(),
      *(longlong *)(in_RCX + 0x60) == 0)) || (lVar3 = *(longlong *)(in_RCX + 0x30), lVar3 == 0))
  goto code_r0x00018062d638;
  pcVar2 = pcRam0000000182ebf2d8;
  if ((pcRam0000000182ebf2d8 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Animator::SetLayerWeight(System.Int32,System.Single)"
                                    ), pcVar2 == (code *)0x0)) {
    uVar4 = FUN_1802ced60("UnityEngine.Animator::SetLayerWeight(System.Int32,System.Single)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  pcRam0000000182ebf2d8 = pcVar2;
  param_1 = (float)(*pcRam0000000182ebf2d8)(lVar3,10);
  if (*(longlong *)(in_RCX + 0xa0) == 0) goto code_r0x00018062d638;
  ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
  param_1 = *(float *)(in_RCX + 0x28) - 0.1;
  if (param_1 < 0.0) {
    param_1 = 0.0;
  }
  else if (3.0 < param_1) {
    param_1 = 3.0;
  }
  *(float *)(in_RCX + 0x28) = param_1;
  if (param_1 <= 0.0) {
    lVar3 = *(longlong *)(in_RCX + 0x38);
    if ((lVar3 == 0) || (*(longlong *)(lVar3 + 0x48) == 0)) goto code_r0x00018062d638;
    if (*(int *)(*(longlong *)(lVar3 + 0x48) + 0x18) != -1) {
      if (((*(longlong *)(in_RCX + 0x40) == 0) ||
          (lVar3 = *(longlong *)(*(longlong *)(in_RCX + 0x40) + 0x60), lVar3 == 0)) ||
         (lVar3 = *(longlong *)(lVar3 + 0x48), lVar3 == 0)) goto code_r0x00018062d638;
      if ((*(char *)(lVar3 + 0x25) == '\0') &&
         (*(int *)(*(longlong *)(*(longlong *)(in_RCX + 0x38) + 0x48) + 0x18) != 0x2714))
      goto code_r0x00018062cdf0;
      lVar3 = *(longlong *)(in_RCX + 0x38);
    }
    if ((*(char *)(lVar3 + 0x1b) == '\0') &&
       (((*(longlong *)(in_RCX + 0x40) == 0 ||
         (lVar3 = *(longlong *)(*(longlong *)(in_RCX + 0x40) + 0x60), lVar3 == 0)) ||
        (*(longlong *)(lVar3 + 0x48) == 0)))) goto code_r0x00018062d638;
  }
code_r0x00018062cdf0:
  if (((*(longlong *)(in_RCX + 0x68) != 0) &&
      (param_1 = (float)ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c(),
      *(longlong *)(in_RCX + 0x68) != 0)) && (lVar3 = *(longlong *)(in_RCX + 0x30), lVar3 != 0)) {
    pcVar2 = pcRam0000000182ebf2d8;
    if ((pcRam0000000182ebf2d8 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Animator::SetLayerWeight(System.Int32,System.Single)"
                                      ), pcVar2 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Animator::SetLayerWeight(System.Int32,System.Single)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    pcRam0000000182ebf2d8 = pcVar2;
    param_1 = (float)(*pcRam0000000182ebf2d8)(lVar3,3);
    lVar3 = *(longlong *)(in_RCX + 0x48);
    if (**(longlong **)(DAT_182d57e50 + 0xb8) != 0) {
      pcVar2 = pcRam0000000182ec1508;
      if ((pcRam0000000182ec1508 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_timeScale()"), pcVar2 == (code *)0x0
         )) {
        uVar4 = FUN_1802ced60("UnityEngine.Time::get_timeScale()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      pcRam0000000182ec1508 = pcVar2;
      param_1 = (float)(*pcRam0000000182ec1508)();
      if ((lVar3 != 0) &&
         (param_1 = (float)ExposureUnnoticed2_Scripts_Base_SmoothFloat__SetSecond__0600175e(lVar3),
         *(longlong *)(in_RCX + 0x48) != 0)) {
        param_1 = (float)ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
        lVar3 = *(longlong *)(in_RCX + 0x50);
        if (**(longlong **)(DAT_182d57e50 + 0xb8) != 0) {
          pcVar2 = pcRam0000000182ec1508;
          if ((pcRam0000000182ec1508 == (code *)0x0) &&
             (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_timeScale()"),
             pcVar2 == (code *)0x0)) {
            uVar4 = FUN_1802ced60("UnityEngine.Time::get_timeScale()");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar4,0);
          }
          pcRam0000000182ec1508 = pcVar2;
          param_1 = (float)(*pcRam0000000182ec1508)();
          if ((lVar3 != 0) &&
             (param_1 = (float)ExposureUnnoticed2_Scripts_Base_SmoothFloat__SetSecond__0600175e
                                         (lVar3), *(longlong *)(in_RCX + 0x50) != 0)) {
            param_1 = (float)ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
            lVar3 = *(longlong *)(in_RCX + 0x30);
            if (*(int *)(lRam0000000182d6f340 + 0xe0) == 0) {
              param_1 = (float)FUN_18035c820(lRam0000000182d6f340);
            }
            if ((*(longlong *)(in_RCX + 0x48) != 0) && (lVar3 != 0)) {
              uVar1 = *(undefined4 *)(*(longlong *)(lRam0000000182d6f340 + 0xb8) + 4);
              pcVar2 = pcRam0000000182ebf338;
              if ((pcRam0000000182ebf338 == (code *)0x0) &&
                 (pcVar2 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                ), pcVar2 == (code *)0x0)) {
                uVar4 = FUN_1802ced60("UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                     );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar4,0);
              }
              pcRam0000000182ebf338 = pcVar2;
              param_1 = (float)(*pcRam0000000182ebf338)(lVar3,uVar1);
              if ((*(longlong *)(in_RCX + 0x50) != 0) &&
                 (lVar3 = *(longlong *)(in_RCX + 0x30), lVar3 != 0)) {
                uVar1 = *(undefined4 *)(*(longlong *)(lRam0000000182d6f340 + 0xb8) + 0x3c);
                pcVar2 = pcRam0000000182ebf338;
                if ((pcRam0000000182ebf338 == (code *)0x0) &&
                   (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  ), pcVar2 == (code *)0x0)) {
                  uVar4 = FUN_1802ced60(
                                       "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar4,0);
                }
                pcRam0000000182ebf338 = pcVar2;
                param_1 = (float)(*pcRam0000000182ebf338)(lVar3,uVar1);
                if ((*(longlong *)(in_RCX + 0xa0) != 0) &&
                   (lVar3 = *(longlong *)(in_RCX + 0x30), lVar3 != 0)) {
                  uVar1 = **(undefined4 **)(lRam0000000182d6f340 + 0xb8);
                  pcVar2 = pcRam0000000182ebf338;
                  if ((pcRam0000000182ebf338 == (code *)0x0) &&
                     (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  ), pcVar2 == (code *)0x0)) {
                    uVar4 = FUN_1802ced60(
                                         "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                         );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar4,0);
                  }
                  pcRam0000000182ebf338 = pcVar2;
                  param_1 = (float)(*pcRam0000000182ebf338)(lVar3,uVar1);
                  if (*(longlong *)(in_RCX + 0x40) != 0) {
                    lVar3 = *(longlong *)(in_RCX + 0x30);
                    uVar1 = *(undefined4 *)(*(longlong *)(lRam0000000182d6f340 + 0xb8) + 0x70);
                    if ((*(longlong *)(*(longlong *)(in_RCX + 0x40) + 0x170) != 0) && (lVar3 != 0))
                    {
                      pcVar2 = pcRam0000000182ebf338;
                      if ((pcRam0000000182ebf338 == (code *)0x0) &&
                         (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  ), pcVar2 == (code *)0x0)) {
                        uVar4 = FUN_1802ced60(
                                             "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                             );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar4,0);
                      }
                      pcRam0000000182ebf338 = pcVar2;
                      param_1 = (float)(*pcRam0000000182ebf338)(lVar3,uVar1);
                      if ((*(longlong *)(in_RCX + 0x88) != 0) &&
                         (param_1 = (float)ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c
                                                     (), *(longlong *)(in_RCX + 0x90) != 0)) {
                        param_1 = (float)ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c
                                                   ();
                        lVar3 = *(longlong *)(in_RCX + 0x30);
                        if (*(int *)(lRam0000000182d6f340 + 0xe0) == 0) {
                          param_1 = (float)FUN_18035c820(lRam0000000182d6f340);
                        }
                        if ((*(longlong *)(in_RCX + 0x88) != 0) && (lVar3 != 0)) {
                          uVar1 = *(undefined4 *)(*(longlong *)(lRam0000000182d6f340 + 0xb8) + 0x10)
                          ;
                          pcVar2 = pcRam0000000182ebf338;
                          if ((pcRam0000000182ebf338 == (code *)0x0) &&
                             (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  ), pcVar2 == (code *)0x0)) {
                            uVar4 = FUN_1802ced60(
                                                 "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                 );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar4,0);
                          }
                          pcRam0000000182ebf338 = pcVar2;
                          param_1 = (float)(*pcRam0000000182ebf338)(lVar3,uVar1);
                          if ((*(longlong *)(in_RCX + 0x90) != 0) &&
                             (lVar3 = *(longlong *)(in_RCX + 0x30), lVar3 != 0)) {
                            uVar1 = *(undefined4 *)
                                     (*(longlong *)(lRam0000000182d6f340 + 0xb8) + 0x14);
                            pcVar2 = pcRam0000000182ebf338;
                            if ((pcRam0000000182ebf338 == (code *)0x0) &&
                               (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  ), pcVar2 == (code *)0x0)) {
                              uVar4 = FUN_1802ced60(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  );
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar4,0);
                            }
                            pcRam0000000182ebf338 = pcVar2;
                            param_1 = (float)(*pcRam0000000182ebf338)(lVar3,uVar1);
                            if ((((*(longlong *)(in_RCX + 0x38) != 0) &&
                                 (*(longlong *)(in_RCX + 0x98) != 0)) &&
                                (param_1 = (float)ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c
                                                            (), *(longlong *)(in_RCX + 0x98) != 0))
                               && (lVar3 = *(longlong *)(in_RCX + 0x30), lVar3 != 0)) {
                              uVar1 = *(undefined4 *)
                                       (*(longlong *)(lRam0000000182d6f340 + 0xb8) + 0x2c);
                              pcVar2 = pcRam0000000182ebf338;
                              if ((pcRam0000000182ebf338 == (code *)0x0) &&
                                 (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  ), pcVar2 == (code *)0x0)) {
                                uVar4 = FUN_1802ced60(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                FUN_1802cca90(uVar4,0);
                              }
                              pcRam0000000182ebf338 = pcVar2;
                              param_1 = (float)(*pcRam0000000182ebf338)(lVar3,uVar1);
                              if ((*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48) != 0)
                                 && (lVar3 = *(longlong *)(in_RCX + 0x30), lVar3 != 0)) {
                                uVar1 = *(undefined4 *)
                                         (*(longlong *)(lRam0000000182d6f340 + 0xb8) + 100);
                                pcVar2 = pcRam0000000182ebf338;
                                if ((pcRam0000000182ebf338 == (code *)0x0) &&
                                   (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  ), pcVar2 == (code *)0x0)) {
                                  uVar4 = FUN_1802ced60(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                  FUN_1802cca90(uVar4,0);
                                }
                                pcRam0000000182ebf338 = pcVar2;
                                param_1 = (float)(*pcRam0000000182ebf338)(lVar3,uVar1);
                                lVar3 = *(longlong *)(in_RCX + 0x30);
                                uVar1 = *(undefined4 *)
                                         (*(longlong *)(lRam0000000182d6f340 + 0xb8) + 0x6c);
                                if (**(longlong **)(DAT_182d57e50 + 0xb8) != 0) {
                                  pcVar2 = pcRam0000000182ec1508;
                                  if ((pcRam0000000182ec1508 == (code *)0x0) &&
                                     (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Time::get_timeScale()"),
                                     pcVar2 == (code *)0x0)) {
                                    uVar4 = FUN_1802ced60("UnityEngine.Time::get_timeScale()");
                    /* WARNING: Subroutine does not return */
                                    FUN_1802cca90(uVar4,0);
                                  }
                                  pcRam0000000182ec1508 = pcVar2;
                                  param_1 = (float)(*pcRam0000000182ec1508)();
                                  if (lVar3 != 0) {
                                    pcVar2 = pcRam0000000182ebf338;
                                    if ((pcRam0000000182ebf338 == (code *)0x0) &&
                                       (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  ), pcVar2 == (code *)0x0)) {
                                      uVar4 = FUN_1802ced60(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                      FUN_1802cca90(uVar4,0);
                                    }
                                    pcRam0000000182ebf338 = pcVar2;
                                    param_1 = (float)(*pcRam0000000182ebf338)(lVar3,uVar1);
                                    if (((*(longlong *)(in_RCX + 0xb0) != 0) &&
                                        (param_1 = (float)
                                                  ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c
                                                            (), *(longlong *)(in_RCX + 0xb0) != 0))
                                       && (lVar3 = *(longlong *)(in_RCX + 0x30), lVar3 != 0)) {
                                      uVar1 = *(undefined4 *)
                                               (*(longlong *)(lRam0000000182d6f340 + 0xb8) + 0x74);
                                      pcVar2 = pcRam0000000182ebf338;
                                      if ((pcRam0000000182ebf338 == (code *)0x0) &&
                                         (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  ), pcVar2 == (code *)0x0)) {
                                        uVar4 = FUN_1802ced60(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                        FUN_1802cca90(uVar4,0);
                                      }
                                      pcRam0000000182ebf338 = pcVar2;
                                      param_1 = (float)(*pcRam0000000182ebf338)(lVar3,uVar1);
                                      if (param_2 != 0) {
                                        param_1 = *(float *)(param_2 + 0x14) *
                                                  *(float *)(param_2 + 0x14);
                                        if (0.0 < *(float *)(param_2 + 0x10) *
                                                  *(float *)(param_2 + 0x10) + param_1 +
                                                  *(float *)(param_2 + 0x18) *
                                                  *(float *)(param_2 + 0x18)) {
                                          if ((*(longlong *)(in_RCX + 0x40) == 0) ||
                                             (lVar3 = *(longlong *)
                                                       (*(longlong *)(in_RCX + 0x40) + 0x60),
                                             lVar3 == 0)) goto code_r0x00018062d638;
                                          if (*(char *)(lVar3 + 0x19) == '\0') {
                                            lVar3 = *(longlong *)
                                                     (*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                            if (lVar3 == 0) goto code_r0x00018062d638;
                                            param_1 = 1.0 - (float)*(int *)(lVar3 + 0x80) * 0.05;
                                          }
                                        }
                                        if (*(longlong *)(in_RCX + 0xb8) != 0) {
                                          param_1 = (float)
                                                  ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c
                                                            ();
                                          lVar3 = *(longlong *)(in_RCX + 0x30);
                                          if (*(int *)(lRam0000000182d6f340 + 0xe0) == 0) {
                                            param_1 = (float)FUN_18035c820(lRam0000000182d6f340);
                                          }
                                          if ((*(longlong *)(in_RCX + 0xb8) != 0) && (lVar3 != 0)) {
                                            uVar1 = *(undefined4 *)
                                                     (*(longlong *)(lRam0000000182d6f340 + 0xb8) +
                                                     0x60);
                                            pcVar2 = pcRam0000000182ebf338;
                                            if ((pcRam0000000182ebf338 == (code *)0x0) &&
                                               (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  ), pcVar2 == (code *)0x0)) {
                                              uVar4 = FUN_1802ced60(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                              FUN_1802cca90(uVar4,0);
                                            }
                                            pcRam0000000182ebf338 = pcVar2;
                                            param_1 = (float)(*pcRam0000000182ebf338)(lVar3,uVar1);
                                            if ((((*(longlong *)(in_RCX + 0x38) != 0) &&
                                                 (*(longlong *)(*(longlong *)(in_RCX + 0x38) + 0x48)
                                                  != 0)) && (*(longlong *)(in_RCX + 0x70) != 0)) &&
                                               ((param_1 = (float)
                                                  ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c
                                                            (), *(longlong *)(in_RCX + 0x70) != 0 &&
                                                (lVar3 = *(longlong *)(in_RCX + 0x30), lVar3 != 0)))
                                               ) {
                                              pcVar2 = pcRam0000000182ebf2d8;
                                              if ((pcRam0000000182ebf2d8 == (code *)0x0) &&
                                                 (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetLayerWeight(System.Int32,System.Single)"
                                                  ), pcVar2 == (code *)0x0)) {
                                                uVar4 = FUN_1802ced60(
                                                  "UnityEngine.Animator::SetLayerWeight(System.Int32,System.Single)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                FUN_1802cca90(uVar4,0);
                                              }
                                              pcRam0000000182ebf2d8 = pcVar2;
                                              (*pcRam0000000182ebf2d8)(lVar3,8);
                                              if (cRam0000000182eb8389 == '\0') {
                                                FUN_1802f2810(0x182d6f340,0);
                                                LOCK();
                                                UNLOCK();
                                                cRam0000000182eb8389 = '\x01';
                                              }
                                              if (((*(longlong *)(in_RCX + 0x40) != 0) &&
                                                  (lVar3 = *(longlong *)
                                                            (*(longlong *)(in_RCX + 0x40) + 0x60),
                                                  lVar3 != 0)) &&
                                                 ((*(longlong *)(lVar3 + 0x48) != 0 &&
                                                  (*(longlong *)(in_RCX + 0xa8) != 0)))) {
                                                ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c
                                                          ();
                                                lVar3 = *(longlong *)(in_RCX + 0x30);
                                                if (*(int *)(lRam0000000182d6f340 + 0xe0) == 0) {
                                                  FUN_18035c820(lRam0000000182d6f340);
                                                }
                                                if ((*(longlong *)(in_RCX + 0xa8) != 0) &&
                                                   (lVar3 != 0)) {
                                                  uVar1 = *(undefined4 *)
                                                           (*(longlong *)
                                                             (lRam0000000182d6f340 + 0xb8) + 0x50);
                                                  pcVar2 = pcRam0000000182ebf338;
                                                  if ((pcRam0000000182ebf338 == (code *)0x0) &&
                                                     (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  ), pcVar2 == (code *)0x0)) {
                                                    uVar4 = FUN_1802ced60(
                                                  "UnityEngine.Animator::SetFloatID(System.Int32,System.Single)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar4,0);
                                                  }
                                                  pcRam0000000182ebf338 = pcVar2;
                    /* WARNING: Could not recover jumptable at 0x00018062d93e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                                                  (*pcRam0000000182ebf338)(lVar3,uVar1);
                                                  return;
                                                }
                                              }
                    /* WARNING: Subroutine does not return */
                                              FUN_18031dad0();
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
code_r0x00018062d638:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0(param_1);
}

