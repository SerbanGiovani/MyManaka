// Ghidra pseudocode; not original source or compilable C.
// ev_48c74ed9001333b509d9d7bddf926fe58772f0f44ff2175fd17dd9ccec1ca7b6

undefined8 IKA9nt_Encrypter_EncrypterCore__get_property_KeyData__0600006b(void)

{
  if (cRam0000000182ebaa92 == '\0') {
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa92 = '\x01';
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5bfb8);
  }
  return *(undefined8 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18);
}

