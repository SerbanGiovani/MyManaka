// Ghidra pseudocode; not original source or compilable C.
// ev_a3cbc9ab49728c8952bd077d4afd33442956e2a57b84f995f6013d6dc52c13c0

void ExposureUnnoticed2_ObjectUI_InGame_MissionPanel_MissionItemPanelView__LateUpdate__06001afb
               (longlong param_1)

{
  longlong *plVar1;
  char cVar2;
  code *pcVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  float fVar8;
  float fVar9;
  undefined4 auStackX_18 [4];
  undefined8 uStack_38;
  float fStack_30;
  undefined8 uStack_28;
  float fStack_20;
  
  if (cRam0000000182eb7cd8 == '\0') {
    FUN_1802f2810(0x182d648b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64888);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53cd0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64880);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64878);
    LOCK();
    UNLOCK();
    cRam0000000182eb7cd8 = '\x01';
  }
  pcVar3 = DAT_182ec1080;
  if ((DAT_182ec1080 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
     pcVar3 == (code *)0x0)) {
    uVar6 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar6,0);
  }
  DAT_182ec1080 = pcVar3;
  lVar4 = (*DAT_182ec1080)(param_1);
  pcVar3 = DAT_182ec1080;
  if ((DAT_182ec1080 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
     pcVar3 == (code *)0x0)) {
    uVar6 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar6,0);
  }
  DAT_182ec1080 = pcVar3;
  lVar5 = (*DAT_182ec1080)(param_1);
  if (lVar5 != 0) {
    uStack_28 = 0;
    fStack_20 = 0.0;
    pcVar3 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar3 == (code *)0x0)) {
      uVar6 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar6,0);
    }
    DAT_182ec1698 = pcVar3;
    (*DAT_182ec1698)(lVar5,&uStack_28);
    lVar5 = *(longlong *)(param_1 + 0x50);
    if (lVar5 != 0) {
      uStack_38 = 0;
      fStack_30 = 0.0;
      pcVar3 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar3 == (code *)0x0)) {
        uVar6 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
      DAT_182ec1698 = pcVar3;
      (*DAT_182ec1698)(lVar5,&uStack_38);
      fVar9 = (fStack_30 - fStack_20) * 0.1 + fStack_20;
      if (lVar4 != 0) {
        uStack_28 = CONCAT44((uStack_38._4_4_ - uStack_28._4_4_) * 0.1 + uStack_28._4_4_,
                             ((float)uStack_38 - (float)uStack_28) * 0.1 + (float)uStack_28);
        pcVar3 = DAT_182ec16a0;
        fStack_20 = fVar9;
        if ((DAT_182ec16a0 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                          ), pcVar3 == (code *)0x0)) {
          uVar6 = FUN_1802ced60("UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar6,0);
        }
        DAT_182ec16a0 = pcVar3;
        (*DAT_182ec16a0)(lVar4,&uStack_28);
        lVar4 = *(longlong *)(param_1 + 0x40);
        if (((*(longlong *)(param_1 + 0x58) != 0) &&
            (uVar7 = FUN_180005460(3,uRam0000000182d648b0), lVar4 != 0)) &&
           (Common_CommonUI_CommonGauge_GaugeFillView__Set__06001e47(lVar4,uVar7,0),
           *(longlong *)(param_1 + 0x58) != 0)) {
          fVar9 = (float)FUN_180005460(3,uRam0000000182d648b0);
          if ((1.0 <= fVar9) && (*(char *)(param_1 + 0x6c) == '\0')) {
            lVar4 = *(longlong *)(param_1 + 0x60);
            if (*(int *)(lRam0000000182d64888 + 0xe0) == 0) {
              FUN_18035c820(lRam0000000182d64888);
            }
            if (lVar4 == 0) goto DAT_180509855;
            FUN_181eea7c0(lVar4,*(undefined4 *)(*(longlong *)(lRam0000000182d64888 + 0xb8) + 4),0);
            fVar9 = *(float *)(param_1 + 0x68);
            pcVar3 = DAT_182ec14f0;
            if ((DAT_182ec14f0 == (code *)0x0) &&
               (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_unscaledDeltaTime()"),
               pcVar3 == (code *)0x0)) {
              uVar6 = FUN_1802ced60("UnityEngine.Time::get_unscaledDeltaTime()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar6,0);
            }
            DAT_182ec14f0 = pcVar3;
            fVar8 = (float)(*DAT_182ec14f0)();
            *(float *)(param_1 + 0x68) = fVar9 - fVar8;
            if (*(longlong *)(param_1 + 0x58) == 0) goto DAT_180509855;
            cVar2 = FUN_180002c20(4,uRam0000000182d648b0);
            if ((cVar2 != '\0') && (*(float *)(param_1 + 0x68) <= 0.0)) {
              ExposureUnnoticed2_ObjectUI_InGame_MissionPanel_MissionItemPanelView__TransformPerSec__06001afc
                        (param_1,0,0);
            }
          }
          if (*(longlong *)(param_1 + 0x58) != 0) {
            fVar9 = (float)FUN_180005460(3,uRam0000000182d648b0);
            if (fVar9 < 1.0) {
              return;
            }
            if (*(longlong *)(param_1 + 0x58) != 0) {
              cVar2 = FUN_180002c20(4,uRam0000000182d648b0);
              if (cVar2 == '\0') {
                return;
              }
              fVar9 = *(float *)(param_1 + 0x70);
              if (*(longlong *)(param_1 + 0x58) != 0) {
                fVar8 = (float)FUN_180005460(5,uRam0000000182d648b0);
                if (fVar9 == fVar8) {
                  return;
                }
                if (*(longlong *)(param_1 + 0x58) != 0) {
                  auStackX_18[0] = FUN_180005460(5,uRam0000000182d648b0);
                  *(undefined4 *)(param_1 + 0x70) = auStackX_18[0];
                  plVar1 = *(longlong **)(param_1 + 0x30);
                  uVar6 = FUN_1802c3ff0(DAT_182d53cd0,auStackX_18);
                  uVar6 = System_String__Format__0600021f(uRam0000000182d64878,uVar6,0);
                  uVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0
                                    (uRam0000000182d64880,uVar6,0);
                  if (plVar1 != (longlong *)0x0) {
                    (**(code **)(*plVar1 + 0x558))(plVar1,uVar6,*(undefined8 *)(*plVar1 + 0x560));
                    return;
                  }
                }
              }
            }
          }
          goto DAT_180509855;
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
DAT_180509855:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

