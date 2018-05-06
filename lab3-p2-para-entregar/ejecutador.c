#include <stdio.h>
#include <string.h>
#include <stdlib.h>     //exit
#include <unistd.h>     // execvp, getcwd
#include <sys/types.h>  // fork
#include <sys/wait.h>   // wait
#include <sys/types.h>  // pid_t

// comands
#define outercall -1
#define mypwd 1
#define mycp 2
#define myecho 3
#define myclear 4
#define mykill 5

// struct definition
typedef struct {
    char *key;
    int val;
} CliDictionary;

// struct array initialization
static CliDictionary lookUpTable[] = {
    {"mypwd", mypwd}, {"mycp", mycp}, {"myecho", myecho}, {"myclear", myclear},
    {"mykill", mykill}
};

int getCommand(char *key) {

    long dictionarySize = (sizeof(lookUpTable)/ sizeof(CliDictionary));
    for (int i = 0; i < dictionarySize; i++) {    
        if (strcmp(lookUpTable[i].key, key) == 0)
            return lookUpTable[i].val;            
    }
    return outercall;
}

void spawnChild(char* path, char** items, int background) {

    int estado;
    pid_t childProcess;

    childProcess = fork();

    if (childProcess == 0){
        execv(path, items);                
    } else {    
        if (background == 0) {
            wait(&estado);
        }
    }
}

void issueCall(char *expresion, char** items, int itemsSize, int background) {

    char* program;
    char path[300];

    getcwd(path, sizeof(path));

    switch(getCommand(items[0])) {     

        case mypwd:         
            program = "/commands/mypwd.o";
            strcat(path, program);            
            spawnChild(path, items, background);
            break;

        case mycp:
            printf("its a cp! \n");        
            break;

        case myecho:
            program = "/commands/myecho.o";
            strcat(path, program);            
            spawnChild(path, items, background);       
            break;

        case myclear:
            printf("its a clear! \n");       
            break;

        case mykill:
            program = "/commands/mykill.o";
            strcat(path, program);            
            spawnChild(path, items, background);       
            break;

        case outercall:
            printf("outer call \n");   
            break;  
    }
}