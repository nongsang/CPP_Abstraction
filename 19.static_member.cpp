#include <iostream>

using namespace std;

class CTest
{
	int m_nData;
	static int m_nCount;	// 정적 멤버변수 선언
public:
	CTest(int nParam) : m_nData(nParam) { m_nCount++; }
	~CTest() {};

	int GetData() { return m_nData; }
	void ResetCount() { m_nCount = 0; }

	static int GetCount() { return m_nCount; }	// 정적 메서드 선언 및 정의
};

int CTest::m_nCount = 0;	// CTest 클래스의 정적 멤서변수 정의

int main()
{
	CTest a(5), b(10);	// 클래스의 인스턴스 생성

	cout << a.GetCount() << endl;	// 정적 멤버변수에 접근
	b.ResetCount();				// 정적 멤버변수에 접근

	cout << CTest::GetCount() << endl;	// 인스턴스가 없이 접근 가능
}

// 8번째 줄
// 정적 멤버변수 선언을 하였다.

// 10번째 줄
// 인스턴스를 생성할 때 마다 정정 멤버변수에 +1을 한다.

// 16번째 줄
// 정적 메서드 정의를 하였다.
// 이걸 해준 이유는 28번째 줄을 보면 된다.

// 19번째 줄
// 정적으로 선언된 멤버변수는 클래스 외부에서 정의가 가능하다.
// 반대로 정적 선언이 안된 m_nData 멤버변수는 외부에서 정의가 불가능

// 23번째 줄
// 일반적으로 클래스를 변수로 사용한다고 선언과 동시에 인스턴스를 생성해주는 과정이다.

// 25, 26번째 줄
// 일반적으로 멤버함수에 접근하는 방식으로 정적 멤버함수와 변수에 접근이 가능하다.

// 28번째 줄
// 정적으로 선언된 멤버함수는 인스턴스를 사용하지 않고 접근이 가능하다.