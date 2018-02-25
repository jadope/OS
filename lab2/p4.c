#include <stdio.h>
#include <string.h>

void intToChar(int numero, char *buffer) {
  sprintf(buffer, "%d", numero);
}

void reverse(char *hilera) {
  int longitud = strlen(hilera);
  int j,i;

  for (j = 0, i = (longitud-1); j < (longitud/2); j++, i--) {
    char temp = hilera[j];
    hilera[j] = hilera[i];
    hilera[i] = temp;
  }
}

int main(int argc, char *argv[]) {

  int numero;
  char hilera[20];

  printf("Ingrese un numero entero: \n");
  scanf("%d", &numero);

  intToChar(numero, hilera);
  reverse(hilera);

  printf("la hilera al reves: %s\n", hilera);

  return 1;
}
