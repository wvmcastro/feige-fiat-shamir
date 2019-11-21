#include "patricia.h"
#include <stdio.h>
#include <stdlib.h>

#include "mytypes.h"
#include "misc.h"

void patricia(void)
{
    char initialized = -1;
	char ret;
	char running = 1;
	char id;
    char validated_answer = 0;

	unsigned char t_, t;
    unsigned char b;
    ul_int n, v, x, xb;

    while(scanf(" %c", &id) != EOF && running)
	{
		// requests
		switch (id)
		{
			case 'I':
				scanf("%lu %lu %hhu", &n, &v, &t_);
				t = t_;
                initialized = 0;
                ret = 0;
				break;
			
			case 'Q':
                scanf("%lu", &x);
                b = randomBit();
				ret = 0 | validated_answer;
				break;
			
			case 'V':
				scanf("%lu", &xb);
				ret = 0 | !(t != 0);
				break;
			
			case 'C':
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
				printf("C\n");
				break;printf("C\n");

			case 'Q':validated_answer = -1;
				validated_answer = -1;
				printf("C %u \n", b);
				break;
			
			case 'V':
				validated_answer = 0;
				t--;
				break;

            case 'C':
				break;

			case 'T':
				printf("C\n");
				break;

			default:
				t = t_;
				printf("E\n");
				break;
		}
	}
}

unsigned char randomBit()
{
    static unsigned int randomNumber = 0;
    static unsigned char n = 255;

    if(n == 31 || n == 255)
	{
        randomNumber = rand();
		n = 0;
	}
    
    unsigned char b = (randomNumber >> n) & 0x01;
    n++;

    return b;
}

char validate(unsigned char b, ul_int v, ul_int x, ul_int xb_, ul_int n)
{
	ull_int xb = xb_;
	ull_int a;
	if(b == 0)
	{
		if((xb*xb) % n == x)
			return 0;
	}
	else if(b == 1)
	{
		a = xb * xb;
		a %= n;
		a = (a * v) % n;

		if(a == x)
			return 0;
	}

	return -1;
}