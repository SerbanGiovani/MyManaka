// Ghidra pseudocode; not original source or compilable C.
// ev_c86f6bfe7215741fe5c394dc7b7d7d3f5b016adc622c7e516eb7c35a294bea42

void __c__DisplayClass51_0___AdditionalInitializeForFixAction_b__0__0600106a(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uStack_18;
  undefined8 uStack_10;
  
  if ((((*(longlong *)(param_1 + 0x10) == 0) ||
       (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x30), lVar3 == 0)) ||
      (lVar3 = *(longlong *)(lVar3 + 0xa0), lVar3 == 0)) ||
     (lVar3 = *(longlong *)(lVar3 + 0x20), lVar3 == 0)) goto code_r0x00018042b095;
  *(undefined4 *)(lVar3 + 0x1c) = 0;
  if (*(int *)(param_1 + 0x18) == 6) {
    if (((*(longlong *)(param_1 + 0x20) == 0) ||
        (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x30), lVar3 == 0)) ||
       ((lVar3 = *(longlong *)(lVar3 + 0x50), lVar3 == 0 ||
        (lVar3 = *(longlong *)(lVar3 + 0x70), lVar3 == 0)))) goto code_r0x00018042b095;
    pcVar2 = DAT_182ec1088;
    if ((DAT_182ec1088 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
       pcVar2 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec1088 = pcVar2;
    lVar3 = (*DAT_182ec1088)(lVar3);
    if (lVar3 == 0) goto code_r0x00018042b095;
    pcVar2 = DAT_182ec1138;
    if ((DAT_182ec1138 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
       pcVar2 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec1138 = pcVar2;
    (*DAT_182ec1138)(lVar3,1);
    if (((*(longlong *)(param_1 + 0x20) == 0) ||
        (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x30), lVar3 == 0)) ||
       (lVar3 = *(longlong *)(lVar3 + 0xa0), lVar3 == 0)) goto code_r0x00018042b095;
    ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__SetSitBook__06000fd0(lVar3,0);
    if (((*(longlong *)(param_1 + 0x20) == 0) ||
        (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x30), lVar3 == 0)) ||
       (lVar3 = *(longlong *)(lVar3 + 0xa0), lVar3 == 0)) goto code_r0x00018042b095;
    ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__SetIsSit__06000fd2(lVar3,1,0);
  }
  if (*(int *)(param_1 + 0x18) == 7) {
    if (((*(longlong *)(param_1 + 0x20) == 0) ||
        (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x30), lVar3 == 0)) ||
       ((lVar3 = *(longlong *)(lVar3 + 0x50), lVar3 == 0 ||
        (lVar3 = *(longlong *)(lVar3 + 0x60), lVar3 == 0)))) goto code_r0x00018042b095;
    pcVar2 = DAT_182ec1088;
    if ((DAT_182ec1088 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
       pcVar2 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec1088 = pcVar2;
    lVar3 = (*DAT_182ec1088)(lVar3);
    if (lVar3 == 0) goto code_r0x00018042b095;
    pcVar2 = DAT_182ec1138;
    if ((DAT_182ec1138 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
       pcVar2 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec1138 = pcVar2;
    (*DAT_182ec1138)(lVar3,1);
    if (((*(longlong *)(param_1 + 0x20) == 0) ||
        (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x30), lVar3 == 0)) ||
       (lVar3 = *(longlong *)(lVar3 + 0xa0), lVar3 == 0)) goto code_r0x00018042b095;
    ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__SetSitSumaho__06000fd1(lVar3,0);
    if (((*(longlong *)(param_1 + 0x20) == 0) ||
        (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x30), lVar3 == 0)) ||
       (lVar3 = *(longlong *)(lVar3 + 0xa0), lVar3 == 0)) goto code_r0x00018042b095;
    ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__SetIsSit__06000fd2(lVar3,1,0);
  }
  if (*(int *)(param_1 + 0x18) == 5) {
    if (((*(longlong *)(param_1 + 0x20) == 0) ||
        (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x30), lVar3 == 0)) ||
       (lVar3 = *(longlong *)(lVar3 + 0xa0), lVar3 == 0)) goto code_r0x00018042b095;
    ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__SetSitSleep__06000fce(lVar3,0);
    if (((*(longlong *)(param_1 + 0x20) == 0) ||
        (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x30), lVar3 == 0)) ||
       (lVar3 = *(longlong *)(lVar3 + 0xa0), lVar3 == 0)) goto code_r0x00018042b095;
    ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__SetIsSit__06000fd2(lVar3,1,0);
  }
  if (*(int *)(param_1 + 0x18) == 10) {
    if (((*(longlong *)(param_1 + 0x10) == 0) ||
        (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x30), lVar3 == 0)) ||
       ((lVar3 = *(longlong *)(lVar3 + 0xa0), lVar3 == 0 ||
        (lVar3 = *(longlong *)(lVar3 + 0x20), lVar3 == 0)))) goto code_r0x00018042b095;
    *(undefined4 *)(lVar3 + 0x1c) = 0x3f800000;
    if (((*(longlong *)(param_1 + 0x10) == 0) ||
        (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x30), lVar3 == 0)) ||
       (lVar3 = *(longlong *)(lVar3 + 0x28), lVar3 == 0)) goto code_r0x00018042b095;
    pcVar2 = DAT_182ec1060;
    if ((DAT_182ec1060 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Behaviour::set_enabled(System.Boolean)"),
       pcVar2 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Behaviour::set_enabled(System.Boolean)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec1060 = pcVar2;
    (*DAT_182ec1060)(lVar3,1);
  }
  if (*(int *)(param_1 + 0x18) != 2) {
    return;
  }
  lVar3 = *(longlong *)(param_1 + 0x20);
  if ((lVar3 != 0) && (*(longlong *)(lVar3 + 0x30) != 0)) {
    lVar1 = *(longlong *)(lVar3 + 0x10);
    lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x40);
    if (lVar1 != 0) {
      uStack_18 = 0;
      uStack_10 = 0;
      pcVar2 = DAT_182ec16b8;
      if ((DAT_182ec16b8 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                        ), pcVar2 == (code *)0x0)) {
        uVar4 = FUN_1802ced60(
                             "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      DAT_182ec16b8 = pcVar2;
      (*DAT_182ec16b8)(lVar1,&uStack_18);
      if (lVar3 != 0) {
        *(undefined8 *)(lVar3 + 0xa4) = uStack_18;
        *(undefined8 *)(lVar3 + 0xac) = uStack_10;
        return;
      }
    }
  }
code_r0x00018042b095:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

