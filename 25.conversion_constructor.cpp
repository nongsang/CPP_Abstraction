#include <iostream>

using namespace std;

class CTest
{
	int m_nData;
public:
	CTest(int nParam) : m_nData(nParam)		// 변환생성자
	//explicit CTest(int nParam) : m_nData(nParam)		// 생성자 호출 거부
	{
		cout << "생성자" << endl;
	}

	~CTest() { cout << "소멸자" << endl; }

	int GetData() const { return m_nData; }
};

void TestFunc(const CTest& param)	// 여기서 변환생성자 불림
{
	cout << "TestFunc() : " << param.GetData() << endl;
}

int main()
{
	cout << "main() 시작" << endl;
	TestFunc(5);		// 함수 호출인데 인자가?
	//TestFunc(CTest(5));
	cout << "main() 종료" << endl;
}

// 9번째 줄
// 매개변수가 1개인 생성자를 '변환생성자'라고 한다.

// 20번째 줄
// 함수의 파라미터가 클래스이다.

// 28번째 줄
// 19번째 줄 파라미터가 클래스인 함수를 상수 인자로 호출하였다.
// CTest 자료형과 int 자료형은 맞지 않기 때문에 호출이 불가능해야 한다.
// 하지만 CTest 클래스가 int형에 대한 변환생성자를 제공하므로 CTest param(5)로 인식된다.
// 그냥 사용해도 생성자가 불리는데 참조형으로 사용해도 생성자가 불린다.
// 게다가 동적할당을 할 때 처럼 main함수 내에서 생성자, 소멸자가 불린다.
// 함수가 불리면서 생성자가 불리고 함수가 반환되면서 소멸자가 불린다.
//
// 함수가 불리면서 컴파일러가 알아서 임시객체를 생성하고 소멸한다.
// 그러므로써 성능저하가 일어난다.
// 이를 묵시적 변환 생성자 호출(implicit conversion constructor call)이라고 한다.

// 10번째 줄
// 이 묵시적 변환 생성자가 호출되지 않기 위해서 explicit 키워드를 사용한다.
// 키워드를 사용하면 묵시적 변환 생성자 호출할 상황이 발생할 경우 컴파일러차원에서 오류가 발생한다.
// 명시적(explicit)으로 선언하였기 때문
// 일시객체가 생성된다는 사실이 명확히 드러나도록 29번째 줄 TestFunc(CTest(5));라고 해야 한다.