// Ghidra pseudocode; not original source or compilable C.
// ev_b909b2a42daf01e45f605aac161dfee3be9ad764b7268d18291248a36777cd01

void IKA9nt_Encrypter_EncrypterCore__GetPasswordFromMap__060000a8
               (longlong *param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  int iVar11;
  ulonglong unaff_RDI;
  uint uVar12;
  bool bVar13;
  ulonglong uStackX_8;
  ulonglong in_stack_ffffffffffffff88;
  undefined8 uStack_48;
  undefined *puStack_40;
  undefined4 uStack_30;
  
  if (cRam0000000182ebaac8 == '\0') {
    FUN_1802f2810(0x182d53300);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64a10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64e78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d52f00);
    LOCK();
    UNLOCK();
    cRam0000000182ebaac8 = '\x01';
  }
  iVar11 = 0;
  uStack_30 = 0;
  if ((*param_1 != 0) && (*(int *)(*param_1 + 0x10) != 0)) {
code_r0x00018143dd63:
    lVar6 = *param_1;
    if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (cRam0000000182ebaac9 == '\0') {
      puStack_40 = &UNK_18143de65;
      FUN_1802f2810(0x182d64a40);
      LOCK();
      UNLOCK();
      cRam0000000182ebaac9 = '\x01';
    }
    if (lVar6 != 0) {
      puStack_40 = &UNK_18143de9b;
      iVar11 = FUN_18147e670(lVar6,uRam0000000182d64a40,0,*(undefined4 *)(lVar6 + 0x10));
      if (iVar11 < 0) {
        return;
      }
      puStack_40 = &UNK_18143debb;
      uStackX_8 = unaff_RDI;
      uVar7 = func_0x00018031d720(0x182d531f8);
      puStack_40 = &UNK_18143dec8;
      uVar7 = func_0x00018031d8c0(uVar7,1);
      puStack_40 = &UNK_18143ded3;
      FUN_1800039f0(uVar7);
      puStack_40 = &UNK_18143dee0;
      FUN_180002cd0(uVar7,0,param_2);
      puStack_40 = &UNK_18143deec;
      uVar9 = func_0x00018031d720(0x182d5bfb8);
      puStack_40 = &UNK_18143def4;
      func_0x0001800039e0(uVar9);
      puStack_40 = &UNK_18143df00;
      uVar9 = func_0x00018031d720(0x182d64a38);
      puStack_40 = &UNK_18143df0f;
      uVar10 = func_0x00018031d720(0x182d64a30);
      puStack_40 = &UNK_18143df20;
      uVar7 = FUN_18143f3a0(uVar10,uVar9,uVar7,0);
      puStack_40 = &UNK_18143df2f;
      uVar9 = func_0x00018031d720(0x182d53398);
      puStack_40 = &UNK_18143df37;
      uVar9 = func_0x00018031da80(uVar9);
      puStack_40 = &UNK_18143df48;
      FUN_18165bfb0(uVar9,uVar7,0);
      puStack_40 = &UNK_18143df54;
      uVar7 = func_0x00018031d720(0x182d64a50);
      puStack_40 = &UNK_18143df5f;
      FUN_18031da90(uVar9,uVar7);
    }
    puStack_40 = &UNK_18143df69;
    FUN_18031dad0();
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5bfb8);
  }
  lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x20);
  if (lVar6 != 0) {
    lVar6 = *(longlong *)(lVar6 + 0x10);
    if (lVar6 != 0) {
      lVar6 = FUN_180eb45b0(lVar6,param_2,uRam0000000182d64a10);
      *param_1 = **(longlong **)(lRam0000000182d52f00 + 0xb8);
      if (iRam0000000182eb5d50 != 0) {
        uVar12 = (uint)((ulonglong)param_1 >> 0xc);
        lVar8 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(lVar8 + 0x182f0c920);
          puVar1 = (ulonglong *)(lVar8 + 0x182f0c920);
          LOCK();
          bVar13 = uVar2 == *puVar1;
          if (bVar13) {
            *puVar1 = uVar2 | 1L << (uVar12 & 0x3f);
          }
          UNLOCK();
        } while (!bVar13);
      }
      if (lVar6 != 0) {
        for (; iVar11 < *(int *)(lVar6 + 0x10); iVar11 = iVar11 + 1) {
          if (*(int *)(lRam0000000182d64e78 + 0xe0) == 0) {
            FUN_18035c820(lRam0000000182d64e78);
          }
          lVar8 = **(longlong **)(lRam0000000182d64e78 + 0xb8);
          uVar7 = FUN_18147cec0(lVar6,iVar11,1,0);
          if (lVar8 == 0) {
code_r0x00018143de2a:
            FUN_18031dad0();
            goto code_r0x00018143de2f;
          }
          in_stack_ffffffffffffff88 = in_stack_ffffffffffffff88 & 0xffffffff00000000;
          iVar4 = FUN_18147e670(lVar8,uVar7,0,*(undefined4 *)(lVar8 + 0x10),
                                in_stack_ffffffffffffff88,0);
          if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
            FUN_18035c820(lRam0000000182d5bfb8);
          }
          lVar8 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18);
          if (lVar8 == 0) {
code_r0x00018143de25:
            FUN_18031dad0();
            goto code_r0x00018143de2a;
          }
          lVar8 = *(longlong *)(lVar8 + 0x18);
          if (lVar8 == 0) {
            FUN_18031dad0();
            goto code_r0x00018143de25;
          }
          lVar8 = FUN_18147cec0(lVar8,iVar11,1,0);
          if (*(int *)(lRam0000000182d53300 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (lVar8 == 0) {
            iVar5 = 0;
          }
          else {
            if (cRam0000000182eb54e8 == '\0') {
              FUN_1802f2810();
              LOCK();
              UNLOCK();
              cRam0000000182eb54e8 = '\x01';
            }
            uStack_48 = lVar8 + 0x14;
            uStackX_8 = uStackX_8 & 0xffffffff00000000;
            puStack_40 = (undefined *)(ulonglong)*(uint *)(lVar8 + 0x10);
            in_stack_ffffffffffffff88 = 0;
            iVar5 = FUN_18162c4f0(&uStack_48,0x10,0x1000,&uStackX_8,0);
          }
          lVar8 = *param_1;
          uVar7 = IKA9nt_Encrypter_EncrypterCore__PasswordCharacterSubstring__060000ab
                            (iVar4 - iVar5,0);
          lVar8 = FUN_181478910(lVar8,uVar7);
          *param_1 = lVar8;
          if (iRam0000000182eb5d50 != 0) {
            uVar12 = (uint)((ulonglong)param_1 >> 0xc);
            lVar8 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
            do {
              uVar2 = *(ulonglong *)(lVar8 + 0x182f0c920);
              puVar1 = (ulonglong *)(lVar8 + 0x182f0c920);
              LOCK();
              bVar13 = uVar2 == *puVar1;
              if (bVar13) {
                *puVar1 = uVar2 | 1L << (uVar12 & 0x3f);
              }
              UNLOCK();
            } while (!bVar13);
          }
        }
        goto code_r0x00018143dd63;
      }
code_r0x00018143de2f:
      FUN_18031dad0();
    }
    FUN_18031dad0();
  }
  FUN_18031dad0();
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}

