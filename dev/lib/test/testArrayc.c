#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../header/Arrayc.h"

int main(int argc, char const *argv[])
{
    Array ar1 = onesArray(5, 5);
    Array rlt = NULL;
    op_Array_r(ar1, rlt, *log);
    op_Array_r(rlt, rlt, *exp);

    printfArray(ar1, True);
    freeArray(ar1);

    return 0;
}
