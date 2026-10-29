// Ghidra pseudocode; not original source or compilable C.
// ev_7de8068eeb6663b651f08320ce0c9babfc2b98b70f3310aa4d68f28ac2b4d264

void ExposureUnnoticed2_ObjectUI_ClosetMenu_CustomizeMenu_CustomizeMenuView__OnChangeHairType__06001cc6
               (longlong param_1)

{
  ulonglong *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  uint uVar10;
  bool bVar11;
  ulonglong in_stack_ffffffffffffffb8;
  
  if (cRam0000000182eb7dea == '\0') {
    FUN_1802f2810(0x182d61940);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62c08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65780);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65778);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65770);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65768);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65758);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65750);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb7dea = '\x01';
  }
  lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
  if (((lVar5 != 0) && (*(longlong *)(param_1 + 0x300) != 0)) &&
     (lVar5 = *(longlong *)(lVar5 + 0x118), lVar5 != 0)) {
    uVar8 = FUN_180e75f20(lVar5,*(undefined4 *)(*(longlong *)(param_1 + 0x300) + 0x18),DAT_182d58190
                         );
    bVar11 = DAT_182eb5d50 != 0;
    *(undefined8 *)(param_1 + 0x308) = uVar8;
    if (bVar11) {
      uVar10 = (uint)(param_1 + 0x308U >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8);
      do {
        uVar6 = *puVar1;
        LOCK();
        uVar9 = *puVar1;
        if (uVar6 == uVar9) {
          *puVar1 = uVar6 | 1L << (uVar10 & 0x3f);
        }
        UNLOCK();
      } while (uVar6 != uVar9);
    }
    if (((*(longlong *)(param_1 + 0x300) != 0) &&
        (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x300) + 0x38), lVar5 != 0)) &&
       (*(longlong *)(param_1 + 0x2b8) != 0)) {
      ExposureUnnoticed2_ObjectUI_OptionMenu_CustomizeBarItemView__SetMax__06001baa
                (*(longlong *)(param_1 + 0x2b8),*(int *)(lVar5 + 0x18) + -1,0);
      lVar5 = *(longlong *)(param_1 + 0x2b8);
      if (*(longlong *)(param_1 + 0x308) != 0) {
        uVar2 = *(undefined4 *)(*(longlong *)(param_1 + 0x308) + 0x14);
        uVar8 = FUN_1802c43a0(uRam0000000182d61940);
        FUN_180006cd0(uVar8,param_1,uRam0000000182d65780);
        if (lVar5 != 0) {
          *(undefined1 *)(lVar5 + 0x5b) = 1;
          in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffffffffff00;
          ExposureUnnoticed2_ObjectUI_OptionMenu_CustomizeBarItemView__Initialize__06001ba8
                    (lVar5,uVar2,uVar8,0,in_stack_ffffffffffffffb8,0);
          lVar5 = *(longlong *)(param_1 + 0x2c0);
          if (*(longlong *)(param_1 + 0x308) != 0) {
            uVar2 = *(undefined4 *)(*(longlong *)(param_1 + 0x308) + 0x18);
            uVar8 = FUN_1802c43a0(uRam0000000182d61940);
            FUN_180006cd0(uVar8,param_1,uRam0000000182d65778);
            if (lVar5 != 0) {
              in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffffffffff00;
              *(undefined1 *)(lVar5 + 0x5b) = 1;
              ExposureUnnoticed2_ObjectUI_OptionMenu_CustomizeBarItemView__Initialize__06001ba8
                        (lVar5,uVar2,uVar8,0,in_stack_ffffffffffffffb8,0);
              lVar5 = *(longlong *)(param_1 + 0x2c8);
              if (*(longlong *)(param_1 + 0x308) != 0) {
                uVar2 = *(undefined4 *)(*(longlong *)(param_1 + 0x308) + 0x1c);
                uVar8 = FUN_1802c43a0(uRam0000000182d61940);
                FUN_180006cd0(uVar8,param_1,uRam0000000182d65770);
                if (lVar5 != 0) {
                  in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffffffffff00;
                  *(undefined1 *)(lVar5 + 0x5b) = 1;
                  ExposureUnnoticed2_ObjectUI_OptionMenu_CustomizeBarItemView__Initialize__06001ba8
                            (lVar5,uVar2,uVar8,0,in_stack_ffffffffffffffb8,0);
                  lVar5 = *(longlong *)(param_1 + 0x2d0);
                  if (*(longlong *)(param_1 + 0x308) != 0) {
                    uVar2 = *(undefined4 *)(*(longlong *)(param_1 + 0x308) + 0x20);
                    uVar8 = FUN_1802c43a0(uRam0000000182d61940);
                    FUN_180006cd0(uVar8,param_1,uRam0000000182d65768);
                    if (lVar5 != 0) {
                      *(undefined1 *)(lVar5 + 0x5b) = 1;
                      ExposureUnnoticed2_ObjectUI_OptionMenu_CustomizeBarItemView__Initialize__06001ba8
                                (lVar5,uVar2,uVar8,0,in_stack_ffffffffffffffb8 & 0xffffffffffffff00,
                                 0);
                      lVar5 = *(longlong *)(param_1 + 0x308);
                      lVar7 = *(longlong *)(param_1 + 0x2d8);
                      if (lVar5 != 0) {
                        uVar2 = *(undefined4 *)(lVar5 + 0x18);
                        uVar3 = *(undefined4 *)(lVar5 + 0x1c);
                        uVar4 = *(undefined4 *)(lVar5 + 0x20);
                        uVar9 = FUN_1802c43a0(uRam0000000182d62c08);
                        FUN_180007430(uVar9,param_1,uRam0000000182d65758);
                        if (lVar7 != 0) {
                          ExposureUnnoticed2_ObjectUI_OptionMenu_CustomizeColorItemView__Initialize__06001bb6
                                    (lVar7,uVar2,uVar3,uVar4,uVar9,0,0,0,0);
                          lVar5 = *(longlong *)(param_1 + 0x2e0);
                          if (*(longlong *)(param_1 + 0x308) != 0) {
                            uVar2 = *(undefined4 *)(*(longlong *)(param_1 + 0x308) + 0x24);
                            uVar8 = FUN_1802c43a0(uRam0000000182d61940);
                            FUN_180006cd0(uVar8,param_1,uRam0000000182d65750);
                            if (lVar5 != 0) {
                              *(undefined1 *)(lVar5 + 0x5b) = 1;
                              ExposureUnnoticed2_ObjectUI_OptionMenu_CustomizeBarItemView__Initialize__06001ba8
                                        (lVar5,uVar2,uVar8,0,uVar9 & 0xffffffffffffff00,0);
                              return;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

