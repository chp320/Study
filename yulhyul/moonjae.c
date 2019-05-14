#include <stdio.h>
/* 연습문제 16-1 */
// int main()
// {
// 	int nArray[3][9] = {0, } ;
// 	for(int i=0; i<3; i++)
// 	{
// 		for(int j=0; j<9; j++)
// 		{
// 			nArray[i][j] = (i+2) * (j+1) ;
// 		}
// 	}
// 	for(int i=0; i<3; i++)
// 	{
// 		for(int j=0; j<9; j++)
// 		{
// 			printf("%d ", nArray[i][j]) ;
// 		}
// 		printf("\n") ;
// 	}
// }

/* 연습문제 16-2 */
// 2x4 -> 4x2 로 변경
// int main()
// {
// 	// 2x4배열 선언/초기화
// 	int array1[2][4] = { {1, 2, 3, 4}, {5, 6, 7, 8} } ;
// 	int array2[4][2] ;
	
// 	for(int i=0; i<4; i++)
// 	{
// 		for(int j=0; j<2; j++)
// 		{
// 			if(i==j)
// 			{
// 				array2[i][j] = array1[i][j] ;
// 			}
// 			else
// 			{
// 				array2[i][j] = array1[j][i] ;
// 			}
// 		}
// 	}
// 		for(int i=0; i<4; i++)
// 	{
// 		for(int j=0; j<2; j++)
// 		{
// 			printf("%d ", array2[i][j]) ;
// 		}
// 		printf("\n") ;
// 	}
// }

/* 연습문제 16-3 */
// int main()
// {
// 	int nScore[5][5] = {0, } ;
	
// 	// 학생별 과목별 점수 입력
// 	for(int i=0; i<4; i++)
// 	{
// 		for(int j=0; j<4; j++)
// 		{
// 			scanf("%d", &nScore[i][j]) ;
// 		}
// 	}
	
// 	// 학생별 총점 입력
// 	for(int i=0; i<4; i++)
// 	{
// 		// 학생별 총점
// 		int sumA = 0 ;
// 		for(int j=0; j<4; j++)
// 		{
// 			sumA += nScore[i][j] ;
// 		}
// 		nScore[i][4] = sumA ;
// 	}
	
// 	// 과목별 총점 입력
// 	for(int j=0; j<4; j++)
// 	{
// 		// 과목별 총점
// 		int sumB = 0 ;
// 		for(int i=0; i<4; i++)
// 		{
// 			sumB += nScore[i][j] ;
// 		}
// 		nScore[4][j] = sumB ;
// 	}
	
// 	// 전체 출력
// 	for(int i=0; i<5; i++)
// 	{
// 		for(int j=0; j<5; j++)
// 		{
// 			printf("%d ", nScore[i][j]) ;
// 		}
// 		printf("\n") ;
// 	}
// }