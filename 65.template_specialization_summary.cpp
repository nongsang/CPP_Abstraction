#include <iostream>

using namespace std;

template<class T>	    // A
class CTest				// 기본 템플릿 클래스, 함수처럼 오버로딩은 불가능
{
public:
	CTest(T param) { cout << "class<T>" << endl; }
};

template<class T>		// A - 1
class CTest<T*>			// A에서 포인터 형식에 대한 특수화
{
public:
	CTest(T* pparam) { cout << "class<T*>" << endl; }
};

template<>				// A - 2
class CTest<int>		// A에서 int타입에 대한 완전 특수화
{
public:
	CTest(int nparam) { cout << "class<int>" << endl; }
};

template<typename T>    // B
void TestFunc(T t)		// 기본 템플릿 함수, 가장 기본적이다.
{
	cout << "TestFunc(T)" << endl;
}

template<typename T>		// B - 1
void TestFunc(int i, T t)	// B의 오버로딩이다.	첫번째 인자를 int로 받는 부분 특수화. 클래스도 이런식으로 부분 특수화 가능
{
	cout << "TestFunc(int,T)" << endl;
}

template<typename T>	// B - 2
void TestFunc(T* t)		// 포인터 특수화, B의 오버로딩이다.
{
	cout << "TestFunc(T*)" << endl;
}

template<>					// C
void TestFunc<int>(int i)	// int형에 대한 완전 특수화
{
	cout << "TestFunc<int>(int)" << endl;
}

void TestFunc(double d)		// D. 그냥 일반 함수
{
	cout << "TestFunc(double)" << endl;
}

int main()
{
	bool b{ true };			// 항상 초기화를
	int i{ 0 };				// 생활화하자.
	double d{ 0.0 };		// 안하면 템플릿에서
	int* p{ nullptr };		// 오류 뿜뿜한다.

	//CTest<int*> a(i);		// int형과 int*가 맞지 않으므로 오류발생
	CTest<bool> B(b);	// A가 불린다. 가장 기본 템플릿 클래스이기 때문이다.
	CTest<int*> P(p);	// A - 1이 불린다. 포인터형 특수화를 해주었기 때문이다.
	CTest<int> I(i);	// A - 2가 불린다. int형 특수화를 해주었기 때문이다.

	TestFunc(b);		// B가 불린다. 가장 기본 템플릿 함수이기 때문이다.
	TestFunc(i, d);		// B - 1이 불린다. n과 d가 바뀌어도 불린다.
	TestFunc(p);		// B - 2가 불린다. &n으로 주소값을 보내도 불린다.
	TestFunc(i);		// C가 불린다. int형 완전 특수화를 정의해주었기 때문이다.
	TestFunc(d);		// D가 불린다. 기본 템플릿 함수가 존재해도 기본함수가 먼저 불린다.
}

// 5 ~ 10번 줄
// 기본 템플릿 클래스이다.
// 함수처럼 오버로딩 하는 것은 불가능하다.
// A로 정의

// 12 ~ 17번 줄
// 포인터 형식에 대한 특수화 클래스이다.
// A - 1로 정의

// 19 ~ 24번 줄
// int형에 대한 완전 특수화 클래스이다.
// A - 2로 정의

// 24 ~ 30번 줄
// 기본 템플릿 함수이다.
// 함수는 오버로딩이 가능하다.
// B로 정의

// 32 ~ 36번 줄
// 첫번째 파라미터를 int로 받는 부분 특수화 함수이다.
// 클래스도 이런식으로 부분 특수화가 가능하다.
// B - 1로 정의

// 38 ~ 42번 줄
// 포인터 형식에 대한 특수화 함수이다.
// B - 2로 정의

// 44 ~ 48번 줄
// int형에 대한 완전 특수화 함수이다.
// 명시적으로 int가 들어오면 호출되게 정의한 것이다.
// C로 정의

// 50 ~ 53번 줄
// double형에 대한 일반 함수이다.
// D로 정의

// 57 ~ 60번 줄
// 각 자료형 변수들을 생성하였다.
// 템플릿을 쓰려면 초기화를 하자.
// 오류 뿜뿜함.

// 62번 줄
// 템플릿을 쓸 때 자료형을 명시해줘야 한다.
// 하지만 인자의 자료형과 다르면 안된다.

// 63번 줄
// bool에 대한 클래스 특수화를 정의하지 않았다.
// 그러므로 A가 불린다.

// 64번 줄
// 포인터에 대한 클래스 특수화를 정의해주었다.
// 그러므로 A - 1이 불린다.

// 65번 줄
// int형에 대한 특수화를 정의해주었다.
// 그러므로 A - 2가 불린다.

// 67 ~ 70번 줄
// 클래스와 같은 매커니즘으로 설명가능

// 71번 줄
// double형으로 받는 일반 함수이다.
// 기본 템플릿 함수가 존재함에도 일반 함수가 호출된다.

// 여기서 알 수 있는 것
// 호출 순서는 일반함수 > 특수화 템플릿 함수 > 가장 비슷한 함수 > 기본 템플릿 함수 이다.

// 헷깔리는데 꼭 이렇게 해야하나?
// 특수화할 바에 일반함수 쓰는게 낫지 않나?
// 66.reason_do_not_template_specialization에서 한번 알아보자.