
/** 풀이에 필요한 함수들 선언 **/
#ifndef __CALC_H__
#define __CALC_H__

#include "common.h"

void Calc1(Element (*)[LINE_LEN], int*);
void Calc2(Element (*)[LINE_LEN], int*);

/*******************(ver 2.0 추가 함수)************************/
int ReadQuizFile(Element(*arr)[LINE_LEN], int*);
void BoardInit(Element(*arr)[LINE_LEN]);
void CandidateRefresh(Element (*)[LINE_LEN]);

#endif
