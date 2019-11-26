#include "misc.h"

#include <stdio.h>
#include <stdlib.h>

#include "mytypes.h"

void throwError()
{
	printf("E\n");
	exit(0);
}

unsigned char checkNAndV(ul_int n, ul_int v)
{
	if(n < 6)
		return -1;
	if(v < 2 || v > n-1)
		return -1;
	
	return 0;
}