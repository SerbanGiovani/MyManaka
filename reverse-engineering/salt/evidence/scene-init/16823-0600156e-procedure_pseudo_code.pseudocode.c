// Ghidra pseudocode; not original source or compilable C.
// ev_abb784aa203b023a555b8df1a17c961e24b18239ee0d14c56cc4299a7ac0354f

/* WARNING: Removing unreachable block (ram,0x0001809936a3) */
/* WARNING: Removing unreachable block (ram,0x0001809936ab) */
/* WARNING: Removing unreachable block (ram,0x0001809936ba) */
/* WARNING: Removing unreachable block (ram,0x0001809936db) */
/* WARNING: Removing unreachable block (ram,0x0001809936e0) */
/* WARNING: Removing unreachable block (ram,0x0001809936fb) */
/* WARNING: Removing unreachable block (ram,0x000180993712) */
/* WARNING: Removing unreachable block (ram,0x00018099377e) */
/* WARNING: Removing unreachable block (ram,0x000180993717) */
/* WARNING: Removing unreachable block (ram,0x00018099371c) */
/* WARNING: Removing unreachable block (ram,0x000180993749) */
/* WARNING: Removing unreachable block (ram,0x00018099374e) */
/* WARNING: Removing unreachable block (ram,0x00018099389e) */
/* WARNING: Removing unreachable block (ram,0x00018099375a) */
/* WARNING: Removing unreachable block (ram,0x000180993781) */
/* WARNING: Removing unreachable block (ram,0x000180993775) */
/* WARNING: Removing unreachable block (ram,0x00018099378d) */
/* WARNING: Removing unreachable block (ram,0x000180993952) */
/* WARNING: Removing unreachable block (ram,0x0001809937a4) */
/* WARNING: Removing unreachable block (ram,0x0001809937a9) */
/* WARNING: Removing unreachable block (ram,0x0001809935d9) */
/* WARNING: Removing unreachable block (ram,0x0001809935de) */
/* WARNING: Removing unreachable block (ram,0x00018099360b) */
/* WARNING: Removing unreachable block (ram,0x000180993610) */
/* WARNING: Removing unreachable block (ram,0x0001809937de) */
/* WARNING: Removing unreachable block (ram,0x00018099361c) */
/* WARNING: Removing unreachable block (ram,0x000180993637) */

void ExposureUnnoticed2_Scripts_InGame_InGameEventListener__Initialize__0600156e
               (longlong param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  char cVar6;
  int iVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  ulonglong uVar12;
  uint uVar13;
  undefined8 uVar14;
  undefined7 uVar15;
  bool bVar16;
  
  if (cRam0000000182eb79ce == '\0') {
    FUN_1802f2810(0x182d57d38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d868);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d858);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d57d30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d850);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d848);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d838);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d830);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d828);
    LOCK();
    UNLOCK();
    cRam0000000182eb79ce = '\x01';
  }
  bVar16 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x10) = param_2;
  if (bVar16) {
    uVar13 = (uint)(param_1 + 0x10U >> 0xc);
    uVar12 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
      LOCK();
      bVar16 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
      if (bVar16) {
        *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar2 | 1L << (uVar13 & 0x3f);
      }
      UNLOCK();
    } while (!bVar16);
  }
  uVar8 = FUN_1802c43a0(uRam0000000182d57d38);
  FUN_180665bb0(uVar8,param_1,uRam0000000182d5d838,0);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_180993250(uVar8,0,uRam0000000182d57d30);
  uVar8 = FUN_1802c43a0(uRam0000000182d5d868);
  FUN_180665bb0(uVar8,param_1,uRam0000000182d5d830,0);
  FUN_180993250(uVar8,0,uRam0000000182d5d850);
  uVar8 = FUN_1802c43a0(uRam0000000182d5d858);
  FUN_180665bb0(uVar8,param_1,uRam0000000182d5d828,0);
  lVar5 = lRam0000000182d5d848;
  if (*(longlong *)(lRam0000000182d5d848 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d36a90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d36aa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f9b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d36a98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d36a78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar5 + 0x38) == 0) {
      FUN_1803204f0(lVar5);
    }
  }
  lVar11 = 0;
  lVar9 = **(longlong **)(lVar5 + 0x38);
  if ((*(byte *)(lVar9 + 0x135) & 1) == 0) {
    lVar9 = FUN_180320470(lVar9);
  }
  lVar9 = FUN_1802c43a0(lVar9);
  if (lVar9 != 0) {
    bVar16 = DAT_182eb5d50 != 0;
    *(undefined8 *)(lVar9 + 0x10) = uVar8;
    if (bVar16) {
      uVar13 = (uint)(lVar9 + 0x10U >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar13 & 0x1fffff) >> 6) * 8);
      do {
        uVar2 = *puVar1;
        LOCK();
        uVar12 = *puVar1;
        if (uVar2 == uVar12) {
          *puVar1 = uVar2 | 1L << (uVar13 & 0x3f);
        }
        UNLOCK();
      } while (uVar2 != uVar12);
    }
    if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d583a0);
    }
    lVar10 = *(longlong *)(*(longlong *)(DAT_182d583a0 + 0xb8) + 8);
    if (lVar10 != 0) {
      iVar7 = FUN_180e9f040(lVar10,*(undefined8 *)(lVar9 + 0x10),
                            *(undefined8 *)
                             (*(longlong *)(*(longlong *)(DAT_182d36aa0 + 0x20) + 0xc0) + 0xf8));
      if (-1 < iVar7) {
        return;
      }
      lVar10 = FUN_1802c43a0(DAT_182d36a90);
      FUN_180665bb0(lVar10,lVar9,*(undefined8 *)(*(longlong *)(lVar5 + 0x38) + 0x18),0);
      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d583a0);
      }
      lVar3 = *(longlong *)(*(longlong *)(DAT_182d583a0 + 0xb8) + 8);
      if (lVar3 != 0) {
        FUN_180eba640(lVar3,*(undefined8 *)(lVar9 + 0x10),lVar10,1,
                      *(undefined8 *)
                       (*(longlong *)(*(longlong *)(DAT_182d36a98 + 0x20) + 0xc0) + 0x100));
        uVar8 = *(undefined8 *)(*(longlong *)(lVar5 + 0x38) + 0x20);
        lVar9 = **(longlong **)(DAT_182d583a0 + 0xb8);
        if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar8 = FUN_181638ed0(uVar8,0);
        if (lVar9 != 0) {
          uVar14 = DAT_182d5f9b8;
          cVar6 = FUN_180ebb4c0(lVar9,uVar8,&stack0x00000008,DAT_182d5f9b8);
          if (cVar6 == '\0') {
            if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
              FUN_18035c820(DAT_182d583a0);
            }
            lVar9 = **(longlong **)(DAT_182d583a0 + 0xb8);
            uVar8 = *(undefined8 *)(*(longlong *)(lVar5 + 0x38) + 0x20);
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar8 = FUN_181638ed0(uVar8,0);
            if (lVar9 != 0) {
              uVar15 = (undefined7)((ulonglong)uVar14 >> 8);
              uVar14 = *(undefined8 *)
                        (*(longlong *)(*(longlong *)(DAT_182d36a78 + 0x20) + 0xc0) + 0x100);
              lVar11 = lVar10;
LAB_180993542:
              FUN_180eba640(lVar9,uVar8,lVar11,CONCAT71(uVar15,1),uVar14);
              return;
            }
          }
          else {
            if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
              FUN_18035c820(DAT_182d583a0);
            }
            lVar9 = **(longlong **)(DAT_182d583a0 + 0xb8);
            uVar8 = *(undefined8 *)(*(longlong *)(lVar5 + 0x38) + 0x20);
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar8 = FUN_181638ed0(uVar8,0);
            if (DAT_182ebbb85 == '\0') {
              FUN_1802f2810(&DAT_182d535d8);
              LOCK();
              UNLOCK();
              DAT_182ebbb85 = '\x01';
            }
            uVar4 = DAT_182d36a90;
            if ((lVar10 != 0) && (lVar11 = FUN_1802c42e0(lVar10,DAT_182d36a90), lVar11 == 0)) {
                    /* WARNING: Subroutine does not return */
              FUN_18031e210(lVar10,uVar4);
            }
            if (lVar9 != 0) {
              uVar15 = (undefined7)((ulonglong)uVar14 >> 8);
              uVar14 = *(undefined8 *)
                        (*(longlong *)(*(longlong *)(DAT_182d36a78 + 0x20) + 0xc0) + 0x100);
              goto LAB_180993542;
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

