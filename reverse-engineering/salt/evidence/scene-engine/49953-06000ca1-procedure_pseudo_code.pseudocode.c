// Ghidra pseudocode; not original source or compilable C.
// ev_49abe3b64ca3247c2cfc0f777fc49133d6ba354028fc5f2a326e7e7ec46ffe4f

ulonglong UnityEngine_SceneManagement_SceneManager__LoadScene__06000ca1(undefined8 param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  undefined8 uVar4;
  code *pcVar5;
  ulonglong unaff_RBX;
  ulonglong auStackX_8 [4];
  
  if (cRam0000000182ec19a2 == '\0') {
    FUN_1802f2810(&DAT_182d535b8);
    LOCK();
    UNLOCK();
    cRam0000000182ec19a2 = '\x01';
  }
  auStackX_8[0] = 0;
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar1 = auStackX_8[0];
  uVar2 = unaff_RBX;
  if (cRam0000000182ec19a3 == '\0') {
    uVar2 = unaff_RBX;
    FUN_1802f2810(&DAT_182d535b8,auStackX_8[0],0);
    auStackX_8[0] = uVar2;
    LOCK();
    UNLOCK();
    cRam0000000182ec19a3 = '\x01';
    uVar2 = auStackX_8[0];
  }
  auStackX_8[0] = uVar2;
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_181f58bf0(param_1,0xffffffff,uVar1,1,0);
  pcVar5 = pcRam0000000182ec1990;
  if ((pcRam0000000182ec1990 == (code *)0x0) &&
     (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.SceneManagement.SceneManager::get_sceneCount()"),
     pcVar5 == (code *)0x0)) {
    uVar4 = FUN_1802ced60("UnityEngine.SceneManagement.SceneManager::get_sceneCount()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  pcRam0000000182ec1990 = pcVar5;
  iVar3 = (*pcRam0000000182ec1990)();
  if (cRam0000000182ec1999 == '\0') {
    FUN_1802f2810(&DAT_182d535b8,0);
    LOCK();
    UNLOCK();
    cRam0000000182ec1999 = '\x01';
  }
  auStackX_8[0] = auStackX_8[0] & 0xffffffff00000000;
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar5 = pcRam0000000182ec19b8;
  if ((pcRam0000000182ec19b8 == (code *)0x0) &&
     (pcVar5 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.SceneManagement.SceneManager::GetSceneAt_Injected(System.Int32,UnityEngine.SceneManagement.Scene&)"
                                    ), pcVar5 == (code *)0x0)) {
    uVar4 = FUN_1802ced60(
                         "UnityEngine.SceneManagement.SceneManager::GetSceneAt_Injected(System.Int32,UnityEngine.SceneManagement.Scene&)"
                         );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  pcRam0000000182ec19b8 = pcVar5;
  (*pcRam0000000182ec19b8)(iVar3 + -1,auStackX_8);
  return auStackX_8[0] & 0xffffffff;
}

