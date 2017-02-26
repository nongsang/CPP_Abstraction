#include <iostream>

using namespace std;

class CTest
{
	int* m_npData{ nullptr };		// 동적할당하기 위해서 int*형으로 해놨다.
public:
	explicit CTest(int nParam)
	{
		cout << "변환 생성자" << endl;
		m_npData = new int(nParam);
	}

	~CTest()
	{
		cout << "소멸자" << endl;
		if (nullptr != m_npData)
			delete[] m_npData;
	}

	operator int()
	{
		cout << "형변환 연산자" << endl;
		return *m_npData;
	}

	CTest(const CTest& rhs)// : m_nData(rhs.m_nData)	// 저번에 쓰던 복사 생성자
	{
		cout << "복사 생성자" << endl;
		m_npData = new int(*rhs.m_npData);		// 저번에 쓰던 복사 생성자와는 다르네?
	}

	CTest operator+(const CTest& rhs)		// 덧셈 연산자 정의
	{
		/*CTest result(0);
		result.m_nData = this->m_nData + rhs.m_nData;	// 이전에 쓰던 덧셈 연산자 정의
		return result;*/

		cout << "덧셈 연산자" << endl;
		return CTest(*m_npData + *rhs.m_npData);		// 이것도 전에 쓰던거랑 다르네
	}

	CTest& operator=(const CTest& rhs)
	{
		cout << "단순 대입 연산자" << endl;
		if (this == &rhs)
		{
			cout << "대입하지 않음" << endl;
			return *this;
		}

		if (nullptr != m_npData)
			delete[] m_npData;

		m_npData = new int(*rhs.m_npData);
		return *this;
	}

	CTest& operator+=(const CTest& rhs)
	{
		cout << "복합 대입 연산자" << endl;
		int *pnNewData = new int(*m_npData);

		*pnNewData += *rhs.m_npData;

		if (nullptr != m_npData)
			delete[] m_npData;

		m_npData = pnNewData;

		//*m_npData += *rhs.m_npData;		// 이것만 있어도 가능한거같은데? 이건 교수님께 여쭤볼까?

		return *this;
	}

	CTest& operator=(CTest&& rhs)
	//CTest(const CTest&& rhs) : m_nData(rhs.m_nData)		// 전에 쓰던 이동 대입 연산자
	{
		cout << "이동 대입 연산자" << endl;

		m_npData = rhs.m_npData;		// rhs.m_npData의 주소값을 얕은 복사 후에
		rhs.m_npData = nullptr;			// 참조 객체의 주소값을 쓰지 못하게

		return *this;
	}
};

int main()
{
	CTest a(0), b(3), c(4);

	a = b + c;		// 임시객체가 생성되는데?

	cout << a << endl;

	a = b;			// 이건 임시객체 없음

	cout << a << endl;
}

// 동적할당하기 위해서 int*로 선언했다.
// 이것 하나로 목적과 오버로딩 함수 구조가 어떻게 바뀌는지 알아보자

// 28 ~ 32번째 줄
// 복사 생성자를 정의해주었다.
// 전에 쓰던 복사 생성자와는 구조가 다르다.
// 전에 쓰던 구조는 멤버 이니셜라이저를 이용하여 값을 저장하는 것이었다.
// 하지만 지금은 새롭게 동적할당을 하고 있다.
// 동적할당이 목표이기 때문이다.

// 34 ~ 42번째 줄
// 덧셈 연산자를 정의해주었다.
//
// 34번째 줄 CTest형 함수라는 것에 주목
// 임시객체를 나타내는 자료형이다.
// 임시객체로 값을 반환한다는 뜻이기 때문에 CTest&가 아니다.
// CTest&를 쓰게 된다면 원본인 임시객체가 없어지기 때문에 오류가 날지도?
// 자세한건 30.addition_operator_overloading에 나와있으니 읽어보도록
//
// 36 ~ 38번째 줄
// 새롭게 객체를 생성하고 새로운 객체 안에 값을 더하여 그 값을 반환하는 구조다.
// 이건 전에 쓰던 코드인데 멤버변수가 int형일 때나 먹혔다.
// 지금은 동적할당을 해야하는 상황
//
// 41번째 줄
// 원본과 참조본의 값을 더하여 새롭게 객체를 생성한다.
// 그리하면 두 값을 더한 값을 가진 객체가 새롭게 동적할당이 된다.
// 주 목적은 '동적할당'이다.
// 기존에 쓰던 코드에서는 동적할당이 안되기 때문에 객체를 새로 생성하는 것이다.

// 77 ~ 86번째 줄
// 이동 대입 연산자를 정의해주었다.
//
// 77번째 줄 CTest&형으로 정의해주었다.
// CTest형으로 부르면 복사 생성자가 불리게 되므로 주의
//
// 78번째 줄
// 기존에 쓰던 코드이다.
// 클래스형이 아니었기 때문에 멤버 이니셜라이저를 사용할 수 있었다.
//
// 82, 83번째 줄
// 얕은 복사를 하고 참조형 객체의 멤버변수는 쓰지 못하게 nullptr로 만들었다.

// 93번째 줄
// 아주 중요한 부분이다.
// 여기서 임시객체를 이용한 연산이 이루어진다.
// 가장 최종적으로 82, 83번째 줄 연산이 이루어진다.
// 존재하는 객체와 임시객체의 대입 연산은 이동 대입 연산이 되기 때문
// 기존에 있던 데이터는 힙에 존재한다.
// 값을 바꿔주기 보다 참조형으로 들어온 객체의 데이터의 주소값을 복사하여 넣는다.
// 그리고 참조형으로 들어온 데이터는 쓰지 못하게 nullptr로 만들어준다.
// 어차피 참조형 객체는 임시객체기 때문에 곧 사라지기 때문
// 얕은 복사는 동적할당과 주소값을 사용할때 유용하다.
// 만약 이동 대입 연산자가 없었다면 단순 대입 연산자가 불렸을 것이다.
// 힙에 새롭게 할당하는 바보짓을 했을 것.
// 성능에도 악영향이 미쳤을 것이다.
// 이동 대입 연산자가 불렸기에 주소값만 바꾸는 연산을 하여 성능을 끌어올렸다.

// 97번째 줄
// 단순 대입 연산자가 불린다.
// 실제로 존재하는 객체끼리의 대입이기 때문이다.