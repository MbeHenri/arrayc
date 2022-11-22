#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>

#include "../header/base.h"

void affiche_suite(int df,int nb, ...)
{
    va_list ap;

    va_start(ap, nb);

    while (nb > 0)
    {
        int n;
        n = va_arg(ap, int);
        printf("%d.\n", n);
        --nb;
    }

    va_end(ap);
}
int main(int argc, char const *argv[])
{
    int n =10;
    affiche_suite(12,2,14,15);
    return 0;
}
