#include <iostream>

using namespace std;

class CUSB
{
public:
	virtual int GetUsbVersion() = 0;		// 순수가상함수
	virtual int GetTransferRate() = 0;		// 순수가상함수는 기능이 있다고만 알려주는 것
};

class CSerial
{
public:
	virtual int GetSignal() = 0;		// 이것도 순수가상함수
	virtual int GetRate() = 0;			// 이것도
};

class CDevice : public CUSB, public CSerial		// 순수가상클래스로만 다중상속
{
public:
	// USB 인터페이스
	virtual int GetUsbVersion() { return 0; }
	virtual int GetTransferRate() { return 0; }

	// 시리얼 인터페이스
	virtual int GetSignal() { return 0; }
	virtual int GetRate() { return 0; }
};

int main()
{
	CDevice dev;

	return 0;
}

// 5 ~ 10번 줄
// CUSB의 함수들을 전부 순수가상함수로 정의하였다.
// 그러므로 순수가상클래스가 탄생하였다.

// 12 ~ 17번 줄
// CSerial도 마찬가지로 전부 순수가상함수로 정의하였다.
// 이것도 순수가상클래스

// 19 ~ 29번 줄
// 순수가상클래스로만 다중상속을 하였다.
// 그러므로 CDevice에서는 순수가상함수들을 전부 오버라이딩해주어야 사용이 가능하다.
// 이처럼 각 자식클래스들에서 각 자식클래스가 다르면서 각자에 맞는 기능들을 오버라이딩으로 정의하여 활용하는 것을 다형성이라 한다.

// 여기서 다중상속을 사용해도 좋은 유일한 상황이 존재한다.
// 바로 각 부모클래스가 전부 순수가상클래스일 경우.
// 부모클래스는 자식클래스에서 재정의해줘야하는 인터페이스를 제공할 뿐이다.
// 한마디로 딱 필요한 기능을 알려주고 자식클래스에서 구현하는 것이다.
// 그 외에는 전부 다중상속을 사용해서 득될 것이 없다.
// 처음 개발할 때는 좋지만 점점 복잡해져서 유지보수가 힘들기 때문이다.
