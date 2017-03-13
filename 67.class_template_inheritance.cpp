#include <iostream>

using namespace std;

template<class T>
class CTest
{
protected:
	T m_Data;
};

template<class T>
class CTestEx : public CTest<T>		// 템플릿 클래스 사용법
{
public:
	T GetData() const { return m_Data; }
	void SetData(T param) { m_Data = param; }
};

int main()
{
	CTestEx<int> a;
	a.SetData(5);
	cout << a.GetData() << endl;
}

// 5 ~ 10번 줄
// 일반 템플릿 클래스를 정의해줬다.

// 12 ~ 18번 줄
// 템플릿 클래스의 상속을 받아서 정의하였다.
// 13번 줄에서 클래스이름과 템플릿을 정의해주는 것으로 쉽게 사용할 수 있다.

// 22번 줄
// 템플릿 클래스를 사용하기 위해서 자료형을 항상 명시해야 한다.