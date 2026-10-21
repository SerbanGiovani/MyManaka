// Ghidra pseudocode; not original source or compilable C.
// ev_edf6d94454fd50b9afadfb8ea00e4e8cf7251767d844a0f924e7893a2ebeba9c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __c__DisplayClass31_0___LoadBundleFromStreamAsync_b__0__060000bf
               (longlong param_1,longlong *param_2)

{
  ulonglong *puVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  int iVar7;
  undefined8 *puVar8;
  uint uVar9;
  bool bVar10;
  undefined8 auStack_148 [35];
  undefined *puStack_30;
  
  if (cRam0000000182ebaadd == '\0') {
    puStack_30 = &UNK_18143faaf;
    FUN_1802f2810(0x182d64998);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_18143fac0;
    FUN_1802f2810(0x182d64c98);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_18143fad1;
    FUN_1802f2810(0x182d34308);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_18143fae2;
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_18143faf3;
    FUN_1802f2810(&DAT_182d2c730);
    LOCK();
    UNLOCK();
    cRam0000000182ebaadd = '\x01';
  }
  uVar2 = *(undefined8 *)(param_1 + 0x10);
  puStack_30 = &UNK_18143fb0f;
  uVar4 = FUN_1802c43a0(uRam0000000182d64c98);
  if (param_2 != (longlong *)0x0) {
    if ((*(byte *)(*param_2 + 0x130) < *(byte *)(lRam0000000182d64998 + 0x130)) ||
       (*(longlong *)
         (*(longlong *)(*param_2 + 200) + -8 +
         (ulonglong)*(byte *)(lRam0000000182d64998 + 0x130) * 8) != lRam0000000182d64998)) {
                    /* WARNING: Subroutine does not return */
      puStack_30 = &UNK_18143fc29;
      FUN_18031e210(param_2);
    }
  }
  puStack_30 = &UNK_18143fb5b;
  IKA9nt_Encrypter_EncryptLabelData___ctor__06000024(uVar4,param_2,uVar2,0);
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    puStack_30 = &UNK_18143fb73;
    FUN_18035c820(lRam0000000182d5bfb8);
  }
  if (**(longlong **)(lRam0000000182d5bfb8 + 0xb8) != 0) {
    puStack_30 = &UNK_18143fb9d;
    lVar5 = FUN_180eb45b0(**(longlong **)(lRam0000000182d5bfb8 + 0xb8),
                          *(undefined8 *)(param_1 + 0x10),uRam0000000182d34308);
    if (lVar5 != 0) {
      bVar10 = DAT_182eb5d50 != 0;
      *(undefined8 *)(lVar5 + 0x10) = uVar4;
      if (bVar10) {
        uVar9 = (uint)(lVar5 + 0x10U >> 0xc);
        puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
        do {
          uVar3 = *puVar1;
          LOCK();
          uVar6 = *puVar1;
          if (uVar3 == uVar6) {
            *puVar1 = uVar3 | 1L << (uVar9 & 0x3f);
          }
          UNLOCK();
        } while (uVar3 != uVar6);
      }
      if (*(int *)(_DAT_182d2c730 + 0xe0) == 0) {
        puStack_30 = &UNK_18143fc06;
        FUN_18035c820();
      }
      if (cRam0000000182ebbad2 == '\0') {
        puStack_30 = &UNK_18165e489;
        FUN_1802f2810(&DAT_182d2c730);
        LOCK();
        UNLOCK();
        cRam0000000182ebbad2 = '\x01';
      }
      if (*(int *)(_DAT_182d2c730 + 0xe0) == 0) {
        puStack_30 = &UNK_18165e4aa;
        FUN_18035c820();
      }
      if (cRam0000000182ebbad3 == '\0') {
        puStack_30 = &UNK_18165e4bf;
        FUN_1802f2810(&DAT_182d2c730);
        LOCK();
        UNLOCK();
        cRam0000000182ebbad3 = '\x01';
      }
      if (*(int *)(_DAT_182d2c730 + 0xe0) == 0) {
        puStack_30 = &UNK_18165e4e0;
        FUN_18035c820();
      }
      puStack_30 = &UNK_18165e4e5;
      FUN_1802ae7d0();
      if (DAT_182eb5cfc == 0) {
        return;
      }
      if (DAT_182eb5558 != 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_182ec5dc0);
      }
      iVar7 = DAT_182eb5cfc;
      uVar9 = DAT_182eb57ac;
      if (DAT_182eb5804 == 0) {
        uVar6 = (ulonglong)DAT_182eb57ac;
        DAT_182eb5804 = 1;
        if (DAT_182eb57ac != 0) {
          FUN_1803a8090(auStack_148,&DAT_182eb5b70,uVar6 << 3);
          DAT_182eb57ac = 0;
          FUN_1803a8730(&DAT_182eb5b70,0,uVar6 << 3);
        }
        if (DAT_182eb5558 != 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_182ec5dc0);
        }
        if (DAT_182eb5878 == 0) {
          iVar7 = 0;
        }
        else {
          (*DAT_182eb5cb0)();
        }
        if (uVar9 != 0) {
          FUN_1802b6760("Found %u leaked objects:\n",uVar6);
          puVar8 = auStack_148;
          do {
            FUN_1802aadd0(*puVar8);
            FUN_1802b1680(*puVar8);
            puVar8 = puVar8 + 1;
            uVar6 = uVar6 - 1;
            iVar7 = 1;
          } while (uVar6 != 0);
        }
        if ((iVar7 != 0) && (lVar5 = thunk_FUN_180381388("GC_ABORT_ON_LEAK"), lVar5 != 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_1802b68d0("Leaked or smashed objects encountered");
        }
        if (DAT_182eb5558 != 0) {
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_182ec5dc0);
        }
        DAT_182eb5804 = 0;
      }
      if (DAT_182eb5558 != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_182ec5dc0);
      }
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  puStack_30 = &UNK_18143fc2f;
  FUN_18031dad0();
}

