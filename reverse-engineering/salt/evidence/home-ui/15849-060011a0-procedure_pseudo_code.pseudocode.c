// Ghidra pseudocode; not original source or compilable C.
// ev_3af960f1cd9053a3b404fb7c4890cd8a27aebf2116bc7ef71f3b9199d91426c5

undefined8
ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
          (longlong param_1,longlong param_2,ulonglong param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  bool bVar8;
  
  if (DAT_182eb77f0 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5a9d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5a9c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5a9c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5a9b0);
    LOCK();
    UNLOCK();
    DAT_182eb77f0 = '\x01';
  }
  lVar2 = FUN_1802c43a0(DAT_182d5a9b0);
  if (lVar2 != 0) {
    bVar8 = DAT_182eb5d50 != 0;
    *(longlong *)(lVar2 + 0x10) = param_1;
    if (bVar8) {
      uVar7 = (uint)(lVar2 + 0x10U >> 0xc);
      lVar5 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
        LOCK();
        bVar8 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
        if (bVar8) {
          *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar1 | 1L << (uVar7 & 0x3f);
        }
        UNLOCK();
      } while (!bVar8);
    }
    if (param_2 != 0) {
      pcVar3 = DAT_182ec1088;
      if ((DAT_182ec1088 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
         pcVar3 == (code *)0x0)) {
        uVar6 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
      DAT_182ec1088 = pcVar3;
      uVar4 = (*DAT_182ec1088)(param_2);
      uVar6 = *(undefined8 *)(param_1 + 0xb0 + (param_3 & 0xff) * 8);
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar5 = FUN_1809f1050(uVar4,uVar6,DAT_182d54d90);
      if (lVar5 != 0) {
        uVar6 = FUN_1809a08f0(lVar5,DAT_182d5a9d0);
        bVar8 = DAT_182eb5d50 != 0;
        *(undefined8 *)(lVar2 + 0x18) = uVar6;
        if (bVar8) {
          uVar7 = (uint)(lVar2 + 0x18U >> 0xc);
          lVar5 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
          do {
            uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
            LOCK();
            bVar8 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
            if (bVar8) {
              *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar1 | 1L << (uVar7 & 0x3f);
            }
            UNLOCK();
          } while (!bVar8);
        }
        lVar5 = *(longlong *)(lVar2 + 0x18);
        uVar6 = FUN_1802c43a0(DAT_182d58368);
        FUN_1814df680(uVar6,lVar2,DAT_182d5a9c8,0);
        if (lVar5 != 0) {
          bVar8 = DAT_182eb5d50 != 0;
          *(undefined8 *)(lVar5 + 0x28) = uVar6;
          if (bVar8) {
            uVar7 = (uint)(lVar5 + 0x28U >> 0xc);
            lVar5 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
            do {
              uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
              LOCK();
              bVar8 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
              if (bVar8) {
                *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar1 | 1L << (uVar7 & 0x3f);
              }
              UNLOCK();
            } while (!bVar8);
          }
          *(undefined1 *)(param_1 + 0x23) = 1;
          uVar6 = FUN_1802c43a0(DAT_182d58368);
          FUN_1814df680(uVar6,lVar2,DAT_182d5a9c0,0);
          ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(uVar6,2,0);
          return *(undefined8 *)(lVar2 + 0x18);
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

