// Ghidra pseudocode; not original source or compilable C.
// ev_c3f984c16df16168fb59ef91aed61884fbb09eb5fbb82cd0c62089fa244903a2

undefined8
UnityEngine_SceneManagement_SceneManager__LoadScene__06000ca2(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  code *pcVar3;
  
  if (cRam0000000182ec19a3 == '\0') {
    FUN_1802f2810(&DAT_182d535b8);
    LOCK();
    UNLOCK();
    cRam0000000182ec19a3 = '\x01';
  }
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_181f58bf0(param_1,0xffffffff,param_2,1,0);
  pcVar3 = pcRam0000000182ec1990;
  if ((pcRam0000000182ec1990 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.SceneManagement.SceneManager::get_sceneCount()"),
     pcVar3 == (code *)0x0)) {
    uVar2 = FUN_1802ced60("UnityEngine.SceneManagement.SceneManager::get_sceneCount()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  pcRam0000000182ec1990 = pcVar3;
  iVar1 = (*pcRam0000000182ec1990)();
  if (cRam0000000182ec1999 == '\0') {
    FUN_1802f2810(&DAT_182d535b8,0);
    LOCK();
    UNLOCK();
    cRam0000000182ec1999 = '\x01';
  }
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar3 = pcRam0000000182ec19b8;
  if ((pcRam0000000182ec19b8 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.SceneManagement.SceneManager::GetSceneAt_Injected(System.Int32,UnityEngine.SceneManagement.Scene&)"
                                    ), pcVar3 == (code *)0x0)) {
    uVar2 = FUN_1802ced60(
                         "UnityEngine.SceneManagement.SceneManager::GetSceneAt_Injected(System.Int32,UnityEngine.SceneManagement.Scene&)"
                         );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  pcRam0000000182ec19b8 = pcVar3;
  (*pcRam0000000182ec19b8)(iVar1 + -1,&stack0x00000008);
  return 0;
}

