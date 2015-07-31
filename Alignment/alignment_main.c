#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <unistd.h>

#include "alignment.h"
#include "../Constants/constants.h"

int lengthI, lengthJ = 0;
const char* getHomePath();

int main() {
    needlemanWunsch("TACCGCA",7,"TGATGCG",7);
    //readFiles();
    return 0;
}



char* openDnaFile(char* fileName) {
    FILE *file;
    char* read;
    char c;
    int counter = 0;
    char path[MAX_NAME_LENGTH+2];
    strcpy(path,getHomePath()); strcat(path,"/Desktop/"); strcat(path,fileName); strcat(path, extension);
    printf(path);

    file = fopen(fileName, "r");

    if (file==NULL) {
        printf(" Error: File %s does not exist \n", fileName);
    } else {
        do {
            c = getc(file);
            counter++;
            strcat(read, &c);

        } while (c != EOF);
    }
    fclose(file);

    return read;
}

int readFiles(){
    int lengthI, lengthJ = 0;
    char* firstSeq, secondSeq, firstFile[30], secondFile[30];

    printf("First sequence: ");
    scanf("%s", firstFile);

    printf("Second sequence: ");
    scanf("%s", secondFile);

    firstSeq = openDnaFile(firstFile);
    secondSeq = openDnaFile(secondFile);

    needlemanWunsch(firstSeq, 7, secondSeq, 7);

    return 0;
}

const char* getHomePath()
{
    if (!(getenv("HOME"))) {
        return getpwuid(getuid())->pw_dir;
    }
}