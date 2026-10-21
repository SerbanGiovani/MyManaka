// Ghidra pseudocode; not original source or compilable C.
// ev_6b7e5efed72ef4782d381ca4fe6df8caf7addd35a604e818984ce392c1c4890d

longlong ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__CreateFixedNpc__0600109b
                   (longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  
  lVar1 = ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__InstantiateNpc__0600109a
                    (param_1,0,0,param_2,0);
  if (lVar1 != 0) {
    ExposureUnnoticed2_Object3D_NPC_Script_NpcController__AdditionalInitializeForFixAction__06001056
              (lVar1,param_2,0);
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;
    return lVar1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

