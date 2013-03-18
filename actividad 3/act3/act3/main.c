//
//  main.c
//  act3
//
//  Created by Shanti on 18/03/13.
//  Copyright (c) 2013 Shanti. All rights reserved.
//

#include <stdio.h>
#include <string.h>

typedef struct
{
	char nom[30];
	char cognom[30];
	char tel[10];
} agenda;


void impmenu(){
	printf("\n<<<<-----Agenda telefonica----->>>>\n\n");
	printf("1.- Introducir un nuevo contacto\n");
	printf("2.- Buscar un contacto por apellido\n");
	printf("3.- Borrar una contacto\n");
	printf("4.- Listar todos los contactos\n");
	printf("5.- Salir\n\n");
}

int novaentrada(agenda age[], int pos2){
	printf("\nInroducir nom:");
	scanf("%s",age[pos2].nom);
	printf("Introducir cognom:");
	scanf("%s",age[pos2].cognom);
	printf("Introducir telefòn:");
	scanf("%s",age[pos2].tel);
	printf("Operació efectuada amb exit!\n");
	pos2++;
	return pos2;
}

void llistaragenda(agenda age[], int pos1){
	int cont=0;
	printf("\nNom\tCognom\tTelèfon\n");
	while(cont<pos1)
	{
		printf("%s\t%s\t%s\n",age[cont].nom, age[cont].cognom, age[cont].tel);
		cont++;
	}
}

void buscarcognom(agenda age[],int pos1){
	int c=0;
	char cognom[30];
	printf("\nIntrodueix cognom:");
	scanf("%s",cognom);
	while(c<pos1){
		if (strcasecmp(cognom,age[c].cognom)==0){
			printf("Nom: %s\tTelèfon: %s\n",age[c].nom, age[c].tel);
		}
		c++;
	}
}

int esborrarentrada(agenda age[],int pos1){
	int c=0, trobat=0;
	char nom[30];
	char resp;
	int cont;
	printf("\nIntrodueix nom de la persona que voleu esborrar:");
	scanf("%s",nom);
	getchar();
	while (c<pos1 && trobat==0)
	{
		if (strcasecmp(nom,age[c].nom)==0)
		{
			printf("¿ Voleu esborrar la següent entrada?[S/N]\nNom: %s\tCognom: %s\tTelèfon: %s\n",age[c].nom, age[c].cognom, age[c].tel);
			printf("\nOpció:");
			scanf("%c",&resp);
			if (resp=='s' || resp=='S')
			{
				trobat=1;
				cont=c;
				printf("pasa");
			}
		}
		c++;
	}
	if (trobat==1)
	{
		while(cont<pos1)
		{
			strcpy(age[cont].nom,age[cont+1].nom);
			strcpy(age[cont].cognom,age[cont+1].cognom);
			strcpy(age[cont].tel,age[cont+1].tel);
			cont++;
		}
		pos1--;
	}
    
	return pos1;
}

int main(){
    
	agenda age[10];
	int opcio;
	int pos1=0;
	impmenu();
	printf("Introdueix opció:");
	scanf("%d",&opcio);
    
	while(opcio != 5)
	{
        if(opcio==1)
        {
            pos1=novaentrada(age,pos1);
        }
        else if (opcio==2)
        {
            buscarcognom(age,pos1);
        }
        else if (opcio==3)
        {
            pos1=esborrarentrada(age,pos1);
        }
        else if(opcio==4)
        {
            llistaragenda(age,pos1);
        }
        else if (opcio==5){
            
        }
        impmenu();
        printf("Introdueix opció:");
        scanf("%d",&opcio);
	}
	return 0;
}


