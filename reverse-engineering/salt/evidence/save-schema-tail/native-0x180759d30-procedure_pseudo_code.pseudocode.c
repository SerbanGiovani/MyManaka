// Ghidra pseudocode; not original source or compilable C.
// ev_e83a55f04945748a1c9d911d7fbc468b7506b23e35f4d2e17804171f8b651d1b

void native_only_180759d30__00000000
               (longlong param_1,longlong *param_2,undefined8 param_3,longlong param_4)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  char cVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  bool bVar8;
  
  if (*(longlong *)(param_4 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d55f40);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_4 + 0x38) == 0) {
      FUN_1803204f0(param_4);
    }
  }
  if (param_2 != (longlong *)0x0) {
    if (*(longlong *)(param_1 + 0x10) == 0) {
      if (param_2[2] == 0) goto code_r0x000180759ed8;
      ES3Types_ES3Type__GetMembers__06000447(param_1,*(undefined1 *)(param_2[2] + 0x4b),0,0);
    }
    lVar5 = (**(code **)(*param_2 + 0x288))(param_2,*(undefined8 *)(*param_2 + 0x290));
    if ((lVar5 == lRam0000000182d55f40) ||
       ((((lVar5 != 0 && (lRam0000000182d55f40 != 0)) &&
         (*(int *)(lVar5 + 0x10) == *(int *)(lRam0000000182d55f40 + 0x10))) &&
        (cVar4 = FUN_181630ad0(lVar5 + 0x14,lRam0000000182d55f40 + 0x14,
                               (longlong)*(int *)(lVar5 + 0x10) * 2,0), cVar4 != '\0')))) {
      uVar6 = ES3Reader__ReadType__0600018a(param_2,0);
      if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar5 = ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(uVar6,1,0);
      if (lVar5 == 0) goto code_r0x000180759ed8;
      FUN_180007d40(**(undefined8 **)(param_4 + 0x38),lVar5,param_2,param_3);
    }
    else {
      bVar8 = DAT_182eb5d50 != 0;
      param_2[4] = lVar5;
      if (bVar8) {
        uVar7 = (uint)((ulonglong)(param_2 + 4) >> 0xc);
        puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
        do {
          uVar3 = *puVar1;
          LOCK();
          uVar2 = *puVar1;
          if (uVar3 == uVar2) {
            *puVar1 = uVar3 | 1L << (uVar7 & 0x3f);
          }
          UNLOCK();
        } while (uVar3 != uVar2);
      }
      ES3Types_ES3Type__ReadProperties__06000445(param_1,param_2,param_3,0);
    }
    return;
  }
code_r0x000180759ed8:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

