/* 
Hacer una funcion que permita que un usuario obtenga el subindice asociado a
la primera aparicion de un caracter en un array. Si el caracter no esta la función 
debera retornar -1. Haga uso de la funcion del punto 1 para validar la presencia 
del caracter. A continuacion se muestra la forma de la función:
*/

#include <stdio.h>
#include <string.h>

int compare(char a, char b, int posicion, int *indice) {
    
    if (a == b) {        
        *indice = posicion;        
        return 1;
    }
    return 0;
}

void determinarPos(char *c, char character, int *indice) { 

    int longitud = strlen(c);
    int j, bandera;

    for (j = 0; j < longitud; j++) {
        
        bandera = compare( c[j], character, j, indice);
        
        if (bandera == 1) {
            break;
        }
    }    
}

int obtenerIndice(char *array, char c) {

    int indice = -1;
    determinarPos(array, c, &indice);
    return indice;    
}

void test() { 

    char c[] = "abacccj";
    char character = 'z';
    int indice = obtenerIndice(c, character);
    printf("El indice de la primera ocurrencia: %d \n", indice);
}

int main(int argc, char const *argv[]) {
    
    test();
}
