#include <iostream>

using namespace std;

template<typename T>		// 템플릿 사용
class CTest
{
	T m_Data;
public:
	CTest(T param) : m_Data(param) {}
	T GetData() const { return m_Data; }

	operator T() { return m_Data; }
	void SetData(T param) { m_Data = param; }
};

int main()
{
	CTest<int> a(5);		// 자료형을 명시하였다.
	cout << a << endl;

	CTest<double> b(123.45);
	cout << b << endl;		// 이것도

	CTest<char*> c("Hello World!");
	cout << c << endl;		// 요것도
}

// 5번 줄
// T라는 이름의 정해지지 않은 자료형을 템플릿이라 한다.

// 6 ~ 15번 줄
// 각 요소들을 템플릿으로 정한 T로 정의해주었다.
// 이렇게 찍어서 만들어진 클래스를 템플릿 클래스라고 한다.

// 19, 22, 25번 줄
// 클래스를 템플릿으로 인스턴스를 선언할 때 각각에 맞는 자료형의 정의하였다.
// 여기서 실제 코드로 드러나지는 않고 내부적으로만 생성된다.