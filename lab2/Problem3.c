//La función srand(): Crea una semilla que me servirá para generar una secuencia de valores que luego la función rand() usará para generar un número pseudorandom. En este caso, le ingresa como parámetro time(Null) para utilizar la hora actual como inicializador de la semilla. 
//En caso de no utilizar srand(), rand() usará por defecto la semilla srand(1), lo cual generaría que se genere una secuencia de números aleatorias iguales.

#include <stdio.h>
#include <stdlib.h> //Librería para generar rand();
#include <time.h> //Librería para generar time(NULL);

int aleatorio(int, int);

int main () { 
srand(time(NULL)); //Inicializo la semilla pseudoaleatoria.
int a, b, random;
printf("Ingrese el rango así 'númeroMenor númeroMayor': ");
scanf("%d %d",&a, &b);
random = aleatorio(a,b);
printf("El número aleatorio entre %d y %d es %d\n", a, b, random);
return 0;   
}

int aleatorio(int a, int b){
int al = rand()%(b+1-a)+a;
return al;
}