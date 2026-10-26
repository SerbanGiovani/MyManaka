// Ghidra pseudocode; not original source or compilable C.
// ev_6b7d5c47dc479598ba5f15369e6dbca09b8482d332c6f4278c03f3aa4d954d70

void ExposureUnnoticed2_Object3D_ScenePlops_CommonDoor_CommonDoorController__Awake__06000b27
               (longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  bool bVar7;
  
  if (cRam0000000182eb82c4 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bdc8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bdc0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bdb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aca0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5ac98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bdb0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bda8);
    LOCK();
    UNLOCK();
    cRam0000000182eb82c4 = '\x01';
  }
  lVar2 = *(longlong *)(param_1 + 0x20);
  uVar4 = FUN_1802c43a0(DAT_182d58368);
  FUN_1814df680(uVar4,param_1,uRam0000000182d6bdc8,0);
  if (lVar2 != 0) {
    ExposureUnnoticed2_Object3D_InteractArea_InteractAreaController__Initialize__06001180
              (lVar2,uVar4,0,0);
    if (*(longlong *)(param_1 + 0x20) != 0) {
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x40);
      lVar5 = FUN_1802c43a0(DAT_182d5ac98);
      if (lVar5 != 0) {
        bVar7 = DAT_182eb5d50 != 0;
        *(undefined8 *)(lVar5 + 0x18) = uRam0000000182d6bda8;
        if (bVar7) {
          uVar6 = (uint)(lVar5 + 0x18U >> 0xc);
          lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
          do {
            uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
            LOCK();
            bVar7 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
            if (bVar7) {
              *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar6 & 0x3f);
            }
            UNLOCK();
          } while (!bVar7);
        }
        uVar4 = FUN_1802c43a0(DAT_182d58368);
        FUN_1814df680(uVar4,param_1,uRam0000000182d6bdc0,0);
        bVar7 = DAT_182eb5d50 != 0;
        *(undefined8 *)(lVar5 + 0x10) = uVar4;
        if (bVar7) {
          uVar6 = (uint)(lVar5 + 0x10U >> 0xc);
          lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
          do {
            uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
            LOCK();
            bVar7 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
            if (bVar7) {
              *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar6 & 0x3f);
            }
            UNLOCK();
          } while (!bVar7);
        }
        if (lVar2 != 0) {
          FUN_180e545f0(lVar2,0,lVar5,2,
                        *(undefined8 *)
                         (*(longlong *)(*(longlong *)(DAT_182d5aca0 + 0x20) + 0xc0) + 0x100));
          if (*(longlong *)(param_1 + 0x20) != 0) {
            lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x40);
            lVar5 = FUN_1802c43a0(DAT_182d5ac98);
            if (lVar5 != 0) {
              bVar7 = DAT_182eb5d50 != 0;
              *(undefined8 *)(lVar5 + 0x18) = uRam0000000182d6bdb0;
              if (bVar7) {
                uVar6 = (uint)(lVar5 + 0x18U >> 0xc);
                lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
                do {
                  uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
                  LOCK();
                  bVar7 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
                  if (bVar7) {
                    *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar6 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar7);
              }
              uVar4 = FUN_1802c43a0(DAT_182d58368);
              FUN_1814df680(uVar4,param_1,uRam0000000182d6bdb8,0);
              bVar7 = DAT_182eb5d50 != 0;
              *(undefined8 *)(lVar5 + 0x10) = uVar4;
              if (bVar7) {
                uVar6 = (uint)(lVar5 + 0x10U >> 0xc);
                lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
                do {
                  uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
                  LOCK();
                  bVar7 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
                  if (bVar7) {
                    *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar6 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar7);
              }
              if (lVar2 != 0) {
                FUN_180e545f0(lVar2,1,lVar5,2,
                              *(undefined8 *)
                               (*(longlong *)(*(longlong *)(DAT_182d5aca0 + 0x20) + 0xc0) + 0x100));
                return;
              }
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

