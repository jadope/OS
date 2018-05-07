#include <stdio.h>
#include <string.h>
#include <stdlib.h>     //exit
#include <unistd.h>     // execvp, getcwd
#include <sys/types.h>  // fork
#include <sys/wait.h>   // wait
#include <sys/types.h>  // pid_t
#include <errno.h>

#include "command-table.h"

void handleError(int resultCode) {

    if (resultCode == -1) {
        printf("El programa no se pudo ejecutar y ha generado el siguiente error: %d\n", errno);
    }
}

void spawnChild(char* path, char** items, int background) {

    int estado, resultCode;
    pid_t childProcess;

    childProcess = fork();

    if (childProcess == 0){
        
        resultCode = execv(path, items);                
        handleError(resultCode);

    } else {    

        if (background == 0) {
            wait(&estado);
        }
    }
}

void issueCall(char *expresion, char** items , int background) {

    char* program;
    char path[300];

    getcwd(path, sizeof(path));

    switch(getCommand(items[0])) {     

        case mypwd:         
            program = "/commands/mypwd.o";
            strcat(path, program);            
            spawnChild(path, items, background);
            break;        

        case myecho:
            program = "/commands/myecho.o";
            strcat(path, program);            
            spawnChild(path, items, background);       
            break;

        case myclear:            
            program = "/commands/myclear.o";
            strcat(path, program);            
            spawnChild(path, items, background);       
            break;

        case mykill:
            program = "/commands/mykill.o";
            strcat(path, program);            
            spawnChild(path, items, background);       
            break;

        case mytime:
            program = "/commands/mytime.o";
            strcat(path, program);            
            spawnChild(path, items, background);       
            break;    

        case myps:
            program = "/commands/myps.o";
            strcat(path, program);            
            spawnChild(path, items, background);       
            break;   

        case myexit: 
            exit(0);

        case outercall:
            program = items[0];                        
            spawnChild(program, items, background);
            break;  
    }
}