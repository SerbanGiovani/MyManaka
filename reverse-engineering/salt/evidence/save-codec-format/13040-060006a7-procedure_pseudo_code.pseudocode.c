// Ghidra pseudocode; not original source or compilable C.
// ev_b1535699ca29fd19a70aa6b429d03ec4715dcc25f35633fa657903cfa6fa40ed

undefined2 ES3Internal_ES3JSONReader__StartReadDictionaryKey__060006a7(undefined8 param_1)

{
  short sVar1;
  
  sVar1 = ES3Internal_ES3JSONReader__PeekCharIgnoreWhitespace__060006b7(param_1,0);
  if (sVar1 != 0x7d) {
    return 1;
  }
  ES3Internal_ES3JSONReader__ReadCharIgnoreWhitespace__060006b2(param_1,1,0);
  return 0;
}

