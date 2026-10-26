// Ghidra pseudocode; not original source or compilable C.
// ev_b34b1b24ec9f860a87cbaab8afa303cae818cf46907882e2628513799faa1202

ulonglong ES3Internal_ES3JSONReader___ctor__0600069f
                    (longlong param_1,undefined8 param_2,undefined8 param_3,char param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint uVar7;
  bool bVar8;
  short local_res20 [4];
  
  if (DAT_182eb80a4 == '\0') {
    FUN_1802f2810(&DAT_182d52ac0);
    LOCK();
    UNLOCK();
    DAT_182eb80a4 = '\x01';
  }
  *(undefined8 *)(param_1 + 0x10) = param_3;
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)(param_1 + 0x10U >> 0xc);
    lVar1 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar8 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar5 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
  uVar3 = FUN_1802c43a0(DAT_182d52ac0);
  uVar4 = FUN_1816df430(0);
  uVar5 = FUN_1815be7c0(uVar3,param_2,uVar4,1,0x400,0,0);
  *(undefined8 *)(param_1 + 0x28) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)(param_1 + 0x28U >> 0xc);
    lVar1 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      bVar8 = uVar2 == uVar5;
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar7 & 0x3f);
        uVar5 = uVar2;
      }
      UNLOCK();
    } while (!bVar8);
  }
  if (param_4 != '\0') {
    uVar5 = ES3Internal_ES3JSONReader__ReadCharIgnoreWhitespace__060006b2(param_1,1,0);
    local_res20[0] = (short)uVar5;
    if (local_res20[0] != 0x7b) {
      uVar3 = thunk_FUN_1802f2810(&DAT_182d52ad0);
      FUN_1800039e0(uVar3);
      uVar3 = FUN_1815ca950(local_res20,0);
      uVar4 = thunk_FUN_1802f2810(&DAT_182d6a550);
      uVar6 = thunk_FUN_1802f2810(&DAT_182d6a460);
      uVar3 = System_String__Concat__0600021c(uVar6,uVar3,uVar4,0);
      uVar4 = thunk_FUN_1802f2810(&DAT_182d52678);
      uVar4 = thunk_FUN_1802c43a0(uVar4);
      FUN_1815df2d0(uVar4,uVar3,0);
      uVar3 = thunk_FUN_1802f2810(&DAT_182d6a450);
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar4,uVar3);
    }
  }
  return uVar5;
}

