//Problema 1: Escriba una función llamada múltiplo que tome dos enteros y determine si el segundo es 
//múltiplo del primero. La función deberá tomar dos argumentos enteros y devolver 1 si el segundo es 
//un múltiplo del primero y 0 si no. Luego, utilice esta función en un programa que acepte como entrada 
//una serie de pares de enteros.

#include <stdio.h>
int multiplo(int, int); /*Se instancia la función*/

int main() {
    int x, y;
    int impar=1;
    printf("Introduzca un número par: ");
    scanf("%d", &x);
    if(x%2!=0){ /*En caso que no sea par el número, que lo vuelva a ingresar*/
        while (impar){
            printf("Verifique que el número ingresado es par. \nVuelva a digitarlo: ");
            scanf("%d", &x);
            if(x%2==0)
            impar=0;
        }
        impar=1;
    }
    
    printf("Introduzca un segundo número par: ");
    scanf("%d", &y);
    if(y%2!=0){ /*En caso que no sea par el número, que lo vuelva a ingresar*/
        while (impar){
            printf("Verifique que el número ingresado es par. \n Vuelva a digitarlo: ");
            scanf("%d", &y);
            if(y%2==0)
            impar=0;
        }
    }
    multiplo(x, y);
    return 0;
}

int multiplo(int a, int b) /* definicion de la funcion */ {
    float result;
    if (b%a==0){
        result = 1;
        printf("%d es múltiplo de %d\n", b, a);
    }
    else{
        result = 0;
        printf("%d no es múltiplo de %d\n", b, a);
    }
    return result; /* Devuelve 1 si b es múltiplo de a, sino 0. */
}