#include <iostream>

using namespace std;

class CTest
{
	int* m_npData{ nullptr };
public:
	CTest(int nParam)
	{
		cout << "생성자" << endl;
		m_npData = new int;
		*m_npData = nParam;
	}

	~CTest()
	{
		cout << "소멸자" << endl;
		delete m_npData;
		m_npData = nullptr;
	}

	CTest(const CTest& rhs)
	{
		cout << "복사생성자" << endl;
		m_npData = new int;
		*m_npData = *rhs.m_npData;
	}

	CTest& operator=(const CTest& rhs)
	{
		*m_npData = *rhs.m_npData;		// 힙 영역에서 대입 연산을 한다.
		return *this;				// 자신에 대한 참조를 반환
	}

	int GetData() const { return *m_npData; }
};

int main()
{
	CTest a(10);
	CTest b(20);

	a = b;		// 얕은복사

	cout << a.GetData() << endl;
	cout << b.GetData() << endl;
}

// 44번째 줄
// 대입연산자는 같은 값을 저장하는 연산이다.
// 하지만 이는 스택에 존재할 경우의 이야기이다.
// 힙에 존재할 경우 얕은 복사로 인식되어 제대로 값을 전달할 수 없다.
// 따라서 스택에서 일어나는 연산은 얕은 것, 힙에서 일어나야 하는 연산은 깊은 것으로 생각할 수 있다.
//
// 제대로 연산이 일어나기 위해서는 연산자에 대한 오버로딩을 해주어야 한다.
// 일반 연산자보다 우선권을 가지기 위해서.

// 30번째 줄
// 원본 클래스를 참조하여 연산자를 사용하는 연산자 오버로딩을 정의해주었다.
// 44번째 줄은 a.operator=(b);라고 자동 컴파일되어 연산을 한다.
// 따라서 자동으로 바뀌어 연산하는 것보다 우선권을 가지기위하여 클래스에 operator=()라는 함수를 만들어주어 오버로딩으로 우선권을 가져온다.
// 원본의 operator=()라는 함수를 호출한다.
// 그리고 b라는 클래스 변수를 전달하여 참조형으로 연산하는 함수이다.
// 정의에는 힙 영역에 있을 경우 값을 대입하는 것을 정의해준다.
// 그리고 값이 변경됨을 *this로 전달해준다.
// 여기서 *this의 대상은 a가 된다.
// a의 대상으로 = 연산을 b와 하고 a의 값이 바뀌었기 때문이다.
// operator+() 혹은 operator-()와 같은 연산자도 정의할 수 있다.
// 나중에는 출력을 위해서 ostream<<()라는 함수도 정의할 수 있으니 잘 알아두도록