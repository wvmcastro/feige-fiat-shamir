#ifndef __TEODORO_H
#define __TEODORO_H

#include "mytypes.h"

int teodoro(void);
char authenticate(ul_int n_, ul_int* s_, ul_int* v_, char forge);
char checkPAndQ(ul_int p, ul_int q);

#endif