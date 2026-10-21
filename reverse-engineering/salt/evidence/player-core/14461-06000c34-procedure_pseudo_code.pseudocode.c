// Ghidra pseudocode; not original source or compilable C.
// ev_6fe61d61a281699a7874caa81bd75bc3d85aeab38176dbe17c69eced6b0980e4

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAction__OnFrameEnd__06000c34(longlong param_1)

{
  float fVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  float fVar5;
  
  *(undefined1 *)(param_1 + 0x38) = 0;
  if ((*(longlong *)(param_1 + 0x30) == 0) ||
     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar2 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  fVar1 = *(float *)(lVar2 + 0x204);
  pcVar3 = DAT_182ec14d0;
  if ((DAT_182ec14d0 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"), pcVar3 == (code *)0x0)) {
    uVar4 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  DAT_182ec14d0 = pcVar3;
  fVar5 = (float)(*DAT_182ec14d0)();
  *(float *)(lVar2 + 0x204) = fVar1 - fVar5;
  return;
}

