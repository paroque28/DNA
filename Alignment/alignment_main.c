#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <unistd.h>

#include "alignment.h"
#include "../Constants/constants.h"

typedef struct string{
    unsigned long length;
    char *chars;
}string;

int lengthI, lengthJ = 0;
const char* getHomePath();
long get_file_length( FILE *file );
int readFiles();
string openDnaFile(char* fileName);

int main() {
    readFiles();
    return 0;
}





/**
 * @brief openDnaFile opens and processes the DNA files, turning them into inputs
 * @param fileName the file to be opened, without extension
 * @return  the char* with the contents of the file
 */
string openDnaFile(char* fileName) {
    FILE *file;
    char* read;
    string result;
    char path[FILENAME_MAX];
    strcpy(path,getHomePath()); strcat(path,"/Desktop/"); strcat(path,fileName); strcat(path,extension);
    printf("%s\n",path);

    file = fopen(path, "r");


    if (file==NULL) {
        exit(1);
    } else {
        char c;
        result.length = get_file_length(file);
        printf("Size: %ld \n", result.length);
        read = malloc(result.length);
        do {
            c = getc(file);
            strcat(read, &c);
        } while (c != EOF);
        result.chars = read;
    }
    fclose(file);

    return result;
}

/**
 * @brief readFiles prompts the user and manages the file input
 * @return 0 when finished correctly
 */
int readFiles(){
    int lengthI, lengthJ = 0;
    char firstFile[FILENAME_MAX], secondFile[FILENAME_MAX];

    printf("First sequence: ");
    scanf("%s", firstFile);

    printf("Second sequence: ");
    scanf("%s", secondFile);
    string a = openDnaFile(firstFile);
    string b = openDnaFile(secondFile);
    
    free(&firstFile); free(&secondFile);
    needlemanWunsch(a.chars,a.length,b.chars,b.length);
    
    return 0;
}

/**
 * @brief getHomePath gets the location of home for file managing
 * @return home location
 */
const char* getHomePath()
{
        return getpwuid(getuid())->pw_dir;
}

/**
 * Find legth of file
 */
long get_file_length( FILE *file ) {
    fpos_t position; // fpos_t may be a struct and store multibyte info
    long length; // break support for large files on 32-bit systems
Read
    fgetpos( file, &position ); // save previous position in file

    if ( fseek( file, 0, SEEK_END ) // seek to end
         || ( length = ftell( file ) ) == -1 ) { // determine offset of end
        perror( "Finding file length" ); // handle overflow
    }

    fsetpos( file, &position ); // restore position

    return length;
}