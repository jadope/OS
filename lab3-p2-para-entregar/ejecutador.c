#include <stdio.h>
#include <string.h>

// comands
#define outercall -1
#define mypwd 1
#define mycp 2
#define myecho 3
#define myclear 4

// struct definition
struct CliDictionary {
    char *key;
    int val;
};

typedef struct CliDictionary CliDictionary;

// struct initialization
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

void issueCall(char *expresion, char** items, int itemsSize, int background) {

    switch(getCommand(items[0])) {     

        case mypwd:
            printf("its a pwd!");    
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