//
// Created by Pablo Rodriguez Quesada on 7/31/15.
//


#include "alignment.h"

/**
 * Donde char genes[] = {'A','C','G','T'}; A->0 C->1 G->2 T->3
 */
int getValueOfMatch(char a, char b)
{
    return MATCHES[getCharValue(a)][getCharValue(b)];
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

char *needlemanWunsch(const char *a, int lengtha, const char *b, int lengthb) {
    int results[lengtha+1][lengthb+1];
    results[0][0]=0;
    int diag,izq,der;
    for (int i = 0; i < lengtha + 1; ++i) {
        for (int j = 0; j < lengthb + 1; ++j) {
            //Diagonal
            if(i&&j)//i!=0 and j!=0. Check si existe lugar
            {
                diag = results[i-1][j-1] + getValueOfMatch(a[i],b[j]);
            }
            if(i)//Check si existe lugar
            {
                izq = results[i-1][j] + GAP;
            }
            if(j)//Check si existe lugar
            {
                der = results[i][j-1] + GAP;
            }
        }
    }



}
