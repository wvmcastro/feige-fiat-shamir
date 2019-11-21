#ifndef __FABIO_H
#define __FABIO_H

#include "mytypes.h"

int fabio(void);
char checkNSV(ul_int n, ul_int s_, ul_int v);
char getX(ul_int n, ul_int* r_, ul_int* x, char b);
ul_int fabioReply(char bit, ul_int r, ul_int s_, ul_int n);

#endif