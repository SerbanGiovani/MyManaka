// Ghidra pseudocode; not original source or compilable C.
// ev_9e513d51b059c451e93baa328e62450edf9f2c9b80b2eb84478c201772bf7a1d

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAction__ChangeAction__06000c36
               (longlong param_1,int param_2)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  bool bVar8;
  
  if (cRam0000000182eb836f == '\0') {
    FUN_1802f2810(0x182d5ab80);
    LOCK();
    UNLOCK();
    cRam0000000182eb836f = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x28) == 0) ||
     (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x48), lVar4 == 0))
  goto code_r0x000180627f4f;
  iVar1 = *(int *)(lVar4 + 0x18);
  if (((0x272d < iVar1) && (iVar1 < 0x2773)) ||
     ((((iVar1 - 0x272aU < 2 || (iVar1 - 0x2775U < 4)) || (iVar1 == 0x2779)) && (param_2 == 0x272b))
     )) {
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
  if (*(char *)(param_1 + 0x38) != '\0') {
    return;
  }
  if (param_2 < 0x2713) {
    if (param_2 == -1) {
      if ((*(longlong *)(param_1 + 0x30) == 0) ||
         (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x58), lVar4 == 0))
      goto code_r0x000180627f4f;
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__OnEndAction__06000dee(lVar4,0);
    }
    else if (param_2 == 0x2712) {
      if ((*(longlong *)(param_1 + 0x30) == 0) ||
         (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x48), lVar4 == 0))
      goto code_r0x000180627f4f;
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetHoldInHand__06000c88
                (lVar4,0,0);
      if ((*(longlong *)(param_1 + 0x30) == 0) ||
         (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x48), lVar4 == 0))
      goto code_r0x000180627f4f;
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetHadBasket__06000c87
                (lVar4,0,0);
    }
  }
  else if (param_2 == 0x2719) {
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x48), lVar4 == 0))
    goto code_r0x000180627f4f;
    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetHoldInHand__06000c88
              (lVar4,0,0);
  }
  else if ((param_2 != 0x271a) && (param_2 != 0x271b)) {
    if (param_2 == 0x271c) {
      if (((*(longlong *)(param_1 + 0x30) == 0) ||
          (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x70), lVar4 == 0)) ||
         (lVar4 = *(longlong *)(lVar4 + 0x200), lVar4 == 0)) goto code_r0x000180627f4f;
      FUN_181f3ea80(lVar4,1,0);
    }
    else if (param_2 == 0x271d) {
      if (((*(longlong *)(param_1 + 0x30) == 0) ||
          (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x70), lVar4 == 0)) ||
         ((lVar4 = *(longlong *)(lVar4 + 0x50), lVar4 == 0 ||
          (lVar4 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                             (lVar4,0), lVar4 == 0)))) goto code_r0x000180627f4f;
      FUN_181f3ea80(lVar4,1,0);
      if (((*(longlong *)(param_1 + 0x30) == 0) ||
          (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x70), lVar4 == 0)) ||
         (lVar4 = *(longlong *)(lVar4 + 0x50), lVar4 == 0)) goto code_r0x000180627f4f;
      FUN_181fa1000(lVar4,1,0);
      if ((*(longlong *)(param_1 + 0x30) == 0) ||
         (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xb0), lVar4 == 0))
      goto code_r0x000180627f4f;
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerSoundManager__PlaySe__06000e21(lVar4,0x10,0);
    }
    else {
      switch(param_2) {
      case 0x2723:
      case 0x2724:
      case 0x2726:
        if ((*(longlong *)(param_1 + 0x30) == 0) ||
           (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xb0), lVar4 == 0))
        goto code_r0x000180627f4f;
        ExposureUnnoticed2_Object3D_Player_Scripts_PlayerSoundManager__SetPickingSeSoundIfNeed__06000e24
                  (lVar4,1,0);
        break;
      case 0x2725:
      case 0x2727:
      case 0x2728:
      case 0x2729:
        break;
      case 0x272a:
code_r0x000180627c2f:
        lVar4 = FUN_180525140();
        if (lVar4 == 0) goto code_r0x000180627f4f;
        ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__SetOverride__06001a95
                  (lVar4,7,0);
        break;
      case 0x272b:
        if ((*(longlong *)(param_1 + 0x30) == 0) ||
           (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar4 == 0))
        goto code_r0x000180627f4f;
        *(undefined1 *)(lVar4 + 0x23a) = 0;
        break;
      default:
        if (param_2 == 0x2775) goto code_r0x000180627c2f;
      }
    }
  }
  if (*(longlong *)(param_1 + 0x30) != 0) {
    lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60);
    if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d5ab80);
    }
    if (lVar4 != 0) {
      bVar8 = DAT_182eb5d50 != 0;
      *(undefined8 *)(lVar4 + 0x180) =
           *(undefined8 *)(*(longlong *)(lRam0000000182d5ab80 + 0xb8) + 8);
      if (bVar8) {
        uVar7 = (uint)(lVar4 + 0x180U >> 0xc);
        uVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
          LOCK();
          bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
          if (bVar8) {
            *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar2 | 1L << (uVar7 & 0x3f);
          }
          UNLOCK();
        } while (!bVar8);
      }
      lVar4 = *(longlong *)(param_1 + 0x28);
      uVar5 = ExposureUnnoticed2_Master_Action_MAction__Get__06001385(param_2,0);
      if (lVar4 != 0) {
        bVar8 = DAT_182eb5d50 != 0;
        *(undefined8 *)(lVar4 + 0x48) = uVar5;
        if (bVar8) {
          uVar7 = (uint)(lVar4 + 0x48U >> 0xc);
          uVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
          do {
            uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
            LOCK();
            bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
            if (bVar8) {
              *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar2 | 1L << (uVar7 & 0x3f);
            }
            UNLOCK();
          } while (!bVar8);
        }
        if (((*(longlong *)(param_1 + 0x28) != 0) &&
            (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x48), lVar4 != 0)) &&
           (*(longlong *)(param_1 + 0x20) != 0)) {
          ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__TransAction__06000c7f
                    (*(longlong *)(param_1 + 0x20),*(undefined4 *)(lVar4 + 0x18),0);
          if (param_2 != -1) {
            *(undefined1 *)(param_1 + 0x38) = 1;
          }
          if ((((*(longlong *)(param_1 + 0x30) != 0) &&
               (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x48), lVar4 != 0)) &&
              ((*(longlong *)(lVar4 + 0x40) != 0 &&
               ((lVar3 = *(longlong *)(*(longlong *)(lVar4 + 0x40) + 0x60), lVar3 != 0 &&
                (*(longlong *)(lVar3 + 0x48) != 0)))))) && (*(longlong *)(lVar4 + 0xb0) != 0)) {
            *(undefined4 *)(*(longlong *)(lVar4 + 0xb0) + 0x1c) = 0;
            return;
          }
        }
      }
    }
  }
code_r0x000180627f4f:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

