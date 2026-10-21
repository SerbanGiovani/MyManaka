// Ghidra pseudocode; not original source or compilable C.
// ev_5839f71db6044d5dbecee62db1a79ba287ef780b166aea469a4af931586e3a1d

void ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b
               (undefined8 param_1,undefined4 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  bool bVar7;
  
  if (DAT_182eb7aa1 == '\0') {
    FUN_1802f2810(&DAT_182d5f910);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f908);
    LOCK();
    UNLOCK();
    DAT_182eb7aa1 = '\x01';
  }
  lVar4 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
  if (lVar4 != 0) {
    lVar4 = *(longlong *)(lVar4 + 0x20);
    lVar5 = FUN_1802c43a0(DAT_182d5f910);
    bVar7 = DAT_182eb5d50 != 0;
    *(undefined8 *)(lVar5 + 0x10) = param_1;
    if (bVar7) {
      uVar6 = (uint)(lVar5 + 0x10U >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8);
      do {
        uVar3 = *puVar1;
        LOCK();
        uVar2 = *puVar1;
        if (uVar3 == uVar2) {
          *puVar1 = uVar3 | 1L << (uVar6 & 0x3f);
        }
        UNLOCK();
      } while (uVar3 != uVar2);
    }
    *(undefined4 *)(lVar5 + 0x18) = param_2;
    if (lVar4 != 0) {
      FUN_1800068f0(lVar4,lVar5);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

