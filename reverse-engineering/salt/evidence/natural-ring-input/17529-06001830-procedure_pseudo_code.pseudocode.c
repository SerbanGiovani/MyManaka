// Ghidra pseudocode; not original source or compilable C.
// ev_5d32d1b3c5004790adfd2d0480cb61691570657b82e6801cbf4a3c4a6cd59df5

void ExposureUnnoticed2_ObjectUI_SkillPanel_SkillItemView__OnClick__06001830(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x90);
  if (lVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001804c4732. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar1 + 0x18))
              (*(undefined8 *)(lVar1 + 0x40),*(undefined8 *)(param_1 + 0x80),
               *(undefined8 *)(lVar1 + 0x28));
    return;
  }
  return;
}

