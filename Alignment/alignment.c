//
// Created by Pablo Rodriguez Quesada on 7/31/15.
//


#include "alignment.h"

/**
 * Donde char genes[] = {'A','C','G','T'}; A->0 C->1 G->2 T->3
 */
int getValueOfMatch(char a, char b)
{
    return matches[getCharValue(a)][getCharValue(b)];
}
/**
 * Se usa para accesar la matriz del match
 */
int getCharValue(char value) {
    if(value == 'A') return 0;
    else if(value == 'C') return 1;
    else if(value == 'G') return 2;
    else if (value =='T') return 3;
    //else if (value == '-') return 4;
    else {
        printf ("Error: char not recognized or corrupted char stream");
        exit(1);
    }

}
