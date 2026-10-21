// Ghidra pseudocode; not original source or compilable C.
// ev_939a208ab67c6e7bd5ea02da5b8ae9af76586b4ec3a994b1205f71a26f36ee60

void DelayTimeModel___ctor__06001753
               (longlong param_1,undefined8 param_2,undefined4 param_3,char param_4)

{
  ulonglong uVar1;
  code *pcVar2;
  code *pcVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  bool bVar7;
  undefined4 uVar8;
  
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x10) = param_2;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0x10U >> 0xc);
    uVar5 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
      LOCK();
      bVar7 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8) = uVar1 | 1L << (ulonglong)(uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  *(undefined4 *)(param_1 + 0x18) = param_3;
  *(undefined4 *)(param_1 + 0x20) = param_3;
  *(char *)(param_1 + 0x24) = param_4;
  pcVar2 = DAT_182ec14c0;
  if (param_4 == '\0') {
    pcVar3 = DAT_182ec14c0;
    if ((DAT_182ec14c0 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar2 = pcVar3,
       pcVar3 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
  }
  else {
    pcVar3 = DAT_182ec14e0;
    if (DAT_182ec14e0 == (code *)0x0) {
      pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_unscaledTime()");
      if (pcVar2 == (code *)0x0) {
        uVar4 = FUN_1802ced60("UnityEngine.Time::get_unscaledTime()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      DAT_182ec14e0 = pcVar2;
      uVar8 = (*pcVar2)();
      *(undefined4 *)(param_1 + 0x1c) = uVar8;
      return;
    }
  }
  DAT_182ec14c0 = pcVar2;
  uVar8 = (*pcVar3)();
  *(undefined4 *)(param_1 + 0x1c) = uVar8;
  return;
}

