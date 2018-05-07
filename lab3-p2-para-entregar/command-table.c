#include <string.h>

// commands
#define outercall -1
#define mypwd 1
#define mycp 2
#define myecho 3
#define myclear 4
#define mykill 5
#define mytime 6
#define myps 7
#define myexit 8

// struct definition
typedef struct {
    char *key;
    int val;
} CliDictionary;

// struct array initialization
static CliDictionary lookUpTable[] = {
    {"mypwd", mypwd}, 
    {"mycp", mycp},
    {"myecho", myecho}, 
    {"myclear", myclear},
    {"mykill", mykill}, 
    {"mytime", mytime}, 
    {"myps", myps},
    {"myexit", myexit}
};

int getCommand(char *key) {

    long dictionarySize = (sizeof(lookUpTable)/ sizeof(CliDictionary));
    
    for (int i = 0; i < dictionarySize; i++) {  

        if (strcmp(lookUpTable[i].key, key) == 0)
            return lookUpTable[i].val;            
    }
    return outercall;
}