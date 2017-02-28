#include <iostream>

using namespace std;

class CTest
{
	int m_nData{ 0 };
public:
	int GetData() const
	{
		cout << "getter" << endl;
		return m_nData;
	}
	void SetData(const int nParam)
	{
		cout << "setter" << endl;
		m_nData = nParam;
	}
};

class CTestEx : public CTest
{
public:
	void SetData(const int nParam)
	{
		if (nParam < 0)
			CTest::SetData(0);		// 부모 클래스의 멤버변수를 호출

		else if (nParam > 10)
			CTest::SetData(10);		// 이것도 마찬가지
	}
};

int main()
{
	CTest a;

	a.SetData(-10);
	cout << a.GetData() << endl;

	CTestEx b;

	b.SetData(15);
	cout << b.GetData() << endl;
}

// 24번 줄
// 오버라이딩의 개념
// 부모 클래스에도 같은 이름과 기능을 하는 멤버함수가 존재한다.
// 하지만 자식 클래스에 같은 이름을 가진 멤버함수를 새롭게 정의해주었다.
// 자식 클래스를 이용하여 함수를 호출하면 새롭게 정의된 멤버함수가 불리게 된다.

// 27, 30번 줄
// 부모 클래스의 멤버변수를 자식 클래스 멤버변수에서 호출하여 오버라이드(override) 했다.
// 기존에 있던 부모 클래스의 멤버함수를 이용하여 재정의해줄 수 있다.
// 이외에도 전혀 상관없는 기능으로 재정의 해줄 수 있다.

// 36번 줄
// 부모 클래스인 CTest를 생성했다.

// 38번 줄
// a의 SetData()를 사용하여 값을 변경해주고 있다.
// -10을 입력하였으므로 -10이 입력된다.

// 41번 줄
// 자식 클래스인 CTestEx를 생성했다.

// 43번 줄
// b의 SetData()를 사용하여 값을 변경해주고 있다.
// a에서도 SetData()가 있었지만 자식 클래스에 새롭게 정의된 SetData()가 있으므로 자식 클래스의 SetData()를 호출한다.
// b의 SetData()는 값의 범위를 검사하는 새로운 기능을 정의해주었으므로 기존의 것보다 더 많은 기능을 사용할 수 있다.

// 44번 줄
// 자식 클래스인 b를 통해서 부모 클래스의 GetData()를 호출하였다.
// b에는 GetData()가 정의되어 있지 않기때문에 부모 클래스의 GetData()를 호출한다.