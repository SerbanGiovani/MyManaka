// Ghidra pseudocode; not original source or compilable C.
// ev_8ef4e682a9d759b0ecf3978a6150effc7e8f34a11cf6529c53e93fe8cd7634ac

void IKA9nt_Encrypter_EncrypterCore__GetBasePath__060000ae(void)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if (cRam0000000182ebaace == '\0') {
    FUN_1802f2810(0x182d53a48);
    LOCK();
    UNLOCK();
    cRam0000000182ebaace = '\x01';
  }
  if (*(int *)(lRam0000000182d53a48 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar1 = pcRam0000000182ebf9b8;
  if ((pcRam0000000182ebf9b8 == (code *)0x0) &&
     (pcVar1 = (code *)FUN_1802cf0c0("UnityEngine.Application::get_streamingAssetsPath()"),
     pcVar1 == (code *)0x0)) {
    uVar2 = func_0x0001802ced60("UnityEngine.Application::get_streamingAssetsPath()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  pcRam0000000182ebf9b8 = pcVar1;
                    /* WARNING: Could not recover jumptable at 0x00018143e8a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000182ebf9b8)();
  return;
}

