//
// Created by Pablo Rodriguez Quesada on 7/31/15.
//

#ifndef DNASEQUENCEALIGNMENT_ALIGN_H
#define DNASEQUENCEALIGNMENT_ALIGN_H

#include <stdio.h>
#include <stdlib.h>

extern const int SIMILARITY_MATRIX[4][4];
extern const int GAP;
static const int MIN_INT = -2147483647;

int getValueOfMatch(char a, char b);
int getCharValue(char value);
void needlemanWunsch(const char*,int,const char*, int);
void bestMove(int** results, short** resultsDirection, int diag, int izq, int der, int i, int j);
#endif //DNASEQUENCEALIGNMENT_SOURCE_FILE_H
