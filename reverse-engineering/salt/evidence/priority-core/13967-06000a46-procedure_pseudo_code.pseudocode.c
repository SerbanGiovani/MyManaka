// Ghidra pseudocode; not original source or compilable C.
// ev_44380dad629d0de5d993b1ba859ec133caa30691dfc83f82378972b1172b50c2

void ExposureUnnoticed2_Object3D_ScenePlops_WasherMachine_WasherMachineController___cctor__06000a46
               (void)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if (cRam0000000182eb824a == '\0') {
    FUN_1802f2810(&DAT_182d6c188);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c158);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c150);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c148);
    LOCK();
    UNLOCK();
    cRam0000000182eb824a = '\x01';
  }
  uVar3 = uRam0000000182d6c150;
  pcVar2 = pcRam0000000182ebf318;
  if ((pcRam0000000182ebf318 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Animator::StringToHash(System.String)"),
     pcVar2 == (code *)0x0)) {
    uVar3 = FUN_1802ced60("UnityEngine.Animator::StringToHash(System.String)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  pcRam0000000182ebf318 = pcVar2;
  uVar1 = (*pcRam0000000182ebf318)(uVar3);
  **(undefined4 **)(DAT_182d6c188 + 0xb8) = uVar1;
  uVar3 = uRam0000000182d6c148;
  pcVar2 = pcRam0000000182ebf318;
  if ((pcRam0000000182ebf318 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Animator::StringToHash(System.String)"),
     pcVar2 == (code *)0x0)) {
    uVar3 = FUN_1802ced60("UnityEngine.Animator::StringToHash(System.String)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  pcRam0000000182ebf318 = pcVar2;
  uVar1 = (*pcRam0000000182ebf318)(uVar3);
  *(undefined4 *)(*(longlong *)(DAT_182d6c188 + 0xb8) + 4) = uVar1;
  uVar3 = uRam0000000182d6c158;
  pcVar2 = pcRam0000000182ebf318;
  if ((pcRam0000000182ebf318 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Animator::StringToHash(System.String)"),
     pcVar2 == (code *)0x0)) {
    uVar3 = FUN_1802ced60("UnityEngine.Animator::StringToHash(System.String)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  pcRam0000000182ebf318 = pcVar2;
  uVar1 = (*pcRam0000000182ebf318)(uVar3);
  *(undefined4 *)(*(longlong *)(DAT_182d6c188 + 0xb8) + 8) = uVar1;
  return;
}

