// Ghidra pseudocode; not original source or compilable C.
// ev_ffb7875f7600a6f150aaa34ea27ba76544eb3b76e711a0f52bed485ff1ae1108

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__HitSpermOnSkin__06001066
               (longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 uStack_28;
  undefined4 uStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (cRam0000000182eb775f == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d59700);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb775f = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x30) != 0) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40), lVar1 != 0)) {
    *(undefined1 *)(lVar1 + 0xa0) = 1;
    if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
       (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar1 != 0)) {
      if (*(char *)(lVar1 + 0x14) == '\0') {
        return;
      }
      if (*(longlong *)(param_1 + 0x30) != 0) {
        lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40);
        if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
            (lVar2 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar2 != 0)) &&
           (lVar2 = *(longlong *)(lVar2 + 0x18), lVar2 != 0)) {
          uStack_28 = 0;
          uStack_20 = 0;
          pcVar3 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar3 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar3 == (code *)0x0)) {
            uVar4 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar4,0);
          }
          DAT_182ec1698 = pcVar3;
          (*DAT_182ec1698)(lVar2,&uStack_28);
          uStack_c = uStack_20;
          uStack_14 = (undefined4)uStack_28;
          uStack_10 = (undefined4)((ulonglong)uStack_28 >> 0x20);
          uStack_18 = 1;
          if (lVar1 != 0) {
            *(ulonglong *)(lVar1 + 0xb8) = CONCAT44(uStack_14,1);
            *(ulonglong *)(lVar1 + 0xc0) = CONCAT44(uStack_20,uStack_10);
            return;
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

