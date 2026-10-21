// Ghidra pseudocode; not original source or compilable C.
// ev_8672bf7b859e764fc7220c5e288f83ebf6fc8025ed1d8bf575b7e879dd598d79

longlong ExposureUnnoticed2_Object3D_Player_Scripts_InputResolver__Resolve__06000c0c
                   (longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  ulonglong *puVar7;
  undefined8 uVar8;
  bool bVar9;
  float fVar10;
  float fVar11;
  undefined4 uVar12;
  float fVar13;
  undefined4 uStackX_8;
  undefined4 uStackX_c;
  undefined8 uStack_78;
  float fStack_70;
  undefined1 auStack_68 [96];
  
  if (cRam0000000182eb8356 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb8356 = '\x01';
  }
  lVar2 = *(longlong *)(param_1 + 0x20);
  uStack_78 = 0;
  fStack_70 = 0.0;
  if (lVar2 != 0) {
    if (DAT_182eb5480 == '\0') {
      FUN_1802f2810(&DAT_182d522a8);
      LOCK();
      UNLOCK();
      DAT_182eb5480 = '\x01';
    }
    bVar9 = DAT_182eb5482 == '\0';
    uVar12 = *(undefined4 *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
    *(undefined8 *)(lVar2 + 0x10) = **(undefined8 **)(DAT_182d522a8 + 0xb8);
    *(undefined4 *)(lVar2 + 0x18) = uVar12;
    if (bVar9) {
      FUN_1802f2810(&DAT_182d549c8);
      LOCK();
      UNLOCK();
      DAT_182eb5482 = '\x01';
    }
    uVar12 = (*(undefined4 **)(DAT_182d549c8 + 0xb8))[1];
    *(undefined4 *)(lVar2 + 0x1c) = **(undefined4 **)(DAT_182d549c8 + 0xb8);
    bVar9 = false;
    *(undefined4 *)(lVar2 + 0x4c) = 0;
    *(undefined4 *)(lVar2 + 0x20) = uVar12;
    *(undefined2 *)(lVar2 + 0x3c) = 0;
    *(undefined4 *)(lVar2 + 0x28) = 0;
    *(undefined4 *)(lVar2 + 0x3f) = 0;
    *(undefined8 *)(lVar2 + 0x2f) = 0;
    *(undefined1 *)(lVar2 + 0x3e) = 0;
    *(undefined2 *)(lVar2 + 0x39) = 0;
    *(undefined1 *)(lVar2 + 0x38) = 0;
    *(undefined2 *)(lVar2 + 0x2d) = 0;
    *(undefined2 *)(lVar2 + 0x26) = 0;
    *(undefined1 *)(lVar2 + 0x24) = 0;
    lVar2 = *(longlong *)(param_1 + 0x20);
    if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (**(longlong **)(DAT_182d58380 + 0xb8) != 0) {
      if (*(char *)(**(longlong **)(DAT_182d58380 + 0xb8) + 0x21) == '\0') {
        if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (**(longlong **)(DAT_182d58380 + 0xb8) == 0) goto code_r0x000180621028;
        if (*(char *)(**(longlong **)(DAT_182d58380 + 0xb8) + 0x20) == '\0') {
          if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
             (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar3 == 0))
          goto code_r0x000180621028;
          if ((*(char *)(lVar3 + 0x11) == '\0') &&
             (*(char *)(*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30) + 0x13) == '\0')
             ) {
            if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
              FUN_18035c820();
            }
            puVar7 = (ulonglong *)
                     ExposureUnnoticed2_Scripts_Base_InputManager__GetVector3__06001703
                               (auStack_68,0,0);
            uVar1 = *puVar7;
            fVar13 = *(float *)(puVar7 + 1);
            uStack_78 = uVar1 & 0xffffffff;
            fStack_70 = fVar13;
            fVar10 = (float)FUN_1803d4630(&uStack_78);
            fVar11 = (float)uVar1;
            uVar12 = 0;
            if (0.5 <= fVar10) {
              uStack_78 = uVar1 & 0xffffffff;
              fStack_70 = fVar13;
              fVar11 = (float)FUN_1803d4d00(&uStack_78);
              if (1e-05 < fVar11) {
                fVar13 = fVar13 / fVar11;
                uStack_78 = CONCAT44(0.0 / fVar11,(float)uVar1 / fVar11);
              }
              else {
                if (DAT_182eb5480 == '\0') {
                  FUN_1802f2810(&DAT_182d522a8);
                  LOCK();
                  UNLOCK();
                  DAT_182eb5480 = '\x01';
                }
                uStack_78 = **(ulonglong **)(DAT_182d522a8 + 0xb8);
                fVar13 = *(float *)(*(ulonglong **)(DAT_182d522a8 + 0xb8) + 1);
              }
              fVar11 = (float)uStack_78;
              uVar12 = uStack_78._4_4_;
            }
            if (lVar2 != 0) {
              *(ulonglong *)(lVar2 + 0x10) = CONCAT44(uVar12,fVar11);
              *(float *)(lVar2 + 0x18) = fVar13;
              if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
                FUN_18035c820();
              }
              uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x21,0);
              *(undefined1 *)(lVar2 + 0x28) = uVar4;
              cVar5 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x22,0);
              if (cVar5 == '\0') {
                if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(5,0);
                *(undefined1 *)(lVar2 + 0x29) = uVar4;
                uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0xc,0);
                *(undefined1 *)(lVar2 + 0x2b) = uVar4;
                uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(7,0);
                *(undefined1 *)(lVar2 + 0x27) = uVar4;
                uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(3,0);
                *(undefined1 *)(lVar2 + 0x26) = uVar4;
                uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(6,0);
                *(undefined1 *)(lVar2 + 0x2a) = uVar4;
                uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(4,0);
                *(undefined1 *)(lVar2 + 0x2d) = uVar4;
              }
              if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
                FUN_18035c820();
              }
              uVar8 = ExposureUnnoticed2_Scripts_Base_InputManager__GetVector2__06001704(1,0);
              uStackX_8 = (undefined4)uVar8;
              uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
              *(undefined4 *)(lVar2 + 0x1c) = uStackX_8;
              *(undefined4 *)(lVar2 + 0x20) = uStackX_c;
              uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(10,0);
              *(undefined1 *)(lVar2 + 0x37) = uVar4;
              uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__GetLongDown__06001709(0xe,10,0);
              *(undefined1 *)(lVar2 + 0x43) = uVar4;
              uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__GetLongDown__06001709(0x17,10,0)
              ;
              *(undefined1 *)(lVar2 + 0x44) = uVar4;
              uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0xf,0);
              *(undefined1 *)(lVar2 + 0x3b) = uVar4;
              uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x10,0);
              *(undefined1 *)(lVar2 + 0x45) = uVar4;
              uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x14,0);
              *(undefined1 *)(lVar2 + 0x46) = uVar4;
              uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x15,0);
              *(undefined1 *)(lVar2 + 0x47) = uVar4;
              uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x16,0);
              *(undefined1 *)(lVar2 + 0x48) = uVar4;
              uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f4,0);
              *(undefined1 *)(lVar2 + 0x3c) = uVar4;
              uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f8,0);
              *(undefined1 *)(lVar2 + 0x3d) = uVar4;
              if (**(int **)(lRam0000000182d62238 + 0xb8) != 0) {
                if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                cVar5 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x22,0);
                if ((cVar5 == '\0') ||
                   (*(char *)(*(longlong *)(lRam0000000182d62238 + 0xb8) + 4) != '\0')) {
                  switch(**(undefined4 **)(lRam0000000182d62238 + 0xb8)) {
                  case 1:
                    *(undefined1 *)(lVar2 + 0x38) = 1;
                    break;
                  case 2:
                    *(undefined1 *)(lVar2 + 0x39) = 1;
                    break;
                  case 3:
                    *(undefined1 *)(lVar2 + 0x3a) = 1;
                    break;
                  case 4:
                    *(undefined1 *)(lVar2 + 0x3e) = 1;
                    break;
                  case 5:
                    *(undefined1 *)(lVar2 + 0x31) = 1;
                    break;
                  case 6:
                    *(undefined1 *)(lVar2 + 0x32) = 1;
                    break;
                  case 7:
                    *(undefined1 *)(lVar2 + 0x33) = 1;
                    break;
                  case 8:
                    *(undefined1 *)(lVar2 + 0x35) = 1;
                    break;
                  case 9:
                    *(undefined1 *)(lVar2 + 0x34) = 1;
                    break;
                  case 10:
                    *(undefined1 *)(lVar2 + 0x36) = 1;
                    break;
                  case 0xb:
                    *(undefined1 *)(lVar2 + 0x3f) = 1;
                    break;
                  case 0xc:
                    *(undefined1 *)(lVar2 + 0x40) = 1;
                    break;
                  case 0xd:
                    *(undefined1 *)(lVar2 + 0x41) = 1;
                    break;
                  case 0xe:
                    *(undefined1 *)(lVar2 + 0x42) = 1;
                  }
                  if (9999 < **(int **)(lRam0000000182d62238 + 0xb8)) {
                    *(int *)(lVar2 + 0x4c) = **(int **)(lRam0000000182d62238 + 0xb8);
                  }
                }
                **(undefined4 **)(lRam0000000182d62238 + 0xb8) = 0;
              }
              if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
                FUN_18035c820(DAT_182d58380);
              }
              lVar3 = **(longlong **)(DAT_182d58380 + 0xb8);
              if (lVar3 != 0) {
                if ((*(char *)(lVar3 + 0x22) == '\0') && (*(char *)(lVar3 + 0x21) == '\0')) {
                  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  cVar5 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x22,0);
                  if (cVar5 == '\0') {
                    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
                      FUN_18035c820();
                    }
                    uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(8,0)
                    ;
                    *(undefined1 *)(lVar2 + 0x30) = uVar4;
                    uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(8,0);
                    *(undefined1 *)(lVar2 + 0x2f) = uVar4;
                  }
                }
                cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                                  (0x12,0);
                if (cVar5 != '\0') {
                  if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180621028;
                  iVar6 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                                    (**(longlong **)(DAT_182d58230 + 0xb8),0);
                  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  if (iVar6 != 1) {
                    *(undefined1 *)(lVar2 + 0x26) = 0;
                  }
                }
                if (*(float *)(param_1 + 0x10) * *(float *)(param_1 + 0x10) +
                    *(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x14) +
                    *(float *)(param_1 + 0x18) * *(float *)(param_1 + 0x18) <= 0.0) {
                  bVar9 = 0.0 < *(float *)(lVar2 + 0x10) * *(float *)(lVar2 + 0x10) +
                                *(float *)(lVar2 + 0x14) * *(float *)(lVar2 + 0x14) +
                                *(float *)(lVar2 + 0x18) * *(float *)(lVar2 + 0x18);
                }
                *(bool *)(lVar2 + 0x2e) = bVar9;
                uVar12 = *(undefined4 *)(lVar2 + 0x18);
                *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(lVar2 + 0x10);
                *(undefined4 *)(param_1 + 0x18) = uVar12;
                return lVar2;
              }
            }
            goto code_r0x000180621028;
          }
        }
      }
      if (DAT_182eb5493 == '\0') {
        FUN_1802f2810(&DAT_182d592c0);
        LOCK();
        UNLOCK();
        DAT_182eb5493 = '\x01';
      }
      if (**(longlong **)(DAT_182d592c0 + 0xb8) != 0) {
        if (*(char *)(**(longlong **)(DAT_182d592c0 + 0xb8) + 0x10) != '\0') {
          if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
            FUN_18035c820();
          }
          uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(6,0);
          if (lVar2 == 0) goto code_r0x000180621028;
          *(undefined1 *)(lVar2 + 0x2a) = uVar4;
          cVar5 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x22,0);
          if (cVar5 == '\0') {
            if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(4,0);
            *(undefined1 *)(lVar2 + 0x2d) = uVar4;
            uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(5,0);
            *(undefined1 *)(lVar2 + 0x29) = uVar4;
            uVar4 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0xc,0);
            *(undefined1 *)(lVar2 + 0x2b) = uVar4;
          }
        }
        **(undefined4 **)(lRam0000000182d62238 + 0xb8) = 0;
        return lVar2;
      }
    }
  }
code_r0x000180621028:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

