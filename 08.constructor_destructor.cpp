#include <iostream>

using namespace std;

int num{ 0 };		// 순서를 알아보기 위한 전역변수
class CTest
{
public:
	CTest()		// 생성자 정의
	{
		num++;
		cout << num << "번째 CTest 생성자" << endl;
	}

	~CTest()	// 소멸자 정의
	{
		cout << num << "번째 CTest 소멸자" << endl;
		num--;
	}
};

CTest T;		// 전역으로 첫번째 객체 생성

int main()
{
	cout << "main() 시작" << endl;

	CTest C;			// 지역으로 두번째 객체 생성

	cout << "main() 끝" << endl;
}

// 5번째 줄
// 단순히 순서를 알아보기 위한 전역변수 초기화

// 6 ~ 20번째 줄
// 생성자와 소멸자를 정의해주었다.
// 생성자와 소멸자는 자동으로 호출이 되기 때문에 정의를 해주지 않아도 불린다.
// 객체의 순서를 알아보기 위해 전역변수에 접근하였다.

// 22번째 줄
// 전역으로 첫번째 객체를 생성

// 28번째 줄
// 지역으로 두번째 객체를 생성

// 결과를 통해 유추할 수 있는 것은
// 1. 전역으로 선언된 생성자는 main()함수보다 먼저 불린다.
// 2. main()함수가 끝나야 소멸자가 불린다.