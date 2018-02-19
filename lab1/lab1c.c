//gcc -Wall lab1c.c -lm -o je

#include <stdio.h>
#include <math.h>

double calcularDistancia(double, double, double, double);
void printPoint (double, double);

int main() {
    double x1, y1, x2, y2, dist;
    printf("Ingrese el primer punto: ");
    scanf("%lf%lf",&x1,&y1);
    printf("Ingrese el segundo punto: ");
    scanf("%lf%lf",&x2,&y2);
    dist = calcularDistancia(x1, y1, x2, y2);
    printf("La distancia entre ");
    printPoint(x1, y1);
    printf("y ");
    printPoint(x2,y2);
    printf("es %lf\n", dist);

    return 0;
}

double calcularDistancia (double x1, double y1, double x2, double y2){
    double dx = x2 - x1;
    double dy = y2 - y1;
    double d = sqrt(pow(dx, 2) + pow(dy,2));
    return d;
}

void printPoint(double x, double y){
    printf("(%.2lf, %.2lf) ", x, y);
}