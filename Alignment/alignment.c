//
// Created by Pablo Rodriguez Quesada on 7/31/15.
//


#include "alignment.h"

const int SIMILARITY_MATRIX [4][4] ={{1,-1,-1,-1},{1,-1,1,1},{1,1,-1,1},{1,1,1,-1}};  //{{10,-1,-3,-4},{-1,7,-5,-3},{-3,5,9,0},{-4,-3,0,8}};
const int GAP = -2;//-5
/**
 * Donde char genes[] = {'A','C','G','T'}; A->0 C->1 G->2 T->3
 */
int getValueOfMatch(char a, char b)
{
    return SIMILARITY_MATRIX[getCharValue(a)][getCharValue(b)];
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
        printf ("Error: char not recognized : '%c' or corrupted char stream\n", value);
        exit(1);
    }

}

char *needlemanWunsch(const char *a, int lengtha, const char *b, int lengthb) {
    printf("Needleman Wunsch Algorithm for :'%s' and '%s'\n",a,b);
    int results[lengtha+1][lengthb+1];
    results[0][0]=0;
    int diag,izq,der;
    for (int i = 0; i < lengtha + 1; ++i) {
        for (int j = 0; j < lengthb + 1; ++j) {
            if(!(i||j)) continue;
            diag = MIN_INT; izq = MIN_INT; der= MIN_INT;
            //Diagonal
            if(i&&j)//i!=0 and j!=0. Check si existe lugar
            {
                diag = results[i-1][j-1] + getValueOfMatch(a[i-1],b[i-1]);
            }

            if(i)//Check si existe lugar
            {
                izq = results[i-1][j] + GAP;
            }
            if(j)//Check si existe lugar
            {
                der = results[i][j-1] + GAP;
            }
            //Get max number
            if(diag>izq){
                if(diag>der)results[i][j] = diag;
                else results[i][j] = der;
            }
            else if(izq>der) results[i][j] = izq;
            else results[i][j] = der;
        }
    }
    //print the matrix for tests
    for (int i = 0; i < lengtha + 1; ++i) {
        printf("[");
        for (int j = 0; j < lengthb + 1; ++j) {

            printf("%d ",results[i][j]);
        }
        printf("]\n");
    }
    char * result;
    return result;
}
