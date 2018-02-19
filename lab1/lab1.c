#include <stdio.h>

float cm2pulg(float);

int main(int argc, char *argv[])
{
  float cm, pulg;
  printf("Digite la longitud (en cm): ");
  scanf("%f", &cm);
  pulg = cm2pulg(cm);
  printf("Resultados: %.1f cm= %.2f pulg\n", cm, pulg);
  return 0;

}

float cm2pulg (float cm){
  return cm/2.54;
}