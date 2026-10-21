// Ghidra pseudocode; not original source or compilable C.
// ev_34c8daf811845223fd6f9bbaaed04eb81f27c82fac48addac8d5ca0616f72875

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBaretaState__OnEnter__06000ca2
               (longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  
  if (cRam0000000182eb83a6 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb83a6 = '\x01';
  }
  lVar1 = *(longlong *)(DAT_182d58398 + 0xb8);
  lVar2 = *(longlong *)(lVar1 + 0x48);
  if (lVar2 != 0) {
    if (*(char *)(lVar2 + 0x1a9) != '\0') {
      *(undefined1 *)(param_1 + 0x18) = 1;
    }
    lVar2 = *(longlong *)(param_1 + 0x20);
    if (lVar2 != 0) {
      if (*(char *)(param_1 + 0x18) == '\0') {
        if (*(longlong *)(lVar2 + 0x48) == 0) goto DAT_180631a5c;
        ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetBareta__06000c85
                  (*(longlong *)(lVar2 + 0x48),CONCAT71((int7)((ulonglong)lVar1 >> 8),1),0);
        if (((*(longlong *)(param_1 + 0x20) == 0) ||
            (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x48), lVar1 == 0)) ||
           (lVar1 = *(longlong *)(lVar1 + 0x60), lVar1 == 0)) goto DAT_180631a5c;
        *(undefined4 *)(lVar1 + 0x1c) = 0;
      }
      else {
        lVar1 = *(longlong *)(lVar2 + 0x120);
        if ((((lVar2 == 0) || (*(longlong *)(lVar2 + 0xe0) == 0)) ||
            (lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0xe0) + 0x10), lVar2 == 0)) ||
           (uVar4 = ExposureUnnoticed2_Object3D_NPC_Script_NpcController__get_EyePosition__0600104c
                              (lVar2,0), lVar1 == 0)) goto DAT_180631a5c;
        ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__EnableLookAt__06000c0f
                  (lVar1,7,uVar4,1,0);
        if ((*(longlong *)(param_1 + 0x20) == 0) ||
           (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x48), lVar1 == 0))
        goto DAT_180631a5c;
        ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetBaretaFace__06000c86
                  (lVar1,1,0);
        if ((*(longlong *)(param_1 + 0x20) == 0) ||
           ((lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x48), lVar1 == 0 ||
            (lVar1 = *(longlong *)(lVar1 + 0x60), lVar1 == 0)))) goto DAT_180631a5c;
        *(undefined4 *)(lVar1 + 0x1c) = 0x3f800000;
      }
      pcVar3 = DAT_182ec14c0;
      if ((DAT_182ec14c0 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar3 == (code *)0x0)) {
        uVar4 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      DAT_182ec14c0 = pcVar3;
      uVar5 = (*DAT_182ec14c0)();
      *(undefined4 *)(param_1 + 0x28) = uVar5;
      if ((*(longlong *)(param_1 + 0x20) != 0) &&
         (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x48), lVar1 != 0)) {
        *(undefined4 *)(lVar1 + 0x1c) = 0;
        if ((*(longlong *)(param_1 + 0x20) != 0) &&
           (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x48), lVar1 != 0)) {
          *(undefined4 *)(lVar1 + 0x10) = 0;
          if ((*(longlong *)(param_1 + 0x20) != 0) &&
             (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x60), lVar1 != 0)) {
            *(undefined1 *)(lVar1 + 0x1b) = 0;
            if ((*(longlong *)(param_1 + 0x20) != 0) &&
               (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x48), lVar1 != 0)) {
              ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetGamanBaibu__06000c8a
                        (lVar1,0,0);
              lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
              if (lVar1 != 0) {
                *(undefined4 *)(lVar1 + 0x168) = 0;
                return;
              }
            }
          }
        }
      }
    }
  }
DAT_180631a5c:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

