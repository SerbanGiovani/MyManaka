// Ghidra pseudocode; not original source or compilable C.
// ev_1432d36940b4dc6d7f38db99b8db943e877169e7eee66605d28c5cf942589b07

void ExposureUnnoticed2_Object3D_Player_Scripts_StaminaManager__ConsumePerSecond__06000e4f
               (longlong param_1,float param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  float fVar5;
  float fVar6;
  
  if (cRam0000000182eb7650 == '\0') {
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    cRam0000000182eb7650 = '\x01';
  }
  fVar6 = *(float *)(param_1 + 0x10);
  pcVar3 = DAT_182ec14d0;
  if ((DAT_182ec14d0 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"), pcVar3 == (code *)0x0)) {
    uVar4 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  DAT_182ec14d0 = pcVar3;
  fVar5 = (float)(*DAT_182ec14d0)();
  fVar6 = fVar6 - fVar5 * param_2;
  if (fVar6 < 0.0) {
    fVar6 = 0.0;
  }
  else if (*(float *)(param_1 + 0x14) < fVar6) {
    fVar6 = *(float *)(param_1 + 0x14);
  }
  *(float *)(param_1 + 0x10) = fVar6;
  if (*(longlong *)(param_1 + 0x20) == 0) goto code_r0x0001803fbeb4;
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0x24);
  if (fVar6 == 0.0) {
    if (*(char *)(param_1 + 0x2c) == '\0') {
      if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar2 = **(longlong **)(DAT_182d58380 + 0xb8);
      if (lVar2 == 0) {
code_r0x0001803fbeb4:
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      if (cRam0000000182eb77f1 == '\0') {
        FUN_1802f2810(&DAT_182d58380);
        LOCK();
        UNLOCK();
        cRam0000000182eb77f1 = '\x01';
      }
      lVar2 = *(longlong *)(lVar2 + 0x110);
      if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (lVar2 == 0) goto code_r0x0001803fbeb4;
      uVar1 = *(undefined4 *)(*(longlong *)(DAT_182d58380 + 0xb8) + 0xc);
      pcVar3 = DAT_182ebf368;
      if ((DAT_182ebf368 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Animator::SetTriggerID(System.Int32)"),
         pcVar3 == (code *)0x0)) {
        uVar4 = FUN_1802ced60("UnityEngine.Animator::SetTriggerID(System.Int32)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      DAT_182ebf368 = pcVar3;
      (*DAT_182ebf368)(lVar2,uVar1);
    }
    *(undefined1 *)(param_1 + 0x2c) = 1;
  }
  else {
    *(undefined1 *)(param_1 + 0x2c) = 0;
  }
  return;
}

