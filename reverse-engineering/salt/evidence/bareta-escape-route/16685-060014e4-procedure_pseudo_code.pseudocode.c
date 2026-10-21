// Ghidra pseudocode; not original source or compilable C.
// ev_db3f7ce16bac87a1ce02d015fec6d05f8409bb123b93eaf6abd8c4cbffdfe446

void ExposureUnnoticed2_Scripts_InGame_GameOverController__StartSadCharacter__060014e4(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  char cVar5;
  code *pcVar6;
  undefined8 uVar7;
  uint uVar8;
  longlong lStack_60;
  ulonglong uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined *puStack_40;
  longlong lStack_38;
  ulonglong uStack_30;
  undefined8 uStack_28;
  longlong lStack_20;
  ulonglong uStack_18;
  undefined8 uStack_10;
  
  if (cRam0000000182eb795d == '\0') {
    puStack_40 = &UNK_180486429;
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_18048643a;
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb795d = '\x01';
  }
  if ((((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
       (lVar3 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar3 != 0)) &&
      (lVar3 = *(longlong *)(lVar3 + 0x48), lVar3 != 0)) &&
     (lVar3 = *(longlong *)(lVar3 + 0x60), lVar3 != 0)) {
    *(undefined4 *)(lVar3 + 0x1c) = 0;
    if (((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
        (lVar3 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar3 != 0)) &&
       (lVar3 = *(longlong *)(lVar3 + 0x48), lVar3 != 0)) {
      *(undefined4 *)(lVar3 + 0x10) = 0;
      if (((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
          (lVar3 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar3 != 0)) &&
         (lVar3 = *(longlong *)(lVar3 + 0x10), lVar3 != 0)) {
        pcVar6 = DAT_182ebf2f0;
        if (DAT_182ebf2f0 == (code *)0x0) {
          puStack_40 = &UNK_18048651a;
          pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Animator::set_speed(System.Single)");
          if (pcVar6 == (code *)0x0) {
            puStack_40 = &UNK_180486632;
            uVar7 = FUN_1802ced60("UnityEngine.Animator::set_speed(System.Single)");
                    /* WARNING: Subroutine does not return */
            puStack_40 = &UNK_18048663c;
            FUN_1802cca90(uVar7,0);
          }
        }
        DAT_182ebf2f0 = pcVar6;
        puStack_40 = &UNK_180486537;
        (*DAT_182ebf2f0)(lVar3);
        if (((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
            (lVar3 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar3 != 0)) &&
           (lVar3 = *(longlong *)(lVar3 + 0x60), lVar3 != 0)) {
          *(undefined4 *)(lVar3 + 0x234) = 0x2722;
          if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
              (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar3 != 0)) &&
             ((lVar3 = *(longlong *)(lVar3 + 0x30), lVar3 != 0 &&
              ((lVar3 = *(longlong *)(lVar3 + 0x40), lVar3 != 0 &&
               (lVar3 = *(longlong *)(lVar3 + 0x48), lVar3 != 0)))))) {
            uStack_10 = 0;
            uStack_18 = uStack_18 & 0xffffffff00000000;
            puStack_40 = &UNK_1804865d3;
            ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetStrafe__06000c7e
                      (lVar3,0,0);
            if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
               ((((lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar3 != 0
                  && (lVar3 = *(longlong *)(lVar3 + 0x30), lVar3 != 0)) &&
                 (lVar3 = *(longlong *)(lVar3 + 0x40), lVar3 != 0)) &&
                (lVar3 = *(longlong *)(lVar3 + 0x120), lVar3 != 0)))) {
              if (cRam0000000182eb835a == '\0') {
                FUN_1802f2810(0x182d6f960,0);
                LOCK();
                UNLOCK();
                FUN_1802f2810(0x182d6f980);
                LOCK();
                UNLOCK();
                FUN_1802f2810(0x182d6f950);
                LOCK();
                UNLOCK();
                FUN_1802f2810(0x182d6f940);
                LOCK();
                UNLOCK();
                FUN_1802f2810(0x182d6f930);
                LOCK();
                UNLOCK();
                cRam0000000182eb835a = '\x01';
              }
              lStack_60 = *(longlong *)(lVar3 + 0x50);
              if (lStack_60 == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              uStack_50 = 0;
              uStack_48 = 0;
              if (DAT_182eb5d50 != 0) {
                uVar8 = (uint)((ulonglong)&lStack_60 >> 0xc);
                puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8);
                do {
                  uVar4 = *puVar1;
                  LOCK();
                  uVar2 = *puVar1;
                  if (uVar4 == uVar2) {
                    *puVar1 = uVar4 | 1L << (uVar8 & 0x3f);
                  }
                  UNLOCK();
                } while (uVar4 != uVar2);
              }
              uStack_58 = (ulonglong)*(uint *)(lStack_60 + 0x2c);
              puStack_40 = (undefined *)0x2;
              uStack_30 = uStack_58;
              uStack_28 = 0;
              lStack_20 = 0;
              uStack_18 = 2;
              lStack_38 = lStack_60;
              while( true ) {
                cVar5 = FUN_180f89450(&lStack_38,uRam0000000182d6f950);
                if (cVar5 == '\0') {
                  return;
                }
                if (lStack_20 == 0) break;
                *(undefined1 *)(lStack_20 + 0x19) = 0;
              }
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  puStack_40 = &UNK_180486625;
  FUN_18031dad0();
}

