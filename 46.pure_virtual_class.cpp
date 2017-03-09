#include <iostream>

using namespace std;

class CInterface
{
public:
	CInterface() { cout << "CInterface 생성자" << endl; }
	virtual ~CInterface() { cout << "CInterface 소멸자" << endl; }

	virtual int GetData() const = 0;				// 순수 가상함수
	virtual void SetData(const int nParam) = 0;		// 오버라이딩으로만 사용 가능하게 선언
};

class CTest : public CInterface
{
	int m_nData{ 0 };
public:
	CTest() { cout << "CTest 생성자" << endl; }
	~CTest() { cout << "CTest 소멸자" << endl; }

	int GetData() const { return m_nData; }					// 오버라이딩
	void SetData(const int nParam) { m_nData = nParam; }	// 이것도
};

int main()
{
	//CInterface a;		// 순수 가상 클래스는 선언 및 정의 불가
	CTest a;
	a.SetData(5);
	cout << a.GetData() << endl;
}

// 11, 12번 줄
// 순수 가상함수들로써 함수들을 호출할 수 없다.
// 이 함수들은 오버라이딩으로만 사용이 가능하다.
// 반드시 재정의를 해줘야만 한다.

// 22, 23번 줄
// CInterface의 순수 가상함수들을 오버라이딩하였다.

// 28번 줄
// CInterface는 순수 가상함수로만 이루어져 있으므로 순수 가상 클래스다.
// 그러므로 현재 순수 가상 클래스를 생성하려 시도하는 중이다.
// 하지만 순수 가상 클래스는 존재하지만 사용할 수 있는 함수가 없으므로 생성이 불가능하다.

// 29 ~ 31번 줄
// 상속받은 자식클래스 CTest를 생성하고 정의, 호출하고 있다.
// 순수 가상 클래스는 삭속 받은 자식 클래스의 공통직인 특성을 알려주는 것이라 생각하면 된다.
// 자세한 활용은 48.abstract_data_type에서 설명
