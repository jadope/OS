#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  pid_t pid_h1, pid_h2, pid_h3;
  pid_t pid_n;
  int i = 0;
  int estado;

  pid_h1 = fork();

  if(pid_h1 == 0) { // hijo 1

    i++;

    wait(&estado);
    pid_n = fork();

    if(pid_n==0) {    // nieto 1

      i++;
      printf("NIETO: i = %d\n",i);

    }else {   // hijo 1 

      printf("HIJO 1: i = %d\n",i);
    }

  }else {   // padre

    wait(&estado);
    pid_h2 = fork();

    if(pid_h2 == 0) {  // hijo 2

      i++;
      printf("HIJO 2: i = %d\n",i);

    } else { // padre

      wait(&estado);
      pid_h3 = fork(); 

      if(pid_h3 == 0) { // hijo 3

         i++;
         printf("HIJO 3: i = %d\n",i);

      } else { // papa

         wait(&estado);
         printf("PAPA: i = %d\n",i);
      }
    }
  }
  return 0;
}
