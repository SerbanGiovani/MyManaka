// Ghidra pseudocode; not original source or compilable C.
// ev_1317c46c5ba65e32abfc40054fbd41bc73003887cbbfbe8b37a271022e49c9d8

void Common_Scripts_Util_AnimatorFPSController__Initialize__06001e07
               (longlong param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  bVar5 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x18) = param_2;
  if (bVar5) {
    uVar4 = (uint)(param_1 + 0x18U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar4 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  return;
}

