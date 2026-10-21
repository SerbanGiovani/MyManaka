// Ghidra pseudocode; not original source or compilable C.
// ev_e8b9233af6db0448f73b42cd4b775f22c0153276b71585ef07b2e95d64d7b507

void __c__DisplayClass42_0___LoadAssetAsync_b__2__060000ca(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x20);
  plVar2 = *(longlong **)(param_1 + 0x10);
  if (plVar2 != (longlong *)0x0) {
    uVar3 = (**(code **)(*plVar2 + 0x178))(plVar2,*(undefined8 *)(*plVar2 + 0x180));
    if (lVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001814404df. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(lVar1 + 0x18))
                (*(undefined8 *)(lVar1 + 0x40),uVar3,*(undefined8 *)(lVar1 + 0x28),
                 *(code **)(lVar1 + 0x18));
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

