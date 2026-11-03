// Ghidra pseudocode; not original source or compilable C.
// ev_62f856cac0795c80ffab586493d223d058f9c9319985301712eb94ba9e69e879

void ExposureUnnoticed2_ObjectUI_BarberMenu_ClosetMenuView__OnClickItem__06001c7f
               (undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  bool bVar4;
  
  if (cRam0000000182eb7dc0 == '\0') {
    FUN_1802f2810(0x182d5df80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    cRam0000000182eb7dc0 = '\x01';
  }
  if ((((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
       (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 == 0)) ||
      (lVar1 = *(longlong *)(lVar1 + 0x30), lVar1 == 0)) ||
     ((lVar1 = *(longlong *)(lVar1 + 0x40), lVar1 == 0 ||
      (lVar1 = *(longlong *)(lVar1 + 0x60), lVar1 == 0)))) {
code_r0x00018052be8d:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  lVar1 = *(longlong *)(lVar1 + 0x10);
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
  if (param_2 != 0 || lVar1 != 0) {
    if (param_2 == 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (lVar1 == 0) goto code_r0x00018052be8d;
      bVar4 = *(longlong *)(lVar1 + 0x10) == 0;
    }
    else if (lVar1 == 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      bVar4 = *(longlong *)(param_2 + 0x10) == 0;
    }
    else {
      bVar4 = lVar1 == param_2;
    }
    if (!bVar4) {
      lVar1 = **(longlong **)(DAT_182d5aa70 + 0xb8);
      if (lVar1 != 0) {
        if (cRam0000000182eb78ef == '\0') {
          FUN_1802f2810(&DAT_182d58078);
          LOCK();
          UNLOCK();
          cRam0000000182eb78ef = '\x01';
        }
        lVar1 = *(longlong *)(lVar1 + 0x20);
        if ((**(longlong **)(DAT_182d58078 + 0xb8) != 0) && (lVar1 != 0)) {
          FUN_181ef4680(lVar1,*(undefined8 *)(**(longlong **)(DAT_182d58078 + 0xb8) + 200),
                        0x3f800000,0);
          if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
            ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__ChangeClothes__06000d9d
                      (**(longlong **)(DAT_182d58230 + 0xb8),param_2,0);
            ExposureUnnoticed2_ObjectUI_BarberMenu_ClosetMenuView__RefreshClothesView__06001c7e
                      (param_1,0);
            lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if ((lVar1 != 0) && (lVar1 = *(longlong *)(lVar1 + 0x18), param_2 != 0)) {
              uVar3 = 0;
              uVar2 = uVar3;
              if ((*(int *)(param_2 + 0x30) != 0) &&
                 (uVar2 = 0xffffffff, *(int *)(param_2 + 0x30) == 1)) {
                uVar2 = 1;
              }
              if ((lVar1 != 0) &&
                 (lVar1 = FUN_180e75f20(lVar1,uVar2,uRam0000000182d5df80), lVar1 != 0)) {
                if (*(char *)(lVar1 + 0x10) == '\0') {
                  return;
                }
                if (*(int *)(lVar1 + 0x30) != 0) {
                  return;
                }
                if (**(longlong **)(DAT_182d53c48 + 0xb8) != 0) {
                  lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x20);
                  if ((*(int *)(param_2 + 0x30) != 0) &&
                     (uVar3 = 0xffffffff, *(int *)(param_2 + 0x30) == 1)) {
                    uVar3 = 1;
                  }
                  if (lVar1 != 0) {
                    ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__Collect__06001507
                              (lVar1,uVar3,0);
                    return;
                  }
                }
              }
            }
          }
        }
      }
      goto code_r0x00018052be8d;
    }
  }
  return;
}

