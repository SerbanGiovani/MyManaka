// Ghidra pseudocode; not original source or compilable C.
// ev_5edf82774890b66bb60a7489cab6bfaa6e5cd6229befacb80ec05c0e6bf40af6

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__Push__06001064
               (longlong param_1,undefined8 *param_2,char param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  code *pcVar7;
  code *pcVar8;
  code *pcVar9;
  undefined8 uVar10;
  float fVar11;
  undefined8 uStack_58;
  float fStack_50;
  
  if ((*(longlong *)(param_1 + 0x30) != 0) &&
     (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40), lVar5 != 0)) {
    if ((*(int *)(lVar5 + 0x10) == 5) ||
       (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40) + 0x10) == 2)) {
      lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x10);
      if (lVar5 == 0) goto code_r0x00018042a4ea;
      uStack_58 = 0;
      fStack_50 = 0.0;
      pcVar8 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar8 == (code *)0x0)) {
        uVar10 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)")
        ;
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar10,0);
      }
      DAT_182ec1698 = pcVar8;
      (*DAT_182ec1698)(lVar5,&uStack_58);
      if (DAT_182eb548a == '\0') {
        FUN_1802f2810(&DAT_182d522a8);
        LOCK();
        UNLOCK();
        DAT_182eb548a = '\x01';
      }
      lVar6 = *(longlong *)(DAT_182d522a8 + 0xb8);
      uVar10 = *param_2;
      uVar4 = *(undefined8 *)(lVar6 + 0x24);
      fVar1 = *(float *)(lVar6 + 0x28);
      fVar2 = *(float *)(lVar6 + 0x2c);
      fVar3 = *(float *)(param_2 + 1);
      pcVar8 = DAT_182ec14d0;
      pcVar7 = pcRam0000000182ec14f8;
      if (param_3 == '\0') {
        pcVar9 = DAT_182ec14d0;
        if ((DAT_182ec14d0 == (code *)0x0) &&
           (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"), pcVar8 = pcVar9,
           pcVar7 = pcRam0000000182ec14f8, pcVar9 == (code *)0x0)) {
          uVar10 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar10,0);
        }
      }
      else {
        pcVar9 = pcRam0000000182ec14f8;
        if ((pcRam0000000182ec14f8 == (code *)0x0) &&
           (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_fixedDeltaTime()"),
           pcVar8 = DAT_182ec14d0, pcVar7 = pcVar9, pcVar9 == (code *)0x0)) {
          uVar10 = FUN_1802ced60("UnityEngine.Time::get_fixedDeltaTime()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar10,0);
        }
      }
      pcRam0000000182ec14f8 = pcVar7;
      DAT_182ec14d0 = pcVar8;
      fVar11 = (float)(*pcVar9)();
      fStack_50 = (fVar2 * 0.0 + fVar3) * fVar11 + fStack_50;
      uStack_58 = CONCAT44((fVar1 * 0.0 + (float)((ulonglong)uVar10 >> 0x20)) * fVar11 +
                           uStack_58._4_4_,
                           ((float)uVar4 * 0.0 + (float)uVar10) * fVar11 + (float)uStack_58);
      pcVar8 = DAT_182ec16a0;
      if ((DAT_182ec16a0 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar8 == (code *)0x0)) {
        uVar10 = FUN_1802ced60("UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)")
        ;
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar10,0);
      }
      DAT_182ec16a0 = pcVar8;
      (*DAT_182ec16a0)(lVar5,&uStack_58);
    }
    return;
  }
code_r0x00018042a4ea:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

