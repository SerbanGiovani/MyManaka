// Ghidra pseudocode; not original source or compilable C.
// ev_a3be7c903a33715e06ebbd829ba61f4b2ffc5aa52cdb2f1fbdacd6987106e502

undefined8 ES3Reader__Create__06000197(longlong param_1,longlong param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  bool bVar8;
  
  if (cRam0000000182eb7546 == '\0') {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7546 = '\x01';
  }
  lVar4 = FUN_1802c43a0(DAT_182d534a8);
  ES3Settings___ctor__060001ba(lVar4,1,0);
  if (param_2 != 0) {
    ES3Settings__CopyInto__060001bd(param_2,lVar4,0);
  }
  if ((param_1 != 0) && (bVar8 = DAT_182eb5d50 != 0, *(longlong *)(lVar4 + 0x18) = param_1, bVar8))
  {
    uVar7 = (uint)(lVar4 + 0x18U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  if (DAT_182eb7547 == '\0') {
    FUN_1802f2810(&DAT_182d527e0);
    LOCK();
    UNLOCK();
    DAT_182eb7547 = '\x01';
  }
  lVar5 = ES3Internal_ES3Stream__CreateStream__060006e5(lVar4,0,0);
  if (lVar5 != 0) {
    if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(int *)(lVar4 + 0x34) == 0) {
      uVar6 = FUN_1802c43a0(DAT_182d527e0);
      ES3Internal_ES3JSONReader___ctor__0600069f(uVar6,lVar5,lVar4,1,0);
      return uVar6;
    }
  }
  return 0;
}

