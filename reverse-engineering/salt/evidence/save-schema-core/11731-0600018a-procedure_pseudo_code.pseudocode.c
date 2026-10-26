// Ghidra pseudocode; not original source or compilable C.
// ev_3362b6d46a2985bf57943ee66d5e3f618eed99e6020ccbd0546583a12c4edf17

/* WARNING: Type propagation algorithm not settling */

longlong ES3Reader__ReadType__0600018a(void)

{
  undefined8 uVar1;
  char cVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ushort *puVar8;
  ulonglong auStackX_10 [2];
  ulonglong uStackX_20;
  
  if (cRam0000000182eb7541 == '\0') {
    FUN_1802f2810(0x182d52848);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d52840);
    LOCK();
    UNLOCK();
    cRam0000000182eb7541 = '\x01';
  }
  uVar3 = FUN_180003530();
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar6 = 0;
  if (cRam0000000182eb809a == '\0') {
    FUN_1802f2810(&DAT_182d689d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d689a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d68990);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d67d08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d68938);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d68910);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a6b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d561d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d688e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d688d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d688d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d67708);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54dc0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d561c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52e58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d688c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d688b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52bf0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d676f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68ac8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e180);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d688b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d688a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d68898);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6ac68);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6abc8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6ab90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a6b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a6a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a6a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a698);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a690);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a688);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a680);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a678);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a670);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a668);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a660);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a658);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a650);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a648);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a640);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a638);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a630);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a628);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a620);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a618);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a610);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a608);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a600);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a5f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a5f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a5e8);
    LOCK();
    UNLOCK();
    cRam0000000182eb809a = '\x01';
  }
  if (uVar3 == 0) goto code_r0x00018059e03f;
  puVar8 = (ushort *)(uVar3 + 0x14);
  uVar6 = 0x811c9dc5;
  uVar7 = 0;
  while( true ) {
    uVar5 = (uint)uVar6;
    if (*(int *)(uVar3 + 0x10) <= (int)uVar7) break;
    if ((longlong)*(int *)(uVar3 + 0x10) <= (longlong)uVar7) {
                    /* WARNING: Subroutine does not return */
      FUN_18163f740(0);
    }
    uVar7 = (ulonglong)((int)uVar7 + 1);
    uVar6 = (ulonglong)((*puVar8 ^ uVar5) * 0x1000193);
    puVar8 = puVar8 + 1;
  }
  if (uVar5 < 0x9efaa16f) {
    if (uVar5 < 0x60e78bb6) {
      if (uVar5 < 0x1f088d4d) {
        if (uVar5 == 0x1543bda1) {
          lVar4 = DAT_182d561c0;
          if (uVar3 == uRam0000000182d6a650) goto code_r0x00018059d94e;
          uVar6 = uRam0000000182d6a650;
          if ((uRam0000000182d6a650 == 0) ||
             (*(int *)(uVar3 + 0x10) != *(int *)(uRam0000000182d6a650 + 0x10)))
          goto code_r0x00018059e03f;
          uVar6 = uRam0000000182d6a650 + 0x14;
          cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
          lVar4 = DAT_182d561c0;
        }
        else if (uVar5 == 0x17c16538) {
          lVar4 = DAT_182d52bf0;
          if (uVar3 == uRam0000000182d6a688) goto code_r0x00018059d94e;
          uVar6 = uRam0000000182d6a688;
          if ((uRam0000000182d6a688 == 0) ||
             (*(int *)(uVar3 + 0x10) != *(int *)(uRam0000000182d6a688 + 0x10)))
          goto code_r0x00018059e03f;
          uVar6 = uRam0000000182d6a688 + 0x14;
          cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
          lVar4 = DAT_182d52bf0;
        }
        else {
          if (uVar5 != 0x1f088d4c) goto code_r0x00018059e03f;
          lVar4 = DAT_182d68938;
          if (uVar3 == uRam0000000182d6a670) goto code_r0x00018059d94e;
          uVar6 = uRam0000000182d6a670;
          if ((uRam0000000182d6a670 == 0) ||
             (*(int *)(uVar3 + 0x10) != *(int *)(uRam0000000182d6a670 + 0x10)))
          goto code_r0x00018059e03f;
          uVar6 = uRam0000000182d6a670 + 0x14;
          cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
          lVar4 = DAT_182d68938;
        }
      }
      else if (uVar5 == 0x2ad28780) {
        lVar4 = DAT_182d535e8;
        if (uVar3 == uRam0000000182d6a610) goto code_r0x00018059d94e;
        uVar6 = uRam0000000182d6a610;
        if ((uRam0000000182d6a610 == 0) ||
           (*(int *)(uVar3 + 0x10) != *(int *)(uRam0000000182d6a610 + 0x10)))
        goto code_r0x00018059e03f;
        uVar6 = uRam0000000182d6a610 + 0x14;
        cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
        lVar4 = DAT_182d535e8;
      }
      else if (uVar5 == 0x546bdea2) {
        lVar4 = lRam0000000182d676f8;
        if (uVar3 == uRam0000000182d6a630) goto code_r0x00018059d94e;
        uVar6 = uRam0000000182d6a630;
        if ((uRam0000000182d6a630 == 0) ||
           (*(int *)(uVar3 + 0x10) != *(int *)(uRam0000000182d6a630 + 0x10)))
        goto code_r0x00018059e03f;
        uVar6 = uRam0000000182d6a630 + 0x14;
        cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
        lVar4 = lRam0000000182d676f8;
      }
      else {
        if (uVar5 != 0x60e78bb5) goto code_r0x00018059e03f;
        lVar4 = DAT_182d52e58;
        if (uVar3 == uRam0000000182d6a648) goto code_r0x00018059d94e;
        uVar6 = uRam0000000182d6a648;
        if ((uRam0000000182d6a648 == 0) ||
           (*(int *)(uVar3 + 0x10) != *(int *)(uRam0000000182d6a648 + 0x10)))
        goto code_r0x00018059e03f;
        uVar6 = uRam0000000182d6a648 + 0x14;
        cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
        lVar4 = DAT_182d52e58;
      }
    }
    else if (uVar5 < 0x83007031) {
      if (uVar5 == 0x612ac1a2) {
        lVar4 = DAT_182d688b0;
        if (uVar3 == DAT_182d6a680) goto code_r0x00018059d94e;
        uVar6 = DAT_182d6a680;
        if ((DAT_182d6a680 == 0) || (*(int *)(uVar3 + 0x10) != *(int *)(DAT_182d6a680 + 0x10)))
        goto code_r0x00018059e03f;
        uVar6 = DAT_182d6a680 + 0x14;
        cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
        lVar4 = DAT_182d688b0;
      }
      else if (uVar5 == 0x645a021f) {
        lVar4 = DAT_182d689a8;
        if (uVar3 == DAT_182d6a608) goto code_r0x00018059d94e;
        uVar6 = DAT_182d6a608;
        if ((DAT_182d6a608 == 0) || (*(int *)(uVar3 + 0x10) != *(int *)(DAT_182d6a608 + 0x10)))
        goto code_r0x00018059e03f;
        uVar6 = DAT_182d6a608 + 0x14;
        cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
        lVar4 = DAT_182d689a8;
      }
      else {
        if (uVar5 != 0x83007030) goto code_r0x00018059e03f;
        lVar4 = DAT_182d6ac68;
        if (uVar3 == uRam0000000182d6a620) goto code_r0x00018059d94e;
        uVar6 = uRam0000000182d6a620;
        if ((uRam0000000182d6a620 == 0) ||
           (*(int *)(uVar3 + 0x10) != *(int *)(uRam0000000182d6a620 + 0x10)))
        goto code_r0x00018059e03f;
        uVar6 = uRam0000000182d6a620 + 0x14;
        cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
        lVar4 = DAT_182d6ac68;
      }
    }
    else if (uVar5 < 0x890079a3) {
      if (uVar5 == 0x840071c3) {
        lVar4 = DAT_182d6abc8;
        if (uVar3 == uRam0000000182d6a638) goto code_r0x00018059d94e;
        uVar6 = uRam0000000182d6a638;
        if ((uRam0000000182d6a638 == 0) ||
           (*(int *)(uVar3 + 0x10) != *(int *)(uRam0000000182d6a638 + 0x10)))
        goto code_r0x00018059e03f;
        uVar6 = uRam0000000182d6a638 + 0x14;
        cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
        lVar4 = DAT_182d6abc8;
      }
      else {
        if (uVar5 != 0x890079a2) goto code_r0x00018059e03f;
        lVar4 = lRam0000000182d6ab90;
        if (uVar3 == uRam0000000182d6a658) goto code_r0x00018059d94e;
        uVar6 = uRam0000000182d6a658;
        if ((uRam0000000182d6a658 == 0) ||
           (*(int *)(uVar3 + 0x10) != *(int *)(uRam0000000182d6a658 + 0x10)))
        goto code_r0x00018059e03f;
        uVar6 = uRam0000000182d6a658 + 0x14;
        cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
        lVar4 = lRam0000000182d6ab90;
      }
    }
    else if (uVar5 == 0x95e97e5e) {
      lVar4 = DAT_182d688d8;
      if (uVar3 == DAT_182d6a6a8) goto code_r0x00018059d94e;
      uVar6 = DAT_182d6a6a8;
      if ((DAT_182d6a6a8 == 0) || (*(int *)(uVar3 + 0x10) != *(int *)(DAT_182d6a6a8 + 0x10)))
      goto code_r0x00018059e03f;
      uVar6 = DAT_182d6a6a8 + 0x14;
      cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
      lVar4 = DAT_182d688d8;
    }
    else {
      if (uVar5 != 0x9efaa16e) goto code_r0x00018059e03f;
      lVar4 = DAT_182d68898;
      if (uVar3 == DAT_182d6a5f8) goto code_r0x00018059d94e;
      uVar6 = DAT_182d6a5f8;
      if ((DAT_182d6a5f8 == 0) || (*(int *)(uVar3 + 0x10) != *(int *)(DAT_182d6a5f8 + 0x10)))
      goto code_r0x00018059e03f;
      uVar6 = DAT_182d6a5f8 + 0x14;
      cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
      lVar4 = DAT_182d68898;
    }
  }
  else if (uVar5 < 0xc2ecdf54) {
    if (uVar5 < 0xa84c031e) {
      if (uVar5 == 0xa0eb0f08) {
        lVar4 = DAT_182d68910;
        if (uVar3 == DAT_182d6a6b0) goto code_r0x00018059d94e;
        uVar6 = DAT_182d6a6b0;
        if ((DAT_182d6a6b0 == 0) || (*(int *)(uVar3 + 0x10) != *(int *)(DAT_182d6a6b0 + 0x10)))
        goto code_r0x00018059e03f;
        uVar6 = DAT_182d6a6b0 + 0x14;
        cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
        lVar4 = DAT_182d68910;
      }
      else if (uVar5 == 0xa6c45d85) {
        lVar4 = DAT_182d688b8;
        if (uVar3 == DAT_182d6a5f0) goto code_r0x00018059d94e;
        uVar6 = DAT_182d6a5f0;
        if ((DAT_182d6a5f0 == 0) || (*(int *)(uVar3 + 0x10) != *(int *)(DAT_182d6a5f0 + 0x10)))
        goto code_r0x00018059e03f;
        uVar6 = DAT_182d6a5f0 + 0x14;
        cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
        lVar4 = DAT_182d688b8;
      }
      else {
        if (uVar5 != 0xa84c031d) goto code_r0x00018059e03f;
        lVar4 = DAT_182d68990;
        if (uVar3 == DAT_182d6a678) goto code_r0x00018059d94e;
        uVar6 = DAT_182d6a678;
        if ((DAT_182d6a678 == 0) || (*(int *)(uVar3 + 0x10) != *(int *)(DAT_182d6a678 + 0x10)))
        goto code_r0x00018059e03f;
        uVar6 = DAT_182d6a678 + 0x14;
        cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
        lVar4 = DAT_182d68990;
      }
    }
    else if (uVar5 == 0xad82abbb) {
      lVar4 = lRam0000000182d68ac8;
      if (uVar3 == uRam0000000182d6a690) goto code_r0x00018059d94e;
      uVar6 = uRam0000000182d6a690;
      if ((uRam0000000182d6a690 == 0) ||
         (*(int *)(uVar3 + 0x10) != *(int *)(uRam0000000182d6a690 + 0x10)))
      goto code_r0x00018059e03f;
      uVar6 = uRam0000000182d6a690 + 0x14;
      cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
      lVar4 = lRam0000000182d68ac8;
    }
    else if (uVar5 == 0xba226bd5) {
      lVar4 = DAT_182d688e8;
      if (uVar3 == DAT_182d6a6a0) goto code_r0x00018059d94e;
      uVar6 = DAT_182d6a6a0;
      if ((DAT_182d6a6a0 == 0) || (*(int *)(uVar3 + 0x10) != *(int *)(DAT_182d6a6a0 + 0x10)))
      goto code_r0x00018059e03f;
      uVar6 = DAT_182d6a6a0 + 0x14;
      cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
      lVar4 = DAT_182d688e8;
    }
    else {
      if (uVar5 != 0xc2ecdf53) goto code_r0x00018059e03f;
      lVar4 = DAT_182d688d0;
      if (uVar3 == DAT_182d6a618) goto code_r0x00018059d94e;
      uVar6 = DAT_182d6a618;
      if ((DAT_182d6a618 == 0) || (*(int *)(uVar3 + 0x10) != *(int *)(DAT_182d6a618 + 0x10)))
      goto code_r0x00018059e03f;
      uVar6 = DAT_182d6a618 + 0x14;
      cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
      lVar4 = DAT_182d688d0;
    }
  }
  else if (uVar5 < 0xcb9836a2) {
    if (uVar5 == 0xc4167764) {
      lVar4 = lRam0000000182d561d8;
      if (uVar3 == uRam0000000182d6a640) goto code_r0x00018059d94e;
      uVar6 = uRam0000000182d6a640;
      if ((uRam0000000182d6a640 == 0) ||
         (*(int *)(uVar3 + 0x10) != *(int *)(uRam0000000182d6a640 + 0x10)))
      goto code_r0x00018059e03f;
      uVar6 = uRam0000000182d6a640 + 0x14;
      cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
      lVar4 = lRam0000000182d561d8;
    }
    else if (uVar5 == 0xc894953d) {
      lVar4 = DAT_182d689d0;
      if (uVar3 == uRam0000000182d6a668) goto code_r0x00018059d94e;
      uVar6 = uRam0000000182d6a668;
      if ((uRam0000000182d6a668 == 0) ||
         (*(int *)(uVar3 + 0x10) != *(int *)(uRam0000000182d6a668 + 0x10)))
      goto code_r0x00018059e03f;
      uVar6 = uRam0000000182d6a668 + 0x14;
      cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
      lVar4 = DAT_182d689d0;
    }
    else {
      if (uVar5 != 0xcb9836a1) goto code_r0x00018059e03f;
      lVar4 = DAT_182d688a0;
      if (uVar3 == DAT_182d6a600) goto code_r0x00018059d94e;
      uVar6 = DAT_182d6a600;
      if ((DAT_182d6a600 == 0) || (*(int *)(uVar3 + 0x10) != *(int *)(DAT_182d6a600 + 0x10)))
      goto code_r0x00018059e03f;
      uVar6 = DAT_182d6a600 + 0x14;
      cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
      lVar4 = DAT_182d688a0;
    }
  }
  else if (uVar5 < 0xe559d51f) {
    if (uVar5 == 0xcbd54f80) {
      lVar4 = lRam0000000182d67708;
      if (uVar3 == uRam0000000182d6a5e8) goto code_r0x00018059d94e;
      uVar6 = uRam0000000182d6a5e8;
      if ((uRam0000000182d6a5e8 == 0) ||
         (*(int *)(uVar3 + 0x10) != *(int *)(uRam0000000182d6a5e8 + 0x10)))
      goto code_r0x00018059e03f;
      uVar6 = uRam0000000182d6a5e8 + 0x14;
      cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
      lVar4 = lRam0000000182d67708;
    }
    else {
      if (uVar5 != 0xe559d51e) goto code_r0x00018059e03f;
      lVar4 = DAT_182d54dc0;
      if (uVar3 == uRam0000000182d6a660) goto code_r0x00018059d94e;
      uVar6 = uRam0000000182d6a660;
      if ((uRam0000000182d6a660 == 0) ||
         (*(int *)(uVar3 + 0x10) != *(int *)(uRam0000000182d6a660 + 0x10)))
      goto code_r0x00018059e03f;
      uVar6 = uRam0000000182d6a660 + 0x14;
      cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
      lVar4 = DAT_182d54dc0;
    }
  }
  else if (uVar5 == 0xe5b43cf8) {
    lVar4 = lRam0000000182d67d08;
    if (uVar3 == uRam0000000182d6a698) goto code_r0x00018059d94e;
    uVar6 = uRam0000000182d6a698;
    if ((uRam0000000182d6a698 == 0) ||
       (*(int *)(uVar3 + 0x10) != *(int *)(uRam0000000182d6a698 + 0x10))) goto code_r0x00018059e03f;
    uVar6 = uRam0000000182d6a698 + 0x14;
    cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
    lVar4 = lRam0000000182d67d08;
  }
  else {
    if (uVar5 != 0xf3b10488) goto code_r0x00018059e03f;
    lVar4 = DAT_182d688c8;
    if (uVar3 == DAT_182d6a628) goto code_r0x00018059d94e;
    uVar6 = DAT_182d6a628;
    if ((DAT_182d6a628 == 0) || (*(int *)(uVar3 + 0x10) != *(int *)(DAT_182d6a628 + 0x10)))
    goto code_r0x00018059e03f;
    uVar6 = DAT_182d6a628 + 0x14;
    cVar2 = FUN_181630ad0(uVar3 + 0x14,uVar6,(longlong)*(int *)(uVar3 + 0x10) * 2,0);
    lVar4 = DAT_182d688c8;
  }
  if (cVar2 == '\0') {
code_r0x00018059e03f:
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar1 = uRam0000000182d5e180;
    auStackX_10[0] = uVar6;
    uStackX_20 = FUN_18034a630(uVar3,uRam0000000182d6a6b8);
    auStackX_10[0] = 0;
    lVar4 = FUN_18035bc60(uVar1,0,&uStackX_20,auStackX_10);
    if (auStackX_10[0] == 0) {
      if ((lVar4 == 0) &&
         (uStackX_20 = uVar3, lVar4 = FUN_18035bc60(uVar1,0,&uStackX_20,auStackX_10),
         auStackX_10[0] != 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(auStackX_10[0],0);
      }
      return lVar4;
    }
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(auStackX_10[0],0);
  }
code_r0x00018059d94e:
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8,0);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  if (lVar4 != 0) {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar4 = FUN_1803613f0(lVar4,1);
    lVar4 = FUN_1802c5ac0(lVar4 + 0x20);
    return lVar4;
  }
  return 0;
}

