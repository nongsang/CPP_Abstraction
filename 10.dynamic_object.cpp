#include <iostream>

using namespace std;

class CTest
{
	int num{ 0 };
public:
	CTest()
	{
		cout << "CTest 생성자" << endl;
	}

	~CTest()
	{
		cout << "CTest 소멸자" << endl;
	}
};

int main()
{
	cout << "main() 시작" << endl;

	CTest * arrC = new CTest[3];	// 배열 형식으로 동적 할당

	cout << endl;

	CTest * C = new CTest;		// 1개만 동적 할당

	cout << endl;

	delete C;				// 동적 할당 해제

	cout << endl;

	delete[] arrC;			// 동적 할당 해제

	cout << "main() 끝" << endl;
}

// 24번째 줄
// 클래스를 배열 형식으로 동적 할당

// 28번째 줄
// 클래스 1개만 동적 할당

// 32번째 줄
// 1개만 동적 할당 된 클래스를 메모리 해제한다.

// 36번째 줄
// 배열 형식으로 동적 할당 된 클래스를 메모리 해제 한다.

// 이를 통해 유추할 수 있는점
// 1. 동적 할당을 한 클래스는 main()함수 내에서 생성자와 소멸자가 모두 불린다.
// 2. 개발자가 정의한 메모리 해제 순서에 따라 소멸자가 불린다.

// 게임을 개발하기 위해 자주 사용되는 방식이므로 꼭 숙지할 것