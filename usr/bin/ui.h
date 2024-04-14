#ifndef __UIRSA__
#define __UIRSA__

#include "uilib.h"

#define MAXX       160
#define MAXY       50
#define CLRSCR     clearBlock(1, 1, MAXX, MAXY)
#define KEYSIZE    42    

extern BOX screen, rsaBox, cmdBox, keyBox, optBox, logBox, cptBox, pltBox,
           aBox  , bBox  , qBox  , pBox  , nBox;
void initUI();

#endif