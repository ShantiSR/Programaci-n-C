//
//  main.c
//  ex2
//
//  Created by Shanti on 11/03/13.
//  Copyright (c) 2013 Shanti. All rights reserved.
//  Escriu un programa per introduir dos nombres per teclat. El programa ha de cridar a una funció menu(), que visualitzi les següents opcions:
// 1.­ suma 2.­ resta 3.­ multiplica 4.­ Sortir i torni l’opció escollida.


#include <stdio.h>

void menu(){
    printf("Elige una opcion:\n1. Suma\n 2. Resta\n 3. Multiplicar\n 4. Dividir\n 5. Salir\n");
}

int result(int num1, int num2){
    int valor = 0;
    scanf("%i",&valor);
    int menu = valor;
    int suma, resta, multi, divi = 0;
    switch (menu) {
        case 1:
            suma = num1 + num2;
            return suma;
            break;
        case 2:
            resta = num1 - num2;
            return resta;
            break;
        case 3:
            multi = num1 * num2;
            return multi;
            break;
        case 4:
            divi = num1 / num2;
            return divi;
            break;
        case 5:
            return 0;
            break;
        default:
            printf("Introduce un valor correcto [1-5].");
            break;
    }
    return menu;
    
}

int main()
{
    int num1, num2= 0;
    int resultado = 0;
    printf("Introduce un numero:");
        scanf("%i",&num1);
    printf("Introduce un segundo numero:");
        scanf("%i",&num2);
    menu();
    resultado = result(num1, num2);
    printf("%i",resultado);
    
    return 0;
}

