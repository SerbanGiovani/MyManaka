// Ghidra pseudocode; not original source or compilable C.
// ev_324e2581425c348d67e33ac3a160073eba9ab40e58ca92914f8ca600cbf61512

void ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryItemView__Initialize__060019b8
               (longlong param_1,longlong param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5)

{
  char cVar1;
  ulonglong uVar2;
  longlong *plVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  code *pcVar6;
  longlong lVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  undefined4 auStackX_18 [4];
  
  auStackX_18[0] = param_3;
  if (cRam0000000182eb7c30 == '\0') {
    FUN_1802f2810(&DAT_182d61538);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f3c8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c30 = '\x01';
  }
  bVar10 = DAT_182eb5d50 != 0;
  *(longlong *)(param_1 + 0x70) = param_2;
  if (bVar10) {
    uVar9 = (uint)(param_1 + 0x70U >> 0xc);
    lVar7 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar7);
      LOCK();
      bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar7);
      if (bVar10) {
        *(ulonglong *)(&DAT_182f0c920 + lVar7) = uVar2 | 1L << (uVar9 & 0x3f);
      }
      UNLOCK();
    } while (!bVar10);
  }
  uVar5 = FUN_180735660(param_1,DAT_182d61538);
  bVar10 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x78) = uVar5;
  if (bVar10) {
    uVar9 = (uint)(param_1 + 0x78U >> 0xc);
    lVar7 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar7);
      LOCK();
      bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar7);
      if (bVar10) {
        *(ulonglong *)(&DAT_182f0c920 + lVar7) = uVar2 | 1L << (uVar9 & 0x3f);
      }
      UNLOCK();
    } while (!bVar10);
  }
  plVar3 = *(longlong **)(param_1 + 0x20);
  if ((param_2 != 0) &&
     (uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                        (*(undefined8 *)(param_2 + 0x20),0), plVar3 != (longlong *)0x0)) {
    (**(code **)(*plVar3 + 0x558))(plVar3,uVar5,*(undefined8 *)(*plVar3 + 0x560));
    plVar3 = *(longlong **)(param_1 + 0x28);
    uVar5 = FUN_181618010(auStackX_18,0);
    uVar5 = System_String__Concat__0600021b(uRam0000000182d5f3c8,uVar5,0);
    if (plVar3 != (longlong *)0x0) {
      (**(code **)(*plVar3 + 0x558))(plVar3,uVar5,*(undefined8 *)(*plVar3 + 0x560));
      iVar8 = DAT_182eb5d50;
      *(undefined8 *)(param_1 + 0x60) = param_4;
      if (iVar8 != 0) {
        uVar9 = (uint)(param_1 + 0x60U >> 0xc);
        lVar7 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar7);
          LOCK();
          bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar7);
          if (bVar10) {
            *(ulonglong *)(&DAT_182f0c920 + lVar7) = uVar2 | 1L << (uVar9 & 0x3f);
          }
          UNLOCK();
          iVar8 = DAT_182eb5d50;
        } while (!bVar10);
      }
      *(undefined8 *)(param_1 + 0x68) = param_5;
      if (iVar8 != 0) {
        uVar9 = (uint)(param_1 + 0x68U >> 0xc);
        lVar7 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar7);
          LOCK();
          bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar7);
          if (bVar10) {
            *(ulonglong *)(&DAT_182f0c920 + lVar7) = uVar2 | 1L << (uVar9 & 0x3f);
          }
          UNLOCK();
        } while (!bVar10);
      }
      lVar7 = *(longlong *)(param_1 + 0x30);
      if (lVar7 != 0) {
        cVar1 = *(char *)(param_2 + 0x29);
        pcVar6 = DAT_182ec1138;
        if ((DAT_182ec1138 == (code *)0x0) &&
           (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
           pcVar6 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ec1138 = pcVar6;
        (*DAT_182ec1138)(lVar7,cVar1 == '\0');
        lVar7 = *(longlong *)(param_1 + 0x38);
        uVar4 = *(undefined1 *)(param_2 + 0x2c);
        if (lVar7 != 0) {
          pcVar6 = DAT_182ec1138;
          if ((DAT_182ec1138 == (code *)0x0) &&
             (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
             pcVar6 == (code *)0x0)) {
            uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar5,0);
          }
          DAT_182ec1138 = pcVar6;
          (*DAT_182ec1138)(lVar7,uVar4);
          lVar7 = *(longlong *)(param_1 + 0x28);
          if (lVar7 != 0) {
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
            bVar10 = false;
            if (*(char *)(param_2 + 0x29) == '\0') {
              bVar10 = *(char *)(param_2 + 0x28) == '\0';
            }
            if (lVar7 != 0) {
              pcVar6 = DAT_182ec1138;
              if ((DAT_182ec1138 == (code *)0x0) &&
                 (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"
                                                ), pcVar6 == (code *)0x0)) {
                uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar5,0);
              }
              DAT_182ec1138 = pcVar6;
              (*DAT_182ec1138)(lVar7,bVar10);
              if ((*(longlong *)(param_2 + 0x30) == 0) ||
                 (*(int *)(*(longlong *)(param_2 + 0x30) + 0x10) == 0)) {
                uVar4 = 0;
              }
              else {
                uVar4 = 1;
              }
              lVar7 = *(longlong *)(param_1 + 0x40);
              *(undefined1 *)(param_1 + 0x81) = uVar4;
              if (lVar7 != 0) {
                pcVar6 = DAT_182ec1138;
                if ((DAT_182ec1138 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar6 == (code *)0x0)) {
                  uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar5,0);
                }
                DAT_182ec1138 = pcVar6;
                (*DAT_182ec1138)(lVar7,0);
                if (*(char *)(param_1 + 0x81) == '\0') {
                  lVar7 = *(longlong *)(param_1 + 0x50);
                  if (lVar7 != 0) {
                    pcVar6 = DAT_182ec1138;
                    if ((DAT_182ec1138 == (code *)0x0) &&
                       (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar6 == (code *)0x0)) {
                      uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar5,0);
                    }
                    DAT_182ec1138 = pcVar6;
                    uVar5 = 0;
code_r0x0001804ea19e:
                    /* WARNING: Could not recover jumptable at 0x0001804ea1b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    (*DAT_182ec1138)(lVar7,uVar5);
                    return;
                  }
                }
                else {
                  plVar3 = *(longlong **)(param_1 + 0x48);
                  uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                    (*(undefined8 *)(param_2 + 0x30),0);
                  if (plVar3 != (longlong *)0x0) {
                    (**(code **)(*plVar3 + 0x558))(plVar3,uVar5,*(undefined8 *)(*plVar3 + 0x560));
                    lVar7 = *(longlong *)(param_1 + 0x50);
                    if (lVar7 != 0) {
                      pcVar6 = DAT_182ec1138;
                      if ((DAT_182ec1138 == (code *)0x0) &&
                         (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar6 == (code *)0x0)) {
                        uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar5,0);
                      }
                      DAT_182ec1138 = pcVar6;
                      uVar5 = 1;
                      goto code_r0x0001804ea19e;
                    }
                  }
                }
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

