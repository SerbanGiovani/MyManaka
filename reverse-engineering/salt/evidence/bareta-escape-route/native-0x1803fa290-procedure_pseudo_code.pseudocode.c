// Ghidra pseudocode; not original source or compilable C.
// ev_ae475cf25d0f28d1ad94477f284e1d9e3eec9c11e220190c367e402cdde64584

void native_only_1803fa290__00000000(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  longlong lVar6;
  double dVar7;
  undefined1 auVar8 [16];
  float fVar9;
  
  if (DAT_182eb5486 == '\0') {
    FUN_1802f2810(&DAT_182d52288);
    LOCK();
    UNLOCK();
    DAT_182eb5486 = '\x01';
  }
  fVar1 = param_1[1];
  fVar9 = *param_1;
  fVar2 = param_1[2];
  fVar3 = param_2[1];
  fVar4 = *param_2;
  fVar5 = param_2[2];
  if (*(int *)(DAT_182d52288 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d52288);
  }
  lVar6 = DAT_182d52288;
  dVar7 = (double)((fVar4 * fVar4 + fVar3 * fVar3 + fVar5 * fVar5) *
                  (fVar9 * fVar9 + fVar1 * fVar1 + fVar2 * fVar2));
  if (dVar7 < 0.0) {
    dVar7 = (double)FUN_1803989f0();
  }
  else {
    auVar8._8_8_ = 0;
    auVar8._0_8_ = dVar7;
    auVar8 = sqrtpd(ZEXT816(0),auVar8);
    dVar7 = auVar8._0_8_;
  }
  if (1e-15 <= (float)dVar7) {
    fVar9 = ((float)((ulonglong)*(undefined8 *)param_2 >> 0x20) *
             (float)((ulonglong)*(undefined8 *)param_1 >> 0x20) +
             (float)*(undefined8 *)param_2 * (float)*(undefined8 *)param_1 + param_2[2] * param_1[2]
            ) / (float)dVar7;
    fVar1 = -1.0;
    if ((fVar9 < -1.0) || (fVar1 = 1.0, 1.0 < fVar9)) {
      fVar9 = fVar1;
    }
    if (*(int *)(lVar6 + 0xe0) == 0) {
      FUN_18035c820(lVar6);
    }
    FUN_18039d250((double)fVar9);
  }
  return;
}

