#include<stdio.h>
#include<unistd.h>
int main() {
   printf("Hola ");
   fork();
   printf("Mundo");
   fork();
   printf("!");
}
