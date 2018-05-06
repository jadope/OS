#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parser.h"
#include "ejecutador.h"
#define TAM 100

int main(int argc, char const *argv[]) {

    int background, itemsSize;    
    char expresion[TAM];
    char** items;   

    printf("\n");

    while(1) {

        printf("SO@cli $ ");
        fgets (expresion, TAM, stdin);

        itemsSize = separaItems (expresion, &items, &background);    
        issueCall(expresion, items, itemsSize, background);
        liberaItems(items);
    }    
}
