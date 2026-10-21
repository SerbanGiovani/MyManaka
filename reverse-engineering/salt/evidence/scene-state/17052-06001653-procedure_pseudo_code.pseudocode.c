// Ghidra pseudocode; not original source or compilable C.
// ev_22d5cb620d5ebf0146908fc6533c3140e8ae710326e9201ef1845d956cd370bb

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

void ExposureUnnoticed2_Scripts_InGame_StageController__Start__06001653(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong *plVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined8 uVar7;
  char cVar8;
  int iVar9;
  undefined8 uVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  uint uVar14;
  undefined8 uVar15;
  undefined7 uVar16;
  bool bVar17;
  
  if (cRam0000000182eb7a2b == '\0') {
    FUN_1802f2810(0x182d5ae40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ae38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ff40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ff38);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a2b = '\x01';
  }
  lVar3 = *(longlong *)(param_1 + 0x30);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12f4 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f4 = '\x01';
  }
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec129b == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec129b = '\x01';
  }
  if (lVar3 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar3 + 0x10) != 0) {
      plVar4 = *(longlong **)(param_1 + 0x30);
      if (plVar4 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      (**(code **)(*plVar4 + 0x178))(plVar4,*(undefined8 *)(*plVar4 + 0x180));
    }
  }
  uVar10 = FUN_1802c43a0(DAT_182d58368);
  FUN_1814df680(uVar10,param_1,uRam0000000182d5ff38,0);
  ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(uVar10,1,0);
  uVar10 = FUN_1802c43a0(uRam0000000182d5ae40);
  FUN_180665bb0(uVar10,param_1,uRam0000000182d5ff40,0);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar3 = lRam0000000182d5ae38;
  if (*(longlong *)(lRam0000000182d5ae38 + 0x38) == 0) {
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
    if (*(longlong *)(lVar3 + 0x38) == 0) {
      FUN_1803204f0(lVar3);
    }
  }
  lVar13 = 0;
  lVar11 = **(longlong **)(lVar3 + 0x38);
  if ((*(byte *)(lVar11 + 0x135) & 1) == 0) {
    lVar11 = FUN_180320470(lVar11);
  }
  lVar11 = FUN_1802c43a0(lVar11);
  if (lVar11 != 0) {
    bVar17 = DAT_182eb5d50 != 0;
    *(undefined8 *)(lVar11 + 0x10) = uVar10;
    if (bVar17) {
      uVar14 = (uint)(lVar11 + 0x10U >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar14 & 0x1fffff) >> 6) * 8);
      do {
        uVar5 = *puVar1;
        LOCK();
        uVar2 = *puVar1;
        if (uVar5 == uVar2) {
          *puVar1 = uVar5 | 1L << (uVar14 & 0x3f);
        }
        UNLOCK();
      } while (uVar5 != uVar2);
    }
    if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d583a0);
    }
    lVar12 = *(longlong *)(*(longlong *)(DAT_182d583a0 + 0xb8) + 8);
    if (lVar12 != 0) {
      iVar9 = FUN_180e9f040(lVar12,*(undefined8 *)(lVar11 + 0x10),
                            *(undefined8 *)
                             (*(longlong *)(*(longlong *)(DAT_182d36aa0 + 0x20) + 0xc0) + 0xf8));
      if (-1 < iVar9) {
        return;
      }
      lVar12 = FUN_1802c43a0(DAT_182d36a90);
      FUN_180665bb0(lVar12,lVar11,*(undefined8 *)(*(longlong *)(lVar3 + 0x38) + 0x18),0);
      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d583a0);
      }
      lVar6 = *(longlong *)(*(longlong *)(DAT_182d583a0 + 0xb8) + 8);
      if (lVar6 != 0) {
        FUN_180eba640(lVar6,*(undefined8 *)(lVar11 + 0x10),lVar12,1,
                      *(undefined8 *)
                       (*(longlong *)(*(longlong *)(DAT_182d36a98 + 0x20) + 0xc0) + 0x100));
        uVar10 = *(undefined8 *)(*(longlong *)(lVar3 + 0x38) + 0x20);
        lVar11 = **(longlong **)(DAT_182d583a0 + 0xb8);
        if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar10 = FUN_181638ed0(uVar10,0);
        if (lVar11 != 0) {
          uVar15 = DAT_182d5f9b8;
          cVar8 = FUN_180ebb4c0(lVar11,uVar10,&stack0x00000008,DAT_182d5f9b8);
          if (cVar8 == '\0') {
            if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
              FUN_18035c820(DAT_182d583a0);
            }
            lVar11 = **(longlong **)(DAT_182d583a0 + 0xb8);
            uVar10 = *(undefined8 *)(*(longlong *)(lVar3 + 0x38) + 0x20);
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar10 = FUN_181638ed0(uVar10,0);
            if (lVar11 != 0) {
              uVar16 = (undefined7)((ulonglong)uVar15 >> 8);
              uVar15 = *(undefined8 *)
                        (*(longlong *)(*(longlong *)(DAT_182d36a78 + 0x20) + 0xc0) + 0x100);
              lVar13 = lVar12;
LAB_180993542:
              FUN_180eba640(lVar11,uVar10,lVar13,CONCAT71(uVar16,1),uVar15);
              return;
            }
          }
          else {
            if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
              FUN_18035c820(DAT_182d583a0);
            }
            lVar11 = **(longlong **)(DAT_182d583a0 + 0xb8);
            uVar10 = *(undefined8 *)(*(longlong *)(lVar3 + 0x38) + 0x20);
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar10 = FUN_181638ed0(uVar10,0);
            if (DAT_182ebbb85 == '\0') {
              FUN_1802f2810(&DAT_182d535d8);
              LOCK();
              UNLOCK();
              DAT_182ebbb85 = '\x01';
            }
            uVar7 = DAT_182d36a90;
            if ((lVar12 != 0) && (lVar13 = FUN_1802c42e0(lVar12,DAT_182d36a90), lVar13 == 0)) {
                    /* WARNING: Subroutine does not return */
              FUN_18031e210(lVar12,uVar7);
            }
            if (lVar11 != 0) {
              uVar16 = (undefined7)((ulonglong)uVar15 >> 8);
              uVar15 = *(undefined8 *)
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

