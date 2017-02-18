#include <iostream>

using namespace std;

class CTest
{
	int m_nData;
	char* m_pszName{ nullptr };
public:
	CTest(int nParam, char* pszName)
		: m_nData(nParam), m_pszName(pszName)
	{
		cout << "생성자 : " << m_pszName << endl;
	}

	~CTest() { cout << "소멸자 : " << m_pszName<< endl; }

	CTest(const CTest& rhs)
		: m_nData(rhs.m_nData), m_pszName(rhs.m_pszName)
	{
		cout << "복사생성자 : " << m_pszName << endl;
	}

	CTest& operator = (const CTest& rhs)
	{
		cout << "연산자 오버로딩 : =" << endl;
		m_nData = rhs.m_nData;
		return *this;
	}

	int GetData() const { return m_nData; }
};

CTest TestFunc(int nParam)		// 클래스형 함수 정의
{
	CTest a(nParam, "a");		// 인스턴스 생성
	return a;					// 객체 반환
}

int main()
{
	cout << "main() 시작" << endl;

	CTest b(5, "b");					// 인스턴스 생성

	b = TestFunc(10);					// 대입연산
	cout << b.GetData() << endl;
	
	cout << "main() 종료" << endl;
}

// 34 ~ 38번째 줄
// 클래스형 함수를 정의하였다.
// 함수 내에서 클래스의 인스턴스를 정의하고 반환한다.
// 이 부분은 매우 중요

// 46번째 줄
// call by value와 같은 매커니즘으로 함수가 반환되면서 b의 값이 바뀌지 않을거라 예상할 수 있다.
// 하지만 실제로 값이 바뀐다.
// 임시객체가 생기기 때문이다.
//
// 1. 44번째 줄 인스턴스 생성으로 b 생성자 호출
// 2. 46번째 줄 함수 호출
// 3. 36번째 줄 인스턴스 a 생성자 호출
// 4. main()함수 내에서 생성한 것이 아니기 떄문에 컴파일러가 임시로 객체를 생성하면서 복사생성자를 호출
// 5. 37번째 줄 반환으로 처음 a 객체 원본에 대한 소멸자 호출
// 6. 60번째 줄 임시객체가 생성되어서 반환이 되었음에도 메모리에는 남아있기 때문에 대입연산 수행가능
// 7. 대입연산을 마치면서 임시객체인 a 객체 복사본에 대한 소멸자 호출
// 8. 마지막으로 b 객체 소멸자 호출

// 가장 중요한 것은 main()함수 내에서 객체를 생성한 것이 아니다.
// main()함수 외에서 함수를 사용하여 인스턴스를 생성하는 것이 문제인 것.
// 개발자가 명한 것이 아니라 함수가 생성하라고 시켜서 문제가 되었다.
// 임시객체는 이름이 없기 때문에 불러서 없앨 수도 없다.
// 그냥 함수만 불러도 마찬가지로 임시객체가 생성된다.
// 참조형으로 이름을 부여해도 임시객체가 main()함수 이후로 생명이 늘어날 뿐.
// 최대한 이런 코딩은 하지 않게끔 조심하자.