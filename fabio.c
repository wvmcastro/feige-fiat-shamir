#include "fabio.h"
#include "mytypes.h"
#include "misc.h"
#include "math.h"

#include <stdio.h>
#include <stdlib.h>

int fabio()
{	
	char identified = -1;
	char answer = 0;
	char ret = -1;
	char running = 1;
	char id;
	signed char b;

	ul_int n, s, v, r, x, xb;
	while(scanf(" %c", &id) != EOF && running)
	{
		// requests
		switch (id)
		{
			case 'I':
				scanf("%lu %lu %lu", &n, &s, &v);
				ret = checkNSV(n, s, v);
				break;
			
			case 'X':
				ret = getX(n, &r, &x, 0);
				ret |= identified;
				answer = 1;
				break;
			
			case 'P':
				scanf("%lu", &r);
				ret = getX(n, &r, &x, 1);
				ret |= identified;
				answer = 1;
				break;
			
			case 'R':
				scanf("%hhd", &b);
				xb = fabioReply(b, r, s, n);
				ret = 0 | identified | (b != 0 && b != 1) | (~answer & 0x01);
				break;
			
			case 'T':
				running = 0;
				ret = 0;
				break;
			
			default:
				throwError();
				break;
		}

		// replies
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
				answer = 0;
				break;

			default:
				answer = 0;
				printf("E\n");
				break;
		}
		ret = -1;
	}

	return 0;
}

char checkNSV(ul_int n, ul_int s_, ul_int v)
{
	long int a, b;
	
	ull_int s = s_;
	ull_int n_ = n;

	ull_int s2 = s * s;
	ul_int mdc = extEuclidean(&s2, &n_, &a, &b);
	
	if(mdc == 1 && a == v)
		return 0;
	
	return 'E';
}

char getX(ul_int n, ul_int* r_, ul_int* x_, char b)
{
	ull_int x, r;
	
	if(b == 0)
	{	
		do
		{
			r = random(n);
		}
		while(MDC(r, n) != 1);
		
		*r_ = r;
	}
	else
	{
		if(*r_ < 2 || *r_ > n-1)
			return -1;
		
		ul_int mdc = MDC(*r_, n);
		if(mdc != 1)
			return -1;

		r = *r_;
	}

	x = r * r;
	*x_ = x % (ull_int) n;
	
	return 0;
}

ul_int fabioReply(char bit, ul_int r, ul_int s_, ul_int n)
{
	if(bit == 0)
	{
		return r;
	}
	else
	{
		ull_int s = s_;
		ull_int xb = (r * s) % n;
		return (ul_int) xb;
	}
	
}