// Ghidra pseudocode; not original source or compilable C.
// ev_996a5756620c9def27e39dc139480995c5b1548b5f77278132df09cdf3be6db4

ulonglong __c___OnClickLoad_b__8_2__0600195e(void)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  code *pcVar4;
  ulonglong unaff_RBX;
  ulonglong auStackX_8 [2];
  undefined8 uStackX_18;
  
  if (cRam0000000182eb7bfd == '\0') {
    FUN_1802f2810(&DAT_182d535b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61bc8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7bfd = '\x01';
  }
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar3 = uRam0000000182d61bc8;
  if (cRam0000000182ec19a2 == '\0') {
    FUN_1802f2810(&DAT_182d535b8);
    LOCK();
    UNLOCK();
    cRam0000000182ec19a2 = '\x01';
  }
  uStackX_18 = 0;
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar1 = uStackX_18;
  auStackX_8[0] = unaff_RBX;
  if (cRam0000000182ec19a3 == '\0') {
    FUN_1802f2810(&DAT_182d535b8,uStackX_18,0);
    LOCK();
    UNLOCK();
    cRam0000000182ec19a3 = '\x01';
  }
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_181f58bf0(uVar3,0xffffffff,uVar1,1,0);
  pcVar4 = pcRam0000000182ec1990;
  if ((pcRam0000000182ec1990 == (code *)0x0) &&
     (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.SceneManagement.SceneManager::get_sceneCount()"),
     pcVar4 == (code *)0x0)) {
    uVar3 = FUN_1802ced60("UnityEngine.SceneManagement.SceneManager::get_sceneCount()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  pcRam0000000182ec1990 = pcVar4;
  iVar2 = (*pcRam0000000182ec1990)();
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
  pcVar4 = pcRam0000000182ec19b8;
  if ((pcRam0000000182ec19b8 == (code *)0x0) &&
     (pcVar4 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.SceneManagement.SceneManager::GetSceneAt_Injected(System.Int32,UnityEngine.SceneManagement.Scene&)"
                                    ), pcVar4 == (code *)0x0)) {
    uVar3 = FUN_1802ced60(
                         "UnityEngine.SceneManagement.SceneManager::GetSceneAt_Injected(System.Int32,UnityEngine.SceneManagement.Scene&)"
                         );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  pcRam0000000182ec19b8 = pcVar4;
  (*pcRam0000000182ec19b8)(iVar2 + -1,auStackX_8);
  return auStackX_8[0] & 0xffffffff;
}

