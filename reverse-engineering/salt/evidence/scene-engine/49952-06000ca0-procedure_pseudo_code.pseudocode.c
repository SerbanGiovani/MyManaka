// Ghidra pseudocode; not original source or compilable C.
// ev_6c908896fc55f2aabbae85898f3b43fc0024e4a3184b55ab516d7fdc01871bf7

ulonglong UnityEngine_SceneManagement_SceneManager__LoadScene__06000ca0
                    (undefined8 param_1,uint param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  undefined8 uVar4;
  code *pcVar5;
  ulonglong unaff_RBX;
  ulonglong uStackX_8;
  
  if (cRam0000000182ec19a1 == '\0') {
    FUN_1802f2810(&DAT_182d535b8);
    LOCK();
    UNLOCK();
    cRam0000000182ec19a1 = '\x01';
  }
  uStackX_8 = (ulonglong)param_2;
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar1 = uStackX_8;
  uVar2 = unaff_RBX;
  if (cRam0000000182ec19a3 == '\0') {
    uVar2 = unaff_RBX;
    FUN_1802f2810(&DAT_182d535b8,uStackX_8,0);
    uStackX_8 = uVar2;
    LOCK();
    UNLOCK();
    cRam0000000182ec19a3 = '\x01';
    uVar2 = uStackX_8;
  }
  uStackX_8 = uVar2;
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
  uStackX_8 = uStackX_8 & 0xffffffff00000000;
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
  (*pcRam0000000182ec19b8)(iVar3 + -1,&uStackX_8);
  return uStackX_8 & 0xffffffff;
}

