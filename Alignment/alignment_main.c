
#include "alignment.h"
#include "stdlib.h"

static const FILE* file;

int main() {
    needlemanWunsch("GCATGCA",7,"GATTACA",7);



    return 0;
}


int readFiles(){
    int lengthI, lengthJ;
    char* firstSeq, secondSeq, firstFile, secondFile;

    printf("First sequence: ");
    lengthI = scanf("%s", firstFile);

    printf("Second sequence: ");
    lengthJ = scanf("%s", secondFile);

    firstSeq = openDnaFile(firstFile, lengthI);
    secondSeq = openDnaFile(secondFile, lengthJ);

    needlemanWunsch(firstSeq, lengthI, secondSeq, lengthJ);

    return 0;
}

char* openDnaFile(char* fileName, int fileLength) {

}