#include <iostream>

using namespace std;

class CObject
{
public:
	CObject() { cout << "CObject ������" << endl; }
	virtual ~CObject() { cout << "CObject �Ҹ���" << endl; }
};

class CImage : public CObject		// virtual�� ���� ��� ������ ��ӹ��� ��ü ������ŭ ���� ��ü�� ȣ��ȴ�.
//class CImage : virtual public CObject	
{
public:
	CImage() { cout << "CImage ������" << endl; }
	~CImage() { cout << "CImage �Ҹ���" << endl; }
};

class CShape : public CObject
//class CShape : virtual public CObject		// virtual�� ��ӹ޾ƾ� ���� ��ü�� 1���� ȣ��ȴ�.
{
public:
	CShape() { cout << "CShape ������" << endl; }
	~CShape() { cout << "CShape �Ҹ���" << endl; }
};

class CPicture : public CImage, public CShape		// ���߻��
{
public:
	CPicture() { cout << "CPicture ������" << endl; }
	~CPicture() { cout << "CPicture �Ҹ���" << endl; }
};

int main()
{
	CPicture a;
}

// 12, 20�� ��
// CImage�� CShape�� ���� ��ü�� CObject�� �������ְ� ���� ��ӹ޾Ҵ�.

// 35�� ��
// ���� ���� ��ü�� CPicture�� �����Ͽ���.
// ���� ���� ��ü�� �Ҹ��Ƿ� ���� ������ü���� ���ʴ�� ��ü���� ����ȴ�.

// ���⼭ ������ �ϳ� �ִ�.
// ���� ������ü�� ��ӹ��� ��ü���� �����Ѵ�.
// �� ��ü���� ����Ǹ鼭 �ֻ��� ��ü�� 2�� ����ȴ�.

// 13, 21�� ��
// virtual�� ��ӹ޾Ҵ�.
// ���� ���� ��ü�� ��ӹ��� ��ü�� ���� �־ �ֻ��� ��ü�� 1���� ȣ���� �ȴ�.

// ���⼭ ���� �ƴϴ�.
// ���� CImage���� CObject�� ���� �����ϰ� CShape���� �����ϰ� �Ѵٸ�?
// �ʹ� �����Ұ� ����.
// ���� �Ⱦ��°� ����.
// 54.interface_multiple_inheritance���� ���߻���� ���� ��츦 �Ұ��ϰڴ�.