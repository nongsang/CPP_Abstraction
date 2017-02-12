#include <iostream>

using namespace std;

class CMyPoint
{
	int m_x{ 0 };
	int m_y{ 0 };
public:
	CMyPoint(int x)			// 파라미터 1개 있는 생성자 정의
	{
		cout << "CMyPoint(int)" << endl;
		if (x > 100)
			x = 100;

		m_x = x;
	}

	CMyPoint(int x, int y) : CMyPoint(x)	// 파라미터 2개 있는 생성자 정의
	{
		cout << "CMyPoint(int, int)" << endl;

		if (y > 200)
			y = 200;

		m_y = y;
	}

	void Print()
	{
		cout << "X : " << m_x << endl;
		cout << "Y : " << m_y << endl;
	}
};

int main()
{
	CMyPoint ptBegin(110);
	ptBegin.Print();

	CMyPoint ptEnd(50, 250);
	ptEnd.Print();
}

// 10번째 줄
// 파라미터가 1개일때 생성자를 정의하였다.

// 19번째 줄
// 파라미터가 2개일때 생성자를 정의하였다.
// 일반적인 생성자와 차이점은 파라미터가 1개인 생성자가 추가로 호출된다는 것이다.
// x값을 검사하는 생성자를 같이 호출하여 재활용하는 것이다.
// 그냥 호출은 불가능하고 멤버 이니셜라이저로 호출한다.
// 다중 생성자를 정의할 수 있으나 코드가 길어질 수록 읽기가 힘들어지고 유지보수가 어려워진다.
// 그러므로 생성자를 재활용하여 생성자를 정의하는 것이다.
//
// 주의할 점은 너무 남발하여 쓰레드에서 말하는 교착상태에 빠진것같은 상태로 디자인하지 말자.
// 교착상태는 쓰레드에서 설명한다.