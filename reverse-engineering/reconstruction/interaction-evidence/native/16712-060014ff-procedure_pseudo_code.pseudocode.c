// Ghidra pseudocode; not original source or compilable C.
// ev_b7a0254206286b5b62f0877aa532499f24059d6fd204c6e9f3ac17c187d2088a

undefined8
ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__Drop__060014ff
          (undefined8 param_1,undefined8 *param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  longlong lVar5;
  code *pcVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined8 uStack_28;
  undefined4 uStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (cRam0000000182eb796f == '\0') {
    FUN_1802f2810(0x182d5df88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5df80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb796f = '\x01';
  }
  lVar5 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetCache__060014fd
                    (param_1,param_4,0);
  if (lVar5 == 0) {
code_r0x00018048930e:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  pcVar6 = DAT_182ec1088;
  if ((DAT_182ec1088 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
     pcVar6 == (code *)0x0)) {
    uVar9 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar9,0);
  }
  DAT_182ec1088 = pcVar6;
  lVar7 = (*DAT_182ec1088)(lVar5);
  if (lVar7 == 0) goto code_r0x00018048930e;
  pcVar6 = DAT_182ec1138;
  if ((DAT_182ec1138 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
     pcVar6 == (code *)0x0)) {
    uVar9 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar9,0);
  }
  DAT_182ec1138 = pcVar6;
  (*DAT_182ec1138)(lVar7,1);
  pcVar6 = DAT_182ec1080;
  if ((DAT_182ec1080 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
     pcVar6 == (code *)0x0)) {
    uVar9 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar9,0);
  }
  DAT_182ec1080 = pcVar6;
  lVar7 = (*DAT_182ec1080)(lVar5);
  if (lVar7 == 0) goto code_r0x00018048930e;
  uStack_18 = *param_3;
  uStack_14 = param_3[1];
  uStack_10 = param_3[2];
  uStack_c = param_3[3];
  uStack_28 = *param_2;
  uStack_20 = *(undefined4 *)(param_2 + 1);
  pcVar6 = DAT_182ec16f8;
  if ((DAT_182ec16f8 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Transform::SetPositionAndRotation_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                    ), pcVar6 == (code *)0x0)) {
    uVar9 = FUN_1802ced60(
                         "UnityEngine.Transform::SetPositionAndRotation_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                         );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar9,0);
  }
  DAT_182ec16f8 = pcVar6;
  (*DAT_182ec16f8)(lVar7,&uStack_28,&uStack_18);
  lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (((lVar7 == 0) || (lVar7 = *(longlong *)(lVar7 + 0x18), lVar7 == 0)) ||
     (lVar7 = FUN_180e75f20(lVar7,param_4,lRam0000000182d5df80), lVar7 == 0))
  goto code_r0x00018048930e;
  *(undefined1 *)(lVar7 + 0x10) = 1;
  lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (((lVar7 == 0) || (lVar7 = *(longlong *)(lVar7 + 0x18), lVar7 == 0)) ||
     (lVar7 = FUN_180e75f20(lVar7,param_4,lRam0000000182d5df80), lVar7 == 0))
  goto code_r0x00018048930e;
  uVar1 = *(undefined4 *)(param_2 + 1);
  *(undefined8 *)(lVar7 + 0x14) = *param_2;
  *(undefined4 *)(lVar7 + 0x1c) = uVar1;
  lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (((lVar7 == 0) || (lVar7 = *(longlong *)(lVar7 + 0x18), lVar7 == 0)) ||
     (lVar7 = FUN_180e75f20(lVar7,param_4,lRam0000000182d5df80), lVar7 == 0))
  goto code_r0x00018048930e;
  uVar1 = param_3[1];
  uVar2 = param_3[2];
  uVar3 = param_3[3];
  *(undefined4 *)(lVar7 + 0x20) = *param_3;
  *(undefined4 *)(lVar7 + 0x24) = uVar1;
  *(undefined4 *)(lVar7 + 0x28) = uVar2;
  *(undefined4 *)(lVar7 + 0x2c) = uVar3;
  lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar7 == 0) || (lVar7 = *(longlong *)(lVar7 + 0x18), lVar7 == 0)) goto code_r0x00018048930e;
  lVar8 = FUN_180e75f20(lVar7,param_4,lRam0000000182d5df80);
  lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar7 == 0) || (lVar8 == 0)) goto code_r0x00018048930e;
  *(undefined4 *)(lVar8 + 0x30) = *(undefined4 *)(lVar7 + 0x10);
  if (9999 < param_4) {
    lVar7 = *(longlong *)(lVar5 + 0x20);
    if (lVar7 == 0) goto code_r0x00018048939e;
    pcVar6 = DAT_182ec1088;
    if ((DAT_182ec1088 == (code *)0x0) &&
       (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
       pcVar6 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec1088 = pcVar6;
    lVar7 = (*DAT_182ec1088)(lVar7);
    if (lVar7 == 0) goto code_r0x00018048939e;
    pcVar6 = DAT_182ec1138;
    if ((DAT_182ec1138 == (code *)0x0) &&
       (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
       pcVar6 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec1138 = pcVar6;
    (*DAT_182ec1138)(lVar7,1);
    lVar5 = FUN_180735660(lVar5,uRam0000000182d5df88);
    if (lVar5 == 0) goto code_r0x00018048939e;
    *(int *)(lVar5 + 0x68) = param_4;
    *(undefined1 *)(lVar5 + 0x6c) = 0;
  }
  lVar7 = lRam0000000182d5df80;
  lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar5 != 0) && (lVar5 = *(longlong *)(lVar5 + 0x18), lVar5 != 0)) {
    uVar4 = FUN_180e76580(lVar5,param_4,
                          *(undefined8 *)
                           (*(longlong *)(*(longlong *)(lRam0000000182d5df80 + 0x20) + 0xc0) + 0xf8)
                         );
    if ((int)uVar4 < 0) {
      uVar9 = FUN_180003850(*(undefined8 *)(*(longlong *)(lVar7 + 0x20) + 0xc0),0xe);
      uVar9 = il2cpp_value_box(uVar9,&stack0x00000010);
                    /* WARNING: Subroutine does not return */
      FUN_181640310(uVar9,0);
    }
    lVar5 = *(longlong *)(lVar5 + 0x18);
    if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(uint *)(lVar5 + 0x18) <= uVar4) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    return *(undefined8 *)(lVar5 + ((longlong)(int)uVar4 + 2) * 0x18);
  }
code_r0x00018048939e:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

