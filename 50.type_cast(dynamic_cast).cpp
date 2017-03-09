#include <iostream>

using namespace std;

class CShape
{
public:
	CShape() { cout << "CShape 생성자" << endl; }
	virtual ~CShape() { cout << "CShape 소멸자" << endl; }
	virtual void Draw() { cout << "CShape::Draw()" << endl; }
};

class CRectangle : public CShape
{
public:
	virtual void Draw() { cout << "CRectangle::Draw()" << endl; }	// 가상함수임을 명시하고 정의
};

class CCircle : public CShape
{
public:
	virtual void Draw() { cout << "CCircle::Draw()" << endl; }		// 이것도 가상함수
};

int main()
{
	cout << "도형 번호를 입력하세요. [1. 사각형, 2. 원]" << endl;
	int nInput = 0;
	cin >> nInput;

	CShape *pShape{ nullptr };
	if (1 == nInput)
		pShape = new CRectangle;

	else if (2 == nInput)
		pShape = new CCircle;

	else
		pShape = new CShape;

	pShape->Draw();		// 별다른 특징없는 멤버함수 호출

	// 이후는 이상하구만
	CRectangle *pRect = dynamic_cast<CRectangle*>(pShape);
	if (NULL != pRect)		// 제대로 값이 들어갔는지 확인한다.
		pRect->Draw();
	
	else
	{
		CCircle *pCircle = dynamic_cast<CCircle*>(pShape);
		if (NULL != pCircle)		// 제대로 값이 들어갔는지 확인한다.
			pCircle->Draw();

		else
			pShape->Draw();
	}
}

// 16, 22번 줄
// 부모클래스의 상속받은 가상함수임을 virtual을 사용하여 명시하고 있다.
// 또한 상속받은 Draw()함수를 자식클래들에 맞게 오버라이딩하고 있다.

// 41번 줄
// 가상함수를 사용했으므로 참조형식으로 대입해도 실형식의 멤버함수가 불리게 되므로 아주 간결한 문장이다.
// 아주 많이 사용할 기능이므로 잘 기억해두도록

// 44 ~ 57번 줄
// if ~ else를 이용한 동적할당에서의 형변환을 사용하고 그에 따라 멤버함수를 호출하고 있다.
// 가상함수를 사용해서 참조형식과 실형식의 기법을 굳이 if ~ else문을 사용해서 구현하였다.
// if ~ else는 항상 비교를 하므로 성능에 장애가 된다.
//
// dynamic_cast는 형변환에 실패하면 NULL을 반환한다.
// 그렇기에 if ~ else문에서 변수가 포인터형임에도 nullptr이 아닌 NULL로 비교를 해주고 있다.
//
// 특히 45, 51같이 값이 제대로 들어갔는지 확인하는 방식을 RTTI(Run-Time Type Information or Identification)이라고 한다.

// 예제에서 봤듯이 dynamic_cast는 동적할당한 상황에서 형변환에 사용한다.
// 하지만 동시에 상속을 이용한 참조형식과 실형식을 이용한 기법보다 번거롭고 자원소모가 심하다는 것을 알 수 있다.
// 정말 필요한 순간이 아니면 dynamic_cast는 사용하지 말자.
