// Ghidra pseudocode; not original source or compilable C.
// ev_94fb1d7bcea10ce8efff244b6424f27374b95d6eb463993001d3bf31a51267dc

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

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationReceiver__OnAnimEndPickUpItem__06000c50
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
  
  if (cRam0000000182eb837a == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb837a = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x40) == 0) ||
     (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar4 == 0))
  goto code_r0x00018062a20d;
  iVar1 = *(int *)(lVar4 + 0x224);
  if (iVar1 == 5) {
    if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
       (lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x20), lVar4 == 0))
    goto code_r0x00018062a20d;
    ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__Collect__06001507(lVar4,5,0);
    uVar5 = 10000;
code_r0x00018062a1dc:
    ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551(uVar5,1,0);
  }
  else if (iVar1 == 6) {
    if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
       (lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x20), lVar4 == 0))
    goto code_r0x00018062a20d;
    ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__Collect__06001507(lVar4,6,0);
    uVar5 = 0x2711;
    goto code_r0x00018062a1dc;
  }
  if ((*(longlong *)(param_1 + 0x40) == 0) ||
     (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x68), lVar4 == 0)) {
code_r0x00018062a20d:
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

