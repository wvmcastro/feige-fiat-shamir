#include <stdio.h>

#include "../math.h"

int main(void)
{
    printf("a: %lu b: %lu mdc: %lu\n", 3, 5, MDC(3,5));
    printf("a: %lu b: %lu mdc: %lu\n", 6, 12, MDC(6,12));
    printf("a: %lu b: %lu mdc: %lu\n", 12, 6, MDC(12,6));
    printf("a: %lu b: %lu mdc: %lu\n", 6, 9, MDC(6,9));
}