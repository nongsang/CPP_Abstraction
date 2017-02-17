#include <iostream>

using namespace std;

class CTest
{
	int m_nData;
	
public:
	CTest() { cout << "디폴트 생성자" << endl; }
	~CTest() { cout << m_nData << " 소멸자" << endl; }

	// 복사 생성자 선언 및 정의
	CTest(const CTest &rhs)
		//: m_nData(rhs.m_nData)
	{
		this->m_nData = rhs.m_nData;
		cout << "복사 생성자" << endl;
	}

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
};

int main()
{
	CTest a; // 디폴트 생성자 호출
	a.SetData(10);	// SetData 메서드 호출
	cout << a.GetData() << endl;

	CTest b(a); // 복사 생성자 호출
	b.SetData(20);
	cout << b.GetData() << endl;
}

// 10번째 줄
// 생성자가 호출되었을 때 알려줌

// 11번째 줄
// 소멸자가 호출되었을 때 어떤 값을 가진 인스턴스가 소멸했는지 알려줌

// 14번째 줄
// 복사 생성자의 정의
// const는 복사를 했을 때 원본이 훼손됨을 방지한다.
// 그러니까 const는 특별한 이유가 없다면 꼭 써주자.
// 참조형으로 만드는 이유는 참조를 하여 복사하기 때문.
// rhs는 자주 쓰이는 변수명인데 right hand side라는 뜻이다.
// r-value라고 보기 때문이다.

// 15번째 줄
// 멤버 이니셜라이저를 이용한 멤버함수 초기화
// 새로 생성될 m_nData에 참조할 원본 클래스 rhs의 멤버변수 m_nData를 복사저장한다는 의미이다.

// 17번째 줄
// 15번째 줄과 같은 의미이다.
// 그렇지만 m_nData라는 멤버변수의 이름이 같기 때문에 this를 사용하여 명확히 해주었다.

// 31번째 줄
// 복사 생성자를 호출한다.
// 그러므로 14 ~ 18번째 줄에 있는 복사생성의 정의에 따라 실행한다.

// 32번째 줄
// 복사생성된 변수 b에 멤버변수를 20으로 바꾼다.

// 여서기서도 마찬가지로 가장 빨리 생성된 클래스는 가장 늦게 소멸된다.