#include <iostream>

using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest 생성자" << endl; }

	virtual ~CTest() { cout << "CTest 소멸자" << endl; }
	virtual void TestFunc1() {}
	virtual void TestFunc2() {}
};

class CTestEx : public CTest
{
public:
	CTestEx() { cout << "CTestEx 생성자" << endl; }

	~CTestEx() { cout << "CTestEx 소멸자" << endl; }
	void TestFunc1() {}						// 오버라이딩했지만 정의해주지 않음
	void TestFunc2() { cout << "TestFunc2()" << endl; }		// 오버라이딩하면서 텍스트 출력
};

int main()
{
	CTest *pData = new CTestEx;		// 가상함수가 존재하므로 참조형식으로 사용
	pData->TestFunc2();
	delete pData;
	pData = nullptr;
}

// 디버그 -> 중단점 설정/해제(F9)를 선택해서 8, 18번 줄에 브레이크 포인트로 설정한다.

// 프로젝트 -> 프로젝트이름 속성 -> 구성속성 -> 링커 -> 고급 -> 임의 기준 주소 -> 아니오 로 설정한다.
// 윈도우 운영체제가 제공하는 임의 기준 주소를 사용하지 않게 하기 위함이다.
// 임의 기준 주소는 가상 메모리 상에 존재하는 각종 메모리들의 시작 주소를 실행할 때 마다 랜덤으로 변경하는 기능이다.
// 이를 사용하므로써 메로리 해킹을 방지하는 것.
// 이를 잠시 꺼두는 것이다.

// F5로 디버깅을 하고 Ctrl + Alt + V, L로 내용을 확인한다.

// this포인터 아래에 __vfptr이라는 지역 변수가 존재하는데, 이 변수가 vtable 포인터이다.
// F5을 눌러서 진행하면 __vfptr의 값이 바뀐다.
// 그러므로 가리키는 함수 포인터 배열도 달라진다.

// 실행순서
// 1. 27번 줄에서 인스턴스가 생성되면서 CTest의 vtable이 CTest의 가상함수 배열(테이블)의 처음 시작주소를 가리킨다.
// 2. 자식클래스의 생성자가 실행되면서 CTest의 vtable이 CTestEx의 가상함수 테이블을 가리키게 된다.
// 3. 그러므로 CTest의 가상함수 테이블에 자식클래스의 테이블을 덮어 씌우게 된다.