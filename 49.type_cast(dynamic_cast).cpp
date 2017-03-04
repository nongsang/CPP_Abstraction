#include <iostream>

using namespace std;

class CShape
{
public:
	CShape() { cout << "CShape ������" << endl; }
	virtual ~CShape() { cout << "CShape �Ҹ���" << endl; }
	virtual void Draw() { cout << "CShape::Draw()" << endl; }
};

class CRectangle : public CShape
{
public:
	virtual void Draw() { cout << "CRectangle::Draw()" << endl; }	// �����Լ����� ����ϰ� ����
};

class CCircle : public CShape
{
public:
	virtual void Draw() { cout << "CCircle::Draw()" << endl; }		// �̰͵� �����Լ�
};

int main()
{
	cout << "���� ��ȣ�� �Է��ϼ���. [1. �簢��, 2. ��]" << endl;
	int nInput = 0;
	cin >> nInput;

	CShape *pShape{ nullptr };
	if (1 == nInput)
		pShape = new CRectangle;

	else if (2 == nInput)
		pShape = new CCircle;

	else
		pShape = new CShape;

	pShape->Draw();		// ���ٸ� Ư¡���� ����Լ� ȣ��

	// ���Ĵ� �̻��ϱ���
	CRectangle *pRect = dynamic_cast<CRectangle*>(pShape);
	if (NULL != pRect)		// ����� ���� ������ Ȯ���Ѵ�.
		pRect->Draw();
	
	else
	{
		CCircle *pCircle = dynamic_cast<CCircle*>(pShape);
		if (NULL != pCircle)		// ����� ���� ������ Ȯ���Ѵ�.
			pCircle->Draw();

		else
			pShape->Draw();
	}
}

// 16, 22�� ��
// �θ�Ŭ������ ��ӹ��� �����Լ����� virtual�� ����Ͽ� ����ϰ� �ִ�.
// ���� ��ӹ��� Draw()�Լ��� �ڽ�Ŭ���鿡 �°� �������̵��ϰ� �ִ�.

// 41�� ��
// �����Լ��� ��������Ƿ� ������������ �����ص� �������� ����Լ��� �Ҹ��� �ǹǷ� ���� ������ �����̴�.
// ���� ���� ����� ����̹Ƿ� �� ����صε���

// 44 ~ 57�� ��
// if ~ else�� �̿��� �����Ҵ翡���� ����ȯ�� ����ϰ� �׿� ���� ����Լ��� ȣ���ϰ� �ִ�.
// �����Լ��� ����ؼ� �������İ� �������� ����� ���� if ~ else���� ����ؼ� �����Ͽ���.
// if ~ else�� �׻� �񱳸� �ϹǷ� ���ɿ� ��ְ� �ȴ�.
//
// dynamic_cast�� ����ȯ�� �����ϸ� NULL�� ��ȯ�Ѵ�.
// �׷��⿡ if ~ else������ ������ ���������ӿ��� nullptr�� �ƴ� NULL�� �񱳸� ���ְ� �ִ�.
//
// Ư�� 45, 51���� ���� ����� ������ Ȯ���ϴ� ����� RTTI(Run-Time Type Information or Identification)�̶�� �Ѵ�.

// �������� �õ��� dynamic_cast�� �����Ҵ��� ��Ȳ���� ����ȯ�� ����Ѵ�.
// ������ ���ÿ� ����� �̿��� �������İ� �������� �̿��� ������� ���ŷӰ� �ڿ��Ҹ� ���ϴٴ� ���� �� �� �ִ�.
// ���� �ʿ��� ������ �ƴϸ� dynamic_cast�� ������� ����.