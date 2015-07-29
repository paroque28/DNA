#include <stdio.h>

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