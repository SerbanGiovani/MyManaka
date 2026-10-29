// Ghidra pseudocode; not original source or compilable C.
// ev_abdca8586e6468bf4c612f01b06b236b507c95c46833ee0e4a0480e23f0976ff

void ExposureUnnoticed2_Master_Item_MItem__UseItemProcess__0600127e(longlong param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined8 uVar9;
  longlong lVar10;
  longlong *plVar11;
  float fVar12;
  
  if (cRam0000000182eb7864 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c3f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c3e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c3e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c3d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c3d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c3c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c3c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c3b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c3b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c3a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c3a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c398);
    LOCK();
    UNLOCK();
    cRam0000000182eb7864 = '\x01';
  }
  if (param_1 == 0) goto code_r0x000180468b35;
  iVar2 = *(int *)(param_1 + 0x18);
  uVar6 = uRam0000000182d5c3c0;
  switch(iVar2) {
  case 0:
    if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
        (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 == 0)) ||
       (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 == 0)) goto code_r0x000180468b35;
    uVar6 = uRam0000000182d5c3b8;
    if (*(char *)(lVar7 + 0x1c) == '\0') {
      ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551
                (*(undefined4 *)(param_1 + 0x18),0xffffffff,0);
      if (((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
          (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar7 != 0)) &&
         (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 != 0)) {
        *(undefined4 *)(lVar7 + 0x234) = 0x271c;
        lVar7 = **(longlong **)(DAT_182d58230 + 0xb8);
        lVar5 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
        if ((lVar5 != 0) && (fVar12 = *(float *)(lVar5 + 0x19c), lVar7 != 0)) {
          if (cRam0000000182eb83fb == '\0') {
            FUN_1802f2810(&DAT_182d58398);
            LOCK();
            UNLOCK();
            cRam0000000182eb83fb = '\x01';
          }
          lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar7 != 0) {
            *(float *)(lVar7 + 0x174) = fVar12 + *(float *)(lVar7 + 0x174);
            return;
          }
        }
      }
      goto code_r0x000180468b35;
    }
    break;
  case 1:
    if (cRam0000000182eb54a0 == '\0') {
      FUN_1802f2810(0x182d5bca8);
      LOCK();
      UNLOCK();
      cRam0000000182eb54a0 = '\x01';
    }
    lVar7 = **(longlong **)(lRam0000000182d5bca8 + 0xb8);
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
    if (lVar7 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar7 + 0x10) != 0) {
        if (cRam0000000182eb54a0 == '\0') {
          FUN_1802f2810(0x182d5bca8);
          LOCK();
          UNLOCK();
          cRam0000000182eb54a0 = '\x01';
        }
        if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
            (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 == 0)) ||
           (**(longlong **)(lRam0000000182d5bca8 + 0xb8) == 0)) goto code_r0x000180468b35;
        cVar4 = ExposureUnnoticed2_Object3D_ScenePlops_Escalator_EscalatorManager__IsPushed__06000ab4
                          (**(longlong **)(lRam0000000182d5bca8 + 0xb8),
                           *(undefined8 *)(lVar7 + 0x28),0);
        uVar6 = uRam0000000182d5c3b0;
        if (cVar4 != '\0') break;
      }
    }
    if (cRam0000000182eb7e62 == '\0') {
      FUN_1802f2810(&DAT_182d58238);
      LOCK();
      UNLOCK();
      FUN_1802f2810(0x182d654f0);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d58380);
      LOCK();
      UNLOCK();
      cRam0000000182eb7e62 = '\x01';
    }
    if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d58380);
    }
    if (((**(longlong **)(DAT_182d58238 + 0xb8) != 0) &&
        (**(longlong **)(DAT_182d58380 + 0xb8) != 0)) &&
       (plVar8 = (longlong *)
                 ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
                           (**(longlong **)(DAT_182d58380 + 0xb8),
                            *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x220),0,0),
       plVar8 != (longlong *)0x0)) {
      if ((*(byte *)(lRam0000000182d654f0 + 0x130) <= *(byte *)(*plVar8 + 0x130)) &&
         (lVar7 = *(longlong *)(*plVar8 + 200),
         *(longlong *)(lVar7 + -8 + (ulonglong)*(byte *)(lRam0000000182d654f0 + 0x130) * 8) ==
         lRam0000000182d654f0)) {
        plVar11 = (longlong *)0x0;
        if (*(longlong *)(lVar7 + -8 + (ulonglong)*(byte *)(lRam0000000182d654f0 + 0x130) * 8) ==
            lRam0000000182d654f0) {
          plVar11 = plVar8;
        }
        ExposureUnnoticed2_ObjectUI_ChooseDildoPanelView_ChooseDildoPanelView__ToPadModeIfNeed__06001d53
                  (plVar11,0);
        return;
      }
    }
    goto code_r0x000180468b35;
  case 2:
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar7 == 0) goto code_r0x000180468b35;
    if (*(char *)(lVar7 + 0x1dd) == '\0') {
      ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551
                (*(undefined4 *)(param_1 + 0x18),0xffffffff,0);
      if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
          (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 != 0)) &&
         (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 != 0)) {
        *(undefined4 *)(lVar7 + 0x228) = 2;
        if (((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
            (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar7 != 0)) &&
           (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 != 0)) {
          *(undefined4 *)(lVar7 + 0x234) = 5;
          return;
        }
      }
      goto code_r0x000180468b35;
    }
    break;
  case 3:
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar7 == 0) goto code_r0x000180468b35;
    uVar6 = uRam0000000182d5c398;
    if (*(char *)(lVar7 + 0x1dc) == '\0') {
      if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
          (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 != 0)) &&
         (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 != 0)) {
        *(undefined4 *)(lVar7 + 0x228) = 3;
        if (((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
            (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar7 != 0)) &&
           (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 != 0)) {
          *(undefined4 *)(lVar7 + 0x234) = 5;
          return;
        }
      }
      goto code_r0x000180468b35;
    }
    break;
  case 4:
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar7 == 0) goto code_r0x000180468b35;
    uVar6 = uRam0000000182d5c3a0;
    if (*(char *)(lVar7 + 0x1dc) != '\0') {
      if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
          (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 != 0)) &&
         (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 != 0)) {
        *(undefined4 *)(lVar7 + 0x228) = 4;
        if (((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
            (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar7 != 0)) &&
           (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 != 0)) {
          *(undefined4 *)(lVar7 + 0x234) = 5;
          return;
        }
      }
      goto code_r0x000180468b35;
    }
    break;
  case 5:
    if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
        (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 == 0)) ||
       (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 == 0)) goto code_r0x000180468b35;
    *(undefined4 *)(lVar7 + 0x228) = 5;
    if ((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
       (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 == 0))
    goto code_r0x000180468b35;
    lVar7 = *(longlong *)(lVar7 + 0x60);
    fVar12 = (float)FUN_181dc1970(0);
    if (lVar7 == 0) goto code_r0x000180468b35;
    *(float *)(lVar7 + 0x178) = fVar12 + 3.0;
    if (((**(longlong **)(DAT_182d58230 + 0xb8) == 0) ||
        (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar7 == 0)) ||
       (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 == 0)) goto code_r0x000180468b35;
    *(undefined4 *)(lVar7 + 0x234) = 0x2718;
    if ((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
       (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 == 0))
    goto code_r0x000180468b35;
    lVar7 = *(longlong *)(lVar7 + 0x60);
    if (*(int *)(lRam0000000182d5c3d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar5 = *(longlong *)(*(longlong *)(lRam0000000182d5c3d8 + 0xb8) + 8);
    if (lVar5 == 0) {
      if (*(int *)(lRam0000000182d5c3d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar6 = **(undefined8 **)(lRam0000000182d5c3d8 + 0xb8);
      lVar5 = FUN_1802c43a0(DAT_182d58368);
      FUN_1814df680(lVar5,uVar6,uRam0000000182d5c3f0,0);
      *(longlong *)(*(longlong *)(lRam0000000182d5c3d8 + 0xb8) + 8) = lVar5;
      lVar10 = *(longlong *)(lRam0000000182d5c3d8 + 0xb8) + 8;
code_r0x0001804682c6:
      FUN_18031d480(lVar10);
    }
    goto code_r0x0001804682cb;
  case 6:
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar7 == 0) goto code_r0x000180468b35;
    uVar6 = uRam0000000182d5c3a8;
    if (*(char *)(lVar7 + 0x1dd) != '\0') {
      ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551
                (*(undefined4 *)(param_1 + 0x18),0xffffffff,0);
      if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
          (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 != 0)) &&
         (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 != 0)) {
        *(undefined4 *)(lVar7 + 0x228) = 6;
        if (((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
            (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar7 != 0)) &&
           (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 != 0)) {
          *(undefined4 *)(lVar7 + 0x234) = 5;
          return;
        }
      }
      goto code_r0x000180468b35;
    }
    break;
  case 7:
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar7 == 0) goto code_r0x000180468b35;
    if (*(char *)(lVar7 + 0x1dd) == '\0') {
      if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
          (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 != 0)) &&
         (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 != 0)) {
        *(undefined4 *)(lVar7 + 0x228) = 7;
        if (((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
            (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar7 != 0)) &&
           (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 != 0)) {
          *(undefined4 *)(lVar7 + 0x234) = 5;
          return;
        }
      }
      goto code_r0x000180468b35;
    }
    break;
  case 8:
    if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
        (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 == 0)) ||
       (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 == 0)) goto code_r0x000180468b35;
    *(undefined4 *)(lVar7 + 0x228) = 8;
    if ((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
       (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 == 0))
    goto code_r0x000180468b35;
    lVar7 = *(longlong *)(lVar7 + 0x60);
    fVar12 = (float)FUN_181dc1970(0);
    if (lVar7 == 0) goto code_r0x000180468b35;
    *(float *)(lVar7 + 0x178) = fVar12 + 3.0;
    if (((**(longlong **)(DAT_182d58230 + 0xb8) == 0) ||
        (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar7 == 0)) ||
       (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 == 0)) goto code_r0x000180468b35;
    *(undefined4 *)(lVar7 + 0x234) = 0x2718;
    if ((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
       (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 == 0))
    goto code_r0x000180468b35;
    lVar7 = *(longlong *)(lVar7 + 0x60);
    if (*(int *)(lRam0000000182d5c3d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar5 = *(longlong *)(*(longlong *)(lRam0000000182d5c3d8 + 0xb8) + 0x10);
    if (lVar5 == 0) {
      if (*(int *)(lRam0000000182d5c3d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar6 = **(undefined8 **)(lRam0000000182d5c3d8 + 0xb8);
      lVar5 = FUN_1802c43a0(DAT_182d58368);
      FUN_1814df680(lVar5,uVar6,uRam0000000182d5c3e8,0);
      *(longlong *)(*(longlong *)(lRam0000000182d5c3d8 + 0xb8) + 0x10) = lVar5;
      lVar10 = *(longlong *)(lRam0000000182d5c3d8 + 0xb8) + 0x10;
      goto code_r0x0001804682c6;
    }
    goto code_r0x0001804682cb;
  case 9:
    if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
        (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 == 0)) ||
       (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 == 0)) goto code_r0x000180468b35;
    *(undefined4 *)(lVar7 + 0x228) = 9;
    if ((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
       (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 == 0))
    goto code_r0x000180468b35;
    lVar7 = *(longlong *)(lVar7 + 0x60);
    fVar12 = (float)FUN_181dc1970(0);
    if (lVar7 == 0) goto code_r0x000180468b35;
    *(float *)(lVar7 + 0x178) = fVar12 + 3.0;
    if (((**(longlong **)(DAT_182d58230 + 0xb8) == 0) ||
        (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar7 == 0)) ||
       (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 == 0)) goto code_r0x000180468b35;
    *(undefined4 *)(lVar7 + 0x234) = 0x2718;
    if ((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
       (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 == 0))
    goto code_r0x000180468b35;
    lVar7 = *(longlong *)(lVar7 + 0x60);
    if (*(int *)(lRam0000000182d5c3d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar5 = *(longlong *)(*(longlong *)(lRam0000000182d5c3d8 + 0xb8) + 0x18);
    if (lVar5 == 0) {
      if (*(int *)(lRam0000000182d5c3d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar6 = **(undefined8 **)(lRam0000000182d5c3d8 + 0xb8);
      lVar5 = FUN_1802c43a0(DAT_182d58368);
      FUN_1814df680(lVar5,uVar6,uRam0000000182d5c3e0,0);
      *(longlong *)(*(longlong *)(lRam0000000182d5c3d8 + 0xb8) + 0x18) = lVar5;
      lVar10 = *(longlong *)(lRam0000000182d5c3d8 + 0xb8) + 0x18;
      goto code_r0x0001804682c6;
    }
code_r0x0001804682cb:
    if (lVar7 != 0) {
      *(longlong *)(lVar7 + 0x170) = lVar5;
      FUN_18031d480(lVar7 + 0x170);
      return;
    }
code_r0x000180468b35:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  case -1:
    goto code_r0x000180468941;
  default:
    if (iVar2 == 10000) {
      return;
    }
    if (iVar2 == 0x2711) {
      return;
    }
    if (iVar2 != 0x2712) {
      if (iVar2 == 99999) {
code_r0x00018046893c:
        ExposureUnnoticed2_Scripts_InGame_GameStateFacade__RiseRp__06001531(0,0);
        return;
      }
      if (iVar2 == 100000) {
        if ((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
             (lVar7 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar7 != 0)) &&
            (lVar7 = *(longlong *)(lVar7 + 0x30), lVar7 != 0)) &&
           ((lVar7 = *(longlong *)(lVar7 + 0x40), lVar7 != 0 &&
            (lVar7 = *(longlong *)(lVar7 + 200), lVar7 != 0)))) {
          ExposureUnnoticed2_Object3D_Player_Scripts_MentalManager__RecoveryMental__06000c26
                    (lVar7,0);
          return;
        }
      }
      else {
        if (iVar2 == 0x186a1) goto code_r0x00018046893c;
        if (iVar2 == 0x186a2) {
          lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar7 != 0) {
            piVar1 = (int *)(lVar7 + 0x1e8);
            *piVar1 = *piVar1 + 1000;
            if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                (lVar7 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar7 != 0))
               && ((lVar7 = *(longlong *)(lVar7 + 0x30), lVar7 != 0 &&
                   (lVar7 = *(longlong *)(lVar7 + 0x40), lVar7 != 0)))) {
              lVar7 = *(longlong *)(lVar7 + 0x60);
              lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
              if ((lVar5 != 0) &&
                 (uVar6 = ExposureUnnoticed2_Master_Rank_MRank__CalcCurrentRank__06001261
                                    ((double)*(int *)(lVar5 + 0x1e8),0), lVar7 != 0)) {
                *(undefined8 *)(lVar7 + 0x128) = uVar6;
                FUN_18031d480(lVar7 + 0x128);
                return;
              }
            }
          }
        }
        else {
          if (iVar2 != 0x186a3) {
            uVar6 = thunk_FUN_1802f2810(&DAT_182d54bf8);
            uVar6 = thunk_FUN_1802c43a0(uVar6);
            FUN_1815c6ac0(uVar6,0);
            uVar9 = thunk_FUN_1802f2810(0x182d5c390);
                    /* WARNING: Subroutine does not return */
            FUN_18031da90(uVar6,uVar9);
          }
          lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar7 != 0) {
            piVar1 = (int *)(lVar7 + 0x1e8);
            *piVar1 = *piVar1 + 100;
            if ((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                 (lVar7 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar7 != 0))
                && (lVar7 = *(longlong *)(lVar7 + 0x30), lVar7 != 0)) &&
               (lVar7 = *(longlong *)(lVar7 + 0x40), lVar7 != 0)) {
              lVar7 = *(longlong *)(lVar7 + 0x60);
              lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
              if ((lVar5 != 0) &&
                 (uVar6 = ExposureUnnoticed2_Master_Rank_MRank__CalcCurrentRank__06001261
                                    ((double)*(int *)(lVar5 + 0x1e8),0), lVar7 != 0)) {
                *(undefined8 *)(lVar7 + 0x128) = uVar6;
                FUN_18031d480(lVar7 + 0x128);
                return;
              }
            }
          }
        }
      }
      goto code_r0x000180468b35;
    }
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar7 == 0) goto code_r0x000180468b35;
    uVar3 = *(undefined4 *)(lVar7 + 0x10);
    if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar7 = ExposureUnnoticed2_Master_Stage_MStage__Get__06001229(uVar3);
    if (lVar7 == 0) goto code_r0x000180468b35;
    uVar6 = uRam0000000182d5c3d0;
    if ((*(char *)(lVar7 + 0x58) != '\0') &&
       (cVar4 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsRelease__0600155e(0x6a),
       uVar6 = uRam0000000182d5c3c8, cVar4 != '\0')) {
      if (cRam0000000182eb7d2a == '\0') {
        FUN_1802f2810(&DAT_182d58238);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5bcb0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d58380);
        LOCK();
        UNLOCK();
        cRam0000000182eb7d2a = '\x01';
      }
      if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d58380);
      }
      if (((**(longlong **)(DAT_182d58238 + 0xb8) != 0) &&
          (**(longlong **)(DAT_182d58380 + 0xb8) != 0)) &&
         (plVar8 = (longlong *)
                   ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
                             (**(longlong **)(DAT_182d58380 + 0xb8),
                              *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x1c8),0,0),
         plVar8 != (longlong *)0x0)) {
        if ((*(byte *)(lRam0000000182d5bcb0 + 0x130) <= *(byte *)(*plVar8 + 0x130)) &&
           (lVar7 = *(longlong *)(*plVar8 + 200),
           *(longlong *)(lVar7 + -8 + (ulonglong)*(byte *)(lRam0000000182d5bcb0 + 0x130) * 8) ==
           lRam0000000182d5bcb0)) {
          plVar11 = (longlong *)0x0;
          if (*(longlong *)(lVar7 + -8 + (ulonglong)*(byte *)(lRam0000000182d5bcb0 + 0x130) * 8) ==
              lRam0000000182d5bcb0) {
            plVar11 = plVar8;
          }
          ExposureUnnoticed2_ObjectUI_DroneMissionPanel_DroneMissionPanelView__Initialize__06001b67
                    (plVar11,0);
          return;
        }
      }
      goto code_r0x000180468b35;
    }
  }
  uVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar6,0);
  ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14(uVar6,0,0);
code_r0x000180468941:
  return;
}

