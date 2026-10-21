// Ghidra pseudocode; not original source or compilable C.
// ev_d8c6c43f6e893ba4dbfd0d3b24bb218eaa655894dd7fd24a7d34059d90d9fef0

undefined8 ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  code *pcVar5;
  undefined8 uVar6;
  uint uVar7;
  
  if (DAT_182eb7aa0 == '\0') {
    FUN_1802f2810(&DAT_182d5f928);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d55b08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f920);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f918);
    LOCK();
    UNLOCK();
    DAT_182eb7aa0 = '\x01';
  }
  lVar4 = **(longlong **)(DAT_182d5f920 + 0xb8);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12f3 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f3 = '\x01';
  }
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec129b == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec129b = '\x01';
  }
  if (lVar4 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar4 + 0x10) != 0) goto LAB_1804b3c21;
  }
  lVar4 = FUN_1802c43a0(DAT_182d55b08);
  FUN_181f3ed60(lVar4,DAT_182d5f918,0);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar5 = DAT_182ec12d8;
  if ((DAT_182ec12d8 == (code *)0x0) &&
     (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Object::DontDestroyOnLoad(UnityEngine.Object)"),
     pcVar5 == (code *)0x0)) {
    uVar6 = FUN_1802ced60("UnityEngine.Object::DontDestroyOnLoad(UnityEngine.Object)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar6,0);
  }
  DAT_182ec12d8 = pcVar5;
  (*DAT_182ec12d8)(lVar4);
  if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar6 = FUN_1809a0770(lVar4,DAT_182d5f928);
  **(undefined8 **)(DAT_182d5f920 + 0xb8) = uVar6;
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)(*(ulonglong *)(DAT_182d5f920 + 0xb8) >> 0xc);
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
LAB_1804b3c21:
  return **(undefined8 **)(DAT_182d5f920 + 0xb8);
}

