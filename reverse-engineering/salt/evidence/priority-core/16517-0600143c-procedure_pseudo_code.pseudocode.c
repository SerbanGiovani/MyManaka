// Ghidra pseudocode; not original source or compilable C.
// ev_8865b2f4d1f7fbd5824a7dd601dcf233adc94825ec24821b245b9a4585962af7

bool ExposureUnnoticed2_Scripts_Mission_MissionElevatorMoveWithOutsideClothes__IsRpPerSecCondition__0600143c
               (longlong param_1)

{
  float fVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 uStack_28;
  undefined4 uStack_20;
  
  if (cRam0000000182eb790a == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52288);
    LOCK();
    UNLOCK();
    cRam0000000182eb790a = '\x01';
  }
  if ((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
       (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 != 0)) &&
      (lVar2 = *(longlong *)(lVar2 + 0x30), lVar2 != 0)) &&
     ((lVar2 = *(longlong *)(lVar2 + 0x40), lVar2 != 0 &&
      (lVar2 = *(longlong *)(lVar2 + 0x18), lVar2 != 0)))) {
    uStack_28 = 0;
    uStack_20 = 0;
    pcVar3 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar3 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec1698 = pcVar3;
    (*DAT_182ec1698)(lVar2,&uStack_28);
    fVar1 = *(float *)(param_1 + 0x5c);
    if (*(int *)(DAT_182d52288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    *(float *)(param_1 + 0x5c) = uStack_28._4_4_;
    return 0.001 < ABS(uStack_28._4_4_ - fVar1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

