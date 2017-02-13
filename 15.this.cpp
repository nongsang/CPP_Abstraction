#include <iostream>

using namespace std;

class CMyData
{
	int m_nData;
public:
	CMyData(int n) : m_nData(n) {}
	void Print()					// void Print(CMyData *pData)
	{								// CMyData *this = pData;
		// m_nData에 접근
		cout << "m_nData : " << m_nData << endl;

		// CMyData의 멤버변수 m_nData에 접근
		cout << "CMyData::m_nData : " << CMyData::m_nData << endl;

		// 메서드를 호출한 인스턴스의 m_nData에 접근
		cout << "this->m_nData : " << this->m_nData << endl;		// 실제로 컴파일 되는 코드

		// 메서드를 호출한 인스턴스의 CMyData의 멤버변수 m_nData에 접근
		cout << "this->CMyData::m_nData : " << this->CMyData::m_nData << endl;
	}
};
int main()
{
	CMyData a(5), b(10);	// 변수처럼 한번에 a, b로 선언 가능

	cout << "a" << endl;
	a.Print();				// a.Print(&a);

	cout << endl;
	cout << "b" << endl;
	b.Print();				// b.Print(&b);
}

// 10, 11번째 줄
// 컴파일이 될때는 실제로 주석처럼 자동으로 컴파일이 된다.
// 다만 모두 자동으로 되기 때문에 생략하는 것.
// 지금은 이렇게 쓰면 생산성이 떨어지므로 쓰지 않는게 문법에 더 알맞다.

// 13번째 줄
// 일반적으로 멤버변수에 접근하는 방식이다.
// 하지만 이렇게만 쓰면 자동으로 컴파일러가 19번째 줄처럼 컴파일하여 실행한다.
// this 포인터를 안써도 이해가 되는 코드라면 this를 쓰지 않아도 되지만, 명확히 해야할 경우에는 19번째 줄처럼 코딩하자.

// 16번째 줄
// 범위 지정 연산자(::)를 이용하여 소속을 명확히 하여 멤버변수에 접근한다.

// 19번째 줄
// this 포인터를 이용하여 메서드를 호출한 인스턴스의 멤버변수에 접근한다.
// 메서드는 멤버함수와 같은 뜻이다.
// this는 클래스의 인스턴스를 뜻한다고 보면 된다.
// 다시말해 this는 메서드가 속해있는 어떤 클래스 자체를 말한다.

// 22번째 줄
// this 포인터와 범위 지정 연산자(::)를 이용해서 멤버변수의 소속을 명확하게 하고 있다.

// 27번째 줄
// 클래스 변수를 초기화하는 명령이다.
// ()를 이용하여 초기화가 가능하며, 일반 변수처럼 한 줄에 여러 변수를 선언하는 것이 가능하다.

// 30, 34번째 줄
// 10, 11번째 줄의 주석처럼 자동으로 컴파일이 되므로 인스턴스의 주소를 넘겨주는 작업도 자동으로 한다.
// 따라서 이것도 생략하는게 좋다.


// 지금까지 자동으로 컴파일 되는 것을 다 써봤지만 전부 실행되는건 아닌것 같다.
// 그냥 이렇게 컴파일러가 해석한다는 것만 알아두자.
// 어차피 안써도 사용에는 지장이 없어서...