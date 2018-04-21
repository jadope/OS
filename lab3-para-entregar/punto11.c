
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int factorial(int hijo, int fact, int n) {

    int r;
    if (n == 1) {
        return 1;
    }
    r = n * factorial(hijo, fact, (n-1));

    printf("HIJO%d: fact(%d) = %d \n", hijo, fact, r);
    return r;
}

int main() {

    pid_t ph1;
    pid_t ph2;
    pid_t ph3;

    ph1 = fork(); 
    int resultado;

    if (ph1 == 0) {
        
        resultado = factorial(1, 10, 10);
        printf("Resultado final hijo 1: %d \n", resultado);

    } else {

        ph2 = fork();

        if (ph2 == 0) {

            resultado = factorial(2, 10, 10);
            printf("Resultado final hijo 2: %d \n", resultado);

        } else {

            ph3 = fork();

            if (ph3 == 0) {

                resultado = factorial(3, 10, 10);
                printf("Resultado final hijo 3: %d \n", resultado);
            }
        }
    }
}
