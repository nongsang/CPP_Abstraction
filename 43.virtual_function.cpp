#include <iostream>

using namespace std;

class CTest
{
protected:
	int m_nData{ 10 };
public:
	virtual void PrintData() const			// 가상 멤버함수 정의
	//virtual void PrintData() const final	// 가상 멤버함수 오버라이딩 불가능
	{
		cout << "CTest : " << m_nData << endl;
	}
	void TestFunc() const
	{
		cout << "****TestFunc 시작****" << endl;
		PrintData();							// 소속을 밝히지 않고 PrintData();만 사용하였다.
		cout << "**** TestFunc 끝 ****" << endl;
	}
};

class CTestEx : public CTest
{
public:
	virtual void PrintData() const			// 가상 멤버함수 오버라이딩
	{
		cout << "CTestEx : " << m_nData * 2 << endl;
	}
};

int main()
{
	CTestEx a;
	a.PrintData();

	CTest &b = a;
	b.PrintData();

	CTest c;
	c.PrintData();		// 명시적이므로 10이 출력된다.

	a.TestFunc();
}

// 10번 줄
// 가상 멤버함수를 정의해 주었다.
// 가상 멤버함수는 오버라이딩을 한 상태에서만 의미가 있다.
// 오버라이딩을 해야하기 때문에 상속도 필수다.
// 37번 줄에서 다시 설명

// 26번 줄
// 가상 멤버함수의 재정의를 해 주었다.
// 이는 곧 오버라이딩을 했다는 의미.
// 여기서 가상함수의 힘이 발휘된다.
// 부모 클래스가 가상함수를 사용하며, 그 부모 클래스를 상속하였다면,
// 최하단에 있는 자식 클래스가 오버라이딩한 함수를 출력한다.
// CTestEx가 최상단 부모 클래스를 상속받은 최하단 자식 클래스이므로 PrintData()만 사용하면,
// CTestEx의 PrintData()가 호출이 되는 것이다.
//
// 그리고 또 하나
// virtual은 곧 최하단 자식 클래스의 오버라이딩된 함수를 부르게 되므로
// 자식 클래스는 virtual을 사용하지 않아도 된다.

// 34, 35번 줄
// CTestEx 변수를 생성하여 PrintData()를 호출했으므로 당연히 초기값 10에서 2배인 20이 출력된다.

// 37, 38번 줄
// CTest 참조형식으로 원본 a를 이용하여 생성하고 출력하였다.
// 여기서 중요한 것은 CTest의 참조형식으로 생성했음에도 값이 20으로 출력이 된다는 것이다.
// 10번 줄에서 가상 멤버함수를 정의해 주었기 때문에 참조형식으로 생성했음에도 실형태의 멤버함수가 불리는 것이다.
// 39.overriding2에서와 다른 결과를 보여준다.
// virtual을 사용하였다면 '실형태', 곧, 자식 클래스의 멤버함수를,
// virtual을 사용하지 않았다면 '참조형태' 곧, 부모 클래스의 멤버함수를 부르게 된다.

// 40, 41번 줄
// CTest형 변수를 생성하였고 CTest의 PrintData()를 사용하였다.
// 명시적으로 사용하였으므로 10이 출력이 된다.

// 17번 줄
// 부모 클래스 내에서 PrintData()를 호출하고 있다.
// 하지만 virtual이 존재하므로 오버라이딩 된 자식 클래스의 PrintData()가 호출이 된다.
// 부모 클래스 내에서 조차 virtual을 사용한 멤버함수가 불리지 않음을 주의하자.

// 11번 줄
// 만약 가상함수의 오버라이딩을 하지 못하게 하기 위해서는 뒤에 final 키워드를 넣자.
// 자식 클래스의 오버라이딩이 불가능해질 것이다.
