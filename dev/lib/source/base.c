#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../header/base.h"


float float_rand( float min, float max )
{
    float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
    return min + scale * ( max - min );      /* [min, max] */
}

int **create_matrix_int(int n_ligne, int n_col)
{
    int **d = (int **)malloc(n_ligne * sizeof(int *));
    if (d != NULL)
    {

        int i = 00;
        for (i = 0; i < n_ligne; i++)
        {
            d[i] = (int *)malloc(n_col * sizeof(int));
            if (d[i] == NULL)
            {
                while (i > 0)
                {
                    free(d[i]);
                    i--;
                }
                free(d);
                break;
            }
        }
    }
    return d;
}
double **create_matrix_double(int n_ligne, int n_col)
{
    double **d = (double **)malloc(n_ligne * sizeof(double *));
    int i = 0;
    if (d != NULL)
    {
        for (i = 0; i < n_ligne; i++)
        {
            d[i] = (double *)malloc(n_col * sizeof(double));
            if (d[i] == NULL)
            {
                while (i > 0)
                {
                    free(d[i]);
                    i--;
                }
                free(d);
                break;
            }
        }
    }
    return d;
}

void replace_val_matrix_double(int n_row, int n_col, double **tab, double val)
{
    if (tab != NULL)
    {
        int i = 0, j = 0;
        for (i = 0; i < n_row; i++)
        {
            for (j = 0; j < n_col; j++)
            {
                tab[i][j] = val;
            }
        }
    }
}

void free_matrix_int(int **d, int n_ligne)
{
    if (d != NULL)
    {
        int i = 0;
        for (i = 0; i < n_ligne; i++)
            free(d[i]);
        free(d);
    }
}

void free_matrix_double(double **d, int n_ligne)
{
    if (d != NULL)
    {
        int i = 0;
        for (i = 0; i < n_ligne; i++)
            free(d[i]);
        free(d);
    }
}