#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "misc.h"
#include "fabio.h"
#include "patricia.h"
#include "teodoro.h"
#include "ester.h"

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
		r = patricia();
		break;
	case 'T':
		r = teodoro();
		break;
	case 'E':
		r = ester();
		break;
	
	default:
		throwError();
		break;
	}

	if(r != 0)
		throwError();

	return 0;
}