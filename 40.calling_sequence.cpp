#include <iostream>

using namespace std;

class CTestA
{
public:
	CTestA() { cout << "CTestA()" << endl; }
	~CTestA() { cout << "~CTestA()" << endl; }
};

class CTestB : public CTestA
{
public:
	CTestB() { cout << "CTestB()" << endl; }
	~CTestB() { cout << "~CTestB()" << endl; }
};

class CTestC : public CTestB
{
public:
	CTestC() { cout << "CTestC()" << endl; }
	~CTestC() { cout << "~CTestC()" << endl; }
};

int main()
{
	cout << "main() 시작" << endl;
	CTestC data;
	cout << "main() 끝" << endl;
}

// 12번 줄
// CTestB를 정의할 때 CTestA를 상속하였다.

// 19번 줄
// CTestC를 정의할 때 CTestB를 상속하였다.

// 29번 줄
// 마지막 자식 클래스인 CTestC를 생성하였다.
// 여기서 CTestC의 생성자부터 실행이 된다.
// 하지만 생성자는 최상위 부모 클래스인 CTestA부터 호출이 된다.
// 그리고 CTestB, CTestC순으로 소멸자가 불린다.
// 하지만 소멸자는 최하위 자식 클래스인 CTestC부터 호출된다.
// 차례로 CTestB, CTestA순으로 소멸자가 불리게 된다.