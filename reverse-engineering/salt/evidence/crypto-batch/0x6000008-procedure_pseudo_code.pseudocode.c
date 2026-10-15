// Ghidra pseudocode; not original source or compilable C.
// ev_72ec8b6908f1d8df41f74c8d58bde69f0dfa24514bf3215d89f102c124ecbb34

ulonglong SeekableAesAssetBundle_Scripts_SeekableAesStream___ctor__06000008
                    (longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
                    undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  ulonglong *puVar1;
  longlong lVar2;
  longlong *plVar3;
  ulonglong uVar4;
  code *pcVar5;
  int iVar6;
  undefined8 uVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  uint uVar12;
  bool bVar13;
  
  if (cRam0000000182ebaa80 == '\0') {
    FUN_1802f2810(0x182d53428);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53498);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6ab38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64e58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64e60);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa80 = '\x01';
  }
  *(undefined1 *)(param_1 + 0x40) = 1;
  if (*(int *)(lRam0000000182d64e60 + 0xe0) == 0) {
    FUN_18035c820();
  }
  *(undefined8 *)(param_1 + 0x28) = param_2;
  if (iRam0000000182eb5d50 != 0) {
    uVar12 = (uint)(param_1 + 0x28U >> 0xc);
    lVar2 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
    do {
      uVar11 = *(ulonglong *)(lVar2 + 0x182f0c920);
      puVar1 = (ulonglong *)(lVar2 + 0x182f0c920);
      LOCK();
      bVar13 = uVar11 == *puVar1;
      if (bVar13) {
        *puVar1 = uVar11 | 1L << (uVar12 & 0x3f);
      }
      UNLOCK();
    } while (!bVar13);
  }
  if (param_3 == 0) {
    FUN_18031dad0();
    pcVar5 = (code *)swi(3);
    uVar11 = (*pcVar5)();
    return uVar11;
  }
  uVar7 = FUN_18147d780(param_3,2,0);
  plVar8 = (longlong *)FUN_1802c43a0(uRam0000000182d6ab38);
  System_Security_Cryptography_Rfc2898DeriveBytes___ctor__06001562(plVar8,uVar7,param_4,1000,0);
  plVar9 = (longlong *)FUN_1802c43a0(uRam0000000182d64e58);
  FUN_1814a3920(plVar9,0);
  if (plVar9 != (longlong *)0x0) {
    (**(code **)(*plVar9 + 0x228))(plVar9,param_5,*(undefined8 *)(*plVar9 + 0x230));
    (**(code **)(*plVar9 + 0x248))(plVar9,param_6,*(undefined8 *)(*plVar9 + 0x250));
    (**(code **)(*plVar9 + 0x268))(plVar9,param_7,*(undefined8 *)(*plVar9 + 0x270));
    *(longlong **)(param_1 + 0x30) = plVar9;
    if (iRam0000000182eb5d50 != 0) {
      uVar12 = (uint)(param_1 + 0x30U >> 0xc);
      lVar2 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
      do {
        uVar11 = *(ulonglong *)(lVar2 + 0x182f0c920);
        puVar1 = (ulonglong *)(lVar2 + 0x182f0c920);
        LOCK();
        bVar13 = uVar11 == *puVar1;
        if (bVar13) {
          *puVar1 = uVar11 | 1L << (uVar12 & 0x3f);
        }
        UNLOCK();
      } while (!bVar13);
    }
    plVar9 = *(longlong **)(param_1 + 0x30);
    if (plVar9 != (longlong *)0x0) {
      iVar6 = (**(code **)(*plVar9 + 0x218))(plVar9,*(undefined8 *)(*plVar9 + 0x220));
      if (plVar8 != (longlong *)0x0) {
        uVar7 = (**(code **)(*plVar8 + 0x188))
                          (plVar8,(int)((iVar6 >> 0x1f & 7U) + iVar6) >> 3,
                           *(undefined8 *)(*plVar8 + 400));
        (**(code **)(*plVar9 + 0x1f8))(plVar9,uVar7,*(undefined8 *)(*plVar9 + 0x200));
        plVar9 = *(longlong **)(param_1 + 0x30);
        uVar7 = FUN_1802c36c0(uRam0000000182d53428,0x10);
        if (plVar9 != (longlong *)0x0) {
          (**(code **)(*plVar9 + 0x1d8))(plVar9,uVar7,*(undefined8 *)(*plVar9 + 0x1e0));
          plVar9 = *(longlong **)(param_1 + 0x30);
          if (plVar9 != (longlong *)0x0) {
            uVar7 = (**(code **)(*plVar9 + 0x1e8))(plVar9,*(undefined8 *)(*plVar9 + 0x1f0));
            plVar3 = *(longlong **)(param_1 + 0x30);
            if (plVar3 != (longlong *)0x0) {
              uVar10 = (**(code **)(*plVar3 + 0x1c8))(plVar3,*(undefined8 *)(*plVar3 + 0x1d0));
              uVar11 = (**(code **)(*plVar9 + 0x288))
                                 (plVar9,uVar7,uVar10,*(undefined8 *)(*plVar9 + 0x290));
              *(ulonglong *)(param_1 + 0x38) = uVar11;
              if (iRam0000000182eb5d50 != 0) {
                uVar12 = (uint)(param_1 + 0x38U >> 0xc);
                lVar2 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
                do {
                  uVar4 = *(ulonglong *)(lVar2 + 0x182f0c920);
                  puVar1 = (ulonglong *)(lVar2 + 0x182f0c920);
                  LOCK();
                  uVar11 = *puVar1;
                  bVar13 = uVar4 == uVar11;
                  if (bVar13) {
                    *puVar1 = uVar4 | 1L << (uVar12 & 0x3f);
                    uVar11 = uVar4;
                  }
                  UNLOCK();
                } while (!bVar13);
              }
              if (plVar8 != (longlong *)0x0) {
                uVar11 = FUN_180002c20(0,uRam0000000182d53498);
              }
              return uVar11;
            }
            FUN_18031dad0();
          }
          FUN_18031dad0();
        }
        FUN_18031dad0();
      }
      FUN_18031dad0();
    }
    FUN_18031dad0();
  }
  FUN_18031dad0();
  FUN_18031dac0();
  pcVar5 = (code *)swi(3);
  uVar11 = (*pcVar5)();
  return uVar11;
}

