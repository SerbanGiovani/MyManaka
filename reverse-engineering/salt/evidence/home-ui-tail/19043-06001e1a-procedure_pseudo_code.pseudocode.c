// Ghidra pseudocode; not original source or compilable C.
// ev_bb6214672b1e8a923a8d529f3e4b445e170eed15cc7a4ce1df565c33f7bd99b8

void Common_Scripts_UI_BasePanelView__OnAnimCloseEnd__06001e1a
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 unaff_RBX;
  
  if (cRam0000000182eb7fdb == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7fdb = '\x01';
  }
  pcVar1 = DAT_182ec1088;
  if ((DAT_182ec1088 == (code *)0x0) &&
     (pcVar1 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
     pcVar1 == (code *)0x0)) {
    uVar2 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  DAT_182ec1088 = pcVar1;
  uVar2 = (*DAT_182ec1088)(param_1);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12b0 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8,0,param_3,param_4,unaff_RBX);
    LOCK();
    UNLOCK();
    DAT_182ec12b0 = '\x01';
  }
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar1 = DAT_182ec12a8;
  if ((DAT_182ec12a8 == (code *)0x0) &&
     (pcVar1 = (code *)FUN_1802cf0c0("UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)"
                                    ), pcVar1 == (code *)0x0)) {
    uVar2 = FUN_1802ced60("UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  DAT_182ec12a8 = pcVar1;
                    /* WARNING: Could not recover jumptable at 0x000181f43eee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_182ec12a8)(uVar2,0);
  return;
}

