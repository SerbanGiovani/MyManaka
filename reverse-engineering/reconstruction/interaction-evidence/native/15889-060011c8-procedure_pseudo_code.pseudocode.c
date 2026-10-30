// Ghidra pseudocode; not original source or compilable C.
// ev_e1a72253ac97297b1ea185bbb06e35175ef44efb9156ca549960773a0a5ad2f1

void ExposureUnnoticed2_Object3D_DropedCoat_DroppedItemController__Initialize__060011c8
               (longlong param_1,undefined4 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  uint uVar8;
  undefined8 uVar9;
  bool bVar10;
  
  if (cRam0000000182eb7805 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ca38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ca28);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ca18);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ca10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ca08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c9f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c9e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c9e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c9d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c9c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c9c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c9b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c9b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c9a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52e20);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c9a0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7805 = '\x01';
  }
  lVar5 = FUN_1802c43a0(uRam0000000182d5c9e0);
  if (lVar5 == 0) {
DAT_180459e5e:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  *(undefined4 *)(lVar5 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x28) = param_2;
  uVar6 = FUN_180735980(param_1,uRam0000000182d5ca38);
  bVar10 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x20) = uVar6;
  if (bVar10) {
    uVar8 = (uint)(param_1 + 0x20U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  if (*(longlong *)(param_1 + 0x20) == 0) goto DAT_180459e5e;
  *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 100) = *(undefined4 *)(lVar5 + 0x10);
  uVar6 = DAT_182d52e20;
  switch(*(undefined4 *)(lVar5 + 0x10)) {
  case 0:
    uVar6 = uRam0000000182d5c9c0;
    break;
  case 1:
    uVar6 = uRam0000000182d5c9a0;
    break;
  case 3:
    uVar6 = uRam0000000182d5c9a8;
    break;
  case 4:
    uVar6 = uRam0000000182d5c9c8;
    break;
  case 5:
    uVar6 = uRam0000000182d5c9b0;
    break;
  case 6:
    uVar6 = uRam0000000182d5c9b8;
    break;
  case 0xffffffff:
  case 2:
    uVar6 = 0;
  }
  lVar4 = *(longlong *)(param_1 + 0x20);
  if (lVar4 == 0) goto DAT_180459e5e;
  if (*(int *)(lVar4 + 0x20) == 3) {
    uVar6 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(uVar6,0,uRam0000000182d5ca18,0);
    ExposureUnnoticed2_Object3D_InteractArea_InteractAreaController__Initialize__06001180
              (lVar4,uVar6,0,0);
    lVar5 = **(longlong **)(lRam0000000182d5ca28 + 0xb8);
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
    if (lVar5 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar5 + 0x10) != 0) {
        return;
      }
    }
    if (cRam0000000182eb54a4 == '\0') {
      FUN_1802f2810(0x182d5bcc0);
      LOCK();
      UNLOCK();
      cRam0000000182eb54a4 = '\x01';
    }
    lVar5 = **(longlong **)(lRam0000000182d5bcc0 + 0xb8);
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
    if (lVar5 == 0) {
      return;
    }
    if (*(int *)(DAT_182d53aa8 + 0xe0) != 0) {
      return;
    }
    FUN_18035c820();
    return;
  }
  if (*(int *)(lVar4 + 0x20) == 4) {
    lVar7 = FUN_1802c43a0(DAT_182d58368);
    uVar9 = uRam0000000182d5c9f8;
  }
  else {
    if (*(int *)(lVar4 + 0x20) != 0xc) {
      if (*(int *)(lVar4 + 0x20) == 0xf) {
        if (*(int *)(lRam0000000182d5c9d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar7 = *(longlong *)(*(longlong *)(lRam0000000182d5c9d8 + 0xb8) + 8);
        if (lVar7 == 0) {
          if (*(int *)(lRam0000000182d5c9d8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          uVar9 = **(undefined8 **)(lRam0000000182d5c9d8 + 0xb8);
          lVar7 = FUN_1802c43a0(DAT_182d58368);
          FUN_1814df680(lVar7,uVar9,uRam0000000182d5ca10,0);
          *(longlong *)(*(longlong *)(lRam0000000182d5c9d8 + 0xb8) + 8) = lVar7;
          FUN_18031d480(*(longlong *)(lRam0000000182d5c9d8 + 0xb8) + 8);
        }
      }
      else {
        if (*(int *)(lVar4 + 0x20) != 0x10) {
          return;
        }
        if (*(int *)(lRam0000000182d5c9d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar7 = *(longlong *)(*(longlong *)(lRam0000000182d5c9d8 + 0xb8) + 0x10);
        if (lVar7 == 0) {
          if (*(int *)(lRam0000000182d5c9d8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          uVar9 = **(undefined8 **)(lRam0000000182d5c9d8 + 0xb8);
          lVar7 = FUN_1802c43a0(DAT_182d58368);
          FUN_1814df680(lVar7,uVar9,uRam0000000182d5ca08,0);
          *(longlong *)(*(longlong *)(lRam0000000182d5c9d8 + 0xb8) + 0x10) = lVar7;
          FUN_18031d480(*(longlong *)(lRam0000000182d5c9d8 + 0xb8) + 0x10);
        }
      }
      goto code_r0x000180459c80;
    }
    lVar7 = FUN_1802c43a0(DAT_182d58368);
    uVar9 = uRam0000000182d5c9e8;
  }
  FUN_1814df680(lVar7,lVar5,uVar9,0);
code_r0x000180459c80:
  ExposureUnnoticed2_Object3D_InteractArea_InteractAreaController__Initialize__06001180
            (lVar4,lVar7,uVar6,0);
  return;
}

