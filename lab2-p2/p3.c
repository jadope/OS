/*
 Obtener la subcadena de una cadena dada a partir de un subindice siguiendo 
 la siguiente funcion.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *obtenerSubcadena(char *c, int pos) { 

    int longitud = strlen(c);
    int j, i;
    char *subcadena=malloc(longitud);
    
    if(!subcadena) return NULL;
    
    if ( (pos<=longitud) && (pos>=0) ){

        for (j = pos, i = 0; j < longitud; j++, i++) {                
            subcadena[i] = c[j];    
        } 
    
    return subcadena;   
    }
    
    //En caso que la posición se salga de los parámetros de las posiciones de memoria destinados.
    return NULL; 
}


void test() { 

    char c[] = "abacccj";        
    int pos = 4;
    char *cadena;    
    
    cadena = obtenerSubcadena(c, pos);

    if (cadena == NULL){
        printf("Ingresó una posición incorrecta.\n");
    }
    else{
        printf("La subcadena es: %s \n", cadena);
    }
}

int main(int argc, char const *argv[]) {
    
    test();
}
