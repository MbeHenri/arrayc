#ifndef ARRAYC_H_INCLUDED
#define ARRAYC_H_INCLUDED
#include <stdarg.h>
#include <math.h>
#include <stdio.h>
#include "../header/base.h"

// >
// >    DEFINITIONS
// >

/**
 *  Definition du Type de tableau permettant d'effectuer des operations matricieles et
 * vectorieles plus facilement
 * - Array : pour le pointeur sur la structure
 * - ArrayStr : pour la structure
 */
typedef struct array
{
    // nombre de ligne du tableau
    int nRow;

    // nombre de colonne du tableau
    int nCol;

    // matrice de variable de type relle
    double **data;

} ArrayStr, *Array;

// >
// >    FONCTIONS DE GESTION DE MEMOIRE
// >

/**
 * creation du tableau de Type Array remplit depuis un tableau de type double correcte
 * le Tableau de type Array utilisera directement le tableau indiquer
 * sans creation d'un nouvelle espace memmoire pour conserver les donnees
 */
Array newArray(int nRow, int nCol, double **tab);

/**
 * tableau remplit de valeur 'val'
 */
Array valArray(int nRow, int nCol, double val);

/**
 * tableau remplit de 1
 */
Array onesArray(int nRow, int nCol);

/**
 * tableau remplit de maniere aleatoire
 */
Array randomArray(int nRow, int nCol , float min , float max);

/**
 * tableau remplit de 0
 */
Array zerosArray(int nRow, int nCol);

/**
 * liberation du tableau de Type Array
 */
void freeArray(Array);

// >
// >    FONCTIONS UTILES DE STRUCTURES
// >

/**
 * Fonction d'affichage du tableau dans un buffer specifique
 * -    Precondition :
 * * le tableau doit etre correct
 */
void fprintfArray(FILE *stream, Array array, boolean complete);

/**
 * Fonction d'affichage du tableau dans la sortie standard
 * * le tableau doit etre correct
 */
void printfArray(Array array, boolean complete);

// >
// >    FONCTIONS DE GENERAUX D'OPERATIONS DE TABLEAU ARRAY
// >

/**
 * Transformation du tableau de type Array par une application f definie
 *       f: |R x |R => |R
 *
 * -    Precondition :
 * * les tableaux doivent avoir les memes dimensions et doivent etre creer par le biais
 * d'une fonction de creation legitime de Tableau de Type Array
 * * 'result' doit etre un pointeur
 *
 * -    Arguments
 * * result : tableau de sortie
 * * n : nombre des premiers tableaux utlisees
 * * nRow : nombre des premieres lignes utilisees des tableaux
 * * nCol : nombre des premieres colonnes utilisees des tableaux
 */
Array op__Array(Array arg1, Array arg2, double (*f)(double, double));

/**
 * Transformation du tableau de type Array par une application f definie
 *       f: |R x |R => |R
 *  avec reference du resultat ('result')
 *
 * -    Precondition :
 * * les tableaux doivent avoir les memes dimensions et doivent etre creer par le biais
 * d'une fonction de creation legitime de Tableau de Type Array
 * * 'result' doit etre un pointeur
 *
 * -    Arguments
 * * result : tableau de sortie
 * * n : nombre des premiers tableaux utlisees
 * * nRow : nombre des premieres lignes utilisees des tableaux
 * * nCol : nombre des premieres colonnes utilisees des tableaux
 */
boolean op__Array_r(Array arg1, Array arg2, Array result1, double (*f)(double, double));

/**
 * Transformation du tableau de type Array par une application f definie
 *       f: |R => |R
 *
 * -    Precondition :
 * * les tableaux doivent avoir les memes dimensions et doivent etre creer par le biais
 * d'une fonction de creation legitime de Tableau de Type Array
 * * 'result' doit etre un pointeur
 *
 * -    Arguments
 * * n : nombre des premiers tableaux utlisees
 * * nRow : nombre des premieres lignes utilisees des tableaux
 * * nCol : nombre des premieres colonnes utilisees des tableaux
 */
Array op_Array(Array arg, double (*f)(double));

/**
 * Transformation du tableau de type Array par une application f definie
 *       f: |R => |R
 *  avec reference du resultat ('result')
 *
 * -    Precondition :
 * * les tableaux doivent avoir les memes dimensions et doivent etre creer par le biais
 * d'une fonction de creation legitime de Tableau de Type Array
 * * 'result' doit etre un pointeur
 *
 * -    Arguments
 * * result : tableau de sortie
 * * n : nombre des premiers tableaux utlisees
 * * nRow : nombre des premieres lignes utilisees des tableaux
 * * nCol : nombre des premieres colonnes utilisees des tableaux
 */
boolean op_Array_r(Array arg, Array result, double (*f)(double));

// >
// >    FONCTIONS MATHEMATIQUES UTILES
// >

double plus_Array(double a, double b);
double minus_Array(double a, double b);
double mul_Array(double a, double b);

// >
// >    FONCTIONS SPECIFIQUES
// >

/**
 * somme de deux tableaux avec retour du resultat
 * -    precondition :
 * les tableaux doivent avoir les memes dimensions et doivent etre creer par le biais
 * d'une fonction de creation legitime de Tableau de Type Array
 */
Array plusArray(Array arg1, Array arg2);

/**
 * somme de deux tableaux avec reference du resultat('result')
 * -    precondition :
 * * les tableaux doivent avoir les memes dimensions et doivent etre creer par le biais
 * d'une fonction de creation legitime de Tableau de Type Array
 * * 'result' doit etre un pointeur
 */
boolean plusArray_r(Array arg1, Array arg2, Array result);

/**
 * somme de plusieurs tableaux de type Array avec retour du resultat
 *
 * -   Precondition :
 * les tableaux doivent avoir les memes dimensions et doivent etre creer par le biais
 * d'une fonction de creation legitime de Tableau de Type Array
 *
 * -    Arguments
 * * n : nombre des premiers tableaux utlisees
 * * ... : les tableaux
 */
Array plusArray_p(int n, int nRow, int nCol, ...);

/**
 * Somme de plusieurs tableaux de type Array avec reference du resultat ('result')
 *
 * -    Precondition :
 * * les tableaux doivent avoir les memes dimensions et doivent etre creer par le biais
 * d'une fonction de creation legitime de Tableau de Type Array
 * * 'result' doit etre un pointeur
 *
 * -    Arguments
 * * result : tableau de sortie
 * * n : nombre des premiers tableaux utlisees
 * * nRow : nombre des premieres lignes utilisees des tableaux
 * * nCol : nombre des premieres colonnes utilisees des tableaux
 * * ... : les tableaux
 */
boolean plusArray_pr(Array result, int n, int nRow, int nCol, ...);

/**
 * soustraction de deux tableaux avec retour du resultat
 * -    precondition :
 * les tableaux doivent avoir les memes dimensions et doivent etre creer par le biais
 * d'une fonction de creation legitime de Tableau de Type Array
 */
Array minusArray(Array arg1, Array arg2);

/**
 * soustraction de deux tableaux avec reference du resultat('result')
 * -    precondition :
 * * les tableaux doivent avoir les memes dimensions et doivent etre creer par le biais
 * d'une fonction de creation legitime de Tableau de Type Array
 * * 'result' doit etre un pointeur
 */
boolean minusArray_r(Array arg1, Array arg2, Array result);

/**
 * multiplication simple de deux tableaux avec retour du resultat
 * -    precondition :
 * les tableaux doivent avoir les memes dimensions et doivent etre creer par le biais
 * d'une fonction de creation legitime de Tableau de Type Array
 */
Array mulArray(Array arg1, Array arg2);

/**
 * multiplication simple de deux tableaux avec reference du resultat('result')
 * -    precondition :
 * * les tableaux doivent avoir les memes dimensions et doivent etre creer par le biais
 * d'une fonction de creation legitime de Tableau de Type Array
 * * 'result' doit etre un pointeur
 */
boolean mulArray_r(Array arg1, Array arg2, Array result);

/**
 * multiplication matritielle simple de deux tableaux avec retour du resultat
 * -    precondition :
 * * le nombre de colonnes du premier tableau 'arg1' doit etre egale au nombre de lignes du deuxieme tableau
 * 'arg2'
 * * 'arg1' et 'arg2' doivent etre creer par le biais
 * d'une fonction de creation legitime de Tableau de Type Array
 */
Array matMulArray(Array arg1, Array arg2);

/**
 * multiplication matritielle de deux tableaux avec reference du resultat('result')
 * -    precondition :
 * * le nombre de colonnes du premier tableau 'arg1' doit etre egale au nombre de lignes du deuxieme tableau
 * 'arg2'
 * * 'arg1' et 'arg2' doivent etre creer par le biais
 * d'une fonction de creation legitime de Tableau de Type Array
 */
boolean matMulArray_r(Array arg1, Array arg2, Array result);

/**
 * transpose matritielle d'un tableau avec retour du resultat
 * -    precondition :
 * * 'arg' doit etre creer par le biais
 * d'une fonction de creation legitime de Tableau de Type Array
 */
Array transposeArray(Array arg);

/**
 * transpose matritielle d'un tableau avec reference du resultat('result')
 * -    precondition :
 * * 'arg' doit etre creer par le biais
 * d'une fonction de creation legitime de Tableau de Type Array
 */
boolean transposeArray_r(Array arg,Array result);

#endif // ARRAYC_H_INCLUDED