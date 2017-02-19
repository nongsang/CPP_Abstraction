#include <iostream>

using namespace std;

class CTest
{
	int m_nData{ 0 };
public:
	CTest() { cout << "디폴트 생성자" << endl; }
	CTest(int nParam) { cout << "변환 생성자" << endl; }
	~CTest() { cout << "소멸자" << endl; }

	CTest(const CTest& rhs) : m_nData(rhs.m_nData)
	{
		cout << "복사 생성자" << endl;
	}

	CTest(const CTest&& rhs) : m_nData(rhs.m_nData)		// 이동생성자 정의
	{
		cout << "이동 생성자" << endl;
	}

	CTest& operator=(const CTest& rhs)
	{
		cout << "대입 연산자" << endl;
		m_nData = rhs.m_nData;
		return *this;
	}

	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
};

CTest TestFunc(int nParam)
{
	cout << "TestFunc(int) 시작" << endl;
	CTest a;			// 객체생성인데?
	a.SetData(nParam);
	cout << "TestFunc(int) 끝" << endl;
	return a;
}

int main()
{
	cout << "main() 시작" << endl;
	CTest b;
	b = TestFunc(20);		// 임시객체가 생길텐데?
	CTest c(b);
	cout << "main() 끝" << endl;
}

// 이동의미론은 C++11에서 새로 추가된 개념이다.
// 약간 어려우니 반복해서 읽고 생각하도록

// 18 ~ 21번째 줄
// 이동 생성자를 정의해주었다.
// 이 생성자가 있느냐 없느냐에 따라서 성능차가 생길 수 있다.

// 47번째 줄
// 임시객체가 생길만한 문장이다.
// main() 함수 밖에서 함수에게 객체생성을 지시한다.
// 임시객체가 생기는건 맞다.
// 하지만 이동생성자를 정의해주었다.

// 37번째 줄
// main() 함수가 아닌 새로 정의해준 함수 내에서 객체생성을 하였다.
// 함수에서 생성한 객체를 반환할 것이다.
// 반환할 위치가 없기 때문에 임시객체를 만들어서 객체 원본을 복사할 것이다.
// 하지만 복사하면 너무 많은 자원을 사용한다.
// 거기다가 함수를 빠져나오면서 원본객체는 삭제된다.
// 임시객체가 생성이 되는걸 막을 수 없다면?
// 복사되는 것을 바꾸면 성능향상이 있을 것이다.
// 여기서 이동생성자의 힘이 발휘된다.
// 어차피 없어질 원본이라면 원본에 쓰이던 자원을 임시객체로 복사가 아닌 이동한다면?

// 주된 개념은
// 임시객체를 없앨 수 없으니
// 임시객체를 생성할 때 원본객체를 제거하면서
// 원본객체에서 사용하던 자원을 임시객체로 전부 이동시키는 것이다.
// 그러면 자원을 따로 끌어다 쓸 이유는 없다.
// 원래라면 힘들게 객체를 생성했는데, 복사를 위해서 또 자원을 끌어다 쓰고, 원본을 지우는 바보짓을 하게되는 것이다.
// 차라리 임시객체를 지울 수 없다면 원본을 지우면서 임시객체에 자원을 그대로 사용하는 편이 자원절약 및 시간절약이 되면서 성능향상에 도움이 된다.