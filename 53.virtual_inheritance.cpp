#include <iostream>

using namespace std;

class CObject
{
public:
	CObject() { cout << "CObject 생성자" << endl; }
	virtual ~CObject() { cout << "CObject 소멸자" << endl; }
};

class CImage : public CObject		// virtual을 빼고 상속 받으면 상속받은 객체 갯수만큼 상위 객체가 호출된다.
//class CImage : virtual public CObject	
{
public:
	CImage() { cout << "CImage 생성자" << endl; }
	~CImage() { cout << "CImage 소멸자" << endl; }
};

class CShape : public CObject
//class CShape : virtual public CObject		// virtual로 상속받아야 상위 객체가 1번만 호출된다.
{
public:
	CShape() { cout << "CShape 생성자" << endl; }
	~CShape() { cout << "CShape 소멸자" << endl; }
};

class CPicture : public CImage, public CShape		// 다중상속
{
public:
	CPicture() { cout << "CPicture 생성자" << endl; }
	~CPicture() { cout << "CPicture 소멸자" << endl; }
};

int main()
{
	CPicture a;
}

// 12, 20번 줄
// CImage와 CShape의 상위 객체로 CObject를 정의해주고 각각 상속받았다.

// 35번 줄
// 가장 하위 객체로 CPicture를 생성하였다.
// 가장 하위 객체가 불리므로 가장 상위객체부터 차례대로 객체들이 실행된다.

// 여기서 문제가 하나 있다.
// 가장 상위객체를 상속받은 객체들이 존재한다.
// 이 객체들이 실행되면서 최상위 객체가 2번 실행된다.

// 13, 21번 줄
// virtual로 상속받았다.
// 이제 상위 객체를 상속받은 객체가 많이 있어도 최상위 객체는 1번만 호출이 된다.

// 여기서 끝이 아니다.
// 만약 CImage에서 CObject의 값을 변경하고 CShape에서 수정하고 한다면?
// 너무 생각할게 많다.
// 차라리 안쓰는게 좋다.
// 54.interface_multiple_inheritance에서 다중상속이 좋은 경우를 소개하겠다.