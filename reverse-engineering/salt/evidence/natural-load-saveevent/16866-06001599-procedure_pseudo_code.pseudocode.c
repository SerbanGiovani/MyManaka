// Ghidra pseudocode; not original source or compilable C.
// ev_ffb72c9b788c7000bf9b2e4d83d1475a3ce7d679be5e1350d552f909619bb296

void ExposureUnnoticed2_Scripts_InGame_InGameManager__OnExitInGameEvent__06001599
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 unaff_RBX;
  undefined4 auStackX_10 [6];
  
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
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  auStackX_10[0] = FUN_181f58ac0(0);
  if (cRam0000000182ec199b == '\0') {
    FUN_1802f2810(&DAT_182d535b8,auStackX_10[0],0,param_4,unaff_RBX);
    LOCK();
    UNLOCK();
    cRam0000000182ec199b = '\x01';
  }
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar1 = pcRam0000000182ec19c0;
  if ((pcRam0000000182ec19c0 == (code *)0x0) &&
     (pcVar1 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.SceneManagement.SceneManager::MoveGameObjectToScene_Injected(UnityEngine.GameObject,UnityEngine.SceneManagement.Scene&)"
                                    ), pcVar1 == (code *)0x0)) {
    uVar2 = FUN_1802ced60(
                         "UnityEngine.SceneManagement.SceneManager::MoveGameObjectToScene_Injected(UnityEngine.GameObject,UnityEngine.SceneManagement.Scene&)"
                         );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  pcRam0000000182ec19c0 = pcVar1;
  (*pcRam0000000182ec19c0)(uVar2,auStackX_10);
  return;
}

