// Ghidra pseudocode; not original source or compilable C.
// ev_cfdf922fa741e8a9b2cd9388d04db7e38e0c594f0480de84bc4f871f9dd28674

void __c___UseItemProcess_b__5_0__06001282(void)

{
  float fVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (cRam0000000182eb7866 == '\0') {
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb7866 = '\x01';
  }
  if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
      (lVar3 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar3 == 0)) ||
     (lVar3 = *(longlong *)(lVar3 + 0x1e8), lVar3 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (cRam0000000182eb765a == '\0') {
    FUN_1802f2810(&DAT_182d58398,0);
    LOCK();
    UNLOCK();
    cRam0000000182eb765a = '\x01';
  }
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar2 != 0) {
    fVar1 = *(float *)(lVar2 + 0x17c);
    *(undefined4 *)(lVar2 + 0x17c) = 0x42f00000;
    if (fVar1 <= 0.0) {
      if ((*(longlong *)(lVar3 + 0x18) == 0) ||
         (lVar2 = *(longlong *)(*(longlong *)(lVar3 + 0x18) + 0x1b0), lVar2 == 0))
      goto code_r0x0001803fd221;
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__SetupBodyPaintFromGameState__06000cd7
                (lVar2,0);
    }
    *(undefined4 *)(lVar3 + 0x20) = 2;
    if (*(longlong *)(lVar3 + 0x10) != 0) {
      *(undefined4 *)(*(longlong *)(lVar3 + 0x10) + 0x10) = 0x3f800000;
      if ((*(longlong *)(lVar3 + 0x18) != 0) &&
         (lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x18) + 0x60), lVar3 != 0)) {
        if (*(int *)(lVar3 + 0x228) == 8) {
          lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar3 == 0) goto code_r0x0001803fd221;
          *(undefined1 *)(lVar3 + 0x1df) = 1;
        }
        return;
      }
    }
  }
code_r0x0001803fd221:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

