#include <iostream>

using namespace std;

class CTest
{
protected:
	int m_nData{ 0 };
public:
	CTest(int nParam) : m_nData(nParam) {}

	CTest operator+(const CTest &rhs)
	{
		return CTest(m_nData + rhs.m_nData);
	}

	CTest operator=(const CTest &rhs)
	{
		m_nData = rhs.m_nData;

		return *this;
	}

	operator int() { return m_nData; }
};

class CTestEx : public CTest
{
public:
	CTestEx(int nParam) : CTest(nParam) {}

	/*CTestEx operator+(const CTestEx &rhs)
	{
		return CTestEx(static_cast<int>(CTest::operator+(rhs)));
	}*/
	using CTest::operator+;
	using CTest::operator=;
};

int main()
{
	CTest a(3), b(4);
	cout << a + b << endl;		// CTest에 대입연산자를 오버로딩해주었으므로 컴파일 오류가 나지 않는다.

	CTestEx c(3), d(4), e(0);

	e = c + d;		// 클래스에 맞는 대입연산자가 없어서 컴파일 오류가 난다.
	cout << e << endl;
}

// 43번 줄
// CTest 끼리 더하는 덧셈연산자를 오버로딩하였으므로 컴파일 오류가 발생하지 않는다.

// 47번 줄
// CTestEx 끼리 더하는 대입연산자가 없어서 컴파일 오류가 발생한다.
// 여기서 중요한 것은 대입연산자에서 컴파일 오류가 났다는 것이다.
// CTest에 있는 덧셈연산자는 자료형이 CTest이다.
// 이는 단순 대입의 r-value가 CTest형이라는 것.
// 따라서 결과값을 받는 자료형이 CTest여야 하는 것이다.
// 하지만 e는 CTestEx형이므로 오류가 나는 것이다.
// 이를 해결하기 위해서는 CTestEx에 덧셈연산자 오버로딩을 해주어야 한다.

// 32 ~ 35번 줄
// CTestEx operator+(const CTestEx &rhs)를 정의해준다.
// operator+를 호출해주고 연산 결과가 저장된 CTestEx 객체를 반환해주는 것.
// 이게 맞긴하지만 더 편하게 정의해줄 수 있다.

// 36, 37번 줄
// 알맹이는 부모클래스의 것을 사용하고 인터페이스만 맞춰줄 수 있는 방법.
// using으로 상위클래스의 현산자 함수들을 그대로 차용한다고 선언하는 것이다.