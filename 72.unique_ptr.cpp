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

	unique_ptr<CTest> ptr1(new CTest);	// 똑같이 쓰면 된다.

	//unique_ptr<CTest> ptr2(ptr1);		// 불가능
	//ptr2 = ptr1;						// 이것도 불가능

	cout << "main() 끝" << endl;
}

// 18번 줄
// unique_ptr의 사용방법이다.
// 지금까지 해왔던 방식처럼 똑같이 사용하면 된다.

// 20, 21번 줄
// shared_ptr과 달리 한 객체에 여러 포인터를 가질 수 없고 얕은 복사도 불가능하다.
// 이 말은 한 객체에 하나의 포인터만 사용가능하다는 뜻이다.

// 이것 이외에 weak_ptr도 있다.
// 사용법은 똑같다.
// shared_ptr에서 사용되는데 단순히 참조용으로 쓰이고 객체를 수정할 수는 없다.
// shared_ptr의 참조 카운터에도 영향도 없다.
// 참조하려면 shared_ptr로 변환해야 하므로 거의 사용하지 않는다.