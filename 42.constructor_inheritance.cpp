#include <iostream>

using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest()" << endl; }						// 이 생성자가 없으면 자식 클래스의 디폴트 생성자를 호출할 수 없다.
	CTest(int nParam) { cout << "CTest(int)" << endl; }			// 이 생성자가 없어지면 호환 가능한 변환생성자가 불린다. -> CTest(double)
	CTest(double dParam) { cout << "CTest(double)" << endl; }	// 이 생성자가 없어지면 호환 가능한 변환생성자가 불린다. -> CTest(int)
	// 두 생성자가 전부 없으면 디폴트 생성자가 호출된다.
};

class CTestEx : public CTest		// 상속
{
public:
	CTestEx() { cout << "CTestEx()" << endl; }		// CTest의 디폴트 생성자 호출
	CTestEx(int nParam) : CTest(nParam)		// CTest의 int 생성자 호출
	{
		cout << "CTestEx(int)" << endl;
	}
	CTestEx(double dParam) : CTest(dParam)	// 이것도 CTest의 double 생성자 호출
	{
		cout << "CTestEx(double)" << endl;
	}
	//using CTest::CTest;		// 한방에 쓸 수 있는 마법의 문장
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

// 14번 줄
// 상속을 받았다.

// 17번 줄
// 자식의 디폴트 생성자는 부모의 디폴트 생성자가 존재해야 호출될 수 있다.

// 18번 줄
// 멤버 이니셜라이저 형태로 CTest에 nParam값을 전달하였다.
// 이로써 CTestEx에 int형 변환 생성자가 호출되면 CTest의 int형 변환 생성자도 같이 호출된다.
// 만약 이 생성자가 없어지면 CTest(double)가 대신 호출이 된다.
// 인수와 매개변수가 호환이 되는 생성자가 호출이 되는 것이다.

// 22번 줄
// 이 또한 멤버 이니셜라이저 형태로 CTest에 dParam값을 전달하였다.
// 그렇기에 CTestEx에 double형 변환 생성자가 호출되면 CTest의 double형 변환 생성자도 같이 호출된다.
// 만약 이 생성자가 없어지면 CTest(int)가 대신 호출이 된다.
// 인수와 매개변수가 호환이 되는 생성자가 호출이 되는 것이다.

// 18, 22번 줄 이 두 생성자가 모두 없다면 기본생성자가 불리게 된다.

// 26번 줄
// 지금까지 정의한 생성자에 대한 상속을 모두 구현할 수 있는 마법의 문장이다.
// 생성자에 대한 상속이 필요하다면 이 문장을 사용하자.
// C++11을 지원하는 컴파일러에서만 사용가능하다.
// visual C++ 13 이하는 C++11을 제대로 지원하지 않아서 사용할 수 없다.

// 이 모든 것을 '생성자 상속'이라는 이름으로 불린다.
// C#에서도 마찬가지로 생성자 상속과 같은 기능이 있다.
// CPPPP/21.Base.cs 를 보면 된다.