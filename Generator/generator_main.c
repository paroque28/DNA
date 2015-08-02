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

/**
 * @brief commandLine runs the generation interface
 * @return 0 when finished correctly
 */
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

/**
 * @brief generateChain creates the chain of genes
 * @param length the specified length of genes
 * @param name the name of the file were it is going to be saved
 */
void generateChain(unsigned int length, const char* name)
{
    //init file
    static const FILE* fp;
    char path[MAX_NAME_LENGTH+2];
    strcpy(path,getHomePath()); strcat(path,"/Desktop/"); strcat(path,name); strcat(path, extension);
    printf("%s\n",path);
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

/**
 * @brief getRandomNumber produces a random number between 0 and 3
 * @return the number generated
 */
int getRandomNumber() {
    int num =  rand() % 4;
    //printf("%d \n", num);

    return num;
}

/**
 * @brief getHomePath gets the location of home for file managing
 * @return home location
 */
const char* getHomePath()
{
        return getpwuid(getuid())->pw_dir;
}