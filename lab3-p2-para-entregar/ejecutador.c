#include <stdio.h>
#include <string.h>
#include <unistd.h>     // execvp, getcwd
#include <sys/types.h>  // fork
#include <sys/wait.h>   // wait

// comands
#define outercall -1
#define mypwd 1
#define mycp 2
#define myecho 3
#define myclear 4

// struct definition
typedef struct {
    char *key;
    int val;
} CliDictionary;

// struct array initialization
static CliDictionary lookUpTable[] = {
    {"mypwd", mypwd}, {"mycp", mycp}, {"myecho", myecho}, {"myclear", myclear}
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

    int pid;

    if( (pid == fork()) == 0 ){
        
        execv(path, items);

    } else {

        if (background == 0) {
            wait(&pid);
        }
    }
}

void issueCall(char *expresion, char** items, int itemsSize, int background) {

    char* program;
    char path[200];

    getcwd(path, sizeof(path));

    switch(getCommand(items[0])) {     

        case mypwd:                        
            program = "/commands/mypwd.o";
            strcat(path, program);            
            spawnChild(path, items, background);
            break;

        case mycp:
            printf("its a cp!");        
            break;
        case myecho:
            printf("its an echo!");            
            break;
        case myclear:
            printf("its a clear!");       
            break;
        case outercall:
            printf("outer call");     
    }
}