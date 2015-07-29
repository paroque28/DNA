#include <stdio.h>
#include <string.h>

static const FILE* fp;

int main()
{
    commandLine();
    return 0;
}

int commandLine()
{
    int valid = 0;
    length: // tag to return if something went wrong
    printf("Specify the length of the DNA sequence:");
    if(!valid) goto length;
}

unsigned int generateChain(int length)
{
    int genes[] = {'A','G','C', 'T'};

}

int createFile (char* name, int length, char* data)
{
    char fileLength[length];
    fp=fopen(name, "w");
    strcpy(fileLength, data);
    fprintf(fp, "%s \n", fileLength);
    fclose(fp);

    return 0;
}
