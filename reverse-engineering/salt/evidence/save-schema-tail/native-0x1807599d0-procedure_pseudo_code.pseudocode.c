// Ghidra pseudocode; not original source or compilable C.
// ev_f59da06dfddee3e46e17f57096f638d4b81a51ea1df7c74e930c0b0d85effac2

longlong * native_only_1807599d0__00000000(longlong param_1,longlong *param_2,longlong param_3)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  char cVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined8 uVar8;
  longlong *plVar9;
  uint uVar10;
  bool bVar11;
  
  if (*(longlong *)(param_3 + 0x38) == 0) {
    FUN_1802f2810(0x182d52c78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d56108);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d55f40);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_3 + 0x38) == 0) {
      FUN_1803204f0(param_3);
    }
  }
  if (param_2 != (longlong *)0x0) {
    if (*(longlong *)(param_1 + 0x10) == 0) {
      if (param_2[2] == 0) goto code_r0x000180759d18;
      ES3Types_ES3Type__GetMembers__06000447(param_1,*(undefined1 *)(param_2[2] + 0x4b),0,0);
    }
    lVar6 = (**(code **)(*param_2 + 0x288))(param_2,*(undefined8 *)(*param_2 + 0x290));
    if ((lVar6 == lRam0000000182d55f40) ||
       ((((lVar6 != 0 && (lRam0000000182d55f40 != 0)) &&
         (*(int *)(lVar6 + 0x10) == *(int *)(lRam0000000182d55f40 + 0x10))) &&
        (cVar5 = FUN_181630ad0(lVar6 + 0x14,lRam0000000182d55f40 + 0x14,
                               (longlong)*(int *)(lVar6 + 0x10) * 2,0), cVar5 != '\0')))) {
      uVar8 = ES3Reader__ReadType__0600018a(param_2,0);
      if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar6 = ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(uVar8,1,0);
      if (lVar6 == 0) goto code_r0x000180759d18;
      plVar7 = (longlong *)FUN_1800036a0(**(undefined8 **)(param_3 + 0x38),lVar6,param_2);
    }
    else {
      if ((lVar6 == lRam0000000182d56108) ||
         (((lVar6 != 0 && (lRam0000000182d56108 != 0)) &&
          ((*(int *)(lVar6 + 0x10) == *(int *)(lRam0000000182d56108 + 0x10) &&
           (cVar5 = FUN_181630ad0(lVar6 + 0x14,lRam0000000182d56108 + 0x14,
                                  (longlong)*(int *)(lVar6 + 0x10) * 2,0), cVar5 != '\0')))))) {
        uVar8 = (**(code **)(*param_2 + 0x278))(param_2,*(undefined8 *)(*param_2 + 0x280));
        if (*(int *)(lRam0000000182d52c78 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar6 = ES3Internal_ES3ReferenceMgrBase__get_Current__06000627(0);
        if (lVar6 == 0) goto code_r0x000180759d18;
        plVar7 = (longlong *)
                 ES3Internal_ES3ReferenceMgrBase__Get__06000632
                           (lVar6,uVar8,*(undefined8 *)(param_1 + 0x18),0,0);
        if (plVar7 == (longlong *)0x0) {
          uVar4 = *(undefined8 *)(param_1 + 0x18);
          if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
            FUN_18035c820();
          }
          plVar7 = (longlong *)ES3Internal_ES3Reflection__CreateInstance__0600065a(uVar4,0);
          if (*(int *)(lRam0000000182d52c78 + 0xe0) == 0) {
            FUN_18035c820();
          }
          lVar6 = ES3Internal_ES3ReferenceMgrBase__get_Current__06000627(0);
          if (lVar6 == 0) goto code_r0x000180759d18;
          plVar9 = (longlong *)0x0;
          if (plVar7 != (longlong *)0x0) {
            if ((*(byte *)(*plVar7 + 0x130) < *(byte *)(DAT_182d53aa8 + 0x130)) ||
               (plVar9 = plVar7,
               *(longlong *)
                (*(longlong *)(*plVar7 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d53aa8 + 0x130) * 8
                ) != DAT_182d53aa8)) {
                    /* WARNING: Subroutine does not return */
              FUN_18031e210(plVar7);
            }
          }
          ES3Internal_ES3ReferenceMgrBase__Add__06000637(lVar6,plVar9,uVar8,0);
        }
      }
      else {
        bVar11 = DAT_182eb5d50 != 0;
        param_2[4] = lVar6;
        if (bVar11) {
          uVar10 = (uint)((ulonglong)(param_2 + 4) >> 0xc);
          puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8);
          do {
            uVar3 = *puVar1;
            LOCK();
            uVar2 = *puVar1;
            if (uVar3 == uVar2) {
              *puVar1 = uVar3 | 1L << (uVar10 & 0x3f);
            }
            UNLOCK();
          } while (uVar3 != uVar2);
        }
        uVar8 = *(undefined8 *)(param_1 + 0x18);
        if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
          FUN_18035c820();
        }
        plVar7 = (longlong *)ES3Internal_ES3Reflection__CreateInstance__0600065a(uVar8,0);
      }
      ES3Types_ES3Type__ReadProperties__06000445(param_1,param_2,plVar7,0);
    }
    return plVar7;
  }
code_r0x000180759d18:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

