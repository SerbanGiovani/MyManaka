// Ghidra pseudocode; not original source or compilable C.
// ev_75126521564cd7c974923a14fe094c83a1ca03707e360f388e78730b3144f038

void ExposureUnnoticed2_Object3D_NPC_Script_NpcComponent__set_AvaterObject__0600100e
               (longlong param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  bVar5 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x90) = param_2;
  if (bVar5) {
    uVar4 = (uint)(param_1 + 0x90U >> 0xc);
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

