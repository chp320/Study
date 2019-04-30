#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recovery.h"

void loadData();
void printLine();
void printFirstRecovery();
void printSecondRecovery();

char inputData[MAX_DATA_LENGTH];	//입력데이터(원본 데이터)
char backup[MAX_DATA_LENGTH];	//입력데이터(벡업 데이터)
char netWork[NETWORK_DATA_SIZE][NETWORK_DATA_LENGTH];	//입력데이터(네트워크에 저장된 데이터)
int netWorkCnt;	//네트워크에 저장된 데이터 개수

char firstRecovery[MAX_DATA_LENGTH];	//1차 복원된 데이터
char secondRecovery[MAX_DATA_LENGTH];	//2차 복원된 데이터

int main(void) {

	//제공 데이터 세트2를 실행하려면 loadData에서 제공 데이터 세트1을 주석 처리하고 제공 데이터 세트2를 주석 해제하여 실행

	//데이터 읽어오는 기능
	loadData();

	//////////////////////////
	// 1. 데이터 1차 복원 기능
	//////////////////////////

	getFirstRecovery(firstRecovery, inputData, backup);
	printFirstRecovery();


	//////////////////////////
	// 2. 데이터 2차 복원 기능
	//////////////////////////

	getSecondRecovery(secondRecovery, firstRecovery, netWork, netWorkCnt);
	printSecondRecovery();


	return 0;

}


void loadData() {

	memset(inputData, 0, sizeof(inputData));
	memset(backup, 0, sizeof(backup));
	memset(netWork, 0, sizeof(netWork));

	//////////////////////////
	// 제공 데이터 세트 1
	//////////////////////////

	/*char initInputData[MAX_DATA_LENGTH] = "we1re3hewo34ddre67com21rue";
	char initBackup[MAX_DATA_LENGTH] = "1eare4hewor5dd8eamcome3rue";
	char initNetWork[NETWORK_DATA_SIZE][NETWORK_DATA_LENGTH] = {
			"wear",
			"ethe",
			"worl",
			"ddre",
			"amco",
			"metr",
			"ue"
	};

	netWorkCnt = 7;*/


	//////////////////////////
	// 제공 데이터 세트 2
	//////////////////////////

	char initInputData[MAX_DATA_LENGTH] = "ote12lkja23dhbgfl1ejkhf3uhe";
	char initBackup[MAX_DATA_LENGTH] = "otek3lkjaopdhbgfl1ejkhf1uhe";
	char initNetWork[NETWORK_DATA_SIZE][NETWORK_DATA_LENGTH] = {
			"otek",
			"plkj",
			"aopd",
			"hbgf",
			"lkej",
			"khft",
			"uhe"
	};

	netWorkCnt = 7;


	memcpy(inputData, initInputData, sizeof(initInputData));
	memcpy(backup, initBackup, sizeof(initBackup));
	memcpy(netWork, initNetWork, sizeof(initNetWork));


}

void printLine() {
	printf("-----------------------------------------------------\n");
}

void printFirstRecovery() {
	printf("[1차 복원된 데이터]\n");
	printf("입력: %s\n", inputData);
	printf("출력: ");
	if(strlen(firstRecovery) == 0) {
		printf("결과값이 없습니다.\n");
	} else {
		printf("%s\n", firstRecovery);
	}
	printLine();
}

void printSecondRecovery() {
	printf("[2차 복원된 데이터]\n");
	printf("입력: ");
	if(strlen(firstRecovery) == 0) {
		printf("입력값이 없습니다.\n");
	} else {
		printf("%s\n", firstRecovery);
	}
	printf("출력: ");
	if(strlen(secondRecovery) == 0) {
		printf("결과값이 없습니다.\n");
	} else {
		printf("%s\n", secondRecovery);
	}
	printLine();
}
