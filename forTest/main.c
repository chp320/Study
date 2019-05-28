#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
3. 배열 계산
아래와 같은 문자열이 주어질 때 10의 자리의 수를 배열 첫열에 넣고 1의 자리는 옆의 열에 순서대로 채운다. 이중 10의 자리가 가장 많은 수를 찾고(1), 배열의 좌/우를 뒤집는다.(2)
문자열 : 55#56#57#66#62#73#77#78#79#91
배열 : 
5  5  6  7  -1
6  6  2 -1  -1
7  3  7  8   9
9  1  -1  -1  -1
(1) 10의 자리가 가장 많은 수 7
 => 5는 3개, 6은 2개, 7은 4개, 9는 1개
(2) 
-1  7  6  5  5
-1 -1  2  6  6
 9  8   7  3  7
-1 -1 -1  1  9
*/
int setColumn(int arrRslt[][5], int nRow, int nCol, int nVlue) ;
int main(void)
{
	int arrRslt[4][5] = {0, } ;	// 결과저장용 4x5 배열
	memset(arrRslt, -1, sizeof(arrRslt)) ;	// 배열값을 모두 -1로 초기화
	// for(int i=0; i<4; i++)
	// {
	// 	for(int j=0; j<5; j++)
	// 	{
	// 		printf("%d ", arrRslt[i][j]) ;
	// 	}
	// }
	// printf("\n") ;
	
	int arrHist[8] = {0, } ; // 십의자리 발생이력 관리 (arrHist[0]=1, arrHist[1]=2, .., arrHist[8]=9)
	// for(int i=0; i<8; i++)
	// {
	// 	printf("%d ", arrHist[i]) ;
	// }
	// printf("\n") ;
	
	// 주어진 예시 문자열
	char str1[] = "55#56#57#66#62#73#77#78#79#91" ;
	// strtok함수를 사용하여 #를 구분자로 자른다.
	char* tok1 = strtok(str1, "#") ;
	int nRow = -1 ;	// 기록되어야 할 행의 위치
	int nCol = 0 ;	// 기록되어야 할 열의 위치
	while(tok1 != NULL)
	{
		printf("%s", tok1) ;
		// 각 자리수 분리
		printf("(%d),(%d) ", atoi(tok1)/10, atoi(tok1)%10) ;
		// 십의자리수가 이전에 나왔었는지 확인
		if(arrHist[(atoi(tok1)/10)-1] == (atoi(tok1)/10))
		{
			printf("이미 존재! (%d) \n", atoi(tok1)/10) ;
			// 현재 nRow 의 행에서 값을 입력, 입력값은 일의자리수(atoi(tok1)%10)
			nCol = nCol +1 ;
			setColumn(arrRslt, nRow, nCol, atoi(tok1)%10) ;
		}
		else
		{
			printf("존재하지 않음! (%d) \n", atoi(tok1)/10) ;
			// 발생이력배열에 값을 기록
			arrHist[(atoi(tok1)/10)-1] = (atoi(tok1)/10) ;
			// printf("nRow(%d), nCol(%d) \n", nRow, nCol) ;
			// 현재 nRow 의 값을 1 증가시켜(다음 행에서) 값을 입력, 처음 입력되는 것이므로 열의 위치는 0으로 설정, 입력값은 십의자리수(atoi(tok1)/10)
			nRow = nRow + 1 ;
			nCol = 0 ;
			setColumn(arrRslt, nRow, nCol, atoi(tok1)/10) ;
			nCol = nCol + 1 ;
			setColumn(arrRslt, nRow, nCol, atoi(tok1)%10) ;
		}
		tok1 = strtok(NULL, "#") ;
	}
	
	// 숫자이력
	// for(int i=0; i<9; i++)
	// {
	// 	printf("%d ", arrHist[i]) ;
	// }
	// printf("\n") ;

	for(int i=0; i<4; i++)
	{
		for(int j=0; j<5; j++)
		{
			printf("%d ", arrRslt[i][j]) ;
		}
		printf("\n") ;
	}
	printf("\n") ;
}

int setColumn(int arrRslt[][5], int nRow, int nCol, int nVlue)
{
	printf("setColumn =====> nRow(%d), nCol(%d), nVlue(%d) \n", nRow, nCol, nVlue) ;
	arrRslt[nRow][nCol] = nVlue ;
	printf("==> (%d) \n", arrRslt[nRow][nCol]) ;
	
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<5; j++)
		{
			printf("%d ", arrRslt[i][j]) ;
		}
	}
	printf("\n") ;
}