// Ghidra pseudocode; not original source or compilable C.
// ev_976341ee8c67693ed259ddd0a28a6e8f0a6c36dd36faece251ea531f66a5f1f4

void UnityEngine_GameObject__GetComponentFastPath__06000962
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  
  pcVar1 = pcRam0000000182ec10e0;
  if ((pcRam0000000182ec10e0 == (code *)0x0) &&
     (pcVar1 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.GameObject::GetComponentFastPath(System.Type,System.IntPtr)"
                                    ), pcVar1 == (code *)0x0)) {
    uVar2 = func_0x0001802ced60(
                               "UnityEngine.GameObject::GetComponentFastPath(System.Type,System.IntPtr)"
                               );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  pcRam0000000182ec10e0 = pcVar1;
                    /* WARNING: Could not recover jumptable at 0x000181f3e1a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000182ec10e0)(param_1,param_2,param_3);
  return;
}

