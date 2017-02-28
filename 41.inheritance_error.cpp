#include <iostream>

using namespace std;

class CTestA
{
protected:
	char* m_npData{ nullptr };			// 동적할당용 변수
public:
	CTestA()
	{
		cout << "CTestA()" << endl;
		m_npData = new char[32];		// 동적할당
	}
	~CTestA()
	{
		cout << "~CTestA()" << endl;
		delete[] m_npData;				// 메모리 해제
	}
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
	~CTestC()
	{
		cout << "~CTestC()" << endl;
		delete[] m_npData;				// 여기도 메모리 해제?
	}
};

int main()
{
	cout << "main() 시작" << endl;
	CTestC data;
	cout << "main() 끝" << endl;
}

// 8번 줄
// 동적할당용으로 포인터 변수를 선언하였다.

// 13번 줄
// char로 32개 만큼 배열로 동적할당 하였다.

// 18번 줄
// 동적할당 했으니 메모리 해제를 해주고 있다.

// 36번 줄
// 자식 클래스에서 메모리를 해준다.
// 여기서 문제 발생
// 부모 클래스에서 동적할당하였지만 자식 클래스에서 소멸자가 불리면서 메모리를 해제해줄 수 있다.
// 다만 부모 클래스의 소멸자가 나중에 불리면서 또 메모리해제가 된다.
// 그렇기 때문에 오류가 발생한다.

// 여기서 2가지 주의할 점
// 1. 자식 클래스는 부모 클래스의 멤버변수에 쓰기연산하면 안된다.
// 2. 자식 클래스 생성자에서 부모 클래스 멤버변수를 초기화하면 안된다.
//
// 공통적으로 부모 클래스에서 만들고 쓴것은 자식클래스에서 접근하면 안된다.