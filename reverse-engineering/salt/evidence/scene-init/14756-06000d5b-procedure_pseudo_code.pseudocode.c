// Ghidra pseudocode; not original source or compilable C.
// ev_2f2923e05be5ef821a62853171f6d5dfca6998539ff46904577d36a95eacc728

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__Initialize__06000d5b
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  code *pcVar7;
  longlong lVar8;
  uint uVar9;
  uint uVar10;
  longlong *plVar11;
  longlong *plVar12;
  bool bVar13;
  
  if (cRam0000000182eb83e0 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3e6b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3e6c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3e6b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb83e0 = '\x01';
  }
  **(longlong **)(DAT_182d58378 + 0xb8) = param_1;
  if (DAT_182eb5d50 != 0) {
    uVar10 = (uint)(*(ulonglong *)(DAT_182d58378 + 0xb8) >> 0xc);
    lVar5 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
      LOCK();
      bVar13 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
      if (bVar13) {
        *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar3 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar13);
  }
  iVar4 = DAT_182eb5d50;
  *(undefined8 *)(param_1 + 0x20) = param_2;
  if (iVar4 != 0) {
    uVar10 = (uint)(param_1 + 0x20U >> 0xc);
    lVar5 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
      LOCK();
      bVar13 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
      if (bVar13) {
        *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar3 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar13);
  }
  lVar5 = FUN_1802c43a0(uRam0000000182d62238);
  if (cRam0000000182eb8357 == '\0') {
    FUN_1802f2810(0x182d6f9c0);
    LOCK();
    UNLOCK();
    cRam0000000182eb8357 = '\x01';
  }
  uVar6 = FUN_1802c43a0(uRam0000000182d6f9c0);
  *(undefined8 *)(lVar5 + 0x20) = uVar6;
  if (DAT_182eb5d50 != 0) {
    uVar10 = (uint)(lVar5 + 0x20U >> 0xc);
    lVar8 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar8);
      LOCK();
      bVar13 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar8);
      if (bVar13) {
        *(ulonglong *)(&DAT_182f0c920 + lVar8) = uVar3 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar13);
  }
  iVar4 = DAT_182eb5d50;
  *(longlong *)(param_1 + 0x38) = lVar5;
  if (iVar4 != 0) {
    uVar10 = (uint)(param_1 + 0x38U >> 0xc);
    lVar5 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
      LOCK();
      bVar13 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
      if (bVar13) {
        *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar3 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar13);
  }
  uVar6 = FUN_1802c43a0(uRam0000000182d3e6c0);
  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerClassAccessor___ctor__06000d31
            (uVar6,param_1,param_6,0);
  bVar13 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x40) = uVar6;
  if (bVar13) {
    uVar10 = (uint)(param_1 + 0x40U >> 0xc);
    lVar5 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
      LOCK();
      bVar13 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
      if (bVar13) {
        *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar3 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar13);
  }
  if (*(longlong *)(param_1 + 0x40) != 0) {
    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerClassAccessor__Initialize__06000d32
              (*(longlong *)(param_1 + 0x40),0);
    lVar5 = *(longlong *)(param_1 + 0x40);
    if ((lVar5 != 0) && (*(longlong *)(lVar5 + 0x58) != 0)) {
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__Initialize__06000de5
                (*(longlong *)(lVar5 + 0x58),param_3,param_4,param_5,lVar5,0);
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__ChangeLighting__06000d60
                (param_1,0);
      if ((*(longlong *)(param_1 + 0x40) != 0) &&
         (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x78), lVar5 != 0)) {
        lVar5 = *(longlong *)(lVar5 + 0x40);
        uVar10 = 0;
        if (lVar5 != 0) {
          plVar12 = (longlong *)(lVar5 + 0x20);
          do {
            if (*(int *)(lVar5 + 0x18) <= (int)uVar10) {
              uVar6 = FUN_1802c43a0(DAT_182d58368);
              FUN_1814df680(uVar6,param_1,uRam0000000182d3e6b0,0);
              if (DAT_182eb7aa1 == '\0') {
                FUN_1802f2810(&DAT_182d5f910,1,0);
                LOCK();
                UNLOCK();
                FUN_1802f2810(&DAT_182d5f908);
                LOCK();
                UNLOCK();
                DAT_182eb7aa1 = '\x01';
              }
              lVar5 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
              if (lVar5 != 0) {
                lVar5 = *(longlong *)(lVar5 + 0x20);
                lVar8 = FUN_1802c43a0(DAT_182d5f910);
                bVar13 = DAT_182eb5d50 != 0;
                *(undefined8 *)(lVar8 + 0x10) = uVar6;
                if (bVar13) {
                  uVar10 = (uint)(lVar8 + 0x10U >> 0xc);
                  puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8)
                  ;
                  do {
                    uVar2 = *puVar1;
                    LOCK();
                    uVar3 = *puVar1;
                    if (uVar2 == uVar3) {
                      *puVar1 = uVar2 | 1L << (uVar10 & 0x3f);
                    }
                    UNLOCK();
                  } while (uVar2 != uVar3);
                }
                *(undefined4 *)(lVar8 + 0x18) = 1;
                if (lVar5 != 0) {
                  FUN_1800068f0(lVar5,lVar8);
                  return;
                }
              }
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            if (*(uint *)(lVar5 + 0x18) <= uVar10) {
code_r0x000180643a0a:
                    /* WARNING: Subroutine does not return */
              FUN_18031dae0();
            }
            lVar8 = *plVar12;
            if (lVar8 == 0) break;
            pcVar7 = DAT_182ec1088;
            if ((DAT_182ec1088 == (code *)0x0) &&
               (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
               pcVar7 == (code *)0x0)) {
              uVar6 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar6,0);
            }
            DAT_182ec1088 = pcVar7;
            lVar8 = (*DAT_182ec1088)(lVar8);
            if (lVar8 == 0) break;
            lVar8 = FUN_1809a16e0(lVar8);
            uVar9 = 0;
            plVar11 = (longlong *)(lVar8 + 0x20);
            if (lVar8 == 0) break;
            for (; (int)uVar9 < (int)*(uint *)(lVar8 + 0x18); uVar9 = uVar9 + 1) {
              if (*(uint *)(lVar8 + 0x18) <= uVar9) goto code_r0x000180643a0a;
              if ((**(longlong **)(DAT_182d58238 + 0xb8) == 0) || (*plVar11 == 0))
              goto code_r0x0001806439ed;
              FUN_181ef45b0(*plVar11,*(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x388),
                            0);
              plVar11 = plVar11 + 1;
            }
            uVar10 = uVar10 + 1;
            plVar12 = plVar12 + 1;
          } while( true );
        }
      }
    }
  }
code_r0x0001806439ed:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

