// Ghidra pseudocode; not original source or compilable C.
// ev_1c0ab11ced40aaddd3909377565374eb827fb8b7e3aa00307a73eab09c00d4c2

void ExposureUnnoticed2_Scripts_InGame_ObjectCulling_NpcCullArea__OnTriggerExit__060016c7
               (longlong param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  if (cRam0000000182eb7a69 == '\0') {
    FUN_1802f2810(0x182d57c40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d582a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a69 = '\x01';
  }
  if (param_2 != 0) {
    pcVar3 = DAT_182ec1088;
    if ((DAT_182ec1088 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
       pcVar3 == (code *)0x0)) {
      uVar6 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar6,0);
    }
    DAT_182ec1088 = pcVar3;
    lVar4 = (*DAT_182ec1088)(param_2);
    if (lVar4 != 0) {
      pcVar3 = pcRam0000000182ec1128;
      if ((pcRam0000000182ec1128 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_layer()"),
         pcVar3 == (code *)0x0)) {
        uVar6 = FUN_1802ced60("UnityEngine.GameObject::get_layer()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
      pcRam0000000182ec1128 = pcVar3;
      iVar1 = (*pcRam0000000182ec1128)(lVar4);
      if (*(int *)(DAT_182d582a0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      iVar2 = ExposureUnnoticed2_Scripts_Base_LayerAccessor__get_NpcLayer__0600179e(0);
      if (iVar1 != iVar2) {
        return;
      }
      if (DAT_182eb548c == '\0') {
        FUN_1802f2810(&DAT_182d57a70);
        LOCK();
        UNLOCK();
        DAT_182eb548c = '\x01';
      }
      lVar4 = **(longlong **)(DAT_182d57a70 + 0xb8);
      pcVar3 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar3 == (code *)0x0)) {
        uVar6 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
      DAT_182ec1080 = pcVar3;
      lVar5 = (*DAT_182ec1080)(param_2);
      if (lVar5 != 0) {
        pcVar3 = DAT_182ec1088;
        if ((DAT_182ec1088 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
           pcVar3 == (code *)0x0)) {
          uVar6 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar6,0);
        }
        DAT_182ec1088 = pcVar3;
        uVar6 = (*DAT_182ec1088)(lVar5);
        if (lVar4 != 0) {
          lVar4 = ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__SearchNpcController__060010a4
                            (lVar4,uVar6,0);
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
          if (lVar4 == 0) {
            return;
          }
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (*(longlong *)(lVar4 + 0x10) == 0) {
            return;
          }
          if (*(longlong *)(param_1 + 0x20) != 0) {
            FUN_180ea0010(*(longlong *)(param_1 + 0x20),lVar4,uRam0000000182d57c40);
            return;
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

