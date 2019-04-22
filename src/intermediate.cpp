#include <iostream>
#include <string>
#include <vector>	// for using chap.086
#include <regex>

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

// for using chap.085
void Func085_1(int arr[2][2])
{
	// 2차원배열을 인자로 전달받아 Func085_1 내부적으로 0x0 에 값을 1000으로 변경함
	// main 함수로 돌아갈 때는 값 변화 없음.
	// => 헐. 값이 바뀌네요... -_-;; 배열을 인자로 받으며 실제 그 값을 변경 가능함..
	arr[0][0] = 1000 ;
}

// for using chap.085
void Func085_2 (int arr[][2], int row)
{
	// [row-2][1] 위치의 값을 2000으로 변경한다....
	arr[row-2][1] = 2000 ;
}

// for using chap.085
void Func085_3 (int *arr, int row, int col)
{
	// arr[0][0]에서 행/열 각각 1 / 1 씩 이동한 위치.. 즉 arr[1][1]의 값을 3000으로 변경함.
	*((arr + row - 1) + col - 1) = 3000 ;
}

// for using chap.088
struct Princess
{
	string name ;
	string father ;
	string birthday = "알 수 없음" ;
} Goryeo[2] ;	// 구조체 배열

// for using chap.089
struct Pricess2
{
	string name ;
	string father ;
	string birthday ;
} jungseo ;

// for using chap.089
// -> 책에서는... "구조체는 일반 변수처럼 다뤄지기 때문에 주소 번지 지정자 &를 사용하여 넘기고 받는 함수는 &를 이용합니다. 포인터이기 때문에 . 대신  -> 를 사용합니다."..
//    라고 하는데... 그냥 구조체를 넘겨도 값 출력 되는데..? 왜 &를 통해서 주고 받도록 했지..? -_-;;
void Print(Pricess2 who)
// void Print(Pricess2 *who)
{
	cout << "jungseo.name: " << who.name << endl ;
	cout << "jungseo.father: " << who.father << endl ;
	cout << "jungseo.birthday: " << who.birthday << endl ;
	// cout << "jungseo.name: " << who->name << endl ;
	// cout << "jungseo.father: " << who->father << endl ;
	// cout << "jungseo.birthday: " << who->birthday << endl ;
}

// for using chap.090
struct Data1
{
	Data1(int x) : number(x) {}
	int number ;
} ;

// for using chap.090
struct Data2
{
	Data2()
	{
		number = 10 ;
	}
	int number ;
} data2 ;

// for using chap.091
struct Data091_1
{
	int number ;
} ;

// for using chap.091
struct Data091_2
{
	Data091_1 data091_1 ;
	int number ;
} ;

// for using chap.092
struct Info{
	string country ;
	
	struct Who
	{
		string name ;
		string nickname ;
	} who ;
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
	
	
	/*	
	// 080 - enum class 이해하기
	// 아래 소스 컴파일 시 'MachineStatus' is not a class or namespace 라는 컴파일 에러가 발생한다.
	// 이를 해결하기 위해 g++ 옵션에 "-std=c++11"를 추가하여야 함 (gcc가 5.x버전 이하라면 추가하여야 함 - scoped enums는 c++11에 추가되었음.)
	// 출처: https://stackoverflow.com/a/45201081/10521400
		// root@goorm:/workspace/Study(master)# g++ --version
		// g++ (Ubuntu 5.5.0-12ubuntu1~14.04) 5.5.0 20171010
		// -> 5.5 버전이구나~
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
	*/	
	
	
	// // 084 - 2차원 배열 사용하기
	// int data1[2][2] = { 1, 2, 3 } ;		// 2x2 배열 선언. 1, 2, 3, 0 으로 초기화
	// int data2[2][3] = { {1, } } ;		// 2x3 배열 선언. 1, 0, 0, 0, 0, 0 으로 초기화
	
	// cout << "data1[0][0] = " << data1[0][0] << endl ;
	// cout << "data1[0][1] = " << data1[0][1] << endl ;
	// cout << "data1[1][0] = " << data1[1][0] << endl ;
	// cout << "data1[1][1] = " << data1[1][1] << endl ;
	// cout << endl ;
	// cout << "data2[0][0] = " << data2[0][0] << endl ;
	// cout << "data2[0][1] = " << data2[0][1]+1 << endl ;	// 값에 1을 더함
	// cout << "data2[0][2] = " << data2[0][2]+2 << endl ;	// 값에 2를 더함
	// cout << "data2[1][0] = " << data2[1][0]+3 << endl ;	// 값에 3을 더함
	// cout << "data2[1][1] = " << data2[1][1]+4 << endl ;	// 값에 4를 더함
	// cout << "data2[1][2] = " << data2[1][2]+5 << endl ;	// 값에 5를 더함
	
	
	// // 085 - 2차원 배열 함수 인자 사용하기
	// int data[2][2] = { {1, 2}, {3, 4} } ;
	
	// Func085_1(data) ;
	// Func085_2(data, 2) ;
	// Func085_3(*data, 2, 2) ;
	
	// cout << "=== 결과 ===" << endl ;
	// for(int i=0; i<2; i++)
	// {
	// 	for(int j=0; j<2; j++)
	// 	{
	// 		cout << data[i][j] << endl ;
	// 	}
	// }
	
	
	// // 086 - 배열 일부 변경하기(fill: 시작위치~마지막위치까지, 수정값으로 대체)
	// int data1[10] = { 0, } ;
	// fill(data1, data1+3, 10) ;
	// fill(data1+4, data1+8, 20) ;
	
	// cout << "=== data1 결과 ===" << endl ;
	
	// // 1차원 배열의 갯수를 구하려면.. 1) 해당 배열사이즈 확인 (byte로 계산됨) 2) 배열 type으로 나눔 (byte로 계산된 값을 type으로 나눠 갯수를 확인)
	// for(int i=0; i<sizeof(data1)/sizeof(int); i++)
	// 	cout << data1[i] << ", " ;
	
	// vector<int> data2({0, 1, 2, 3, 4, 5, 6, 7}) ;
	// fill(data2.begin(), data2.begin()+3, 30) ;
	// cout << endl << endl << "data2.size: " << data2.size() << endl << "=== data2 결과 ===" << endl ;
	
	// for(int i=0, size=data2.size(); i<size; i++)
	// 	cout << data2.at(i) << ", ";
	// cout << endl ;
	
	
	// // 087 - 배열 일부 변경하기(fill_n: 시작위치~변경할 갯수, 수정할 값으로 대체. fill과의 차이점은 마지막위치가 아닌 변경할 갯수를 받는다는 것.)
	// int data1[10] = { 0, } ;
	// fill_n(data1, 2, 10) ;
	// fill_n(data1+4, 3, 20) ;
	
	// cout << "=== data1 결과 ===" << endl ;
	
	// for(int i=0; i<sizeof(data1)/sizeof(int); i++)
	// 	cout << data1[i] << ", " ;
	
	// vector<int> data2({0, 1, 2, 3, 4, 5, 6, 7}) ;
	// fill_n(data2.begin(), data2.size()-1, 30) ;
	// fill_n(data2.begin(), 4, 40) ;
	// cout << endl << endl << "data2.size: " << data2.size() << endl << "=== data2 결과 ===" << endl ;
	
	// for(int i=0, size=data2.size(); i<size; i++)
	// 	cout << data2.at(i) << ", " ;
	// cout << endl ;
	
	
	// // 088 - 구조체 사용하기(struct)
	// Princess jungmyung ;
	// jungmyung.name = "정명공주" ;
	// jungmyung.father = "조선 선조" ;
	// jungmyung.birthday = "1603년 6월 27일" ;
	
	// Goryeo[0].name = "선정왕후" ;
	// Goryeo[0].father = "고려 성종" ;
	// Goryeo[1].name = "효정공주" ;
	// Goryeo[1].father = "고려 현종" ;
	
	// cout << "=== 조선 공주 ===" << endl ;
	// cout << jungmyung.name << endl ;
	// cout << jungmyung.father << endl ;
	// cout << jungmyung.birthday << endl ;
	
	// cout << "=== 고려 공주 ===" << endl ;
	// cout << Goryeo[0].name << endl ;
	// cout << Goryeo[0].father << endl ;
	// cout << Goryeo[0].birthday << endl << endl ;
	// cout << Goryeo[1].name << endl ;
	// cout << Goryeo[1].father << endl ;
	// cout << Goryeo[1].birthday << endl ;
	
	
	// // 089 - 구조체를 함수 인자로 사용하기
	// jungseo.name = "정소공주" ;
	// jungseo.father = "조선 태종" ;
	// jungseo.birthday = "1412년" ;
	
	// // 왜 구조체 주소를 인자로 넘기게 할까? 출력이면.. 그냥 구조체 자체를 넘겨도 되지 않나?
	// Print(jungseo) ;
	// // Print(&jungseo) ;
	
	
	// // 090 - 구조체 초기화하는 방법1
	// Data1 data1(2) ;
	// cout << "Data1 number: " << data1.number << endl ;
	// cout << "Data2 number: " << data2.number << endl ;
	
	
	// // 091 - 구조체 초기화하는 방법2
	// Data091_1 data091_1 = {} ;	// 구조체 내부 변수 모두를 초기화함. "int = 0"
	// Data091_2 data091_2 {data091_1, 10 } ;	// 구조체 내부 변수 Data091_1, int 를 순서에 맞게 초기화함.
	
	// cout << "Data091_1 number: " << data091_2.data091_1.number << endl ;
	// cout << "Data091_2 number: " << data091_2.number << endl ;
	
	
	// 092 - 구조체 초기화하는 방법3
	Info chuck = {"고려", {"장군 척준경", "소드마스터"}} ;
	Info anjang = {"고구려", "안장왕 고흥왕", "한주 사랑"} ;
	
	cout << chuck.country << ", " << chuck.who.name << ", " << chuck.who.nickname << endl ;
	cout << anjang.country << ", " << anjang.who.name << ", " << anjang.who.nickname << endl ;
	

	
	
	
	
	
	
	return 0 ;
}