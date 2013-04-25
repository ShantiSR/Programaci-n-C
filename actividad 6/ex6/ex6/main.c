//
//  main.c
//  ex6
//
//  Created by Shanti on 25/04/13.
//  Copyright (c) 2013 Shanti. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int grau;
    float *coef;
}tpolinomi;

void impmenu(){
	printf("\nOperacions amb polnomis\n\n");
	printf("1-Intrducir polinomi\n");
	printf("2-Visualitzar polinomi\n");
	printf("3-Sumar dos polinomis\n");
	printf("4-Sortir\n\n");
}

void intropol(int grau, float elements[]){
	int c=0;
	while (c<grau+1){
		printf("Element %d:",c+1);
		scanf("%f",&elements[c]);
		c++;
	}
}

void visualitzarpol(int grau, float elements[]){
	int c=0;
	if(elements[c]==1)
		printf(" X^%d ",grau-c);
	else if(elements[c]==-1)
		printf(" -X^%d ",grau-c);
	else
		printf("%-.1fX^%d ",elements[c],grau-c);
	c=1;
	while(c<grau+1){
        if(elements[c]==1)
            printf(" X^%d ",grau-c);
        else if (elements[c]==-1)
            printf(" -X^%d ",grau-c);
        else if (c==grau)
            printf(" %+.1f ",elements[c]);
        else if (grau-c==1)
            printf(" %+.1fX ",elements[c]);
        /*else if (elements[c]==0)
         c++;*/
        else
			printf(" %+.1fX^%d ",elements[c],grau-c);
        c++;
    }
}

void sumarpols(int grau, float elements[], int grau2, float elements2[]){
	int max=0;
	int c=0;
	tpolinomi suma;
    
	printf("\n");
	visualitzarpol(grau,elements);
	printf("\n");
	visualitzarpol(grau2,elements2);
	printf("\n------------------+\n");
    
	if(grau>grau2)
        max=grau;
    else
        max=grau2;
	suma.grau=max;
	suma.coef=(float*)malloc (suma.grau*sizeof(float));
    
	while(c<max+1){
		suma.coef[c]=elements[c]+elements2[c];
		c++;
		//me falta controlar ,cuando los polinomios son de grados diferentes
	}
	visualitzarpol(suma.grau,suma.coef);
    
}

int main(){
    
	tpolinomi pol;
	tpolinomi pol2;
	int opcio;
	impmenu();
	printf("Introdueix opció:");
    scanf("%d",&opcio);
    
    while(opcio != 4){
        if (opcio==1){
            printf("Introdueix el grau:");
            scanf("%d",&pol.grau);
            pol.coef=(float*)malloc (pol.grau*sizeof(float));
            intropol(pol.grau,pol.coef);
            printf("Polinomi introduit amb exit!\n");
        }
        else if(opcio==2){
            visualitzarpol(pol.grau,pol.coef);
        }
        else if(opcio==3){
            printf("Primer polinomi\n");
            printf("Introdueix el grau:");
            scanf("%d",&pol.grau);
            pol.coef=(float*)malloc (pol.grau*sizeof(float));
            intropol(pol.grau,pol.coef);
            printf("Segon polinomi\n");
            printf("Introdueix el grau:");
            scanf("%d",&pol2.grau);
            pol2.coef=(float*)malloc (pol2.grau*sizeof(float));
            intropol(pol2.grau,pol2.coef);
            sumarpols(pol.grau,pol.coef,pol2.grau,pol2.coef);
        }
        else if(opcio==4){
            
        }
        impmenu();
        printf("Introdueix opció:");
        scanf("%d",&opcio);
    }
	return 0;
}

