#include <iostream>

using namespace std;

int main()
{
	int a = 100, b;
	cout << "Input number : ";
	cin >> b;

	try		// 오류없이 실행하고픈 문장들을 집어넣는다.
	{
		if (0 == b)			// b가 0이면
			throw b;		// 예외처리를 위해 catch로 던져라
		else				// b가 0이 아니라면 
			cout << a / b << endl;	// 100을 입력값으로 나눠라
	}
	
	catch (int nExp)		// throw로 받은 예외값을 받아서 처리
	{
		cout << "ERROR : " << nExp << "으로 나눌 수 없습니다." << endl;
	}
}

// 100을 입력값으로 나누는 프로그램이다.

// 11번 줄
// try로 오류없이 실행하고싶은 문장들을 집어넣는다.

// 14번 줄
// 만약 입력값이 0이라면 catch쪽으로 바로 던져버리고 catch문을 바로 실행해버린다.
// goto구문이랑 비슷하다고 보면 된다.

// 19번 줄
// throw로 예외가 발생한 것을 '던진 것'을 '받아서' 처리한다.

// if ~ else문으로 예외처리처럼 해줄 수 있다.
// 하지만 if ~ else만 남발해서 오류체크를 하면 매우 더러워보인다.
// 오류체크를 많이 하는게 아니라면 if ~ else가 유용하지만 많이 한다면 예외처리를 잘 사용하자.