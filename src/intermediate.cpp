#include <iostream>
#include <string>

using namespace std ;

// for using chap.074
void Func(int arg)
{
	cout << "변경 전: " << arg << endl ;
	arg += 10 ;
	cout << "변경 후: " << arg << endl ;
}

// for using chap.075
// &: 해당 변수의 주소를 가져옴. 즉, 주소의 값을 직접 바꿈.
void Func1(int &arg)
{
	cout << "변경 전: " << arg << endl ;
	arg += 10 ;
	cout << "변경 후: " << arg << endl ;
}
// for using chap.075
void Func2(string &info)
{
	info += "981년" ;
}

// for using chap.076
// 함수 인자로 포인터를 받으며, 함수 호출 시 주소를 명시적으로 전달하기 때문에 포인터의 크기로 인자가 전달됨.
void Func3(bool *isOn)
{
	cout << "Call by Address: " << sizeof(isOn) << endl ;
}
// for using chap.076
// 함수 인자로 주소를 받지만 실제 Func4에서는 포인터로 받음. 함수 호출 시 값을 그대로 넘기기 때문에 해당 자료형의 크기로 넘어감.
void Func4(bool &isOn)
{
	cout << "Call by Reference: " << sizeof(isOn) << endl ;
}

// for using chap.079
// 상수 집합인 열거형 enum
enum Status
{
	// 값을 설정하지 않으면 0부터 자동할당되며, 각 요소값은 이전 요소값보다 자동으로 1이 커져서 할당
	// 여기서, abnormal = 1, closoe = 101이 할당됨
	normal = 0,
	abnormal,
	disconnect = 100,
	close
} ;

// for using chap.080
// enum class의 자료형을 char 형태로 정의 (자료형 명시하지 않으면 기본적으로 int형태로 사용. enum은 int/char형 가능)
enum class MachineStatus : char
{
	normal = 'n',
	abnormal,
	disconnect = 100,
	close
} ;

int main()
{
	/*
	// 074 - Call by Value 이해하기
	int year = 10 ;
	Func(year) ;
	cout << "함수 종료 후: " << year << endl ;
	*/
	
	/*
	// 075 - Call by Reference 이해하기
	int year = 10 ;
	Func1(year) ;
	cout << "Func1 함수 종료 후: " << year << endl ;
	
	string kingInfo = "고려 성종 즉위년: " ;
	Func2(kingInfo) ;
	cout << kingInfo << endl ;
	*/
	
	/*
	// 076 - Call by Address 이해하기
	bool isTmp = true ;
	Func3(&isTmp) ;
	Func4(isTmp) ;
	*/
	
	/*
	// 078 - const 포인터 이해하기 ***
	int number1 = 10 ;
	int number2 = 20 ;
	cout << "number1: " << number1 << endl ;
	cout << "number2: " << number2 << endl ;
	
	// const int를 가리키는 포인터.
	int const *ptr1 ;
	ptr1 = &number1 ;
	cout << "ptr1: " << ptr1 << endl ;
	cout << "*ptr1: " << *ptr1 << endl ;
	// const int이기 때문에 값을 바꿀 수 없음
	// ptr1 = number1 ;
	ptr1 = &number2 ;
	cout << "ptr1: " << ptr1 << endl ;
	cout << "*ptr1: " << *ptr1 << endl ;	
	
	// int를 가리키는 const 포인터로써 int number1의 주소를 할당받은 후 변경불가.
	int *const ptr2 = &number1 ;
	cout << "ptr2: " << ptr2 << endl ;
	cout << "*ptr2: " << *ptr2 << endl ;
	// 할당받은 int number1의 주소에 해당하는 값을 number2 값으로 변경.
	*ptr2 = number2 ;	
	// *ptr2 = &number2 ;
	cout << "ptr2: " << ptr2 << endl ;
	cout << "*ptr2: " << *ptr2 << endl ;
	// 최종 확인
	cout << "number1: " << number1 << endl ;
	cout << "number2: " << number2 << endl ;
	*/
	
	/*
	// 079 - enum 이해하기
	Status number = close ; 
	
	// Status는 클래스 or namespace가 아니기 때문에 아래와 같이 사용하면 안된다.
	// if(number == Status::normal)
	if(number == normal)
		cout << "Status: normal" << endl ;
	else if(number == abnormal)
		cout << "Status: abnormal" << endl ;
	else if(number == 101)
		cout << "Status: disconnect" << endl ;
	else
		cout << "Status: close" << endl ;
	*/
	
	
	
	// 080 - enum class 이해하기
	// 아래 소스 컴파일 시 'MachineStatus' is not a class or namespace 라는 컴파일 에러가 발생한다.
	// 이를 해결하기 위해 g++ 옵션에 "-std=c++11"를 추가하여야 함 (gcc가 5.x버전 이하라면 추가하여야 함 - scoped enums는 c++11에 추가되었음.)
	// 출처: https://stackoverflow.com/a/45201081/10521400
	/*
		root@goorm:/workspace/Study(master)# g++ --version
		g++ (Ubuntu 5.5.0-12ubuntu1~14.04) 5.5.0 20171010
		-> 5.5 버전이구나~
	*/
	// goorm의 빌드/실행 옵션 문제인거 같은데...아무리 찾아보아도 모르겠음
	// 실행script를 짜버림;;
	// root@goorm:/workspace/Study(master)# g++ -std=c++11 /workspace/Study/src/intermediate.cpp -o /tmp/a.out && /tmp/a.out
	MachineStatus machine = MachineStatus::abnormal ;
	
	if(machine == MachineStatus::normal)
		cout << "Status: normal" << endl ;
	else if(machine == MachineStatus::abnormal)
		cout << "Status: abnormal" << endl ;
	else if(machine == MachineStatus::disconnect)
		cout << "Status: disconnect" << endl ;
	else
		cout << "Status: close" << endl ;
	
	cout << "machine: " << static_cast<int>(machine) << ", " << static_cast<char>(machine) << endl ;
	
	
	
	return 0 ;
}