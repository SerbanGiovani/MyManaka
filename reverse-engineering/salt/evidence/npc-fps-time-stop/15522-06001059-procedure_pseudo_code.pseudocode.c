// Ghidra pseudocode; not original source or compilable C.
// ev_5e523ca6f9429b7584c54b374ab07e0dd152c5e5c7c3a79c5923e4b9a7efc359

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__OnUpdateOnTimeStop__06001059
               (longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  int iVar6;
  code *pcVar7;
  undefined8 uVar8;
  float fVar9;
  float fVar10;
  
  if (*(longlong *)(param_1 + 0x58) != 0) {
    ExposureUnnoticed2_Object3D_NPC_Script_NpcFadeOutState__UpdateFadeIn__060010ef
              (*(longlong *)(param_1 + 0x58),0);
    if ((*(longlong *)(param_1 + 0x30) != 0) &&
       (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x88), lVar4 != 0)) {
      if (cRam0000000182eb7745 == '\0') {
        FUN_1802f2810(&DAT_182d58288,0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d58378);
        LOCK();
        UNLOCK();
        cRam0000000182eb7745 = '\x01';
      }
      iVar6 = *(int *)(lVar4 + 0x20) + 1;
      *(int *)(lVar4 + 0x20) = iVar6;
      if (iVar6 < 3) {
        return;
      }
      if ((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
         (lVar1 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar1 != 0)) {
        uVar8 = *(undefined8 *)(lVar1 + 0x28);
        if (*(longlong *)(lVar4 + 0x18) != 0) {
          uVar2 = *(undefined8 *)(*(longlong *)(lVar4 + 0x18) + 0x18);
          if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
            FUN_18035c820();
          }
          fVar9 = (float)ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DistSqrt__06001726
                                   (uVar8,uVar2,0);
          lVar1 = *(longlong *)(lVar4 + 0x28);
          if (lVar1 != 0) {
            if ((float)*(int *)(lVar1 + 0x10) < fVar9) {
              if (lVar1 != 0) {
                if ((float)*(int *)(lVar1 + 0x14) <= fVar9) {
                  if ((float)*(int *)(lVar1 + 0x1c) <= fVar9) {
                    if (lVar1 == 0) goto code_r0x00018041eea4;
                    if ((float)*(int *)(lVar1 + 0x24) <= fVar9) {
                      iVar6 = *(int *)(lVar1 + 0x2c);
                    }
                    else {
                      iVar6 = *(int *)(lVar1 + 0x28);
                    }
                  }
                  else {
                    iVar6 = *(int *)(lVar1 + 0x20);
                  }
                }
                else {
                  iVar6 = *(int *)(lVar1 + 0x18);
                }
                if (((*(longlong *)(lVar4 + 0x18) != 0) &&
                    (lVar1 = *(longlong *)(*(longlong *)(lVar4 + 0x18) + 0xc0), lVar1 != 0)) &&
                   (lVar1 = *(longlong *)(lVar1 + 0x20), lVar1 != 0)) {
                  pcVar7 = DAT_182ec1148;
                  if ((DAT_182ec1148 == (code *)0x0) &&
                     (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::get_activeInHierarchy()")
                     , pcVar7 == (code *)0x0)) {
                    uVar8 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar8,0);
                  }
                  DAT_182ec1148 = pcVar7;
                  cVar5 = (*DAT_182ec1148)(lVar1);
                  if (cVar5 == '\0') {
                    iVar6 = 2;
                  }
                  lVar1 = *(longlong *)(lVar4 + 0x10);
                  if (lVar1 != 0) {
                    if (iVar6 != -1) {
                      *(int *)(lVar1 + 0x14) = iVar6;
                      *(float *)(lVar1 + 0x20) = 1.0 / (float)iVar6;
                    }
                    if (*(char *)(lVar1 + 0x10) == '\0') {
                      lVar3 = *(longlong *)(lVar1 + 0x18);
                      *(undefined1 *)(lVar1 + 0x10) = 1;
                      if (lVar3 == 0) goto code_r0x00018041eea4;
                      pcVar7 = DAT_182ec1060;
                      if ((DAT_182ec1060 == (code *)0x0) &&
                         (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Behaviour::set_enabled(System.Boolean)"
                                                  ), pcVar7 == (code *)0x0)) {
                        uVar8 = FUN_1802ced60("UnityEngine.Behaviour::set_enabled(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar8,0);
                      }
                      DAT_182ec1060 = pcVar7;
                      (*DAT_182ec1060)(lVar3,0);
                      *(undefined4 *)(lVar1 + 0x24) = 0;
                      *(float *)(lVar1 + 0x20) = 1.0 / (float)*(int *)(lVar1 + 0x14);
                    }
                    lVar4 = *(longlong *)(lVar4 + 0x10);
                    if (lVar4 != 0) {
                      if (*(char *)(lVar4 + 0x10) == '\0') {
                        return;
                      }
                      fVar9 = *(float *)(lVar4 + 0x24);
                      pcVar7 = DAT_182ec14d0;
                      if ((DAT_182ec14d0 == (code *)0x0) &&
                         (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"),
                         pcVar7 == (code *)0x0)) {
                        uVar8 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar8,0);
                      }
                      DAT_182ec14d0 = pcVar7;
                      fVar10 = (float)(*DAT_182ec14d0)();
                      fVar10 = fVar10 + fVar9;
                      *(float *)(lVar4 + 0x24) = fVar10;
                      if (fVar10 < *(float *)(lVar4 + 0x20)) {
                        return;
                      }
                      lVar1 = *(longlong *)(lVar4 + 0x18);
                      if (lVar1 != 0) {
                        pcVar7 = pcRam0000000182ebf378;
                        if ((pcRam0000000182ebf378 == (code *)0x0) &&
                           (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::Update(System.Single)"),
                           pcVar7 == (code *)0x0)) {
                          uVar8 = FUN_1802ced60("UnityEngine.Animator::Update(System.Single)");
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar8,0);
                        }
                        pcRam0000000182ebf378 = pcVar7;
                        (*pcRam0000000182ebf378)(lVar1);
                        *(undefined4 *)(lVar4 + 0x24) = 0;
                        return;
                      }
                    }
                  }
                }
              }
            }
            else {
              lVar4 = *(longlong *)(lVar4 + 0x10);
              if (lVar4 != 0) {
                if (*(char *)(lVar4 + 0x10) != '\0') {
                  lVar1 = *(longlong *)(lVar4 + 0x18);
                  *(undefined1 *)(lVar4 + 0x10) = 0;
                  if (lVar1 == 0) goto code_r0x00018041eea4;
                  pcVar7 = DAT_182ec1060;
                  if ((DAT_182ec1060 == (code *)0x0) &&
                     (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Behaviour::set_enabled(System.Boolean)"
                                                  ), pcVar7 == (code *)0x0)) {
                    uVar8 = FUN_1802ced60("UnityEngine.Behaviour::set_enabled(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar8,0);
                  }
                  DAT_182ec1060 = pcVar7;
                  (*DAT_182ec1060)(lVar1,1);
                }
                return;
              }
            }
          }
        }
      }
code_r0x00018041eea4:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

