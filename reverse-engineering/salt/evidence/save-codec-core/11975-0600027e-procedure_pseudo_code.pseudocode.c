// Ghidra pseudocode; not original source or compilable C.
// ev_471e18a3472a12cc8da5b9ce948345ac4863c9293078fc3642991e2ea0eab7a5

void ES3Writer__Create__0600027e(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = ES3Internal_ES3Stream__CreateStream__060006e5(param_1,1,0);
  if (lVar1 != 0) {
    ES3Writer__Create__06000280(lVar1,param_1,1,1,0);
    return;
  }
  return;
}

