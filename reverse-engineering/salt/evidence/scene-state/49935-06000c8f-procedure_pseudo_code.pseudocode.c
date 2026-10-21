// Ghidra pseudocode; not original source or compilable C.
// ev_6c6147e36f25e0e4a858444d13ef5b2a544917c0c94bd8eae8f8818bc20405bd

void UnityEngine_SceneManagement_SceneManagerAPIInternal__LoadSceneAsyncNameIndexInternal_Injected__06000c8f
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined1 param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  
  pcVar1 = pcRam0000000182ec1980;
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
                    /* WARNING: Could not recover jumptable at 0x000181f58824. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000182ec1980)(param_1,param_2,param_3,param_4);
  return;
}

