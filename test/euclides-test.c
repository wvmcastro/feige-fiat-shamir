#include <stdio.h>

#include "../math.h"
#include "../mytypes.h"

void printAB(ull_int a, ull_int b)
{
    printf("a: %llu b: %llu\n", a, b);
}

void printMdcST(ul_int mdc, long int s, long int t)
{
    printf("mdc: %lu s: %ld t: %ld\n", mdc, s, t);
}

void runTest(ul_int a_, ul_int b_)
{
    ul_int mdc;
    ull_int a, b;
    long int s, t;
    
    a = a_;
    b = b_;
    printAB(a, b);
    mdc = unsafeExtEuclidean(&a, &b, &s, &t);
    printMdcST(mdc, s, t);
    printf("------------------------------------\n");
}

int main(void)
{
    runTest(221, 38);
    runTest(221, 196);
    runTest(221, 77);
    runTest(227692200981, 679269927437);
    runTest(404751702281, 679269927437);
    return 0;
}