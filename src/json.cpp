#include <iostream>
#include <regex>
#include <string>

using namespace std ;

/*
	[즉시수행]
	root@goorm:/workspace/Study(master)# g++ -std=c++11 /workspace/Study/src/json.cpp -o /tmp/a.out && /tmp/a.out
*/

int main()
{
	regex re1(R"(\d+)") ;
	string str1("1234") ;
	
	bool is_match = regex_match(str1, re1) ;
	// bool타입의 is_match 값 출력 시 true/false를 찍기 위해 사용함. 이 문장이 없을 경우.. 아래 bool 타입 cout 시, 1 or 0 으로 출력됨 (1:true, 0:false)
	cout << boolalpha ;	
	cout << "is_match: " << is_match << endl ;
	
	regex re2(R"(\d+)") ;
	string str2 = "ab 123456 cd ef" ;
	
	smatch match_info ;
	regex_search(str2, match_info, re2) ;
	cout << "number: " << match_info.str() << endl ;
	
	return 0 ;
}