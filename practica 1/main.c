#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structures

struct Data {
    char *name;
    char *state;
    char *text;
    char *data;
    char *stack;
    char *voluntary;
    char *involuntary;
};

typedef struct Data Data;

// global variables

Data data;
char *line, *value;

// utils

char *getValue(char *line) {
    char *value;
    char divider = ':';

    if (line != NULL) {
        value = strchr(line, divider);
        value++;
        return value;
    } else {
        return NULL;
    }
}

void getName(char *buffer) {

    char name[] = "Name";
    line = strstr(buffer, name);
    value = getValue(line);
    
    if (value != NULL) {
        data.name = value;        
        printf("nombre: %s", data.name);
    } 
}

void getState(char *buffer) {

    char state[] = "State";
    line = strstr(buffer, state);
    value = getValue(line);
    
    if (value != NULL) {
        data.state = value;
        printf("estado: %s", data.state);        
    }
}

void getTextSpace(char *buffer) {

    char text[] = "VmExe";
    line = strstr(buffer, text);
    value = getValue(line);
    
    if (value != NULL) {
        data.text = value;
        printf("text: %s", data.text);        
    }
}

void getDataSpace(char *buffer) {
    
    char _data[] = "VmData";
    line = strstr(buffer, _data);
    value = getValue(line);
    
    if (value != NULL) {
        data.data = value;
        printf("data: %s", data.data);        
    }
}

void getStackSpace(char *buffer) {

    char stack[] = "VmStk";
    line = strstr(buffer, stack);
    value = getValue(line);
    
    if (value != NULL) {
        data.stack = value;
        printf("stack: %s", data.stack);        
    }
}

void getVoluntarySwitches(char *buffer) {
    
    char voluntary[] = "voluntary_ctxt_switches";
    line = strstr(buffer, voluntary);
    value = getValue(line);
    
    if (value != NULL && data.voluntary == NULL) {
        data.voluntary = value;
        printf("voluntary: %s", data.voluntary);        
    }
}

void getInvolutarySwitches(char *buffer) {

    char involuntary[] = "nonvoluntary_ctxt_switches";       

    line = strstr(buffer, involuntary);
    value = getValue(line);
    
    if (value != NULL) {
        data.involuntary = value;
        printf("involuntary: %s", data.involuntary);        
    }
}

// main functions

void getData(char *buffer) {              

    getName(buffer); 
    getState(buffer);
    getTextSpace(buffer);
    getDataSpace(buffer);
    getStackSpace(buffer);    
    getVoluntarySwitches(buffer);
    getInvolutarySwitches(buffer);    
}

void readFile(char *path) {
    
    char buffer[100];
    FILE *file;

    file = fopen(path,"r");
    
    if(file == NULL) {
        printf("file opening failed for path: %s\n", path);
        exit(1);
    }

    while (fgets(buffer, 100, file) != NULL) {            
        getData(buffer);
    }
}

char *getFilePath(const char *pid) {

    char *path = malloc(100);
    char basePath[] = "/proc/";
    char status[] = "/status";

    strcat(path, basePath);
    strcat(path, pid);
    strcat(path, status);    

    return path;
}

// argument processing

Data *dynamicAllocation(int size) {

    Data *array = malloc(size * sizeof(Data));    

    return array;
}

void processArgs(char *args[]) {
    
    char *pid = args[1]; 
    char listFlag[] = "-l";
    
    if (strcmp(listFlag, pid) != 0) {

        char *path = getFilePath(pid);
        readFile(path);

    } else {

        int counter = 2;

        while (args[counter] != NULL) {

            printf("arg: %s \n", args[counter]);
            counter++;            
        }

        Data *dataArray = dynamicAllocation(counter);

        for (int i = 2, j = 0; i < counter; i++, j++) {

            pid = args[i];
            char *path = getFilePath(pid);
            readFile(path);            
        }        

        // printf("%s", dataArray[1]->name)
    }

    // return an array of structs     
}

int main(int argc, char *argv[]) {

    processArgs(argv);    
}
