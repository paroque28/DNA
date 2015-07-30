#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static const FILE* fp;
static const int genePool=4;

int main()
{
    time_t t;
    srand((unsigned) time(&t));
    commandLine();
    return 0;
}

int commandLine()
{
    int valid = 0;
    length: // tag to return if something went wrong
    printf("Specify the length of the DNA sequence:");
    for (int i = 0; i < 10; ++i) {
        getRandomNumber();
    }
    char DNAlength[10];
    scanf("%s", DNAlength);

    //if(!valid) goto length;

    return 0;
}

unsigned int generateChain(int length)
{
    int genes[] = {'A','G','C', 'T'};

}

/* basic file creation */
int createFile (char* name, int length, char* data)
{
    char fileLength[length];
    fp=fopen(name, "w");
    strcpy(fileLength, data);
    fprintf(fp, "%s \n", fileLength);
    fclose(fp);

    return 0;
}

/* Basic random number generation. */
int getRandomNumber() {
    int num =  rand() % 4;
    printf("%d \n", num);

    return num;
}