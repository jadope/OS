#include <stdio.h>
#include <stdlib.h>     //exit
#include <unistd.h>  

int main(int argc, char *argv[]) {
    execvp("pwd", argv);
    exit(0);
}
