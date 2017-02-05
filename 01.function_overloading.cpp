#include <iostream>
using namespace std;

int Add(int a, int b)			// Add(int, int)
{
	cout << "Add(int, int) : ";
	return a + b;
}

int Add(int a, int b, int c)	// Add(int, int, int)
{
	cout << "Add(int, int, int) : ";
	return a + b + c;
}

double Add(double a, double b)	// Add(double, double)
{
	cout << "Add(double, double) : ";
	return a + b;
}

int main()
{
	cout << Add(1, 2) << endl;
	cout << Add(1, 2, 3) << endl;
	cout << Add(1.3, 2.5) << endl;
}

// 4, 10, 16번째 줄
// 함수의 이름이 같고 파라미터만 다르다.
// C에서는 같은 이름을 가진 함수는 허용되지 않는다.
// C++에서는 같은 이름을 가진 함수라고 하더라도 파라미터가 다르면 허용된다.
// 이를 '함수 오버로딩'이라고 한다.
//
// 함수 오버로딩은 반환형, 함수 이름은 영향을 주지 않고 파라미터의 갯수, 자료형만 영향을 준다.
// 만약 디폴트 파라미터랑 엮이면 모호성이 증가한다.
// 따라서 C++에서는 '함수 템플릿'을 권장한다.
// 자세한 내용은 '함수 템플릿'에서 설명