
/** 표준 헤더, 매크로 모음 **/
#ifndef __COMMON_H__
#define __COMMON_H__

#include<stdio.h>
#define LINE_LEN	9
#define ROW_LEN		9

/* board배열의 각 요소에 해당하는 구조체 정의 */
typedef struct element
{
	//후보자 수 정보를 담고있는 [3][3] 배열
	int candidate[3][3];

	//답으로 확정되었을시에 해당 수를 아래 변수에 저장 
	int firmedElement;

	//남은 후보자 수의 개수 정보
	int restCandidate;
}Element;

#endif
