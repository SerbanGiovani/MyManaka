// Ghidra pseudocode; not original source or compilable C.
// ev_fb40ee6b403264895133659c54508c4f20caf5e1981f3a1a0a340bd490ee6a7d

/* WARNING: Removing unreachable block (ram,0x00018049cee1) */
/* WARNING: Removing unreachable block (ram,0x00018049cf2c) */
/* WARNING: Removing unreachable block (ram,0x00018049cf3c) */
/* WARNING: Removing unreachable block (ram,0x00018049cf41) */

void __c___TransStage_b__6_2__0600166f(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  bool bVar10;
  float fVar11;
  
  if (cRam0000000182eb7a3e == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a3e = '\x01';
  }
  lVar5 = **(longlong **)(DAT_182d53c48 + 0xb8);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12f3 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f3 = '\x01';
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
  if (lVar5 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar5 + 0x10) != 0) {
      if (cRam0000000182eb79fe == '\0') {
        FUN_1802f2810(&DAT_182d58398,0xffffffff,1,0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d53c48);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d60190);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d60188);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d60180);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d60278);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d60178);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d60170);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d60168);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d60160);
        LOCK();
        UNLOCK();
        cRam0000000182eb79fe = '\x01';
      }
      uVar2 = **(undefined4 **)(lRam0000000182d60190 + 0xb8);
      ExposureUnnoticed2_Scripts_InGame_SaveManager__SaveSystem__060015ff(3,uVar2,0);
      if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
        FUN_18035c820();
      }
      ExposureUnnoticed2_Scripts_Base_SaveRapper__PreProcess__060017b8(0,uVar2,1,0);
      uVar2 = **(undefined4 **)(lRam0000000182d60190 + 0xb8);
      if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar6 = uRam0000000182d60178;
      if (cRam0000000182eb7ada == '\0') {
        FUN_1802f2810(0x182d5f488);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d60278);
        LOCK();
        UNLOCK();
        cRam0000000182eb7ada = '\x01';
      }
      if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar4 = lRam0000000182d5f488;
      lVar5 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18);
      if (*(longlong *)(lRam0000000182d5f488 + 0x38) == 0) {
        FUN_1802f2810(&DAT_182d534a8);
        LOCK();
        UNLOCK();
        if (*(longlong *)(lVar4 + 0x38) == 0) {
          FUN_1803204f0(lVar4);
        }
      }
      lVar7 = FUN_1802c43a0(DAT_182d534a8);
      ES3Settings___ctor__060001ba(lVar7,1,0);
      if ((lVar5 != 0) && (bVar10 = DAT_182eb5d50 != 0, *(longlong *)(lVar7 + 0x18) = lVar5, bVar10)
         ) {
        uVar9 = (uint)(lVar7 + 0x18U >> 0xc);
        uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
        do {
          uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
          LOCK();
          bVar10 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
          if (bVar10) {
            *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar3 | 1L << (uVar9 & 0x3f);
          }
          UNLOCK();
        } while (!bVar10);
      }
      FUN_1807488d0(uVar6,uVar2,lVar7,*(undefined8 *)(*(longlong *)(lVar4 + 0x38) + 8));
      lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar5 != 0) {
        fVar11 = *(float *)(lVar5 + 0x168);
        if (0.99 <= fVar11) {
          fVar11 = 0.99;
        }
        *(float *)(lVar5 + 0x168) = fVar11;
        lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
              (lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar4 != 0)) &&
             (lVar4 = *(longlong *)(lVar4 + 0x30), lVar4 != 0)) &&
            ((lVar4 = *(longlong *)(lVar4 + 0x40), lVar4 != 0 &&
             (lVar4 = *(longlong *)(lVar4 + 0x60), lVar4 != 0)))) &&
           ((lVar4 = *(longlong *)(lVar4 + 0x10), lVar4 != 0 && (lVar5 != 0)))) {
          *(undefined4 *)(lVar5 + 0x19c) = *(undefined4 *)(lVar4 + 0x30);
          FUN_1809ff300(uRam0000000182d60160,
                        *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48),
                        uRam0000000182d60188);
          uVar6 = DAT_182d60170;
          uVar1 = *(undefined1 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x54);
          if (cRam0000000182eb7add == '\0') {
            FUN_1802f2810(0x182d5f470);
            LOCK();
            UNLOCK();
            FUN_1802f2810(&DAT_182d60278);
            LOCK();
            UNLOCK();
            cRam0000000182eb7add = '\x01';
          }
          if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
            FUN_18035c820(DAT_182d60278);
          }
          lVar4 = lRam0000000182d5f470;
          lVar5 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18);
          if (*(longlong *)(lRam0000000182d5f470 + 0x38) == 0) {
            FUN_1802f2810(&DAT_182d534a8);
            LOCK();
            UNLOCK();
            if (*(longlong *)(lVar4 + 0x38) == 0) {
              FUN_1803204f0(lVar4);
            }
          }
          lVar7 = FUN_1802c43a0(DAT_182d534a8);
          ES3Settings___ctor__060001ba(lVar7,1,0);
          if ((lVar5 != 0) &&
             (bVar10 = DAT_182eb5d50 != 0, *(longlong *)(lVar7 + 0x18) = lVar5, bVar10)) {
            uVar9 = (uint)(lVar7 + 0x18U >> 0xc);
            uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
            do {
              uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
              LOCK();
              bVar10 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
              if (bVar10) {
                *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar3 | 1L << (uVar9 & 0x3f);
              }
              UNLOCK();
            } while (!bVar10);
          }
          FUN_180748060(uVar6,uVar1,lVar7,*(undefined8 *)(*(longlong *)(lVar4 + 0x38) + 8));
          FUN_1809ff300(uRam0000000182d60168,
                        *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60),
                        uRam0000000182d60180);
          if (cRam0000000182eb7ad9 == '\0') {
            FUN_1802f2810(&DAT_182d60278);
            LOCK();
            UNLOCK();
            cRam0000000182eb7ad9 = '\x01';
          }
          if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
            FUN_18035c820(DAT_182d60278);
          }
          *(undefined1 *)(*(longlong *)(DAT_182d60278 + 0xb8) + 4) = 0;
          return;
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
  return;
}

