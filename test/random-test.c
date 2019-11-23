#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "../math.h"


int main(void)
{
    srand(time(NULL));
    unsigned long int n = 10;
    unsigned long int r;
    for(int i = 0; i < 15; i++)
    {
        r = random(n);
        printf("%lu\n", r);
    }

}