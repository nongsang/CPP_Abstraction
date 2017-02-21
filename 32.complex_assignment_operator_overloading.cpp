#include <iostream>

using namespace std;

class CTest
{
	int* m_npData{ nullptr };
public:
	explicit CTest(int nParam)
	{
		cout << "변환 생성자" << endl;
		m_npData = new int(nParam);
	}

	~CTest()
	{
		cout << "소멸자" << endl;
		if (m_npData != nullptr)
			delete[] m_npData;

		m_npData = nullptr;
	}

	operator int()
	{
		cout << "형변환 연산자" << endl;
		return *m_npData;
	}

	CTest& operator=(const CTest& rhs)
	{
		cout << "단순 대입 연산자" << endl;
		if (this == &rhs)
		{
			cout << "대입하지 않음" << endl;
			return *this;
		}

		if (m_npData != nullptr)
			delete[] m_npData;

		m_npData = new int(*rhs.m_npData);
		return *this;
	}

	CTest& operator+=(const CTest& rhs)
	{
		cout << "복합 대입 연산자" << endl;

		int *pnNewData = new int(*m_npData);	// 이건 좀 헷깔릴만 하다.

		*pnNewData += *rhs.m_npData;

		if (m_npData != nullptr)
			delete[] m_npData;		// 기존에 동적할당된 메모리 해제

		m_npData = pnNewData;	// 동적할당 된 위치를 새로운 변수로 설정

		//*m_npData += *rhs.m_npData;		// 이것만 있어도 가능한거같은데? 이건 교수님께 여쭤볼까?

		return *this;
	}
};

int main()
{
	CTest a(0), b(3), c(4);

	a += b;

	cout << a << endl;

	a += c;

	cout << a << endl;
}

// 46번째 줄
// 복합 대입 연산자를 정의해주었다.

// 50번째 줄
// 새로운 변수를 동적할당한다.
// 동적할당하면 힙에 생기는데 스택에서 연산한다음 동적할당하면 안됨?
// 참조할 객체가 이미 동적할당이 되어 있다.
// 그렇기 때문에 굳이 스택에서 연산할 이유가 없다.

// 52번째 줄
// 값을 더하고 원래 데이터에 저장한다.

// 54, 55번째 줄
// 기존에 있던 동적 할당된 데이터가 있다면 메모리 해제한다.
// 왜냐하면 힙 메모리에 올려져 있는 pnNewData의 위치를 객체의 위치로 설정하기 위해서다.

// 57번째 줄
// 동적할당된 위치를 새롭게 동적할당하고 값을 대입한 변수의 주소값을 대입하여 사용하기 위함이다.

// 59번째 줄
// 지금까지 별짓을 다했는데 이거 한줄이면 복합 대입 연산자는 다 정의가 된거 아닌가?
// 그냥 기존에 있던 데이터에 참조한 데이터를 누적해서 저장한다는 뜻인데?
// 굳이 이렇게 정의할 이유가 있나 싶다.
// 교수님께 여쭤보자

// 69, 73번째 줄
// 복합 대입 연산자를 정의하여 실행해 보았다.
// 59번째 줄만 있어도 문제없이 돌아간다.
// 내부적으로 문제가 있는지 교수님께 여쭤보자.