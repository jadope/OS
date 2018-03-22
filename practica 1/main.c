
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
};

struct Data data;

void getValue(char *identifier, char *string) {

}

void getData(char *buffer) {

    // printf("%s", buffer);
    char *line, *value;
    char name[] = "Name", divider = ':';

    line = strstr(buffer, name);
    
    if (line != NULL) {
        value = strchr(line, divider);
        value++;
        data.name = value;
        printf("%s", data.name);
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

