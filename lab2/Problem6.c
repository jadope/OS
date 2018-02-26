#include <stdio.h>
#include <stdlib.h> //Librería para generar rand();
#include <time.h> //Librería para generar time(NULL);
#include <math.h>
#include <string.h>

int digitCounter(int);
void resultLanz(char cadena[]);

int main () { 
srand(time(NULL)); //Inicializo la semilla pseudoaleatoria.
int lanzarmoneda, random, i, j, digit;
double lanzamiento;
char resultado[11];
printf("Ingrese el número de veces de lanzar las monedas.\n(585, por ejemplo, hará que se lance 5 veces, luego 8 y luego otras 5 veces): ");
scanf("%d",&lanzarmoneda);
digit = digitCounter(lanzarmoneda);
printf("Valor de resultado[10]: %c\n", resultado[10]);
for (i=0; i<digit; i++){
    lanzamiento=fmod(lanzarmoneda, pow(10, i+1))/pow(10,i); //Me retorna el último dígito del número ingresado.  
    printf("digit %d  --  lanzarmoneda %d   --- ", digit, lanzarmoneda);
    printf("Lanzamiento: %f \n", lanzamiento);
    for (j=0; j<floor(lanzamiento);j++){//Tengo que aplicar la función floor, para pasarlo de double a int y evitar que sobrepase el ciclo.
        random = rand()%(2);
        if (random==1){
            resultado[j]+='C'; //Si sale 1, agregue C a la cadena de caracteres.
            printf("Caracter: %c, random: %d, J: %d\n", resultado[j], random, j);
        }
        else if (random==0){
            resultado[j]+='S'; //Si sale 0, agregue Sa la cadena de caracteres.
            printf("Caracter: %c, random: %d, J: %d\n", resultado[j], random, j);
        }
    }
    resultLanz(resultado);
    for (j=0; j<lanzamiento;j++){ //Elimino los valores del vector anterior.
        resultado[j]='\0';
    }
}
return 0;   
}

int digitCounter(int n){ //Esta función cuenta cuántos dígitos tiene el número.
    int count = 0;
    while (n!=0){
        n/=10; 
        ++count;
    }
    return count;
}

void resultLanz(char cadena[]){
    int i;
    int cara = 0;
    int sello = 0;
    int longitud = strlen(cadena);
    for(i = 0; i<longitud; i++){
        if(cadena[i]=='C')
            cara+=1;
        else if (cadena[i]=='S')
        sello+=1;
    }
    printf("%s, #de caras = %d, # de sellos = %d\n", cadena, cara, sello);
}
