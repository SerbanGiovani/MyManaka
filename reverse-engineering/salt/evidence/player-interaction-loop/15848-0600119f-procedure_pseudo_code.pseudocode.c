// Ghidra pseudocode; not original source or compilable C.
// ev_134aba30b9e251964ead8406bec81bc989e90bd1546e85d47828a1ee5c345139

void ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__OnInteract__0600119f
               (longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  char cVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  longlong *plVar8;
  
  if (cRam0000000182eb77ef == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa20);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa18);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5a9f8);
    LOCK();
    UNLOCK();
    cRam0000000182eb77ef = '\x01';
  }
  if ((param_2 == 0) || (*(longlong *)(param_2 + 0x10) == 0)) goto code_r0x000180457a36;
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0x10) + 0x10);
  if (uVar1 == 0) {
    return;
  }
  if ((uVar1 < 0x14) && ((0x88410U >> (uVar1 & 0x1f) & 1) != 0)) {
    return;
  }
  if (uVar1 == 0x11) {
    return;
  }
  if (*(int *)(*(longlong *)(param_2 + 0x10) + 0x10) == 1) {
    lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar4 == 0) goto code_r0x000180457a36;
    if ((*(int *)(lVar4 + 0x1a0) != 0) && (*(int *)(lVar4 + 0x1a0) != -1)) {
      return;
    }
    lVar4 = **(longlong **)(DAT_182d58230 + 0xb8);
    if (lVar4 == 0) goto code_r0x000180457a36;
    if (DAT_182eb83fe == '\0') {
      FUN_1802f2810(&DAT_182d3e668);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d3e660);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d5e118);
      LOCK();
      UNLOCK();
      DAT_182eb83fe = '\x01';
    }
    cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsAttachSomeHandcuffs__0600155d(0);
    uVar5 = DAT_182d3e660;
    if (cVar3 != '\0') goto code_r0x000180457a1e;
    if ((*(longlong *)(lVar4 + 0x10) == 0) ||
       (lVar2 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x60), lVar2 == 0))
    goto code_r0x000180457a36;
    uVar5 = DAT_182d3e668;
    if (*(char *)(lVar2 + 0x1b) != '\0') goto code_r0x000180457a1e;
    if (*(longlong *)(lVar2 + 0x48) == 0) goto code_r0x000180457a36;
    uVar5 = DAT_182d5e118;
    if (((*(int *)(*(longlong *)(lVar2 + 0x48) + 0x18) != -1) ||
        (lVar4 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x60), *(int *)(lVar4 + 0x5c) != 0)) ||
       (*(char *)(lVar4 + 0x50) != '\0')) goto code_r0x000180457a1e;
    lVar4 = FUN_180436330();
    if (lVar4 == 0) goto code_r0x000180457a36;
    uVar5 = DAT_182d5e118;
    if (*(char *)(lVar4 + 0x10) != '\0') goto code_r0x000180457a1e;
    if (*(int *)(lRam0000000182d5a9f8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d5a9f8 + 0xb8) + 8);
    if (lVar4 == 0) {
      if (*(int *)(lRam0000000182d5a9f8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar5 = **(undefined8 **)(lRam0000000182d5a9f8 + 0xb8);
      lVar4 = FUN_1802c43a0(DAT_182d58368);
      FUN_1814df680(lVar4,uVar5,uRam0000000182d5aa08,0);
      *(longlong *)(*(longlong *)(lRam0000000182d5a9f8 + 0xb8) + 8) = lVar4;
      FUN_18031d480(*(longlong *)(lRam0000000182d5a9f8 + 0xb8) + 8);
    }
    ExposureUnnoticed2_ObjectUI_BuyPanel_BuyPanelView__Open__06001d6c(0,lVar4,0,0);
  }
  if (*(longlong *)(param_2 + 0x10) == 0) goto code_r0x000180457a36;
  if (*(int *)(*(longlong *)(param_2 + 0x10) + 0x10) == 6) {
    lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar4 == 0) goto code_r0x000180457a36;
    if ((*(int *)(lVar4 + 0x1a0) != 0) && (*(int *)(lVar4 + 0x1a0) != -1)) {
      return;
    }
    lVar4 = **(longlong **)(DAT_182d58230 + 0xb8);
    if (lVar4 == 0) goto code_r0x000180457a36;
    if (DAT_182eb83fe == '\0') {
      FUN_1802f2810(&DAT_182d3e668);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d3e660);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d5e118);
      LOCK();
      UNLOCK();
      DAT_182eb83fe = '\x01';
    }
    cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsAttachSomeHandcuffs__0600155d(0);
    uVar5 = DAT_182d3e660;
    if (cVar3 != '\0') {
code_r0x000180457a1e:
      uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar5,0);
      ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                (uVar5,0,0);
      return;
    }
    if ((*(longlong *)(lVar4 + 0x10) == 0) ||
       (lVar2 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x60), lVar2 == 0))
    goto code_r0x000180457a36;
    uVar5 = DAT_182d3e668;
    if (*(char *)(lVar2 + 0x1b) != '\0') goto code_r0x000180457a1e;
    if (*(longlong *)(lVar2 + 0x48) == 0) goto code_r0x000180457a36;
    uVar5 = DAT_182d5e118;
    if (((*(int *)(*(longlong *)(lVar2 + 0x48) + 0x18) != -1) ||
        (lVar4 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x60), *(int *)(lVar4 + 0x5c) != 0)) ||
       (*(char *)(lVar4 + 0x50) != '\0')) goto code_r0x000180457a1e;
    lVar4 = FUN_180436330();
    if (lVar4 == 0) goto code_r0x000180457a36;
    uVar5 = DAT_182d5e118;
    if (*(char *)(lVar4 + 0x10) != '\0') goto code_r0x000180457a1e;
    if (*(int *)(lRam0000000182d5a9f8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d5a9f8 + 0xb8) + 0x10);
    if (lVar4 == 0) {
      if (*(int *)(lRam0000000182d5a9f8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar5 = **(undefined8 **)(lRam0000000182d5a9f8 + 0xb8);
      lVar4 = FUN_1802c43a0(DAT_182d58368);
      FUN_1814df680(lVar4,uVar5,uRam0000000182d5aa00,0);
      *(longlong *)(*(longlong *)(lRam0000000182d5a9f8 + 0xb8) + 0x10) = lVar4;
      FUN_18031d480(*(longlong *)(lRam0000000182d5a9f8 + 0xb8) + 0x10);
    }
    ExposureUnnoticed2_ObjectUI_BuyPanel_BuyPanelView__Open__06001d6c(1,lVar4,0,0);
  }
  if (*(longlong *)(param_2 + 0x10) == 0) goto code_r0x000180457a36;
  if (*(int *)(*(longlong *)(param_2 + 0x10) + 0x10) == 5) {
    *(undefined1 *)(param_1 + 0x22) = 1;
    uVar5 = ExposureUnnoticed2_Master_Conversation_MConversation__Get__0600132d(0,0);
    uVar6 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(uVar6,param_1,uRam0000000182d5aa18,0);
    ExposureUnnoticed2_ObjectUI_ConversationPanel_ConversationPanelView__Open__06001b99
              (uVar5,uVar6,0);
  }
  if (*(longlong *)(param_2 + 0x10) == 0) goto code_r0x000180457a36;
  if (*(int *)(*(longlong *)(param_2 + 0x10) + 0x10) == 7) {
    *(undefined1 *)(param_1 + 0x22) = 1;
    uVar5 = ExposureUnnoticed2_Master_Conversation_MConversation__Get__0600132d(1,0);
    uVar6 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(uVar6,param_1,uRam0000000182d5aa10,0);
    ExposureUnnoticed2_ObjectUI_ConversationPanel_ConversationPanelView__Open__06001b99
              (uVar5,uVar6,0);
  }
  if (*(longlong *)(param_2 + 0x10) == 0) goto code_r0x000180457a36;
  if (*(int *)(*(longlong *)(param_2 + 0x10) + 0x10) == 8) {
    ExposureUnnoticed2_ObjectUI_BarberMenu_BarberMenuView__Open__06001c8f(0);
  }
  if (*(longlong *)(param_2 + 0x10) == 0) goto code_r0x000180457a36;
  if (*(int *)(*(longlong *)(param_2 + 0x10) + 0x10) == 0xb) {
    lVar4 = **(longlong **)(DAT_182d5aa20 + 0xb8);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec12f3 == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec12f3 = '\x01';
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
    if (lVar4 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar4 + 0x10) != 0) goto code_r0x0001804578ca;
    }
    if (cRam0000000182eb7dc5 == '\0') {
      FUN_1802f2810(&DAT_182d58238);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d5aa20);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d58380);
      LOCK();
      UNLOCK();
      cRam0000000182eb7dc5 = '\x01';
    }
    if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d58380);
    }
    if (((**(longlong **)(DAT_182d58238 + 0xb8) == 0) ||
        (**(longlong **)(DAT_182d58380 + 0xb8) == 0)) ||
       (plVar7 = (longlong *)
                 ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
                           (**(longlong **)(DAT_182d58380 + 0xb8),
                            *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x168),0,0),
       plVar7 == (longlong *)0x0)) goto code_r0x000180457a36;
    if ((*(byte *)(*plVar7 + 0x130) < *(byte *)(DAT_182d5aa20 + 0x130)) ||
       (lVar4 = *(longlong *)(*plVar7 + 200),
       *(longlong *)(lVar4 + -8 + (ulonglong)*(byte *)(DAT_182d5aa20 + 0x130) * 8) != DAT_182d5aa20)
       ) goto code_r0x000180457a36;
    plVar8 = (longlong *)0x0;
    if (*(longlong *)(lVar4 + -8 + (ulonglong)*(byte *)(DAT_182d5aa20 + 0x130) * 8) == DAT_182d5aa20
       ) {
      plVar8 = plVar7;
    }
    ExposureUnnoticed2_ObjectUI_BarberMenu_ClosetMenuView__Initialize__06001c7d(plVar8,0);
  }
code_r0x0001804578ca:
  if (*(longlong *)(param_2 + 0x10) != 0) {
    if (*(int *)(*(longlong *)(param_2 + 0x10) + 0x10) == 0xd) {
      ExposureUnnoticed2_ObjectUI_ChooseHandcuffsPanel_SleepSelectPanelView__Open__06001d50(0);
    }
    if (*(longlong *)(param_2 + 0x10) != 0) {
      if (*(int *)(*(longlong *)(param_2 + 0x10) + 0x10) != 0xe) {
        return;
      }
      if (cRam0000000182eb7b6d == '\0') {
        FUN_1802f2810(&DAT_182d58238);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d58380);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d61970);
        LOCK();
        UNLOCK();
        cRam0000000182eb7b6d = '\x01';
      }
      if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d58380);
      }
      if (((**(longlong **)(DAT_182d58238 + 0xb8) != 0) &&
          (**(longlong **)(DAT_182d58380 + 0xb8) != 0)) &&
         (plVar7 = (longlong *)
                   ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
                             (**(longlong **)(DAT_182d58380 + 0xb8),
                              *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x198),0,0),
         plVar7 != (longlong *)0x0)) {
        if ((*(byte *)(lRam0000000182d61970 + 0x130) <= *(byte *)(*plVar7 + 0x130)) &&
           (lVar4 = *(longlong *)(*plVar7 + 200),
           *(longlong *)(lVar4 + -8 + (ulonglong)*(byte *)(lRam0000000182d61970 + 0x130) * 8) ==
           lRam0000000182d61970)) {
          plVar8 = (longlong *)0x0;
          if (*(longlong *)(lVar4 + -8 + (ulonglong)*(byte *)(lRam0000000182d61970 + 0x130) * 8) ==
              lRam0000000182d61970) {
            plVar8 = plVar7;
          }
          ExposureUnnoticed2_ObjectUI_PcMenuPanel_PcMenuPanelView__Initialize__0600186c(plVar8,0);
          return;
        }
      }
    }
  }
code_r0x000180457a36:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

