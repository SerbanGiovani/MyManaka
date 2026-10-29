// Ghidra pseudocode; not original source or compilable C.
// ev_96dfba8083e4cfafc521ea02728f6c4ff186682dd8aa020aaee538690a064dbf

void ExposureUnnoticed2_ObjectUI_InGame_MissionPanel_MissionItemPanelView__OnTransOutAnimEnd__06001afe
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 unaff_RBX;
  
  if (cRam0000000182eb7cdb == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7cdb = '\x01';
  }
  lVar1 = *(longlong *)(param_1 + 0x50);
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  pcVar2 = DAT_182ec1088;
  if ((DAT_182ec1088 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
     pcVar2 == (code *)0x0)) {
    uVar3 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  DAT_182ec1088 = pcVar2;
  uVar3 = (*DAT_182ec1088)(lVar1);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_181f43e80(uVar3,0);
  pcVar2 = DAT_182ec1088;
  if ((DAT_182ec1088 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
     pcVar2 == (code *)0x0)) {
    uVar3 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  DAT_182ec1088 = pcVar2;
  uVar3 = (*DAT_182ec1088)(param_1);
  if (DAT_182ec12b0 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8,0,param_3,param_4,unaff_RBX);
    LOCK();
    UNLOCK();
    DAT_182ec12b0 = '\x01';
  }
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar2 = DAT_182ec12a8;
  if ((DAT_182ec12a8 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)"
                                    ), pcVar2 == (code *)0x0)) {
    uVar3 = FUN_1802ced60("UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  DAT_182ec12a8 = pcVar2;
                    /* WARNING: Could not recover jumptable at 0x000181f43eee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_182ec12a8)(uVar3,0);
  return;
}

