#include <iostream>

using namespace std;

void ExceptTest1()			// try 내에서 사용할 함수
{
	int nInput;
	cout << "1 ~ 10 양의 정수 입력 : ";
	cin >> nInput;

	if (nInput < 1 || nInput > 10)
		throw nInput;		// 예외처리
}

void ExceptTest2()			// 이것도 try 내에서 사용할 것이다.
{
	char ch;
	cout << "Menu : [A]dd\t[D]elete\t[E}xit" << endl;
	cin >> ch;
	if ('A' != ch && 'D' != ch && 'E' != ch)
		throw ch;			// 예외처리
}

int main()
{
	try
	{
		ExceptTest1();		// 함수만 돌린다.
		ExceptTest2();		// 이것도
	}

	catch (int nExp)		// 예외처리를 다중화하였다.
	{
		cout << "ERROR : " << nExp << "은 범위를 벗어난 숫자입니다." << endl;
	}

	catch (char cExp)		// 이것도 마찬가지
	{
		cout << "ERROR : " << cExp << "알 수 없는 메뉴입니다." << endl;
	}

	/*catch (...)
	{
		cout << "ERROR" << endl;
		try
		{
			// 테스트 문장
		}

		catch(...)
		{
			// 예외처리
		}
	}*/
}

// 5 ~ 13번 줄
// 첫번째 함수를 정의하였다.
// 범위를 벗어나면 catch로 값을 던져버린다.

// 15 ~ 22번 줄
// 두번째 함수를 정의하였다.
// 맞는 문자가 아니라면 catch로 값을 던져버린다.

// 26 ~ 30번 줄
// try 내에서 함수만 호출한다.

// 32 ~ 40번 줄
// 예외값에 따라서 오버로딩된 catch가 호출이 된다.
// 첫번째 함수에서는 int형을 던지므로 int형으로 정의된 catch가 호출이되고,
// 두번째 함수에서는 char형을 던지므로 char형으로 정의된 catch가 호출이된다.

// 42 ~ 54번 줄
// catch(...)를 사용하면 던지는 변수의 자료형에 구애받지 않고 던진 것을 받아서 처리한다.
// 예외처리의 템플릿과 같은 형식이다.
// C언어에서도 사용가능하니 알아두자.
// 게다가 catch로 받은 값으로 try를 사용하여 다른것을 테스트해볼 수 있다.
// 이런 중첩된 예외처리코드는 나중에 자주 사용하니 잘 기억해두자.