#include <stdio.h>
#include <stdlib.h>
#include "polynome.h"
#include <assert.h>

void Init(polynom *l)
{
    l->first=NULL;
    l->last=NULL;
}
void saisie(polynom *l)
{
    float coefficiant;
    int i=0,a,degree;
      printf("------------Insertion des monomes-------------\n");
    do{
        
        printf("donner coeficient de monome %d : ",i+1);scanf("%f",&coefficiant);
        printf("\n");
        printf("donner degree degrer de monome %d: ",i+1);scanf("%d",&degree);
        printf("\n");
       InsertionFin(l,degree,coefficiant);
        printf("Continuer D'entrer TAPER 1  / Pour Arreter Taper 0  :  ");scanf("%d",&a);
        printf("\n");
        printf("----------------------------------------------------------");
        printf("\n");
        i++;
    }while(a!=0);
}

//Trier les termesde polynome selon les degrer
void TriPoly(polynom *l)
{
    monome *debut=l->first;
    float cof=0;
    int degre=0;
    monome *apres=debut->next;
    while (debut)
    {
        while (apres)
        {
           if(debut->degr>apres->degr)
         {
            cof=apres->coeff;
            degre=apres->degr;
            apres->coeff=debut->coeff;
            apres->degr=debut->degr;
            debut->coeff=cof;
            debut->degr=degre;
         }
           apres=apres->next;
        }
        debut=debut->next;
        
    }
    

}
//nombre de terme du polynome
int nbreMonome(polynom *l)
{
    if(l->first==NULL)
    return -1;
    else
    {
        monome *debut=l->first;

        int cmp=0;
        while (debut)
        {
            
            debut=debut->next;
            cmp++;
        }
        return cmp;
        
    }
}
// 
void addpoly(polynom *l1, polynom *l2,polynom *l3)
{
    int nbp1=nbreMonome(l1);
    int nbp2=nbreMonome(l2);
    float som=0;
    //trier selon les coefficiant les polynome
    TriPoly(l1);
    TriPoly(l2);
    //traitement
    monome *start1=l1->first;
    monome *start2=l2->first;
    if(nbp1==nbp2){
        while (start1)
        {
        som=0;
        som=start1->coeff+start2->coeff;
        start1->coeff=som;
        InsertionFin(l3, start1->degr , start1->coeff);
        start1=start1->next;
        start2=start2->next;   
        }
    }
    if(nbp1>nbp2)
    {
     while (start1)
      {
        if (start1->next==NULL)
        {
             InsertionFin(l3, start1->degr , start1->coeff);break;
        }
        
        som=0;
        som=start1->coeff+start2->coeff;
        start1->coeff=som;
        InsertionFin(l3, start1->degr , start1->coeff);
        start1=start1->next;
        start2=start2->next;   
      }
    }
    if(nbp1<nbp2)
    {
      while (start2)
      {
        if (start2->next==NULL)
        {
             InsertionFin(l3, start2->degr , start2->coeff);break;
        }
        
        som=0;
        som=start1->coeff+start2->coeff;
        start1->coeff=som;
        InsertionFin(l3, start1->degr , start1->coeff);
        start1=start1->next;
        start2=start2->next;   
      }
    }
    

}
//
void sousPoly(polynom *l1, polynom *l2,polynom *l3)
{

    // declaration
    int nbp1=nbreMonome(l1);
    int nbp2=nbreMonome(l2);
    float som=0;
    //trier selon les coefficiant les polynome
    TriPoly(l1);
    TriPoly(l2);
    //traitement
    monome *start1=l1->first;
    monome *start2=l2->first;
    if(nbp1==nbp2){
        while (start1)
    {
        som=0;
        som=start1->coeff-start2->coeff;
        start1->coeff=som;
        InsertionFin(l3, start1->degr , start1->coeff);
        start1=start1->next;
        start2=start2->next;   
    }
    }
    if(nbp1>nbp2){
     while (start1)
    {
        if (start1->next==NULL)
        {
             InsertionFin(l3, start1->degr , start1->coeff);continue;
        }
        
        som=0;
        som=start1->coeff-start2->coeff;
        start1->coeff=som;
        InsertionFin(l3, start1->degr , start1->coeff);
        start1=start1->next;
        start2=start2->next;   
    }
    }
    if(nbp1<nbp2){
     while (start2)
    {
        if (start2->next==NULL)
        {
             InsertionFin(l3, start2->degr , start2->coeff);continue;
        }
        
        som=0;
        som=start1->coeff-start2->coeff;
        start1->coeff=som;
        InsertionFin(l3, start1->degr , start1->coeff);
        start1=start1->next;
        start2=start2->next;   
    }
    }
    

}
//foction de derivation d un polynome
void DerivePolynome(polynom *l){
    if(l->first)
    {
        monome *debut =l->first;
        while (debut)
        {
            if(debut->degr==0)
            {
                debut->coeff=0;
            }
            debut->coeff=debut->coeff * debut->degr;
            debut->degr=debut->degr-1;
            debut=debut->next;
        
        }
        
    }




}
//
void IntegratonPoly(polynom *l){
    if(l->first)
    {
        monome *debut =l->first;
        while (debut)
        {
            if(debut->degr==0)
            {
                debut->degr=debut->degr+1;
            }
            debut->coeff=(debut->coeff)/(debut->degr+1);
            debut->degr=debut->degr+1;
            debut=debut->next;
        
        }
        
    }
}

//fontion changement de signe : 
void changersignPoly(polynom *l)
{
    //tester le polynome n est pas vide
    if(l->first)
    {
        monome *debut=l->first;
        while (debut)
        {
            debut->coeff=-(debut->coeff);
            debut=debut->next;
        }
    }
}
//Fonction d insertion 
void InsertionFin(polynom *l, int de, float coe)
{
   monome *nouv = malloc(sizeof(monome));
   if(!nouv) printf("impossible");
   nouv->coeff = coe;
   nouv->degr = de;
   nouv->pre = l->last;
   nouv->next = NULL;
   if(l->last) l->last->next = nouv;
   else l->first = nouv;
   l->last = nouv;        
}
//fonvtion d affichage d'un polynome trier
void Afficher(polynom *l)
{
    if(l->first==NULL) printf("polynome est vide");
    TriPoly(l);
    monome *debut =l->first;
    while(debut)
    {
        if(debut->next==NULL)  
        printf("%.2fX^%d ",debut->coeff,debut->degr);
        else
        printf("%.2fX^%d +",debut->coeff,debut->degr);
        debut=debut->next;
        
    }
}
