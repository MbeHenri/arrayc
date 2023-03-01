#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED

typedef enum boolean
{
    True = 1,
    False = 0
} boolean;


/*
* genère un nombre aleatoire entre min et max
*/
float float_rand( float min, float max );

/**
 * creation de matrice d'entier de type 'int' 
*/
int **create_matrix_int(int n_row, int n_col);

/**
 * creation de matrice de nombre reelle de type 'double' 
*/
double **create_matrix_double(int n_row, int n_col);

/**
 * remplacement de toute la matrice a une valeur definie 
*/
void replace_val_matrix_double(int n_row, int n_col, double** tab, double val );

/**
 * liberation de matrice d'entier de type 'int' 
*/
void free_matrix_int(int **d, int n_row);

/**
 * liberation de matrice de nombres reelle de type 'int' 
*/
void free_matrix_double(double **d, int n_row);

/**
 * void affiche_suite(int nb, ...)
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
int operateur_binaire(int a, int b, int (*f)(int, int))
{
  return((*f)(a,b));
}
*/

#endif // BASE_H_INCLUDED