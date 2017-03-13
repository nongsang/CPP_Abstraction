#include <iostream>

using namespace std;

void TestFunc1()
{
	cout << "TestFunc1 시작" << endl;
	//throw 0;
	cout << "TestFunc1 끝" << endl;
}

void TestFunc2()
{
	cout << "TestFunc2 시작" << endl;
	TestFunc1();
	cout << "TestFunc2 끝" << endl;
}

void TestFunc3()
{
	cout << "TestFunc3 시작" << endl;
	TestFunc2();
	cout << "TestFunc3 끝" << endl;
}

int main()
{
	try
	{
		TestFunc3();
	}

	catch (...)
	{
		cout << "Exception handling" << endl;
	}
}

// 5 ~ 24번 줄
// 함수를 호출하여 스택에 하나씩 쌓는다.
// 하지만 함수를 반환하려면 차례차례 반환하게끔 프로그래밍해야 한다.
// TestFunc3부터 시작해서 TestFunc1까지 차례로 함수에서 호출하는 함수들이다.
// 연쇄적으로 함수내에서 함수를 호출하는 방식으로 진행된다.
// 이대로 보면 후입선출이 잘 진행되는 것처럼 보인다.

// 8번 줄
// 0을 던진다.
// 만약 0을 던지게 되면 catch는 모든 자료형을 받게끔 되어있으므로 TestFunc1()에서 예외처리가 발생한다.
// 예외처리가 되면 프로그램을 곧바로 종료된다.
// 그럼 함수반환이 제대로 이루어진게 아닌가 하지만 제대로 반환이 된다.
// main()은 스택에 남아있고 연결된 TestFunc3()부터 TestFunc1()까지 반환이 된다.
// 한마디로 TestFunc3()가 호출되기 전으로 '되돌려진다'라고 표현하는게 적절하겠다.
// 이를 '스택 풀기'라고 한다.

// 이처럼 구조적 예외처리를 이용하면 스택은 자동으로 풀리고 코드도 간결해진다.