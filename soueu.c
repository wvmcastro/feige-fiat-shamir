#include <stdio.h>

#include "math.h"
#include "mytypes.h"


int main(int argc, char* argv[])
{
	ul_int mdc;
	ull_int a, n;
	long int y, t;

	a = 3267;
	n = 2893;

	mdc = extEuclidean(&a, &n, &y, &t);

	printf("a: %llu\n", a);
	printf("n: %llu\n", n);
	printf("y: %ld\n", y);
	printf("t: %ld\n", t);
	printf("mdc: %lu\n", mdc);
}