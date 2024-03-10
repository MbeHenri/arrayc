#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <arrayc.h>

int main(int argc, char const *argv[])
{
    Array rlt = NULL;
    op_Array_r(rlt = onesArray(5, 5), rlt, *exp);

    printfArray(rlt, True);
    freeArray(rlt);

    return 0;
}
