#ifndef __MATH_H
#define __MATH_H

#include "mytypes.h"

ul_int extEuclidean(ull_int* a, ull_int* n, long int* y, long int* t);
ul_int unsafeExtEuclidean(ull_int* a, ull_int* n, long int* y, long int* t);
ul_int MDC(ul_int a, ul_int b);
ul_int random(ul_int n);

#endif