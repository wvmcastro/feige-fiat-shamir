#include "ester.h"

#include <stdio.h>

#include "mytypes.h"
#include "misc.h"

int ester(void)
{
    char initialized = -1;
    char running = 1;
    char id;
    char ret;

    unsigned char b;
    ul_int n, s, v, x0, x1;
    while(running && scanf(" %c", &id) != EOF)
    {
        switch (id)
        {
            case 'I':
                scanf("%lu %lu", &n, &v);
                initialized = 0;
                ret = 0;
                break;
            
            case 'P':
                scanf("%hhu", &b);
                break;
            
            case 'S':
                scanf("%lu %lu", &x0, &x1);
                // TODO
                ret = 0;
                break;

            case 'T':
                running = 0;
                ret = 0;
            
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

