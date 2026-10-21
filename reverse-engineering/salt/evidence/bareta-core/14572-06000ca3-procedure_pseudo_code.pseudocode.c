// Ghidra pseudocode; not original source or compilable C.
// ev_d201429419140c9ba22f6498c492fee4df6a3b84fe5c6131a6d5bf505ae25e49

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBaretaState__OnExit__06000ca3
               (longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  bool bVar7;
  
  if (cRam0000000182eb83a7 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb83a7 = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x20) != 0) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x48), lVar1 != 0)) {
    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetBareta__06000c85
              (lVar1,0,0);
    if ((*(longlong *)(param_1 + 0x20) != 0) &&
       (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x48), lVar1 != 0)) {
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetBaretaFace__06000c86
                (lVar1,0,0);
      if ((*(longlong *)(param_1 + 0x20) != 0) &&
         (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x48), lVar1 != 0)) {
        *(undefined4 *)(lVar1 + 0x1c) = 0x3f800000;
        if ((*(longlong *)(param_1 + 0x20) != 0) &&
           (lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48), lVar1 != 0)) {
          lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x60);
          uVar4 = 0x2725;
          if (*(char *)(lVar1 + 0x1a9) == '\0') {
            uVar4 = 0xffffffff;
          }
          uVar4 = ExposureUnnoticed2_Master_Action_MAction__Get__06001385(uVar4,0);
          if (lVar2 != 0) {
            bVar7 = DAT_182eb5d50 != 0;
            *(undefined8 *)(lVar2 + 0x48) = uVar4;
            if (bVar7) {
              uVar6 = (uint)(lVar2 + 0x48U >> 0xc);
              uVar5 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
              do {
                uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
                LOCK();
                bVar7 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
                if (bVar7) {
                  *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8) = uVar3 | 1L << (uVar6 & 0x3f);
                }
                UNLOCK();
              } while (!bVar7);
            }
            if ((*(longlong *)(param_1 + 0x20) != 0) &&
               (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x120), lVar1 != 0)) {
              ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__DisableLookAt__06000c10
                        (lVar1,7,0);
              *(undefined1 *)(param_1 + 0x18) = 0;
              return;
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

