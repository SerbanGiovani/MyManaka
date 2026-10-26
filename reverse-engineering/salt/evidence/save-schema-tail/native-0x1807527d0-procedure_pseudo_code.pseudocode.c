// Ghidra pseudocode; not original source or compilable C.
// ev_bc7eb040f3635d334d914d82e1acd7fdc15ca247d0ed5f789b8c19999206560a

void native_only_1807527d0__00000000
               (longlong *param_1,longlong *param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  bool bVar8;
  longlong lStack_38;
  longlong lStack_30;
  undefined8 uStack_28;
  
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
  if ((param_1 != (longlong *)0x0) && (param_2 != (longlong *)0x0)) {
    while( true ) {
      if (param_2[4] == 0) {
        lVar4 = (**(code **)(*param_2 + 0x288))(param_2,*(undefined8 *)(*param_2 + 0x290));
      }
      else {
        bVar8 = DAT_182eb5d50 != 0;
        lVar4 = param_2[4];
        param_2[4] = 0;
        if (bVar8) {
          uVar7 = (uint)((ulonglong)(param_2 + 4) >> 0xc);
          lVar1 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
          do {
            uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
            LOCK();
            bVar8 = uVar6 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
            if (bVar8) {
              *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar6 | 1L << (uVar7 & 0x3f);
            }
            UNLOCK();
          } while (!bVar8);
        }
      }
      if (lVar4 == lRam0000000182d55f40) break;
      if (lVar4 == 0) {
        return;
      }
      if ((lRam0000000182d55f40 != 0) &&
         (*(int *)(lVar4 + 0x10) == *(int *)(lRam0000000182d55f40 + 0x10))) {
        cVar3 = FUN_181630ad0(lVar4 + 0x14,lRam0000000182d55f40 + 0x14,
                              (longlong)*(int *)(lVar4 + 0x10) * 2,0);
        if (cVar3 != '\0') break;
        if (lVar4 == 0) {
          return;
        }
      }
      bVar8 = DAT_182eb5d50 != 0;
      param_2[4] = lVar4;
      if (bVar8) {
        uVar7 = (uint)((ulonglong)(param_2 + 4) >> 0xc);
        uVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
          LOCK();
          bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
          if (bVar8) {
            *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar2 | 1L << (uVar7 & 0x3f);
          }
          UNLOCK();
        } while (!bVar8);
      }
      lVar4 = *(longlong *)(*(longlong *)(param_4 + 0x38) + 8);
      lStack_38 = *(longlong *)(*param_1 + ((ulonglong)*(ushort *)(lVar4 + 0x50) + 0x14) * 0x10);
      lStack_30 = 0;
      if ((*(byte *)(lStack_38 + 0x53) & 2) != 0) {
        lStack_30 = (*(longlong **)(lStack_38 + 0x40))[1];
        lStack_38 = **(longlong **)(lStack_38 + 0x40);
      }
      uStack_28 = *(undefined8 *)(*(longlong *)(lVar4 + 0x40) + 0x10);
      lVar4 = FUN_180306310(&lStack_38,CONCAT71((int7)((ulonglong)lStack_38 >> 8),1));
      (**(code **)(lVar4 + 8))(param_1,param_2);
    }
    uVar5 = ES3Reader__ReadType__0600018a(param_2,0);
    if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar4 = ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(uVar5,1,0);
    if (lVar4 != 0) {
      FUN_180007d40(**(undefined8 **)(param_4 + 0x38),lVar4,param_2,param_3);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

