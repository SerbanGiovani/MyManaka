// Ghidra pseudocode; not original source or compilable C.
// ev_45e98d0357cf584aacb8492954e493e3db696d6e04395bc43abfd2bb1e68df0d

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__Initialize__06001055
               (longlong param_1,undefined8 param_2,longlong param_3,char param_4,int param_5)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong *plVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  code *pcVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 *puVar11;
  undefined4 *puVar12;
  ulonglong uVar13;
  uint uVar14;
  bool bVar15;
  bool bVar16;
  float fVar17;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  
  if (DAT_182eb775a == '\0') {
    FUN_1802f2810(&DAT_182d57c08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59908);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d557e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d57bf8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59900);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d598f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d598e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d598e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59a98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d598d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d598c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d598c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d598b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d598a0);
    LOCK();
    UNLOCK();
    DAT_182eb775a = '\x01';
  }
  lVar9 = *(longlong *)(param_1 + 0x28);
  iVar1 = **(int **)(DAT_182d59a98 + 0xb8);
  **(int **)(DAT_182d59a98 + 0xb8) = iVar1 + 1;
  *(int *)(param_1 + 0x38) = iVar1;
  if (lVar9 != 0) {
    *(int *)(lVar9 + 0x88) = iVar1;
    if (*(longlong *)(param_1 + 0x28) != 0) {
      uVar6 = FUN_180735660(*(longlong *)(param_1 + 0x28),DAT_182d557e8);
      bVar15 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x40) = uVar6;
      if (bVar15) {
        uVar14 = (uint)(param_1 + 0x40U >> 0xc);
        uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
          LOCK();
          bVar15 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
          if (bVar15) {
            *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) = uVar2 | 1L << (uVar14 & 0x3f);
          }
          UNLOCK();
        } while (!bVar15);
      }
      uVar6 = FUN_1802c43a0(DAT_182d598b0);
      ExposureUnnoticed2_Object3D_NPC_Script_NpcStateModel___ctor__060010bb(uVar6,0);
      bVar15 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x48) = uVar6;
      if (bVar15) {
        uVar14 = (uint)(param_1 + 0x48U >> 0xc);
        uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
          LOCK();
          bVar15 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
          if (bVar15) {
            *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) = uVar2 | 1L << (uVar14 & 0x3f);
          }
          UNLOCK();
        } while (!bVar15);
      }
      if (*(longlong *)(param_1 + 0x48) != 0) {
        *(int *)(*(longlong *)(param_1 + 0x48) + 0x58) = param_5;
        uVar6 = FUN_1802c43a0(DAT_182d598c0);
        bVar15 = DAT_182eb5d50 != 0;
        *(undefined8 *)(param_1 + 0x50) = uVar6;
        if (bVar15) {
          uVar14 = (uint)(param_1 + 0x50U >> 0xc);
          uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
          do {
            uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
            LOCK();
            bVar15 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
            if (bVar15) {
              *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) = uVar2 | 1L << (uVar14 & 0x3f);
            }
            UNLOCK();
          } while (!bVar15);
        }
        uVar6 = FUN_1802c43a0(DAT_182d598d8);
        ExposureUnnoticed2_Object3D_NPC_Script_NpcFadeOutState___ctor__060010f0(uVar6,0);
        bVar15 = DAT_182eb5d50 != 0;
        *(undefined8 *)(param_1 + 0x58) = uVar6;
        if (bVar15) {
          uVar14 = (uint)(param_1 + 0x58U >> 0xc);
          uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
          do {
            uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
            LOCK();
            bVar15 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
            if (bVar15) {
              *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) = uVar2 | 1L << (uVar14 & 0x3f);
            }
            UNLOCK();
          } while (!bVar15);
        }
        uVar6 = FUN_1802c43a0(DAT_182d598f8);
        bVar15 = DAT_182eb5d50 != 0;
        *(undefined8 *)(param_1 + 0x60) = uVar6;
        if (bVar15) {
          uVar14 = (uint)(param_1 + 0x60U >> 0xc);
          uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
          do {
            uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
            LOCK();
            bVar15 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
            if (bVar15) {
              *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) = uVar2 | 1L << (uVar14 & 0x3f);
            }
            UNLOCK();
          } while (!bVar15);
        }
        uVar6 = FUN_1802c43a0(DAT_182d598c8);
        bVar15 = DAT_182eb5d50 != 0;
        *(undefined8 *)(param_1 + 0x68) = uVar6;
        if (bVar15) {
          uVar14 = (uint)(param_1 + 0x68U >> 0xc);
          uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
          do {
            uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
            LOCK();
            bVar15 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
            if (bVar15) {
              *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) = uVar2 | 1L << (uVar14 & 0x3f);
            }
            UNLOCK();
          } while (!bVar15);
        }
        uVar6 = *(undefined8 *)(param_1 + 0x28);
        uVar3 = *(undefined8 *)(param_1 + 0x48);
        uVar7 = FUN_1802c43a0(DAT_182d59900);
        bVar15 = false;
        ExposureUnnoticed2_Object3D_NPC_Script_NpcComponentAccessor___ctor__06001037
                  (uVar7,param_1,uVar6,uVar3,param_2,0);
        *(undefined8 *)(param_1 + 0x30) = uVar7;
        FUN_18031d480(param_1 + 0x30);
        if (*(longlong *)(param_1 + 0x30) != 0) {
          ExposureUnnoticed2_Object3D_NPC_Script_NpcComponentAccessor__Initialize__06001038
                    (*(longlong *)(param_1 + 0x30),0);
          if (*(longlong *)(param_1 + 0x30) != 0) {
            lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x28);
            uVar5 = FUN_181f37380(0,100,0);
            if (lVar9 != 0) {
              pcVar8 = DAT_182ebeea8;
              if ((DAT_182ebeea8 == (code *)0x0) &&
                 (pcVar8 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.AI.NavMeshAgent::set_avoidancePriority(System.Int32)"
                                                ), pcVar8 == (code *)0x0)) {
                uVar6 = FUN_1802ced60(
                                     "UnityEngine.AI.NavMeshAgent::set_avoidancePriority(System.Int32)"
                                     );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar6,0);
              }
              DAT_182ebeea8 = pcVar8;
              (*DAT_182ebeea8)(lVar9,uVar5);
              if ((*(longlong *)(param_1 + 0x30) != 0) &&
                 (lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x98), lVar9 != 0)) {
                *(undefined8 *)(lVar9 + 0x20) = *(undefined8 *)(param_1 + 0x30);
                FUN_18031d480(lVar9 + 0x20);
                lVar9 = *(longlong *)(param_1 + 0x50);
                uVar6 = *(undefined8 *)(param_1 + 0x30);
                if (lVar9 != 0) {
                  *(longlong *)(lVar9 + 0x18) = param_1;
                  FUN_18031d480(lVar9 + 0x18);
                  *(undefined8 *)(lVar9 + 0x20) = uVar6;
                  FUN_18031d480(lVar9 + 0x20);
                  if (*(longlong *)(param_1 + 0x58) != 0) {
                    ExposureUnnoticed2_Object3D_NPC_Script_NpcFadeOutState__Initialize__060010ec
                              (*(longlong *)(param_1 + 0x58),*(undefined8 *)(param_1 + 0x30),0);
                    lVar9 = *(longlong *)(param_1 + 0x60);
                    if (lVar9 != 0) {
                      bVar16 = DAT_182eb5d50 != 0;
                      *(undefined8 *)(lVar9 + 0x10) = *(undefined8 *)(param_1 + 0x30);
                      if (bVar16) {
                        uVar14 = (uint)(lVar9 + 0x10U >> 0xc);
                        uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                        do {
                          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
                          LOCK();
                          bVar16 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
                          if (bVar16) {
                            *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) =
                                 uVar2 | 1L << (uVar14 & 0x3f);
                          }
                          UNLOCK();
                        } while (!bVar16);
                      }
                      lVar9 = *(longlong *)(param_1 + 0x30);
                      if ((lVar9 != 0) && (*(longlong *)(lVar9 + 0x48) != 0)) {
                        ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__InitializeForNpc__06000c14
                                  (*(longlong *)(lVar9 + 0x48),lVar9,0);
                        if (*(longlong *)(param_1 + 0x30) != 0) {
                          lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40);
                          fVar17 = (float)FUN_181f373e0(0);
                          if (lVar9 != 0) {
                            *(float *)(lVar9 + 0x2c) = (fVar17 * 0.4 + 1.0) - 0.3;
                            if (*(longlong *)(param_1 + 0x30) != 0) {
                              lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40);
                              bVar16 = false;
                              if (param_5 == 0) {
                                fVar17 = (float)FUN_181f373e0(0);
                                bVar16 = fVar17 <= 0.1;
                              }
                              if (lVar9 != 0) {
                                *(bool *)(lVar9 + 200) = bVar16;
                                if (*(longlong *)(param_1 + 0x30) != 0) {
                                  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40);
                                  uVar5 = FUN_181f37310(0x3ecccccd,0x3f333333,0);
                                  if (lVar9 != 0) {
                                    *(undefined4 *)(lVar9 + 0xcc) = uVar5;
                                    if (*(longlong *)(param_1 + 0x30) != 0) {
                                      lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40);
                                      uVar5 = FUN_181f37310(0x3e99999a,0x3f000000,0);
                                      if (lVar9 != 0) {
                                        *(undefined4 *)(lVar9 + 0xd0) = uVar5;
                                        if ((*(longlong *)(param_1 + 0x30) != 0) &&
                                           (lVar9 = *(longlong *)
                                                     (*(longlong *)(param_1 + 0x30) + 0x60),
                                           lVar9 != 0)) {
                                          lVar9 = *(longlong *)(lVar9 + 0x10);
                                          uVar5 = FUN_181f37310(0x3dcccccd,0x3ecccccd,0);
                                          if (lVar9 != 0) {
                                            *(undefined4 *)(lVar9 + 0x10) = uVar5;
                                            if (((*(longlong *)(param_1 + 0x30) != 0) &&
                                                (lVar9 = *(longlong *)
                                                          (*(longlong *)(param_1 + 0x30) + 0x50),
                                                lVar9 != 0)) &&
                                               (lVar9 = *(longlong *)(lVar9 + 0x60), lVar9 != 0)) {
                                              lVar9 = 
                                                  ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                                                            (lVar9,0);
                                              if (((*(longlong *)(param_1 + 0x30) != 0) &&
                                                  (lVar10 = *(longlong *)
                                                             (*(longlong *)(param_1 + 0x30) + 0x40),
                                                  lVar10 != 0)) && (lVar9 != 0)) {
                                                FUN_181f3ea80(lVar9,*(undefined1 *)(lVar10 + 200),0)
                                                ;
                                                if (((*(longlong *)(param_1 + 0x30) != 0) &&
                                                    (lVar9 = *(longlong *)
                                                              (*(longlong *)(param_1 + 0x30) + 0x50)
                                                    , lVar9 != 0)) &&
                                                   (lVar9 = *(longlong *)(lVar9 + 0x68), lVar9 != 0)
                                                   ) {
                                                  lVar10 = 
                                                  ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                                                            (lVar9,0);
                                                  lVar9 = *(longlong *)
                                                           (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                           0x48);
                                                  if (lVar9 != 0) {
                                                    if ((*(char *)(lVar9 + 0x20) == '\0') &&
                                                       (*(int *)(lVar9 + 0x10) != 0xb)) {
                                                      bVar15 = *(int *)(lVar9 + 0x10) != 7;
                                                    }
                                                    if (lVar10 != 0) {
                                                      FUN_181f3ea80(lVar10,bVar15,0);
                                                      lVar9 = *(longlong *)(param_1 + 0x30);
                                                      if (((lVar9 != 0) &&
                                                          (*(longlong *)(lVar9 + 0x40) != 0)) &&
                                                         (*(longlong *)(lVar9 + 0x90) != 0)) {
                                                        FUN_181eeaba0(*(longlong *)(lVar9 + 0x90),
                                                                      *(undefined4 *)
                                                                       (*(longlong *)(lVar9 + 0x40)
                                                                       + 0x2c),0);
                                                        lVar9 = *(longlong *)(param_1 + 0x30);
                                                        if (((lVar9 != 0) &&
                                                            (*(longlong *)(lVar9 + 0x48) != 0)) &&
                                                           (lVar10 = *(longlong *)(lVar9 + 0x68),
                                                           lVar10 != 0)) {
                                                          *(undefined8 *)(lVar10 + 0x80) =
                                                               *(undefined8 *)
                                                                (*(longlong *)(lVar9 + 0x48) + 0x10)
                                                          ;
                                                          FUN_18031d480(lVar10 + 0x80);
                                                          if ((*(longlong *)(lVar10 + 0x88) != 0) &&
                                                             (lVar9 = *(longlong *)
                                                                       (*(longlong *)(lVar10 + 0x88)
                                                                       + 0x40), lVar9 != 0)) {
                                                            *(float *)(lVar10 + 0x24) =
                                                                 *(float *)(lVar9 + 0x5c) *
                                                                 *(float *)(lVar10 + 0x24);
                                                            if ((*(longlong *)(param_1 + 0x30) != 0)
                                                               && (lVar9 = *(longlong *)
                                                                            (*(longlong *)
                                                                              (param_1 + 0x30) +
                                                                            0x40), lVar9 != 0)) {
                                                              *(undefined1 *)(lVar9 + 0xd4) = 1;
                                                              if (param_5 == 0) {
                                                                if (*(longlong *)(param_1 + 0x30) ==
                                                                    0) goto LAB_180427f8e;
                                                                lVar9 = *(longlong *)
                                                                         (*(longlong *)
                                                                           (param_1 + 0x30) + 0x40);
                                                                plVar4 = (longlong *)
                                                                         **(longlong **)
                                                                           (DAT_182d59908 + 0xb8);
                                                                lVar10 = *(longlong *)
                                                                          (*(longlong *)
                                                                            (param_1 + 0x30) + 0x40)
                                                                ;
                                                                if ((lVar10 == 0) ||
                                                                   (plVar4 == (longlong *)0x0))
                                                                goto LAB_180427f8e;
                                                                uVar6 = (**(code **)(*plVar4 + 0x198
                                                                                    ))(plVar4,*(
                                                  undefined1 *)(lVar10 + 0x22),
                                                  *(undefined8 *)(*plVar4 + 0x1a0));
                                                  *(undefined8 *)(lVar9 + 0x40) = uVar6;
                                                  FUN_18031d480(lVar9 + 0x40);
                                                  if (param_3 == 0) {
                                                    if (param_4 != '\0') {
                                                      if (((*(longlong *)(param_1 + 0x30) == 0) ||
                                                          (lVar9 = *(longlong *)
                                                                    (*(longlong *)(param_1 + 0x30) +
                                                                    0x40), lVar9 == 0)) ||
                                                         (lVar9 = *(longlong *)(lVar9 + 0x40),
                                                         lVar9 == 0)) goto LAB_180427f8e;
                                                                                                            
                                                  ExposureUnnoticed2_Object3D_RoutePoint_RouteData__ProceedRandom__06000b7f
                                                            (lVar9,0);
                                                  }
                                                  if ((((*(longlong *)(param_1 + 0x30) == 0) ||
                                                       (lVar9 = *(longlong *)
                                                                 (*(longlong *)(param_1 + 0x30) +
                                                                 0x40), lVar9 == 0)) ||
                                                      (lVar9 = *(longlong *)(lVar9 + 0x40),
                                                      lVar9 == 0)) ||
                                                     ((lVar9 = *(longlong *)(lVar9 + 0x10),
                                                      lVar9 == 0 ||
                                                      (lVar9 = FUN_181d769d0(lVar9,0), lVar9 == 0)))
                                                     ) goto LAB_180427f8e;
                                                  puVar11 = (undefined8 *)
                                                            FUN_181f4b9a0(&local_68,lVar9,0);
                                                  uVar6 = *puVar11;
                                                  uVar5 = *(undefined4 *)(puVar11 + 1);
                                                  puVar12 = (undefined4 *)
                                                            FUN_181f4c700(&local_58,lVar9,0);
                                                  local_58 = *puVar12;
                                                  uStack_54 = puVar12[1];
                                                  uStack_50 = puVar12[2];
                                                  uStack_4c = puVar12[3];
                                                  local_68 = uVar6;
                                                  local_60 = uVar5;
                                                  ExposureUnnoticed2_Object3D_NPC_Script_NpcController__Warp__06001062
                                                            (param_1,&local_68,&local_58,0);
                                                  if (((*(longlong *)(param_1 + 0x30) == 0) ||
                                                      ((lVar9 = *(longlong *)
                                                                 (*(longlong *)(param_1 + 0x30) +
                                                                 0x40), lVar9 == 0 ||
                                                       (lVar9 = *(longlong *)(lVar9 + 0x40),
                                                       lVar9 == 0)))) ||
                                                     (lVar9 = *(longlong *)(lVar9 + 0x10),
                                                     lVar9 == 0)) goto LAB_180427f8e;
                                                  if (*(int *)(lVar9 + 0x20) == 1) {
                                                    lVar9 = *(longlong *)
                                                             (*(longlong *)(param_1 + 0x30) + 0xd8);
                                                    if (lVar9 == 0) goto LAB_180427f8e;
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_NPC_Script_NpcSoundController__PlaySe__060010b5
                                                            (lVar9,0x35,0);
                                                  }
                                                  if ((((*(longlong *)(param_1 + 0x30) == 0) ||
                                                       (lVar9 = *(longlong *)
                                                                 (*(longlong *)(param_1 + 0x30) +
                                                                 0x40), lVar9 == 0)) ||
                                                      (lVar9 = *(longlong *)(lVar9 + 0x40),
                                                      lVar9 == 0)) ||
                                                     (lVar9 = *(longlong *)(lVar9 + 0x10),
                                                     lVar9 == 0)) goto LAB_180427f8e;
                                                  if (*(int *)(lVar9 + 0x20) == 4) {
                                                    lVar9 = *(longlong *)
                                                             (*(longlong *)(param_1 + 0x30) + 0xd8);
                                                    if (lVar9 == 0) goto LAB_180427f8e;
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_NPC_Script_NpcSoundController__PlaySe__060010b5
                                                            (lVar9,0x47,0);
                                                  }
                                                  if (((*(longlong *)(param_1 + 0x30) == 0) ||
                                                      (lVar9 = *(longlong *)
                                                                (*(longlong *)(param_1 + 0x30) +
                                                                0x40), lVar9 == 0)) ||
                                                     ((lVar9 = *(longlong *)(lVar9 + 0x40),
                                                      lVar9 == 0 ||
                                                      (lVar9 = *(longlong *)(lVar9 + 0x10),
                                                      lVar9 == 0)))) goto LAB_180427f8e;
                                                  if (*(int *)(lVar9 + 0x20) == 5) {
                                                    lVar9 = *(longlong *)
                                                             (*(longlong *)(param_1 + 0x30) + 0xd8);
                                                    if (lVar9 == 0) goto LAB_180427f8e;
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_NPC_Script_NpcSoundController__PlaySe__060010b5
                                                            (lVar9,0x47,0);
                                                  }
                                                  lVar9 = *(longlong *)
                                                           (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                           0x48);
                                                  if (lVar9 == 0) goto LAB_180427f8e;
                                                  if (*(int *)(lVar9 + 0x10) == 6) {
                                                    lVar9 = FUN_180436370();
                                                    if (lVar9 == 0) goto LAB_180427f8e;
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_ScenePlops_Conbini_ConbiniController__PlayEnterSoundIfInCondition__06000b17
                                                            (lVar9,0);
                                                  }
                                                  }
                                                  else {
                                                    local_58 = *(undefined4 *)(param_3 + 0x1c);
                                                    uStack_54 = *(undefined4 *)(param_3 + 0x20);
                                                    uStack_50 = *(undefined4 *)(param_3 + 0x24);
                                                    uStack_4c = *(undefined4 *)(param_3 + 0x28);
                                                    local_60 = *(undefined4 *)(param_3 + 0x18);
                                                    local_68 = *(undefined8 *)(param_3 + 0x10);
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_NPC_Script_NpcController__Warp__06001062
                                                            (param_1,&local_68,&local_58,0);
                                                  }
                                                  }
                                                  else if (param_5 == 10) {
                                                    if (*(longlong *)(param_1 + 0x30) == 0)
                                                    goto LAB_180427f8e;
                                                    lVar9 = *(longlong *)
                                                             (*(longlong *)(param_1 + 0x30) + 0x40);
                                                    plVar4 = (longlong *)
                                                             **(longlong **)(DAT_182d59908 + 0xb8);
                                                    if ((plVar4 == (longlong *)0x0) ||
                                                       (uVar6 = (**(code **)(*plVar4 + 0x1a8))
                                                                          (plVar4,*(undefined8 *)
                                                                                   (*plVar4 + 0x1b0)
                                                                          ), lVar9 == 0))
                                                    goto LAB_180427f8e;
                                                    *(undefined8 *)(lVar9 + 0x40) = uVar6;
                                                    FUN_18031d480(lVar9 + 0x40);
                                                    if ((*(longlong *)(param_1 + 0x30) == 0) ||
                                                       ((((lVar9 = *(longlong *)
                                                                    (*(longlong *)(param_1 + 0x30) +
                                                                    0x40), lVar9 == 0 ||
                                                          (lVar9 = *(longlong *)(lVar9 + 0x40),
                                                          lVar9 == 0)) ||
                                                         (lVar9 = *(longlong *)(lVar9 + 0x10),
                                                         lVar9 == 0)) ||
                                                        (lVar9 = FUN_181d769d0(lVar9,0), lVar9 == 0)
                                                        ))) goto LAB_180427f8e;
                                                    puVar11 = (undefined8 *)
                                                              FUN_181f4b9a0(&local_68,lVar9,0);
                                                    uVar6 = *puVar11;
                                                    uVar5 = *(undefined4 *)(puVar11 + 1);
                                                    puVar12 = (undefined4 *)
                                                              FUN_181f4c700(&local_58,lVar9,0);
                                                    local_58 = *puVar12;
                                                    uStack_54 = puVar12[1];
                                                    uStack_50 = puVar12[2];
                                                    uStack_4c = puVar12[3];
                                                    local_68 = uVar6;
                                                    local_60 = uVar5;
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_NPC_Script_NpcController__Warp__06001062
                                                            (param_1,&local_68,&local_58,0);
                                                  lVar9 = *(longlong *)
                                                           (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                           0x48);
                                                  if (lVar9 == 0) goto LAB_180427f8e;
                                                  if (*(int *)(lVar9 + 0x10) == 7) {
                                                    if (*(longlong *)(param_1 + 0x68) == 0)
                                                    goto LAB_180427f8e;
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_NPC_Script_State_NpcFashionClerkSubState__Initialize__06001118
                                                            (*(longlong *)(param_1 + 0x68),
                                                             *(undefined8 *)(param_1 + 0x30),0);
                                                  }
                                                  }
                                                  if ((*(longlong *)(param_1 + 0x30) != 0) &&
                                                     (lVar9 = *(longlong *)
                                                               (*(longlong *)(param_1 + 0x30) + 0x20
                                                               ), lVar9 != 0)) {
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__SetActiveNavAgent__0600107d
                                                            (lVar9,1,0);
                                                  lVar9 = *(longlong *)(param_1 + 0x48);
                                                  if (lVar9 != 0) {
                                                    lVar10 = *(longlong *)(lVar9 + 0x98);
                                                    if (*(longlong *)(lVar9 + 0x98) != 0) {
                                                      *(undefined4 *)
                                                       (*(longlong *)(lVar9 + 0x98) + 0x10) =
                                                           0x3f800000;
                                                      *(undefined4 *)(lVar10 + 0x1c) = 0x3f800000;
                                                      uVar6 = *(undefined8 *)(param_1 + 0x30);
                                                      if (*(int *)(DAT_182d598a0 + 0xe0) == 0) {
                                                        FUN_18035c820();
                                                      }
                                                      if (DAT_182eb7bd9 == '\0') {
                                                        FUN_1802f2810(&DAT_182d58238);
                                                        LOCK();
                                                        UNLOCK();
                                                        FUN_1802f2810(&DAT_182d61320);
                                                        LOCK();
                                                        UNLOCK();
                                                        FUN_1802f2810(&DAT_182d58380);
                                                        LOCK();
                                                        UNLOCK();
                                                        FUN_1802f2810(&DAT_182d54d90);
                                                        LOCK();
                                                        UNLOCK();
                                                        FUN_1802f2810(&DAT_182d53aa8);
                                                        LOCK();
                                                        UNLOCK();
                                                        DAT_182eb7bd9 = '\x01';
                                                      }
                                                      if (**(longlong **)(DAT_182d58238 + 0xb8) != 0
                                                         ) {
                                                        uVar3 = *(undefined8 *)
                                                                 (**(longlong **)
                                                                    (DAT_182d58238 + 0xb8) + 0x110);
                                                        if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
                                                          FUN_18035c820(DAT_182d58380);
                                                        }
                                                        if (**(longlong **)(DAT_182d58380 + 0xb8) !=
                                                            0) {
                                                          uVar7 = *(undefined8 *)
                                                                   (**(longlong **)
                                                                      (DAT_182d58380 + 0xb8) + 0xc0)
                                                          ;
                                                          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                                            FUN_18035c820();
                                                          }
                                                          lVar9 = FUN_1809f1050(uVar3,uVar7,
                                                                                DAT_182d54d90);
                                                          if ((lVar9 != 0) &&
                                                             (lVar9 = FUN_1809a08f0(lVar9,
                                                  DAT_182d61320), lVar9 != 0)) {
                                                                                                        
                                                  ExposureUnnoticed2_ObjectUI_NpcUi_NpcUiView__Initialize__0600192e
                                                            (lVar9,uVar6,0);
                                                  ExposureUnnoticed2_ObjectUI_InGame_NpcDirectIconPanel_NpcDirectionPanelView__Register__06001ae8
                                                            (param_1,0);
                                                  uVar6 = FUN_1802c43a0(DAT_182d58368);
                                                  FUN_1814df680(uVar6,param_1,DAT_182d598e0,0);
                                                  ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b
                                                            (uVar6,3,0);
                                                  uVar6 = FUN_1802c43a0(DAT_182d57c08);
                                                  FUN_180665bb0(uVar6,param_1,DAT_182d598e8,0);
                                                  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  FUN_180993250(uVar6,0,DAT_182d57bf8);
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
LAB_180427f8e:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

