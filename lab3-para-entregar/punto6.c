#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>

int main() {
    // int estado;
    // pid_t pp;
    pid_t ph;
    pid_t pn;
    
    // fflush(stdout);

    ph = fork();

    if (ph == 0) { // hijo

        // sleep(2);
        printf("mundo\n");

        pn = fork();
        
        if (pn == 0) {

            printf("!\n");
        }

    } else {

        printf("Hola\n");
    }

    // wait(&estado);
    // printf("Mundo");
    // fflush(stdout);
    // fork();   

    // wait(&estado);
    // printf("!");
    // fflush(stdout);
}
