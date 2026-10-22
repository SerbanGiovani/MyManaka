// Ghidra pseudocode; not original source or compilable C.
// ev_cebf4ee8044629db8b35818399a74ca30433fab064ff67396483574295e31db0

ulonglong __c__DisplayClass79_0___OpenRingMenu_b__0__06001abc(longlong param_1,longlong param_2)

{
  ulonglong *puVar1;
  longlong lVar2;
  longlong *plVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  bool bVar8;
  
  if (cRam0000000182eb7cba == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb7cba = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x10) != 0) &&
     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar2 != 0)) {
    if (*(int *)(lVar2 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    lVar2 = *(longlong *)(lVar2 + 0x20);
    if (lVar2 != 0) {
      if (cRam0000000182eb7cc5 == '\0') {
        FUN_1802f2810(&DAT_182d61798);
        LOCK();
        UNLOCK();
        cRam0000000182eb7cc5 = '\x01';
      }
      plVar3 = *(longlong **)(lVar2 + 0x20);
      uVar5 = DAT_182d61798;
      if (param_2 != 0) {
        uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                          (*(undefined8 *)(param_2 + 0x20),0);
      }
      if (plVar3 != (longlong *)0x0) {
        uVar6 = (**(code **)(*plVar3 + 0x558))(plVar3,uVar5,*(undefined8 *)(*plVar3 + 0x560));
        lVar2 = *(longlong *)(param_1 + 0x10);
        if (lVar2 != 0) {
          bVar8 = DAT_182eb5d50 != 0;
          *(longlong *)(lVar2 + 0x88) = param_2;
          if (bVar8) {
            uVar7 = (uint)(lVar2 + 0x88U >> 0xc);
            puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
            do {
              uVar4 = *puVar1;
              LOCK();
              uVar6 = *puVar1;
              bVar8 = uVar4 == uVar6;
              if (bVar8) {
                *puVar1 = uVar4 | 1L << (uVar7 & 0x3f);
                uVar6 = uVar4;
              }
              UNLOCK();
            } while (!bVar8);
          }
          if (param_2 != 0) {
            lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar2 == 0) goto code_r0x000180504473;
            uVar6 = (ulonglong)*(uint *)(param_2 + 0x30);
            *(uint *)(lVar2 + 0x50) = *(uint *)(param_2 + 0x30);
          }
          return uVar6;
        }
      }
    }
  }
code_r0x000180504473:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

