// Ghidra pseudocode; not original source or compilable C.
// ev_5ae0eca51c5b800840284c72022e4f506430700947b2d8b6895b07bdf3cc548a

undefined1
ExposureUnnoticed2_Object3D_ScenePlops_CommonDoor_CommonDoorController__CanInteract__06000b29
          (longlong param_1)

{
  undefined8 uVar1;
  
  if (cRam0000000182eb82c6 == '\0') {
    FUN_1802f2810(&DAT_182d5e118);
    LOCK();
    UNLOCK();
    cRam0000000182eb82c6 = '\x01';
  }
  if (*(char *)(param_1 + 0x5b) != '\0') {
    return 1;
  }
  uVar1 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(DAT_182d5e118,0);
  ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14(uVar1,1,0);
  return 0;
}

