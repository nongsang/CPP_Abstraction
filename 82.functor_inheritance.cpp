#include <iostream>

using namespace std;

class CCompareBase
{
public:
	virtual int operator()(int a, int b) const = 0;
};

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

	void Sort(const CCompareBase &cmp)
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

class CCmpDesc : public CCompareBase
{
public:
	int operator()(int a, int b) const { return a - b; }
};

class CCmpAsce : public CCompareBase
{
public:
	int operator()(int a, int b) const { return b - a; }
};

int main()
{
	CTest data;

	CCmpDesc desc;
	data.Sort(desc);	// 펑터 사용
	data.Print();

	CCmpAsce asce;
	data.Sort(asce);	// 펑터 사용
	data.Print();
}

// 32 ~ 48번 줄
// 정렬방법 정의
// 여기서 40번 줄이 중요하다.
// CCompareBase으로 정의된 참조형 변수에 두개의 정수를 넘겨주는 방식이다.

// 51 ~ 61번 줄
// CCompareBase를 상속받는 자식클래스들이 정수를 받아서 각자의 정의로 값을 비교한다.
// 부모클래스가 순수가상클래스이므로 사실 CCompareBase를 사용해서 값을 비교하는 40번 줄은
// 자식클래스의 정의에 따라서 값을 비교한다.

// 68, 72번 줄
// 배웠던 펑터를 사용해서 각자의 함수를 호출한다.