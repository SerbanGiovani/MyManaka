// Ghidra pseudocode; not original source or compilable C.
// ev_b990703328260d54e2e2137ff13bc656b9fa38024ce2a718af688268b56c3c01

float ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStrangenessController__CalcNoisy__06000e34
                (longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  float fVar3;
  float fVar4;
  undefined8 uStack_48;
  undefined4 uStack_40;
  
  if (cRam0000000182eb844c == '\0') {
    FUN_1802f2810(0x182d5c7e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb844c = '\x01';
  }
  if (*(longlong *)(param_1 + 0x10) != 0) {
    uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x28);
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uStack_48 = *param_2;
    uStack_40 = *(undefined4 *)(param_2 + 1);
    fVar3 = (float)ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DistSqrt__0600172a
                             (uVar1,&uStack_48,0);
    lVar2 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
    if (lVar2 != 0) {
      fVar4 = *(float *)(lVar2 + 0x150);
      lVar2 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
      if (lVar2 != 0) {
        fVar3 = ((fVar4 - fVar3) + 1.0) / *(float *)(lVar2 + 0x150);
        if (fVar3 < 0.0) {
          fVar3 = 0.0;
        }
        else if (1.0 < fVar3) {
          fVar3 = 1.0;
        }
        fVar4 = 0.0;
        if (*(int *)(lRam0000000182d5c7e8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar2 = **(longlong **)(lRam0000000182d5c7e8 + 0xb8);
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
        if (lVar2 != 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (*(longlong *)(lVar2 + 0x10) != 0) {
            if (*(int *)(lRam0000000182d5c7e8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (*(int *)(*(longlong *)(lRam0000000182d5c7e8 + 0xb8) + 8) == 2) {
              lVar2 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
              if (lVar2 == 0) goto code_r0x0001806601cd;
              fVar4 = *(float *)(lVar2 + 0x14c);
            }
            if (*(int *)(lRam0000000182d5c7e8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (*(int *)(*(longlong *)(lRam0000000182d5c7e8 + 0xb8) + 8) == 1) {
              lVar2 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
              if (lVar2 == 0) goto code_r0x0001806601cd;
              fVar4 = *(float *)(lVar2 + 0x148);
            }
          }
        }
        fVar4 = fVar4 + 0.0;
        if ((*(longlong *)(param_1 + 0x10) != 0) &&
           (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar2 != 0)) {
          if (*(char *)(lVar2 + 0x1c) != '\0') {
            fVar4 = fVar4 + 0.03;
          }
          return fVar3 * fVar4;
        }
      }
    }
  }
code_r0x0001806601cd:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

