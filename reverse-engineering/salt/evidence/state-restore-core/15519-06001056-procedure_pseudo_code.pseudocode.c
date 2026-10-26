// Ghidra pseudocode; not original source or compilable C.
// ev_96c34a05aa1fbbab61c858f623b87da7f34b9a630018494a680c61cf3ea0ff28

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__AdditionalInitializeForFixAction__06001056
               (longlong param_1,undefined4 param_2)

{
  ulonglong uVar1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  bool bVar8;
  
  if (DAT_182eb775b == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59828);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59820);
    LOCK();
    UNLOCK();
    DAT_182eb775b = '\x01';
  }
  lVar3 = FUN_1802c43a0(DAT_182d59820);
  if (lVar3 == 0) goto LAB_180428257;
  *(undefined4 *)(lVar3 + 0x18) = param_2;
  *(longlong *)(lVar3 + 0x20) = param_1;
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)(lVar3 + 0x20U >> 0xc);
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
  iVar2 = DAT_182eb5d50;
  *(longlong *)(lVar3 + 0x10) = param_1;
  if (iVar2 != 0) {
    uVar7 = (uint)(lVar3 + 0x10U >> 0xc);
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
  if (*(int *)(lVar3 + 0x18) != 10) {
    if (((*(longlong *)(lVar3 + 0x10) == 0) ||
        (lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x30), lVar5 == 0)) ||
       (lVar5 = *(longlong *)(lVar5 + 0x28), lVar5 == 0)) goto LAB_180428257;
    pcVar4 = DAT_182ec1060;
    if ((DAT_182ec1060 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Behaviour::set_enabled(System.Boolean)"),
       pcVar4 == (code *)0x0)) {
      uVar6 = FUN_1802ced60("UnityEngine.Behaviour::set_enabled(System.Boolean)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar6,0);
    }
    DAT_182ec1060 = pcVar4;
    (*DAT_182ec1060)(lVar5,0);
  }
  if (((*(int *)(lVar3 + 0x18) == 2) || (*(int *)(lVar3 + 0x18) == 1)) ||
     (*(int *)(lVar3 + 0x18) == 9)) {
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40), lVar5 == 0))
    goto LAB_180428257;
    if (*(char *)(lVar5 + 0x54) != '\0') {
      *(undefined1 *)(lVar5 + 0x54) = 0;
      if (((*(longlong *)(param_1 + 0x30) == 0) ||
          (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xc0), lVar5 == 0)) ||
         (lVar5 = *(longlong *)(lVar5 + 0x78), lVar5 == 0)) goto LAB_180428257;
      pcVar4 = DAT_182ec1088;
      if ((DAT_182ec1088 == (code *)0x0) &&
         (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
         pcVar4 == (code *)0x0)) {
        uVar6 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
      DAT_182ec1088 = pcVar4;
      lVar5 = (*DAT_182ec1088)(lVar5);
      if (lVar5 == 0) goto LAB_180428257;
      pcVar4 = DAT_182ec1138;
      if ((DAT_182ec1138 == (code *)0x0) &&
         (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
         pcVar4 == (code *)0x0)) {
        uVar6 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
      DAT_182ec1138 = pcVar4;
      (*DAT_182ec1138)(lVar5,0);
    }
    if (*(int *)(lVar3 + 0x18) == 9) {
      if ((*(longlong *)(param_1 + 0x30) == 0) ||
         (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40), lVar5 == 0)) {
LAB_180428257:
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      *(undefined1 *)(lVar5 + 0x84) = 1;
    }
  }
  uVar6 = FUN_1802c43a0(DAT_182d58368);
  FUN_1814df680(uVar6,lVar3,DAT_182d59828,0);
  ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(uVar6,3,0);
  return;
}

