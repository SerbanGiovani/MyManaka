// Ghidra pseudocode; not original source or compilable C.
// ev_1808cde9a36346d8f614a78aeaec1195b76b636e907fe2a5fa5dfe36269dda64

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionHandcuffsMapExpose__IsRpPerSecCondition__06001459
                    (void)

{
  longlong lVar1;
  ulonglong uVar2;
  
  if (cRam0000000182eb791b == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb791b = '\x01';
  }
  if ((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
       (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 != 0)) &&
      (uVar2 = *(ulonglong *)(lVar1 + 0x30), uVar2 != 0)) &&
     (((*(longlong *)(uVar2 + 0x40) != 0 &&
       (lVar1 = *(longlong *)(*(longlong *)(uVar2 + 0x40) + 0x60), lVar1 != 0)) &&
      (lVar1 = *(longlong *)(lVar1 + 0x48), lVar1 != 0)))) {
    if (*(int *)(lVar1 + 0x18) != 0x2726) {
      lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(uVar2 + 0x40) + 0x60) + 0x48);
      return CONCAT71((int7)((ulonglong)lVar1 >> 8),*(int *)(lVar1 + 0x18) != 0x2723);
    }
    return uVar2 & 0xffffffffffffff00;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

