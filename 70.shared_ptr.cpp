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

int main()
{
	cout << "main() 시작" << endl;
	shared_ptr<CTest> ptr1(new CTest);	// shared_ptr 사용법

	cout << "Count : " << ptr1.use_count() << endl;		// ptr1이라는 객체가 하나 생성되어 있으므로 1이다.
	{
		shared_ptr<CTest> ptr2(ptr1);		// ptr2 = ptr1과 같은 의미

		cout << "Count : " << ptr1.use_count() << endl;		// ptr2라는 객체도 생성되어 있으므로 2이다.
		cout << "Count : " << ptr2.use_count() << endl;		// 이걸 보면 객체가 따로 있는게 아닌거같다.

		ptr2->TestFunc();
	}

	cout << "Count : " << ptr1.use_count() << endl;		// ptr2가 소멸했으므로 1이다.
	ptr1->TestFunc();
	cout << "main() 끝" << endl;
}

// 17번 줄
// auto_ptr과 똑같이 사용하면 된다.
// auto_ptr과 다른것은 생성된 객체는 1개라는 점이다.
// 생성된 객체는 1개지만 포인터를 생성하여 여러 포인터가 1개의 객체를 참조하는 형식이다.
// 그리고 객체는 참조하는 포인터의 갯수를 저장한다.
// 포인터 갯수가 0이 되면 객체는 소멸하게 된다.

// 19번 줄
// ptr1이라는 포인터만 객체를 참조하고 있으므로 1이 출력된다.

// 21번 줄
// ptr1이 가리키는 객체를 가리키는 ptr2라는 포인터를 생성한다는 뜻이다.
// 그러므로 ptr2 = ptr1과 같은 의미이다.

// 23, 24번 줄
// 하나의 객체를 ptr1, ptr2가 가리키고 있으므로 출력되는 값은 2이다.

// 29번 줄
// 현재 ptr2는 구간을 빠져나온 상태이다.
// 그러므로 ptr2는 삭제되고 ptr1만 객체를 가리키는 상태가 된다.
// 따라서 1이 출력된다.