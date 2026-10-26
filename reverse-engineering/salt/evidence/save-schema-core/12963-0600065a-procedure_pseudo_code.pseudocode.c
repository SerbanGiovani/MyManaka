// Ghidra pseudocode; not original source or compilable C.
// ev_e5cd5eb9cd4a30dcedcd35fcb019689154488fe347fc79efad0b65dafc3b56a3

longlong ES3Internal_ES3Reflection__CreateInstance__0600065a(longlong *param_1)

{
  bool bVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  longlong *plVar10;
  
  if (cRam0000000182eb808a == '\0') {
    FUN_1802f2810(&DAT_182d535e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a790);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a798);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    cRam0000000182eb808a = '\x01';
  }
  lVar4 = DAT_182d535e8;
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  plVar5 = (longlong *)0x0;
  if (lVar4 != 0) {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar4 = FUN_1803613f0(lVar4,1);
    plVar5 = (longlong *)FUN_1802c5ac0(lVar4 + 0x20);
  }
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (plVar5 != (longlong *)0x0) {
    cVar2 = (**(code **)(*plVar5 + 0x288))(plVar5,param_1,*(undefined8 *)(*plVar5 + 0x290));
    uVar7 = DAT_182d6a798;
    if (cVar2 != '\0') {
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
      lVar3 = FUN_1802c43a0(DAT_182d55b08);
      FUN_181f3ed60(lVar3,uRam0000000182d68ac0,0);
      lVar4 = lRam0000000182d68ac8;
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182ebb9aa == '\0') {
        FUN_1802f2810(&DAT_182d535d8);
        LOCK();
        UNLOCK();
        DAT_182ebb9aa = '\x01';
      }
      if (lVar4 == 0) {
        plVar5 = (longlong *)0x0;
      }
      else {
        if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar4 = FUN_1803613f0(lVar4,1);
        plVar5 = (longlong *)FUN_1802c5ac0(lVar4 + 0x20);
      }
      if (param_1 != plVar5) {
        if (cRam0000000182eb7eca == '\0') {
          FUN_1802f2810(&DAT_182d53aa8,param_1,0);
          LOCK();
          UNLOCK();
          cRam0000000182eb7eca = '\x01';
        }
        if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        pcVar6 = pcRam0000000182ec10d8;
        if ((pcRam0000000182ec10d8 == (code *)0x0) &&
           (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::GetComponent(System.Type)"),
           pcVar6 == (code *)0x0)) {
          uVar7 = FUN_1802ced60("UnityEngine.GameObject::GetComponent(System.Type)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar7,0);
        }
        pcRam0000000182ec10d8 = pcVar6;
        lVar4 = (*pcRam0000000182ec10d8)(lVar3,param_1);
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
        if (lVar4 != 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (*(longlong *)(lVar4 + 0x10) != 0) {
            return lVar4;
          }
        }
        pcVar6 = DAT_182ec1118;
        if ((DAT_182ec1118 == (code *)0x0) &&
           (pcVar6 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.GameObject::Internal_AddComponentWithType(System.Type)"
                                          ), pcVar6 == (code *)0x0)) {
          uVar7 = FUN_1802ced60("UnityEngine.GameObject::Internal_AddComponentWithType(System.Type)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar7,0);
        }
        DAT_182ec1118 = pcVar6;
                    /* WARNING: Could not recover jumptable at 0x000180551aab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        lVar4 = (*DAT_182ec1118)(lVar3,param_1);
        return lVar4;
      }
      if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      pcVar6 = pcRam0000000182ec10d8;
      if ((pcRam0000000182ec10d8 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::GetComponent(System.Type)"),
         pcVar6 == (code *)0x0)) {
        uVar7 = FUN_1802ced60("UnityEngine.GameObject::GetComponent(System.Type)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar7,0);
      }
      pcRam0000000182ec10d8 = pcVar6;
                    /* WARNING: Could not recover jumptable at 0x000180551c45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      lVar4 = (*pcRam0000000182ec10d8)(lVar3,param_1);
      return lVar4;
    }
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    plVar5 = (longlong *)FUN_181638ed0(uVar7,0);
    if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (plVar5 != (longlong *)0x0) {
      cVar2 = (**(code **)(*plVar5 + 0x288))(plVar5,param_1,*(undefined8 *)(*plVar5 + 0x290));
      if (cVar2 != '\0') {
        pcVar6 = pcRam0000000182ec1250;
        if ((pcRam0000000182ec1250 == (code *)0x0) &&
           (pcVar6 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.ScriptableObject::CreateScriptableObjectInstanceFromType(System.Type,System.Boolean)"
                                          ), pcVar6 == (code *)0x0)) {
          uVar7 = FUN_1802ced60(
                               "UnityEngine.ScriptableObject::CreateScriptableObjectInstanceFromType(System.Type,System.Boolean)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar7,0);
        }
        pcRam0000000182ec1250 = pcVar6;
                    /* WARNING: Could not recover jumptable at 0x00018059b71c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        lVar4 = (*pcRam0000000182ec1250)(param_1,1);
        return lVar4;
      }
      if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar2 = ES3Internal_ES3Reflection__HasParameterlessConstructor__06000671(param_1,0);
      if (cVar2 != '\0') {
        if (DAT_182ebba65 == '\0') {
          FUN_1802f2810(&DAT_182d4fc20,0,1,0);
          LOCK();
          UNLOCK();
          DAT_182ebba65 = '\x01';
        }
        if (param_1 == (longlong *)0x0) {
          uVar7 = thunk_FUN_1802f2810(&DAT_182d528c8);
          uVar7 = thunk_FUN_1802c43a0(uVar7);
          uVar8 = thunk_FUN_1802f2810(&DAT_182d5c530);
          FUN_1815c6a10(uVar7,uVar8,0);
          uVar8 = thunk_FUN_1802f2810(&DAT_182d28f38);
                    /* WARNING: Subroutine does not return */
          FUN_18031da90(uVar7,uVar8);
        }
        plVar5 = (longlong *)
                 (**(code **)(*param_1 + 0x308))(param_1,*(undefined8 *)(*param_1 + 0x310));
        if (plVar5 == (longlong *)0x0) {
          plVar10 = (longlong *)0x0;
        }
        else {
          if ((*(byte *)(*plVar5 + 0x130) < *(byte *)(DAT_182d4fc20 + 0x130)) ||
             (*(longlong *)
               (*(longlong *)(*plVar5 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d4fc20 + 0x130) * 8)
              != DAT_182d4fc20)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          plVar10 = (longlong *)0x0;
          if (bVar1) {
            plVar10 = plVar5;
          }
        }
        if (*(int *)(DAT_182d4fc20 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d4fc20);
        }
        if (plVar10 == (longlong *)0x0) {
          uVar7 = thunk_FUN_1802f2810(&DAT_182d1d0e8);
          uVar7 = System_String__Clone__06000289(uVar7,0);
          uVar8 = thunk_FUN_1802f2810(&DAT_182d53468);
          uVar8 = thunk_FUN_1802c43a0(uVar8);
          uVar9 = thunk_FUN_1802f2810(&DAT_182d5c530);
          FUN_1815c65d0(uVar8,uVar7,uVar9,0);
          uVar7 = thunk_FUN_1802f2810(&DAT_182d28f38);
                    /* WARNING: Subroutine does not return */
          FUN_18031da90(uVar8,uVar7);
        }
        lVar4 = FUN_1816689c0(plVar10,1,0,1,1,&stack0x00000008,0);
        return lVar4;
      }
      if (*(int *)(lRam0000000182d6a790 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (cRam0000000182ebb0ea == '\0') {
        FUN_1802f2810(0x182d6a790,0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d4fc20);
        LOCK();
        UNLOCK();
        cRam0000000182ebb0ea = '\x01';
      }
      if (param_1 == (longlong *)0x0) {
        uVar7 = thunk_FUN_1802f2810(&DAT_182d528c8);
        uVar7 = thunk_FUN_1802c43a0(uVar7);
        uVar8 = thunk_FUN_1802f2810(&DAT_182d5c530);
        FUN_1815c6a10(uVar7,uVar8,0);
        uVar8 = thunk_FUN_1802f2810(0x182d3cd00);
                    /* WARNING: Subroutine does not return */
        FUN_18031da90(uVar7,uVar8);
      }
      if ((*(byte *)(*param_1 + 0x130) < *(byte *)(DAT_182d4fc20 + 0x130)) ||
         (*(longlong *)
           (*(longlong *)(*param_1 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d4fc20 + 0x130) * 8) !=
          DAT_182d4fc20)) {
        uVar7 = thunk_FUN_1802f2810(&DAT_182d626c0);
        uVar7 = FUN_18031d8c0(uVar7,1);
        FUN_1800039f0(param_1);
        uVar8 = FUN_180002bf0(3,param_1);
        FUN_1800039f0(uVar7);
        FUN_180003860(uVar7,uVar8);
        FUN_180002cd0(uVar7,0,uVar8);
        uVar8 = thunk_FUN_1802f2810(0x182d3cd78);
        uVar7 = FUN_181672e50(uVar8,uVar7,0);
        uVar8 = thunk_FUN_1802f2810(0x182d29500);
        uVar8 = thunk_FUN_1802c43a0(uVar8);
        FUN_1814faf30(uVar8,uVar7,0);
        uVar7 = thunk_FUN_1802f2810(0x182d3cd00);
                    /* WARNING: Subroutine does not return */
        FUN_18031da90(uVar8,uVar7);
      }
      if (*(int *)(lRam0000000182d6a790 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if ((*(byte *)(DAT_182d4fc20 + 0x130) <= *(byte *)(*param_1 + 0x130)) &&
         (*(longlong *)
           (*(longlong *)(*param_1 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d4fc20 + 0x130) * 8) ==
          DAT_182d4fc20)) {
        lVar4 = FUN_1803613f0(param_1[2],1);
        if (lVar4 != 0) {
          FUN_180365320(lVar4);
          lVar4 = FUN_1802c43a0(lVar4);
          return lVar4;
        }
        return 0;
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(param_1);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

