// Ghidra pseudocode; not original source or compilable C.
// ev_d902c125ec89f8da948947de3c2f2038b16ccf8d7a240f6cc215f02436a2a5f6

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__ChangeState__06000d5e
               (longlong param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  code *pcVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  uint uVar8;
  undefined8 uVar9;
  bool bVar10;
  
  if (cRam0000000182eb83e3 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb83e3 = '\x01';
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  if ((lVar2 == 0) || (*(longlong *)(lVar2 + 0x60) == 0)) goto code_r0x00018064539b;
  uVar9 = 0xffffffff;
  if (*(int *)(*(longlong *)(lVar2 + 0x60) + 0x5c) == 1) {
    lVar2 = *(longlong *)(lVar2 + 0xe0);
    if (lVar2 == 0) goto code_r0x00018064539b;
    if (cRam0000000182eb83a7 == '\0') {
      FUN_1802f2810(&DAT_182d58398);
      LOCK();
      UNLOCK();
      cRam0000000182eb83a7 = '\x01';
    }
    if ((*(longlong *)(lVar2 + 0x20) == 0) ||
       (lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x20) + 0x48), lVar3 == 0))
    goto code_r0x00018064539b;
    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetBareta__06000c85
              (lVar3,0,0);
    if ((*(longlong *)(lVar2 + 0x20) == 0) ||
       (lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x20) + 0x48), lVar3 == 0))
    goto code_r0x00018064539b;
    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetBaretaFace__06000c86
              (lVar3,0,0);
    if ((((*(longlong *)(lVar2 + 0x20) == 0) ||
         (lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x20) + 0x48), lVar3 == 0)) ||
        (*(undefined4 *)(lVar3 + 0x1c) = 0x3f800000, *(longlong *)(lVar2 + 0x20) == 0)) ||
       (lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48), lVar3 == 0))
    goto code_r0x00018064539b;
    uVar6 = 0x2725;
    if (*(char *)(lVar3 + 0x1a9) == '\0') {
      uVar6 = 0xffffffff;
    }
    lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x20) + 0x60);
    uVar6 = ExposureUnnoticed2_Master_Action_MAction__Get__06001385(uVar6,0);
    if (lVar3 == 0) goto code_r0x00018064539b;
    bVar10 = DAT_182eb5d50 != 0;
    *(undefined8 *)(lVar3 + 0x48) = uVar6;
    if (bVar10) {
      uVar8 = (uint)(lVar3 + 0x48U >> 0xc);
      uVar7 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
      do {
        uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
        LOCK();
        bVar10 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
        if (bVar10) {
          *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) = uVar4 | 1L << (uVar8 & 0x3f);
        }
        UNLOCK();
      } while (!bVar10);
    }
    if ((*(longlong *)(lVar2 + 0x20) == 0) ||
       (lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x20) + 0x120), lVar3 == 0))
    goto code_r0x00018064539b;
    ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__DisableLookAt__06000c10(lVar3,7,0);
    *(undefined1 *)(lVar2 + 0x18) = 0;
  }
  if ((*(longlong *)(param_1 + 0x40) != 0) &&
     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar2 != 0)) {
    *(int *)(lVar2 + 0x5c) = param_2;
    if (param_2 == 1) {
      if (*(longlong *)(param_1 + 0x40) != 0) {
        lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xd8);
        lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar3 != 0) {
          iVar1 = *(int *)(lVar3 + 0x10);
          if ((iVar1 == 10) || (iVar1 - 0xbU < 2)) {
            uVar9 = 8;
          }
          if (lVar2 != 0) {
            pcVar5 = DAT_182ebee88;
            if ((DAT_182ebee88 == (code *)0x0) &&
               (pcVar5 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.AI.NavMeshAgent::set_areaMask(System.Int32)"
                                              ), pcVar5 == (code *)0x0)) {
              uVar9 = FUN_1802ced60("UnityEngine.AI.NavMeshAgent::set_areaMask(System.Int32)");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar9,0);
            }
            DAT_182ebee88 = pcVar5;
            (*DAT_182ebee88)(lVar2,uVar9);
            if ((*(longlong *)(param_1 + 0x40) != 0) &&
               (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x48), lVar2 != 0)) {
              ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetEcstasy__06000c82
                        (lVar2,0,0);
              if ((*(longlong *)(param_1 + 0x40) != 0) &&
                 (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xe0), lVar2 != 0)) {
                ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBaretaState__OnEnter__06000ca2
                          (lVar2,0);
                return;
              }
            }
          }
        }
      }
    }
    else {
      if (param_2 != 2) {
        return;
      }
      if ((*(longlong *)(param_1 + 0x40) != 0) &&
         (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x48), lVar2 != 0)) {
        ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetEcstasy__06000c82
                  (lVar2,0,0);
        if ((*(longlong *)(param_1 + 0x40) != 0) &&
           (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xd8), lVar2 != 0)) {
          FUN_181ed9520(lVar2,1,0);
          if ((*(longlong *)(param_1 + 0x40) != 0) &&
             (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xd8), lVar2 != 0)) {
            FUN_181ed9580(lVar2,1,0);
            return;
          }
        }
      }
    }
  }
code_r0x00018064539b:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

