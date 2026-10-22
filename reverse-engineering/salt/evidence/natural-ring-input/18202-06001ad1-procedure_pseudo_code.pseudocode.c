// Ghidra pseudocode; not original source or compilable C.
// ev_1dfaded282eeb3b544ac843b373dd8923d8a70e85436db77a8f756fedf5d36bb

void ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuView__ShowUpdate__06001ad1
               (longlong param_1)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  longlong *plVar6;
  float fVar7;
  
  if (cRam0000000182eb7cbf == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7cbf = '\x01';
  }
  ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuView__AngleUpdate__06001ad2(param_1,0);
  lVar3 = *(longlong *)(param_1 + 0x88);
  if (lVar3 != 0) {
    if (*(int *)(lVar3 + 0x78) == 0) {
      iVar2 = *(int *)(lVar3 + 0x20);
    }
    else if (*(int *)(lVar3 + 0x78) == 1) {
      iVar2 = *(int *)(lVar3 + 0x24);
    }
    else if (*(int *)(lVar3 + 0x78) == 2) {
      iVar2 = *(int *)(lVar3 + 0x28);
    }
    else if (*(int *)(lVar3 + 0x78) == 3) {
      iVar2 = *(int *)(lVar3 + 0x2c);
    }
    else if (*(int *)(lVar3 + 0x78) == 4) {
      iVar2 = *(int *)(lVar3 + 0x30);
    }
    else if (*(int *)(lVar3 + 0x78) == 5) {
      iVar2 = *(int *)(lVar3 + 0x34);
    }
    else if (*(int *)(lVar3 + 0x78) == 6) {
      iVar2 = *(int *)(lVar3 + 0x38);
    }
    else if (*(int *)(lVar3 + 0x78) == 7) {
      iVar2 = *(int *)(lVar3 + 0x3c);
    }
    else {
      iVar2 = -1;
    }
    if (iVar2 == *(int *)(param_1 + 0x80)) {
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar1 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0xf,0);
      if (cVar1 != '\0') {
        lVar3 = *(longlong *)(param_1 + 0x58);
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
            lVar3 = *(longlong *)(param_1 + 0x58);
            if (lVar3 == 0) goto code_r0x0001805059ea;
            if ((*(longlong *)(lVar3 + 0x30) != 0) && (*(char *)(lVar3 + 0x38) != '\0')) {
              lVar3 = *(longlong *)(lVar3 + 0x30);
              if (*(longlong *)(lVar3 + 0x18) == 0) {
                **(undefined4 **)(lRam0000000182d62238 + 0xb8) = *(undefined4 *)(lVar3 + 0x14);
              }
              else {
                if ((lVar3 == 0) || (lVar3 = *(longlong *)(lVar3 + 0x18), lVar3 == 0))
                goto code_r0x0001805059ea;
                (**(code **)(lVar3 + 0x18))
                          (*(undefined8 *)(lVar3 + 0x40),*(undefined8 *)(lVar3 + 0x28));
              }
              if (*(longlong *)(param_1 + 0x88) == 0) goto code_r0x0001805059ea;
              *(undefined1 *)(*(longlong *)(param_1 + 0x88) + 0xe0) = 1;
            }
          }
        }
      }
      if (*(float *)(param_1 + 100) * *(float *)(param_1 + 100) +
          *(float *)(param_1 + 0x68) * *(float *)(param_1 + 0x68) <= 0.0) {
        return;
      }
      FUN_180524f50();
      FUN_180524fa0();
      FUN_180524ff0();
      FUN_180525040();
      fVar7 = (float)FUN_1803a02a0(-*(float *)(param_1 + 0x6c) + 90.0 + 360.0);
      lVar3 = *(longlong *)(param_1 + 0x50);
      uVar4 = 0;
      if (lVar3 != 0) {
        lVar5 = 0x20;
        do {
          if (*(int *)(lVar3 + 0x18) <= (int)uVar4) {
            return;
          }
          lVar3 = *(longlong *)(param_1 + 0x50);
          if (lVar3 == 0) break;
          if (*(uint *)(lVar3 + 0x18) <= uVar4) goto code_r0x0001805059f0;
          lVar3 = *(longlong *)(lVar5 + lVar3);
          if (lVar3 == 0) break;
          if (cRam0000000182eb7ca1 == '\0') {
            FUN_1802f2810(0x182d625e8);
            LOCK();
            UNLOCK();
            cRam0000000182eb7ca1 = '\x01';
          }
          lVar3 = *(longlong *)(lVar3 + 0x28);
          if (*(int *)(lRam0000000182d625e8 + 0xe0) == 0) {
            FUN_18035c820(lRam0000000182d625e8);
          }
          if (lVar3 == 0) break;
          FUN_181eea680(lVar3,**(undefined4 **)(lRam0000000182d625e8 + 0xb8),
                        uVar4 == (int)(fVar7 / 45.0),0);
          if (uVar4 == (int)(fVar7 / 45.0)) {
            lVar3 = *(longlong *)(param_1 + 0x50);
            if (lVar3 == 0) break;
            if (*(uint *)(lVar3 + 0x18) <= uVar4) goto code_r0x0001805059f0;
            *(undefined8 *)(param_1 + 0x58) = *(undefined8 *)(lVar5 + lVar3);
            FUN_18031d480(param_1 + 0x58);
          }
          lVar3 = *(longlong *)(param_1 + 0x50);
          uVar4 = uVar4 + 1;
          lVar5 = lVar5 + 8;
        } while (lVar3 != 0);
      }
    }
    else {
      lVar3 = *(longlong *)(param_1 + 0x50);
      uVar4 = 0;
      if (lVar3 != 0) {
        plVar6 = (longlong *)(lVar3 + 0x20);
        while( true ) {
          if (*(int *)(lVar3 + 0x18) <= (int)uVar4) {
            return;
          }
          if (*(uint *)(lVar3 + 0x18) <= uVar4) break;
          lVar5 = *plVar6;
          if (lVar5 == 0) goto code_r0x0001805059ea;
          if (cRam0000000182eb7ca1 == '\0') {
            FUN_1802f2810(0x182d625e8);
            LOCK();
            UNLOCK();
            cRam0000000182eb7ca1 = '\x01';
          }
          lVar5 = *(longlong *)(lVar5 + 0x28);
          if (*(int *)(lRam0000000182d625e8 + 0xe0) == 0) {
            FUN_18035c820(lRam0000000182d625e8);
          }
          if (lVar5 == 0) goto code_r0x0001805059ea;
          FUN_181eea680(lVar5,**(undefined4 **)(lRam0000000182d625e8 + 0xb8),0,0);
          uVar4 = uVar4 + 1;
          plVar6 = plVar6 + 1;
        }
code_r0x0001805059f0:
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
    }
  }
code_r0x0001805059ea:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

