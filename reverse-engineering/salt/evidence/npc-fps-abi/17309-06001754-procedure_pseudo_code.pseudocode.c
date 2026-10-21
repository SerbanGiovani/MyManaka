// Ghidra pseudocode; not original source or compilable C.
// ev_7ac6fa41def4be12fadc4d2cdfb8358e706c08dc1dedb868e13c4a37fb645000

undefined8 DelayTimeModel__InvokeIfNeed__06001754(longlong param_1)

{
  float fVar1;
  longlong lVar2;
  code *pcVar3;
  code *pcVar4;
  code *pcVar5;
  undefined8 uVar6;
  float extraout_XMM0_Da;
  
  if (cRam0000000182eb7aa7 == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb7aa7 = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
     (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar2 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if ((*(char *)(lVar2 + 0x14) == '\0') || (*(char *)(param_1 + 0x24) != '\0')) {
    fVar1 = *(float *)(param_1 + 0x20);
    pcVar3 = DAT_182ec14d0;
    pcVar4 = DAT_182ec14f0;
    if (*(char *)(param_1 + 0x24) == '\0') {
      pcVar5 = DAT_182ec14d0;
      if ((DAT_182ec14d0 == (code *)0x0) &&
         (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"), pcVar3 = pcVar5,
         pcVar4 = DAT_182ec14f0, pcVar5 == (code *)0x0)) {
        uVar6 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
    }
    else {
      pcVar5 = DAT_182ec14f0;
      if ((DAT_182ec14f0 == (code *)0x0) &&
         (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_unscaledDeltaTime()"),
         pcVar3 = DAT_182ec14d0, pcVar4 = pcVar5, pcVar5 == (code *)0x0)) {
        uVar6 = FUN_1802ced60("UnityEngine.Time::get_unscaledDeltaTime()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
    }
    DAT_182ec14f0 = pcVar4;
    DAT_182ec14d0 = pcVar3;
    (*pcVar5)();
    *(float *)(param_1 + 0x20) = fVar1 - extraout_XMM0_Da;
  }
  if (0.0 < *(float *)(param_1 + 0x20)) {
    return 0;
  }
  lVar2 = *(longlong *)(param_1 + 0x10);
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  (**(code **)(lVar2 + 0x18))(*(undefined8 *)(lVar2 + 0x40),*(undefined8 *)(lVar2 + 0x28));
  return 1;
}

