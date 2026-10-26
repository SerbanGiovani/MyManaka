// Ghidra pseudocode; not original source or compilable C.
// ev_9d504903e9433e88dd57f7a2fbcfe655aa297c0ca1552c8011c02101315904a8

void ES3Internal_ES3JSONWriter___ctor__0600072f
               (longlong *param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4,
               undefined1 param_5)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  bool bVar6;
  
  if (DAT_182eb80cd == '\0') {
    FUN_1802f2810(&DAT_182d52a40);
    LOCK();
    UNLOCK();
    DAT_182eb80cd = '\x01';
  }
  *(undefined1 *)(param_1 + 6) = 1;
  ES3Writer___ctor__06000269(param_1,param_3,param_4,param_5,0);
  lVar4 = FUN_1802c43a0(DAT_182d52a40);
  FUN_1815e47f0(lVar4,param_2,0);
  bVar6 = DAT_182eb5d50 != 0;
  param_1[5] = lVar4;
  if (bVar6) {
    uVar5 = (uint)((ulonglong)(param_1 + 5) >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
                    /* WARNING: Could not recover jumptable at 0x0001805a84b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x198))(param_1,*(undefined8 *)(*param_1 + 0x1a0));
  return;
}

