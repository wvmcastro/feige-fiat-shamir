#ifndef __PATRICIA_H
#define __PATRICIA_H

#include "mytypes.h"

int patricia(void);
unsigned char randomBit();
char validate(unsigned char b, ul_int v, ul_int x, ul_int xb_, ul_int n);
void patriciaError(char id, unsigned char t);

#endif