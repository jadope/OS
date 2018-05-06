#include <stdio.h>
#include <stdlib.h>     //exit
#include <unistd.h>  

int main(int argc, char *argv[]) {

    printf("hello world !, this is my first argument: %s \n", argv[0]);
    // execvp("pwd", argv);
    exit(0);
}