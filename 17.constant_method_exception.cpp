#include <iostream>

using namespace std;

class CTest
{
	mutable int m_nData{ 0 };			// 멤버변수를 뮤터블로 설정
public:
	CTest(int nParam) : m_nData(nParam) {};
	~CTest() {};

	int GetData() const
	{
		m_nData = 20;		// 상수형 메서드임에도 멤버변수에 값을 할당한다?
		return m_nData;
	}

	int SetData(const int& nParam) { m_nData = nParam; }
};

void TestFunc(const int& nParam)
{
	// 상수형 잠조였으나 일반 참조로 형변환
	int &nNewParam = const_cast<int&>(nParam);		// int 참조형으로 const 형변환을 했기 때문에 값의 변경 허용
	nNewParam = 20;
}

int main()
{
	CTest a(10);
	cout << a.GetData() << endl;

	int nData = 10;
	TestFunc(nData);
	cout << nData << endl;
}
// 1. mutable
// 7번째 줄
// 멤버변수를 mutable로 선언하였다.
//
// 14번째 줄
// 상수형 메서드임에도 멤버변수가 mutable이기 때문에 값 변경이 가능하다.

// 2. const_cast<>()
// 21번째 줄
// 매개변수로 const int 참조형으로 정의되어 있다.
//
// 24번째 줄
// int 참조형으로 nNewParam을 정의하여 nData값을 바꾸는 작업을 한다.
// 하지만 매개변수가 const이므로 참조형으로 변수를 수정하는게 불가능하다.
// const_cast<>()를 사용하여 const형을 형변환하여 수정이 가능하게 바꾼다.
//
// 25번째 줄
// const_cast<>()로 형변환이 되어 수정하면 참조형이므로 nData값도 바뀌게 된다.

// 이 두가지 방법은 나중에 유지보수를 위해 사용하는 것이지 일반적으로 사용하지 않는다.