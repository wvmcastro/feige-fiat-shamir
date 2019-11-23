#include "math.h"
#include <stdlib.h>

ul_int extEuclidean(ull_int* a, ull_int* n, long int* y, long int* t)
{
	ul_int mdc = unsafeExtEuclidean(a, n, y, t);

	if(*y < 0)
		*y +=  *n;
	else if(*y > *n)
		*y -= *n;

	return mdc;
}

ul_int unsafeExtEuclidean(ull_int* a, ull_int* n, long int* y, long int* t)
{
	ul_int mdc;

	if(*n == 0)
	{
		*y = 1;
		*t = 0;

		return (ul_int) *a;
	}
	else
	{
		long int e, f;
		
		ull_int r = *a % *n;
		mdc = unsafeExtEuclidean(n, &r, &e, &f);

		*y = f;
		*t = e - f * (*a / *n);

		return mdc;
	}	
}

ul_int MDC(ul_int a, ul_int b)
{
	if(b == 0)
		return a;
	
	ul_int mdc = MDC(b, a % b);

	return mdc;
}

ul_int random(ul_int n)
{
	ull_int randomBits = rand();
	randomBits = randomBits << 32;
	randomBits |= rand();

	ull_int auxBits = rand();
	randomBits |= (auxBits & 0x01) << 63;
	randomBits |= (auxBits & 0x02) << 30;


	ul_int m, l, r;
	l = 1; 
	r = n;

	while(l < r-1)
	{
		m = (l + r) / 2;
		if((randomBits & 0x01) == 1) // right
			l = m;
		else
			r = m;
		
		randomBits >>= 1;
	}
	return r;
}