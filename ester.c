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
                initialized = checkNAndV(n, v);
                ret = 0 | initialized;
                break;
            
            case 'P':
                scanf("%hhu", &b);
                calculateXAndXb(b, v, n, &x, &xb);
                ret = 0 | initialized | (b != 0 && b != 1);
                break;
            
            case 'S':
                scanf("%lu %lu", &x0, &x1);
                s = getS(x0, x1, n);
                ret = 0 | initialized;
                break;

            case 'T':
                running = 0;
                ret = 0;
                break;
            
            default:
                throwError();
                break;
        }
        
        switch (id | ret)
        {
            case 'I':
                printf("C\n");
                break;
            
            case 'P':
                printf("C %lu %lu\n", x, xb);
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

void calculateXAndXb(unsigned char b, ul_int v_, ul_int n_, ul_int* x_, ul_int* xb)
{
    if(n_ < 6)
        return;

    if(b == 0)
    {
        ull_int n = n_;
        
        ull_int r = random(n_);
        ull_int x = r * r;

        *x_ = x % n; 
        *xb = r;

    }
    else if(b == 1)
    {
        ull_int n = n_;

        ull_int y = random(n_);
        ull_int x = y * y;
        x %= n;
        x *= (ull_int) v_;
        x %= n;

        *x_ = y;
        *xb = x;
    }
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