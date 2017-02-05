#include <iostream>

using namespace std;

class CTest			// 클래스 선언
{
public:				// 접근제어지시자
	int m_nData;	// 멤버변수
	CTest()			// 디폴트 생성자		매우 중요
	{
		cout << "디폴트 생성자" << endl;
		m_nData = 10;
	}

	void PrintData()	// 멤버함수 정의
	{
		cout << m_nData << endl;
	}

	void SetData();		// 멤버함수 선언
};

void CTest::SetData()	// 멤버함수의 정의
{
	m_nData = 20;
}

int main()
{
	CTest t;		// 클래스 생성
	t.PrintData();	// 멤버함수에 접근
	t.SetData();	// 외부에 정의된 멤버함수에 접근
	t.PrintData();
}

// 5 ~ 18번째 줄
// 클래스 정의를 한다.

// 7번째 줄
// 접근제어지시자이다.
// 접근할 수 있는 권한을 부여한다고 생각하면 된다.
// 이외에 private, protected가 있다.
// 나머지는 다음에 설명

// 8번째 줄
// 멤버변수를 선언하였다.
// 변수를 선언하면 가능한 초기화도 같이 하여 버그를 줄이자.

// 9 ~ 13번째 줄
// 매우 중요하다.
// 클래스를 생성하면 자동으로 호출이 된다.
// 심지어 정의가 되어 있지 않아도 자동으로 호출된다.
// 보통 멤버변수의 초기화를 해주기 위해 사용한다.
// 디버그용으로 사용하기도 한다.
// 생성자이므로 소멸자도 존재하지만 나중에 설명한다.

// 15번째 줄
// 멤버함수를 클래스 내에 정의하였다.
// 클래스 내에 있는 멤버변수에 접근이 가능함을 보이고 있다.

// 20번째 줄
// 멤버함수를 선언만 하였다.

// 23번째 줄
// 선언만 되어 있던 멤버함수를 클래스 외부에서 정의하였다.
// 잘 알아 두어야 한다.
// 나중에 파일 분할하였을 경우 자주 쓰일 방식이다.

// 30번째 줄
// 클래스를 생성하였다.
// 이 순간 디폴트 생성자가 불리게 된다.

// 31번째 줄
// 생성된 클래스에 있는 멤버함수에 접근한다.
// 수행을 마치고 소멸자가 불리게 된다.

// 32번째 줄
// 외부에 정의된 멤버할수라도 다른 멤버함수와 같이 사용이 가능