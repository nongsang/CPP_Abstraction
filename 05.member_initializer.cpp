#include <iostream>

using namespace std;

class CTest
{
public:
	int m_nData1, m_nData2;
	CTest() : m_nData1(10), m_nData2(20)	// 멤버 이니셜라이저
	{
		cout << "디폴트 생성자" << endl;
	}

	void PrintData()
	{
		cout << m_nData1 << endl;
		cout << m_nData2 << endl;
	}
};

int main()
{
	CTest t;
	t.PrintData();
}

// 9번째 줄
// 멤버 이니셜라이저를 이용하여 생성과 함께 초기화를 하는 바이너리 코드를 생성한다.
// C++11부터 일반적인 변수 초기화로 선언과 동시에 멤버변수를 초기화할 수 있다.
// 생성과 함께 초기화를 하기 때문에 성능이 약간 상승하기에 사용했지만 지금은 호환성 때문에 사용한다.
// 일반적인 변수 초기화처럼 사용해도 성능은 똑같다.