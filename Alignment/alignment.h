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
char* needlemanWunsch(const char*,int,const char*, int);

#endif //DNASEQUENCEALIGNMENT_SOURCE_FILE_H
