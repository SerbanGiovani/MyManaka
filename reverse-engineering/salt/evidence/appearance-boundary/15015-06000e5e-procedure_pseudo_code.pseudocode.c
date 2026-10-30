// Ghidra pseudocode; not original source or compilable C.
// ev_416ca056859a28ff1995b18c3dafc3e17541361c88ff7cb530ccc0908a7f1efe

void ExposureUnnoticed2_Object3D_Player_Scripts_Other_BodyPaintController__OnUseItem__06000e5e
               (longlong param_1)

{
  float fVar1;
  longlong lVar2;
  
  if (cRam0000000182eb765a == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb765a = '\x01';
  }
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar2 != 0) {
    fVar1 = *(float *)(lVar2 + 0x17c);
    *(undefined4 *)(lVar2 + 0x17c) = 0x42f00000;
    if (fVar1 <= 0.0) {
      if ((*(longlong *)(param_1 + 0x18) == 0) ||
         (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x1b0), lVar2 == 0))
      goto code_r0x0001803fd221;
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__SetupBodyPaintFromGameState__06000cd7
                (lVar2,0);
    }
    *(undefined4 *)(param_1 + 0x20) = 2;
    if (*(longlong *)(param_1 + 0x10) != 0) {
      *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x10) = 0x3f800000;
      if ((*(longlong *)(param_1 + 0x18) != 0) &&
         (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x60), lVar2 != 0)) {
        if (*(int *)(lVar2 + 0x228) == 8) {
          lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar2 == 0) goto code_r0x0001803fd221;
          *(undefined1 *)(lVar2 + 0x1df) = 1;
        }
        return;
      }
    }
  }
code_r0x0001803fd221:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

