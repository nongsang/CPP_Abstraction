#include <iostream>

using namespace std;

int main()
{
	int nData{ 10 };
	cout << nData << endl;

	auto TestFunc = [nData](void) -> void		// 람다 캡쳐
	{
		cout << nData << endl;
	};

	TestFunc();
}

// 10번 줄
// 람다캡쳐 방식이다.
// ()가 없어지고 람다를 사용하여 써주고 있다.
// auto형으로 사용해주었는데 실제 자료형은 function<void(void)>형이다.
// function<void()>로 써줘도 된다.
// 사용법은 4가지가 있다.
// 1. auto TestFunc = [nData](void) -> void	처럼 모두 기술하는 방법
// 2. auto TestFunc = [nData](void)	처럼 반환형이 없으면 반환형만 생략
// 3. auto TestFunc = [nData]()	처럼 반환형도 없고 파라미터도 없으면 둘다 생략
// 4. auto TestFunc = [nData] 처럼 3에서 다 없으면 그냥 변수만 써주는 방법

// 캡쳐 종류는 4가지가 있다.
// 1. [nData](void)->void처럼 사용하는 복사캡쳐
// 2. [&nData](void)->void처럼 사용하는 참조캡쳐
// 3. [=](void)->void처럼 사용하는 디폴트 복사캡쳐
// 4. [&](void)->void처럼 사용하는 디폴트 참조캡쳐

// 복사캡쳐의 경우는 외부의 변수를 복사하여 함수내에서만 값을 읽을 수 있으며 변경할 수 없다.
// const를 사용한 것처럼 작동하는 것.

// 참조캡쳐의 경우는 외부의 변수를 참조하여 함수내에서만 값을 읽을 수 있으며 변경도 가능하다.
// 물론 외부에 있는 변수의 값도 변경된다.