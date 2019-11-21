#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "misc.h"
#include "fabio.h"
#include "patricia.h"

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
		patricia();
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