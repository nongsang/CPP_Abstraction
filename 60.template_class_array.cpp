#include <iostream>
using namespace std;

template<typename T>
class CMyArray
{
private:
	T *m_pData = nullptr;
	int m_nSize = 0;
public:
	explicit CMyArray(int nSize) : m_nSize(nSize)
	{
		m_pData = new T[nSize];		// 템플릿의 자료형을 정해주면 그 크기만큼 배열로 생성
	}

	~CMyArray() { delete[] m_pData; }

	CMyArray(const CMyArray &rhs)			// 깊은 복사
	{
		m_pData = new T[rhs.m_nSize];			// 힙에 생성하고
		memcpy(m_pData, rhs.m_pData, sizeof(T)* rhs.m_nSize);	// 데이터 복사
		m_nSize = rhs.m_nSize;		// 크기도 복사함
	}

	CMyArray& operator=(const CMyArray &rhs)	// 대입 연산자
	{
		if (this == &rhs)		// 자기 자신을 대입하면 아무것도 안함
			return *this;

		if(nullptr != m_pData)
			delete[] m_pData;			// 기존의 데이터는 삭제
		m_pData = new T[rhs.m_nSize];	// 새롭게 동적할당
		memcpy(m_pData, rhs.m_pData, sizeof(T)* rhs.m_nSize);		// 데이터 복사
		m_nSize = rhs.m_nSize;		// 크기도 복사

		return *this;
	}

	CMyArray(CMyArray &&rhs)	// 이동 생성자
	{
		operator = (rhs);	// 이동 생성자를 더 쉽게 정의할 수 있다.
	}

	CMyArray& operator=(const CMyArray &&rhs)		// 이동 대입 연산자
	{
		m_pData = rhs.m_pData;		// 이동 대입이니 얕은 복사로 해준다.
		m_nSize = rhs.m_nSize;		// 이것은 어차피 얕은 복사
		rhs.m_pData = nullptr;		// 참조할 것은 안쓰니 nullptr로
		rhs.m_nSize = 0;			// 사이즈는 0
	}

	T& operator[](int nIndex)		// 배열 연산자, 값을 대입할 때 불린다.
	{
		if (nIndex < 0 || nIndex >= m_nSize)
		{
			cout << "ERROR: 배열의 경계를 벗어난 접근입니다." << endl;
			exit(1);
		}

		return m_pData[nIndex];
	}

	T& operator[](int nIndex) const			// 상수화된 배열 연산자, 값을 출력할 때 불린다.
	{
		return operator[](nIndex);
	}

	int GetSize() { return m_nSize; }	// 배열 요소의 개수를 반환
};

int main()
{
	CMyArray<int> arr(5);		// 크기가 5

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;

	for (int i = 0; i < 5; ++i)
		cout << arr[i] << ' ';

	cout << endl;

	CMyArray<int> arr2(3);		// 크기가 3
	arr2 = arr;				// 여기서 중요
	for (int i = 0; i < 5; ++i)
		cout << arr2[i] << ' ';

	cout << endl;

	return 0;
}

// 배열 형태로 데이터를 관리하는 템플릿 클래스 배열이다.

// 기본적으로 오버로딩은 한번씩 해봤던 것들이다.
// 템플릿으로 클래스를 정의하고 배열형태로 만들어줬을 뿐

// 87번 줄
// 여기가 가장 중요한 부분이다.
// arr는 크기가 5, arr2는 크기가 3이다.
// 그런데 크기가 3인 arr2에 크기가 5인 arr를 복사 저장한다?
// 말도 안되지만 여기서는 가능하다.

// 25 ~ 37번 줄
// 대입연산자에서 기존에 있던 데이터를 삭제한다.
// 그리도 대입하는 배열의 크기만큼 새롭데 동적할당한다.
// 여기서 크기가 다른 배열끼리 연산이 가능한 것이다.