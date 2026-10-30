// Ghidra pseudocode; not original source or compilable C.
// ev_0bc692e19f71654f442062f9c8348bdc29849bc36d979f21dd9d0d9e58c87adc

/* WARNING: Removing unreachable block (ram,0x0001804b201c) */

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationReceiver__JustEffectItem__06000c53
               (longlong param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  char cVar5;
  byte bVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong lVar9;
  
  if (cRam0000000182eb837d == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb837d = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x40) == 0) ||
     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar2 == 0))
  goto code_r0x00018062ad95;
  iVar1 = *(int *)(lVar2 + 0x228);
  switch(iVar1) {
  case 2:
    lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar2 == 0) goto code_r0x00018062ad95;
    *(undefined1 *)(lVar2 + 0x1dd) = 1;
    break;
  case 3:
    if ((*(longlong *)(param_1 + 0x40) != 0) &&
       (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x1d8), lVar2 != 0)) {
      if (cRam0000000182eb7670 == '\0') {
        FUN_1802f2810(&DAT_182d58398,CONCAT71((uint7)(uint3)((uint)iVar1 >> 8),1),0);
        LOCK();
        UNLOCK();
        cRam0000000182eb7670 = '\x01';
      }
      lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar3 != 0) {
        *(undefined1 *)(lVar3 + 0x1dc) = 1;
        lVar2 = *(longlong *)(lVar2 + 0x18);
        if (lVar2 != 0) {
          *(undefined4 *)(lVar2 + 0x1c) = 0x3f800000;
          return;
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    goto code_r0x00018062ad95;
  case 4:
    if ((*(longlong *)(param_1 + 0x40) == 0) ||
       (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x1d8), lVar2 == 0))
    goto code_r0x00018062ad95;
    ExposureUnnoticed2_Object3D_Player_Scripts_Other_FutanariController__ChangeActive__06000e89
              (lVar2,0,0);
    cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEquipAdultGoods__0600153c(8,0);
    if (cVar5 == '\0') {
      return;
    }
    if (*(longlong *)(param_1 + 0x40) == 0) goto code_r0x00018062ad95;
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
    uVar7 = ExposureUnnoticed2_Master_AdultGoods_MAdultGoods__Get__06001380(8,0);
    if (lVar2 == 0) goto code_r0x00018062ad95;
    *(undefined8 *)(lVar2 + 0x38) = uVar7;
    FUN_18031d480(lVar2 + 0x38);
    if ((*(longlong *)(param_1 + 0x40) == 0) ||
       (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x168), lVar2 == 0))
    goto code_r0x00018062ad95;
    if (cRam0000000182eb8381 == '\0') {
      FUN_1802f2810(&DAT_182d583a0);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d58080);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      cRam0000000182eb8381 = '\x01';
    }
    if ((*(longlong *)(lVar2 + 0x40) == 0) ||
       (lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x40) + 0x60), lVar3 == 0))
    goto code_r0x00018062b4e0;
    lVar3 = *(longlong *)(lVar3 + 0x38);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec12f4 == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec12f4 = '\x01';
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
    if (lVar3 == 0) {
      lVar9 = *(longlong *)(lVar2 + 0x40);
    }
    else {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar9 = *(longlong *)(lVar2 + 0x40);
      if (*(longlong *)(lVar3 + 0x10) != 0) {
        if (((lVar9 != 0) && (*(longlong *)(lVar9 + 0x60) != 0)) &&
           (lVar3 = *(longlong *)(*(longlong *)(lVar9 + 0x60) + 0x38), lVar3 != 0)) {
          bVar6 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEquipAdultGoods__0600153c
                            (*(undefined4 *)(lVar3 + 0x18),0);
          lVar2 = *(longlong *)(lVar2 + 0x40);
          if (((lVar2 == 0) || (*(longlong *)(lVar2 + 0x60) == 0)) ||
             ((lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x60) + 0x38), lVar3 == 0 ||
              (*(longlong *)(lVar2 + 0x100) == 0)))) goto code_r0x00018062b4e0;
          ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAdultGoodsController__ChangeAdultGoods__06000c40
                    (*(longlong *)(lVar2 + 0x100),*(undefined4 *)(lVar3 + 0x18),bVar6 ^ 1,0);
          goto code_r0x00018062b48a;
        }
        goto code_r0x00018062b4e0;
      }
    }
    if ((lVar9 != 0) && (*(longlong *)(lVar9 + 0x60) != 0)) {
      lVar3 = *(longlong *)(*(longlong *)(lVar9 + 0x60) + 0x40);
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182ec12f4 == '\0') {
        FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        DAT_182ec12f4 = '\x01';
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
      if (lVar3 != 0) {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if ((*(longlong *)(lVar3 + 0x10) != 0) &&
           (((lVar2 = *(longlong *)(lVar2 + 0x40), lVar2 == 0 ||
             (lVar3 = *(longlong *)(lVar2 + 0x118), *(longlong *)(lVar2 + 0x60) == 0)) ||
            (ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEquipCostume__0600153e
                       (*(undefined8 *)(*(longlong *)(lVar2 + 0x60) + 0x40),0), lVar3 == 0))))
        goto code_r0x00018062b4e0;
      }
code_r0x00018062b48a:
      if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d58080);
      }
      plVar4 = *(longlong **)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x88);
      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182eb7a98 == '\0') {
        FUN_1802f2810(&DAT_182d5f9b8,0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d583a0);
        LOCK();
        UNLOCK();
        DAT_182eb7a98 = '\x01';
      }
      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d583a0);
      }
      lVar2 = **(longlong **)(DAT_182d583a0 + 0xb8);
      if (((plVar4 != (longlong *)0x0) && (uVar7 = FUN_1802c5ac0(*plVar4 + 0x20), lVar2 != 0)) &&
         (cVar5 = FUN_180ebb4c0(lVar2,uVar7,&stack0x00000008,DAT_182d5f9b8), cVar5 == '\0')) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
code_r0x00018062b4e0:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  case 5:
code_r0x00018062ad9b:
    uVar7 = thunk_FUN_1802f2810(&DAT_182d54bf8);
    uVar7 = thunk_FUN_1802c43a0(uVar7);
    FUN_1815c6ac0(uVar7,0);
    uVar8 = thunk_FUN_1802f2810(0x182d6f468);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar7,uVar8);
  case 6:
    lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar2 == 0) goto code_r0x00018062ad95;
    *(undefined1 *)(lVar2 + 0x1dd) = 0;
    break;
  case 7:
    lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar2 != 0) {
      *(undefined1 *)(lVar2 + 0x1dd) = 1;
      lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar2 != 0) {
        *(undefined1 *)(lVar2 + 0x1de) = 1;
        return;
      }
    }
    goto code_r0x00018062ad95;
  case -1:
  case 0:
  case 1:
    goto code_r0x00018062ac09;
  default:
    if ((((((iVar1 != 10000) && (iVar1 != 0x2711)) && (iVar1 != 0x2712)) &&
         ((iVar1 != 99999 && (iVar1 != 100000)))) && (iVar1 != 0x186a1)) && (iVar1 != 0x186a2))
    goto code_r0x00018062ad9b;
    goto code_r0x00018062ac09;
  }
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar2 == 0) {
code_r0x00018062ad95:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  *(undefined1 *)(lVar2 + 0x1de) = 0;
code_r0x00018062ac09:
  return;
}

