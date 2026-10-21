// Ghidra pseudocode; not original source or compilable C.
// ev_e5a77520c8f98f4f9764a16f2f9cf5bd300c2e650d872a3e7d55acf08a068d77

void ExposureUnnoticed2_Object3D_UIPlayer_UiPlayerController__Initialize__060009cd(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  code *pcVar6;
  uint uVar7;
  bool bVar8;
  
  if (cRam0000000182eb8202 == '\0') {
    FUN_1802f2810(0x182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d58250);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c3a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d54d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d634f0);
    LOCK();
    UNLOCK();
    cRam0000000182eb8202 = '\x01';
  }
  if (*(int *)(lRam0000000182d634f0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_18060cf80(param_1);
  if (**(longlong **)(lRam0000000182d58238 + 0xb8) != 0) {
    uVar5 = *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x350);
    uVar2 = *(undefined8 *)(param_1 + 0x28);
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar4 = FUN_1809f1050(uVar5,uVar2,uRam0000000182d54d90);
    if (lVar4 != 0) {
      uVar5 = FUN_1809a08f0(lVar4,uRam0000000182d58250);
      bVar8 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x30) = uVar5;
      if (bVar8) {
        uVar7 = (uint)(param_1 + 0x30U >> 0xc);
        lVar1 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
        do {
          uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
          LOCK();
          bVar8 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
          if (bVar8) {
            *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar7 & 0x3f);
          }
          UNLOCK();
        } while (!bVar8);
      }
      uVar5 = FUN_1809a08f0(lVar4,uRam0000000182d6c3a0);
      bVar8 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x38) = uVar5;
      if (bVar8) {
        uVar7 = (uint)(param_1 + 0x38U >> 0xc);
        lVar4 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
        do {
          uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
          LOCK();
          bVar8 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
          if (bVar8) {
            *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar3 | 1L << (uVar7 & 0x3f);
          }
          UNLOCK();
        } while (!bVar8);
      }
      lVar4 = *(longlong *)(param_1 + 0x20);
      if (lVar4 != 0) {
        pcVar6 = pcRam0000000182ec1138;
        if ((pcRam0000000182ec1138 == (code *)0x0) &&
           (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
           pcVar6 == (code *)0x0)) {
          uVar5 = func_0x0001802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        pcRam0000000182ec1138 = pcVar6;
                    /* WARNING: Could not recover jumptable at 0x0001805eba0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*pcRam0000000182ec1138)(lVar4,0);
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

