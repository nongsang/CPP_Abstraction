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
			CTest::SetData(0);

		else if (nParam > 10)
			CTest::SetData(10);
	}
};

int main()
{
	CTestEx a;
	CTest &rData = a;
	rData.SetData(15);
	cout << rData.GetData() << endl;
}

// 36번 줄
// 참조형의 원본으로 삼기 위해서 자식 클래스인 CTestEx로 생성하였다.
// 이를 '실형식'이라고 한다.

// 37번 줄
// 부모 클래스인 CTest의 참조형으로 생성하며 원본은 a이다.
// 이를 '참조형식'이라고 한다.
// 자식 클래스를 부모 클래스라고 말하는 것은 이상한 논리가 아니다.
// 가령 부모 클래스가 '사람'이고, 자식 클래스가 '소크라테스'일때,
// '소크라테스는 사람이다' 라는 논리가 틀리지 않기 때문이다.
// 참조형이 아닌 CTest형이여도 참조형과 같다.
// 단지 복사가 이루어지는 것만 다를 뿐

// 38번 줄
// 부모 클래스의 참조형의 원본이 자식 클래스이지만 참조형의 메서드는 부모 클래스의 메서드로 인식된다.
// 따라서 값 보정을 하지 않은 상태로 15가 그대로 적용이 된다.