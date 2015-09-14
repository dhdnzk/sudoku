/* 스도쿠 푸는 프로그램¿ (ver 2.0) *
 * developed by IDH
 * last modified : 2015/8/3
 *
 * 프로젝트 폴더 안에 있는 quiz.txt파일에 스도쿠 문제를 입력한 뒤 프로그램을 
 * 실행시키면 문제를 풀어 정답을 알려드립니다.(빈칸 : 0으로 입력)
 * 
 *
 * (ver 1.0)->(ver 2.0) 변경사항*
 * board 배열을 int형9x9배열에서 Element형9x9 구조체 배열로 변경(후보자 수 개념 도입)
 * 그에 따른 기존 함수들 전면 수정
 * 파일에서 문제 읽어들이는 과정(main함수에 있던 부분) 따로 함수로 정의해서 호출하는 방식으로 변경
 * 후보자 수 개념을 적용해 풀 수 있는 함수들 정의
 *
 */
#include "common.h"
#include "calc.h"

int main(void)
{
	//풀리지 않은 문제 수
	int totalCount = 0;	
	//임시 count
	int Count = 0;
	int x, y;
	Element board[ROW_LEN][LINE_LEN];
	
	if (ReadQuizFile(board, &totalCount) == -1)
	return 0;


	//문제 출력
	printf("문제\n");
	printf("풀어야 할 문제 : %d\n", totalCount);
	for(y = 0; y < ROW_LEN; y++) {
		for(x = 0; x < LINE_LEN; x++) {
			if(board[y][x].firmedElement == 0)
				printf("   ");
			else
				printf(" %d ", board[y][x].firmedElement);
		}
		printf("\n");
	}

	
	//배열 요소 중 남아있는 0이 없을때까지 진행
	while (Count != 100) {
		Calc1(board, &totalCount);
		Calc2(board, &totalCount);
		Count++;
	}
	
	printf("\n풀이 결과\n");
	printf("못 푼 문제 : %d개\n", totalCount);

	for (y = 0; y < ROW_LEN; y++) {
		for ( x = 0; x < LINE_LEN; x++) {
			if(board[y][x].firmedElement == 0)
				printf("   ");
			else
				printf(" %d ", board[y][x].firmedElement);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
	}
