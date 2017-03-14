#include <iostream>

using namespace std;

class CTest
{
	int* m_pnData{ nullptr };
public:
	explicit CTest(int nParam)
	{
		cout << "변환 생성자" << endl;
		m_pnData = new int(nParam);
	}

	~CTest()
	{
		cout << "소멸자" << endl;
		if (m_pnData != nullptr)
			delete[] m_pnData;

		m_pnData = nullptr;
	}

	operator int()
	{
		cout << "형변환 연산자" << endl;
		return *m_pnData;
	}

	CTest& operator=(const CTest& rhs)
	{
		cout << "단순 대입 연산자" << endl;
		if (this == &rhs)
		{
			cout << "대입하지 않음" << endl;
			return *this;
		}

		if (m_pnData != nullptr)
			delete[] m_pnData;

		m_pnData = new int(*rhs.m_pnData);
		return *this;
	}

	CTest& operator+=(const CTest& rhs)
	{
		cout << "복합 대입 연산자" << endl;

		int *pnNewData = new int(*m_pnData);	// 이건 좀 헷깔릴만 하다.

		*pnNewData += *rhs.m_pnData;

		if (m_pnData != nullptr)
			delete[] m_pnData;		// 기존에 동적할당된 메모리 해제

		m_pnData = pnNewData;	// 동적할당 된 위치를 새로운 변수로 설정

		//*m_npData += *rhs.m_npData;		// 이것만 있어도 가능한거같은데? 이건 교수님께 여쭤볼까?

		return *this;
	}

	int operator==(const CTest& rhs)
	{
		if (m_pnData != nullptr && rhs.m_pnData != nullptr)
			if (*m_pnData == *rhs.m_pnData)
				return 1;

		return 0;
	}

	int operator!=(const CTest& rhs)
	{
		if (m_pnData != nullptr && rhs.m_pnData != nullptr)
			if (*m_pnData != *rhs.m_pnData)
				return 1;

		return 0;
	}
};

int main()
{
	CTest a(3), b(3), c(4);

	if (a == b)
		cout << "same" << endl;
	if (a != c)
		cout << "different" << endl;
}

// 64 ~ 71번 줄
// operator==()을 오버로딩 하였다.
// 클래스의 값이 있는지 확인한 후 값을 비교한다.
// 값이 같으면 1 반환, 다르면 0 반환

// 73 ~ 80번 줄
// operator!=()을 오버로딩 하였다.
// 마찬가지로 클래스의 값이 있는지 확인한 후 값을 비교한다.
// 값이 같으면 0 반환, 다르면 1 반환

// 두 함수의 반환형으로 bool을 써도 될 것 같은데, 원래는 int형이란다.
// 알아서 잘 쓰자.