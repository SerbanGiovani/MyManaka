// Ghidra pseudocode; not original source or compilable C.
// ev_9f620779a4cf5a544890264d02baa81b3845db09f3ecddbbf5acbc4c4217ffde

void ExposureUnnoticed2_ObjectUI_PcMenuPanel_PcMenuPanelView__Initialize__0600186c(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  char cVar3;
  longlong lVar4;
  code *pcVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined8 uStack_30;
  
  if (cRam0000000182eb7b64 == '\0') {
    FUN_1802f2810(0x182d619c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ff60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b64 = '\x01';
  }
  lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar4 == 0) || (lVar4 = *(longlong *)(lVar4 + 0x1d0), lVar4 == 0)) goto code_r0x0001804ca996;
  uVar12 = 0x3f000000;
  uVar11 = 0x3f800000;
  if (*(int *)(lVar4 + 0x20) == *(int *)(lVar4 + 0x28)) {
    uVar8 = 0x3f000000;
    uVar9 = 0x3f000000;
    uVar10 = 0x3f000000;
  }
  else {
    uVar8 = 0x3f800000;
    uVar9 = 0x3f800000;
    uVar10 = 0x3f800000;
  }
  plVar1 = *(longlong **)(param_1 + 0x78);
  if (plVar1 == (longlong *)0x0) goto code_r0x0001804ca996;
  uStack_30 = (undefined *)CONCAT44(0x3f800000,uVar10);
  uStack_38 = uVar8;
  uStack_34 = uVar9;
  (**(code **)(*plVar1 + 0x2a8))(plVar1,&uStack_38,*(undefined8 *)(*plVar1 + 0x2b0));
  plVar1 = *(longlong **)(param_1 + 0x70);
  if (DAT_182eb79c1 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb79c1 = '\x01';
  }
  lVar4 = ExposureUnnoticed2_Master_RankRelease_MRankRelease__Get__0600125c(8,0);
  if (((lVar4 == 0) ||
      (lVar4 = ExposureUnnoticed2_Master_Rank_MRank__GetByRank__06001262
                         (*(undefined4 *)(lVar4 + 0x38),0), lVar4 == 0)) ||
     (lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48), lVar2 == 0))
  goto code_r0x0001804ca996;
  if (*(int *)(lVar2 + 0x1e8) < *(int *)(lVar4 + 0x28)) {
    uVar11 = 0x3f000000;
    uVar8 = 0x3f000000;
  }
  else {
    uVar12 = 0x3f800000;
    uVar8 = 0x3f800000;
  }
  if (plVar1 == (longlong *)0x0) goto code_r0x0001804ca996;
  uStack_30 = (undefined *)CONCAT44(0x3f800000,uVar8);
  uStack_38 = uVar11;
  uStack_34 = uVar12;
  (**(code **)(*plVar1 + 0x2a8))(plVar1,&uStack_38,*(undefined8 *)(*plVar1 + 0x2b0));
  uVar7 = 0;
  if (DAT_182eb79c1 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb79c1 = '\x01';
  }
  lVar4 = ExposureUnnoticed2_Master_RankRelease_MRankRelease__Get__0600125c(10,0);
  if (((lVar4 == 0) ||
      (lVar4 = ExposureUnnoticed2_Master_Rank_MRank__GetByRank__06001262
                         (*(undefined4 *)(lVar4 + 0x38),0), lVar4 == 0)) ||
     (lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48), lVar2 == 0))
  goto code_r0x0001804ca996;
  if ((*(int *)(lVar2 + 0x1e8) < *(int *)(lVar4 + 0x28)) ||
     (9 < *(int *)(*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48) + 0x90))) {
    if (DAT_182eb79c1 == '\0') {
      FUN_1802f2810(&DAT_182d58398);
      LOCK();
      UNLOCK();
      DAT_182eb79c1 = '\x01';
    }
    lVar4 = ExposureUnnoticed2_Master_RankRelease_MRankRelease__Get__0600125c(9,0);
    if (((lVar4 == 0) ||
        (lVar4 = ExposureUnnoticed2_Master_Rank_MRank__GetByRank__06001262
                           (*(undefined4 *)(lVar4 + 0x38),0), lVar4 == 0)) ||
       (lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48), lVar2 == 0))
    goto code_r0x0001804ca996;
    if ((*(int *)(lVar4 + 0x28) <= *(int *)(lVar2 + 0x1e8)) &&
       (*(int *)(*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48) + 0x90) < 9))
    goto code_r0x0001804ca8cb;
    if (DAT_182eb79c1 == '\0') {
      FUN_1802f2810(&DAT_182d58398);
      LOCK();
      UNLOCK();
      DAT_182eb79c1 = '\x01';
    }
    lVar4 = ExposureUnnoticed2_Master_RankRelease_MRankRelease__Get__0600125c(8,0);
    if (((lVar4 == 0) ||
        (lVar4 = ExposureUnnoticed2_Master_Rank_MRank__GetByRank__06001262
                           (*(undefined4 *)(lVar4 + 0x38),0), lVar4 == 0)) ||
       (lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48), lVar2 == 0))
    goto code_r0x0001804ca996;
    if ((*(int *)(lVar4 + 0x28) <= *(int *)(lVar2 + 0x1e8)) &&
       (*(int *)(*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48) + 0x90) < 8))
    goto code_r0x0001804ca8cb;
  }
  else {
code_r0x0001804ca8cb:
    uVar7 = 1;
  }
  lVar4 = *(longlong *)(param_1 + 0x68);
  if (lVar4 != 0) {
    pcVar5 = DAT_182ec1138;
    if ((DAT_182ec1138 == (code *)0x0) &&
       (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
       pcVar5 == (code *)0x0)) {
      uVar6 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar6,0);
    }
    DAT_182ec1138 = pcVar5;
    (*DAT_182ec1138)(lVar4,uVar7);
    if (**(longlong **)(DAT_182d5aa70 + 0xb8) != 0) {
      ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                (**(longlong **)(DAT_182d5aa70 + 0xb8),0x31,0xbf800000,0,0);
      if (*(int *)(lRam0000000182d5ff60 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d5ff60);
      }
      if (**(longlong **)(lRam0000000182d5ff60 + 0xb8) != 0) {
        *(undefined1 *)(**(longlong **)(lRam0000000182d5ff60 + 0xb8) + 0x60) = 1;
        if (DAT_182eb7b65 == '\0') {
          uStack_30 = (undefined *)0x1804ca9e5;
          FUN_1802f2810(&DAT_182d5aa88,1,0);
          LOCK();
          UNLOCK();
          DAT_182eb7b65 = '\x01';
        }
        uStack_30 = (undefined *)0x1804ca9fb;
        Common_Scripts_UI_BasePanelView__IsActivePanel__06001e1c(param_1,0);
        if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
          uStack_30 = (undefined *)0x1804caa19;
          FUN_18035c820();
        }
        uStack_30 = (undefined *)0x1804caa1e;
        cVar3 = FUN_180477d40();
        lVar4 = *(longlong *)(param_1 + 0x80);
        if (cVar3 == '\0') {
          if (lVar4 != 0) {
            uStack_30 = (undefined *)0x1804caa38;
            HadakaCoat_ObjectsUi_Common_Button_ButtonGroupManager__ReceiveOnClickNotify__06001de6
                      (lVar4,0,0);
            return;
          }
        }
        else if ((lVar4 != 0) && (lVar2 = *(longlong *)(lVar4 + 0x38), lVar2 != 0)) {
          if (*(uint *)(lVar2 + 0x18) <= *(uint *)(param_1 + 0x8c)) {
                    /* WARNING: Subroutine does not return */
            uStack_30 = &UNK_1804caa7f;
            FUN_18031dae0();
          }
          HadakaCoat_ObjectsUi_Common_Button_ButtonGroupManager__ReceiveOnClickNotify__06001de6
                    (lVar4,*(undefined8 *)
                            (lVar2 + 0x20 + (longlong)(int)*(uint *)(param_1 + 0x8c) * 8),0);
          return;
        }
                    /* WARNING: Subroutine does not return */
        uStack_30 = &UNK_1804caa79;
        FUN_18031dad0();
      }
    }
  }
code_r0x0001804ca996:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

