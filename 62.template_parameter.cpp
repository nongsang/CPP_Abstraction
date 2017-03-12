#include <iostream>
using namespace std;

template <typename T, int nSize>		// 템플릿 매개변수
// template <typename T = int, int nSize = 3>		// 디폴트 값을 지정해줄 수 있다. 디폴트 매개변수처럼
class CArray
{
	T *m_pData{ nullptr };
public:
	CArray() { m_pData = new T[nSize]; }
	~CArray() { delete[] m_pData; }

	T& operator[](int nIndex)
	{
		if (nIndex < 0 || nIndex >= nSize)
		{
			cout << "ERROR : 배열의 경계를 벗어난 접근입니다." << endl;
			exit(1);
		}
		return m_pData[nIndex];
	}

	T& operator[](int nIndex) const { return operator[](nIndex); }

	int GetSize() const { return nSize; }
};

int main()
{
	CArray<int, 3> arr;
	//CArray<> arr;		// 디폴트 템플릿을 사용한다면 사용가능

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;

	/*for (auto &n : arr)		// 범위기반 루프는 불가능
		cout << n << endl;*/

	for (int i = 0; i < 3; ++i)
		cout << arr[i] << endl;
}

// 4번 줄
// 템플릿 매개변수가 2개이다.
// 여기서 알 수 있는 것이 있다.
// typename은 자료형이 정해져있지 않고 원하는 대로 바꿀 수 있는 키워드로 사용할 수 있다.

// 9번 줄
// nSize만큼 행렬 형대로 동적할당한다.
// 여기서 또 알 수 있는 것.
// 템플릿 매개변수는 클래스 템플릿 내부에서 모두 접근할 수 있다.

// 29번 줄
// 템플릿으로 선언했으므로 자료형을 명시해야 한다.
// 게다가 템플릿으로 int형 변수를 선언하였으므로 같이 정수를 입력해야 한다.
// CArray<int> arr(5);와 같은 저번 코드와는 다르다.

// 31 ~ 33번 줄
// 배열 요소 하나하나에 값을 집어 넣는다.
// 여기서 배열연산자가 불린다.

// 35, 36번 줄
// 범위기반 루프는 여기서 사용할 수 없다.
// 반복자를 찾을 수 없어서인듯?
// STL 아니면 잘 사용하고 있는 배열을 사용한다면 쓸 수 있다.
// 아니면 내가 직접 begin을 정의해줘야 하나?

// 40, 41번 줄
// 반복해서 배열값을 출력한다.
// 여기서 상수형 배열연산자가 호출된다.

// 5번 줄
// 디폴트 매개변수처럼 템플릿 매개변수도 디폴트로 정할 수 있다.

// 31번 줄
// 템플릿 매개변수를 디폴트로 정한다면 사용할 수 있다.
// 디폴트로 값을 정해주었으니까.