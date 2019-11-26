#ifndef __ESTER_H
#define __ESTER_H

#include "mytypes.h"

int ester(void);
void calculateXAndXb(unsigned char b, ul_int v_, ul_int n_, ul_int* x_, ul_int* xb);
ul_int getS(ul_int x0, ul_int x1, ul_int n_);

#endif