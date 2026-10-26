// Ghidra pseudocode; not original source or compilable C.
// ev_57b190c9ee78f9cd00a1fd21ae136facc92dec082fdd52eeff285c026f841389

void ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__Initialize__06001093
               (longlong param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  bVar5 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x48) = param_2;
  if (bVar5) {
    uVar4 = (uint)(param_1 + 0x48U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (ulonglong)(uVar4 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  FUN_180436590(param_1);
  *(undefined1 *)(param_1 + 100) = 1;
  return;
}

