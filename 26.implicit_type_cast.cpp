#include <iostream>

using namespace std;

class CTest
{
	int m_nData;
public:
	explicit CTest(int nParam) : m_nData(nParam)
	{
		cout << "생성자" << endl;
	}

	operator int(void) { return m_nData; }		// 형변환 연산자
	//explicit operator int(void) { return m_nData; }	// 명시적 형변환

	~CTest() { cout << "소멸자" << endl; }

	int GetData() const { return m_nData; }
};

int main()
{
	cout << "main() 시작" << endl;

	CTest a(10);		// 변환생성자 호출

	cout << a.GetData() << endl;	// 일반적 멤버변수 접근 방식
	cout << a << endl;				// 묵시적 자료형 변환
	cout << (int)a << endl;			// C 스타일 형변환
	cout << static_cast<int>(a) << endl;	// C++ 스타일 형변환
	
	cout << "main() 종료" << endl;
}

// 14번째 줄
// 형변환 연산자를 오버로딩하였다.
// 객체에 대한 형변환은 형변환 연산자가 있어야 한다.

// 28번째 줄
// 일반적으로 멤버변수에 접근하는 방식이다.

// 29번째 줄
// 묵시적으로 자료형 변환을 하여 출력하는 방식이다.
// 형변환 연산자가 존재해야만 형변환이 가능하다.
// 이는 묵시적 변환이기 때문에 15번째 줄 처럼 명시적으로 형변환 연산자 오버로딩을 하면 사용할 수 없다.

// 30번째 줄
// C 스타일의 명시적 형변환이다.
// 이 형변환도 형변환 오버로딩이 필수다.

// 32번째 줄
// C++ 스타일의 형변환이다.
// 이 스타일을 우리가 지향해야 한다.
// 이 형변환도 형변환 오버로딩이 필수.