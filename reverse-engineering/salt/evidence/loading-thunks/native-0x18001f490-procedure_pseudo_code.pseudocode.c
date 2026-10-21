// Ghidra pseudocode; not original source or compilable C.
// ev_5cd1e5594e0ed87b6fec412e5e128778e3b020830559d6c6de0461fc1076e96c

void native_only_18001f490__00000000
               (undefined8 param_1,undefined8 param_2,longlong *param_3,undefined8 param_4)

{
  longlong lVar1;
  ushort uVar2;
  undefined8 *puVar3;
  
  lVar1 = *param_3;
  uVar2 = 0;
  if (*(ushort *)(lVar1 + 0x12e) != 0) {
    do {
      if (*(longlong *)(*(longlong *)(lVar1 + 0xb0) + (ulonglong)uVar2 * 0x10) ==
          lRam0000000182d342e0) {
        puVar3 = (undefined8 *)
                 ((longlong)
                  (*(int *)(*(longlong *)(lVar1 + 0xb0) + 8 + (ulonglong)uVar2 * 0x10) + 2) * 0x10 +
                  0x138 + lVar1);
        goto code_r0x00018001f4e4;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(ushort *)(lVar1 + 0x12e));
  }
  puVar3 = (undefined8 *)FUN_180320910(param_3,lRam0000000182d342e0,2);
code_r0x00018001f4e4:
                    /* WARNING: Could not recover jumptable at 0x00018001f4fb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar3)(param_3,param_4,puVar3[1],(code *)*puVar3);
  return;
}

