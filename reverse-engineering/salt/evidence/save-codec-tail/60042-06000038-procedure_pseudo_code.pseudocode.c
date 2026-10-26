// Ghidra pseudocode; not original source or compilable C.
// ev_92209ce55960aa1cb31d62b1ca80960a10b2f8b21441c68076ead9df383da114

void System_Security_Cryptography_AesCryptoServiceProvider___ctor__06000038(longlong param_1)

{
  if (cRam0000000182ebbeba == '\0') {
    FUN_1802f2810(0x182d6ab48);
    LOCK();
    UNLOCK();
    cRam0000000182ebbeba = '\x01';
  }
  if (*(int *)(lRam0000000182d6ab48 + 0xe0) == 0) {
    FUN_18035c820();
  }
  System_Security_Cryptography_Aes___ctor__060015b4(param_1,0);
  *(undefined4 *)(param_1 + 0x14) = 8;
  return;
}

