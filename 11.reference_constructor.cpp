#include <iostream>

using namespace std;

class CRefTest
{
	int& num;		// 참조형으로 private 선언
public:
	CRefTest(int& n) : num(n) { }	// 이부분 잘 봐야함	// CRefTest(int n) : num(n) { }은 안됨
	int Getter() { return num; }
};

int main()
{
	int a = 10;
	CRefTest t(a);	// 변수를 전달하여 참조형 사용
	
	cout << t.Getter() << endl;

	a = 20;			// 변수만 수정

	cout << t.Getter() << endl;
}

// 7번째 줄
// 참조형으로 변수를 선언하였다.

// 9번째 줄
// 생성자의 파라미터를 참조형으로 받았다.
// 거기다 멤버 이니셜라이저를 이용하여 num = n 연산을 하였다.
// 만약 CRefTest(int& n) { num = n }; 처럼 함수를 정의 하였다면 컴파일 오류를 뿜어낸다.
// 왜냐하면 참조형 int인 num이 선언되고 후에 num = n; 연산이 되기 때문
// 참조형 변수는 생성과 동시에 초기화 해야만 하며, 생성 후 할당은 당연이 성립이 되지 않기 때문이다.
//
// 참고
// CRefTest(int n) : num(n) { } 으로 파라미터가 단순 변수이면 안된다.
// 왜냐하면 입력받는 변수 n의 원본이 사라지기 때문이다.
// 무슨 말이냐 하면 n에 입력 받고, 입력 받은 값을 num에 저장하는 역할을 하는 생성자 함수가 역할을 끝내면
// int형인 n은 스택에서 제거되기 때문에 원본이 소멸하면서 제대로된 값이 나오지 않는다.

// 16번째 줄
// 참조형으로 사용하기 위해 변수를 클래스로 전달

// 20번째 줄
// int형 변수인 a만 수정했음에도 참조형으로 전달된 num의 값도 변함을 알 수 있다.