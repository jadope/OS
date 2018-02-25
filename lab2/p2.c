#include <stdio.h>
#include <math.h>

// gcc -Wall p2.c -o p2 -lm
int main(int argc, char *argv[])
{
  int potencia;
  double base, suma = 1;

  printf("Ingrese la base: \n");
  scanf("%lf", &base);

  printf("Ingrese la potencia: \n");
  scanf("%d", &potencia);

  if (potencia < 0) {
    return 1;
  }

  for (int contador = 1; contador <= potencia; contador++) {
    suma = suma + pow(base, contador);
  }

  printf("La suma total es: %.1lf\n", suma);

  return 0;
}
