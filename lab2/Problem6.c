#include <stdio.h>
#include <stdlib.h> //Librería para generar rand();
#include <time.h> //Librería para generar time(NULL);
#include <math.h>
#include <string.h>

int digitCounter(int n);

int main () { 
srand(time(NULL)); //Inicializo la semilla pseudoaleatoria.
int lanzarmoneda, random, i, j, digit;
double lanzamiento;
char resultado[];
printf("Ingrese el número de veces de lanzar las monedas (585, por ejemplo, hará que se lance 5 veces, luego 8 y luego otras 5 veces): ");
scanf("%d",&lanzarmoneda);
digit = digitCounter(lanzarmoneda);
for (i=0; i<digit; i++){
    lanzamiento=fmod(lanzarmoneda, pow(10, i+1))/pow(10,i); //Me retorna el último dígito del número ingresado.  
    printf("digit %d  --  lanzarmoneda %d   --- ", digit, lanzarmoneda);
    printf("Lanzamiento: %f \n", lanzamiento);
    for (j=0; j<floor(lanzamiento);j++){//Tengo que aplicar la función floor, para pasarlo de double a int y evitar que sobrepase el ciclo.
        random = rand()%(2);
        if (random==1)
        resultado[j]+="C"; //Si sale 1, agregue C a la cadena de caracteres.
        else
        resultado[j]+="S"; //Si sale 0, agregue Sa la cadena de caracteres. 
    }
    resultLanz(resultado[]);
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

char resultLanz(char cadena[]){
    int i = 0;
    int cara = 0;
    int sello = 0;
    int longitud = strlen(cadena)
    for(i; i<longitud; i++){
        if(cadena[i]=="C")
        cara+=1;
        else
        sello+=1;
    }
    printf("%s, #de caras = %d, # de sellos = %d", cadena[], cara, sello);
}
