// Ghidra pseudocode; not original source or compilable C.
// ev_5db9c7cef4489c0de9bc3c079a027abebfcc696f17a3b31c29d7b8aa7e599c33

int SeekableAesAssetBundle_Scripts_SeekableAesStream__Read__06000014
              (longlong *param_1,undefined8 param_2,undefined4 param_3,int param_4,longlong param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(*param_1 + 0x1e8))(param_1,*(undefined8 *)(*param_1 + 0x1f0));
  SeekableAesAssetBundle_Scripts_SeekableAesStream__Cipher__06000009
            (param_1,param_2,param_3,param_4,uVar2,0);
  lVar1 = param_1[9];
  if (param_5 < lVar1 + param_4) {
    param_1[9] = param_5;
    param_4 = (int)param_5 - (int)lVar1;
  }
  else {
    param_1[9] = lVar1 + param_4;
  }
  return param_4;
}

