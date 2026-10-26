// Ghidra pseudocode; not original source or compilable C.
// ev_4a765a1408e273eb3fe2803449ca696638e137a0af038a63a742f1655bc64010

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

void ExposureUnnoticed2_Scripts_Mission_MissionCountEcstasy__Initialize__0600142e
               (undefined8 param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  char cVar7;
  int iVar8;
  undefined8 uVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  uint uVar13;
  undefined8 uVar14;
  undefined7 uVar15;
  bool bVar16;
  
  if (cRam0000000182eb7901 == '\0') {
    FUN_1802f2810(0x182d5e210);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e208);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e200);
    LOCK();
    UNLOCK();
    cRam0000000182eb7901 = '\x01';
  }
  ExposureUnnoticed2_Scripts_Mission_MissionBase__Initialize__0600141f(param_1,param_2,0);
  uVar9 = FUN_1802c43a0(uRam0000000182d5e210);
  FUN_180665bb0(uVar9,param_1,uRam0000000182d5e200,0);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar6 = lRam0000000182d5e208;
  if (*(longlong *)(lRam0000000182d5e208 + 0x38) == 0) {
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
    if (*(longlong *)(lVar6 + 0x38) == 0) {
      FUN_1803204f0(lVar6);
    }
  }
  lVar12 = 0;
  lVar10 = **(longlong **)(lVar6 + 0x38);
  if ((*(byte *)(lVar10 + 0x135) & 1) == 0) {
    lVar10 = FUN_180320470(lVar10);
  }
  lVar10 = FUN_1802c43a0(lVar10);
  if (lVar10 != 0) {
    bVar16 = DAT_182eb5d50 != 0;
    *(undefined8 *)(lVar10 + 0x10) = uVar9;
    if (bVar16) {
      uVar13 = (uint)(lVar10 + 0x10U >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar13 & 0x1fffff) >> 6) * 8);
      do {
        uVar3 = *puVar1;
        LOCK();
        uVar2 = *puVar1;
        if (uVar3 == uVar2) {
          *puVar1 = uVar3 | 1L << (uVar13 & 0x3f);
        }
        UNLOCK();
      } while (uVar3 != uVar2);
    }
    if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d583a0);
    }
    lVar11 = *(longlong *)(*(longlong *)(DAT_182d583a0 + 0xb8) + 8);
    if (lVar11 != 0) {
      iVar8 = FUN_180e9f040(lVar11,*(undefined8 *)(lVar10 + 0x10),
                            *(undefined8 *)
                             (*(longlong *)(*(longlong *)(DAT_182d36aa0 + 0x20) + 0xc0) + 0xf8));
      if (-1 < iVar8) {
        return;
      }
      lVar11 = FUN_1802c43a0(DAT_182d36a90);
      FUN_180665bb0(lVar11,lVar10,*(undefined8 *)(*(longlong *)(lVar6 + 0x38) + 0x18),0);
      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d583a0);
      }
      lVar4 = *(longlong *)(*(longlong *)(DAT_182d583a0 + 0xb8) + 8);
      if (lVar4 != 0) {
        FUN_180eba640(lVar4,*(undefined8 *)(lVar10 + 0x10),lVar11,1,
                      *(undefined8 *)
                       (*(longlong *)(*(longlong *)(DAT_182d36a98 + 0x20) + 0xc0) + 0x100));
        uVar9 = *(undefined8 *)(*(longlong *)(lVar6 + 0x38) + 0x20);
        lVar10 = **(longlong **)(DAT_182d583a0 + 0xb8);
        if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar9 = FUN_181638ed0(uVar9,0);
        if (lVar10 != 0) {
          uVar14 = DAT_182d5f9b8;
          cVar7 = FUN_180ebb4c0(lVar10,uVar9,&stack0x00000008,DAT_182d5f9b8);
          if (cVar7 == '\0') {
            if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
              FUN_18035c820(DAT_182d583a0);
            }
            lVar10 = **(longlong **)(DAT_182d583a0 + 0xb8);
            uVar9 = *(undefined8 *)(*(longlong *)(lVar6 + 0x38) + 0x20);
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar9 = FUN_181638ed0(uVar9,0);
            if (lVar10 != 0) {
              uVar15 = (undefined7)((ulonglong)uVar14 >> 8);
              uVar14 = *(undefined8 *)
                        (*(longlong *)(*(longlong *)(DAT_182d36a78 + 0x20) + 0xc0) + 0x100);
              lVar12 = lVar11;
LAB_180993542:
              FUN_180eba640(lVar10,uVar9,lVar12,CONCAT71(uVar15,1),uVar14);
              return;
            }
          }
          else {
            if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
              FUN_18035c820(DAT_182d583a0);
            }
            lVar10 = **(longlong **)(DAT_182d583a0 + 0xb8);
            uVar9 = *(undefined8 *)(*(longlong *)(lVar6 + 0x38) + 0x20);
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar9 = FUN_181638ed0(uVar9,0);
            if (DAT_182ebbb85 == '\0') {
              FUN_1802f2810(&DAT_182d535d8);
              LOCK();
              UNLOCK();
              DAT_182ebbb85 = '\x01';
            }
            uVar5 = DAT_182d36a90;
            if ((lVar11 != 0) && (lVar12 = FUN_1802c42e0(lVar11,DAT_182d36a90), lVar12 == 0)) {
                    /* WARNING: Subroutine does not return */
              FUN_18031e210(lVar11,uVar5);
            }
            if (lVar10 != 0) {
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

