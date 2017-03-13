#include <iostream>
#include <memory>

using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest 생성자" << endl; }
	~CTest() { cout << "CTest 소멸자" << endl; }
};

int main()
{
	cout << "main() 시작" << endl;
	{
		auto_ptr<CTest> ptrTest(new CTest);		// auto_ptr사용법
	}
	cout << "main() 끝" << endl;
}

// 16 ~ 18번 줄
// auto_ptr를 사용하는 방법이다.
// CTest의 크기만큼 동적할당하고 ptrTest가 동적생성된 객체의 주소를 담고 있다.
// 그리고 ptrTest가 소멸하면서 자동으로 가리키는 대상을 삭제한다.
// 재미있는 것은 for문이나 if문도 아닌데 {}를 사용하여 묶어준 것이다.
// 구간이 넘어가면서 자동으로 소멸되도록 유도하기위함이다.