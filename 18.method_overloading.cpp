#include <iostream>

using namespace std;

class CTest
{
	int m_nData;
public:
	CTest() : m_nData(0) {};
	~CTest() {};

	int GetData() { return m_nData; }

	void SetData(int nParam) { m_nData = nParam; }		// 함수 이름이 SetData
	void SetData(double nParam) { m_nData = 0; }		// 이것도 함수 이름이 SetData
	void SetData(char nParam) = delete;					// 요거도 함수 이름이 SetData
};

int main()
{
	CTest a;

	a.SetData(10);					// SetData 멤버함수 부르기
	cout << a.GetData() << endl;

	a.SetData(5.5);					// 이것도 SetData 멤버함수 부르는데?
	cout << a.GetData() << endl;

	a.SetData('a');					// 요거도 SetData 멤버함수 부름
	cout << a.GetData() << endl;
}

// 14 ~ 16번째 줄
// 두 메소드 이름이 SetData로 같다.

// 23번째 줄
// 메소드를 부른다.
// 하지만 int형으로 인자를 전달하고 있다.
// 그렇기 때문에 자동으로 int형 파라미터를 가진 SetData 메소드를 찾아서 실행한다.

// 26번째 줄
// 이번에는 double형으로 인자를 전달한다.
// 그러므로 double형 파라미터를 가진 SetData 메소드를 자동으로 찾아서 실행한다.

// 29번째 줄
// 이번에는 char형으로 인자를 전달한다.
// SetData 메소드 중에서 char형 파라미터를 가진 메소드를 자동으로 찾아서 실행한다.
// 하지만 멤버한수가 delete 예약어로 정의되어 있다.
// 따라서 컴파일러차원에서 오류를 일으키게 된다.

// 15번째 줄 메소드가 정의되어 있지 않다면?
// double형으로 인자를 넘겨줄 때 int형으로 형변환해서 정보손실이 일어난다.
// 정보손실을 줄이기 위해서 오버로딩을 하자.