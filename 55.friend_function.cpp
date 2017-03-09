#include <iostream>

using namespace std;

class CTest
{
private:
	int m_nData;		// private로 선언된 멤버변수다.
public:
	CTest(int nParam) : m_nData(nParam) {}
	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	friend void PrintData(const CTest &rData);		// 외부에서 접근하는 함수를 friend로 선언, 함수의 원형을 써도 좋다.
};

void PrintData(const CTest& rData)
{
	cout << "PrintData() : " << rData.m_nData << endl;		// 여기 중요
}

int main()
{
	CTest a(5);
	PrintData(a);
}

// 14번 줄
// 외부에서 접근하는 함수를 friend로 선언하였다.
// 함수의 원형을 써도 좋다.
// friend void PrintData(const CTest&)만 써도 된다는 뜻이다.

// 19번 줄
// 외부 함수에서 private선언된 멤버변수에 접근하여 출력하고 있다.
// GetData()가 아니라 바로 접근이 가능한 것이 friend의 힘이다.

// 쌔빠지게 객체지향 공부했는데 다 열어주는 friend를 배우네?
// 완전히 무관하게 설계하거나, 떨어져있더라도 서로 긴밀하느 관계라면 friend를 써줄 수 있다.