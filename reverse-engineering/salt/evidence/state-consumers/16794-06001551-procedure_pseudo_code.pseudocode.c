// Ghidra pseudocode; not original source or compilable C.
// ev_814d27e7a9109e55cd957a9a0b88af3cb292e15c8493d14cfe0e0d51b745ac26

void ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551
               (undefined4 param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (cRam0000000182eb79b4 == '\0') {
    FUN_1802f2810(0x182d5daf0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dae8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dae0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dad0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa80);
    LOCK();
    UNLOCK();
    cRam0000000182eb79b4 = '\x01';
  }
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar2 != 0) && (lVar2 = *(longlong *)(lVar2 + 0x218), lVar2 != 0)) {
    iVar1 = FUN_180e6c800(lVar2,param_1,
                          *(undefined8 *)
                           (*(longlong *)(*(longlong *)(DAT_182d5dae8 + 0x20) + 0xc0) + 0xf8));
    if (iVar1 < 0) {
      lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if ((lVar2 == 0) || (lVar2 = *(longlong *)(lVar2 + 0x218), lVar2 == 0))
      goto code_r0x000180491596;
      FUN_180e72490(lVar2,param_1,0,2,
                    *(undefined8 *)
                     (*(longlong *)(*(longlong *)(lRam0000000182d5daf0 + 0x20) + 0xc0) + 0x100));
    }
    lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar2 != 0) && (lVar2 = *(longlong *)(lVar2 + 0x218), lVar2 != 0)) {
      iVar1 = FUN_180e71cd0(lVar2,param_1,DAT_182d5dae0);
      FUN_180e72490(lVar2,param_1,iVar1 + param_2,CONCAT71((uint7)(uint3)((uint)iVar1 >> 8),1),
                    *(undefined8 *)
                     (*(longlong *)(*(longlong *)(lRam0000000182d5dad0 + 0x20) + 0xc0) + 0x100));
      lVar2 = ExposureUnnoticed2_Master_Item_MItem__Get__0600127c(param_1,0);
      if (lVar2 != 0) {
        if ((*(char *)(lVar2 + 0x29) != '\0') && (0 < param_2)) {
          lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if ((lVar2 == 0) || (lVar2 = *(longlong *)(lVar2 + 0x218), lVar2 == 0))
          goto code_r0x000180491596;
          FUN_180e72490(lVar2,param_1,1,1,
                        *(undefined8 *)
                         (*(longlong *)(*(longlong *)(lRam0000000182d5dad0 + 0x20) + 0xc0) + 0x100))
          ;
        }
        if (**(longlong **)(lRam0000000182d5aa80 + 0xb8) != 0) {
          ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelView__RefreshItemCategory__060019f4
                    (**(longlong **)(lRam0000000182d5aa80 + 0xb8),0);
        }
        return;
      }
    }
  }
code_r0x000180491596:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

