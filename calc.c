/** 풀이에 필요한 함수들 정의 **/
#include "common.h"
#include "calc.h"

/* void Calc1(Element (*) [LINE_LEN], int * ) 
 * 3x3확인 & 가로줄 확인 & 세로줄 확인 후 답을 채울 수 있으면 채우는 함수
 * Parameter	: 게임 판의 첫번째 주소값, 풀리지 않은 문제 수를 담는 변수의 주소값
 * Return type	: void
 */
void Calc1(Element (*arr) [LINE_LEN], int * totalCount)
{
	//temp 배열의 0번째 요소값의 의미 : [1]~[9]배열 안에 들어있는 0의 개수
	int temp[10];
	int ypos, xpos;
	int y, x;
	int num;

	for (ypos = 0; ypos < ROW_LEN; ypos++) {
		for (xpos = 0; xpos < LINE_LEN; xpos++) {
			if (arr[ypos][xpos].firmedElement != 0)
				continue;

			//temp 초기화
			temp[0] = 9;
			for (num = 1; num < 10; num++)	
				temp[num] = 0;
				
			//행 탐색
			for (x = 0; x < LINE_LEN; x++) {
				num = arr[ypos][x].firmedElement;
				if (num == 0)
					continue;
				if (temp[num] != num) {
				temp[num] = num;
					temp[0]--;
				}
			}

			//열 탐색
			for (y = 0; y < ROW_LEN; y++) {
				num = arr[y][xpos].firmedElement;
				if (num == 0)
					continue;
				if (temp[num] != num) {
					temp[num] = num;
					temp[0]--;
				}
			}

			//3x3 탐색	
			switch(ypos){
			case 0:
			case 1:
			case 2:
					if ((0 <= xpos) && (xpos < 3)){
						for (y = 0; y < 3; y++) {
							for (x = 0; x < 3; x++) {
								num = arr[y][x].firmedElement;
								if (num == 0)			
								continue;		
								if (temp[num] != num) {
									temp[num] = num;
									temp[0]--;
								}
							}
						}
					}

					else	if ((3 <= xpos) && (xpos < 6)) {
						for (y = 0; y < 3; y++) {
							for (x = 3; x < 6; x++) {
								num = arr[y][x].firmedElement;
								if (num == 0)		
								continue;		
								if (temp[num] != num) {
									temp[num] = num;
									temp[0]--;
								}
							}
						}
					}
					else	if ((6 <= xpos) && (xpos < 9)) {
						for (y = 0; y < 3; y++) {
							for (x = 6; x < 9; x++) {
								num = arr[y][x].firmedElement;
								if (num == 0)		
								continue;			
								if (temp[num] != num) {
									temp[num] = num;
									temp[0]--;
								}
							}
						}
					}
					break;
			case 3:
			case 4:
			case 5:	
					if ((0 <= xpos) && (xpos < 3)) {
						for (y = 3; y < 6; y++) {
							for (x = 0; x < 3; x++) {
								num = arr[y][x].firmedElement;
								if (num == 0)		
								continue;			
								if (temp[num] != num) {
									temp[num] = num;
									temp[0]--;
								}
							}
						}
					}

					else	if ((3 <= xpos) && (xpos < 6)) {
						for (y = 3; y < 6; y++) {
							for (x = 3; x < 6; x++) {
								num = arr[y][x].firmedElement;
								if (num == 0)		
								continue;			
								if (temp[num] != num) {
									temp[num] = num;
									temp[0]--;
								}
							}
						}
					}
					else	if ((6 <= xpos) && (xpos < 9)) {
						for (y = 3; y < 6; y++) {
							for (x = 6; x < 9; x++) {
								num = arr[y][x].firmedElement;
								if (num == 0)		
								continue;			
								if (temp[num] != num) {
									temp[num] = num;
									temp[0]--;
								}
							}
						}
					}
					break;
			case 6:
			case 7:
			case 8:
				if((0 <= xpos) && (xpos < 3)) {
					for (y = 6; y < 9; y++) {
						for (x = 0; x < 3; x++) {
							num = arr[y][x].firmedElement;
							if (num == 0)			
							continue;		
							if (temp[num] != num) {
								temp[num] = num;
								temp[0]--;
							}
						}
					}
				}
				else	if ((3 <= xpos) && (xpos < 6)) {
					for (y = 6; y < 9; y++) {
						for (x = 3; x < 6; x++) {
							num = arr[y][x].firmedElement;
							if (num == 0)			
							continue;				
							if (temp[num] != num) {
								temp[num] = num;
								temp[0]--;
							}
						}
					}
				}
				else if ((6 <= xpos) && (xpos < 9)) {
					for (y = 6; y < 9; y++) {
						for (x = 6; x < 9; x++) {
							num = arr[y][x].firmedElement;
							if (num == 0)			
							continue;	
							if (temp[num] != num) {
								temp[num] = num;
								temp[0]--;
							}
						}
					}
				}
				break;
			}

			//답 채울 수 있을때 실행
			if (temp[0] == 1) {
				for (num = 1; num < 10; num++) {
					if (temp[num] != num) {	
						arr[ypos][xpos].firmedElement = num;
						*totalCount -= 1;
					}
				}	
			}
		}
	}
}

/* void Calc2(Element (*) [LINE_LEN], int * )
 * 탐색할 숫자를 정한 뒤, 해당 수가 존재하는 x, y의 idx불끄기 방식
 * Parameter	: 게임 판의 첫번째 주소값, 풀리지 않은 문제 수를 담는 변수의 주소값
 * Return type	: void
 */
void Calc2(Element (*arr) [LINE_LEN], int * totalCount)
{
	int xarr[LINE_LEN];
	int yarr[ROW_LEN];
	int y, x;
	int xidx, yidx;
	int i;
	int resti;
	int idxclear;

	// i : 1~9 숫자 바꿔가며 탐색
	for (i = 0; i < 9; i++)
 	{
		resti = 9;
		for (idxclear = 0; idxclear < LINE_LEN; idxclear++) {
			xarr[idxclear] = idxclear;
		}

		// i값이 다음으로 넘어갈때마다 초기화
		for (idxclear = 0; idxclear < ROW_LEN; idxclear++) {
			yarr[idxclear] = idxclear;
		}		

		for (y = 0; y < ROW_LEN; y++) {
			for (x = 0; x < LINE_LEN; x++) {
				if (arr[y][x].firmedElement == (i+1)) {
					xarr[x] = -1;
					yarr[y] = -1;
					resti--;
				}
			}
		}

		//x, y 각각 유효한 idx값이 한개 남았을때
		if (resti == 1) {
			for (y = 0; y < ROW_LEN; y++) {
				if (yarr[y] != (-1))
					yidx = yarr[y];
			}
			for (x = 0; x < LINE_LEN; x++) {
				if (xarr[x] != (-1))
					xidx = xarr[x];
			}
			arr[yidx][xidx].firmedElement = (i+1);
			*totalCount -= 1;
		}
	}
}



/********************(ver 2.0 추가 함수)*************************/

/* int ReadProblem(Element (*) [LINE_LEN], int *)
 * quiz.txt 파일에서 문제를 읽어오는 함수
 * Parameter	: 게임 판의 첫번째 주소값, 풀리지 않은 문제 수를 담는 변수의 주소값
 * Return type	: 정상적으로 파일 읽기에 성공시 0 반환, 실패시 -1 반환
 * Reference	: 함수 내에서 BoardInit()함수 호출, CandidateRefresh()함수 호출
 */
int ReadQuizFile(Element (*arr) [LINE_LEN], int * totalCount)
{
	FILE*fp = fopen("quiz.txt", "rt");	
	int ypos, xpos;
	int cy, cx;
	int i;

	if (fp == NULL) {
		printf("읽어들일 파일이 없습니다.\n");
		return -1;
	}

	//판 초기화 함수 호출
	BoardInit(arr);
	
	//판에 내용 입력 시작(312 ~ 349)
	for (ypos = 0; ypos < ROW_LEN; ypos++)	{
		for (xpos = 0; xpos < LINE_LEN; xpos++) {
			i = 1;
			arr[ypos][xpos].firmedElement = fgetc(fp);
			arr[ypos][xpos].firmedElement -= '0';

			//파일에서 읽어들인 수가 0일때(빈칸일때)
			if (arr[ypos][xpos].firmedElement == 0)	{
				for (cy = 0; cy < 3; cy++) {
					for (cx = 0; cx < 3; cx++) {
						arr[ypos][xpos].candidate[cy][cx] = i;
						i++;
					}
				}
				arr[ypos][xpos].restCandidate = 9;
				*totalCount += 1;
			}

			//파일에서 읽어들인 수가 0이 아닐때(주어진 수일떄)
			else	{
				for (cy = 0; cy < 3; cy++) {
					for (cx = 0; cx < 3; cx++) {
						if (i == arr[ypos][xpos].firmedElement)
							arr[ypos][xpos].candidate[cy][cx] = i;
						else
							arr[ypos][xpos].candidate[cy][cx] = 0;
						i++;
					}
				}
				arr[ypos][xpos].restCandidate = 1;
			}
		}
	}

	fclose(fp);

	//판 새로고침 함수 호출
	CandidateRefresh(arr);	
	return 0;
}
	
/* void BoardInit(Element (*)[LINE_LEN])
 * 9x9 스도쿠 게임판을 초기화하는 함수
 * Parameter	: Element * 형 변수(게임 판의 첫번째 주소)
 * Return type	: void
 */
void BoardInit(Element (*arr) [LINE_LEN])
{
	int ypos, xpos, cy, cx;

	for (ypos = 0; ypos < ROW_LEN; ypos++) {
		for (xpos = 0; xpos < LINE_LEN; xpos++) {
			arr[ypos][xpos].firmedElement = 0;
			arr[ypos][xpos].restCandidate = 9;
			for (cy = 0; cy < 3; cy++) {
				for (cx = 0;cx < 3; cx++) {
					arr[ypos][xpos].candidate[cy][cx] = 0;
				}
			}
		}
	}
}

/* void CandidateRefresh(Element (*)[LINE_LEN)
 * 현재 판 상황에 맞춰서 구조체 변수의 멤버 후보자 수 새로고침
 * Parameter	: 게임 판의 첫번째 주소
 * Return type	: void
 */
void CandidateRefresh(Element (*arr) [LINE_LEN])
{
	int ypos, xpos;

	for (ypos = 0; ypos < ROW_LEN; ypos++) {
		for (xpos = 0; xpos < LINE_LEN; xpos++) {
			if (arr[ypos][xpos].firmedElement == 0)
				continue;
			else {
				//해당 열의 candidate에 있는 실값 제거+ restcandidate-=1
				//해당 행의 candidate에 있는 실값 제거+ restcandidate-=1
				//해당 3x3의 candidate에 있는 실값 제거+ restcandidate-=1
			}
		}
	}
}

