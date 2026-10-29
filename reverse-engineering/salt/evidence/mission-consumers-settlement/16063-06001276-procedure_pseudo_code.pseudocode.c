// Ghidra pseudocode; not original source or compilable C.
// ev_8c71c293a3a6c77a47c54f48bf8215f21f2542ab10c2c91bf7f135d12950c8c0

void ExposureUnnoticed2_Master_Mission_MMissionOverrideRecord__Initialize__06001276
               (longlong param_1,int param_2,int param_3)

{
  *(int *)(param_1 + 0x54) = param_3;
  *(int *)(param_1 + 0x50) = param_3 * 10000 + param_2;
  return;
}

