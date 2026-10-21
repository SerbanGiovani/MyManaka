// Ghidra pseudocode; not original source or compilable C.
// ev_f419957821afacabd1f57614b01b07fe37e23019722dfd9b17fad1268bae11c4

void ExposureUnnoticed2_Scripts_InGame_GameOverController__OnGameOverEvent__060014e0
               (longlong param_1)

{
  int *piVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 uVar11;
  code *pcVar12;
  longlong lVar13;
  undefined8 *puVar14;
  ulonglong uVar15;
  bool bVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  undefined4 auStackX_20 [2];
  undefined8 uStack_e8;
  float fStack_e0;
  undefined8 uStack_d8;
  float fStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined4 uStack_80;
  
  if (cRam0000000182eb795a == '\0') {
    FUN_1802f2810(&DAT_182d59ac8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e258);
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
    FUN_1802f2810(0x182d5e190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d55a30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e260);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58298);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e0b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c830);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53648);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58290);
    LOCK();
    UNLOCK();
    cRam0000000182eb795a = '\x01';
  }
  uStack_a8 = 0;
  uStack_a0 = 0;
  uStack_88 = 0;
  uStack_98 = 0;
  uStack_90 = 0;
  uStack_80 = 0;
  lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar9 == 0) goto code_r0x00018048609a;
  if (*(int *)(lVar9 + 0x34) != 0) {
    lVar9 = ExposureUnnoticed2_Master_Rank_MRank__CalcCurrentRank__06001261
                      ((double)*(int *)(lVar9 + 0x1e8),0);
    if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
        (lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48), lVar10 == 0)) ||
       (lVar13 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar13 == 0))
    goto code_r0x00018048609a;
    *(int *)(lVar13 + 0x24) = (int)*(double *)(lVar10 + 0x1f0);
    lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar10 == 0) goto code_r0x00018048609a;
    *(double *)(lVar10 + 0x140) = *(double *)(lVar10 + 0x1f0) + *(double *)(lVar10 + 0x140);
    lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (((lVar10 == 0) || (**(longlong **)(DAT_182d53c48 + 0xb8) == 0)) ||
       (lVar13 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar13 == 0))
    goto code_r0x00018048609a;
    *(double *)(lVar10 + 0x148) = (double)*(int *)(lVar13 + 0x20) + *(double *)(lVar10 + 0x148);
    lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar10 == 0) goto code_r0x00018048609a;
    lVar10 = ExposureUnnoticed2_Master_Rank_MRank__CalcCurrentRank__06001261
                       ((double)*(int *)(lVar10 + 0x1e8),0);
    if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
        (lVar13 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar13 == 0)) ||
       ((lVar13 = *(longlong *)(lVar13 + 0x30), lVar13 == 0 ||
        ((lVar13 = *(longlong *)(lVar13 + 0x40), lVar13 == 0 ||
         (lVar13 = *(longlong *)(lVar13 + 0x60), lVar13 == 0)))))) goto code_r0x00018048609a;
    bVar16 = DAT_182eb5d50 != 0;
    *(longlong *)(lVar13 + 0x128) = lVar10;
    if (bVar16) {
      uVar6 = (uint)(lVar13 + 0x128U >> 0xc);
      uVar15 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
      do {
        uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
        LOCK();
        bVar16 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
        if (bVar16) {
          *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8) = uVar3 | 1L << (uVar6 & 0x3f);
        }
        UNLOCK();
      } while (!bVar16);
    }
    if ((((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) || (lVar9 == 0)) || (lVar10 == 0)) ||
       (lVar13 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar13 == 0))
    goto code_r0x00018048609a;
    *(bool *)(lVar13 + 0x1c) = *(int *)(lVar9 + 0x18) != *(int *)(lVar10 + 0x18);
  }
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
      (lVar9 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar9 != 0)) &&
     ((lVar9 = *(longlong *)(lVar9 + 0x30), lVar9 != 0 &&
      (lVar9 = *(longlong *)(lVar9 + 0x40), lVar9 != 0)))) {
    lVar9 = *(longlong *)(lVar9 + 0x60);
    uVar11 = ExposureUnnoticed2_Master_Clothes_MClothes__Get__06001343(0,0);
    if (lVar9 != 0) {
      bVar16 = DAT_182eb5d50 != 0;
      *(undefined8 *)(lVar9 + 0x10) = uVar11;
      if (bVar16) {
        uVar6 = (uint)(lVar9 + 0x10U >> 0xc);
        uVar15 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
        do {
          uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
          LOCK();
          bVar16 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
          if (bVar16) {
            *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8) = uVar3 | 1L << (uVar6 & 0x3f);
          }
          UNLOCK();
        } while (!bVar16);
      }
      lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar9 != 0) {
        bVar16 = DAT_182eb54a2 == '\0';
        *(undefined4 *)(lVar9 + 0x19c) = 0;
        if (bVar16) {
          FUN_1802f2810(&DAT_182d5bcb8);
          LOCK();
          UNLOCK();
          DAT_182eb54a2 = '\x01';
        }
        if ((**(longlong **)(DAT_182d5bcb8 + 0xb8) != 0) &&
           (ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__Collect__06001507
                      (**(longlong **)(DAT_182d5bcb8 + 0xb8),0,0),
           **(longlong **)(lRam0000000182d5e258 + 0xb8) != 0)) {
          if (cRam0000000182eb7968 == '\0') {
            FUN_1802f2810(&DAT_182d58398);
            LOCK();
            UNLOCK();
            cRam0000000182eb7968 = '\x01';
          }
          lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar9 != 0) {
            *(undefined4 *)(lVar9 + 0xbc) = 0xffffffff;
            if (**(longlong **)(lRam0000000182d5e260 + 0xb8) != 0) {
              *(undefined1 *)(**(longlong **)(lRam0000000182d5e260 + 0xb8) + 0x10) = 0;
              lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
              if (lVar9 != 0) {
                *(undefined8 *)(lVar9 + 0x1f0) = 0;
                if (**(longlong **)(lRam0000000182d5e190 + 0xb8) != 0) {
                  ExposureUnnoticed2_Scripts_Mission_MissionManager__ResetMission__0600146a
                            (**(longlong **)(lRam0000000182d5e190 + 0xb8),0);
                  lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                  if (lVar9 != 0) {
                    *(undefined4 *)(lVar9 + 0x1b8) = 0;
                    lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                    if (lVar9 != 0) {
                      *(undefined4 *)(lVar9 + 0x274) = 0;
                      lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                      if (lVar9 != 0) {
                        *(undefined8 *)(lVar9 + 0x170) = 0;
                        lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                        if (lVar9 != 0) {
                          *(undefined4 *)(lVar9 + 0x1bc) = 1;
                          lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                          if (lVar9 != 0) {
                            *(undefined4 *)(lVar9 + 0x10) = 0;
                            lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                            if (lVar9 != 0) {
                              *(undefined8 *)(lVar9 + 0x180) = 0x3dcccccd00000000;
                              *(undefined4 *)(lVar9 + 0x188) = 0;
                              lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                              if (lVar9 != 0) {
                                *(undefined4 *)(lVar9 + 0x178) = 0;
                                lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                if (lVar9 != 0) {
                                  piVar1 = (int *)(lVar9 + 300);
                                  *piVar1 = *piVar1 + 1;
                                  lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                  if (lVar9 != 0) {
                                    cVar5 = *(char *)(lVar9 + 0x1a9);
                                    if (cVar5 != '\0') {
                                      *(undefined1 *)(lVar9 + 0x1a9) = 0;
                                      lVar9 = *(longlong *)
                                               (*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                      if (lVar9 == 0) goto code_r0x00018048609a;
                                      uVar2 = *(undefined4 *)(lVar9 + 0x1ac);
                                      bVar4 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEquipAdultGoods__0600153c
                                                        (*(undefined4 *)
                                                          (*(longlong *)
                                                            (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                            0x48) + 0x1ac),0);
                                      ExposureUnnoticed2_Scripts_InGame_GameStateFacade__UpdateAdultGoodsState__0600153d
                                                (uVar2,bVar4 ^ 1,0);
                                    }
                                    lVar9 = *(longlong *)
                                             (*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                    if (lVar9 != 0) {
                                      if (*(char *)(lVar9 + 0x1a8) != '\0') {
                                        *(undefined1 *)(lVar9 + 0x1a8) = 0;
                                        lVar9 = *(longlong *)
                                                 (*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                        if (lVar9 == 0) goto code_r0x00018048609a;
                                        uVar2 = *(undefined4 *)(lVar9 + 0x1ac);
                                        bVar4 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEquipAdultGoods__0600153c
                                                          (*(undefined4 *)
                                                            (*(longlong *)
                                                              (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                              0x48) + 0x1ac),0);
                                        ExposureUnnoticed2_Scripts_InGame_GameStateFacade__UpdateAdultGoodsState__0600153d
                                                  (uVar2,bVar4 ^ 1,0);
                                      }
                                      if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
                                        FUN_18035c820(DAT_182d59ac8);
                                      }
                                      if (*(char *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 1) == '\0'
                                         ) {
                                        ExposureUnnoticed2_Scripts_InGame_SaveManager__Save__06001601
                                                  (3,0xffffffff,0,0);
                                      }
                                      if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                                         (lVar9 = *(longlong *)
                                                   (**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30),
                                         lVar9 != 0)) {
                                        *(undefined1 *)(lVar9 + 0x10) = 1;
                                        if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                                            (((lVar9 = *(longlong *)
                                                        (**(longlong **)(DAT_182d53c48 + 0xb8) +
                                                        0x28), lVar9 != 0 &&
                                              (lVar9 = *(longlong *)(lVar9 + 0x30), lVar9 != 0)) &&
                                             (lVar9 = *(longlong *)(lVar9 + 0x40), lVar9 != 0)))) &&
                                           (lVar9 = *(longlong *)(lVar9 + 0x10), lVar9 != 0)) {
                                          pcVar12 = DAT_182ebf2f0;
                                          if ((DAT_182ebf2f0 == (code *)0x0) &&
                                             (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::set_speed(System.Single)"),
                                             pcVar12 == (code *)0x0)) {
                                            uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Animator::set_speed(System.Single)");
                    /* WARNING: Subroutine does not return */
                                            FUN_1802cca90(uVar11,0);
                                          }
                                          DAT_182ebf2f0 = pcVar12;
                                          (*DAT_182ebf2f0)(lVar9,0);
                                          if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                                              (lVar9 = *(longlong *)
                                                        (**(longlong **)(DAT_182d53c48 + 0xb8) +
                                                        0x28), lVar9 != 0)) &&
                                             (lVar9 = *(longlong *)(lVar9 + 0x50), lVar9 != 0)) {
                                            ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__OnGameOverEvent__0600109f
                                                      (lVar9,0);
                                            lVar9 = *(longlong *)(param_1 + 0x28);
                                            if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                                                (lVar10 = *(longlong *)
                                                           (**(longlong **)(DAT_182d53c48 + 0xb8) +
                                                           0x28), lVar10 != 0)) &&
                                               (lVar10 = *(longlong *)(lVar10 + 0x38), lVar10 != 0))
                                            {
                                              pcVar12 = DAT_182ec1080;
                                              if ((DAT_182ec1080 == (code *)0x0) &&
                                                 (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_transform()"),
                                                 pcVar12 == (code *)0x0)) {
                                                uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                                                FUN_1802cca90(uVar11,0);
                                              }
                                              DAT_182ec1080 = pcVar12;
                                              lVar10 = (*DAT_182ec1080)(lVar10);
                                              if (lVar10 != 0) {
                                                uStack_e8 = 0;
                                                fStack_e0 = 0.0;
                                                pcVar12 = DAT_182ec1698;
                                                if ((DAT_182ec1698 == (code *)0x0) &&
                                                   (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar12 == (code *)0x0)) {
                                                  uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                }
                                                DAT_182ec1698 = pcVar12;
                                                (*DAT_182ec1698)(lVar10,&uStack_e8);
                                                if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                                                    (lVar10 = *(longlong *)
                                                               (**(longlong **)
                                                                  (DAT_182d53c48 + 0xb8) + 0x28),
                                                    lVar10 != 0)) &&
                                                   (lVar10 = *(longlong *)(lVar10 + 0x38),
                                                   lVar10 != 0)) {
                                                  pcVar12 = DAT_182ec1080;
                                                  if ((DAT_182ec1080 == (code *)0x0) &&
                                                     (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_transform()"),
                                                  pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec1080 = pcVar12;
                                                  lVar10 = (*DAT_182ec1080)(lVar10);
                                                  if (lVar10 != 0) {
                                                    uStack_b8 = 0;
                                                    uStack_b0 = 0;
                                                    pcVar12 = DAT_182ec16b8;
                                                    if ((DAT_182ec16b8 == (code *)0x0) &&
                                                       (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec16b8 = pcVar12;
                                                  (*DAT_182ec16b8)(lVar10,&uStack_b8);
                                                  if (lVar9 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  fStack_d0 = fStack_e0;
                                                  uStack_c8 = uStack_b8;
                                                  uStack_c0 = uStack_b0;
                                                  uStack_d8 = uStack_e8;
                                                  pcVar12 = DAT_182ec16f8;
                                                  if ((DAT_182ec16f8 == (code *)0x0) &&
                                                     (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::SetPositionAndRotation_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                                  ), pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Transform::SetPositionAndRotation_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec16f8 = pcVar12;
                                                  (*DAT_182ec16f8)(lVar9,&uStack_d8,&uStack_c8);
                                                  uVar11 = DAT_182d53648;
                                                  if (cVar5 == '\0') {
                                                    if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0
                                                         ) || (lVar9 = *(longlong *)
                                                                        (**(longlong **)
                                                                           (DAT_182d58378 + 0xb8) +
                                                                        0x40), lVar9 == 0)) ||
                                                       (lVar9 = *(longlong *)(lVar9 + 0x170),
                                                       lVar9 == 0)) goto code_r0x00018048609a;
                                                    fVar20 = *(float *)(lVar9 + 0x28) * 1.2;
                                                  }
                                                  else {
                                                    fVar20 = 0.6;
                                                  }
                                                  pcVar12 = DAT_182ec1198;
                                                  if ((DAT_182ec1198 == (code *)0x0) &&
                                                     (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.LayerMask::NameToLayer(System.String)"
                                                  ), pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.LayerMask::NameToLayer(System.String)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec1198 = pcVar12;
                                                  bVar4 = (*DAT_182ec1198)(uVar11);
                                                  uVar11 = DAT_182d58290;
                                                  pcVar12 = DAT_182ec1198;
                                                  if ((DAT_182ec1198 == (code *)0x0) &&
                                                     (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.LayerMask::NameToLayer(System.String)"
                                                  ), pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.LayerMask::NameToLayer(System.String)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec1198 = pcVar12;
                                                  uVar6 = (*DAT_182ec1198)(uVar11);
                                                  uVar11 = DAT_182d5c830;
                                                  pcVar12 = DAT_182ec1198;
                                                  if ((DAT_182ec1198 == (code *)0x0) &&
                                                     (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.LayerMask::NameToLayer(System.String)"
                                                  ), pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.LayerMask::NameToLayer(System.String)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec1198 = pcVar12;
                                                  uVar7 = (*DAT_182ec1198)(uVar11);
                                                  uVar11 = DAT_182d58298;
                                                  pcVar12 = DAT_182ec1198;
                                                  if ((DAT_182ec1198 == (code *)0x0) &&
                                                     (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.LayerMask::NameToLayer(System.String)"
                                                  ), pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.LayerMask::NameToLayer(System.String)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec1198 = pcVar12;
                                                  uVar8 = (*DAT_182ec1198)(uVar11);
                                                  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0)
                                                     && (lVar9 = *(longlong *)
                                                                  (**(longlong **)
                                                                     (DAT_182d53c48 + 0xb8) + 0x28),
                                                        lVar9 != 0)) {
                                                    lVar9 = *(longlong *)(lVar9 + 0x30);
                                                    lVar10 = *(longlong *)(param_1 + 0x38);
                                                    if (lVar9 != 0) {
                                                      pcVar12 = DAT_182ec1080;
                                                      if ((DAT_182ec1080 == (code *)0x0) &&
                                                         (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_transform()"),
                                                  pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec1080 = pcVar12;
                                                  lVar13 = (*DAT_182ec1080)(lVar9);
                                                  if (lVar13 != 0) {
                                                    uStack_e8 = 0;
                                                    fStack_e0 = 0.0;
                                                    pcVar12 = DAT_182ec1698;
                                                    if ((DAT_182ec1698 == (code *)0x0) &&
                                                       (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec1698 = pcVar12;
                                                  (*DAT_182ec1698)(lVar13,&uStack_e8);
                                                  pcVar12 = DAT_182ec1080;
                                                  if ((DAT_182ec1080 == (code *)0x0) &&
                                                     (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_transform()"),
                                                  pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec1080 = pcVar12;
                                                  lVar13 = (*DAT_182ec1080)(lVar9);
                                                  if (lVar13 != 0) {
                                                    uStack_d8 = 0;
                                                    fStack_d0 = 0.0;
                                                    pcVar12 = DAT_182ec1698;
                                                    if ((DAT_182ec1698 == (code *)0x0) &&
                                                       (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec1698 = pcVar12;
                                                  (*DAT_182ec1698)(lVar13,&uStack_d8);
                                                  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  if (lVar10 != 0) {
                                                    uStack_c8 = CONCAT44(uStack_d8._4_4_ + fVar20,
                                                                         (float)uStack_e8);
                                                    uStack_c0 = CONCAT44(uStack_c0._4_4_,fStack_e0);
                                                    pcVar12 = DAT_182ec16a0;
                                                    if ((DAT_182ec16a0 == (code *)0x0) &&
                                                       (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec16a0 = pcVar12;
                                                  (*DAT_182ec16a0)(lVar10,&uStack_c8);
                                                  lVar10 = *(longlong *)(param_1 + 0x38);
                                                  if (lVar10 != 0) {
                                                    uStack_e8 = 0;
                                                    fStack_e0 = 0.0;
                                                    pcVar12 = DAT_182ec1698;
                                                    if ((DAT_182ec1698 == (code *)0x0) &&
                                                       (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec1698 = pcVar12;
                                                  (*DAT_182ec1698)(lVar10,&uStack_e8);
                                                  pcVar12 = DAT_182ec1080;
                                                  if ((DAT_182ec1080 == (code *)0x0) &&
                                                     (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_transform()"),
                                                  pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec1080 = pcVar12;
                                                  lVar10 = (*DAT_182ec1080)(lVar9);
                                                  if (lVar10 != 0) {
                                                    puVar14 = (undefined8 *)
                                                              FUN_181f4c360(&uStack_b8,lVar10,0);
                                                    uVar11 = *puVar14;
                                                    uVar2 = *(undefined4 *)(puVar14 + 1);
                                                    if (*(int *)(lRam0000000182d55a30 + 0xe0) == 0)
                                                    {
                                                      FUN_18035c820();
                                                    }
                                                    if (cRam0000000182ec3721 == '\0') {
                                                      FUN_1802f2810(0x182d55a30);
                                                      LOCK();
                                                      UNLOCK();
                                                      cRam0000000182ec3721 = '\x01';
                                                    }
                                                    if (*(int *)(lRam0000000182d55a30 + 0xe0) == 0)
                                                    {
                                                      FUN_18035c820();
                                                    }
                                                    auStackX_20[0] = FUN_181fb32b0(0);
                                                    uStack_d8 = uStack_e8;
                                                    fStack_d0 = fStack_e0;
                                                    uStack_c0 = CONCAT44(uStack_c0._4_4_,uVar2);
                                                    uStack_c8 = uVar11;
                                                    cVar5 = FUN_181fbacd0(auStackX_20,&uStack_d8,
                                                                          0x3ccccccd,&uStack_c8,
                                                                          &uStack_a8,0x3f4ccccd,
                                                                          ~(1 << (bVar4 & 0x1f) |
                                                                            1 << (uVar6 & 0x1f) |
                                                                            1 << (uVar7 & 0x1f) |
                                                                           1 << (uVar8 & 0x1f)),1,0)
                                                    ;
                                                    fVar19 = 0.8;
                                                    if (cVar5 != '\0') {
                                                      fVar19 = uStack_90._4_4_;
                                                    }
                                                    lVar10 = *(longlong *)(param_1 + 0x30);
                                                    pcVar12 = DAT_182ec1080;
                                                    if ((DAT_182ec1080 == (code *)0x0) &&
                                                       (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_transform()"),
                                                  pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec1080 = pcVar12;
                                                  lVar13 = (*DAT_182ec1080)(lVar9);
                                                  if (lVar13 != 0) {
                                                    uStack_e8 = 0;
                                                    fStack_e0 = 0.0;
                                                    pcVar12 = DAT_182ec1698;
                                                    if ((DAT_182ec1698 == (code *)0x0) &&
                                                       (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec1698 = pcVar12;
                                                  (*DAT_182ec1698)(lVar13,&uStack_e8);
                                                  pcVar12 = DAT_182ec1080;
                                                  if ((DAT_182ec1080 == (code *)0x0) &&
                                                     (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_transform()"),
                                                  pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec1080 = pcVar12;
                                                  lVar9 = (*DAT_182ec1080)(lVar9);
                                                  if (lVar9 != 0) {
                                                    puVar14 = (undefined8 *)
                                                              FUN_181f4c360(&uStack_b8,lVar9,0);
                                                    uStack_c8 = *puVar14;
                                                    fVar17 = (float)((ulonglong)uStack_c8 >> 0x20) *
                                                             fVar19 + uStack_e8._4_4_;
                                                    fVar18 = (float)uStack_c8 * fVar19 +
                                                             (float)uStack_e8;
                                                    fVar19 = *(float *)(puVar14 + 1) * fVar19 +
                                                             fStack_e0;
                                                    if (DAT_182eb547c == '\0') {
                                                      FUN_1802f2810(&DAT_182d522a8);
                                                      LOCK();
                                                      UNLOCK();
                                                      DAT_182eb547c = '\x01';
                                                    }
                                                    uStack_c8 = *(undefined8 *)
                                                                 (*(longlong *)
                                                                   (DAT_182d522a8 + 0xb8) + 0x18);
                                                    if (lVar10 != 0) {
                                                      uStack_c8 = CONCAT44((float)((ulonglong)
                                                                                   uStack_c8 >> 0x20
                                                                                  ) * fVar20 +
                                                                           fVar17,(float)uStack_c8 *
                                                                                  fVar20 + fVar18);
                                                      uStack_c0 = CONCAT44(uStack_c0._4_4_,
                                                                           *(float *)(*(longlong *)
                                                                                       (
                                                  DAT_182d522a8 + 0xb8) + 0x20) * fVar20 + fVar19);
                                                  pcVar12 = DAT_182ec16a0;
                                                  if ((DAT_182ec16a0 == (code *)0x0) &&
                                                     (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec16a0 = pcVar12;
                                                  (*DAT_182ec16a0)(lVar10,&uStack_c8);
                                                  lVar9 = *(longlong *)(param_1 + 0x30);
                                                  lVar10 = *(longlong *)(param_1 + 0x38);
                                                  if (lVar9 != 0) {
                                                    if (cRam0000000182ec1631 == '\0') {
                                                      FUN_1802f2810(&DAT_182d53aa8);
                                                      LOCK();
                                                      UNLOCK();
                                                      cRam0000000182ec1631 = '\x01';
                                                    }
                                                    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                                      FUN_18035c820();
                                                    }
                                                    if (DAT_182ec129a == '\0') {
                                                      FUN_1802f2810(&DAT_182d53aa8);
                                                      LOCK();
                                                      UNLOCK();
                                                      DAT_182ec129a = '\x01';
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
                                                    if (lVar10 != 0) {
                                                      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                                        FUN_18035c820();
                                                      }
                                                      if (*(longlong *)(lVar10 + 0x10) != 0) {
                                                        uStack_e8 = 0;
                                                        fStack_e0 = 0.0;
                                                        pcVar12 = DAT_182ec1698;
                                                        if ((DAT_182ec1698 == (code *)0x0) &&
                                                           (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  DAT_182ec1698 = pcVar12;
                                                  (*DAT_182ec1698)(lVar10,&uStack_e8);
                                                  if (DAT_182eb547c == '\0') {
                                                    FUN_1802f2810(&DAT_182d522a8);
                                                    LOCK();
                                                    UNLOCK();
                                                    DAT_182eb547c = '\x01';
                                                  }
                                                  uStack_d8 = *(undefined8 *)
                                                               (*(longlong *)(DAT_182d522a8 + 0xb8)
                                                               + 0x18);
                                                  fStack_d0 = *(float *)(*(longlong *)
                                                                          (DAT_182d522a8 + 0xb8) +
                                                                        0x20);
                                                  uStack_b0 = CONCAT44(uStack_b0._4_4_,fStack_e0);
                                                  uStack_b8 = uStack_e8;
                                                  pcVar12 = pcRam0000000182ec1710;
                                                  if ((pcRam0000000182ec1710 == (code *)0x0) &&
                                                     (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::Internal_LookAt_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&)"
                                                  ), pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Transform::Internal_LookAt_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  pcRam0000000182ec1710 = pcVar12;
                                                  (*pcRam0000000182ec1710)
                                                            (lVar9,&uStack_b8,&uStack_d8);
                                                  }
                                                  }
                                                  uVar11 = uRam0000000182d5e0b0;
                                                  lVar9 = *(longlong *)(param_1 + 0x50);
                                                  if (lVar9 != 0) {
                                                    pcVar12 = pcRam0000000182ebf360;
                                                    if ((pcRam0000000182ebf360 == (code *)0x0) &&
                                                       (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetTriggerString(System.String)"
                                                  ), pcVar12 == (code *)0x0)) {
                                                    uVar11 = FUN_1802ced60(
                                                  "UnityEngine.Animator::SetTriggerString(System.String)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar11,0);
                                                  }
                                                  pcRam0000000182ebf360 = pcVar12;
                                                  (*pcRam0000000182ebf360)(lVar9,uVar11);
                                                  return;
                                                  }
                                                  }
                                                  }
                    /* WARNING: Subroutine does not return */
                                                  FUN_18031dad0();
                                                  }
                                                  }
                                                  }
                                                  goto code_r0x00018048609a;
                                                  }
                                                  }
                    /* WARNING: Subroutine does not return */
                                                  FUN_18031dad0();
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
  }
code_r0x00018048609a:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

