#include <iostream>

using namespace std;

void TestFunc(int rParam)			// int형 파라미터를 가진 함수
{
	cout << "TestFunc(int)" << endl;
}

void TestFunc(int& rParam)			// 참조형 파라미터를 가진 함수
{
	cout << "TestFunc(int&)" << endl;
}

void TestFunc(int&& rParam)			// r-value 참조형 파라미터를 가진 함수
{
	cout << "TestFunc(int&&)" << endl;
}

int main()
{
	int x = 3;
	TestFunc(4);		// 상수를 인자로 전달
	TestFunc(x);		// 변수를 인자로 전달
	TestFunc(3 + 4);	// 상수의 합을...?
	TestFunc(x + 3);	// 변수 + 상수?
}

// 5, 10, 15번째 줄
// 참조형 파라미터를 가진 함수와 r-value 참조형 파라미터를 가진 함수를 오버로딩하였다.
// 차이는 꽤 난다.

// 23번째 줄
// 상수를 인자로 전달하고 있다.
// TestFunc(int), TestFunc(int&&) 함수가 호출된다.
//
// 참조형 파라미터를 가진 변수는 상수를 받을 수 없기 때문이다.
// 5번째 줄 int rParam = 4는 상수를 변수에 저장하기 때문에 호출이 된다.
// 15번째 줄 int&& rParam = 4는 상수인 4가 임시변수 곧, r-value를 생성하여 전달하기 때문에 호출이 된다.
//
// 참조형의 경우 임시변수처럼 곧 사라질 변수를 참조할 수 없게 설계(?)하였다.

// 24번째 줄
// TestFunc(int), TestFunc(int&) 함수가 호출되다.
// 10번째 줄 int& rParam = x는 실체를 가진 변수 x를 참조하는 연산을 하기 때문이다.

// 25번째 줄
// TestFunc(int), TestFunc(int&&) 함수를 호출한다.
// 상수끼리의 합을 한 결과를 임시변수를 생성(r-value)하고 저장하여 인자를 전달하기 때문이다.

// 26번째 줄
// TestFunc(int), TestFunc(int&&) 함수를 호출한다.
// 이 또한 변수와 상수의 합한 결과를 임시변수(r-value)에 저장하고 인자를 전달한다.

// 여기서 알 수 있는것은 int형은 상수, 변수 모두 받을수 있고
// 참조형 변수는 변수만,
// r-value 참조형 변수는 임시변수인 r-value를 참조받는다.
// r-value는 상수라고 생각해도 될거 같다.