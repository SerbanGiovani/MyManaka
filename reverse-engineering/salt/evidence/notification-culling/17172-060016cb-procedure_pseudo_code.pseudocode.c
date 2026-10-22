// Ghidra pseudocode; not original source or compilable C.
// ev_839410af94e58dd672438db08ba41e6302026d4360ce2c5e207f8e780f347b3d

void ExposureUnnoticed2_Scripts_InGame_ObjectCulling_ObjectCuller__Awake__060016cb(longlong param_1)

{
  ulonglong *puVar1;
  char cVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  code *pcVar6;
  longlong lVar7;
  undefined1 *puVar8;
  longlong lVar9;
  longlong lVar10;
  uint uVar11;
  undefined8 unaff_RDI;
  longlong *plVar12;
  bool bVar13;
  
  if (cRam0000000182eb7a6d == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fc70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fc68);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a6d = '\x01';
  }
  lVar9 = lRam0000000182d5fc70;
  if (*(longlong *)(lRam0000000182d5fc70 + 0x38) == 0) {
    FUN_1803204f0(lRam0000000182d5fc70);
  }
  uVar5 = FUN_1807366b0(param_1,0,**(undefined8 **)(lVar9 + 0x38));
  bVar13 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x30) = uVar5;
  if (bVar13) {
    uVar11 = (uint)(param_1 + 0x30U >> 0xc);
    lVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar9);
      LOCK();
      bVar13 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar9);
      if (bVar13) {
        *(ulonglong *)(&DAT_182f0c920 + lVar9) = uVar3 | 1L << (ulonglong)(uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar13);
  }
  lVar9 = *(longlong *)(param_1 + 0x30);
  uVar11 = 0;
  if (lVar9 != 0) {
    plVar12 = (longlong *)(lVar9 + 0x20);
    while( true ) {
      if (*(int *)(lVar9 + 0x18) <= (int)uVar11) {
        lVar7 = FUN_1802c43a0(DAT_182d58368);
        lVar9 = lRam0000000182d5fc68;
        bVar13 = DAT_182eb5d50 != 0;
        *(undefined8 *)(lVar7 + 0x10) = *(undefined8 *)(lRam0000000182d5fc68 + 8);
        *(longlong *)(lVar7 + 0x28) = lVar9;
        *(longlong *)(lVar7 + 0x20) = param_1;
        if (bVar13) {
          uVar11 = (uint)(lVar7 + 0x20U >> 0xc);
          lVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
          do {
            uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar10);
            LOCK();
            bVar13 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar10);
            if (bVar13) {
              *(ulonglong *)(&DAT_182f0c920 + lVar10) = uVar3 | 1L << (uVar11 & 0x3f);
            }
            UNLOCK();
          } while (!bVar13);
        }
        cVar2 = *(char *)(lVar9 + 0x52);
        *(longlong *)(lVar7 + 0x40) = lVar7;
        if (((*(byte *)(lVar9 + 0x4c) & 0x10) == 0) || (cVar2 != '\0')) {
          *(undefined8 *)(lVar7 + 0x40) = *(undefined8 *)(lVar7 + 0x20);
          puVar8 = *(undefined1 **)(lVar7 + 0x10);
        }
        else {
          puVar8 = &LAB_1800c7840;
        }
        *(undefined1 **)(lVar7 + 0x18) = puVar8;
        *(code **)(lVar7 + 0x38) = FUN_1801e91e0;
        if (DAT_182eb7aa1 == '\0') {
          FUN_1802f2810(&DAT_182d5f910,3,0,lVar7,unaff_RDI);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d5f908);
          LOCK();
          UNLOCK();
          DAT_182eb7aa1 = '\x01';
        }
        lVar9 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
        if (lVar9 != 0) {
          lVar9 = *(longlong *)(lVar9 + 0x20);
          lVar10 = FUN_1802c43a0(DAT_182d5f910);
          bVar13 = DAT_182eb5d50 != 0;
          *(longlong *)(lVar10 + 0x10) = lVar7;
          if (bVar13) {
            uVar11 = (uint)(lVar10 + 0x10U >> 0xc);
            puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8);
            do {
              uVar4 = *puVar1;
              LOCK();
              uVar3 = *puVar1;
              if (uVar4 == uVar3) {
                *puVar1 = uVar4 | 1L << (uVar11 & 0x3f);
              }
              UNLOCK();
            } while (uVar4 != uVar3);
          }
          *(undefined4 *)(lVar10 + 0x18) = 3;
          if (lVar9 != 0) {
            FUN_1800068f0(lVar9,lVar10);
            return;
          }
        }
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      if (*(uint *)(lVar9 + 0x18) <= uVar11) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      lVar7 = *plVar12;
      if (lVar7 == 0) break;
      pcVar6 = DAT_182ec1088;
      if ((DAT_182ec1088 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
         pcVar6 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec1088 = pcVar6;
      lVar7 = (*DAT_182ec1088)(lVar7);
      if (lVar7 == 0) break;
      pcVar6 = DAT_182ec1138;
      if ((DAT_182ec1138 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
         pcVar6 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec1138 = pcVar6;
      (*DAT_182ec1138)(lVar7);
      uVar11 = uVar11 + 1;
      plVar12 = plVar12 + 1;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

