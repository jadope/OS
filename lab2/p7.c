#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printMessage(int code) {
  if (code == 0) {
    printf("Felicitaciones \n");
  }

  if (code == 1) {
    printf("Te has equivocado, vuelve a intentarlo \n");
  }
}

int verify(int value, int a, int b) {
  int multiplicacion = a * b;

  if (value == -1){
      return 2;
  }

  if (value == multiplicacion) {
    return 0;
  }

  return 1;
}

int main(int argc, char const *argv[]) {

  int input, valido = 0;
  int multiplicandoA, multiplicandoB;

  printf("Para salir del programa en cualquier momento, presiona le tecla -1 \n");
  srand(time(NULL));

  while (input != -1) {

    if (valido == 0) {
      multiplicandoA = (int) rand() % 10 + 1;
      multiplicandoB = (int) rand() % 10 + 1;
    }

    printf("¿ Cual es el resultado entre %d y %d ? ", multiplicandoA, multiplicandoB);
    scanf("%d", &input);

    // if input < -1, repeat the input process

    valido = verify(input, multiplicandoA, multiplicandoB);
    printMessage(valido);
  }

  return 0;
}
