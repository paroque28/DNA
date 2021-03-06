//
// Created by Pablo Rodriguez Quesada on 7/31/15.
//


#include "alignment.h"




const int SIMILARITY_MATRIX [4][4] ={{1,-1,-1,-1},{-1,1,-1,-1},{-1,-1,1,-1},{-1,-1,-1,1}};  //{{10,-1,-3,-4},{-1,7,-5,-3},{-3,5,9,0},{-4,-3,0,8}};
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
    else {
        printf ("Error: char not recognized : '%c' or corrupted char stream\n", value);
        exit(1);
    }

}

void needlemanWunsch(const char *a, int lengtha, const char *b, int lengthb) {
    printf("Needleman Wunsch Algorithm for :'%s' and '%s'\n",a,b);
    int results[lengtha+1][lengthb+1];
    short int resultsDirection[lengtha+1][lengthb+1];
    results[0][0]=0;
    int diag, left, up;
    int i, j = 0;
    for (i = 0; i < lengtha + 1; ++i) {
        for (j = 0; j < lengthb + 1; ++j) {
            if(!(i||j)) continue;
            diag = MIN_INT; left = MIN_INT; up = MIN_INT;
            //Diagonal
            if(i&&j)//i!=0 and j!=0. Check si existe lugar
            {
                diag = results[i-1][j-1] + getValueOfMatch(a[i-1],b[j-1]);
            }

            if(i)//Check si existe lugar
            {
                left = results[i-1][j] + GAP;
            }
            if(j)//Check si existe lugar
            {
                up = results[i][j-1] + GAP;
            }

            //Get max number
            if(diag> left){
                if(diag> up)
                {
                    results[i][j] = diag;
                    resultsDirection[i][j]= 0;
                }
                else
                {
                    results[i][j] = up;
                    resultsDirection[i][j]= 1;
                }
            }
            else if(left > up)
            {
                results[i][j] = left;
                resultsDirection[i][j]= -1;
            }
            else
            {
                results[i][j] = up;
                resultsDirection[i][j]= 1;
            }

        }
    }
    //print the matrix for tests
    for (j = 0; j < lengthb + 1; ++j) {
        printf("[");
        for (i = 0; i < lengtha + 1; ++i) {

            printf("%d ",results[i][j]);
        }
        printf("]\n");
    }
    i = lengtha;
    j = lengthb;
    node_t *node = malloc(sizeof(node_t));
    node->dir = resultsDirection[i][j];
    node->next = NULL;
    while (i || j)
    {
        node_t *prev = malloc(sizeof(node_t));
        int step = resultsDirection[i][j];
        prev->dir = step;
        prev->next = node;
        node = prev;
        switch (step) { // Manipulate directions
            case 1:
                j--;
                break;
            case -1:
                i--;
                break;
            case 0:
                i--;
                j--;
                break;
            default:
                printf("Error retriving steps! Got: %d and options are(-1(left),0,1(rigth))",step);
                exit(1);
            }

    }

    i=0;
    j=0;
    while(node->next!= NULL)
    {
        char left, right;
        switch (node->dir)
        {
            case 1:
                right = b[j];
                left = '-';
                j++;
                break;
            case -1:
                left = a[i];
                right = '-';
                i++;
                break;
            case 0:

                left = a[i];
                right = b[j];
                i++;
                j++;
                break;
        }


        if(left == right) printf("%c = %c\n",left, right);
        else printf("%c   %c\n",left, right);
        node_t *prev = node;
        node= node->next;
        free(prev);
    }
    free(node); // Garbage collection


}
