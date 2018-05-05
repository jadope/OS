#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// *** ~ a pointer of an array of strings
void getParams(char* commandLine, char*** params, int* backgroundFlag) {

    *params = NULL;
    char* token = strtok(commandLine, " ");
    printf("mem address: %p", *params);
    int tokenCounter = 0;

    // while(token) {
    //     *params = realloc(commandLine, sizeof (char*) * ++tokenCounter);                

    //     if (params == NULL)
    //         exit(-1);

    //     // params[tokenCounter-1] = token;
    //     token = strtok (NULL, " ");
    // }
}

int main(int argc, char const *argv[]) {

    int backgroundFlag = 0;
    char commandLine[200];

    // array of strings
    char** params;   
    printf("initial mem address: %p", *params);

    printf("\nSO@cli $ ");
    scanf("%s", commandLine);

    getParams(commandLine, &params, &backgroundFlag);
}
