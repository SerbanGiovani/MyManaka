// Ghidra pseudocode; not original source or compilable C.
// ev_1d21f5f6e159d5ee1e846d291b0e34657baa31ae760e73d74b95c2d29aa28db9

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionEscalatorMove__GetAddSatisfy__06001440
                    (ulonglong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  longlong in_RCX;
  float fVar4;
  undefined8 uStack_28;
  float fStack_20;
  undefined8 uStack_18;
  float fStack_10;
  
  if (cRam0000000182eb790c == '\0') {
    param_1 = FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb790c = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 != 0)) {
    lVar1 = *(longlong *)(lVar1 + 0x30);
    param_1 = *(ulonglong *)(in_RCX + 0x48);
    fVar4 = *(float *)(in_RCX + 0x50);
    uStack_18 = param_1;
    if ((lVar1 != 0) &&
       ((lVar1 = *(longlong *)(lVar1 + 0x40), lVar1 != 0 &&
        (lVar1 = *(longlong *)(lVar1 + 0x18), lVar1 != 0)))) {
      uStack_28 = 0;
      fStack_20 = 0.0;
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
      fStack_10 = fVar4 - fStack_20;
      uStack_18 = CONCAT44(uStack_18._4_4_ - uStack_28._4_4_,(float)uStack_18 - (float)uStack_28);
      fVar4 = (float)FUN_1803d4630(&uStack_18);
      param_1 = 0;
      if (*(float *)(in_RCX + 0x58) <= fVar4 && fVar4 != *(float *)(in_RCX + 0x58)) {
        if (*(longlong *)(in_RCX + 0x28) == 0) goto code_r0x00018047b10f;
        param_1 = (ulonglong)
                  (uint)((fVar4 - *(float *)(in_RCX + 0x58)) /
                        *(float *)(*(longlong *)(in_RCX + 0x28) + 0x38));
        *(float *)(in_RCX + 0x58) = fVar4;
      }
      return param_1;
    }
  }
code_r0x00018047b10f:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0(param_1);
}

