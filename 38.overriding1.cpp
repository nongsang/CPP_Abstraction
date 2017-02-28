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

	b.SetData(15);					// 묵시적 호출
	//b.CTest::SetData(15);			// 명시적 호출
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
// 주의해야 할 점은 SetData()만 사용할 경우 '재귀호출'이 이루어진다.
// 그러므로 재사용을 하기 위해서는 꼭 소속을 적어줘야 한다.

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
// 이를 묵시적 호출이라고 한다.
// 자식 클래스 b를 이용하여 부모 클래스의 멤버함수에 접근하기 위해서는 b.CTest::SetData()로 호출해야 한다.
// 이를 명시적 호출이라고 한다.

// 44번 줄
// 자식 클래스 b를 이용하여 부모 클래스의 멤버함수에 접근하기 위해서는 b.CTest::SetData()로 호출해야 한다.
// 이를 명시적 호출이라고 한다.

// 45번 줄
// 자식 클래스 b를 사용하여 부모 클래스 GetData()에 접근한다.
// 이 상황에서는 오버라이딩을 하지 않았으므로 그대로 GetData()가 호출된다.