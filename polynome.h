#include <stdio.h>
#include <stdlib.h>
// declaration des strucutre
typedef struct monome
{
    float coeff;
    int degr;
    struct monome *next;
    struct monome *pre;
}monome;
typedef struct 
{
    monome *first;
    monome *last;
}polynom;
//prototype fonction 
void Init(polynom *l);
void InsertionFin(polynom *l, int de, float coe);
/*void InsertionDebut(polynom *l, int de, float coe);*/
void Afficher(polynom *l);
int nbreMonome(polynom *l);
void TriPoly(polynom *l);//trier les terme de polynome
void saisie(polynom *l);
void addpoly(polynom *l1, polynom *l2,polynom *l3);
void souspoly(polynom *l1, polynom *l2,polynom *l3);
void changersignPoly(polynom *l);
void DerivePolynome(polynom *l);
void IntegratonPoly(polynom *l);
//
