#include <iostream>

using namespace std;

class CTest
{
	int m_nData;
public:
	CTest(int nParam) : m_nData(nParam)
	{
		cout << "변환 생성자" << endl;
	}

	~CTest()
	{
		cout << "소멸자" << endl;
	}

	operator int()
	{
		cout << "형변환 연산자" << endl;
		return m_nData;
	}

	/*int& operator++()
	{
		cout << "전위 증가 연산자" << endl;
		return ++m_nData;
	}

	int& operator++(int)
	{
		cout << "후위 증가 연산자" << endl;
		int nData = m_nData;
		m_nData++;
	
		return nData;
	}*/

	CTest& operator++()			// 전위 증가 연산
	{
		cout << "전위 증가 연산자" << endl;

		this->m_nData = this->m_nData + 1;

		return *this;
	}

	CTest operator++(int)		// 후위 증가 연산
	{
		cout << "후위 증가 연산자" << endl;

		const CTest nData = this->m_nData;
		this->m_nData = this->m_nData + 1;

		return nData;
	}
};

int main()
{
	CTest a(10);
	
	cout << ++a << endl;

	cout << a++ << endl;

	cout << a << endl;
}

// 25 ~ 29번 줄
// 전위 증가 연산자를 정의해 주었다.
// CTest&형인 것에 주목하자.
// 원본을 그대로 바꾼다는 뜻이다.

// 31 ~ 38번 줄
// 34, 35번 줄에서 새로운 변수를 생성하여 값을 백업(backup)해놓고 원본값을 +1했다.
// 그리고 백업한 값을 반환한다.
// 여기서 int형이 아니라 int&으로 반환형을 사용해도 통한다.
// 하지만 객체에서 문제가 발생한다.
// 백업을 해놓는다는 연산을 추가로 해줘야 한다.
// 이는 변수일 경우 큰 문제는 안되지만 객체가 존재할 경우 큰 문제가 발생한다.

// 40 ~ 47번 줄
// 25 ~ 29번 줄처럼 똑같이 전위 연산을 한다.
// 특별한 거 없다.

// 49 ~ 57번 줄
// 31 ~ 38번 줄과 같이 새로운 객체를 생성하여 값을 백업(backup)해놓고 원본값을 +1했다.
// 여기서 문제 발생
// 객체를 임시로 개발자가 호출했다는 것이다.
// 그리고 그 객체는 곧 사라질 운명이라는 것.
// 불필요하진 않지만 자원을 더 사용한다는 것이기 때문에 사용이 꺼려진다.
// 변수일 경우는 무시해도 좋을 만큼의 자원소모지만 객체를 다룰 경우 무시할 수 없다.
// 그렇기에 for문을 사용할 때 ++i를 애용하는 것이다.
//
// 그리고 CTest&형이 아닌 이유는 변경결과가 호출한 객체로 바로 전달이 되는 것이 아니기 때문
// 어떠한 객체가 연산 결과 값을 받는 것이기 때문에 자신의 값을 바꾸는 return *this를 사용하지 않는다.

// 64번 줄
// 전위증가를 하고 출력하였다.
// 생성자와 형변환 연산자만 호출하므로 딱 필요한 연산만 존재한다.

// 66번 줄
// 후위증가를 하고 출력하였다.
// 후위증가는 개발자가 임시로 객체를 생성하였으므로 지금 연산에서는 불필요한 자원소모가 발생한다.
// 함수내에서 객체를 생성하였고 소멸하였다.
// 전위증가에 비해서 객체 1개 정도의 연산을 더 하는 것이다.
// 이걸 잘 알아두고 객체를 사용하는 코드의 경우 전위증가를 애용하자.