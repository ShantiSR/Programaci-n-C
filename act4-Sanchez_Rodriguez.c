//
//  main.c
//  act4
//
//  Created by Shanti on 10/04/13.
//  Copyright (c) 2013 Shanti. All rights reserved.
//

#include <stdio.h>
#include <string.h>

typedef struct
{
	int dia, mes, any;
}data;

typedef struct
{
	char nom[25];
	char codiss[11];
	char dni[9];
	data dataingres;
	char radiografia;
}pacient;

void radiografiestemps(data datainici, data datafinal, pacient p1[]){
	int c=0, di, df;
	di=datainici.any*1000 + datainici.mes*100 + datainici.dia;
	df=datafinal.any*1000 + datafinal.mes*100 + datafinal.dia;
    
	if(di>df){
		printf("data incial mes gran que la final");
	}
	else{
		while(c<5){
			if(p1[c].dataingres.any < datafinal.any && p1[c].dataingres.any > datainici.any && p1[c].radiografia == 'S'){
				printf("Dades del pacient amb codi SS:%s \n",p1[c].codiss);
				printf("Nom: %s\n",p1[c].nom);
				printf("DNI: %s\n",p1[c].dni);
				printf("Data ingrés: %d/%d/%d\n",p1[c].dataingres.dia, p1[c].dataingres.mes, p1[c].dataingres.any);
				printf("Radiografies: %c\n",p1[c].radiografia);
			}
			else
			{
				printf("No hi han pacients!");
				c=4;
			}
			c++;
		}
	}
    
    
}
void dadespacient(pacient p1[], char numsegsocial[10]){
	int c=0, sw=0;
    
	while(c<5 && sw==1){
        
		if (strcmp(numsegsocial,p1[c].codiss)==0){
			printf("Dades del pacient amb codi SS:%s \n",numsegsocial);
			printf("Nom: %s\n",p1[c].nom);
			printf("DNI: %s\n",p1[c].dni);
			printf("Data ingrés: %d/%d/%d\n",p1[c].dataingres.dia, p1[c].dataingres.mes, p1[c].dataingres.any);
			printf("Radiografies: %c\n",p1[c].radiografia);
			sw=1;
		}
		c++;
	}
	if (c==5)
        printf("El pacient no existeix a la base de dades");
}

int main(){
	char numsegsocial[10];
	int opcio;
	data datai;
	data dataf;
	pacient p1[]={{"Pere Sans","111111111","1111A",{10,7,2008},'S'},
        {"Sofia Cardozo","222222222","2222B",{22,4,2005},'N'},
        {"Shanti Rodriguez","333333333","3333C",{4,2,2010},'S'},
        {"Frank Sanchez","444444444","4444D",{14,11,2011},'N'}};
    
	printf("---- Dades pacinets ----\n\n");
	printf("1. Consultar dades per número de la Seguretat Social\n");
	printf("2. Consultar pacients amb radiografies entre dues dates donades\n\n");
	printf("Opcio:");
	scanf("%d",&opcio);
	if (opcio==1){
		printf("Introdueix numero SS:");
		scanf("%s",numsegsocial);
		dadespacient(p1,numsegsocial);
	}
	else if(opcio==2){
		printf("Introdueix data inici - dia:");
		scanf("%d",&datai.dia);
		printf("Introdueix data inici - mes:");
		scanf("%d",&datai.mes);
		printf("Introdueix data inici - any:");
		scanf("%d",&datai.any);
		printf("Introdueix data final - dia:");
		scanf("%d",&dataf.dia);
		printf("Introdueix data final - mes:");
		scanf("%d",&dataf.mes);
		printf("Introdueix data final - any:");
		scanf("%d",&dataf.any);
	}
    
    
	radiografiestemps(datai, dataf,p1);
	return 0;
}
