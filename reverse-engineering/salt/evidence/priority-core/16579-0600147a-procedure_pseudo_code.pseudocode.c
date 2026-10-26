// Ghidra pseudocode; not original source or compilable C.
// ev_44f4a580f90ea5b96b28054575367da2899c550794778105397a30ce68e370c3

bool ExposureUnnoticed2_Scripts_Mission_MissionPee__IsInCondition__0600147a(void)

{
  longlong lVar1;
  longlong lVar2;
  
  if (cRam0000000182eb7930 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7930 = '\x01';
  }
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
      (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 != 0)) &&
     (lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38), lVar1 != 0)) {
    if (*(char *)(lVar1 + 0x11) == '\0') {
      lVar2 = *(longlong *)(lVar2 + 0x30);
      if (((lVar2 == 0) || (lVar2 = *(longlong *)(lVar2 + 0x40), lVar2 == 0)) ||
         (lVar2 = *(longlong *)(lVar2 + 0x60), lVar2 == 0)) goto code_r0x00018047f7fb;
      if (*(char *)(lVar2 + 0x1c) != '\0') {
        if (cRam0000000182eb54aa == '\0') {
          FUN_1802f2810(0x182d5d568);
          LOCK();
          UNLOCK();
          cRam0000000182eb54aa = '\x01';
        }
        lVar2 = **(longlong **)(lRam0000000182d5d568 + 0xb8);
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
        if (lVar2 != 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (*(longlong *)(lVar2 + 0x10) != 0) {
            lVar2 = FUN_180498d30();
            if (lVar2 != 0) {
              return *(char *)(lVar2 + 0x20) != '\0';
            }
            goto code_r0x00018047f7fb;
          }
        }
        return true;
      }
    }
    return false;
  }
code_r0x00018047f7fb:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

