// Ghidra pseudocode; not original source or compilable C.
// ev_110cad2604b1d32c5fb9065f45ca96db56dea02bcec1bc14cef6de92c8d53210

void Common_Scripts_Util_AnimatorFPSController__OnUpdate__06001e0b(longlong param_1)

{
  float fVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  float fVar5;
  
  if (*(char *)(param_1 + 0x10) != '\0') {
    fVar1 = *(float *)(param_1 + 0x24);
    pcVar3 = DAT_182ec14d0;
    if ((DAT_182ec14d0 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"), pcVar3 == (code *)0x0))
    {
      uVar4 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec14d0 = pcVar3;
    fVar5 = (float)(*DAT_182ec14d0)();
    fVar5 = fVar5 + fVar1;
    *(float *)(param_1 + 0x24) = fVar5;
    if (*(float *)(param_1 + 0x20) <= fVar5) {
      lVar2 = *(longlong *)(param_1 + 0x18);
      if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      pcVar3 = pcRam0000000182ebf378;
      if ((pcRam0000000182ebf378 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Animator::Update(System.Single)"),
         pcVar3 == (code *)0x0)) {
        uVar4 = FUN_1802ced60("UnityEngine.Animator::Update(System.Single)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      pcRam0000000182ebf378 = pcVar3;
      (*pcRam0000000182ebf378)(lVar2,fVar5);
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}

