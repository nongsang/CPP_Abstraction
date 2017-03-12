#include <iostream>
#include <memory>
using namespace std;

template<typename T>
T Add(T a, T b) { return a + b; }

template<>			// 템플릿 특수화
char* Add(char* pszLeft, char* pszRight)		// 템플릿 특수화를 사용하기 위한 조건
{
	int nLenLeft = strlen(pszLeft);
	int nLenRight = strlen(pszRight);
	char* pszResult = new char[nLenLeft + nLenRight + 1];

	strcpy_s(pszResult, nLenLeft + 1, pszLeft);		// 이거 중요함
	strcpy_s(pszResult + nLenLeft, nLenRight + 1, pszRight);	// 이것도

	return pszResult;
}

int main()
{
	int nResult = Add<int>(3, 4);
	cout << nResult << endl;

	char* pszResult = Add<char*>("Hello", "World");
	cout << pszResult << endl;
	delete[] pszResult;
}

// 8번 줄
// 템플릿을 사용하되 아무것도 선언을 안했다.
// template<typename T>이라고 사용해도 상관없다.
// 그냥 템플릿 특수화를 강조하기위해서 template<>라고 사용하는편이 많다.

// 9 ~ 19번 줄
// 템플릿 특수화를 사용한 함수 정의
// 여기서 함수의 시작 부분을 유의하자.
// 선행되어야 하는 것은 8번 줄처럼 템플릿 선언이 되어야 한다.
// 그 후에 함수의 이름은 템플릿 함수와 같으며 반환형, 파라미터의 자료형이 모두 char*형으로 통일이 되어야 템플릿 특수화를 사용할 수 있다.
// 그렇지 않다면 템플릿 특수화로 인식하지 않는다.
// 단순히 이름이 같은 함수로 인식하므로 오류를 뿜어낸다.
//
// 상수형인 문자열끼리 더하는 방법이다.
// 1. 각 파라미터로 받은 문자열의 크기를 구한다.
// 2. 파라미터로 받은 문자열의 크기의 합 + 1만큼 힙에 동적할당한다.
// 3. 동적할당한 곳에 첫번째 문자열 크기 + 1만큼 넣는다. -> 이유는 \0도 들어가므로 딱 첫 문자열만큼만 들어간다.
// 4. 동적할당한 곳에서 시작하여 첫번째 문자열의 끝 위치로 이동한다.
// 5. 두번째 문자열 크기 + 1만큼 넣는다.
// 6. 마지막에는 \0이 삽입되어 종료