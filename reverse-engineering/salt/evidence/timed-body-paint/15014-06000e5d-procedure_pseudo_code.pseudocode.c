// Ghidra pseudocode; not original source or compilable C.
// ev_5065a9d89487d9703a209b419e5f34c102f31d43db86d25f0c542fe20be95caa

bool ExposureUnnoticed2_Object3D_Player_Scripts_Other_BodyPaintController__IsPainted__06000e5d
               (longlong param_1)

{
  if (*(int *)(param_1 + 0x20) == 1) {
    return false;
  }
  return *(int *)(param_1 + 0x20) != 0;
}

