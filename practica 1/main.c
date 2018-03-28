#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structures

struct Data {
    char pid[100];
    char name[100];
    char state[100];
    char text[100];
    char data[100];
    char stack[100];
    char voluntary[200];
    char involuntary[200];
};

typedef struct Data Data;

// data storing utilities

char *getValue(char *line) {

    char *value, divider = ':';

    if (line != NULL) {
        value = strchr(line, divider);
        value++;


        return value;
    } else {
        return NULL;
    }
}

void getName(char *buffer, Data *data) {

    char name[] = "Name", *line, *value;
    line = strstr(buffer, name);
    value = getValue(line);
    
    if (value != NULL) {
        strcpy(data->name,value);                
    } 
}

void getState(char *buffer, Data *data) {

    char state[] = "State", *line, *value;
    line = strstr(buffer, state);
    value = getValue(line);
    
    if (value != NULL) {        
        strcpy(data->state, value);          
    }
}

void getTextSpace(char *buffer, Data *data) {

    char text[] = "VmExe", *line, *value;
    line = strstr(buffer, text);
    value = getValue(line);
    
    if (value != NULL) {
        strcpy(data->text,value);              
    }
}

void getDataSpace(char *buffer, Data *data) {
    
    char _data[] = "VmData", *line, *value;
    line = strstr(buffer, _data);
    value = getValue(line);
    
    if (value != NULL) {
        strcpy(data->data, value);                
    }
}

void getStackSpace(char *buffer, Data *data) {

    char stack[] = "VmStk", *line, *value;
    line = strstr(buffer, stack);
    value = getValue(line);
    
    if (value != NULL) {
        strcpy(data->stack, value);            
    }
}

void getVoluntarySwitches(char *buffer, Data *data) {
    
    char voluntary[] = "voluntary_ctxt_switches", *line, *value;
    line = strstr(buffer, voluntary);
    value = getValue(line);
    
    if (value != NULL && strlen(data->voluntary) == 0) {
        strcpy(data->voluntary, value);             
    }
}

void getInvolutarySwitches(char *buffer, Data *data) {

    char involuntary[] = "nonvoluntary_ctxt_switches", *line, *value;       

    line = strstr(buffer, involuntary);
    value = getValue(line);    
    
    if (value != NULL) {        
        strcpy(data->involuntary, value);               
    }
}

// file reading and data storing utilities

void getData(char *buffer, Data *data) {              

    getName(buffer, data); 
    getState(buffer, data);
    getTextSpace(buffer, data);
    getDataSpace(buffer, data);
    getStackSpace(buffer, data);    
    getVoluntarySwitches(buffer, data);
    getInvolutarySwitches(buffer, data);    
}

void readFile(char *path, Data *data) {
    
    char buffer[100];
    FILE *file;

    file = fopen(path,"r");
    
    if(file == NULL) {
        printf("file opening failed for path: %s\n", path);
        exit(1);
    }

    while (fgets(buffer, 100, file) != NULL) {            
        getData(buffer, data);
    }
}

// common utilities for the argument processing section

Data *spawnDynamicDataArray(int size) {

    Data *array = malloc(size * sizeof(Data));    
    return array;
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

void storeProcessData(char *pid, int pos, Data *dataArray) {

    char *path = getFilePath(pid);
    readFile(path, &dataArray[pos]);
}

void printValues(int size, Data *data) {

    for (int i = 0; i < size; i++) {
        printf("proceso: %s \n", data[i].pid);
        printf("nombre del proceso: %s", data[i].name);
        printf("estado: %s", data[i].state);
        printf("tamaño de la region TEXT: %s", data[i].text);
        printf("tamaño de la region DATA: %s", data[i].data);
        printf("tamaño de la region STACK: %s", data[i].stack);
        printf("cambios voluntarios: %s", data[i].voluntary);
        printf("cambios involuntarios: %s", data[i].involuntary);
        printf("\n");
    }
}

// argument processing

// get and store the data of a single process
void getProcessData(char *args[]) {
    
    int size = 1;
    Data *dataArray = spawnDynamicDataArray(size);

    char *pid = args[1]; 
    strcpy(dataArray[0].pid, pid);

    storeProcessData(pid, 0, dataArray);            
    printValues(size, dataArray);
}

// get and store the data from a list of processes
void getProcessListData(char *args[]) {

    int counter = 2;

    while (args[counter] != NULL) {            
        counter++;            
    }

    int size = counter - 2;
    Data *dataArray = spawnDynamicDataArray(size);

    for (int i = 2, j = 0; j < size; i++, j++) {

        char *pid = args[i];
        strcpy(dataArray[j].pid, pid);

        storeProcessData(pid, j, dataArray);                          
    }

    printValues(size, dataArray);     
}

void processArgs(char *args[]) {
    
    char *flag = args[1]; 
    
    char listFlag[] = "-l";
    char saveFlag[] = "-r";  

    if (strcmp(listFlag, flag) != 0 && strcmp(saveFlag, flag) != 0) {

        getProcessData(args);
    }
    
    if (strcmp(listFlag, flag) == 0) {
        
        getProcessListData(args);       
    } 
    
    if (strcmp(saveFlag, flag) == 0) {

        getProcessListData(args);       
    }        
}

int main(int argc, char *argv[]) {

    processArgs(argv);    
}
