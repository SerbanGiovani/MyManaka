// Ghidra pseudocode; not original source or compilable C.
// ev_9ef905bdfcec7432db71ffca40d923f62c8912d4f392ff0a91b0c4ad7cdaaf21

void ExposureUnnoticed2_Object3D_Player_Scripts_StaminaManager__OnUpdate__06000e50(longlong param_1)

{
  float fVar1;
  float fVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  if (cRam0000000182eb7651 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb7651 = '\x01';
  }
  if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
      (lVar3 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar3 == 0)) ||
     (lVar3 = *(longlong *)(lVar3 + 0x60), lVar3 == 0)) goto code_r0x0001803fc15c;
  if (*(int *)(param_1 + 0x28) == *(int *)(lVar3 + 0xb8)) {
    lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar3 == 0) goto code_r0x0001803fc15c;
    if (*(int *)(param_1 + 0x30) != *(int *)(lVar3 + 0x34)) {
      *(undefined4 *)(param_1 + 0x30) =
           *(undefined4 *)(*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48) + 0x34);
      goto code_r0x0001803fbff2;
    }
  }
  else {
    if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
        (lVar3 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar3 == 0)) ||
       (lVar3 = *(longlong *)(lVar3 + 0x60), lVar3 == 0)) goto code_r0x0001803fc15c;
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(lVar3 + 0xb8);
code_r0x0001803fbff2:
    ExposureUnnoticed2_Object3D_Player_Scripts_StaminaManager__UpdateMax__06000e52(param_1,0);
  }
  fVar8 = *(float *)(param_1 + 0x18);
  pcVar4 = DAT_182ec14d0;
  if ((DAT_182ec14d0 == (code *)0x0) &&
     (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"), pcVar4 == (code *)0x0)) {
    uVar5 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar5,0);
  }
  DAT_182ec14d0 = pcVar4;
  fVar6 = (float)(*DAT_182ec14d0)();
  fVar8 = fVar8 - fVar6;
  *(float *)(param_1 + 0x18) = fVar8;
  if (0.0 < fVar8) {
    return;
  }
  lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar3 != 0) {
    if (*(int *)(lVar3 + 0x34) == 2) {
      fVar8 = 1.25;
    }
    else {
      fVar8 = 1.75;
    }
    fVar6 = *(float *)(param_1 + 0x10);
    fVar1 = *(float *)(param_1 + 0x14);
    if (*(longlong *)(param_1 + 0x20) != 0) {
      fVar2 = *(float *)(*(longlong *)(param_1 + 0x20) + 0x28);
      pcVar4 = DAT_182ec14d0;
      if ((DAT_182ec14d0 == (code *)0x0) &&
         (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"), pcVar4 == (code *)0x0
         )) {
        uVar5 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec14d0 = pcVar4;
      fVar7 = (float)(*DAT_182ec14d0)();
      if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
          (lVar3 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar3 != 0)) &&
         (lVar3 = *(longlong *)(lVar3 + 0x60), lVar3 != 0)) {
        fVar6 = ((float)*(int *)(lVar3 + 0xc4) * 0.01 + 1.0) * fVar2 * fVar1 * fVar7 * fVar8 + fVar6
        ;
        if (fVar6 < 0.0) {
          fVar6 = 0.0;
        }
        else if (*(float *)(param_1 + 0x14) < fVar6) {
          fVar6 = *(float *)(param_1 + 0x14);
        }
        *(float *)(param_1 + 0x10) = fVar6;
        return;
      }
    }
  }
code_r0x0001803fc15c:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

