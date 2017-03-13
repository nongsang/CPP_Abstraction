#include <iostream>

using namespace std;


class CTest
{
	char *m_pszData;
public:
	CTest(int nSize)
	{
		m_pszData = new char[nSize];
	}
	~CTest()
	{
		delete[] m_pszData;
		cout << "정상적으로 객체가 소멸함" << endl;
	}
};

int main()
{
	try
	{
		int nSize;
		cout << "Input Size : ";
		cin >> nSize;

		CTest a(nSize);		// try 내에서 객체생성을 하고 있다.
	}

	catch (bad_alloc &exp)	// 메모리 예외처리
	//catch (exception &exp)
	{
		cout << exp.what() << endl;		// 예외 발생 이유
		cout << "ERROE : CTest()" << endl;
	}
}

// 29번 줄
// 입력받은 값으로 객체를 생성하고 있다.
// 만약 -1값을 넣으면 메모리는 int형으로 입력해도 unsined로 인식하므로 32비트에서 가장 큰수로 인식한다.
// 따라서 오류를 뿜을 것이다.

// 32번 줄
// 메모리 예외처리를 하기 위한 catch문 작성법이다.
// bad_alloc 클래스는 exception 클래스의 파생 클래스이며 메모리관련 예외처리를 담당한다.
// 물론 33번 줄처럼 bad_alloc대신에 exception을 사용해도 된다.

// 35번 줄
// what() 메서드를 사용하면 예외가 발생한 이유를 알 수 있다.