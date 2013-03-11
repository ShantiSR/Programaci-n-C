//
//  main.c
//  ex1
//  Shanti
//  Created by Shanti on 26/02/13.
//  Copyright (c) 2013 Shanti. All rights reserved.
//  1. Introduir dos nombres per teclat. Dissenyar una funció que retorni el més gran dels dos nombres entrats.

#include <stdio.h>
int mayor(int num1, int num2){
    int resultado = 0;
    if (num1 > num2){
        resultado = num1;
    }
    if (num2>num1){
        resultado = num2;
    }
    return resultado;
}

int main()

{
    int num1=0;
    int num2=0;
    int resultado=0;
    
    printf("introducir el primer numero: ");
    scanf("%d",&num1);
    
    printf("introducir segundo numero: ");
    scanf("%d",&num2);
    
    resultado=mayor(num1,num2);
    
    printf("%d",resultado);
    
    return 0;
}


