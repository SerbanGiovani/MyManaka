// Ghidra pseudocode; not original source or compilable C.
// ev_1a0d339c13439fb98d775f60afd9a96d22509f8fcb35299d8e5e086e0ed9d3e4

ulonglong ExposureUnnoticed2_Scripts_OtherScene_SpringboardLoadEmpty__Start__06001409(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  code *pcVar6;
  ulonglong unaff_RBX;
  ulonglong auStackX_8 [2];
  undefined8 uStackX_18;
  
  if (cRam0000000182eb78f6 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d594e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d535b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e268);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d57e50);
    LOCK();
    UNLOCK();
    cRam0000000182eb78f6 = '\x01';
  }
  if (**(longlong **)(lRam0000000182d57e50 + 0xb8) != 0) {
    FUN_1804bbf60(**(longlong **)(lRam0000000182d57e50 + 0xb8),0,0,0);
    **(undefined1 **)(lRam0000000182d5e268 + 0xb8) = 1;
    lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar4 != 0) {
      uVar1 = *(undefined4 *)(lVar4 + 0x10);
      if (*(int *)(lRam0000000182d594e8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar4 = FUN_1804643d0(uVar1,0);
      if (lVar4 != 0) {
        uVar5 = *(undefined8 *)(lVar4 + 0x20);
        if (*(int *)(lRam0000000182d535b8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (cRam0000000182ec19a2 == '\0') {
          FUN_1802f2810(0x182d535b8);
          LOCK();
          UNLOCK();
          cRam0000000182ec19a2 = '\x01';
        }
        uStackX_18 = 0;
        if (*(int *)(lRam0000000182d535b8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar2 = uStackX_18;
        auStackX_8[0] = unaff_RBX;
        if (cRam0000000182ec19a3 == '\0') {
          FUN_1802f2810(0x182d535b8,uStackX_18,0);
          LOCK();
          UNLOCK();
          cRam0000000182ec19a3 = '\x01';
        }
        if (*(int *)(lRam0000000182d535b8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        FUN_181f58bf0(uVar5,0xffffffff,uVar2,1,0);
        pcVar6 = pcRam0000000182ec1990;
        if ((pcRam0000000182ec1990 == (code *)0x0) &&
           (pcVar6 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.SceneManagement.SceneManager::get_sceneCount()"
                                          ), pcVar6 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.SceneManagement.SceneManager::get_sceneCount()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        pcRam0000000182ec1990 = pcVar6;
        iVar3 = (*pcRam0000000182ec1990)();
        if (cRam0000000182ec1999 == '\0') {
          FUN_1802f2810(0x182d535b8,0);
          LOCK();
          UNLOCK();
          cRam0000000182ec1999 = '\x01';
        }
        auStackX_8[0] = auStackX_8[0] & 0xffffffff00000000;
        if (*(int *)(lRam0000000182d535b8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        pcVar6 = pcRam0000000182ec19b8;
        if ((pcRam0000000182ec19b8 == (code *)0x0) &&
           (pcVar6 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.SceneManagement.SceneManager::GetSceneAt_Injected(System.Int32,UnityEngine.SceneManagement.Scene&)"
                                          ), pcVar6 == (code *)0x0)) {
          uVar5 = FUN_1802ced60(
                               "UnityEngine.SceneManagement.SceneManager::GetSceneAt_Injected(System.Int32,UnityEngine.SceneManagement.Scene&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        pcRam0000000182ec19b8 = pcVar6;
        (*pcRam0000000182ec19b8)(iVar3 + -1,auStackX_8);
        return auStackX_8[0] & 0xffffffff;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

