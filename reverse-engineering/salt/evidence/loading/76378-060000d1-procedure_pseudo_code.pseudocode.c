// Ghidra pseudocode; not original source or compilable C.
// ev_d246c45be46815fa54a88c19e538612d69211c07cba79b60a797cdd50e8a5bdc

void IKA9nt_Encrypter_EncrypterStarter__Init__060000d1(void)

{
  undefined8 uVar1;
  longlong lVar2;
  code *pcVar3;
  
  if (cRam0000000182ebaae1 == '\0') {
    FUN_1802f2810(0x182d5f428);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64968);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64960);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64970);
    LOCK();
    UNLOCK();
    cRam0000000182ebaae1 = '\x01';
  }
  uVar1 = FUN_1809fce30(uRam0000000182d64970,uRam0000000182d64968);
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar2 = FUN_1809f0e30(uVar1,uRam0000000182d5f428);
  uVar1 = uRam0000000182d64960;
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (cRam0000000182ec129d == '\0') {
    FUN_1802f2810(0x182d53aa8,uRam0000000182d64960,0);
    LOCK();
    UNLOCK();
    cRam0000000182ec129d = '\x01';
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar3 = pcRam0000000182ec1328;
  if ((pcRam0000000182ec1328 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Object::SetName(UnityEngine.Object,System.String)"
                                    ), pcVar3 == (code *)0x0)) {
    uVar1 = func_0x0001802ced60("UnityEngine.Object::SetName(UnityEngine.Object,System.String)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar1,0);
  }
  pcRam0000000182ec1328 = pcVar3;
                    /* WARNING: Could not recover jumptable at 0x000181f4351a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000182ec1328)(lVar2,uVar1);
  return;
}

