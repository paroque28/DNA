#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <unistd.h>
#include "../Constants/constants.h"

int commandLine();
void generateChain(unsigned int,const char*);
int getRandomNumber();
const char* getHomePath();

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

    if(length < 7 && length>1000000) valid = 0; // invalid input less than 7 digits
    else valid = 1;
    if(!valid) goto lengthTag; // reAsk if is an invalid input
    nameTag:
    printf("Specify the NAME of the file:\n");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    if(strlen(name)<1) valid=0;
    else valid =1;
    if(!valid) goto nameTag; // reAsk if is an invalid input
    generateChain(length, name);
    return 0;
}
void generateChain(unsigned int length, const char* name)
{
    //init file
    static const FILE* fp;
    char path[MAX_NAME_LENGTH+2];
    strcpy(path,getHomePath()); strcat(path,"/Desktop/"); strcat(path,name); strcat(path, extension);
    printf(path);
    fp=fopen(path, "w");

    const char *homedir;

    int i = 0;
    char genes[] = {'A','G','C', 'T'};
    for (i = 0; i < length; ++i) {
        char randomChar = genes[getRandomNumber()];
        printf("%c", randomChar);
        fputc(randomChar,fp);
    }

    fclose(fp);

}


/* Basic random number generation. */
int getRandomNumber() {
    int num =  rand() % 4;
    //printf("%d \n", num);

    return num;
}

const char* getHomePath()
{
    if (!(getenv("HOME"))) {
        return getpwuid(getuid())->pw_dir;
    }
}