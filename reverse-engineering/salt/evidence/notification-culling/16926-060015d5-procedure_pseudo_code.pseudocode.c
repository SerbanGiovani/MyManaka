// Ghidra pseudocode; not original source or compilable C.
// ev_52863a917bf4c1262f80554a46a146dba515082728e03824bec841b4372f1dbe

void ExposureUnnoticed2_Scripts_InGame_ObjectCullCollider__OnTriggerEnter__060015d5
               (longlong param_1,longlong param_2)

{
  code *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  bool bVar5;
  
  if (cRam0000000182eb79ea == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb79ea = '\x01';
  }
  if (param_2 != 0) {
    pcVar1 = DAT_182ec1088;
    if ((DAT_182ec1088 == (code *)0x0) &&
       (pcVar1 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
       pcVar1 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec1088 = pcVar1;
    lVar2 = (*DAT_182ec1088)(param_2);
    if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
        (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar3 != 0)) &&
       (lVar3 = *(longlong *)(lVar3 + 0x38), lVar3 != 0)) {
      pcVar1 = DAT_182ec1088;
      if ((DAT_182ec1088 == (code *)0x0) &&
         (pcVar1 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
         pcVar1 == (code *)0x0)) {
        uVar4 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      DAT_182ec1088 = pcVar1;
      lVar3 = (*DAT_182ec1088)(lVar3);
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
      if (lVar2 != 0 || lVar3 != 0) {
        if (lVar3 == 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (lVar2 == 0) goto code_r0x000180499c05;
          bVar5 = *(longlong *)(lVar2 + 0x10) == 0;
        }
        else if (lVar2 == 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          bVar5 = *(longlong *)(lVar3 + 0x10) == 0;
        }
        else {
          bVar5 = lVar2 == lVar3;
        }
        if (!bVar5) {
          return;
        }
      }
      *(undefined1 *)(param_1 + 0x20) = 1;
      return;
    }
  }
code_r0x000180499c05:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

