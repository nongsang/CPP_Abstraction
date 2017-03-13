#include <iostream>
#include <memory>

using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest 생성자" << endl; }
	~CTest() { cout << "CTest 소멸자" << endl; }
	void TestFunc() { cout << "CTest::TestFunc()" << endl; }
};

int main()
{
	auto_ptr<CTest> ptr(new CTest[3]);		// auto_ptr은 배열형대로 생성해도 배열형태로 소멸이 안된다.

	auto_ptr<CTest> ptrTest(new CTest);
	auto_ptr<CTest>	ptrNew;

	cout << "0x" << ptrTest.get() << endl;		// auto_ptr의 주소값 얻는 방법

	ptrNew = ptrTest;						// 얕은 복사
	cout << "0x" << ptrTest.get() << endl;

	ptrTest->TestFunc();		// 이게 사용불가
}

// 16번 줄
// auto_ptr을 사용해서 배열형태로 생성하였다.
// 하지만 배열형태로 생성했지만 배열형태로 소멸이 되지 않아서 오류가 발생한다.

// 23번 줄
// 얕은 복사를 해주고 있다.
// 문제는 얕은 복사를 해주면서 ptrTest의 인스턴스를 ptrNew로 복사해주고 ptrTest는 NULL로 초기화해버린다는 것이다.

// 26번 줄
// ptrTest는 NULL이 되면서 멤버변수를 사용할 수 없어지게 된다.

// 정리하면 auto_ptr의 단점은
// 1. 배열생성 불가
// 2. 얕은 복사시 자신 접근 불가