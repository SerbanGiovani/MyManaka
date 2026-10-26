// Ghidra pseudocode; not original source or compilable C.
// ev_b8b107d48b0bdb5fde7bde6c171086aed4b8961b46d25ef3c78ad53e15d1c7d3

void HairCustomizeData___ctor__0600129c(longlong param_1,longlong param_2)

{
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x14);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 0x18);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_2 + 0x24);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

