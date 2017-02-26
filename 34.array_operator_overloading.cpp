#include <iostream>

using namespace std;

class CArray
{
	int *m_npData;		// 배열 메모리
	int m_nSize;		// 배열 요소 갯수
public:
	CArray(int nSize)
	{
		cout << "배열 생성자" << endl;
		m_npData = new int[nSize];			// nSize 갯수만큼 배열 형태로 동적할당
		memset(m_npData, 0, sizeof(int) * nSize);	// 동적할당한 메모리를 0으로 int크기의 nSize 갯수만큼 값 할당
	}

	~CArray()
	{
		cout << "소멸자" << endl;
		if(nullptr != m_npData)
			delete[] m_npData;
	}

	int operator[](int nIndex) const		// 출력할때 불림
	{
		cout << "참조 배열 연산자" << endl;
		return m_npData[nIndex];
	}

	int& operator[](int nIndex)			// 값을 대입할 때 불림
	{
		cout << "일반 배열 연산자" << endl;
		return m_npData[nIndex];
	}
};

void TestFunc(const CArray& arParam)
{
	cout << "TestFunc() 시작" << endl;

	cout << arParam[3] << endl;

	cout << "TestFunc() 끝" << endl;
}

int main()
{
	cout << "main() 시작" << endl;

	CArray arr(5);
	const CArray& a = arr;

	for (int i = 0; i < 5; ++i)
		arr[i] = i * 10;

	cout << a[3] << endl;

	TestFunc(arr);

	cout << "main() 끝" << endl;
}

// 7번 줄
// 배열형식으로 힙에 동적할당을 위한 포인터 변수

// 8번 줄
// 배열의 요소 갯수를 담는 변수

// 13번 줄
// nSize만큼 배열형태로 동적할당

// 14번 줄
// 동적할당된 메모리를 int크기의 메모리 갯수만큼을 0으로 저장한다.

// 24 ~ 28번 줄
// 참조 배열 연산자를 정의해주었다.
// 여기서 중요한건 const이다.
// const를 사용하여 호출하면 이 배열 연산이 호출된다.
// 한마디로 r-value, 곧 상수형으로 불리면 호출된다는 것.
// 이를 잘 보여주는게 37, 41, 51, 58번 줄이다.

// 30 ~ 34번 줄
// 일반적으로 배열 연산이 불릴경우 호출된다.
// 이를 보여주는게 54번 줄

// 50번 줄
// 배열형태로 생성자가 불리게 된다.

// 51번 줄
// const로 상수형태로 만든 참조형 변수를 만들었다.
// 나중에 쓰이므로 기억해두도록

// 54번 줄
// 50번 줄에서 선언한 일반 배열 형태인 arr가 불렸으므로 일반 배열 연산자가 불리게 된다.
// 게다가 값을 변경할 수 있으므로 더 확실하다.

// 56번 줄
// 51번 줄에서 const로 불린 a가 불렸다.
// 그러므로 참조 배열 연산자가 불리게 된다.
// 참조형일 뿐이므로 배열의 값을 가져온다.

// 58번 줄
// 37 ~ 44번 줄에서 정의한 함수를 호출한다.
// 함수의 파라미터는 const형 참조 변수이다.
// 여기서도 56번 줄과 같이 상수형태로 호출이 되었으므로 참조 배열 연산자가 호출된다.