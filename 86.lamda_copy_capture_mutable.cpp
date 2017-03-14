#include <iostream>

using namespace std;

int main()
{
	int nData{ 10 };
	cout << nData << endl;

	auto TestFunc = [nData](void) mutable -> void		// 복사 캡쳐임에도 값 변경 가능
	{
		cout << ++nData << endl;	// 캡쳐값 변경
	};

	TestFunc();
	cout << nData << endl;		// 원래대로?
}

// 10번 줄
// 복사캡쳐는 const를 사용한 것처럼 값의 참조만 가능하고 변경은 불가능하다.
// 하지만 mutable을 사용하여 복사캡쳐임에도 값의 변경이 가능하다.
// mutable은 17.constant_method_exception에서 처음 나오므로 한번 보도록

// 12번 줄
// 복사캡쳐한 변수의 값을 ++연산하고 출력하였다.
// nData가 10이었으므로 11이 출력된다.

// 16번 줄
// 람다식 내에서 값을 변경했지만 다시 원래대로 10으로 돌아왔다.
// 이를 미루어 보아 복사캡쳐를 사용한 값의 변경은 람다식 내에서만 유지된다는 것을 알 수 있다.