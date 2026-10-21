// Ghidra pseudocode; not original source or compilable C.
// ev_97a5f467b5fe41a31191d90cc914342b543f98113597314c4fbdf3be62aa482e

void ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimatorFpsController__OnUpdate__06000fe4
               (longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  char cVar4;
  int iVar5;
  code *pcVar6;
  undefined8 uVar7;
  float fVar8;
  float fVar9;
  
  if (cRam0000000182eb7745 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb7745 = '\x01';
  }
  iVar5 = *(int *)(param_1 + 0x20) + 1;
  *(int *)(param_1 + 0x20) = iVar5;
  if (iVar5 < 3) {
    return;
  }
  if ((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
     (lVar1 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar1 != 0)) {
    uVar7 = *(undefined8 *)(lVar1 + 0x28);
    if (*(longlong *)(param_1 + 0x18) != 0) {
      uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x18);
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      fVar8 = (float)ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DistSqrt__06001726
                               (uVar7,uVar2,0);
      lVar1 = *(longlong *)(param_1 + 0x28);
      if (lVar1 != 0) {
        if ((float)*(int *)(lVar1 + 0x10) < fVar8) {
          if (lVar1 != 0) {
            if ((float)*(int *)(lVar1 + 0x14) <= fVar8) {
              if ((float)*(int *)(lVar1 + 0x1c) <= fVar8) {
                if (lVar1 == 0) goto code_r0x00018041eea4;
                if ((float)*(int *)(lVar1 + 0x24) <= fVar8) {
                  iVar5 = *(int *)(lVar1 + 0x2c);
                }
                else {
                  iVar5 = *(int *)(lVar1 + 0x28);
                }
              }
              else {
                iVar5 = *(int *)(lVar1 + 0x20);
              }
            }
            else {
              iVar5 = *(int *)(lVar1 + 0x18);
            }
            if (((*(longlong *)(param_1 + 0x18) != 0) &&
                (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0xc0), lVar1 != 0)) &&
               (lVar1 = *(longlong *)(lVar1 + 0x20), lVar1 != 0)) {
              pcVar6 = DAT_182ec1148;
              if ((DAT_182ec1148 == (code *)0x0) &&
                 (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_activeInHierarchy()"),
                 pcVar6 == (code *)0x0)) {
                uVar7 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar7,0);
              }
              DAT_182ec1148 = pcVar6;
              cVar4 = (*DAT_182ec1148)(lVar1);
              if (cVar4 == '\0') {
                iVar5 = 2;
              }
              lVar1 = *(longlong *)(param_1 + 0x10);
              if (lVar1 != 0) {
                if (iVar5 != -1) {
                  *(int *)(lVar1 + 0x14) = iVar5;
                  *(float *)(lVar1 + 0x20) = 1.0 / (float)iVar5;
                }
                if (*(char *)(lVar1 + 0x10) == '\0') {
                  lVar3 = *(longlong *)(lVar1 + 0x18);
                  *(undefined1 *)(lVar1 + 0x10) = 1;
                  if (lVar3 == 0) goto code_r0x00018041eea4;
                  pcVar6 = DAT_182ec1060;
                  if ((DAT_182ec1060 == (code *)0x0) &&
                     (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Behaviour::set_enabled(System.Boolean)"
                                                  ), pcVar6 == (code *)0x0)) {
                    uVar7 = FUN_1802ced60("UnityEngine.Behaviour::set_enabled(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar7,0);
                  }
                  DAT_182ec1060 = pcVar6;
                  (*DAT_182ec1060)(lVar3,0);
                  *(undefined4 *)(lVar1 + 0x24) = 0;
                  *(float *)(lVar1 + 0x20) = 1.0 / (float)*(int *)(lVar1 + 0x14);
                }
                lVar1 = *(longlong *)(param_1 + 0x10);
                if (lVar1 != 0) {
                  if (*(char *)(lVar1 + 0x10) == '\0') {
                    return;
                  }
                  fVar8 = *(float *)(lVar1 + 0x24);
                  pcVar6 = DAT_182ec14d0;
                  if ((DAT_182ec14d0 == (code *)0x0) &&
                     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"),
                     pcVar6 == (code *)0x0)) {
                    uVar7 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar7,0);
                  }
                  DAT_182ec14d0 = pcVar6;
                  fVar9 = (float)(*DAT_182ec14d0)();
                  fVar9 = fVar9 + fVar8;
                  *(float *)(lVar1 + 0x24) = fVar9;
                  if (fVar9 < *(float *)(lVar1 + 0x20)) {
                    return;
                  }
                  lVar3 = *(longlong *)(lVar1 + 0x18);
                  if (lVar3 != 0) {
                    pcVar6 = pcRam0000000182ebf378;
                    if ((pcRam0000000182ebf378 == (code *)0x0) &&
                       (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Animator::Update(System.Single)"
                                                      ), pcVar6 == (code *)0x0)) {
                      uVar7 = FUN_1802ced60("UnityEngine.Animator::Update(System.Single)");
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar7,0);
                    }
                    pcRam0000000182ebf378 = pcVar6;
                    (*pcRam0000000182ebf378)(lVar3);
                    *(undefined4 *)(lVar1 + 0x24) = 0;
                    return;
                  }
                }
              }
            }
          }
        }
        else {
          lVar1 = *(longlong *)(param_1 + 0x10);
          if (lVar1 != 0) {
            if (*(char *)(lVar1 + 0x10) != '\0') {
              lVar3 = *(longlong *)(lVar1 + 0x18);
              *(undefined1 *)(lVar1 + 0x10) = 0;
              if (lVar3 == 0) goto code_r0x00018041eea4;
              pcVar6 = DAT_182ec1060;
              if ((DAT_182ec1060 == (code *)0x0) &&
                 (pcVar6 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.Behaviour::set_enabled(System.Boolean)"
                                                ), pcVar6 == (code *)0x0)) {
                uVar7 = FUN_1802ced60("UnityEngine.Behaviour::set_enabled(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar7,0);
              }
              DAT_182ec1060 = pcVar6;
              (*DAT_182ec1060)(lVar3,1);
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

