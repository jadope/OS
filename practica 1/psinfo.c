#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// structures

struct Data {
    char pid[100];
    char name[100];
    char state[100];
    char segment[100];
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

        while(isspace(*value)) {
            value++;
        }                

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

void getSegmentsSpace(char *buffer, Data *data) {

    char segmentData[] = "VmData", *line, *value;
    line = strstr(buffer, segmentData);
    value = getValue(line);
    
    if (value != NULL) {        
        strcpy(data->segment, value);          
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

void getData(char *buffer, Data *data) {              

    // todo: stop the execution when a line is found and store    
    getName(buffer, data); 
    getState(buffer, data);
    getSegmentsSpace(buffer, data);
    getTextSpace(buffer, data);
    getDataSpace(buffer, data);
    getStackSpace(buffer, data);    
    getVoluntarySwitches(buffer, data);
    getInvolutarySwitches(buffer, data);    
}

// file reading and data storing utilities

void readFile(char *path, Data *data) {
    
    char buffer[100];
    FILE *file;

    file = fopen(path,"r");
    
    if(file == NULL) {
    
        printf("Unexpected error while opening a file in the following path: %s \n", path);        
        exit(1);

    } else {

        while (fgets(buffer, 100, file) != NULL) {            
            getData(buffer, data);
        }
    }
}

void writeToFile(char *path, char *line) {

    FILE *fp;
    fp = fopen(path, "a+");

    if(fp == NULL) {
    
        printf("Unexpected error while opening a file in the following path: %s \n", path);        
        exit(1);

    } else {

        fputs(line, fp);
        fclose(fp);
    }
}

void removeFile(char *path) {

    remove(path);
}

// common utilities for the argument processing section

Data *spawnDynamicDataArray(int size) {

    Data *array = malloc(size * sizeof(Data));    

    for (int i = 0; i < size; i++) {
        char noValue[] = "0 \n";
        strcpy(array[i].segment, noValue);
        strcpy(array[i].text, noValue);
        strcpy(array[i].data, noValue);
        strcpy(array[i].stack, noValue);    
    }

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

void printValues(int size, Data *data, int writeFlag, char *path) {

    for (int i = 0; i < size; i++) {

        char pid[150];
        sprintf(pid, "proceso: %s \n", data[i].pid);
        
        char name[150];
        sprintf(name, "nombre del proceso: %s", data[i].name);

        char state[150];
        sprintf(state, "estado: %s", data[i].state);
        
        char segment[150];
        sprintf(segment, "tamaño total de la imagen de memoria: %s", data[i].segment);

        char text[150];
        sprintf(text, "tamaño de la region TEXT: %s", data[i].text);

        char dataRegion[150];
        sprintf(dataRegion, "tamaño de la region DATA: %s", data[i].data);

        char stack[150];
        sprintf(stack, "tamaño de la region STACK: %s", data[i].stack);

        char voluntary[150];
        sprintf(voluntary, "cambios voluntarios: %s", data[i].voluntary);

        char involuntary[150];
        sprintf(involuntary, "cambios involuntarios: %s \n", data[i].involuntary);

        // todo: automate this process
        if (writeFlag != 1) {

            printf("%s", pid);
            printf("%s", name);
            printf("%s", state);
            printf("%s", segment);
            printf("%s", text);            
            printf("%s", dataRegion);
            printf("%s", stack);        
            printf("%s", voluntary);
            printf("%s", involuntary);            

        } else {
            
            writeToFile(path, pid);
            writeToFile(path, name);
            writeToFile(path, state);
            writeToFile(path, segment);
            writeToFile(path, text);            
            writeToFile(path, dataRegion);
            writeToFile(path, stack);
            writeToFile(path, voluntary);
            writeToFile(path, involuntary);
        }        
    }
}

// argument processing

// check for every process existance
void checkArguments(int pos, int size, char *arguments[]) {

    int flag = 0, errorIndex = 0;
    char messages[size][100];
    FILE *fp;

    for(int i = pos, j = 0; j < size; i++, j++) {
        
        char *pid = arguments[i];
        char *path = getFilePath(pid);                

        fp = fopen(path, "r");        
        
        if (fp == NULL) {      

            // todo: something is stored on path if the file opening failed
            free(path);
            strcpy(messages[errorIndex], pid);            
            errorIndex++;
            flag = 1;            
        }
    }

    if (flag == 1) {

        printf("hay argumentos invalidos. Estos procesos no se han podido encontrar: \n");

        for (int i = 0; i < errorIndex; i++) {

            printf("%s \n", messages[i]);
        }

        exit(1);
    }
}

// get and store the data of a single process
void getProcessData(char *args[]) {
    
    int size = 1, writeFlag = 0;

    checkArguments(1, size, args);

    Data *dataArray = spawnDynamicDataArray(size);
    char *pid = args[1]; 

    strcpy(dataArray[0].pid, pid);
    storeProcessData(pid, 0, dataArray);            

    printValues(size, dataArray, writeFlag, NULL);

    free(dataArray);
}

// get and store the data from a list of processes
void getProcessListData(char *args[], int writeFlag) {

    int counter = 2;
    char path[150];

    while (args[counter] != NULL) {            
        counter++;
    }

    int size = counter - 2;

    checkArguments(2, size, args);

    Data *dataArray = spawnDynamicDataArray(size);
    strcpy(path, "psinfo-report");    

    for (int i = 2, j = 0; j < size; i++, j++) {

        char *pid = args[i];    

        strcat(path, "-");        
        strcat(path, pid);        

        strcpy(dataArray[j].pid, pid);
        storeProcessData(pid, j, dataArray);                          
    }

    if (writeFlag != 1) {

        printValues(size, dataArray, writeFlag, NULL);     

    } else {
        
        strcat(path, ".txt");        
        printf("generando archivo: %s \n", path);

        removeFile(path);
        printValues(size, dataArray, writeFlag, path);        
    }    

    free(dataArray);
}

// check if the provided flag is of type "-r" or "-l"
void checkInput(char *flag, char *args[]) {

    if (flag == NULL) {
        printf("No hay argumentos \n");           
        exit(2);
    }

    // todo: check asyntomatic complexity
    if (flag[0] == '-') {

        if (flag[1] != 'r' && flag[1] != 'l') {

            printf("El argumento %s no es valido, utilice en cambio -l o -r \n", flag);   
            exit(1);
        }

        if (args[2] == NULL) {
            printf("No hay argumentos \n");           
            exit(2);
        }

    } else {

        if (args[1] == NULL) {
            printf("No hay argumentos \n");           
            exit(2);
        }
    }
}

void processArgs(char *args[]) {
    
    char *flag = args[1]; 
    
    char listFlag[] = "-l";
    char saveFlag[] = "-r";  
    int writeFlag;

    checkInput(flag, args);

    if (strcmp(listFlag, flag) != 0 && strcmp(saveFlag, flag) != 0) {

        getProcessData(args);
    }
    
    if (strcmp(listFlag, flag) == 0) {
        
        writeFlag = 0;
        getProcessListData(args, writeFlag);       
    } 
    
    if (strcmp(saveFlag, flag) == 0) {

        writeFlag = 1;
        getProcessListData(args, writeFlag);       
    }        

    exit(0);
}

int main(int argc, char *argv[]) {

    processArgs(argv);    
}
