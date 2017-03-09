#include <iostream>

using namespace std;

class CObject
{
protected:
	int m_nDeviceID{ 0 };
public:
	CObject() { cout << "CObject 생성자" << endl; }
	virtual ~CObject() { cout << "COBject 소멸자" << endl; }

	virtual int GetDevice() const = 0;		// 상속받은 클래스들이 공통적으로 가지고 있는 함수라는걸 알림
};

void PrintID(CObject* pObj)		// 여기서 중요
{
	cout << "Device ID : " << pObj->GetDevice() << endl;// 입력되는 어떤 클래스든 공통으로 있는 GetDevice()로 값을 출력하겠다. 
}

class CTV : public CObject			// CObject를 상속
{
public:
	CTV(int nID)
	{
		cout << "CTV 생성자" << endl;
		m_nDeviceID = nID;
	}
	~CTV() { cout << "CTV 소멸자" << endl; }
	int GetDevice() const
	{
		cout << "CTV::GetDivice()" << endl;
		return m_nDeviceID;
	}
};

class CPhone : public CObject		// CObject를 상속
{
public:
	CPhone(int nID)
	{
		cout << "CPhone 생성자" << endl;
		m_nDeviceID = nID;
	}
	~CPhone() { cout << "CPhone 소멸자" << endl; }
	int GetDevice() const
	{
		cout << "CPhone::GetDivice()" << endl;
		return m_nDeviceID;
	}
};

int main()
{
	CTV a(5);
	CPhone b(10);

	PrintID(&a);	// 참조형식과 실형식
	PrintID(&b);	// 여기서도 쓰인다.
}

// 13번 줄
// 순수가상함수로 선언하였다.
// 다르게 생각하면 상속받은 자식클래스들은 이 함수를 공통적으로 가지고 있다고 생각할 수 있다.
// 한마디로 상속받은 클래스들을 공통적으로 묶어주는 특징들은 전부 부모클래스에 있으며, 부모클래스라는 그룹으로 묶을 수 있다.

// 16 ~ 19번 줄
// CObject형 포인터 변수를 파라미터로 이용하여 값을 출력한다.
// 여기서 중요한 문장은 CObject형 포인터 변수를 파라미터를 설정했다는 것.
// 58, 59번 줄에서 다시 설명

// 21, 37번 줄
// CObject라는 부모클래스를 상속받은 자식클래스들이다.
// 순수가상함수를 오버라이딩하여 사용하고 있다.

// 58, 59번 줄
// 16 ~ 19번 줄과 같이 매우 중요한 문장이다. ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// PrintID함수를 호출하며 인자로 주소값을 넘겨주고 있다.
// 함수는 파라미터로 CObject형 포인터로 정의해주었다.
// 그 결과 CObject* pObj = (CTV)&a; 가 된다.
// 이는 참조형식과 실형식의 관계를 가진다.
// 참조형식은 순수가상클래스이므로 실형식인 자식클래스의 함수가 수행이 된다.

// 18번 줄
// CObject형 포인터변수인 pObj를 이용하여 함수에 접근한다.
// 그럼에도 실형식을 풀력해야하는 상황이므로 자식클래스의 함수가 호출이 된다.
// 이 함수는 바뀌지 않아도 실형식으로 다른 자식클래스를 전달 받으면 그대로 같은 기능을 수행한다.
// 이런식으로 interface를 구축할 수 있다.
