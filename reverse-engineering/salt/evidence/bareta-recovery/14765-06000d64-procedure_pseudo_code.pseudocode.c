// Ghidra pseudocode; not original source or compilable C.
// ev_23bcf4f7b754b1662e2b4ef9ec8024898292c6cb8f9ee5fffaca10bad49597d3

ulonglong ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__OnFoundStrangerEvent__06000d64
                    (longlong param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  char cVar6;
  longlong lVar7;
  longlong lVar8;
  code *pcVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  longlong lVar12;
  undefined8 unaff_RDI;
  uint uVar13;
  bool bVar14;
  undefined4 uVar15;
  undefined4 unaff_XMM6_Da;
  undefined4 unaff_XMM6_Db;
  
  if (cRam0000000182eb83e6 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e108);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3e6a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3e698);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3e6a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3e690);
    LOCK();
    UNLOCK();
    cRam0000000182eb83e6 = '\x01';
  }
  uVar10 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525(0x15,0)
  ;
  if (((char)uVar10 != '\0') ||
     (uVar10 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                         (0x16,0), (char)uVar10 != '\0')) {
    return uVar10;
  }
  if ((*(longlong *)(param_1 + 0x40) != 0) &&
     ((lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar12 != 0 &&
      (lVar12 = *(longlong *)(lVar12 + 0x1f8), lVar12 != 0)))) {
    if ((*(int *)(lVar12 + 0x18) != 0) &&
       (uVar10 = FUN_180112740(*(undefined8 *)(lVar12 + 0x10),param_2), (int)uVar10 != -1)) {
      return uVar10;
    }
    if ((*(longlong *)(param_1 + 0x40) != 0) &&
       (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xe0), lVar12 != 0)) {
      if ((*(longlong *)(lVar12 + 0x10) == 0) &&
         (bVar14 = DAT_182eb5d50 != 0, *(undefined8 *)(lVar12 + 0x10) = param_2, bVar14)) {
        uVar13 = (uint)(lVar12 + 0x10U >> 0xc);
        uVar10 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
        do {
          uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
          LOCK();
          bVar14 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
          if (bVar14) {
            *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar4 | 1L << (uVar13 & 0x3f);
          }
          UNLOCK();
        } while (!bVar14);
      }
      uVar10 = *(ulonglong *)(param_1 + 0x40);
      if ((uVar10 != 0) && (*(longlong *)(uVar10 + 0x60) != 0)) {
        if (*(int *)(*(longlong *)(uVar10 + 0x60) + 0x5c) == 1) {
          return uVar10;
        }
        cVar6 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                          (0xc,0);
        if (cVar6 == '\0') {
          ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController___OnFoundStrangerEvent_g__Action_39_0__06000d69
                    (0);
          uVar10 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__ChangeState__06000d5e
                             (param_1,1,0);
          return uVar10;
        }
        uVar11 = FUN_1802c43a0(DAT_182d58368);
        FUN_1814df680(uVar11,param_1,uRam0000000182d3e698,0);
        if (*(int *)(lRam0000000182d3e690 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar12 = *(longlong *)(*(longlong *)(lRam0000000182d3e690 + 0xb8) + 0x10);
        if (lVar12 == 0) {
          if (*(int *)(lRam0000000182d3e690 + 0xe0) == 0) {
            FUN_18035c820();
          }
          uVar5 = **(undefined8 **)(lRam0000000182d3e690 + 0xb8);
          lVar12 = FUN_1802c43a0(uRam0000000182d5e108);
          FUN_180005c40(lVar12,uVar5,uRam0000000182d3e6a0);
          *(longlong *)(*(longlong *)(lRam0000000182d3e690 + 0xb8) + 0x10) = lVar12;
          FUN_18031d480(*(longlong *)(lRam0000000182d3e690 + 0xb8) + 0x10);
        }
        if (cRam0000000182eb7aa4 == '\0') {
          FUN_1802f2810(0x182d5f8e8,lVar12,0x41200000,0,CONCAT44(unaff_XMM6_Db,unaff_XMM6_Da));
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d5f8e0);
          LOCK();
          UNLOCK();
          cRam0000000182eb7aa4 = '\x01';
        }
        lVar7 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
        if (lVar7 != 0) {
          lVar7 = *(longlong *)(lVar7 + 0x50);
          lVar8 = FUN_1802c43a0(uRam0000000182d5f8e8);
          *(undefined8 *)(lVar8 + 0x10) = uVar11;
          if (DAT_182eb5d50 != 0) {
            uVar13 = (uint)(lVar8 + 0x10U >> 0xc);
            uVar10 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
            do {
              uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
              LOCK();
              bVar14 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
              if (bVar14) {
                *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar4 | 1L << (uVar13 & 0x3f);
              }
              UNLOCK();
            } while (!bVar14);
          }
          iVar2 = DAT_182eb5d50;
          *(longlong *)(lVar8 + 0x18) = lVar12;
          if (iVar2 != 0) {
            uVar13 = (uint)(lVar8 + 0x18U >> 0xc);
            uVar10 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
            do {
              uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
              LOCK();
              bVar14 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
              if (bVar14) {
                *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar4 | 1L << (uVar13 & 0x3f);
              }
              UNLOCK();
            } while (!bVar14);
          }
          pcVar9 = DAT_182ec14c0;
          if ((DAT_182ec14c0 == (code *)0x0) &&
             (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar9 == (code *)0x0)
             ) {
            uVar11 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar11,0);
          }
          DAT_182ec14c0 = pcVar9;
          uVar15 = (*DAT_182ec14c0)();
          *(undefined4 *)(lVar8 + 0x24) = uVar15;
          *(undefined4 *)(lVar8 + 0x20) = 0x41200000;
          lVar12 = lRam0000000182d5f8e0;
          if (lVar7 != 0) {
            lVar3 = *(longlong *)(lVar7 + 0x10);
            *(int *)(lVar7 + 0x1c) = *(int *)(lVar7 + 0x1c) + 1;
            if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            uVar13 = *(uint *)(lVar7 + 0x18);
            if (*(uint *)(lVar3 + 0x18) <= uVar13) {
              iVar2 = *(int *)(lVar7 + 0x18);
              FUN_18010dcd0(lVar7,iVar2 + 1,
                            *(undefined8 *)
                             (*(longlong *)
                               (*(longlong *)
                                 (*(longlong *)
                                   (*(longlong *)(*(longlong *)(lVar12 + 0x20) + 0xc0) + 0x70) +
                                 0x20) + 0xc0) + 0x78),lVar3,unaff_RDI);
              *(int *)(lVar7 + 0x18) = iVar2 + 1;
              if (*(longlong *)(lVar7 + 0x10) != 0) {
                uVar10 = FUN_180002cd0(*(longlong *)(lVar7 + 0x10),(longlong)iVar2,lVar8);
                return uVar10;
              }
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            uVar10 = (ulonglong)(uVar13 + 1);
            *(uint *)(lVar7 + 0x18) = uVar13 + 1;
            if (uVar13 < *(uint *)(lVar3 + 0x18)) {
              bVar14 = DAT_182eb5d50 != 0;
              *(longlong *)(lVar3 + 0x20 + (longlong)(int)uVar13 * 8) = lVar8;
              if (bVar14) {
                uVar13 = (uint)((ulonglong)(lVar3 + ((longlong)(int)uVar13 + 4) * 8) >> 0xc);
                puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar13 & 0x1fffff) >> 6) * 8);
                do {
                  uVar4 = *puVar1;
                  LOCK();
                  uVar10 = *puVar1;
                  bVar14 = uVar4 == uVar10;
                  if (bVar14) {
                    *puVar1 = uVar4 | 1L << (uVar13 & 0x3f);
                    uVar10 = uVar4;
                  }
                  UNLOCK();
                } while (!bVar14);
              }
              return uVar10;
            }
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
        }
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

