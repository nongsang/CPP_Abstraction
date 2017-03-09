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
	CTest &rData = a;		// 이거 이상하다.
	rData.SetData(15);		// 어떤 멤버함수가 호출이 되나? CTest? CTestEx?
	cout << rData.GetData() << endl;

	CTest *pData = new CTestEx;		// 이거 이상하다?
	pData->SetData(12);
	cout << pData->GetData() << endl;
	delete pData;
	pData = nullptr;
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

// 41번 줄
// CTest형 포인터 변수를 이용하여 CTestEX 크기만큼 동적할당 하였다.
// 여기서도 '실형식'은 pData이므로, pData 클래스의 메소드를 사용하게 된다.
// 하지만 이런 형식은 쓰지 말도록
// 자식 클래스인 CTestEx의 소멸자가 불리지 않기때문이다.
// 해결법은 44.virtual_destructor에서 다룬다.