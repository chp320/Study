#include <iostream>
using namespace std ;

int main()
{
	int data[10] = { 5, 19, 76, 3, 10, 89, 54, 43, 2, 17 } ;
	
	int nSize = sizeof(data) ;
	cout << "nSize: " << nSize << ", 배열개수: " << nSize / sizeof(int) << endl ;
	
	/* 배열의 개수를 구하려면.. sizeof(배열명)/sizeof(타입) 으로 구하여야 한다. */
	
	for(int i=0; i<10; i++)
	{
		if(data[i] % 2 == 0)
			/* 짝수인 경우 */
			cout << i << " : " << data[i] << "는 짝수입니다." << endl ;
		else
			/* 홀수인 경우 */
			cout << i << " : " << data[i] << "는 홀수입니다." << endl ;
	}
	
	return 0 ;
	return 0 ;
}