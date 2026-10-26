// Ghidra pseudocode; not original source or compilable C.
// ev_927aa13334b0c68a497be1adc3aab3bf048ccc3e16ccb8daef9b827118861730

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBoneScaleAdjuster___OnChangeBody_b__4_0__06000ce3
               (longlong param_1)

{
  float fVar1;
  longlong lVar2;
  code *pcVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uStack_28;
  float fStack_20;
  undefined8 uStack_18;
  float fStack_10;
  
  if (cRam0000000182eb83be == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    cRam0000000182eb83be = '\x01';
  }
  pcVar3 = DAT_182ec1080;
  if ((DAT_182ec1080 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
     pcVar3 == (code *)0x0)) {
    uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar5,0);
  }
  DAT_182ec1080 = pcVar3;
  lVar4 = (*DAT_182ec1080)(param_1);
  if (DAT_182eb548b == '\0') {
    FUN_1802f2810(&DAT_182d522a8);
    LOCK();
    UNLOCK();
    DAT_182eb548b = '\x01';
  }
  lVar2 = *(longlong *)(param_1 + 0x20);
  uStack_18 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0xc);
  fVar1 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x14);
  if (lVar2 != 0) {
    uStack_28 = 0;
    fStack_20 = 0.0;
    pcVar3 = DAT_182ec16d8;
    if ((DAT_182ec16d8 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_localScale_Injected(UnityEngine.Vector3&)"
                                      ), pcVar3 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Transform::get_localScale_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ec16d8 = pcVar3;
    (*DAT_182ec16d8)(lVar2,&uStack_28);
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    fStack_10 = fVar1 / fStack_20;
    if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uStack_18 = CONCAT44(uStack_18._4_4_ / uStack_28._4_4_,(float)uStack_18 / (float)uStack_28);
    pcVar3 = DAT_182ec16e0;
    if ((DAT_182ec16e0 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                      ), pcVar3 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ec16e0 = pcVar3;
    (*DAT_182ec16e0)(lVar4,&uStack_18);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

