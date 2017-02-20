#include <iostream>

using namespace std;

class CTest
{
	int m_nData{ 0 };
public:
	CTest() { cout << "디폴트 생성자" << endl; }
	CTest(int nParam) : m_nData(nParam) { cout << "변환 생성자" << endl; }
	~CTest() { cout << "소멸자" << endl; }

	CTest(const CTest& rhs) : m_nData(rhs.m_nData)
	{
		cout << "복사 생성자" << endl;
	}

	CTest(const CTest&& rhs) : m_nData(rhs.m_nData)
	{
		cout << "이동 생성자" << endl;
	}

	operator int() const		// 형변환 연산자 정의
	{
		cout << "형변환 연산자" << endl;
		return this->m_nData;
	}

	CTest& operator=(const CTest& rhs)		// 대입 연산자 정의
	{
		cout << "대입 연산자" << endl;
		this->m_nData = rhs.m_nData;
		return *this;
	}

	CTest operator+(const CTest& rhs)		// 덧셈 연산자 정의
	{
		cout << "덧셈 연산자" << endl;
		CTest result(0);
		result.m_nData = this->m_nData + rhs.m_nData;
		return result;
	}
};

int main()
{
	CTest a(0), b(3), c(4);

	a = b + c;			// a = b.operator+(c); == a.operator=(b.operator+(c));

	cout << a << endl;
}

// 23번째 줄
// 형변환 연산자를 정의해주었다.

// 36번째 줄
// 덧셈 연산자를 정의해주었다.
// 여기서 중요한 것은 대입연산자와는 다른 구조를 보인다는 것이다.
// 자료형은 참조형이 아닌 클래스형이다.
// 게다가 39번째 줄 새로운 객체를 생성하였다.
// 새로운 객체에 원본 멤버변수와 참조형 멤버변수를 더하여 저장후 새로운 객체를 반환한다.
// 기존에 있던 b, c 객체를 더하는 b = b + c; 같은 구조를 가지지 않는다.
// 왜냐하면 덧셈 연산을 한 이후에는 임시객체에 저장하기 때문이다.
// 그렇기 때문에 b = b + c;같은 구조를 가지면 b의 값이 바뀐 상태로 저장이된다.
// 따라서 a = b + c;를 하게 될 경우 a와 b의 값이 같은 상태로 저장이된다.
// a는 a이고 b는 b여야 한다.
// 그러므로 객체는 생성하되 어차피 사라질 것이기 때문에 아무렇게나 생성을 해놔야 한다.
// 형태를 잘 기억하자.

// 49번째 줄
// a = b.operator+(c);라고 해석이 가능하다.
// 이는 a.operator=(b.operator+(c));라고 또 해석이 가능하다.
// 덧셈 연산자와 대임 연산자가 불리게 된다.

// 51번째 줄
// 23번째 줄에서 형변환 연산자를 정의해주었으므로 a만 불러도 static_cast<int>(a)가 자동으로 호출되며 출력한다.