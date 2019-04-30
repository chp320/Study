#ifndef _RECOVERY_H_
#define _RECOVERY_H_

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_DATA_LENGTH 50	//최대 데이터 길이
#define NETWORK_DATA_SIZE 20	//네트워크에 저장된 데이터 개수
#define NETWORK_DATA_LENGTH 5	//네트워크에 저장된 데이터 길이

void getFirstRecovery(char firstRecovery[MAX_DATA_LENGTH], char inputData[MAX_DATA_LENGTH], char backup[MAX_DATA_LENGTH]);
void getSecondRecovery(char secondRecovery[MAX_DATA_LENGTH], char firstRecovery[MAX_DATA_LENGTH], char netWork[NETWORK_DATA_SIZE][NETWORK_DATA_LENGTH], int netWorkCnt);

#ifdef __cplusplus
}
#endif

#endif
