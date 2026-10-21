// Ghidra pseudocode; not original source or compilable C.
// ev_91d8d1cb6501f4e417808bacdf93e876a2cff282a1f36907133aee41c71d6a62

ulonglong ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimatorFpsController__Initialize__06000fe3
                    (longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  bool bVar9;
  undefined4 uVar10;
  
  if (DAT_182eb7744 == '\0') {
    FUN_1802f2810(&DAT_182d59ba8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59b98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb7744 = '\x01';
  }
  bVar9 = DAT_182eb5d50 != 0;
  *(longlong *)(param_1 + 0x18) = param_2;
  if (bVar9) {
    uVar8 = (uint)(param_1 + 0x18U >> 0xc);
    uVar6 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
    do {
      uVar7 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
      LOCK();
      bVar9 = uVar7 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar7 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
    } while (!bVar9);
  }
  lVar2 = FUN_1802c43a0(DAT_182d59ba8);
  iVar5 = DAT_182eb5d50;
  *(undefined4 *)(lVar2 + 0x14) = 5;
  *(longlong *)(param_1 + 0x10) = lVar2;
  if (iVar5 != 0) {
    uVar8 = (uint)(param_1 + 0x10U >> 0xc);
    uVar6 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
    do {
      uVar7 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
      LOCK();
      bVar9 = uVar7 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar7 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
      iVar5 = DAT_182eb5d50;
    } while (!bVar9);
  }
  if ((param_2 != 0) && (lVar2 = *(longlong *)(param_1 + 0x10), lVar2 != 0)) {
    *(undefined8 *)(lVar2 + 0x18) = *(undefined8 *)(param_2 + 0x90);
    if (iVar5 != 0) {
      uVar8 = (uint)(lVar2 + 0x18U >> 0xc);
      uVar6 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
      do {
        uVar7 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
        LOCK();
        bVar9 = uVar7 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
        if (bVar9) {
          *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar7 | 1L << (ulonglong)(uVar8 & 0x3f);
        }
        UNLOCK();
      } while (!bVar9);
    }
    pcVar3 = DAT_182ec14c0;
    if ((DAT_182ec14c0 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar3 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec14c0 = pcVar3;
    uVar10 = (*DAT_182ec14c0)();
    *(undefined4 *)(param_1 + 0x24) = uVar10;
    lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar2 != 0) {
      if (*(int *)(lVar2 + 0x10) == 0xb) {
        uVar6 = FUN_1802c43a0(DAT_182d59b98);
        if (uVar6 != 0) {
          bVar9 = DAT_182eb5d50 == 0;
          *(undefined4 *)(uVar6 + 0x10) = 10;
          *(undefined4 *)(uVar6 + 0x14) = 0x14;
          *(undefined4 *)(uVar6 + 0x18) = 0x1e;
          *(undefined4 *)(uVar6 + 0x1c) = 0x19;
          *(undefined4 *)(uVar6 + 0x20) = 10;
          *(undefined4 *)(uVar6 + 0x24) = 0x23;
          *(undefined4 *)(uVar6 + 0x28) = 5;
          *(undefined4 *)(uVar6 + 0x2c) = 2;
          *(ulonglong *)(param_1 + 0x28) = uVar6;
          if (bVar9) {
            return uVar6;
          }
          uVar8 = (uint)(param_1 + 0x28U >> 0xc);
          uVar6 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
          do {
            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
            LOCK();
            uVar7 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
            bVar9 = uVar1 == uVar7;
            if (bVar9) {
              *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar1 | 1L << (uVar8 & 0x3f);
              uVar7 = uVar1;
            }
            UNLOCK();
          } while (!bVar9);
          return uVar7;
        }
      }
      else {
        uVar6 = FUN_1802c43a0(DAT_182d59b98);
        if (uVar6 != 0) {
          bVar9 = DAT_182eb5d50 != 0;
          *(undefined4 *)(uVar6 + 0x10) = 0x14;
          *(undefined4 *)(uVar6 + 0x14) = 0x1e;
          *(undefined4 *)(uVar6 + 0x18) = 0x1e;
          *(undefined4 *)(uVar6 + 0x1c) = 0x28;
          *(undefined4 *)(uVar6 + 0x20) = 10;
          *(undefined4 *)(uVar6 + 0x24) = 0x32;
          *(undefined4 *)(uVar6 + 0x28) = 5;
          *(undefined4 *)(uVar6 + 0x2c) = 2;
          *(ulonglong *)(param_1 + 0x28) = uVar6;
          if (bVar9) {
            uVar8 = (uint)(param_1 + 0x28U >> 0xc);
            uVar7 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
            do {
              uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
              LOCK();
              uVar6 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
              bVar9 = uVar1 == uVar6;
              if (bVar9) {
                *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) = uVar1 | 1L << (uVar8 & 0x3f);
                uVar6 = uVar1;
              }
              UNLOCK();
            } while (!bVar9);
          }
          return uVar6;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

