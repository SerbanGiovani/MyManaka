// Ghidra pseudocode; not original source or compilable C.
// ev_414a0aa17197ca9e41a067a64b6ad80369ff62e55153fbf394887fb66ee5a77d

void ES3Writer__Create__0600027d(longlong param_1,longlong param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  bool bVar7;
  
  if (cRam0000000182eb75b7 == '\0') {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    cRam0000000182eb75b7 = '\x01';
  }
  lVar4 = FUN_1802c43a0(DAT_182d534a8);
  ES3Settings___ctor__060001ba(lVar4,1,0);
  if (param_2 != 0) {
    ES3Settings__CopyInto__060001bd(param_2,lVar4,0);
  }
  if ((param_1 != 0) && (bVar7 = DAT_182eb5d50 != 0, *(longlong *)(lVar4 + 0x18) = param_1, bVar7))
  {
    uVar6 = (uint)(lVar4 + 0x18U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  lVar5 = ES3Internal_ES3Stream__CreateStream__060006e5(lVar4,1,0);
  if (lVar5 == 0) {
    return;
  }
  ES3Writer__Create__06000280(lVar5,lVar4,1,1,0);
  return;
}

