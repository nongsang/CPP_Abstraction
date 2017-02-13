#include <iostream>

using namespace std;

class CTest
{
	int m_nData{ 0 };
public:
	CTest(int nParam) : m_nData(nParam) {};
	~CTest() {};

	int GetData() const { return m_nData; }		// 상수형 메서드

	int SetData(int nParam) { m_nData = nParam; }	// 세터는 상수형으로 사용 불가
};

int main()
{
	CTest a(10);
	cout << a.GetData() << endl;
}

// 12번째 줄
// 함수 바로 뒤에 const를 사용하여 변수들의 변경을 막고있다.
// 그냥 읽기만 하기 위해서 const를 사용하는 것이다.
// const를 얼마나 잘 쓰느냐에 따라서 프로그래머의 실력을 가늠할 수 있다.

// 14번째 줄
// 세터의 경우 값의 할당을 하기 때문에 const는 사용불가