#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    char str[150];
    printf("Ingrese la ruta del programa a ejecutar: ");
    scanf("%s", str);
    execl(str, str, (char *) NULL );
    printf("Hubo un error con la ruta especificada.\n");
}