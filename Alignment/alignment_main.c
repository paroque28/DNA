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


/**
 * @brief openDnaFile opens and processes the DNA files, turning them into inputs
 * @param fileName the file to be opened, without extension
 * @return  the char* with the contents of the file
 */
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

/**
 * @brief readFiles prompts the user and manages the file input
 * @return 0 when finished correctly
 */
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

/**
 * @brief getHomePath gets the location of home for file managing
 * @return home location
 */
const char* getHomePath()
{
    if (!(getenv("HOME"))) {
        return getpwuid(getuid())->pw_dir;
    }
}