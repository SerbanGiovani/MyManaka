// Ghidra pseudocode; not original source or compilable C.
// ev_7cf5126e038f0315e6d6336e0abc77ce9a570a61981e524308feb7eef8a9bb46

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __c___Awake_b__29_1__06001712(undefined8 param_1,undefined4 param_2)

{
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined4 uStack_18;
  
  if (cRam0000000182eb7a97 == '\0') {
    FUN_1802f2810(&DAT_182d5fa80);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a97 = '\x01';
  }
  uStack_28 = _DAT_182d5fa80;
  uStack_20 = 0xffffffffffffffff;
  uStack_18 = param_2;
  FUN_1816580e0(&uStack_28,0);
  return;
}

