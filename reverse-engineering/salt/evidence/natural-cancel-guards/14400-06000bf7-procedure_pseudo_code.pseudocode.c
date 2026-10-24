// Ghidra pseudocode; not original source or compilable C.
// ev_401f19adb0940d332ccb72575451503f1d5dea0c2981da24b1eea15f288f3d12

void ExposureUnnoticed2_Object3D_Portal_PortalController__Update__06000bf7(longlong param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  longlong lVar5;
  undefined8 uVar6;
  bool bVar7;
  float fVar8;
  undefined4 uVar9;
  
  if (*(char *)(param_1 + 0x50) == '\0') {
    pcVar4 = DAT_182ec14c0;
    if ((DAT_182ec14c0 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar4 == (code *)0x0)) {
      uVar6 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar6,0);
    }
    DAT_182ec14c0 = pcVar4;
    fVar8 = (float)(*DAT_182ec14c0)();
    if (1.0 <= fVar8 - *(float *)(param_1 + 0x4c)) {
      pcVar4 = DAT_182ec14c0;
      if ((DAT_182ec14c0 == (code *)0x0) &&
         (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar4 == (code *)0x0)) {
        uVar6 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
      DAT_182ec14c0 = pcVar4;
      uVar9 = (*DAT_182ec14c0)();
      *(undefined4 *)(param_1 + 0x4c) = uVar9;
      if (DAT_182eb8347 == '\0') {
        FUN_1802f2810(&DAT_182d58398,0,0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d594e8);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d58378);
        LOCK();
        UNLOCK();
        DAT_182eb8347 = '\x01';
      }
      uVar9 = *(undefined4 *)(param_1 + 0x20);
      if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar5 = ExposureUnnoticed2_Master_Stage_MStage__Get__06001229(uVar9,0);
      if ((((lVar5 != 0) && (**(longlong **)(DAT_182d58378 + 0xb8) != 0)) &&
          (lVar3 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar3 != 0)) &&
         ((lVar3 = *(longlong *)(lVar3 + 0x60), lVar3 != 0 &&
          (lVar3 = *(longlong *)(lVar3 + 0x128), lVar3 != 0)))) {
        iVar1 = *(int *)(lVar3 + 0x18);
        iVar2 = *(int *)(lVar5 + 0x54);
        *(bool *)(param_1 + 0x50) = iVar2 <= iVar1;
        if (iVar1 < iVar2) {
          lVar5 = *(longlong *)(param_1 + 0x38);
          if (lVar5 != 0) {
            pcVar4 = DAT_182ec1138;
            if ((DAT_182ec1138 == (code *)0x0) &&
               (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
               pcVar4 == (code *)0x0)) {
              uVar6 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar6,0);
            }
            DAT_182ec1138 = pcVar4;
            (*DAT_182ec1138)(lVar5,0);
            lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar5 != 0) {
              if (*(char *)(lVar5 + 0x20) == '\0') {
                bVar7 = *(char *)(param_1 + 0x48) == '\0';
              }
              else {
                bVar7 = true;
              }
              lVar5 = *(longlong *)(param_1 + 0x40);
              if (lVar5 != 0) {
                pcVar4 = DAT_182ec1138;
                if ((DAT_182ec1138 == (code *)0x0) &&
                   (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar4 == (code *)0x0)) {
                  uVar6 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar6,0);
                }
LAB_18061e31c:
                DAT_182ec1138 = pcVar4;
                    /* WARNING: Could not recover jumptable at 0x00018061e32c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                (*DAT_182ec1138)(lVar5,bVar7);
                return;
              }
            }
          }
        }
        else {
          lVar5 = *(longlong *)(param_1 + 0x40);
          if (lVar5 != 0) {
            pcVar4 = DAT_182ec1138;
            if ((DAT_182ec1138 == (code *)0x0) &&
               (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
               pcVar4 == (code *)0x0)) {
              uVar6 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar6,0);
            }
            DAT_182ec1138 = pcVar4;
            (*DAT_182ec1138)(lVar5,0);
            lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar5 != 0) {
              if (*(char *)(lVar5 + 0x20) == '\0') {
                bVar7 = *(char *)(param_1 + 0x48) == '\0';
              }
              else {
                bVar7 = true;
              }
              lVar5 = *(longlong *)(param_1 + 0x38);
              if (lVar5 != 0) {
                pcVar4 = DAT_182ec1138;
                if ((DAT_182ec1138 == (code *)0x0) &&
                   (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar4 == (code *)0x0)) {
                  uVar6 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar6,0);
                }
                goto LAB_18061e31c;
              }
            }
          }
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
  return;
}

