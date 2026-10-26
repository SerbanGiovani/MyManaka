// Ghidra pseudocode; not original source or compilable C.
// ev_a4c45ef2de1cec3f9a29c6e7b29de61c241ebe9344c1f60f86702f459cee62a8

void ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__RepopNpc__06001098(longlong param_1)

{
  int iVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  char cVar5;
  longlong lVar6;
  longlong lVar7;
  undefined1 *puVar8;
  code *pcVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  uint uVar12;
  int iVar13;
  bool bVar14;
  float fVar15;
  undefined8 local_50;
  longlong *plStack_48;
  undefined8 uStack_40;
  longlong local_38;
  longlong lStack_30;
  longlong local_28;
  
  if (DAT_182eb776f == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59908);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59508);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d595a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59598);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59590);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59580);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182eb776f = '\x01';
  }
  lVar6 = *(longlong *)(param_1 + 0x38);
  if (lVar6 != 0) {
    if (DAT_182eb5d50 != 0) {
      uVar12 = (uint)((ulonglong)&local_50 >> 0xc);
      uVar11 = (ulonglong)((uVar12 & 0x1fffff) >> 6);
      do {
        uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
        LOCK();
        bVar14 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
        if (bVar14) {
          *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar3 | 1L << (uVar12 & 0x3f);
        }
        UNLOCK();
      } while (!bVar14);
    }
    iVar13 = 0;
    plStack_48 = (longlong *)((ulonglong)*(uint *)(lVar6 + 0x1c) << 0x20);
    uStack_40 = 0;
    lStack_30 = (longlong)plStack_48;
    local_28 = 0;
    local_50 = 0;
    plStack_48 = &local_38;
    local_38 = lVar6;
    while (cVar5 = FUN_180f72b70(&local_38,DAT_182d59598), cVar5 != '\0') {
      if (local_28 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      ExposureUnnoticed2_Object3D_NPC_Script_NpcController__Destroy__06001063(local_28,0);
    }
    lVar6 = *(longlong *)(param_1 + 0x38);
    if (lVar6 != 0) {
      *(int *)(lVar6 + 0x1c) = *(int *)(lVar6 + 0x1c) + 1;
      iVar1 = *(int *)(lVar6 + 0x18);
      *(undefined4 *)(lVar6 + 0x18) = 0;
      if (0 < iVar1) {
        FUN_181646f50(*(undefined8 *)(lVar6 + 0x10),0,iVar1,0);
      }
      if (*(longlong *)(param_1 + 0x40) != 0) {
        FUN_180e0d9c0(*(longlong *)(param_1 + 0x40),DAT_182d59508);
        *(undefined4 *)(param_1 + 0x6c) = 0;
        lVar6 = **(longlong **)(DAT_182d59908 + 0xb8);
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
        if (lVar6 != 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (*(longlong *)(lVar6 + 0x10) != 0) {
            if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
               (lVar6 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x40), lVar6 != 0)) {
              uVar2 = *(undefined4 *)(lVar6 + 0x20);
              if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              lVar6 = ExposureUnnoticed2_Master_Stage_MStage__Get__06001229(uVar2,0);
              *(longlong *)(param_1 + 0x70) = lVar6;
              if (DAT_182eb5d50 != 0) {
                uVar12 = (uint)(param_1 + 0x70U >> 0xc);
                uVar11 = (ulonglong)((uVar12 & 0x1fffff) >> 6);
                do {
                  uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                  LOCK();
                  bVar14 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                  if (bVar14) {
                    *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar3 | 1L << (uVar12 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar14);
              }
              iVar1 = DAT_182eb5d50;
              lVar7 = *(longlong *)(param_1 + 0x50);
              lVar4 = *(longlong *)(param_1 + 0x70);
              if (lVar7 != 0) {
                *(longlong *)(lVar7 + 0x10) = lVar4;
                if (iVar1 != 0) {
                  uVar12 = (uint)(lVar7 + 0x10U >> 0xc);
                  uVar11 = (ulonglong)((uVar12 & 0x1fffff) >> 6);
                  do {
                    uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                    LOCK();
                    bVar14 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                    if (bVar14) {
                      *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar3 | 1L << (uVar12 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar14);
                }
                if (lVar4 != 0) {
                  *(bool *)(lVar7 + 0x1e) = *(char *)(lVar4 + 0x3d) == '\0';
                  fVar15 = 1.0;
                  if (lVar6 != 0) {
                    if (*(int *)(lVar6 + 0x18) == 0xb) {
                      lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
                      if (lVar7 == 0) goto LAB_18042fdda;
                      fVar15 = (float)*(int *)(lVar7 + 0x2c) * 0.01;
                    }
                    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                    if (lVar7 != 0) {
                      if (*(char *)(lVar7 + 0x20) == '\0') {
                        fVar15 = (float)*(int *)(lVar6 + 0x38);
                      }
                      else {
                        fVar15 = (float)*(int *)(lVar6 + 0x34) * fVar15;
                      }
                      if (*(int *)(lVar7 + 0x34) != 2) {
                        fVar15 = fVar15 * 0.7;
                      }
                      if ((*(char *)(lVar6 + 0x3c) != '\0') && (*(char *)(lVar6 + 0x3d) == '\0')) {
                        return;
                      }
                      if ((int)fVar15 < 1) {
                        return;
                      }
                      while( true ) {
                        lVar7 = FUN_1802c43a0(DAT_182d58368);
                        lVar6 = DAT_182d594e0;
                        *(undefined8 *)(lVar7 + 0x10) = *(undefined8 *)(DAT_182d594e0 + 8);
                        *(longlong *)(lVar7 + 0x28) = lVar6;
                        *(longlong *)(lVar7 + 0x20) = param_1;
                        if (DAT_182eb5d50 != 0) {
                          uVar12 = (uint)(lVar7 + 0x20U >> 0xc);
                          uVar11 = (ulonglong)((uVar12 & 0x1fffff) >> 6);
                          do {
                            uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                            LOCK();
                            bVar14 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
                            if (bVar14) {
                              *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) =
                                   uVar3 | 1L << (uVar12 & 0x3f);
                            }
                            UNLOCK();
                          } while (!bVar14);
                        }
                        cVar5 = *(char *)(lVar6 + 0x52);
                        *(longlong *)(lVar7 + 0x40) = lVar7;
                        if (((*(byte *)(lVar6 + 0x4c) & 0x10) == 0) || (cVar5 != '\0')) {
                          *(undefined8 *)(lVar7 + 0x40) = *(undefined8 *)(lVar7 + 0x20);
                          puVar8 = *(undefined1 **)(lVar7 + 0x10);
                        }
                        else {
                          puVar8 = &LAB_1800c7840;
                        }
                        *(undefined1 **)(lVar7 + 0x18) = puVar8;
                        *(code **)(lVar7 + 0x38) = FUN_1801e91e0;
                        pcVar9 = DAT_182ec0fd8;
                        if ((DAT_182ec0fd8 == (code *)0x0) &&
                           (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.Random::get_value()"),
                           pcVar9 == (code *)0x0)) break;
                        DAT_182ec0fd8 = pcVar9;
                        (*DAT_182ec0fd8)();
                        ExposureUnnoticed2_Scripts_Base_Scheduler__DelayUnscaledTime__0600174c
                                  (lVar7);
                        iVar13 = iVar13 + 1;
                        if ((int)fVar15 <= iVar13) {
                          return;
                        }
                      }
                      uVar10 = FUN_1802ced60("UnityEngine.Random::get_value()");
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar10,0);
                    }
                  }
                }
              }
            }
            goto LAB_18042fdda;
          }
        }
        return;
      }
    }
  }
LAB_18042fdda:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

