// Ghidra pseudocode; not original source or compilable C.
// ev_825638e84b03b03dfa2d3e799d5042b0194619db7634593ebe8fd15827ff94c9

void ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c(longlong param_1,float param_2)

{
  float fVar1;
  code *pcVar2;
  code *pcVar3;
  code *pcVar4;
  undefined8 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar1 = *(float *)(param_1 + 0x10);
  fVar8 = *(float *)(param_1 + 0x14);
  if (*(char *)(param_1 + 0x20) != '\0') {
    if (fVar8 < 0.0) {
      fVar8 = 0.0;
    }
    else if (1.0 < fVar8) {
      fVar8 = 1.0;
    }
    *(float *)(param_1 + 0x10) = (param_2 - fVar1) * fVar8 + fVar1;
    return;
  }
  if (param_2 < fVar1) {
    fVar8 = *(float *)(param_1 + 0x18);
  }
  pcVar2 = DAT_182ec14d0;
  pcVar3 = DAT_182ec14f0;
  if (*(char *)(param_1 + 0x30) == '\0') {
    pcVar4 = DAT_182ec14d0;
    if ((DAT_182ec14d0 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"), pcVar2 = pcVar4,
       pcVar3 = DAT_182ec14f0, pcVar4 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
  }
  else {
    pcVar4 = DAT_182ec14f0;
    if ((DAT_182ec14f0 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_unscaledDeltaTime()"),
       pcVar2 = DAT_182ec14d0, pcVar3 = pcVar4, pcVar4 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Time::get_unscaledDeltaTime()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
  }
  DAT_182ec14f0 = pcVar3;
  DAT_182ec14d0 = pcVar2;
  fVar6 = (float)(*pcVar4)();
  if (fVar6 * fVar8 < ABS(param_2 - fVar1)) {
    if (param_2 - fVar1 < 0.0) {
      fVar7 = -1.0;
    }
    else {
      fVar7 = 1.0;
    }
    param_2 = fVar7 * fVar6 * fVar8 + fVar1;
  }
  *(float *)(param_1 + 0x10) = param_2;
  return;
}

