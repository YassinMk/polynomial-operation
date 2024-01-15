#include <stdio.h>
#include <stdlib.h>
#include "polynome.h"

int main()
{
    polynom l1,l2,l3,l4;
    //initialisation
    Init(&l1);
    Init(&l2);
    Init(&l3);
    Init(&l4);
    //saisie 
    saisie(&l1);
    saisie(&l2);
    saisie(&l3);
    saisie(&l4);
    //affichage
    printf("P(X)=");Afficher(&l1);
    printf("\n");
    printf("Q(X)=");Afficher(&l2);
    printf("\n");
    //operation sur polynome
    addpoly(&l1,&l2,&l3);
    printf("K(X)=");Afficher(&l3);
    printf("\n");
    souspoly(&l1,&l3,&l4);
    printf("G(X)=");Afficher(&l3);
    printf("\n");
    //changer le signe d un polynome
     
   //deriver d un polynome
    printf("P(X)=");Afficher(&l1);
    DerivePolynome(&l1);
    printf("dP(X)/dx=");Afficher(&l1);//resultat
    printf("\n");
    //integration d un polynome
    printf("P(X)=");Afficher(&l3);
    printf("\n");
    IntegratonPoly(&l3);//non borner 
    printf("IP(X)=");Afficher(&l3);printf("+Cste");//resultat
    printf("\n");    
}