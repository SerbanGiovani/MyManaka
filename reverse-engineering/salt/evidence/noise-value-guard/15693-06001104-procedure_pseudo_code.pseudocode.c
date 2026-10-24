// Ghidra pseudocode; not original source or compilable C.
// ev_77938d0656b41c3d97177697951f04bdc9eb123077e3a95eb075ab977f258b17

void ExposureUnnoticed2_Object3D_NPC_Script_StrangenessValueManager__OnUpdate__06001104
               (longlong param_1,char param_2)

{
  float fVar1;
  code *pcVar2;
  undefined8 uVar3;
  float fVar4;
  float fVar5;
  
  if (*(int *)(param_1 + 0x18) < 0) {
    fVar5 = *(float *)(param_1 + 0x14);
    fVar1 = *(float *)(param_1 + 0x10);
    pcVar2 = DAT_182ec14d0;
    if ((DAT_182ec14d0 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"), pcVar2 == (code *)0x0))
    {
      uVar3 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar3,0);
    }
    DAT_182ec14d0 = pcVar2;
    fVar4 = (float)(*DAT_182ec14d0)();
    fVar5 = fVar5 - fVar4 * fVar1;
    if (fVar5 < 0.0) {
      fVar5 = 0.0;
    }
    else if (1.0 < fVar5) {
      fVar5 = 1.0;
    }
    *(float *)(param_1 + 0x14) = fVar5;
  }
  if (param_2 == '\0') {
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
  }
  return;
}

