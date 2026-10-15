// Ghidra pseudocode; not original source or compilable C.
// ev_05ec85353a6b8129f18251cbbe86a55b1bcc706d311d8da20272f5fac0f0c640

void System_Security_Cryptography_Rfc2898DeriveBytes___ctor__06001562
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  longlong *plVar3;
  undefined8 uVar4;
  
  uVar2 = FUN_18149cc20(0);
  plVar3 = (longlong *)System_Text_Encoding__get_UTF8__060014ff(0);
  if (plVar3 != (longlong *)0x0) {
    uVar4 = (**(code **)(*plVar3 + 600))(plVar3,param_2,*(undefined8 *)(*plVar3 + 0x260));
    System_Security_Cryptography_Rfc2898DeriveBytes___ctor__06001560
              (param_1,uVar4,param_3,param_4,uVar2,0);
    return;
  }
  FUN_18031dad0();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

