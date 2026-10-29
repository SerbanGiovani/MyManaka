// Ghidra pseudocode; not original source or compilable C.
// ev_9362555ba609a0a9a4d1e83fced4c53f9f406d8fb0c724cbec6545279e469d31

void Native_NullThrowHelper(void)

{
  code *pcVar1;
  
  FUN_1802ccb30();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

