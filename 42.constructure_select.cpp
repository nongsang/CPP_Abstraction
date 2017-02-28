#include <iostream>

using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest()" << endl; }
	CTest(int nParam) { cout << "CTest(int)" << endl; }
	CTest(double dParam) { cout << "CTest(double)" << endl; }
};

class CTestEx : public CTest		// 상속
{
public:
	CTestEx() { cout << "CTestEx()" << endl; }		// CTest의 디폴트 생성자 호출
	CTestEx(int nParam)	: CTest(nParam)		// CTest의 int 생성자 호출
	{
		cout << "CTestEx(int)" << endl;
	}
	CTestEx(double dParam) : CTest(dParam)	// 이것도 CTest의 double 생성자 호출
	{
		cout << "CTestEx(double)" << endl;
	}
};

int main()
{
	CTestEx a;
	CTestEx b(5);
	CTestEx c(3.3);
}

// 8 ~ 10번 줄
// 멤버함수 오버로딩을 하였다.
// default, int, double형이다.

// 13번 줄
// 상속을 받았다.

// 17번 줄
// 멤버 이니셜라이저 형태로 CTest에 nParam값을 전달하였다.
// 이로써 CTestEx에 int형 변환 생성자가 호출되면 CTest의 int형 변환 생성자도 같이 호출된다.

// 21번 줄
// 이 또한 멤버 이니셜라이저 형태로 CTest에 dParam값을 전달하였다.
// 그렇기에 CTestEx에 double형 변환 생성자가 호출되면 CTest의 double형 변환 생성자도 같이 호출된다.