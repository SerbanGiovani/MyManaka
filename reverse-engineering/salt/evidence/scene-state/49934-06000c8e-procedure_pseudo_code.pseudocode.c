// Ghidra pseudocode; not original source or compilable C.
// ev_666c62dc517d4b6e135ed73260b6d94ffcb8bf57997cc29d8467b98499f53760

void UnityEngine_SceneManagement_SceneManagerAPIInternal__LoadSceneAsyncNameIndexInternal__06000c8e
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined1 param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 auStackX_18 [2];
  
  pcVar1 = pcRam0000000182ec1980;
  auStackX_18[0] = param_3;
  if ((pcRam0000000182ec1980 == (code *)0x0) &&
     (pcVar1 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.SceneManagement.SceneManagerAPIInternal::LoadSceneAsyncNameIndexInternal_Injected(System.String,System.Int32,UnityEngine.SceneManagement.LoadSceneParameters&,System.Boolean)"
                                    ), pcVar1 == (code *)0x0)) {
    uVar2 = FUN_1802ced60(
                         "UnityEngine.SceneManagement.SceneManagerAPIInternal::LoadSceneAsyncNameIndexInternal_Injected(System.String,System.Int32,UnityEngine.SceneManagement.LoadSceneParameters&,System.Boolean)"
                         );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  pcRam0000000182ec1980 = pcVar1;
  (*pcRam0000000182ec1980)(param_1,param_2,auStackX_18,param_4);
  return;
}

