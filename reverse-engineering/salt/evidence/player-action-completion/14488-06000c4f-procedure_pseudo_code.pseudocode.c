// Ghidra pseudocode; not original source or compilable C.
// ev_b1ac7ae30f652928856c3b4cc797b262f8ec3174e3ed87d51f2707f829d49102

/* WARNING: Removing unreachable block (ram,0x000180627d2f) */
/* WARNING: Removing unreachable block (ram,0x000180627d3c) */
/* WARNING: Removing unreachable block (ram,0x000180627d49) */
/* WARNING: Removing unreachable block (ram,0x000180627d85) */
/* WARNING: Removing unreachable block (ram,0x000180627d92) */
/* WARNING: Removing unreachable block (ram,0x000180627d9f) */
/* WARNING: Removing unreachable block (ram,0x000180627db6) */
/* WARNING: Removing unreachable block (ram,0x000180627dc3) */
/* WARNING: Removing unreachable block (ram,0x000180627d7d) */
/* WARNING: Removing unreachable block (ram,0x000180627c52) */
/* WARNING: Removing unreachable block (ram,0x000180627c5f) */
/* WARNING: Removing unreachable block (ram,0x000180627c6c) */
/* WARNING: Removing unreachable block (ram,0x000180627c79) */
/* WARNING: Removing unreachable block (ram,0x000180627c89) */
/* WARNING: Removing unreachable block (ram,0x000180627ca3) */
/* WARNING: Removing unreachable block (ram,0x000180627cb0) */
/* WARNING: Removing unreachable block (ram,0x000180627cbd) */
/* WARNING: Removing unreachable block (ram,0x000180627cd4) */
/* WARNING: Removing unreachable block (ram,0x000180627ce4) */
/* WARNING: Removing unreachable block (ram,0x000180627b7f) */
/* WARNING: Removing unreachable block (ram,0x000180627b8d) */
/* WARNING: Removing unreachable block (ram,0x000180627b96) */
/* WARNING: Removing unreachable block (ram,0x000180627b9f) */
/* WARNING: Removing unreachable block (ram,0x000180627cf6) */
/* WARNING: Removing unreachable block (ram,0x000180627d03) */
/* WARNING: Removing unreachable block (ram,0x000180627d10) */
/* WARNING: Removing unreachable block (ram,0x000180627d20) */
/* WARNING: Removing unreachable block (ram,0x000180627ba8) */
/* WARNING: Removing unreachable block (ram,0x000180627bb1) */
/* WARNING: Removing unreachable block (ram,0x000180627bbc) */
/* WARNING: Removing unreachable block (ram,0x000180627c23) */
/* WARNING: Removing unreachable block (ram,0x000180627c2f) */
/* WARNING: Removing unreachable block (ram,0x000180627c3d) */
/* WARNING: Removing unreachable block (ram,0x000180627ef6) */

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationReceiver__OnAnimEndPick__06000c4f
               (longlong param_1)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  bool bVar8;
  undefined8 uStack_18;
  undefined4 uStack_10;
  
  if (cRam0000000182eb8379 == '\0') {
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb8379 = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x40) == 0) ||
     (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar4 == 0))
  goto code_r0x00018062a118;
  iVar1 = *(int *)(lVar4 + 0x210);
  if (iVar1 == 0) {
    lVar4 = *(longlong *)(param_1 + 0x30);
    if (lVar4 == 0) goto code_r0x00018062a118;
    if (cRam0000000182eb7976 == '\0') {
      FUN_1802f2810(0x182d5df40);
      LOCK();
      UNLOCK();
      FUN_1802f2810(0x182d5df80);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d58398);
      LOCK();
      UNLOCK();
      cRam0000000182eb7976 = '\x01';
    }
    ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__Hide__06001504(lVar4,2,0);
    if (*(int *)(lRam0000000182d5df40 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d5df40);
    }
    uStack_18 = **(undefined8 **)(lRam0000000182d5df40 + 0xb8);
    uStack_10 = *(undefined4 *)(*(undefined8 **)(lRam0000000182d5df40 + 0xb8) + 1);
    ExposureUnnoticed2_Scripts_InGame_FashionShopManager__SaveDropBasket__06001610(&uStack_18,0);
    if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x00018062a118;
    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__SetHadBasket__06000d8e
              (**(longlong **)(DAT_182d58230 + 0xb8),1,0);
  }
  else if (iVar1 == 1) {
    lVar4 = *(longlong *)(param_1 + 0x40);
    if (((lVar4 == 0) || (*(longlong *)(lVar4 + 0x60) == 0)) || (*(longlong *)(lVar4 + 0x98) == 0))
    goto code_r0x00018062a118;
    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerHoldInHand__Hold__06000ddb
              (*(longlong *)(lVar4 + 0x98),*(undefined4 *)(*(longlong *)(lVar4 + 0x60) + 0x21c),0,0)
    ;
  }
  if ((*(longlong *)(param_1 + 0x40) == 0) ||
     (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x68), lVar4 == 0)) {
code_r0x00018062a118:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (cRam0000000182eb836f == '\0') {
    FUN_1802f2810(0x182d5ab80);
    LOCK();
    UNLOCK();
    cRam0000000182eb836f = '\x01';
  }
  if ((*(longlong *)(lVar4 + 0x28) != 0) &&
     (lVar2 = *(longlong *)(*(longlong *)(lVar4 + 0x28) + 0x48), lVar2 != 0)) {
    iVar1 = *(int *)(lVar2 + 0x18);
    if ((0x272d < iVar1) && (iVar1 < 0x2773)) {
      if (cRam0000000182eb54b1 == '\0') {
        FUN_1802f2810(0x182d625a8);
        LOCK();
        UNLOCK();
        cRam0000000182eb54b1 = '\x01';
      }
      if (**(longlong **)(lRam0000000182d625a8 + 0xb8) == 0) goto code_r0x000180627f4f;
      ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__SetOverride__06001a95
                (**(longlong **)(lRam0000000182d625a8 + 0xb8),0,0);
    }
    if (*(char *)(lVar4 + 0x38) != '\0') {
      return;
    }
    if ((*(longlong *)(lVar4 + 0x30) != 0) &&
       (lVar2 = *(longlong *)(*(longlong *)(lVar4 + 0x30) + 0x58), lVar2 != 0)) {
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__OnEndAction__06000dee(lVar2,0);
      if (*(longlong *)(lVar4 + 0x30) != 0) {
        lVar2 = *(longlong *)(*(longlong *)(lVar4 + 0x30) + 0x60);
        if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
          FUN_18035c820(lRam0000000182d5ab80);
        }
        if (lVar2 != 0) {
          bVar8 = DAT_182eb5d50 != 0;
          *(undefined8 *)(lVar2 + 0x180) =
               *(undefined8 *)(*(longlong *)(lRam0000000182d5ab80 + 0xb8) + 8);
          if (bVar8) {
            uVar7 = (uint)(lVar2 + 0x180U >> 0xc);
            uVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
            do {
              uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
              LOCK();
              bVar8 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
              if (bVar8) {
                *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar3 | 1L << (uVar7 & 0x3f);
              }
              UNLOCK();
            } while (!bVar8);
          }
          lVar2 = *(longlong *)(lVar4 + 0x28);
          uVar5 = ExposureUnnoticed2_Master_Action_MAction__Get__06001385(0xffffffff,0);
          if (lVar2 != 0) {
            bVar8 = DAT_182eb5d50 != 0;
            *(undefined8 *)(lVar2 + 0x48) = uVar5;
            if (bVar8) {
              uVar7 = (uint)(lVar2 + 0x48U >> 0xc);
              uVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
              do {
                uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
                LOCK();
                bVar8 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
                if (bVar8) {
                  *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar3 | 1L << (uVar7 & 0x3f);
                }
                UNLOCK();
              } while (!bVar8);
            }
            if (((*(longlong *)(lVar4 + 0x28) != 0) &&
                (lVar2 = *(longlong *)(*(longlong *)(lVar4 + 0x28) + 0x48), lVar2 != 0)) &&
               (*(longlong *)(lVar4 + 0x20) != 0)) {
              ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__TransAction__06000c7f
                        (*(longlong *)(lVar4 + 0x20),*(undefined4 *)(lVar2 + 0x18),0);
              if ((((*(longlong *)(lVar4 + 0x30) != 0) &&
                   (lVar4 = *(longlong *)(*(longlong *)(lVar4 + 0x30) + 0x48), lVar4 != 0)) &&
                  ((*(longlong *)(lVar4 + 0x40) != 0 &&
                   ((lVar2 = *(longlong *)(*(longlong *)(lVar4 + 0x40) + 0x60), lVar2 != 0 &&
                    (*(longlong *)(lVar2 + 0x48) != 0)))))) && (*(longlong *)(lVar4 + 0xb0) != 0)) {
                *(undefined4 *)(*(longlong *)(lVar4 + 0xb0) + 0x1c) = 0;
                return;
              }
            }
          }
        }
      }
    }
  }
code_r0x000180627f4f:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

