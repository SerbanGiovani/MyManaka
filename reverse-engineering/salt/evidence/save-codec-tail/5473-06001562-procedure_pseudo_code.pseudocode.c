// Ghidra pseudocode; not original source or compilable C.
// ev_60dc3cd3941ce2c81aa5c8d8e6eaaec46bba037a52f9d91baa575c00f0409e64

void System_Security_Cryptography_Rfc2898DeriveBytes___ctor__06001562
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  longlong *plVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_18149cc20(0);
  plVar2 = (longlong *)System_Text_Encoding__get_UTF8__060014ff(0);
  if (plVar2 != (longlong *)0x0) {
    uVar3 = (**(code **)(*plVar2 + 600))(plVar2,param_2,*(undefined8 *)(*plVar2 + 0x260));
    System_Security_Cryptography_Rfc2898DeriveBytes___ctor__06001560
              (param_1,uVar3,param_3,param_4,uVar1,0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

