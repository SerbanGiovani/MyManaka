// Ghidra pseudocode; not original source or compilable C.
// ev_bb4db7d521b956d1e3c46ad26db1a740a3b12040a3623d20fa8ed53de5cf8a52

ulonglong ES3Internal_ES3IO___cctor__0600061f(void)

{
  longlong lVar1;
  ulonglong uVar2;
  code *pcVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  bool bVar7;
  
  if (cRam0000000182eb8058 == '\0') {
    FUN_1802f2810(&DAT_182d53a48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53488);
    LOCK();
    UNLOCK();
    cRam0000000182eb8058 = '\x01';
  }
  if (*(int *)(DAT_182d53a48 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar3 = pcRam0000000182ebf9c0;
  if ((pcRam0000000182ebf9c0 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Application::get_persistentDataPath()"),
     pcVar3 == (code *)0x0)) {
    uVar4 = FUN_1802ced60("UnityEngine.Application::get_persistentDataPath()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  pcRam0000000182ebf9c0 = pcVar3;
  uVar4 = (*pcRam0000000182ebf9c0)();
  **(undefined8 **)(DAT_182d53488 + 0xb8) = uVar4;
  if (DAT_182eb5d50 != 0) {
    uVar6 = (uint)(*(ulonglong *)(DAT_182d53488 + 0xb8) >> 0xc);
    lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  pcVar3 = DAT_182ebf9b0;
  if ((DAT_182ebf9b0 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Application::get_dataPath()"),
     pcVar3 == (code *)0x0)) {
    uVar4 = FUN_1802ced60("UnityEngine.Application::get_dataPath()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  DAT_182ebf9b0 = pcVar3;
  uVar5 = (*DAT_182ebf9b0)();
  *(ulonglong *)(*(longlong *)(DAT_182d53488 + 0xb8) + 8) = uVar5;
  if (DAT_182eb5d50 != 0) {
    uVar6 = (uint)(*(longlong *)(DAT_182d53488 + 0xb8) + 8U >> 0xc);
    lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      bVar7 = uVar2 == uVar5;
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar6 & 0x3f);
        uVar5 = uVar2;
      }
      UNLOCK();
    } while (!bVar7);
  }
  return uVar5;
}

