#include <iostream>

using namespace std;

#define DEFAULT_FARE 1000

class CPerson
{
protected:
	unsigned m_nFare{ 0 };			// unsigned만 쓰면 기본적으로 unsigned int형
public:
	CPerson() { cout << "CPerson 생성자" << endl; }
	virtual ~CPerson() { cout << "CPerson 소멸자" << endl; }

	virtual void CalcFare() = 0;	// 요금을 계산하는 가상 함수

	virtual unsigned GetFare() const { return m_nFare; }	// 요금을 알려주는 가상함수지만 중요한건 따로 설명
};

class CBaby : public CPerson
{
public:
	void CalcFare() { m_nFare = 0; }
};

class CChide : public CPerson
{
public:
	void CalcFare() { m_nFare = DEFAULT_FARE * 50 / 100; }
};

class CTeen : public CPerson
{
public:
	void CalcFare() { m_nFare = DEFAULT_FARE * 75 / 100; }
};

class CAdult : public CPerson
{
public:
	void CalcFare() { m_nFare = DEFAULT_FARE; }
};

int main()
{
	CPerson* arList[3]{ nullptr };
	int nAge = 0;

	for (auto &person : arList)
	{
		cout << "나이 입력 : " << endl;
		cin >> nAge;

		if (nAge < 8)
			person = new CBaby;

		else if (nAge < 14)
			person = new CChide;

		else if (nAge < 20)
			person = new CTeen;

		else
			person = new CAdult;

		person->CalcFare();
	}

	for (auto &person : arList)
		cout << person->GetFare() << "원" << endl;

	for (auto &person : arList)
	{
		delete person;
		person = nullptr;
	}
}

// 10번 줄
// unsigned만 사용하여도 unsigned int와 같은 의미이다.

// 15, 17번 줄
// virtual로 선언하여 상속을 받는 클래스들의 공통 특성을 알려준다.
// 하지만 GetFare()함수는 virtual로 선언했으나 오버라이딩이 되지 않았다.
// 70번 줄에서 다시 설명

// 20, 26, 32, 38번 줄
// 각 자식 클래스들은 부모클래스의 특성을 상속받는다.
// 클래스들은 CalcFunc()을 오버라이딩 했으며, GetFare()는 오버라이딩하지 않았다.

// 49 ~ 67번 줄
// 범위기반 루프를 이용하여 사용자의 입력에 따라 구분하여 자식클래스를 부모클래스로 동적할당하고 있다.
// 여기서도 마찬가지로 '참조형식'과 '실형식'에 따라서 virtual로 선언한 함수가 호출된다.
// 사용자의 입력에 따라서 적절한 생성자를 호출하는 구조를 보이고 있다.
// 필요한 객체만 생성이 가능하다는 의미이다.
// 이러한 상당히 유용하므로 기억해놓자.

// 69, 70번 줄
// 범위기반 루프를 이용해 GetFare()를 호출하여 값을 출력한다.
// 17번 줄에서 GetFare()는 virtual로 선언하였다.
// 하지만 GetFare()는 오버라이딩을 하지 않았으므로 CPerson의 GetFare()가 호출이 된다.
