
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

void getData(char *buffer) {

    char *line, *value;
    char name[] = "Name",
         state[] = "State",
         text[] = "VmExe",
         _data[] = "VmData",
         stack[] = "VmStk",
         voluntary[] = "voluntary_ctxt_switches",
         involuntary[] = "nonvoluntary_ctxt_switches";         

    line = strstr(buffer, name);
    value = getValue(line);
    
    if (value != NULL) {
        data.name = value;        
        printf("nombre: %s", data.name);
    }    
    
    line = strstr(buffer, state);
    value = getValue(line);
    
    if (value != NULL) {
        data.state = value;
        printf("estado: %s", data.state);        
    }

    line = strstr(buffer, text);
    value = getValue(line);
    
    if (value != NULL) {
        data.text = value;
        printf("text: %s", data.text);        
    }

    line = strstr(buffer, _data);
    value = getValue(line);
    
    if (value != NULL) {
        data.data = value;
        printf("data: %s", data.data);        
    }

    line = strstr(buffer, stack);
    value = getValue(line);
    
    if (value != NULL) {
        data.stack = value;
        printf("stack: %s", data.stack);        
    }

    line = strstr(buffer, voluntary);
    value = getValue(line);
    
    if (value != NULL && data.voluntary == NULL) {
        data.voluntary = value;
        printf("voluntary: %s", data.voluntary);        
    }

    line = strstr(buffer, involuntary);
    value = getValue(line);
    
    if (value != NULL) {
        data.involuntary = value;
        printf("involuntary: %s", data.involuntary);        
    }
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

