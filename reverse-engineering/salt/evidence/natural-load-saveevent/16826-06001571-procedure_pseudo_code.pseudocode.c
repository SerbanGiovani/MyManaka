// Ghidra pseudocode; not original source or compilable C.
// ev_028198e28017472aa46279968088544be9167a408823b76cb8cce9434614e92f

void ExposureUnnoticed2_Scripts_InGame_InGameEventListener__OnExitInGameEvent__06001571(void)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 unaff_RBX;
  undefined8 in_R9;
  undefined4 auStackX_10 [6];
  
  if (cRam0000000182eb79d1 == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb79d1 = '\x01';
  }
  lVar1 = **(longlong **)(DAT_182d53c48 + 0xb8);
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (cRam0000000182eb79dc == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535b8);
    LOCK();
    UNLOCK();
    cRam0000000182eb79dc = '\x01';
  }
  *(undefined1 *)(*(longlong *)(DAT_182d53c48 + 0xb8) + 8) = 0;
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
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  auStackX_10[0] = FUN_181f58ac0(0);
  if (cRam0000000182ec199b == '\0') {
    FUN_1802f2810(&DAT_182d535b8,auStackX_10[0],0,in_R9,unaff_RBX);
    LOCK();
    UNLOCK();
    cRam0000000182ec199b = '\x01';
  }
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar2 = pcRam0000000182ec19c0;
  if ((pcRam0000000182ec19c0 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.SceneManagement.SceneManager::MoveGameObjectToScene_Injected(UnityEngine.GameObject,UnityEngine.SceneManagement.Scene&)"
                                    ), pcVar2 == (code *)0x0)) {
    uVar3 = FUN_1802ced60(
                         "UnityEngine.SceneManagement.SceneManager::MoveGameObjectToScene_Injected(UnityEngine.GameObject,UnityEngine.SceneManagement.Scene&)"
                         );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  pcRam0000000182ec19c0 = pcVar2;
  (*pcRam0000000182ec19c0)(uVar3,auStackX_10);
  return;
}

