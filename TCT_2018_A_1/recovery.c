#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "recovery.h"

/**
 * 데이터 1차 복원 기능
 *
 * @param[out]	firstRecovery	1차 복원된 데이터
 * @param[in]	inputData		입력데이터(원본 데이터)
 * @param[in]	backup			입력데이터(백업 데이터)
 */
void getFirstRecovery(char firstRecovery[MAX_DATA_LENGTH], char inputData[MAX_DATA_LENGTH], char backup[MAX_DATA_LENGTH]) {

	memset(firstRecovery, 0, sizeof(char) * MAX_DATA_LENGTH);
	memcpy(firstRecovery, inputData, sizeof(char) * MAX_DATA_LENGTH);

	for(int i=0; i<strlen(firstRecovery); i++) {
		if(isdigit(firstRecovery[i]) && isalpha(backup[i])){
			firstRecovery[i] = backup[i];
		}
	}

}

/**
 * 데이터 2차 복원 기능
 *
 * @param[out]	secondRecovery	2차 복원된 데이터
 * @param[in]	firstRecovery	1차 복원된 데이터
 * @param[in]	netWork			입력데이터(네트워크에 저장된 데이터)
 * @param[in]	netWorkCnt		네트워크에 저장된 데이터 개수
 */
void getSecondRecovery(char secondRecovery[MAX_DATA_LENGTH], char firstRecovery[MAX_DATA_LENGTH], char netWork[NETWORK_DATA_SIZE][NETWORK_DATA_LENGTH], int netWorkCnt) {

	memset(secondRecovery, 0, sizeof(char) * MAX_DATA_LENGTH);

	char tmpNetWork[MAX_DATA_LENGTH];
	memset(tmpNetWork, 0, sizeof(char) * MAX_DATA_LENGTH);
	for(int i=0; i<netWorkCnt; i++)	{
		strcat(tmpNetWork, netWork[i]);
	}

	getFirstRecovery(secondRecovery, firstRecovery, tmpNetWork);

}
