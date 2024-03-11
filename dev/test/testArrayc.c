#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <arrayc/arrayc.h>

double sqrtplus(double d)
{
    return sqrt(d + 1);
}

int main()
{
    Array rlt = NULL;
    op_Array_r(rlt = onesArray(5, 5), rlt, *sqrtplus);

    printfArray(rlt, True);
    freeArray(rlt);

    return 0;
}