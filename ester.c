#include "ester.h"

#include <stdio.h>

#include "mytypes.h"
#include "misc.h"
#include "math.h"

int ester(void)
{
    char initialized = -1;
    char running = 1;
    char id;
    char ret;

    unsigned char b;
    ul_int n, s, v, x, xb, x0, x1;
    while(running && scanf(" %c", &id) != EOF)
    {
        switch (id)
        {
            case 'I':
                scanf("%lu %lu", &n, &v);
                initialized = (v > n);
                ret = 0 | initialized;
                break;
            
            case 'P':
                scanf("%hhu", &b);
                ret = 0 | initialized;
                break;
            
            case 'S':
                scanf("%lu %lu", &x0, &x1);
                s = getS(x0, x1, n);
                ret = 0 | initialized;
                break;

            case 'T':
                running = 0;
                ret = 0 | initialized;
            
            default:
                throwError();
                break;
        }

        switch (id | ret)
        {
            case 'I':
                printf("C\n");
                break;
            
            case 'S':
                printf("C %lu\n", s);
                break;
            
            case 'T':
                printf("C\n");
                break;
            
            default:
                printf("E\n");
                break;
        }
    }


    return 0;
}

ul_int getS(ul_int x0, ul_int x1, ul_int n_)
{
    ull_int r, n;
    ul_int invR;
    long int t;

    r = x0;
    n = n_;
    extEuclidean(&r, &n, (long int*) &invR, &t);

    return (x1 * invR) % n;
}