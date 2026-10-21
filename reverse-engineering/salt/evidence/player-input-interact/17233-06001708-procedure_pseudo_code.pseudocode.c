// Ghidra pseudocode; not original source or compilable C.
// ev_d89500c2bdadbc6c58898d096eb37b1638d8497a1c53f015105a8cf148bd0d73

ulonglong ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(undefined4 param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  if (DAT_182eb7a90 == '\0') {
    FUN_1802f2810(&DAT_182d5fa38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb7a90 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar4 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x18);
  if (lVar4 != 0) {
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x10);
    lVar4 = *(longlong *)(lVar4 + 0x90);
    if (lVar1 != 0) {
      uVar3 = FUN_180e75f20(lVar1,param_1,DAT_182d5fa38);
      if (lVar4 != 0) {
        lVar4 = FUN_181952d80(lVar4,uVar3,0);
        if (lVar4 != 0) {
          if (*(longlong *)(lVar4 + 200) == 0) {
            FUN_18194cbf0(lVar4,0);
          }
          uVar2 = *(ulonglong *)(lVar4 + 200);
          if (uVar2 != 0) {
            if (*(longlong *)(uVar2 + 0x60) == 0) {
              return uVar2 & 0xffffffffffffff00;
            }
            lVar1 = *(longlong *)(*(longlong *)(uVar2 + 0x60) + 0x60);
            return CONCAT71((int7)((ulonglong)lVar1 >> 8),
                            (*(byte *)((longlong)*(int *)(lVar4 + 0xc0) * 0x44 + 1 + lVar1) & 0x40)
                            != 0);
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

