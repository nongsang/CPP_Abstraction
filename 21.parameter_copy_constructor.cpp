#include <iostream>

using namespace std;

class CTest
{
	int m_nData{ 0 };
	
public:
	CTest(int nParam) : m_nData(nParam)
	{
		cout << "CTest(int)" << endl; 
	}

	~CTest() { cout << "소멸자" << endl; }

	CTest(const CTest &rhs) : m_nData(rhs.m_nData)	// = delete;
	{
		cout << "복사 생성자" << endl;
	}

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
};

void TestFunc(CTest cParam)		// 매개변수가 클래스이므로 복사생성 발생
//void TestFunc(CTest& cParam)
//void TestFunc(const CTest& cParam)
{
	cout << "TestFunc()" << endl;

	cParam.SetData(20);	// 함수에서 인스턴스의 값을 변경
}

int main()
{
	cout << "main() 시작" << endl;

	CTest a(10);
	TestFunc(a);

	cout << "a : " << a.GetData() << endl;
	cout << "main() 끝" << endl;
}

// 26번째 줄
// 매개변수가 클래스이므로 복사생성이 발생한다.

// 32번째 줄
// 함수 내에서 멤버함수 값을 변경을 시도하고 있다.

// 여기서의 문제점은 명확하다.
// 1. 쓸데없는 복사생성이 발생
// 2. call by value이므로 값의 변경이 되지 않는다.

// 이 문제들을 해결하기 위해서는 무엇을 해야 하는가

// 1. 27번째 줄 '참조형'을 이용하여 복사생성 방지
// 2. 17번째 줄 'delete'로 복사생성 원천 봉쇄
// 3. 28번째 줄 const '참조형'으로 사용하여 값의 변경을 허용하지 않는다.

// 복사생성은 잘 쓰면 좋지만 잘 못쓰면 오히려 독이된다.