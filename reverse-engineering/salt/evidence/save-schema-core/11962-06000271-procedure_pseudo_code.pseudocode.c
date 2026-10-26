// Ghidra pseudocode; not original source or compilable C.
// ev_187266c59969e637fff39946730f0f6cc66ac23313aef367d899de53add80c4d

void ES3Writer__WriteProperty__06000271
               (longlong *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  char cVar1;
  
  cVar1 = ES3Writer__SerializationDepthLimitExceeded__06000281(param_1,0);
  if (cVar1 == '\0') {
    (**(code **)(*param_1 + 0x1d8))(param_1,param_2,*(undefined8 *)(*param_1 + 0x1e0));
    (**(code **)(*param_1 + 0x3d8))(param_1,param_3,param_4,*(undefined8 *)(*param_1 + 0x3e0));
    (**(code **)(*param_1 + 0x1e8))(param_1,param_2,*(undefined8 *)(*param_1 + 0x1f0));
  }
  return;
}

