#include <stdlib.h>
#include <math.h>

#include "../header/arrayc.h"

void freeArray(Array arg)
{
    if (arg != NULL)
    {
        free_matrix_double(arg->data, arg->nRow);
        free(arg);
    }
}

Array newArray(int nRow, int nCol, double **tab)
{
    Array rlt = NULL;
    if (nCol > 0 && nRow > 0 && tab != NULL)
    {
        Array rlt = malloc(sizeof(ArrayStr));
        if (rlt != NULL)
        {
            rlt->data = tab;
        }
    }
    return rlt;
}

Array valArray(int nRow, int nCol, double val)
{
    Array rlt = NULL;
    if (nCol > 0 && nRow > 0)
    {
        rlt = malloc(sizeof(ArrayStr));
        if (rlt != NULL)
        {
            rlt->data = create_matrix_double(nRow, nCol);
            if (rlt->data != NULL)
            {
                rlt->nRow = nRow;
                rlt->nCol = nCol;
                int i = 0, j = 0;
                for (i = 0; i < nRow; i++)
                {
                    for (j = 0; j < nCol; j++)
                    {
                        rlt->data[i][j] = val;
                    }
                }
            }
            else
            {
                free(rlt);
            }
        }
    }
    return rlt;
}

Array onesArray(int nRow, int nCol)
{
    return valArray(nRow, nCol, 1);
}

Array zerosArray(int nRow, int nCol)
{
    return valArray(nRow, nCol, 0);
}

void fprintfArray(FILE *stream, Array array, boolean complete)
{
    if (array != NULL)
    {
        fprintf(stream, "\n[Nrow : %d, Ncol : %d] \n\n", array->nRow, array->nCol);
        if (complete)
        {
            int i = 0, j = 0;
            for (i = 0; i < array->nRow; i++)
            {
                for (j = 0; j < array->nCol; j++)
                {
                    fprintf(stream, "%lf ", array->data[i][j]);
                }
                fprintf(stream, "\n");
            }
        }
    }
}

void printfArray(Array array, boolean complete)
{
    fprintfArray(stdout, array, complete);
}

Array op__Array(Array arg1, Array arg2, double (*f)(double, double))
{
    Array rlt = NULL;
    if (arg1 != NULL && arg2 != NULL)
    {
        rlt = zerosArray(arg1->nRow, arg1->nCol);
        if (rlt != NULL)
        {
            int i = 0, j = 0;
            for (i = 0; i < arg1->nRow; i++)
            {
                for (j = 0; j < arg1->nCol; j++)
                {
                    rlt->data[i][j] = (*f)(arg1->data[i][j], arg2->data[i][j]);
                }
            }
        }
    }
    return rlt;
}

boolean op__Array_r(Array arg1, Array arg2, Array result1, double (*f)(double, double))
{
    if (arg1 != NULL && arg2 != NULL)
    {
        Array rlt = op__Array(arg1, arg2, f);
        if (result1 != NULL)
        {
            free_matrix_double(result1->data, result1->nRow);
            result1->data = rlt->data;
            result1->nRow = rlt->nRow;
            result1->nCol = rlt->nCol;
            free(rlt);
        }
        else
        {
            result1 = rlt;
        }

        return True;
    }
    return False;
}

Array op_Array(Array arg, double (*f)(double))
{
    Array rlt = NULL;
    if (arg != NULL)
    {
        rlt = zerosArray(arg->nRow, arg->nCol);
        int i = 0, j = 0;
        for (i = 0; i < arg->nRow; i++)
        {
            for (j = 0; j < arg->nCol; j++)
            {
                rlt->data[i][j] = (*f)(arg->data[i][j]);
            }
        }
    }
    return rlt;
}

boolean op_Array_r(Array arg, Array result, double (*f)(double))
{
    if (arg != NULL)
    {
        Array rlt = op_Array(arg, f);
        if (result != NULL)
        {
            free_matrix_double(result->data, result->nRow);
            result->data = rlt->data;
            result->nRow = rlt->nRow;
            result->nCol = rlt->nCol;
            free(rlt);
        }
        else
        {
            result = rlt;
        }
        return True;
    }
    return False;
}

double plus_Array(double a, double b)
{
    return a + b;
}
double minus_Array(double a, double b)
{
    return a - b;
}
double mul_Array(double a, double b)
{
    return a * b;
}

Array plusArray(Array arg1, Array arg2)
{
    return op__Array(arg1, arg2, *plus_Array);
}

boolean plusArray_r(Array arg1, Array arg2, Array result)
{
    return op__Array_r(arg1, arg2, result, *plus_Array);
}

Array minusArray(Array arg1, Array arg2)
{
    return op__Array(arg1, arg2, *minus_Array);
}

boolean minusArray_r(Array arg1, Array arg2, Array result)
{
    return op__Array_r(arg1, arg2, result, *minus_Array);
}

Array mulArray(Array arg1, Array arg2)
{
    return op__Array(arg1, arg2, *plus_Array);
}

boolean mulArray_r(Array arg1, Array arg2, Array result)
{
    return op__Array_r(arg1, arg2, result, *mul_Array);
}

Array matMulArray(Array arg1, Array arg2)
{
    Array rlt = NULL;
    if (arg1 != NULL && arg2 != NULL)
    {
        rlt = zerosArray(arg1->nRow, arg2->nCol);
        if (rlt != NULL)
        {
            int i = 0, j = 0, k = 0;
            for (i = 0; i < arg1->nRow; i++)
                for (j = 0; j < arg2->nCol; j++)
                    for (k = 0; k < arg1->nCol; k++)
                        rlt->data[i][j] += arg1->data[i][k]*arg2->data[k][j];
        }
    }
    return rlt;
}

boolean matMulArray_r(Array arg1, Array arg2, Array result)
{
    if (arg1 != NULL && arg2 != NULL)
    {
        Array rlt = matMulArray(arg1, arg2);
        if (result != NULL)
        {
            free_matrix_double(result->data, result->nRow);
            result->data = rlt->data;
            result->nRow = rlt->nRow;
            result->nCol = rlt->nCol;
            free(rlt);
        }
        else
        {
            result = rlt;
        }

        return True;
    }
    return False;
}

Array transposeArray(Array arg){
    Array rlt = NULL;
    if (arg != NULL)
    {
        rlt = zerosArray(arg->nCol, arg->nRow);
        if (rlt != NULL)
        {
            int i = 0, j = 0;
            for (i = 0; i < arg->nCol; i++)
                for (j = 0; j < arg->nRow; j++)
                    rlt->data[i][j] = arg->data[j][i];
        }
    }
    return rlt;
}

boolean transposeArray_r(Array arg,Array result){
    if (arg != NULL)
    {
        Array rlt = transposeArray(arg);
        if (result != NULL)
        {
            free_matrix_double(result->data, result->nRow);
            result->data = rlt->data;
            result->nRow = rlt->nRow;
            result->nCol = rlt->nCol;
            free(rlt);
        }
        else
        {
            result = rlt;
        }
        
        return True;
    }
    return False;
}

Array plusArray_p(int n, int nRow, int nCol, ...)
{
    Array rlt = NULL;
    if (nRow > 0 && nCol > 0)
    {
        rlt = zerosArray(nRow, nCol);
        if (rlt != NULL)
        {
            va_list ap;
            int i = 0, j = 0;
            va_start(ap, nCol);

            Array currentArray = NULL;
            while (n > 0)
            {
                currentArray = va_arg(ap, Array);
                if (currentArray != NULL)
                {
                    for (i = 0; i < nRow; i++)
                    {
                        for (j = 0; j < nCol; j++)
                        {
                            rlt->data[i][j] += currentArray->data[i][j];
                        }
                    }
                }
                --n;
            }
            va_end(ap);
        }
    }
    return rlt;
}

boolean plusArray_pr(Array result, int n, int nRow, int nCol, ...)
{
    if (nRow > 0 && nCol > 0)
    {

        Array rlt = zerosArray(nRow, nCol);
        if (rlt == NULL)
        {
            return False;
        }

        va_list ap;
        va_start(ap, nCol);

        Array currentArray = NULL;
        int i = 0, j = 0;
        while (n > 0)
        {
            currentArray = va_arg(ap, Array);
            if (currentArray != NULL)
            {
                for (i = 0; i < nRow; i++)
                {
                    for (j = 0; j < nCol; j++)
                    {
                        rlt->data[i][j] += currentArray->data[i][j];
                    }
                }
            }
            --n;
        }
        va_end(ap);

        if (result != NULL)
        {
            freeArray(result);
        }
        result = rlt;
        return True;
    }
    return False;
}
