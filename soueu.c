#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "math.h"
#include "mytypes.h"

void throwError()
{
	printf("E\n");
	exit(0);
}

char checkNSV(ul_int n, ul_int s, ul_int v)
{
	printf("n: %lu s: %lu v: %lu\n", n, s, v);
	ull_int auxS = s;
	ull_int s2 = (auxS * auxS) % n;
	printf("s2: %llu\n", s2);
	ull_int n_ = n;
	long int a, b;

	ul_int mdc = extEuclidean(&s2, &n_, &a, &b);
	printf("mdc %lu a: %ld b: %ld\n", mdc, a , b);
	if(mdc == 1 && a == v)
		return 0;
	
	return 'E';
}

ul_int getX(ul_int n)
{
	ul_int r = rand();
	ull_int x = r * r;

	return x % n;
}

ul_int fabioReply(char bit, ul_int r, ul_int s, ul_int n)
{
	if(bit == 0)
	{
		return r;
	}
	else
	{
		ull_int xb = (r * s) % n;
		return (ul_int) xb;
	}
	
}

int fabio()
{	
	char identified = -1;
	char ret;
	char running = 1;
	char id;
	char b;

	ul_int n, s, v, r, x, xb;
	ull_int auxX;
	while(scanf(" %c", &id) != EOF && running)
	{
		switch (id)
		{
		case 'I':
			scanf("%lu %lu %lu", &n, &s, &v);
			ret = checkNSV(n, s, v);
			break;
		
		case 'X':
			x = getX(n);
			ret = 0 | identified;
			break;
		
		case 'P':
			scanf("%lu", &r);
			auxX = r * r;
			x = auxX % n;
			ret = 0 | identified;
			break;
		
		case 'R':
			scanf("%hhd", &b);
			xb = fabioReply(b, r, s, n);
			ret = 0 | identified | (b != 0 && b != 1);
			break;
		
		case 'T':
			running = 0;
			ret = 0;
			break;
		
		default:
			throwError();
			break;
		}

		switch(id | ret)
		{
			case 'I':
				identified = 0;
				printf("C\n");
				break;

			case 'X':
				printf("C %lu \n", x);
				break;
			
			case 'P':
				printf("C %lu \n", x);
				break;

			case 'T':
				printf("C\n");
				break;
			
			case 'R':
				printf("C %lu \n", xb);
				break;

			default:
				printf("E\n");
				break;
		}
	}

	return 0;
}


int main(int argc, char* argv[])
{
	srand(time(NULL));

	if(argc != 2)
		throwError();

	int r = -1;

	switch (*argv[1])
	{
	case 'F':
		r = fabio();
		break;
	case 'P':
		printf("P\n");
		break;
	case 'T':
		printf("T\n");
		break;
	case 'E':
		printf("F\n");
		break;
	
	default:
		throwError();
		break;
	}

	if(r != 0)
		throwError();

	return 0;
}