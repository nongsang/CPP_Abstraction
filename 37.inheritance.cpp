#include <iostream>

using namespace std;

class CTest
{
private:				// 같은 클래스 내에서만 접근 가능
	int m_nData{ 0 };
protected:				// 상속받은 자식 클래스만 접근 가능
	void PrintData()
	{
		cout << "출력" << endl;
		cout << CTest::GetData() << endl;
	}
public:					// 모두 접근 가능
	CTest() { cout << "CTest 생성자" << endl; }
	~CTest() { cout << "CTest 소멸자" << endl; }
	int GetData() const
	{
		cout << "getter" << endl;
		return m_nData;
	}
	void SetData(const int& nParam)
	{
		cout << "setter" << endl;
		this->m_nData = nParam;
	}
};

class CTestEx : public CTest		// 상속 방법
{
public:
	CTestEx() { cout << "CTestEx 생성자" << endl; }
	~CTestEx() { cout << "CTestEx 소멸자" << endl; }
	void TestFunc()
	{
		PrintData();
		SetData(5);
		cout << CTest::GetData() << endl;
	}
};

int main()
{
	CTestEx data;

	data.SetData(10);
	cout << data.GetData() << endl;

	//CTestEx::GetData();

	data.TestFunc();
}

// 9번 줄
// protected라는 키워드는 상속에서만 의미가 있다.
// 30번 줄과 연관 있다.

// 30번 줄
// public을 사용하여 상속을 하였다.
// 상속은 부모와 자식관계로 나타낼 수 있는데, 프로그래밍에서는 기존의 코드를 '재사용'한다는 의미와 같다.
// 상속 예약어는 private, protected, public 3가지를 사용할 수 있다.

// 37 ~ 39번 줄
// 매우 중요한 내용 ~~~~~~~~
// 자식 클래스는 부모 클래스로부터 public으로 상속받았다.
// 이 말은 부모 클래스의 public, protected 예약어로 사용된 멤버변수, 멤버함수를 자식 클래스에서 접근 가능하다는 의미이다.
// protected로 상속했다면 protected만, private로 상속하면 아무것도 사용할 수 없다.
// 자식 클래스에서 얼만큼의 접근권한을 부여하는지에 대한 내용이다.

// 45번 줄
// CTest를 public으로 상속받은 CTestEx를 생성하였다.
// 여기서 한가지 이슈가 있다.
// 자식 클래스를 생성하였지만 부모 클래스의 생성자가 먼저 불렸다.
// 기존에 있던 생성자가 먼저 불려야 나중에 덧붙여진 클래스가 의미가 있기 때문이다.

// 47, 48번 줄
// CTestEx형 변수인 data에 없는 SetData()함수를 사용하여 값을 저장하는 중이다.
// 이것이 '재사용'의 의미이다.
// 자식 클래스를 통해서 부모 클래스의 멤버변수를 사용한다.

// 50번 줄
// 이런 형식의 접근 방법은 클래스 내에서만 사용이 가능하다.
// main()에서 접근하기 위해서는 생성자가 호출이 되어야(메모리에 생성되어야)한다.
// 클래스형 변수 a를 생성했다고 가정하면, a.GetData(); 형식으로만 접근이 가능하다.