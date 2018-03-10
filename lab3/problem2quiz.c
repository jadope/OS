/*Implementar una función que permita realizar la conversión de un número en sistema decimal a un número binario. El programa deberá solicitar al usuario que ingrese un número entero. Este valor deberá ser pasado como argumento a la función creada. La función deberá retornar el resultado, para que el programa lo imprima en pantalla.*/
#include <stdio.h>
#include <math.h>


long decimalToBinary(long);

int main(){
    long decnum;
    long binnum;
    printf("Escriba en pantalla el número decimal que quiere convertir a binario: ");
    scanf("%ld", &decnum);
    binnum = decimalToBinary(decnum);
    printf("El número %ld en binario es: %ld\n", decnum, binnum);
    return 0;
}
 
long decimalToBinary(long n) {
    int numb; 
    long bin = 0, i = 1;
  
    while(n != 0) {
        numb = n%2;
        n = n/2;
        bin+=(numb*i);
        i = i*10;
    }
    return bin;
}