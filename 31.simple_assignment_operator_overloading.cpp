#include <iostream>

using namespace std;

class CTest
{
	int* m_npData{ nullptr };	// 포인터형 변수
public:
	explicit CTest(int nParam)
	{
		cout << "변환 생성자" << endl;
		m_npData = new int(nParam);	// 동적할당
	}

	~CTest()
	{
		cout << "소멸자" << endl;
		if (m_npData != nullptr)	// 이 부분은 눈여겨 보자
			delete[] m_npData;

		m_npData = nullptr;		// 이 부분도
	}

	operator int()
	{
		cout << "형변환 연산자" << endl;
		return *m_npData;				// 반환형이 포인터형
	}

	CTest& operator=(const CTest& rhs)	// void operator=(const CTest& rhs)로 한다면?
	{
		cout << "대입 연산자" << endl;
		if (this == &rhs)	// r-value가 자신이라면 대입 수행하지 않는다. a = a;같은거
		{
			cout << "대입하지 않음" << endl;	// 대입하지 않을 경우 출력
			return *this;
		}

		if (m_npData != nullptr)	// 이 부분 중요
			delete[] m_npData;

		m_npData = new int(*rhs.m_npData);		// m_npData = new int; *m_npData = *rhs.m_npData;
		return *this;
	}
};

int main()
{
	CTest a(0), b(3), c(4);

	a = a;		// 이건 수행 안함

	a = b = c;			// 이게 가능해야지

	cout << a << b << c << endl;
}

// 7번째 줄
// 클래스에서 동적할당으로 쓰기 위해 포인터형으로 선언

// 12번째 줄
// 변환 생성자를 호출하면서 동적할당한다.

// 18, 19번쨰 줄
// 일단 동적할당이 되어 있는지 확인한다.
// 동적할당이 되었다면 메모리 해제를 한다.
// 확인하는 것은 꼭 만들어주자.

// 21번째 줄
// 메모리 해제를 해주면 아무것도 하지 못하게 nullptr로 할당해주자.

// 27번째 줄
// 동적할당 할 멤버변수는 포인터형이다.
// 이를 출력하기 위해서는 일반 자료형으로 형변환 해주어야 한다.
// 그러므로 int*형인 멤버변수의 값을 반환해야 한다.

// 42번째 줄
// 원래 쓰던 대입 연산자 함수가 아닌 void operator=(const CTest& rhs)로 나타낼 수 있다.
// 기본적으로 스택에서 생성하고 사용하기에는 void operator=(const CTest& rhs)만으로도 가능하다.

// 38번째 줄
// 원래 힙에 있던 메모리를 해제하고 새롭게 동적할당을 한다.
// 여기서 30번째 줄 void operator=(const CTest& rhs)이 문제가 된다.
// void 이므로 참조형으로 사용하던 rhs가 없어져서 a = a경우 제대로 값이 복사가 되지 않는다.
// a = a; 같은경우 불필요하지만 혹시 이런 연산을 할 경우를 대비해서 금지해야한다.

// 33 ~ 37번째 줄
// 42번째 줄만 있을경우 발생하는 문제를 해결하기 위해서
// a = a; 연산을 하지 않게끔했다.
// 하지만 문제는 아직도 존재한다.
// a = b = c; 같은 연산이 불가능하다.

// 다시 30번째 줄
// void operator=(const CTest& rhs)에서 void형은 l-value가 될 수 없다.
// 게다가 존재하지 않는 것을 대입한다(r-value가 생성된다)는 것은 논리적으로 불가능하다.
// 따라서 r-value가 생성되게끔 만들어줘야한다.
// CTest& operator=(const CTest& rhs)로 해주고 내부는 return *this;로 해줘야 한다.
// 이렇게 하면 임시객체가 생성되므로 가능하다.

// 51번째 줄
// 33 ~ 37번째 줄에서 정의해준 것과 같이 본인을 저장한다는 연산은 하지 않는다.

// 53번째 줄
// 30번째 줄 처럼 참조형으로 정의해주었기 때문에 임시객체가 생성되므로 
// 이 것은 가능한 연산이 된다.