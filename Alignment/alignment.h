//
// Created by Pablo Rodriguez Quesada on 7/31/15.
//

#ifndef DNASEQUENCEALIGNMENT_ALIGN_H
#define DNASEQUENCEALIGNMENT_ALIGN_H

#include <stdio.h>
#include <stdlib.h>

const int MATCHES[4][4]= {{10,-1,-3,-4},{-1,7,-5,-3},{-3,5,9,0},{-4,-3,0,8}};
const int GAP = -5;
int getValueOfMatch(char a, char b);
int getCharValue(char value);
char* needlemanWunsch(const char*,int,const char*, int);

#endif //DNASEQUENCEALIGNMENT_SOURCE_FILE_H
