// Ghidra pseudocode; not original source or compilable C.
// ev_48bc71daee042d962bf86926f069802744334ba07c5cf19e5130710e19b03e56

void IKA9nt_Encrypter_BridgeAssetBundleRequest____ctor_b__30_0__06000055(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  plVar1 = *(longlong **)(param_1 + 0x10);
  if (plVar1 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar3 = (**(code **)(*plVar1 + 0x178))(plVar1,*(undefined8 *)(*plVar1 + 0x180));
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (lVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000181434ae2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar2 + 0x18))
              (*(undefined8 *)(lVar2 + 0x40),uVar3,*(undefined8 *)(lVar2 + 0x28),
               *(code **)(lVar2 + 0x18));
    return;
  }
  return;
}

