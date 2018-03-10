/*Hacer una función que tome un número entero positivo y que retorne la suma de cada uno de sus dígitos. La función deberá validar que el número ingresado sea positivo; Si el número ingresado resulta siendo negativo, esta retornará -1*/
#include <stdio.h>
#include <math.h>

int sumaDigitos(int);
int digitCounter(int);

int main(){
    int num;
    int seguir;
    do{
        printf("Ingrese el número para sumar sus dígitos: ");
        scanf("%d", &num);
        sumaDigitos(num);
        printf("¿Quiere seguir ingresando números, ingrese 1 para sí, cualquier otro valor para no: ");
        scanf("%d",&seguir);
    } while (seguir==1);
    return 0;
}

int sumaDigitos(int a){
    if(a<0){
        printf("Ingresó un número negativo.");
        return -1;
    }
    else{
        int auxiliar, i, longitud;
        int result=0;
        double temp=0;
        longitud = digitCounter(a);
        for (i=1; i<=longitud; i++){
            temp=fmod(a, pow(10, i))/pow(10,i-1);
            auxiliar=temp;
            result=result+auxiliar;
        }    
        printf("El resultado de la suma de todos los dígitos es de %d\n", result);
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

