// Ghidra pseudocode; not original source or compilable C.
// ev_b37ae9af7abf0743f311142c053043f0668d36b6145b130e4e50001204678dd1

undefined8 System_Text_Encoding__get_UTF8__060014ff(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong *plVar4;
  uint uVar5;
  
  if (DAT_182ebbe9a == '\0') {
    FUN_1802f2810(&DAT_182d2bd98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d3b3f8);
    LOCK();
    UNLOCK();
    DAT_182ebbe9a = '\x01';
  }
  LOCK();
  UNLOCK();
  if (*(longlong *)(*(longlong *)(DAT_182d2bd98 + 0xb8) + 0x20) == 0) {
    plVar4 = (longlong *)FUN_1802c43a0(DAT_182d3b3f8);
    *(undefined1 *)((longlong)plVar4 + 0x21) = 1;
    *(undefined4 *)(plVar4 + 2) = 0xfde9;
    (**(code **)(*plVar4 + 0x188))(plVar4,*(undefined8 *)(*plVar4 + 400));
    *(undefined2 *)(plVar4 + 7) = 1;
    LOCK();
    UNLOCK();
    *(longlong **)(*(longlong *)(DAT_182d2bd98 + 0xb8) + 0x20) = plVar4;
    if (DAT_182eb5d50 != 0) {
      uVar5 = (uint)(*(longlong *)(DAT_182d2bd98 + 0xb8) + 0x20U >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
      do {
        uVar3 = *puVar1;
        LOCK();
        uVar2 = *puVar1;
        if (uVar3 == uVar2) {
          *puVar1 = uVar3 | 1L << (uVar5 & 0x3f);
        }
        UNLOCK();
      } while (uVar3 != uVar2);
    }
  }
  LOCK();
  UNLOCK();
  return *(undefined8 *)(*(longlong *)(DAT_182d2bd98 + 0xb8) + 0x20);
}

