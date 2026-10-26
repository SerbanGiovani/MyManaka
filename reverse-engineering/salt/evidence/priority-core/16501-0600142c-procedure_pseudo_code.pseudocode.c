// Ghidra pseudocode; not original source or compilable C.
// ev_5cff93a35bc4a7b34825e696fcca2841cb837a19da184f0d621461a4935d0224

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionConbiniRegiExpose__IsInCondition__0600142c
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  byte bVar6;
  undefined8 unaff_RBX;
  
  if (cRam0000000182eb7900 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb7900 = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
     (*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28) == 0)) goto code_r0x000180479d76;
  if (DAT_182eb5492 == '\0') {
    FUN_1802f2810(&DAT_182d592a0);
    LOCK();
    UNLOCK();
    DAT_182eb5492 = '\x01';
  }
  lVar3 = **(longlong **)(DAT_182d592a0 + 0xb8);
  uVar1 = DAT_182d592a0;
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    uVar1 = FUN_18035c820();
  }
  if (DAT_182ec12f3 == '\0') {
    uVar1 = FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f3 = '\x01';
  }
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    uVar1 = FUN_18035c820();
  }
  if (DAT_182ec129b == '\0') {
    uVar1 = FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec129b = '\x01';
  }
  if (lVar3 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      uVar1 = FUN_18035c820();
    }
    if (*(longlong *)(lVar3 + 0x10) != 0) {
      if (DAT_182eb5492 == '\0') {
        FUN_1802f2810(&DAT_182d592a0);
        LOCK();
        UNLOCK();
        DAT_182eb5492 = '\x01';
      }
      lVar3 = **(longlong **)(DAT_182d592a0 + 0xb8);
      if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
        uVar2 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                          ();
        uVar1 = uVar2;
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          uVar1 = FUN_18035c820();
        }
        bVar6 = 0;
        if ((int)uVar2 == 1) {
          bVar6 = (byte)uVar2 & 1;
        }
        if (bVar6 != 0) goto code_r0x000180479d6a;
        if (lVar3 != 0) {
          if ((*(int *)(lVar3 + 0x58) < 1) || (*(char *)(lVar3 + 0x5c) == '\0'))
          goto code_r0x000180479d6a;
          uVar1 = *(ulonglong *)(lVar3 + 0x20);
          if (uVar1 != 0) {
            if (*(char *)(uVar1 + 0x20) == '\0') goto code_r0x000180479d6a;
            if ((((*(longlong *)(lVar3 + 0x60) != 0) &&
                 (lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x60) + 0x30), lVar3 != 0)) &&
                (lVar3 = *(longlong *)(lVar3 + 0xc0), lVar3 != 0)) &&
               ((lVar3 = *(longlong *)(lVar3 + 0x80), lVar3 != 0 &&
                (lVar3 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                                   (lVar3,0), lVar3 != 0)))) {
              pcVar4 = DAT_182ec1148;
              if ((DAT_182ec1148 == (code *)0x0) &&
                 (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_activeInHierarchy()",0
                                                 ,param_3,param_4,unaff_RBX), pcVar4 == (code *)0x0)
                 ) {
                uVar5 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar5,0);
              }
              DAT_182ec1148 = pcVar4;
                    /* WARNING: Could not recover jumptable at 0x000181f3eb65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              uVar1 = (*DAT_182ec1148)(lVar3);
              return uVar1;
            }
          }
        }
      }
code_r0x000180479d76:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
code_r0x000180479d6a:
  return uVar1 & 0xffffffffffffff00;
}

