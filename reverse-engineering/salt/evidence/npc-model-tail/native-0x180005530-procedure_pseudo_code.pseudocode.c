// Ghidra pseudocode; not original source or compilable C.
// ev_7b70115316cad33fc4e07a3ad8f540b4b1a1d30b6068fd31af1cae7831d6c5bc

undefined8 native_only_180005530__00000000(longlong param_1)

{
  undefined4 uVar1;
  uint uVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (*(longlong *)(param_1 + 0x18) != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x18);
    pcVar3 = DAT_182ec0fd0;
    if ((DAT_182ec0fd0 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Random::RandomRangeInt(System.Int32,System.Int32)"
                                      ), pcVar3 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Random::RandomRangeInt(System.Int32,System.Int32)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec0fd0 = pcVar3;
    uVar2 = (*DAT_182ec0fd0)(0,uVar1);
    if (*(uint *)(param_1 + 0x18) <= uVar2) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    return *(undefined8 *)(param_1 + 0x20 + (longlong)(int)uVar2 * 8);
  }
  return 0;
}

