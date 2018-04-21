#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t ph1;
    pid_t ph2;
    pid_t pn1;
    pid_t pn2;
    int estado;

    ph1 = fork();

    if (ph1==0){ //hijo 1

        printf("Soy el hijo 1.\n");

    }
    else//padre.
    {        
        
        printf("Soy el padre.\n");
        
        ph2=fork();

        if(ph2==0){//hijo 2

            printf("Soy el hijo 2.\n");
            pn1=fork(); // creo el nieto 1
            
            if (pn1==0){ // valido si es el nieto 1.
                fflush(stdout);
                printf("Soy el nieto 1.\n");

            }
            else{ // sigue siendo el hijo 2.
                wait(&estado);
                pn2=fork();
                if(pn2==0){
                    fflush(stdout);
                    printf("Soy el nieto 2.\n");

                }
            }
            
        }
        // else {
        //     printf("Soy el padre.\n");
        // }
    }

}