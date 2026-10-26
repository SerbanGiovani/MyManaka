// Ghidra pseudocode; not original source or compilable C.
// ev_10899478061eb7afbc3782555a0f1d4783b2156f95d7617173eaececbff9e773

longlong ES3Internal_ES3Reflection__CreateInstance__0600065b(longlong param_1,undefined8 param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined8 uVar6;
  
  if (cRam0000000182eb808b == '\0') {
    FUN_1802f2810(&DAT_182d535e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a798);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    cRam0000000182eb808b = '\x01';
  }
  lVar3 = DAT_182d535e8;
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  plVar4 = (longlong *)0x0;
  if (lVar3 != 0) {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar3 = FUN_1803613f0(lVar3,1);
    plVar4 = (longlong *)FUN_1802c5ac0(lVar3 + 0x20);
  }
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (plVar4 != (longlong *)0x0) {
    cVar1 = (**(code **)(*plVar4 + 0x288))(plVar4,param_1,*(undefined8 *)(*plVar4 + 0x290));
    uVar6 = DAT_182d6a798;
    if (cVar1 != '\0') {
      if (cRam0000000182eb7ecb == '\0') {
        FUN_1802f2810(&DAT_182d55b08,0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d68ac8);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d535d8);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d68ac0);
        LOCK();
        UNLOCK();
        cRam0000000182eb7ecb = '\x01';
      }
      lVar2 = FUN_1802c43a0(DAT_182d55b08);
      FUN_181f3ed60(lVar2,uRam0000000182d68ac0,0);
      lVar3 = lRam0000000182d68ac8;
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182ebb9aa == '\0') {
        FUN_1802f2810(&DAT_182d535d8);
        LOCK();
        UNLOCK();
        DAT_182ebb9aa = '\x01';
      }
      if (lVar3 == 0) {
        lVar3 = 0;
      }
      else {
        if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar3 = FUN_1803613f0(lVar3,1);
        lVar3 = FUN_1802c5ac0(lVar3 + 0x20);
      }
      if (param_1 != lVar3) {
        if (cRam0000000182eb7eca == '\0') {
          FUN_1802f2810(&DAT_182d53aa8,param_1,0);
          LOCK();
          UNLOCK();
          cRam0000000182eb7eca = '\x01';
        }
        if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        pcVar5 = pcRam0000000182ec10d8;
        if ((pcRam0000000182ec10d8 == (code *)0x0) &&
           (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::GetComponent(System.Type)"),
           pcVar5 == (code *)0x0)) {
          uVar6 = FUN_1802ced60("UnityEngine.GameObject::GetComponent(System.Type)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar6,0);
        }
        pcRam0000000182ec10d8 = pcVar5;
        lVar3 = (*pcRam0000000182ec10d8)(lVar2,param_1);
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
        if (lVar3 != 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (*(longlong *)(lVar3 + 0x10) != 0) {
            return lVar3;
          }
        }
        pcVar5 = DAT_182ec1118;
        if ((DAT_182ec1118 == (code *)0x0) &&
           (pcVar5 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.GameObject::Internal_AddComponentWithType(System.Type)"
                                          ), pcVar5 == (code *)0x0)) {
          uVar6 = FUN_1802ced60("UnityEngine.GameObject::Internal_AddComponentWithType(System.Type)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar6,0);
        }
        DAT_182ec1118 = pcVar5;
                    /* WARNING: Could not recover jumptable at 0x000180551aab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        lVar3 = (*DAT_182ec1118)(lVar2,param_1);
        return lVar3;
      }
      if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      pcVar5 = pcRam0000000182ec10d8;
      if ((pcRam0000000182ec10d8 == (code *)0x0) &&
         (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::GetComponent(System.Type)"),
         pcVar5 == (code *)0x0)) {
        uVar6 = FUN_1802ced60("UnityEngine.GameObject::GetComponent(System.Type)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
      pcRam0000000182ec10d8 = pcVar5;
                    /* WARNING: Could not recover jumptable at 0x000180551c45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      lVar3 = (*pcRam0000000182ec10d8)(lVar2,param_1);
      return lVar3;
    }
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    plVar4 = (longlong *)FUN_181638ed0(uVar6,0);
    if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (plVar4 != (longlong *)0x0) {
      cVar1 = (**(code **)(*plVar4 + 0x288))(plVar4,param_1,*(undefined8 *)(*plVar4 + 0x290));
      if (cVar1 == '\0') {
        lVar3 = FUN_18164b740(param_1,0x214,0,param_2,0,0,0);
        return lVar3;
      }
      pcVar5 = pcRam0000000182ec1250;
      if ((pcRam0000000182ec1250 == (code *)0x0) &&
         (pcVar5 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.ScriptableObject::CreateScriptableObjectInstanceFromType(System.Type,System.Boolean)"
                                        ), pcVar5 == (code *)0x0)) {
        uVar6 = FUN_1802ced60(
                             "UnityEngine.ScriptableObject::CreateScriptableObjectInstanceFromType(System.Type,System.Boolean)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
      pcRam0000000182ec1250 = pcVar5;
                    /* WARNING: Could not recover jumptable at 0x00018059b940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      lVar3 = (*pcRam0000000182ec1250)(param_1,1);
      return lVar3;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

