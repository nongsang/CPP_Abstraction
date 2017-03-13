#include <iostream>

using namespace std;

int TestFunc(int nParam)
{
	cout << "Function Pointer: " << nParam << endl;
	return nParam;
}

int main()
{
	auto Func = [](int nParam) -> int
	{
		cout << "Lamda : " << nParam << endl;
		return nParam;
	};
	Func(5);

	auto pfTest = TestFunc;
	pfTest(10);
}

// 13 ~ 18번 줄
// 람다를 사용하는 방법이다.
// 파라미터를 int형으로 받아서 반환형식이 int형인 함수 원형으로 볼 수 있다.
// 단지 람다는 이름이 없으므로 이름을 대신할 변수가 정의되어 있어야만 한다.
// 이는 auto형으로 정의된 Func변수가 대신한다.
// 그리고 18번 줄에서 값을 대입하는 형식이다.

// 5 ~ 9번, 20, 21번 줄
// 람다와 비슷한 C언어 방식이 존재한다.
// TestFunc()에서 함수를 정의해주고 이름을 대신할 pfTest변수에 저장을 한다.
// 21번 줄에서 TestFunc()을 대신하는 pfTest에 값을 대입하는 방법이다.

// 물론 이런식으로 잘 쓰이지는 않는다.
// 그냥 쓰는 방법을 보여준 것일 뿐이다.