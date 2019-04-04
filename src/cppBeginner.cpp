#include <iostream>
#include <string>
// chap.063 atoi() 사용하기 위해 include
#include <stdlib.h>
// chap.065 sort() 사용하기 위해 include
#include <algorithm>
// chap.070 vector 사용하기 위해 include
#include <vector>

using namespace std ;

// for using chap.070
int ptrFunc(vector<string> *info)
{
	if(info->empty() == true)
		return 0 ;
	else
		return sizeof(info) ;
}

// for using chap.072
int temp1(const int arg)
{
	int number = 20 ;
	return number + 1 ;
}
// for using chap.072
int temp2(const int arg)
{
	int number = arg ;
	return number + 1 ;
}

// for using chap.073
extern int g_number = 100 ;
// for using chap.073
int func1()
{
	return g_number++ ;
}
// for using chap.074
int func2()
{
	return g_number++ ;
}



int main()
{
	/*
	// 054
	string strBaekhap = "백합벌 전투 : 백제 왕자 부여창의 일기토로 유명한 전투" ;
	int rtn = strBaekhap.find("부여창") ;
	
	if(rtn > 0)
		cout << "문자열을 찾았습니다. 위치는 " << rtn << "입니다. " << endl ;
	else
		cout << "문자열을 찾을 수 없습니다." << endl ;
	*/
	
	/*
	// 063
	string str1 = "10" ;
	string str2 = "2.456" ;
	string str3 = "456 문자열" ;
	
	// atoi()를 사용하기 위해서는 인자가 char* 타입으로 전달되어야 한다 (C언어 스타일, c++에서는 char* 사용을 지양하고 있기 때문에 warning 발생)
	char* str1 = "10" ;
	char* str2 = "2.456" ;
	char* str3 = "456 문자열" ;
	
	// int num1 = stoi(str1) ;
	// int num2 = stoi(str2) ;
	// int num3 = stoi(str3) ;
	
	int num1 = atoi(str1) ;
	int num2 = atoi(str2) ;
	int num3 = atoi(str3) ;
	
	// int num1 = atoi("10") ;
	// int num2 = atoi("2.456") ;
	// int num3 = atoi("456 문자열") ;
	
	cout << num1 << ", " << num2 << ", " << num3 << endl ;
	*/
	
	/*
	// 065
	string str1 = "gojoseon" ;
	string str2 = "AaBbCcDdEe" ;
	
	sort(str1.begin(), str1.end()) ;
	sort(str2.begin(), str2.end()) ;
	
	cout << "소문자만 정렬: " << str1 << endl ;
	cout << "대소문자만 정렬: " << str2 << endl ;
	*/
	
	/*
	// 068
	int result1 = min(1, 5) ;
	char result2 = max('a', 'z') ;
	cout << result1 << ", " << result2 << endl ;
	
	// minmax()는 못쓰는 걸로..;;
	int arr1[3] = { 1, 2, 3 } ;
	char arr2[3] = { 'a', 'n', 'z' } ;
	// int result3 = minmax({ 1, 2, 3 }) ;
	// char result4 = minmax({ 'a', 'n', 'z'}) ;	
	// cout << result3.first << ", " << result3.second << endl ;
	// cout << result4.first << ", " << result4.second << endl ;
	*/
	
	/*
	// 069 - 포인터 이해하기
	int num1 = 10 ;
	int *ptr1 = &num1 ;
	// int *ptr1 = num1 ;
	
	double num2 = 23.4 ;
	double *ptr2 = &num2 ;
	
	cout << "num1: " << num1 << " (size: " << sizeof(num1) << ")" << endl ;
	cout << "ptr1: " << ptr1 << " (size: " << sizeof(ptr1) << ")" << endl ;
	
	cout << "num2: " << num2 << " (size: " << sizeof(num2) << ")" << endl ;
	cout << "ptr2: " << ptr2 << " (size: " << sizeof(ptr2) << ")" << endl ;
	*/
	
	/*
	// 070 - 포인터 변수 사용하기
	vector<string> message ;
	message.push_back("고려 장군") ;
	message.push_back("척준경!") ;
	message.push_back("절친 이름은") ;
	message.push_back("... 무엇일까") ;
	
	cout << "포인터 인자 크기: " << ptrFunc(&message) << endl ;
	cout << "원래 변수 크기: " << sizeof(message) << endl ;
	
	// for test
	message.clear() ;	// vector내 데이터 초기화
	cout << "포인터 인자 크기: " << ptrFunc(&message) << endl ;
	cout << "원래 변수 크기: " << sizeof(message) << endl ;
	*/
	
	/*
	// 071 - 포인터 배열 사용하기
	const int kSize = 3 ;
	
	int numbers[kSize] = { 10, 20, 30 } ;
	int *ptr1 = numbers ;	// numbers[0]의 위치임.
	// 왜 이것은 안될까?? -_-;;
	// int *ptr1 = &numbers ;
	
	int no1 = 1 ;
	int no2 = 2 ;
	int no3 = 3 ;
	int *ptr2[kSize] = { &no1, &no2, &no3 } ;	// 포인터 배열 선언&초기화. 각 변수의 주소를 저장
	
	for(int i=0; i<kSize; i++)
		cout << "ptr1[" << i << "] = " << *(ptr1 + i) << endl ;	// ptr1은 numbers[0]을 가리키며 해당 위치의 실제값 표현을 위해 * 사용
	
	for(int i=0; i<kSize; i++)
		cout << "ptr2[" << i << "] = " << *ptr2[i] << endl ;
	*/
	
	/*
	// 072 - 지역 변수 이해하기
	int number = 10 ;
	
	int rtn1 = temp1(number) ;
	int rtn2 = temp2(number) ;
	cout << "메인함수 number: " << number << endl ;
	cout << "temp함수 number: " << rtn1 << endl ;
	cout << "temp함수 number: " << rtn2 << endl ;
	*/
	
	
	// 073 - 전역 변수 이해하기 (extern) : c++에서는 extern에 대해 warning. 쓰지말자.
	int number = g_number++ ;
	cout << "메인 number: " << number << endl ;
	cout << "func1 number: " << func1() << endl ;
	cout << "func2 number: " << func2() << endl ;
	
	return 0 ;
}