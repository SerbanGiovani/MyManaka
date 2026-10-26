// Ghidra pseudocode; not original source or compilable C.
// ev_d3845fba11b63dd2540dbec595fa65c6b308771c7cece007ace1dcca1a21fb0e

float ExposureUnnoticed2_Scripts_Mission_MissionElevatorMoveWithOutsideClothes__GetAddSatisfy__0600143b
                (float param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  longlong in_RCX;
  float fVar4;
  undefined8 uStack_28;
  undefined4 uStack_20;
  
  if (cRam0000000182eb7909 == '\0') {
    param_1 = (float)FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb7909 = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 != 0)) {
    lVar1 = *(longlong *)(lVar1 + 0x30);
    fVar4 = *(float *)(in_RCX + 0x4c);
    if ((lVar1 != 0) &&
       ((lVar1 = *(longlong *)(lVar1 + 0x40), lVar1 != 0 &&
        (lVar1 = *(longlong *)(lVar1 + 0x18), lVar1 != 0)))) {
      uStack_28 = 0;
      uStack_20 = 0;
      pcVar2 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar2 == (code *)0x0)) {
        uVar3 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar3,0);
      }
      DAT_182ec1698 = pcVar2;
      (*DAT_182ec1698)(lVar1,&uStack_28);
      param_1 = 0.0;
      fVar4 = ABS(fVar4 - uStack_28._4_4_);
      if (*(float *)(in_RCX + 0x58) <= fVar4 && fVar4 != *(float *)(in_RCX + 0x58)) {
        if (*(longlong *)(in_RCX + 0x28) == 0) goto code_r0x00018047ab4d;
        param_1 = (fVar4 - *(float *)(in_RCX + 0x58)) /
                  *(float *)(*(longlong *)(in_RCX + 0x28) + 0x38);
        *(float *)(in_RCX + 0x58) = fVar4;
      }
      return param_1;
    }
  }
code_r0x00018047ab4d:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0(param_1);
}

