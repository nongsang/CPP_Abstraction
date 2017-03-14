#include <iostream>
#include <functional>

using namespace std;

class CTest
{
	int m_narray[5];
public:
	CTest()
	{
		m_narray[0] = 30;
		m_narray[1] = 10;
		m_narray[2] = 50;
		m_narray[3] = 20;
		m_narray[4] = 40;
	}

	void Print()
	{
		for (auto &n : m_narray)
			cout << n << '\t';

		cout << endl;
	}

	void Sort(function<int(int, int)> cmp)
	{
		int nTemp;

		for (int i = 0; i < 4; ++i)
		{
			for (int j = i + 1; j < 5; ++j)
			{
				if (cmp(m_narray[i], m_narray[j]) < 0)
				{
					nTemp = m_narray[i];
					m_narray[i] = m_narray[j];
					m_narray[j] = nTemp;
				}
			}
		}
	}
};

int main()
{
	CTest data;

	data.Sort([](int a, int b)->int {return a - b;});	// sort로 람다 전달
	data.Print();

	data.Sort([](int a, int b)->int {return b - a;});	// sort로 람다 전달
	data.Print();
}

// 함수 객체를 람다식으로 사용하였다.
// 비교용으로 사용했던 부모클래스를 선언하고
// 그 밑으로 구체적으로 비교하는 자식클래스를 만들지 않았다.

// 27 ~ 43번 줄
// 부모클래스를 받아서 참조형식을 이용하여 정렬하는 함수를 만들었었다.
// 하지만 지금은 function을 받아서 비교하고 정렬하는 함수를 만들었다.
// 그러므로 비교용으로 클래스를 만들지 않아도 된다.

// 50, 53번 줄
// CTest클래스에 있는 Sort함수로 람다를 전달하고 있다.
// 여기서 Sort()함수를 실행하면서 전달받은 람다를 기준으로 값을 비교하여 정렬을 한다.

// 이처럼 함수식을 인자로 넘겨주는 방식을 람다식이라고 한다.
// 내가 만든 함수에서 람다식을 받기 위해서는 functional을 include해줘야 한다.
// qsort()는 제너릭 함수이므로 functional은 필요없다.
// qsort를 사용한 정렬에 람다를 사용해보자.