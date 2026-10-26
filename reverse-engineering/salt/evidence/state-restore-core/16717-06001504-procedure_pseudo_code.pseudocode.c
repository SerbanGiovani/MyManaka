// Ghidra pseudocode; not original source or compilable C.
// ev_20e6c95b3c40e1a6bca87fecc502dbdbedb222eddebc8c024fd487d763c10cca

void ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__Hide__06001504
               (undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  lVar1 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetCache__060014fd
                    (param_1,param_2,0);
  if (lVar1 != 0) {
    pcVar2 = DAT_182ec1088;
    if ((DAT_182ec1088 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
       pcVar2 == (code *)0x0)) {
      uVar3 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar3,0);
    }
    DAT_182ec1088 = pcVar2;
    lVar1 = (*DAT_182ec1088)(lVar1);
    if (lVar1 != 0) {
      pcVar2 = DAT_182ec1138;
      if ((DAT_182ec1138 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
         pcVar2 == (code *)0x0)) {
        uVar3 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar3,0);
      }
      DAT_182ec1138 = pcVar2;
                    /* WARNING: Could not recover jumptable at 0x000180489815. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*DAT_182ec1138)(lVar1,0);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

