#include <iostream>

using namespace std;

class Add
{
public:
	int operator()(int a, int b)
	{
		cout << "()(int a, int b)" << endl;
		return a + b;
	}

	double operator() (double a, double b)
	{
		cout << "()(double a, double b)" << endl;
		return a + b;
	}
};

void TestFunc(Add &add)				// 클래스를 파라미터로 가진 함수다.
{
	cout << "TestFunc()" << endl;
	cout << add(3, 4) << endl;
}

int main()
{	
	Add adder;

	cout << adder(3, 4) << endl;		// 별로 대단하진 않네
	cout << adder(3.3, 4.4) << endl;	// 이것도
	TestFunc(adder);				// 이게 함수객체
}

// 21 ~ 25번 줄
// 클래스를 파라미터로 받는 함수다.
// 그리고 클래스의 멤버함수를 호출한다.
// 중요하니 기억해두도록

// 31, 32번 줄
// 클래스 객체를 생성하여 오버로딩된 멤버함수를 사용한다.

// 33번 줄
// 여기서 함수 객체(Functor)라고 부른다.
// 함수로 객체를 전달하여 객체의 멤버함수를 호출하는 방식이다.
// 한마디로 기능에 맞는 함수를 정의하되 함수 내에서 객체의 기능을 빼내서 구현하는 것이다.