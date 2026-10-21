// Ghidra pseudocode; not original source or compilable C.
// ev_9f65b05425d12aec7d29e89865cf15f5c3bb93774374880b8181f67449db4038

void ExposureUnnoticed2_Scripts_InGame_StageController___Start_b__32_1__0600165f(longlong param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  bool bVar9;
  
  if (cRam0000000182eb7a35 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a35 = '\x01';
  }
  lVar3 = *(longlong *)(param_1 + 0x70);
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
      lVar3 = *(longlong *)(param_1 + 0x70);
      if (lVar3 == 0) goto code_r0x0001804a632d;
      if (cRam0000000182eb825c == '\0') {
        FUN_1802f2810(0x182d5ae40);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d6c0c0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5ae38);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d583a0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d6c0b8);
        LOCK();
        UNLOCK();
        cRam0000000182eb825c = '\x01';
      }
      uVar5 = FUN_1802c43a0(uRam0000000182d5ae40);
      FUN_180665bb0(uVar5,lVar3,uRam0000000182d6c0b8,0);
      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      FUN_180993250(uVar5,0,uRam0000000182d5ae38);
      lVar6 = lRam0000000182d6c0c0;
      if (*(longlong *)(lRam0000000182d6c0c0 + 0x38) == 0) {
        FUN_1803204f0(lRam0000000182d6c0c0);
      }
      uVar5 = FUN_1807366b0(lVar3,0,**(undefined8 **)(lVar6 + 0x38));
      bVar9 = DAT_182eb5d50 != 0;
      *(undefined8 *)(lVar3 + 0x28) = uVar5;
      if (bVar9) {
        uVar7 = (uint)(lVar3 + 0x28U >> 0xc);
        uVar8 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
        do {
          uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
          LOCK();
          bVar9 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
          if (bVar9) {
            *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar4 | 1L << (uVar7 & 0x3f);
          }
          UNLOCK();
        } while (!bVar9);
      }
      ExposureUnnoticed2_Object3D_ScenePlops_TalkPoint_TalkNpcManager__Spawn__06000a71(lVar3,0);
    }
  }
  lVar3 = *(longlong *)(param_1 + 0x78);
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
      lVar3 = *(longlong *)(param_1 + 0x78);
      if (lVar3 == 0) goto code_r0x0001804a632d;
      if (cRam0000000182eb7714 == '\0') {
        FUN_1802f2810(0x182d57b50);
        LOCK();
        UNLOCK();
        cRam0000000182eb7714 = '\x01';
      }
      uVar1 = *(undefined4 *)(lVar3 + 0x38);
      uVar2 = *(undefined4 *)(lVar3 + 0x3c);
      lVar6 = FUN_1802c43a0(uRam0000000182d57b50);
      bVar9 = DAT_182eb5d50 != 0;
      *(undefined4 *)(lVar6 + 0x1c) = uVar1;
      *(undefined4 *)(lVar6 + 0x20) = uVar2;
      *(undefined4 *)(lVar6 + 0x18) = 0xc97423f0;
      *(undefined1 *)(lVar6 + 0x10) = 0;
      *(undefined1 *)(lVar6 + 0x24) = 1;
      *(longlong *)(lVar3 + 0x58) = lVar6;
      if (bVar9) {
        uVar7 = (uint)(lVar3 + 0x58U >> 0xc);
        uVar8 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
        do {
          uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
          LOCK();
          bVar9 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
          if (bVar9) {
            *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar4 | 1L << (ulonglong)(uVar7 & 0x3f);
          }
          UNLOCK();
        } while (!bVar9);
      }
      uVar1 = *(undefined4 *)(lVar3 + 0x44);
      uVar2 = *(undefined4 *)(lVar3 + 0x48);
      lVar6 = FUN_1802c43a0(uRam0000000182d57b50);
      bVar9 = DAT_182eb5d50 != 0;
      *(undefined4 *)(lVar6 + 0x1c) = uVar1;
      *(undefined4 *)(lVar6 + 0x20) = uVar2;
      *(undefined4 *)(lVar6 + 0x18) = 0xc97423f0;
      *(undefined1 *)(lVar6 + 0x10) = 0;
      *(undefined1 *)(lVar6 + 0x24) = 1;
      *(longlong *)(lVar3 + 0x60) = lVar6;
      if (bVar9) {
        uVar7 = (uint)(lVar3 + 0x60U >> 0xc);
        uVar8 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
        do {
          uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
          LOCK();
          bVar9 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
          if (bVar9) {
            *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar4 | 1L << (uVar7 & 0x3f);
          }
          UNLOCK();
        } while (!bVar9);
      }
      FUN_18041a660(lVar3);
    }
  }
  lVar3 = *(longlong *)(param_1 + 0x80);
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
      if (*(longlong *)(param_1 + 0x80) == 0) goto code_r0x0001804a632d;
      ExposureUnnoticed2_Object3D_NPC_Script_SitNpcManager__Spawn__060010e1
                (*(longlong *)(param_1 + 0x80),0);
    }
  }
  lVar3 = *(longlong *)(param_1 + 0x88);
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
    if ((*(longlong *)(lVar3 + 0x10) != 0) && (*(longlong *)(param_1 + 0x88) == 0))
    goto code_r0x0001804a632d;
  }
  lVar3 = *(longlong *)(param_1 + 0x98);
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
      if (*(longlong *)(param_1 + 0x98) == 0) goto code_r0x0001804a632d;
      ExposureUnnoticed2_Object3D_ScenePlops_Conbini_ConbiniController__Initialize__06000b15
                (*(longlong *)(param_1 + 0x98),0);
    }
  }
  lVar3 = *(longlong *)(param_1 + 0xa8);
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
      if (*(longlong *)(param_1 + 0xa8) == 0) goto code_r0x0001804a632d;
      ExposureUnnoticed2_Object3D_ScenePlops_Elevator_ElevatorController__Initialize__06000ad8
                (*(longlong *)(param_1 + 0xa8),0);
    }
  }
  lVar3 = *(longlong *)(param_1 + 0x90);
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
      lVar3 = *(longlong *)(param_1 + 0x90);
      if (lVar3 == 0) goto code_r0x0001804a632d;
      if (cRam0000000182eb7792 == '\0') {
        FUN_1802f2810(0x182d5ae40);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5ae38);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d583a0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5ae30);
        LOCK();
        UNLOCK();
        cRam0000000182eb7792 = '\x01';
      }
      uVar5 = FUN_1802c43a0(uRam0000000182d5ae40);
      FUN_180665bb0(uVar5,lVar3,uRam0000000182d5ae30,0);
      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      FUN_180993250(uVar5,0,uRam0000000182d5ae38);
      ExposureUnnoticed2_Object3D_NPC_Script_PinponNpcManager__Spawn__060010ce(lVar3,0);
    }
  }
  lVar3 = *(longlong *)(param_1 + 0xa0);
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
      lVar3 = *(longlong *)(param_1 + 0xa0);
      if (lVar3 == 0) goto code_r0x0001804a632d;
      if (cRam0000000182eb8209 == '\0') {
        FUN_1802f2810(0x182d5ae40);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5ae38);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d583a0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d6c388);
        LOCK();
        UNLOCK();
        cRam0000000182eb8209 = '\x01';
      }
      ExposureUnnoticed2_Object3D_ToiletManager_ToiletManager__Reset__060009de(lVar3,0);
      uVar5 = FUN_1802c43a0(uRam0000000182d5ae40);
      FUN_180665bb0(uVar5,lVar3,uRam0000000182d6c388,0);
      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      FUN_180993250(uVar5,0,uRam0000000182d5ae38);
    }
  }
  lVar3 = *(longlong *)(param_1 + 0xb0);
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
      lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if ((lVar3 == 0) || (*(longlong *)(param_1 + 0xb0) == 0)) {
code_r0x0001804a632d:
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      ExposureUnnoticed2_Scripts_Tools_Corevale_SwapLightmap__SwapLightmapData__060013cf
                (*(longlong *)(param_1 + 0xb0),*(undefined1 *)(lVar3 + 0x20),1,0);
    }
  }
  ExposureUnnoticed2_Scripts_InGame_StageController__UpdateByDaytimeNight__06001658(param_1,1,0);
  *(undefined1 *)(param_1 + 0xd8) = 1;
  return;
}

