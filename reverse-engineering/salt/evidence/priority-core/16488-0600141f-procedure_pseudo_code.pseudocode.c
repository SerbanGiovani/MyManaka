// Ghidra pseudocode; not original source or compilable C.
// ev_2847f4d0d06b00d218c2754af73147926c4573bdf5d93431580aefad152e0128

undefined4
ExposureUnnoticed2_Scripts_Mission_MissionBase__Initialize__0600141f
          (longlong param_1,undefined8 param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  bool bVar8;
  undefined4 uVar9;
  undefined4 auStackX_10 [2];
  
  bVar8 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x28) = param_2;
  if (bVar8) {
    uVar4 = (uint)(param_1 + 0x28U >> 0xc);
    uVar7 = (ulonglong)((uVar4 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
      LOCK();
      bVar8 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) = uVar1 | 1L << (ulonglong)(uVar4 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    uVar9 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetMissionSatisfy__0600155b
                      (*(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x50),0);
    *(undefined4 *)(param_1 + 0x30) = uVar9;
    if (*(longlong *)(param_1 + 0x28) != 0) {
      uVar9 = *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x50);
      if (cRam0000000182eb79bf == '\0') {
        FUN_1802f2810(0x182d5da00);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5d9f8);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5e218);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d58398);
        LOCK();
        UNLOCK();
        cRam0000000182eb79bf = '\x01';
      }
      lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if ((lVar2 != 0) && (lVar2 = *(longlong *)(lVar2 + 0x110), lVar2 != 0)) {
        iVar5 = FUN_180e44350(lVar2,uVar9,
                              *(undefined8 *)
                               (*(longlong *)(*(longlong *)(lRam0000000182d5d9f8 + 0x20) + 0xc0) +
                               0xf8));
        if (iVar5 < 0) {
          lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if ((lVar2 == 0) || (lVar2 = *(longlong *)(lVar2 + 0x110), lVar2 == 0))
          goto code_r0x0001804788af;
          FUN_180e59ff0(lVar2,uVar9,0,2,
                        *(undefined8 *)
                         (*(longlong *)(*(longlong *)(lRam0000000182d5da00 + 0x20) + 0xc0) + 0x100))
          ;
        }
        lVar3 = lRam0000000182d5e218;
        lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if ((lVar2 != 0) && (lVar2 = *(longlong *)(lVar2 + 0x110), lVar2 != 0)) {
          uVar4 = FUN_180e44350(lVar2,uVar9,
                                *(undefined8 *)
                                 (*(longlong *)(*(longlong *)(lRam0000000182d5e218 + 0x20) + 0xc0) +
                                 0xf8));
          if ((int)uVar4 < 0) {
            auStackX_10[0] = uVar9;
            uVar6 = FUN_180003850(*(undefined8 *)(*(longlong *)(lVar3 + 0x20) + 0xc0),0xe);
            uVar6 = il2cpp_value_box(uVar6,auStackX_10);
                    /* WARNING: Subroutine does not return */
            FUN_181640310(uVar6,0);
          }
          lVar2 = *(longlong *)(lVar2 + 0x18);
          if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          if (*(uint *)(lVar2 + 0x18) <= uVar4) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
          return *(undefined4 *)(lVar2 + 0x2c + (longlong)(int)uVar4 * 0x10);
        }
      }
    }
  }
code_r0x0001804788af:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

