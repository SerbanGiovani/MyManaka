// Ghidra pseudocode; not original source or compilable C.
// ev_0c1967e14de53072bdf650c36be275f01ece07b421fc664b854ad6bd77cb97c3

void IKA9nt_Encrypter_EncrypterKeyData__OnAfterDeserialize__0600001e(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  longlong lVar9;
  bool bVar10;
  
  if (cRam0000000182ebaa84 == '\0') {
    FUN_1802f2810(0x182d64dc8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64df0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64de8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64de0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64dd8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64e00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3bd28);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3bd20);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64df8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa84 = '\x01';
  }
  uVar4 = FUN_1802c43a0(uRam0000000182d64e00);
  FUN_180e95b10(uVar4,uRam0000000182d64de8);
  bVar10 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x28) = uVar4;
  if (bVar10) {
    uVar6 = (uint)(param_1 + 0x28U >> 0xc);
    lVar5 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
      LOCK();
      bVar10 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
      if (bVar10) {
        *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar1 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar10);
  }
  lVar5 = *(longlong *)(param_1 + 0x30);
  uVar7 = 0;
  uVar6 = 0;
  if (lVar5 != 0) {
    lVar8 = 0x20;
    lVar9 = 0x20;
    while ((int)uVar6 < *(int *)(lVar5 + 0x18)) {
      lVar5 = *(longlong *)(param_1 + 0x30);
      if (lVar5 == 0) goto code_r0x000181432279;
      if (*(uint *)(lVar5 + 0x18) <= uVar6) goto code_r0x000181432285;
      lVar5 = *(longlong *)(lVar5 + 0x10);
      if (lVar5 == 0) goto code_r0x000181432279;
      if (*(uint *)(lVar5 + 0x18) <= uVar6) goto code_r0x00018143227f;
      lVar2 = *(longlong *)(param_1 + 0x38);
      if (lVar2 == 0) goto code_r0x000181432279;
      if (*(uint *)(lVar2 + 0x18) <= uVar6) goto code_r0x000181432285;
      lVar2 = *(longlong *)(lVar2 + 0x10);
      if (lVar2 == 0) goto code_r0x000181432279;
      if (*(uint *)(lVar2 + 0x18) <= uVar6) goto code_r0x00018143227f;
      if (*(longlong *)(param_1 + 0x28) == 0) goto code_r0x000181432279;
      uVar4 = *(undefined8 *)
               (*(longlong *)(*(longlong *)(lRam0000000182d64df0 + 0x20) + 0xc0) + 0x100);
      FUN_180eba640(*(longlong *)(param_1 + 0x28),*(undefined8 *)(lVar9 + lVar5),
                    *(undefined8 *)(lVar9 + lVar2),CONCAT71((int7)((ulonglong)uVar4 >> 8),2),uVar4);
      lVar5 = *(longlong *)(param_1 + 0x30);
      uVar6 = uVar6 + 1;
      lVar9 = lVar9 + 8;
      if (lVar5 == 0) goto code_r0x000181432279;
    }
    uVar4 = FUN_1802c43a0(uRam0000000182d64dd8);
    FUN_180e95b10(uVar4,uRam0000000182d64de0);
    bVar10 = DAT_182eb5d50 != 0;
    *(undefined8 *)(param_1 + 0x48) = uVar4;
    if (bVar10) {
      uVar6 = (uint)(param_1 + 0x48U >> 0xc);
      lVar5 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
        LOCK();
        bVar10 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
        if (bVar10) {
          *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar1 | 1L << (uVar6 & 0x3f);
        }
        UNLOCK();
      } while (!bVar10);
    }
    lVar5 = *(longlong *)(param_1 + 0x40);
    if (lVar5 == 0) goto code_r0x000181432279;
    do {
      if (*(int *)(lVar5 + 0x18) <= (int)uVar7) {
        return;
      }
      lVar5 = *(longlong *)(param_1 + 0x40);
      if (lVar5 == 0) break;
      if (*(uint *)(lVar5 + 0x18) <= uVar7) {
code_r0x000181432285:
        FUN_181640100(0);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      lVar5 = *(longlong *)(lVar5 + 0x10);
      if (lVar5 == 0) break;
      if (*(uint *)(lVar5 + 0x18) <= uVar7) {
code_r0x00018143227f:
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      if (*(longlong *)(param_1 + 0x48) == 0) break;
      FUN_180eb08f0(*(longlong *)(param_1 + 0x48),*(undefined8 *)(lVar8 + lVar5),uVar7,2,
                    *(undefined8 *)
                     (*(longlong *)(*(longlong *)(lRam0000000182d64dc8 + 0x20) + 0xc0) + 0x100));
      lVar5 = *(longlong *)(param_1 + 0x40);
      uVar7 = uVar7 + 1;
      lVar8 = lVar8 + 8;
    } while (lVar5 != 0);
  }
code_r0x000181432279:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

