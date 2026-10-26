// Ghidra pseudocode; not original source or compilable C.
// ev_c2dd6f9d9e34a3f0005cd05cca6e6bbfcb0cff5025d1571a3df7cd9324c674f3

void native_only_1807525e0__00000000(longlong *param_1,longlong *param_2,longlong param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  longlong lVar4;
  undefined8 uVar5;
  uint uVar6;
  bool bVar7;
  longlong lStack_28;
  longlong lStack_20;
  undefined8 uStack_18;
  
  if (*(longlong *)(param_3 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d55f40);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_3 + 0x38) == 0) {
      FUN_1803204f0(param_3);
    }
  }
  if ((param_1 != (longlong *)0x0) && (param_2 != (longlong *)0x0)) {
    if (param_2[4] == 0) {
      lVar4 = (**(code **)(*param_2 + 0x288))(param_2,*(undefined8 *)(*param_2 + 0x290));
    }
    else {
      bVar7 = DAT_182eb5d50 != 0;
      lVar4 = param_2[4];
      param_2[4] = 0;
      if (bVar7) {
        uVar6 = (uint)((ulonglong)(param_2 + 4) >> 0xc);
        lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
          LOCK();
          bVar7 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
          if (bVar7) {
            *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar6 & 0x3f);
          }
          UNLOCK();
        } while (!bVar7);
      }
    }
    if ((lVar4 == lRam0000000182d55f40) ||
       ((((lVar4 != 0 && (lRam0000000182d55f40 != 0)) &&
         (*(int *)(lVar4 + 0x10) == *(int *)(lRam0000000182d55f40 + 0x10))) &&
        (cVar3 = FUN_181630ad0(lVar4 + 0x14,lRam0000000182d55f40 + 0x14,
                               (longlong)*(int *)(lVar4 + 0x10) * 2,0), cVar3 != '\0')))) {
      uVar5 = ES3Reader__ReadType__0600018a(param_2,0);
      if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      param_1 = (longlong *)ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(uVar5,1,0);
      if (param_1 == (longlong *)0x0) goto code_r0x0001807527c8;
      lVar4 = **(longlong **)(param_3 + 0x38);
    }
    else {
      bVar7 = DAT_182eb5d50 != 0;
      param_2[4] = lVar4;
      if (bVar7) {
        uVar6 = (uint)((ulonglong)(param_2 + 4) >> 0xc);
        lVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
          LOCK();
          bVar7 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
          if (bVar7) {
            *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar2 | 1L << (uVar6 & 0x3f);
          }
          UNLOCK();
        } while (!bVar7);
      }
      lVar4 = *(longlong *)(*(longlong *)(param_3 + 0x38) + 8);
    }
    lStack_28 = *(longlong *)(*param_1 + ((ulonglong)*(ushort *)(lVar4 + 0x50) + 0x14) * 0x10);
    lStack_20 = 0;
    if ((*(byte *)(lStack_28 + 0x53) & 2) != 0) {
      lStack_20 = (*(longlong **)(lStack_28 + 0x40))[1];
      lStack_28 = **(longlong **)(lStack_28 + 0x40);
    }
    uStack_18 = *(undefined8 *)(*(longlong *)(lVar4 + 0x40) + 0x10);
    lVar4 = FUN_180306310(&lStack_28,1);
    (**(code **)(lVar4 + 8))(param_1,param_2,lVar4);
    return;
  }
code_r0x0001807527c8:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

