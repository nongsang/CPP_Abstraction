#include <iostream>

using namespace std;

class CTest
{
	int m_nData;		// 접근제어지시자가 없다.
public:
	CTest() : m_nData(10)
	{
		cout << "디폴트 생성자" << endl;
	}

	void PrintData()
	{
		cout << m_nData << endl;

	}

	int Getter()				// getter
	{
		return m_nData;
	}

	void Setter(const int& n)	// setter
	{
		m_nData = n;
	}
};

int main()
{
	CTest t;
	int n;
	t.PrintData();

	cout << endl;

	// t.m_nData = 20;	// private는 외부에서 접근 불가
	t.Getter();			// 게터를 이용한 멤버변수 접근
	cin >> n;
	t.Setter(n);		// 세터를 이용한 멤버변수값 수정
	t.PrintData();
}

// 7번째 줄
// 접근제어지시자 없이 멤버변수를 선언하였다.
// 이 경우 디폴트로 private 선언이 된다.
// private 선언이 된 멤버변수는 클래스 외부에서 접근이 불가능하다.
// 이 경우 다른 방법을 사용하여야 한다.

// 20 ~ 23번째 줄
// 게터를 이용하여 멤버변수에 접근하여 값을 반환하는 함수이다.
// 멤버변수가 private선언이 되어도 멤버함수는 멤버변수에 접근이 가능하다.

// 25 ~ 28번째 줄
// 세터를 이용하여 멤버변수의 값을 수정하는 함수이다.
// 마찬가지로 멤버함수는 멤버변수에 접근이 가능하면 값 또한 바꿀 수 있다.

// 39번째 줄
// private 선언이 된 멤버변수에 클래스 외부에서 직접 접근이 불가능함을 보여준다.

// 40번째 줄
// getter를 이용하여 멤버변수에 접근 후 멤버변수의 값을 출력할 수 있음을 보여준다.
// public 선언된 getter는 외부에서 얼마든지 접근이 가능하다.

// 42, 43번째 줄
// setter를 이용하여 멤볍변수의 값을 수정하고 출력한다.
// 마찬가지로 public 선언된 getter는 외부에서 접근이 가능하고 멤버변수의 값 또한 바꿀 수 있다.

// 이렇게 getter와 setter를 사용하여 private값에 얼마든지 접근이 가능하다.