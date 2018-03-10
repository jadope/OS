#include <stdio.h>
#include <string.h>

/*
    Hacer que barra una cadena de caracteres en busca de un caracter especifico. 
    La funcion deberá retornar el numero de veces que aparece este caracter o -1
    en caso de que no este. La forma de la funcion se muestra a continuación
*/

void compare(char a, char b, int *counter) {
    
    if (a == b) {
        *counter = *counter + 1;
    }
}

int traverse(char *c, char character) { 

    int counter = 0;
    int longitud = strlen(c);
    int j;

    for (j = 0; j < longitud; j++) {
        compare( c[j], character, &counter);
    }
    
    return counter;
}

void test() { 

    char c[] = "abaccc";
    char character = 'c';
    int contador = traverse(c, character);
    printf("Hay un total de ocurrencias: %d \n", contador);
}

int main(int argc, char const *argv[]) {
    
    test();
}
