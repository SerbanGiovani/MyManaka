// Ghidra pseudocode; not original source or compilable C.
// ev_911731cc37ebe5f7dc5b01ef1b4598819f707dd57e853b9f91b4e70d71ea904a

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerRpBonusCalculator__OnUpdate__06000e0f
               (longlong param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  longlong lVar10;
  code *pcVar11;
  longlong lVar12;
  undefined8 *puVar13;
  ulonglong uVar14;
  undefined8 uVar15;
  int iVar16;
  undefined4 *puVar17;
  bool bVar18;
  float fVar19;
  float fVar20;
  int iStackX_18;
  float afStackX_20 [2];
  undefined8 uStack_168;
  undefined1 auStack_160 [16];
  undefined8 uStack_150;
  undefined8 uStack_148;
  longlong lStack_140;
  longlong lStack_138;
  ulonglong uStack_130;
  undefined8 uStack_128;
  longlong lStack_120;
  undefined8 uStack_118;
  longlong lStack_110;
  longlong lStack_108;
  longlong lStack_100;
  undefined8 uStack_f8;
  undefined4 uStack_f0;
  undefined8 uStack_e8;
  undefined4 uStack_e0;
  longlong lStack_d8;
  ulonglong uStack_d0;
  undefined8 uStack_c8;
  longlong lStack_c0;
  undefined8 uStack_b8;
  
  if (cRam0000000182eb8436 == '\0') {
    FUN_1802f2810(0x182d5c6f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d653b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e250);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5e240);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5df80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ee68);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c700);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ee80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d653d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ee70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d653b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c6e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d653a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c6d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ee58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ee60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d600c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65388);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c6c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ee50);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e260);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64648);
    LOCK();
    UNLOCK();
    cRam0000000182eb8436 = '\x01';
  }
  lStack_110 = 0;
  lStack_108 = 0;
  lStack_100 = 0;
  lStack_d8 = 0;
  uStack_d0 = 0;
  uStack_c8 = 0;
  lStack_c0 = 0;
  uStack_b8 = 0;
  lVar4 = *(longlong *)(param_1 + 0x10);
  if ((lVar4 == 0) || (lVar10 = *(longlong *)(lVar4 + 0x60), lVar10 == 0))
  goto code_r0x00018065cc56;
  iStackX_18 = *(int *)(lVar10 + 0xf0) + 100 + *(int *)(lVar10 + 0xf4) + *(int *)(lVar10 + 0xac);
  lVar4 = *(longlong *)(*(longlong *)(lVar4 + 0x60) + 0x160);
  lStack_140 = lVar4;
  if (lVar4 == 0) goto code_r0x00018065cc56;
  if (DAT_182eb5d50 != 0) {
    uVar9 = (uint)((ulonglong)&uStack_168 >> 0xc);
    uVar14 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
      LOCK();
      bVar18 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
      if (bVar18) {
        *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8) = uVar5 | 1L << (ulonglong)(uVar9 & 0x3f);
      }
      UNLOCK();
    } while (!bVar18);
  }
  uStack_148 = 2;
  uStack_150 = 0;
  auStack_160._4_4_ = 0;
  auStack_160._0_4_ = *(uint *)(lVar4 + 0x2c);
  uStack_130 = auStack_160._0_8_;
  uStack_128 = 0;
  lStack_120 = 0;
  uStack_118 = 2;
  uStack_168 = 0;
  auStack_160._8_8_ = 0;
  auStack_160._0_8_ = &lStack_138;
  lStack_138 = lVar4;
  while (cVar7 = FUN_180f89450(&lStack_138,uRam0000000182d653b0), cVar7 != '\0') {
    if (((int)uStack_128 != 0xc) && ((int)uStack_128 != 0x24)) {
      if (lStack_120 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      *(undefined1 *)(lStack_120 + 0x30) = 0;
    }
  }
  lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar10 == 0) goto code_r0x00018065cc56;
  if (*(char *)(lVar10 + 0x20) != '\0') {
    lVar10 = FUN_180e75f20(lVar4,8,uRam0000000182d3ee68);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    *(undefined1 *)(lVar10 + 0x30) = 1;
  }
  if ((*(longlong *)(param_1 + 0x10) == 0) ||
     (lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar10 == 0))
  goto code_r0x00018065cc56;
  if (*(char *)(lVar10 + 0x1c) != '\0') {
    lVar10 = FUN_180e75f20(lVar4,0x25,uRam0000000182d3ee68);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    *(undefined1 *)(lVar10 + 0x30) = 1;
  }
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
      (lVar10 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar10 == 0)) ||
     (lVar10 = *(longlong *)(lVar10 + 0x50), lVar10 == 0)) goto code_r0x00018065cc56;
  iVar8 = ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__CalcInRangeNpcNum__060010a2
                    (lVar10,0x3fc00000,0);
  iVar16 = 5;
  if (iVar8 < 5) {
    iVar16 = iVar8;
  }
  lVar10 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
  if (lVar10 == 0) goto code_r0x00018065cc56;
  iVar16 = iVar16 * *(int *)(lVar10 + 0x16c);
  if (0 < iVar16) {
    lVar10 = FUN_180e75f20(lVar4,9,uRam0000000182d3ee68);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    *(undefined1 *)(lVar10 + 0x30) = 1;
    lVar10 = FUN_180e75f20(lVar4,9,uRam0000000182d3ee68);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    *(int *)(lVar10 + 0x20) = iVar16;
  }
  iVar16 = 0;
  if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x00018065cc56;
  uVar9 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                    (**(longlong **)(DAT_182d58230 + 0xb8),0);
  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if ((uVar9 & 2) != 0) {
    lVar10 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    iVar16 = *(int *)(lVar10 + 0x174);
  }
  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if ((uVar9 & 8) != 0) {
    lVar10 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    iVar16 = iVar16 + *(int *)(lVar10 + 0x178);
  }
  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if ((uVar9 & 4) == 0) {
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if ((uVar9 & 0x20) != 0) {
      lVar10 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      iVar16 = iVar16 + *(int *)(lVar10 + 0x17c);
    }
  }
  else {
    lVar10 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    iVar16 = iVar16 + *(int *)(lVar10 + 0x180);
  }
  if (0 < iVar16) {
    lVar10 = FUN_180e75f20(lVar4,10,uRam0000000182d3ee68);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    *(undefined1 *)(lVar10 + 0x30) = 1;
    lVar10 = FUN_180e75f20(lVar4,10,uRam0000000182d3ee68);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    *(int *)(lVar10 + 0x20) = iVar16;
  }
  afStackX_20[0] = 0.0;
  if (((*(longlong *)(param_1 + 0x10) == 0) ||
      (lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar10 == 0)) ||
     (lVar10 = *(longlong *)(lVar10 + 0x138), lVar10 == 0)) goto code_r0x00018065cc56;
  if (DAT_182eb5d50 != 0) {
    uVar9 = (uint)((ulonglong)&uStack_168 >> 0xc);
    uVar14 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
      LOCK();
      bVar18 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
      if (bVar18) {
        *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8) = uVar5 | 1L << (uVar9 & 0x3f);
      }
      UNLOCK();
    } while (!bVar18);
  }
  uVar9 = 0;
  auStack_160._0_8_ = (ulonglong)*(uint *)(lVar10 + 0x1c) << 0x20;
  lStack_108 = auStack_160._0_8_;
  lStack_100 = 0;
  uStack_168 = 0;
  auStack_160._8_8_ = 0;
  auStack_160._0_8_ = &lStack_110;
  lStack_110 = lVar10;
  while (fVar20 = afStackX_20[0], cVar7 = FUN_180f72b70(&lStack_110,uRam0000000182d3ee70),
        cVar7 != '\0') {
    if (*(longlong *)(param_1 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (lStack_100 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    afStackX_20[0] =
         (float)ExposureUnnoticed2_Object3D_Light_StreetLightController__CalcBareyasusa__06001171
                          (lStack_100,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x28),0);
    afStackX_20[0] = fVar20 + afStackX_20[0];
  }
  if (0.5 <= fVar20) {
    lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    if (*(char *)(lVar10 + 0x20) == '\0') {
      lVar10 = FUN_180e75f20(lVar4,0xb,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined1 *)(lVar10 + 0x30) = 1;
    }
  }
  lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar10 == 0) goto code_r0x00018065cc56;
  if (*(char *)(lVar10 + 0x1dd) != '\0') {
    lVar10 = FUN_180e75f20(lVar4,0x2c,uRam0000000182d3ee68);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    *(undefined1 *)(lVar10 + 0x30) = 1;
  }
  fVar20 = *(float *)(param_1 + 0x18);
  pcVar11 = DAT_182ec14c0;
  if ((DAT_182ec14c0 == (code *)0x0) &&
     (pcVar11 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar11 == (code *)0x0)) {
    uVar15 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar15,0);
  }
  DAT_182ec14c0 = pcVar11;
  fVar19 = (float)(*DAT_182ec14c0)();
  if (fVar20 < fVar19) {
    pcVar11 = DAT_182ec14c0;
    if ((DAT_182ec14c0 == (code *)0x0) &&
       (pcVar11 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar11 == (code *)0x0)) {
      uVar15 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar15,0);
    }
    DAT_182ec14c0 = pcVar11;
    fVar20 = (float)(*DAT_182ec14c0)();
    *(float *)(param_1 + 0x18) = fVar20 + 0.5;
    fVar20 = 3.4028235e+38;
    if (((*(longlong *)(param_1 + 0x10) == 0) ||
        (lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0xa0), lVar10 == 0)) ||
       (lVar10 = *(longlong *)(lVar10 + 0x18), lVar10 == 0)) goto code_r0x00018065cc56;
    puVar17 = (undefined4 *)(lVar10 + 0x20);
    for (; (int)uVar9 < *(int *)(lVar10 + 0x18); uVar9 = uVar9 + 1) {
      if (*(uint *)(lVar10 + 0x18) <= uVar9) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      lVar12 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (((lVar12 == 0) || (lVar12 = *(longlong *)(lVar12 + 0x18), lVar12 == 0)) ||
         (lVar12 = FUN_180e75f20(lVar12,*puVar17,uRam0000000182d5df80), lVar12 == 0))
      goto code_r0x00018065cc56;
      if (*(char *)(lVar12 + 0x10) != '\0') {
        lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar6 == 0) goto code_r0x00018065cc56;
        if (*(int *)(lVar12 + 0x30) == *(int *)(lVar6 + 0x10)) {
          uVar15 = *(undefined8 *)(lVar12 + 0x14);
          uVar2 = *(undefined4 *)(lVar12 + 0x1c);
          if ((*(longlong *)(param_1 + 0x10) == 0) ||
             (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18), lVar12 == 0))
          goto code_r0x00018065cc56;
          puVar13 = (undefined8 *)FUN_181f4b9a0(&uStack_168,lVar12,0);
          uVar1 = *puVar13;
          uVar3 = *(undefined4 *)(puVar13 + 1);
          if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
            FUN_18035c820();
          }
          uStack_f8 = uVar1;
          uStack_f0 = uVar3;
          uStack_e8 = uVar15;
          uStack_e0 = uVar2;
          fVar19 = (float)ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__CalcPathLength__0600173f
                                    (&uStack_e8,&uStack_f8,0);
          if (fVar19 <= fVar20) {
            fVar20 = fVar19;
          }
        }
      }
      puVar17 = puVar17 + 1;
    }
    if ((fVar20 < 3.4028235e+38) && (60.0 <= fVar20)) {
      fVar20 = 60.0;
    }
    lVar10 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    *(int *)(param_1 + 0x1c) = ((int)fVar20 / 10) * *(int *)(lVar10 + 0x164);
  }
  if (*(int *)(param_1 + 0x1c) < 1) {
code_r0x00018065b915:
    lVar10 = FUN_180e75f20(lVar4,0xc,uRam0000000182d3ee68);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    *(undefined1 *)(lVar10 + 0x30) = 0;
  }
  else {
    if ((*(longlong *)(param_1 + 0x10) == 0) ||
       (lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar10 == 0))
    goto code_r0x00018065cc56;
    if (*(int *)(lVar10 + 0x168) != 0) goto code_r0x00018065b915;
    lVar10 = FUN_180e75f20(lVar4,0xc,uRam0000000182d3ee68);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    *(undefined1 *)(lVar10 + 0x30) = 1;
    lVar10 = FUN_180e75f20(lVar4,0xc,uRam0000000182d3ee68);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    *(undefined4 *)(lVar10 + 0x20) = *(undefined4 *)(param_1 + 0x1c);
  }
  lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar10 == 0) goto code_r0x00018065cc56;
  iVar16 = 0x1c - (int)*(float *)(lVar10 + 0x178);
  if (iVar16 < 0x17) {
    iVar16 = 0x17;
  }
  lVar10 = FUN_180e75f20(lVar4,iVar16,uRam0000000182d3ee68);
  if (lVar10 == 0) goto code_r0x00018065cc56;
  *(undefined1 *)(lVar10 + 0x30) = 1;
  if (DAT_182eb7988 == '\0') {
    FUN_1802f2810(&DAT_182d5dd30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb7988 = '\x01';
  }
  iVar16 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529(5,0);
  if (0 < iVar16) {
    lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar10 == 0) || (lVar10 = *(longlong *)(lVar10 + 0x1d0), lVar10 == 0))
    goto code_r0x00018065cc56;
    cVar7 = FUN_180e6c190(lVar10,5,DAT_182d5dd30);
    if (cVar7 != '\0') {
      lVar10 = FUN_180e75f20(lVar4,1,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined1 *)(lVar10 + 0x30) = 1;
    }
  }
  if (DAT_182eb7988 == '\0') {
    FUN_1802f2810(&DAT_182d5dd30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb7988 = '\x01';
  }
  iVar16 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529(10,0);
  if (0 < iVar16) {
    lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar10 == 0) || (lVar10 = *(longlong *)(lVar10 + 0x1d0), lVar10 == 0))
    goto code_r0x00018065cc56;
    cVar7 = FUN_180e6c190(lVar10,10,DAT_182d5dd30);
    if (cVar7 != '\0') {
      lVar10 = FUN_180e75f20(lVar4,2,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined1 *)(lVar10 + 0x30) = 1;
    }
  }
  if (DAT_182eb7988 == '\0') {
    FUN_1802f2810(&DAT_182d5dd30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb7988 = '\x01';
  }
  iVar16 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529(0x14,0);
  if (0 < iVar16) {
    lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar10 == 0) || (lVar10 = *(longlong *)(lVar10 + 0x1d0), lVar10 == 0))
    goto code_r0x00018065cc56;
    cVar7 = FUN_180e6c190(lVar10,0x14,DAT_182d5dd30);
    if (cVar7 != '\0') {
      lVar10 = FUN_180e75f20(lVar4,0x43,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined1 *)(lVar10 + 0x30) = 1;
    }
  }
  if (DAT_182eb7988 == '\0') {
    FUN_1802f2810(&DAT_182d5dd30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb7988 = '\x01';
  }
  iVar16 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529(0x13,0);
  if (0 < iVar16) {
    lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar10 == 0) || (lVar10 = *(longlong *)(lVar10 + 0x1d0), lVar10 == 0))
    goto code_r0x00018065cc56;
    cVar7 = FUN_180e6c190(lVar10,0x13,DAT_182d5dd30);
    if (cVar7 != '\0') {
      lVar10 = FUN_180e75f20(lVar4,0x42,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined1 *)(lVar10 + 0x30) = 1;
    }
  }
  if (DAT_182eb7988 == '\0') {
    FUN_1802f2810(&DAT_182d5dd30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb7988 = '\x01';
  }
  iVar16 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529(0xd,0);
  if (0 < iVar16) {
    lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar10 == 0) || (lVar10 = *(longlong *)(lVar10 + 0x1d0), lVar10 == 0))
    goto code_r0x00018065cc56;
    cVar7 = FUN_180e6c190(lVar10,0xd,DAT_182d5dd30);
    if (cVar7 != '\0') {
      lVar10 = FUN_180e75f20(lVar4,0x20,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined1 *)(lVar10 + 0x30) = 1;
    }
  }
  if (DAT_182eb7988 == '\0') {
    FUN_1802f2810(&DAT_182d5dd30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb7988 = '\x01';
  }
  iVar16 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529(7,0);
  if (0 < iVar16) {
    lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar10 == 0) || (lVar10 = *(longlong *)(lVar10 + 0x1d0), lVar10 == 0))
    goto code_r0x00018065cc56;
    cVar7 = FUN_180e6c190(lVar10,7,DAT_182d5dd30);
    if (cVar7 != '\0') {
      lVar10 = FUN_180e75f20(lVar4,0x21,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined1 *)(lVar10 + 0x30) = 1;
    }
  }
  if (DAT_182eb7988 == '\0') {
    FUN_1802f2810(&DAT_182d5dd30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb7988 = '\x01';
  }
  iVar16 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529(9,0);
  if (0 < iVar16) {
    lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar10 == 0) || (lVar10 = *(longlong *)(lVar10 + 0x1d0), lVar10 == 0))
    goto code_r0x00018065cc56;
    cVar7 = FUN_180e6c190(lVar10,9,DAT_182d5dd30);
    if (cVar7 != '\0') {
      lVar10 = FUN_180e75f20(lVar4,0x37,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined1 *)(lVar10 + 0x30) = 1;
    }
  }
  if (DAT_182eb7988 == '\0') {
    FUN_1802f2810(&DAT_182d5dd30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb7988 = '\x01';
  }
  iVar16 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529(0x12,0);
  if (0 < iVar16) {
    lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar10 == 0) || (lVar10 = *(longlong *)(lVar10 + 0x1d0), lVar10 == 0))
    goto code_r0x00018065cc56;
    cVar7 = FUN_180e6c190(lVar10,0x12,DAT_182d5dd30);
    if (cVar7 != '\0') {
      lVar10 = FUN_180e75f20(lVar4,0x30,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined1 *)(lVar10 + 0x30) = 1;
    }
  }
  if (DAT_182eb5498 == '\0') {
    FUN_1802f2810(&DAT_182d5a900);
    LOCK();
    UNLOCK();
    DAT_182eb5498 = '\x01';
  }
  lVar10 = **(longlong **)(DAT_182d5a900 + 0xb8);
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
  if (lVar10 == 0) {
    bVar18 = false;
  }
  else {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    bVar18 = *(longlong *)(lVar10 + 0x10) != 0;
  }
  if (bVar18) {
    if (DAT_182eb5498 == '\0') {
      FUN_1802f2810(&DAT_182d5a900);
      LOCK();
      UNLOCK();
      DAT_182eb5498 = '\x01';
    }
    if (**(longlong **)(DAT_182d5a900 + 0xb8) == 0) goto code_r0x00018065cc56;
    iVar16 = ExposureUnnoticed2_Scripts_InGame_SceneProcessManager_LaundryManager__GetRpBuffSourceType__060016bc
                       (**(longlong **)(DAT_182d5a900 + 0xb8),0);
    if (iVar16 != -1) {
      lVar10 = FUN_180e75f20(lVar4,iVar16,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined1 *)(lVar10 + 0x30) = 1;
    }
  }
  if (DAT_182eb79c0 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb79c0 = '\x01';
  }
  lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar10 == 0) goto code_r0x00018065cc56;
  if ((((*(char *)(lVar10 + 0x1a8) != '\0') || (*(char *)(lVar10 + 0x1a9) != '\0')) &&
      (lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48),
      *(int *)(lVar10 + 0x1ac) == 5)) && (0.0 < *(float *)(lVar10 + 0x1b0))) {
    if (*(int *)(lVar10 + 0x1b4) == 1) {
      lVar10 = FUN_180e75f20(lVar4,0x2d,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined1 *)(lVar10 + 0x30) = 1;
      lVar10 = FUN_180e75f20(lVar4,0x2d,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined4 *)(lVar10 + 0x20) = 10;
      lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      if (*(char *)(lVar10 + 0x1a9) != '\0') {
        lVar10 = FUN_180e75f20(lVar4,0x2d,uRam0000000182d3ee68);
        if (lVar10 == 0) goto code_r0x00018065cc56;
        *(int *)(lVar10 + 0x20) = *(int *)(lVar10 + 0x20) * 2;
      }
    }
    lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    if (*(int *)(lVar10 + 0x1b4) == 3) {
      lVar10 = FUN_180e75f20(lVar4,0x2e,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined1 *)(lVar10 + 0x30) = 1;
      lVar10 = FUN_180e75f20(lVar4,0x2e,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined4 *)(lVar10 + 0x20) = 0xf;
      lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      if (*(char *)(lVar10 + 0x1a9) != '\0') {
        lVar10 = FUN_180e75f20(lVar4,0x2e,uRam0000000182d3ee68);
        if (lVar10 == 0) goto code_r0x00018065cc56;
        *(int *)(lVar10 + 0x20) = *(int *)(lVar10 + 0x20) * 2;
      }
    }
    lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    if (*(int *)(lVar10 + 0x1b4) == 5) {
      lVar10 = FUN_180e75f20(lVar4,0x2f,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined1 *)(lVar10 + 0x30) = 1;
      lVar10 = FUN_180e75f20(lVar4,0x2f,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined4 *)(lVar10 + 0x20) = 0x14;
      lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      if (*(char *)(lVar10 + 0x1a9) != '\0') {
        lVar10 = FUN_180e75f20(lVar4,0x2f,uRam0000000182d3ee68);
        if (lVar10 == 0) goto code_r0x00018065cc56;
        *(int *)(lVar10 + 0x20) = *(int *)(lVar10 + 0x20) * 2;
      }
    }
  }
  if (**(longlong **)(lRam0000000182d5e260 + 0xb8) == 0) goto code_r0x00018065cc56;
  if (*(char *)(**(longlong **)(lRam0000000182d5e260 + 0xb8) + 0x10) != '\0') {
    lVar10 = FUN_180e75f20(lVar4,0x31,uRam0000000182d3ee68);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    *(undefined1 *)(lVar10 + 0x30) = 1;
    lVar10 = FUN_180e75f20(lVar4,0x31,uRam0000000182d3ee68);
    if ((**(longlong **)(lRam0000000182d5e260 + 0xb8) == 0) || (lVar10 == 0))
    goto code_r0x00018065cc56;
    *(undefined4 *)(lVar10 + 0x20) =
         *(undefined4 *)(**(longlong **)(lRam0000000182d5e260 + 0xb8) + 0x14);
  }
  if ((*(longlong *)(param_1 + 0x10) == 0) ||
     (lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar10 == 0))
  goto code_r0x00018065cc56;
  iVar16 = ((int)(*(float *)(lVar10 + 0x98) * 100.0) + -100) / 5;
  if (0 < iVar16) {
    lVar10 = FUN_180e75f20(lVar4,0x32,uRam0000000182d3ee68);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    *(undefined1 *)(lVar10 + 0x30) = 1;
    lVar10 = FUN_180e75f20(lVar4,0x32,uRam0000000182d3ee68);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    *(int *)(lVar10 + 0x20) = iVar16;
  }
  lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar10 == 0) goto code_r0x00018065cc56;
  if (*(int *)(lVar10 + 0x1ac) == 3) {
    if (*(char *)(lVar10 + 0x1a8) == '\0') {
      if (*(char *)(lVar10 + 0x1a9) == '\0') goto code_r0x00018065c3c1;
      uVar15 = 0x35;
    }
    else {
      uVar15 = 0x34;
    }
    lVar10 = FUN_180e75f20(lVar4,uVar15,uRam0000000182d3ee68);
    if (lVar10 == 0) goto code_r0x00018065cc56;
    *(undefined1 *)(lVar10 + 0x30) = 1;
  }
code_r0x00018065c3c1:
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
      (lVar10 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x48), lVar10 != 0)) &&
     (lVar10 = *(longlong *)(lVar10 + 0x10), lVar10 != 0)) {
    if (1.0 <= *(float *)(lVar10 + 0x1c)) {
      lVar10 = FUN_180e75f20(lVar4,0x33,uRam0000000182d3ee68);
      if (lVar10 == 0) goto code_r0x00018065cc56;
      *(undefined1 *)(lVar10 + 0x30) = 1;
    }
    if ((*(longlong *)(param_1 + 0x10) != 0) &&
       (lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar10 != 0)) {
      if (*(char *)(lVar10 + 0x50) != '\0') {
        lVar10 = FUN_180e75f20(lVar4,0x44,uRam0000000182d3ee68);
        if (lVar10 == 0) goto code_r0x00018065cc56;
        *(undefined1 *)(lVar10 + 0x30) = 1;
      }
      if ((*(longlong *)(param_1 + 0x10) != 0) &&
         (lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x1e8), lVar10 != 0)) {
        if ((*(int *)(lVar10 + 0x20) != 1) && (*(int *)(lVar10 + 0x20) != 0)) {
          lVar10 = FUN_180e75f20(lVar4,0x36,uRam0000000182d3ee68);
          if (lVar10 == 0) goto code_r0x00018065cc56;
          *(undefined1 *)(lVar10 + 0x30) = 1;
        }
        lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar10 != 0) {
          if (*(char *)(lVar10 + 0x1dd) == '\0') {
            if (DAT_182eb548c == '\0') {
              FUN_1802f2810(&DAT_182d57a70);
              LOCK();
              UNLOCK();
              DAT_182eb548c = '\x01';
            }
            if (**(longlong **)(DAT_182d57a70 + 0xb8) == 0) goto code_r0x00018065cc56;
            if (*(char *)(**(longlong **)(DAT_182d57a70 + 0xb8) + 0x5e) != '\0') {
              lVar10 = FUN_180e75f20(lVar4,0x38,uRam0000000182d3ee68);
              if (lVar10 == 0) goto code_r0x00018065cc56;
              *(undefined1 *)(lVar10 + 0x30) = 1;
            }
          }
          lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar10 != 0) {
            if (*(int *)(lVar10 + 0x34) == 1) {
              lVar10 = FUN_180e75f20(lVar4,0x40,uRam0000000182d3ee68);
              if (lVar10 == 0) goto code_r0x00018065cc56;
              *(undefined1 *)(lVar10 + 0x30) = 1;
            }
            lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar10 != 0) {
              if (*(int *)(lVar10 + 0x34) == 0) {
                lVar10 = FUN_180e75f20(lVar4,0x41,uRam0000000182d3ee68);
                if (lVar10 == 0) goto code_r0x00018065cc56;
                *(undefined1 *)(lVar10 + 0x30) = 1;
              }
              if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              if (cRam0000000182eb7836 == '\0') {
                FUN_1802f2810(&DAT_182d594e8);
                LOCK();
                UNLOCK();
                cRam0000000182eb7836 = '\x01';
              }
              if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              ExposureUnnoticed2_Master_Stage_MStage__CheckInitialize__06001228(0);
              lVar10 = **(longlong **)(DAT_182d594e8 + 0xb8);
              if (lVar10 != 0) {
                if (DAT_182eb5d50 != 0) {
                  uVar9 = (uint)((ulonglong)&uStack_168 >> 0xc);
                  uVar14 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                  do {
                    uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                    LOCK();
                    bVar18 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                    if (bVar18) {
                      *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8) =
                           uVar5 | 1L << (ulonglong)(uVar9 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar18);
                }
                uStack_148 = 2;
                uStack_150 = 0;
                auStack_160._4_4_ = 0;
                auStack_160._0_4_ = *(uint *)(lVar10 + 0x2c);
                uStack_d0 = auStack_160._0_8_;
                uStack_c8 = 0;
                lStack_c0 = 0;
                uStack_b8 = 2;
                uStack_168 = 0;
                auStack_160._8_8_ = 0;
                auStack_160._0_8_ = &lStack_d8;
                lStack_d8 = lVar10;
                while (cVar7 = FUN_180f89450(&lStack_d8,uRam0000000182d5c6e8), cVar7 != '\0') {
                  lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                  if (lVar10 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  if (*(int *)(lVar10 + 0x10) == (int)uStack_c8) {
                    if (lStack_c0 == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    fVar20 = *(float *)(lStack_c0 + 0x18);
                    if (**(longlong **)(DAT_182d53c48 + 0xb8) == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    lVar10 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30);
                    if (lVar10 == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    lVar10 = *(longlong *)(lVar10 + 0x40);
                    if (lVar10 == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    FUN_180005b10(lVar10,fVar20,0);
                    if (**(longlong **)(DAT_182d53c48 + 0xb8) == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    lVar10 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30);
                    if (lVar10 == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    lVar10 = *(longlong *)(lVar10 + 0x40);
                    if (lVar10 == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    iVar16 = FUN_180e71cd0(lVar10,fVar20);
                    if (4 < iVar16) {
                      iVar8 = (iVar16 / 5) * 5;
                      iVar16 = 0x14;
                      if (iVar8 < 0x14) {
                        iVar16 = iVar8;
                      }
                      switch(fVar20) {
                      case 8.40779e-45:
                        lVar10 = FUN_180e75f20(lVar4,0x3b);
                        break;
                      case 9.80909e-45:
                        lVar10 = FUN_180e75f20(lVar4,0x3f);
                        break;
                      default:
                        afStackX_20[0] = fVar20;
                        uVar15 = il2cpp_value_box(uRam0000000182d64648,afStackX_20);
                    /* WARNING: Subroutine does not return */
                        _PrivateImplementationDetails___ThrowSwitchExpressionException__06001e66
                                  (uVar15,0);
                      case 1.4013e-44:
                        lVar10 = FUN_180e75f20(lVar4,0x39);
                        break;
                      case 1.54143e-44:
                        lVar10 = FUN_180e75f20(lVar4,0x3e);
                        break;
                      case 1.68156e-44:
                        lVar10 = FUN_180e75f20(lVar4,0x3c);
                        break;
                      case 1.96182e-44:
                        lVar10 = FUN_180e75f20(lVar4,0x3a);
                        break;
                      case 2.10195e-44:
                        lVar10 = FUN_180e75f20(lVar4,0x3d);
                      }
                      if (lVar10 == 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      *(undefined1 *)(lVar10 + 0x30) = 1;
                      *(int *)(lVar10 + 0x20) = iVar16;
                    }
                  }
                }
                if (DAT_182eb5d50 != 0) {
                  uVar9 = (uint)((ulonglong)&uStack_168 >> 0xc);
                  uVar14 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                  do {
                    uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                    LOCK();
                    bVar18 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                    if (bVar18) {
                      *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8) = uVar5 | 1L << (uVar9 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar18);
                }
                uStack_148 = 2;
                uStack_150 = 0;
                auStack_160._4_4_ = 0;
                auStack_160._0_4_ = *(uint *)(lVar4 + 0x2c);
                uStack_130 = auStack_160._0_8_;
                uStack_128 = 0;
                lStack_120 = 0;
                uStack_118 = 2;
                uStack_168 = 0;
                auStack_160._8_8_ = 0;
                auStack_160._0_8_ = &lStack_138;
                lStack_138 = lVar4;
                while (cVar7 = FUN_180f89450(&lStack_138,uRam0000000182d653b0), cVar7 != '\0') {
                  if (lStack_120 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  if (*(char *)(lStack_120 + 0x30) != '\0') {
                    iStackX_18 = iStackX_18 + *(int *)(lStack_120 + 0x20);
                  }
                }
                if ((*(longlong *)(param_1 + 0x10) != 0) &&
                   (lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar10 != 0)) {
                  fVar20 = (float)*(int *)(lVar10 + 0x100) * *(float *)(lVar10 + 0x10c) +
                           (float)iStackX_18 +
                           (float)*(int *)(lVar10 + 0x104) * *(float *)(lVar10 + 0x110);
                  uStack_150 = 0;
                  if (DAT_182eb5d50 != 0) {
                    uVar9 = (uint)((ulonglong)&uStack_168 >> 0xc);
                    uVar14 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                    do {
                      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                      LOCK();
                      bVar18 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                      if (bVar18) {
                        *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8) = uVar5 | 1L << (uVar9 & 0x3f);
                      }
                      UNLOCK();
                    } while (!bVar18);
                  }
                  uStack_148 = 2;
                  auStack_160._4_4_ = 0;
                  auStack_160._0_4_ = *(uint *)(lVar4 + 0x2c);
                  uStack_130 = auStack_160._0_8_;
                  uStack_128 = 0;
                  lStack_120 = 0;
                  uStack_118 = 2;
                  uStack_168 = 0;
                  auStack_160._8_8_ = 0;
                  auStack_160._0_8_ = &lStack_138;
                  lStack_138 = lVar4;
                  while (cVar7 = FUN_180f89450(&lStack_138,uRam0000000182d653b0), cVar7 != '\0') {
                    if (lStack_120 == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    if ((*(char *)(lStack_120 + 0x30) != '\0') && (*(int *)(lStack_120 + 0x24) != 0)
                       ) {
                      fVar20 = fVar20 * (float)*(int *)(lStack_120 + 0x24) * 0.01;
                    }
                  }
                  if (*(longlong *)(param_1 + 0x10) != 0) {
                    lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60);
                    fVar19 = fVar20 / 100.0;
                    if (fVar19 < 0.0) {
                      fVar19 = 0.0;
                    }
                    if (lVar4 != 0) {
                      *(float *)(lVar4 + 0xe8) = fVar19;
                      if (*(longlong *)(param_1 + 0x10) != 0) {
                        lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60);
                        fVar19 = 0.0;
                        if (0.0 <= fVar20) {
                          fVar19 = fVar20;
                        }
                        if (lVar4 != 0) {
                          *(float *)(lVar4 + 0xec) = fVar19;
                          lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                          if (lVar4 != 0) {
                            if ((*(longlong *)(param_1 + 0x10) != 0) &&
                               (lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60),
                               lVar10 != 0)) {
                              fVar20 = *(float *)(lVar10 + 0xe8);
                              fVar19 = *(float *)(lVar4 + 0x15c);
                              if (*(float *)(lVar4 + 0x15c) <= fVar20) {
                                fVar19 = fVar20;
                              }
                              *(float *)(lVar4 + 0x15c) = fVar19;
                              return;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
code_r0x00018065cc56:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

