// Ghidra pseudocode; not original source or compilable C.
// ev_378e6f9ba061be0d731d83dae72a4977a25b14fb8cf483eaaf5fe982f4685c0b

float ExposureUnnoticed2_Scripts_Mission_MissionMoveVerticalFromClothes__GetAddSatisfy__06001477
                (float param_1)

{
  float fVar1;
  float fVar2;
  longlong lVar3;
  longlong lVar4;
  code *pcVar5;
  undefined8 uVar6;
  longlong in_RCX;
  float extraout_XMM0_Da;
  float extraout_XMM0_Da_00;
  float extraout_XMM0_Da_01;
  float fVar7;
  undefined8 uStack_28;
  undefined4 uStack_20;
  undefined8 uStack_18;
  undefined4 uStack_10;
  
  if (cRam0000000182eb792f == '\0') {
    param_1 = (float)FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb792f = '\x01';
  }
  if (DAT_182eb54a2 == '\0') {
    param_1 = (float)FUN_1802f2810(&DAT_182d5bcb8);
    LOCK();
    UNLOCK();
    DAT_182eb54a2 = '\x01';
  }
  if (**(longlong **)(DAT_182d5bcb8 + 0xb8) != 0) {
    lVar4 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetDropClothesInSameArea__0600150d
                      (**(longlong **)(DAT_182d5bcb8 + 0xb8),0);
    if (lVar4 == 0) {
      return 0.0;
    }
    param_1 = extraout_XMM0_Da;
    if (DAT_182eb54a2 == '\0') {
      param_1 = (float)FUN_1802f2810(&DAT_182d5bcb8);
      LOCK();
      UNLOCK();
      DAT_182eb54a2 = '\x01';
    }
    if (**(longlong **)(DAT_182d5bcb8 + 0xb8) != 0) {
      lVar4 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetCache__060014fd
                        (**(longlong **)(DAT_182d5bcb8 + 0xb8),*(undefined4 *)(lVar4 + 0x34),0);
      param_1 = extraout_XMM0_Da_00;
      if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
          (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar3 != 0)) &&
         (lVar3 = *(longlong *)(lVar3 + 0x30), lVar4 != 0)) {
        pcVar5 = DAT_182ec1080;
        if ((DAT_182ec1080 == (code *)0x0) &&
           (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
           pcVar5 == (code *)0x0)) {
          uVar6 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar6,0);
        }
        DAT_182ec1080 = pcVar5;
        lVar4 = (*DAT_182ec1080)(lVar4);
        param_1 = extraout_XMM0_Da_01;
        if (lVar4 != 0) {
          uStack_28 = 0;
          uStack_20 = 0;
          pcVar5 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar6 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar6,0);
          }
          DAT_182ec1698 = pcVar5;
          param_1 = (float)(*DAT_182ec1698)(lVar4,&uStack_28);
          if (((lVar3 != 0) && (lVar4 = *(longlong *)(lVar3 + 0x40), lVar4 != 0)) &&
             (lVar4 = *(longlong *)(lVar4 + 0x18), lVar4 != 0)) {
            uStack_18 = 0;
            uStack_10 = 0;
            pcVar5 = DAT_182ec1698;
            if ((DAT_182ec1698 == (code *)0x0) &&
               (pcVar5 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                              ), pcVar5 == (code *)0x0)) {
              uVar6 = FUN_1802ced60(
                                   "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar6,0);
            }
            DAT_182ec1698 = pcVar5;
            (*DAT_182ec1698)(lVar4,&uStack_18);
            param_1 = 0.0;
            fVar7 = ABS(uStack_28._4_4_ - uStack_18._4_4_);
            if (*(float *)(in_RCX + 0x54) <= fVar7 && fVar7 != *(float *)(in_RCX + 0x54)) {
              if (*(longlong *)(in_RCX + 0x28) == 0) goto code_r0x00018047f5cb;
              fVar1 = *(float *)(*(longlong *)(in_RCX + 0x28) + 0x38);
              fVar2 = *(float *)(in_RCX + 0x54);
              *(float *)(in_RCX + 0x54) = fVar7;
              param_1 = (fVar7 - fVar2) / (fVar1 * 2.5);
            }
            return param_1;
          }
        }
      }
    }
  }
code_r0x00018047f5cb:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0(param_1);
}

