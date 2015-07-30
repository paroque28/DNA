#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static const FILE* fp;

int commandLine();
void generateChain(unsigned int);
int createFile(char* name, int length, char* data);
int getRandomNumber();
int main()
{
    time_t t;
    srand((unsigned) time(&t));
    commandLine();
    return 0;
}

int commandLine()
{
    int valid = 1;
    unsigned int length = 0;
    lengthTag: // tag to return if something went wrong
    printf("Specify the length of the DNA sequence:\n");

    scanf("%d", &length);// read from user

    if(length < 7) valid = 0; // invalid input less than 7 digits
    else valid = 1;
    if(!valid) goto lengthTag; // reAsk if is an invalid input

    generateChain(length);
    return 0;
}
void generateChain(unsigned int length)
{
    char genes[] = {'A','G','C', 'T'};
    for (int i = 0; i < length; ++i) {
        printf("%c",genes[getRandomNumber()]);
    }

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
    //printf("%d \n", num);

    return num;
}