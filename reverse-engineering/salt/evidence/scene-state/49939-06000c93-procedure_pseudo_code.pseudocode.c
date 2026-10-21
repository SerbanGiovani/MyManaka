// Ghidra pseudocode; not original source or compilable C.
// ev_d6792efb722919777243da0ba84610d2b7fceed747403c20a5b443104932647a

void UnityEngine_SceneManagement_SceneManagerAPI__LoadSceneAsyncByNameOrIndex__06000c93
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined1 param_5)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 auStackX_10 [3];
  
  pcVar1 = pcRam0000000182ec1980;
  auStackX_10[0] = param_4;
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
  (*pcRam0000000182ec1980)(param_2,param_3,auStackX_10,param_5);
  return;
}

