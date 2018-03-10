#include <stdio.h>
#include <string.h>

int compare(char a, char b, int posicion, int *indice) {
    
    if (a == b) {
        // el indice empieza desde el 1
        *indice = posicion + 1;        
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
