#include <iostream>
#include <memory>

using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest 생성자" << endl; }
	~CTest() { cout << "CTest 소멸자" << endl; }
	void TestFunc() { cout << "TestFunc()" << endl; }
};

void RemoveTest(CTest *pTest)		// 배열삭제용으로 정의
{
	cout << "RemoveTest()" << endl;
	delete[] pTest;
}

int main()
{
	cout << "main() 시작" << endl;

	shared_ptr<CTest> ptr1(new CTest[3], RemoveTest);	// 배열생성과 배열소멸이 가능하게끔 한다.

	shared_ptr<CTest> ptr2(new CTest);		// 새롭게 생성
	ptr2.reset();				// 가리키는 대상을 즉시 삭제

	cout << "main() 끝" << endl;
}

// 14 ~ 18번 줄
// 객체삭제용으로 함수를 정의하였다.
// 파라미터가 클래스 포인터형임을 주의하자.
// 그리고 배열로 생성해도 각자의 객체에 접근은 불가능하다.

// 24번 줄
// shared_ptr이지만 객체를 3개 생성한다.
// 그리고 객체 소멸할 때는 정의해 준 RemoveTest()함수를 호출하면서 소멸하게 된다.

// 27번 줄
// 따로 새롭게 생성한 객체를 즉시 삭제할 수 있다.