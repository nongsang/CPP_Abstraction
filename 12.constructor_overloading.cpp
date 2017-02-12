#include <iostream>

using namespace std;

class CMyData
{
	int m_nData;
public:
	// 디폴트 생성자는 없다.
	CMyData(int nParam) : m_nData(nParam) {};	// 파라미터가 한개 있는 생성자
	CMyData(int x, int y) : m_nData(x + y) {};	// 파라미터가 두개 있는 생성자
	int GetData() { return m_nData; }
};

int main()
{
	CMyData a(10);
	CMyData b(3, 4);
	//CMyData c;		// 불가능

	cout << a.GetData() << endl;
	cout << b.GetData() << endl;
}

// 10, 11번째 줄
// 파라미터를 1개 밭는 생성자와 2개 받는 생성자를 정의하였다.
// 디폴트 생성자를 제외한 생성자를 여러개 정의하는 것을 '생성자 다중 정의', 혹은 '생성자 오버로딩'이라고 한다.

// 17, 18번째 줄
// 어떤 생성자를 호출할지 컴파일러가 매개변수를 보고 자동으로 결정한다.

// 19번째 줄
// 디폴트 생성자가 없으므로 생성자 호출 불가