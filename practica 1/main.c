
/* 
    nombre, - Name
    estado, - State
    text, - VmExe
    data, - VmData
    stack, - VmStk
    cambios de contextos voluntarios - voluntary_ctxt-switches
    cambio de contexto no voluntarios - nonvoluntary_ctxt-switches
*/

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

struct Data data;

// global variables

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

void readFile() {

    char filename[80] = "status";
    char buffer[100];
    FILE *file;

    file = fopen(filename,"r");
    
    if(file == NULL) {
        printf("file opening failed %s\n", filename);
        exit(1);
    }

    while (fgets(buffer, 100, file) != NULL) {            
        getData(buffer);
    }
}

int main(int argc, char const *argv[]) {
    readFile();
}

