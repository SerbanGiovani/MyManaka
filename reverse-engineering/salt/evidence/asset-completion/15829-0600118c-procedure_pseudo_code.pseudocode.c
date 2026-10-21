// Ghidra pseudocode; not original source or compilable C.
// ev_9bee9b92f0a23d9510f725fadf37598169ffcd191e14218f349d5c579dd008d0

ulonglong ExposureUnnoticed2_Object3D_IngameManager_AssetReferencer__Awake__0600118c
                    (undefined8 param_1)

{
  ulonglong *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  code *pcVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  bool bVar8;
  
  if (cRam0000000182eb77e9 == '\0') {
    FUN_1802f2810(0x182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb77e9 = '\x01';
  }
  lVar2 = **(longlong **)(uRam0000000182d58238 + 0xb8);
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec12f3 == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec12f3 = '\x01';
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec129b == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec129b = '\x01';
  }
  if (lVar2 != 0) {
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar2 + 0x10) != 0) {
      pcVar4 = pcRam0000000182ec1088;
      if ((pcRam0000000182ec1088 == (code *)0x0) &&
         (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
         pcVar4 == (code *)0x0)) {
        uVar5 = func_0x0001802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      pcRam0000000182ec1088 = pcVar4;
      uVar5 = (*pcRam0000000182ec1088)(param_1);
      if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (cRam0000000182ec12b0 == '\0') {
        FUN_1802f2810(0x182d53aa8,0);
        LOCK();
        UNLOCK();
        cRam0000000182ec12b0 = '\x01';
      }
      if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      pcVar4 = pcRam0000000182ec12a8;
      if ((pcRam0000000182ec12a8 == (code *)0x0) &&
         (pcVar4 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)"
                                        ), pcVar4 == (code *)0x0)) {
        uVar5 = func_0x0001802ced60("UnityEngine.Object::Destroy(UnityEngine.Object,System.Single)")
        ;
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      pcRam0000000182ec12a8 = pcVar4;
                    /* WARNING: Could not recover jumptable at 0x000181f43eee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar6 = (*pcRam0000000182ec12a8)(uVar5,0);
      return uVar6;
    }
  }
  uVar6 = uRam0000000182d58238;
  **(undefined8 **)(uRam0000000182d58238 + 0xb8) = param_1;
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)(*(ulonglong *)(uRam0000000182d58238 + 0xb8) >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar6 = *puVar1;
      bVar8 = uVar3 == uVar6;
      if (bVar8) {
        *puVar1 = uVar3 | 1L << (uVar7 & 0x3f);
        uVar6 = uVar3;
      }
      UNLOCK();
    } while (!bVar8);
  }
  return uVar6;
}

