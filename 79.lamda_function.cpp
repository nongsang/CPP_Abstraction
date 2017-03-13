#include <iostream>
#include <functional>	// 이걸?

using namespace std;

int TestFunc(char* pszParam, function<int(char*,int)> param)	// 흠?
{
	cout << pszParam << endl;
	return param("Hello", 10);		// 매개변수로 값을 넘긴다?
}

int main()
{
	cout << "main() 시작" << endl;
	TestFunc("TestFunc()",
		[](char *pszParam, int nParam)->int
	{
		cout << pszParam << " : " << nParam << endl;
		return 0;
	}
	);

	cout << "main() 끝" << endl;
}

// 2번 줄
// std::function를 사용하기 위한 라이브러리

// 6번 줄
// std::function<int (char*, int)> param 까지가 매개변수다.
// 당황스럽지만 진짜다.
// std::function은 어떤 함수라도 매개변수로 받을 수 있는 클래스 템플릿이다.
// <int (char*, int)> 에서 첫번째 int는 함수의 반환형을 나타낸다.
// ()안은 매개변수 목록이다.

// 9번 줄
// 매개변수로 값을 반환해주고 있다.

// 15 ~ 21번 줄
// TestFunc()안의 매개변수를 람다로 정의해주고 있다.
// 거기다 값을 집어넣는게 아니고 그냥 출력만 해주고 있다.
// 9번 줄에서 함수로 쓰인 매개변수에 값을 반환해주는 것으로 값을 집어넣는다.