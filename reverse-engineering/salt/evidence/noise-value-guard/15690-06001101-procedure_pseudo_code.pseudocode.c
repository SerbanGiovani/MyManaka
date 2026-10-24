// Ghidra pseudocode; not original source or compilable C.
// ev_7d90a68b9c02946d506c9ab555f09fbb12d63d3e67515627d0c7cd6ade37019b

void ExposureUnnoticed2_Object3D_NPC_Script_StrangenessValueManager__set_Value__06001101
               (longlong param_1,float param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  *(undefined4 *)(param_1 + 0x18) = 0x78;
  if ((0.0 <= param_2) && (uVar1 = 0x3f800000, param_2 <= 1.0)) {
    *(float *)(param_1 + 0x14) = param_2;
    return;
  }
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  return;
}

