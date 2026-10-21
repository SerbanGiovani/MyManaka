// Ghidra pseudocode; not original source or compilable C.
// ev_0be9cd0406461932126d75ec99598ffaf3458d7d3a10b42d02cb27841fc68180

ulonglong __c__DisplayClass42_1___LoadAssetAsync_b__1__060000cc(longlong param_1,longlong param_2)

{
  ulonglong *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong *puVar5;
  ulonglong uVar6;
  ulonglong *puVar7;
  
  if (param_2 != 0) {
    lVar2 = FUN_181f43410(param_2,0);
    if (lVar2 != 0) {
      lVar2 = System_String__ToLower__06000247(lVar2,0);
      uVar3 = *(ulonglong *)(param_1 + 0x10);
      if (uVar3 != 0) {
        lVar4 = (longlong)*(int *)(uVar3 + 0x18) + -1;
        if (*(uint *)(uVar3 + 0x18) <= (uint)lVar4) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dae0();
        }
        lVar4 = *(longlong *)(uVar3 + 0x20 + lVar4 * 8);
        if (lVar2 == lVar4) {
          return CONCAT71((int7)(uVar3 >> 8),1);
        }
        if (((lVar2 == 0) || (lVar4 == 0)) ||
           (uVar3 = (ulonglong)*(uint *)(lVar4 + 0x10),
           *(uint *)(lVar2 + 0x10) != *(uint *)(lVar4 + 0x10))) {
          return uVar3 & 0xffffffffffffff00;
        }
        puVar1 = (ulonglong *)(lVar2 + 0x14);
        uVar6 = (longlong)*(int *)(lVar2 + 0x10) * 2;
        puVar5 = (ulonglong *)(lVar4 + 0x14);
        if (puVar1 != puVar5) {
          if (7 < uVar6) {
            uVar6 = uVar6 - 8;
            if (uVar6 != 0) {
              puVar7 = puVar5;
              do {
                uVar3 = *puVar7;
                if (*(ulonglong *)((longlong)puVar7 + ((longlong)puVar1 - (longlong)puVar5)) !=
                    uVar3) goto LAB_181630b44;
                puVar7 = puVar7 + 1;
              } while ((ulonglong)((longlong)puVar7 - (longlong)puVar5) < uVar6);
            }
            return CONCAT71((int7)((ulonglong)*(longlong *)(uVar6 + (longlong)puVar5) >> 8),
                            *(longlong *)(uVar6 + (longlong)puVar1) ==
                            *(longlong *)(uVar6 + (longlong)puVar5));
          }
          if (uVar6 != 0) {
            puVar7 = puVar5;
            do {
              uVar3 = 0;
              if (*(char *)((longlong)puVar7 + ((longlong)puVar1 - (longlong)puVar5)) !=
                  (char)*puVar7) {
LAB_181630b44:
                return uVar3 & 0xffffffffffffff00;
              }
              puVar7 = (ulonglong *)((longlong)puVar7 + 1);
              uVar3 = (longlong)puVar7 - (longlong)puVar5;
            } while (uVar3 < uVar6);
          }
        }
        return CONCAT71((int7)(uVar3 >> 8),1);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

