#include "math.h"

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