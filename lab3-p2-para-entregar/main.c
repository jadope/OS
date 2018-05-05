#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parser.h"
#define TAM 100

int main(int argc, char const *argv[]) {

    int background, num;    
    char expresion[TAM];
    char** items;   

    printf("\nSO@cli $ ");
    fgets (expresion, TAM, stdin);

    num = separaItems (expresion, &items, &background);    

    printf ("Numero de parametros: %d\n", num);
}
