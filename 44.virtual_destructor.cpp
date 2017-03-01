#include <iostream>

using namespace std;

class CTest
{
	char* m_pszData{ nullptr };
public:
	CTest()
	{
		cout << "CTest 생성자" << endl;
		m_pszData = new char[32];		// CTest 동적할당
	}
	virtual ~CTest()				// 소멸자를 virtual로 정의하였다.
	{
		cout << "CTest 소멸자" << endl;
		delete[] m_pszData;
		m_pszData = nullptr;
	}
};

class CTestEx :	public CTest
{
	int* m_pnData{ nullptr };
public:
	CTestEx()
	{
		cout << "CTestEx 생성자" << endl;
		m_pnData = new int;			// CTestEx만의 동적할당
	}
	~CTestEx()				// CTestEx 소멸자 정의
	{
		cout << "CTestEx 소멸자" << endl;
		delete[] m_pnData;
		m_pnData = nullptr;
	}
};

int main()
{
	CTest *pData = new CTestEx;		// virtual을 쓰지 않았으므로 참조형식을 따름

	delete pData;			// 여기서 문제가 발생

	pData = nullptr;
}

// 12번 줄
// char형으로 CTest의 멤버변수를 동적할당 해주었다.

// 14번 줄
// 소멸자를 부르면서 메모리 해제를 해주고 있다.
// 여기서 주목할 것은 소멸자를 virtual을 사용하여 가상함수로 정의해 주었다는 것.
// 43번 줄에서 다시 설명

// 29번 줄
// int형으로 CTestEx의 멤버변수를 동적할당 해주었다.

// 31번 줄
// 소멸자를 호출하면서 CTestEx의 메모리를 해제하고 있다.

// 41번 줄
// 참조형식이 CTest, 실형식이 CTestEx다.
// 가상함수를 사용한 함수는 소멸자밖에 없다.

// 43번 줄
// 눈여겨 봐야하는 줄~~~~~~~~
// 여기서 참조형식인 CTest형 변수 pData를 메모리 해제해주고 있다.
// 하지만 메모리 크기는 CTestEx로 잡았으므로 CTestEx의 생성자가 불린다는 것이 문제다.
// pData를 메모리 해제를 하면 CTest의 소멸자가 불리지만, CTestEx의 소멸자가 불리지 않는다.
// 그렇게 때문에 14번 줄 소멸자를 가상함수로 정의해준 것이다.
// virtual은 최하단에 있는 자식 클래스의 오버라이딩된 함수를 가리킨다.
// 소멸자는 비록 이름이 같지 않더라도 가상함수로 일심동체가 된다는 생각을 하면 CTestEx의 소멸자가 불리는 것은 당연하다.