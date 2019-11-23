#include "teodoro.h"

#include <stdio.h>
#include <stdlib.h>

#include "mytypes.h"
#include "math.h"
#include "misc.h"

int teodoro(void)
{
    char initialized = -1;
    char running = 1;
    char id;
    char ret;

    ul_int n, p, q, s, v;
    while(running && scanf(" %c", &id) != EOF)
    {
        switch (id)
        {
            case 'I':
                scanf("%lu %lu", &p, &q);
                n = p * q;
                initialized = checkPAndQ(p, q);
                ret = 0 | initialized;
                break;
            
            case 'A':
                ret = authenticate(n, &s, &v, 0);
                ret |= initialized;
                break;

            case 'F':
                scanf("%lu", &s);
                ret = authenticate(n, &s, &v, 1);
                ret |= initialized | (s > n-1) | (s < 2);
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
                printf("C %lu\n", n);
                break;
            
            case 'A':
                printf("C %lu %lu\n", v, s);
                break;

            case 'F':
                printf("C %lu\n", v);
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

char authenticate(ul_int n_, ul_int* s_, ul_int* v_, char forge)
{
    if(forge == 0)
        *s_ = random(n_);

    ull_int s = *s_;
    s = s * s;

    long int v, t;
    ull_int n = n_;
    s %= n;
    ul_int mdc;
    mdc = extEuclidean(&s, &n, &v, &t);

    *v_ = v;

    if(mdc == 1)
        return 0;
    
    return 1;
}

char checkPAndQ(ul_int p, ul_int q)
{
    if(p == q)
        return -1;

    if(p <= 2)
        return -1;
    
    if(q <= 2)
        return -1;

    return 0;
}