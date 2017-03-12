#include <iostream>

using namespace std;

class CImage
{
protected:
	int m_nHeight{ 0 };
	int m_nWidth{ 0 };
public:
	CImage(int nHeight, int nWidth)
		: m_nHeight(nHeight), m_nWidth(nWidth)
	{
		cout << "CImage ������" << endl;
	}
	~CImage() { cout << "CImage �Ҹ���" << endl; }


	int GetHeight() const { return m_nHeight; }
	int GetWidth() const { return m_nWidth; }
	int GetSize() const { return 0; }			// �θ�Ŭ������ CShape���� �ִ� �Լ���.
};

class CShape
{
protected:
	int m_nType{ 0 };
public:
	CShape(int nType) : m_nType(nType)
	{
		cout << "CShape ������" << endl;
	}
	~CShape() { cout << "CShape �Ҹ���" << endl; }

	int GetType() const { return m_nType; }
	int GetSize() const { return 0; }			// �θ�Ŭ������ CImage���� �ִ� �Լ���.
};

class CPicture : public CImage, public CShape		// ���߻��
{
public:
	CPicture() : CImage(200, 120), CShape(1)
	{
		cout << "CPicture ������" << endl;
	}
	~CPicture() { cout << "CPicture �Ҹ���" << endl; }
};

int main()
{
	CPicture a;
	cout << "Height : " << a.GetHeight() << endl;
	cout << "Width : " << a.GetWidth() << endl;
	cout << "Type : " << a.GetType() << endl;

	//a.GetSize();			// ��ȣ�� �߻�
	a.CImage::GetSize();	// ��������� ȣ���ؾ��Ѵ�.
	a.CShape::GetSize();	// �̰͵� ��������
}

// 39�� ��
// �� �θ�Ŭ���� CImage�� CShape�� ���߻���Ͽ���.
// CImage�� CShape �ΰ��� ������ ��� ������ ���̴�.
// ������ ���⼭ ������ �߻��Ѵ�.

// 21, 36�� ��
// �θ�Ŭ�������� ���� ���� �޼��带 �����ִ�.

// 56�� ��
// �� �θ�Ŭ�������� ���� ���� �޼��带 ���� �����Ƿ� ��ȣ���� �߻��Ѵ�.

// 57, 58�� ��
// 56�� �ٿ��� ��ȣ���� �߻��ϹǷ� ��������� ȣ���ؾ��Ѵ�.
// ���⼭ �߿��� ���� ���� ������ �� ���� �̻��� �ǹ̷� �ؼ��� ������ �־�� �� �ȴٴ� ���̴�.
// �̸� ������ ���̾Ƹ��(the Deadly Diamond of Death. DDD)��� �θ���.

// ���⼭���� ���� ���߻���� ���������.
// ���߻���� �����ϸ� ���� �ʴ°� ���Űǰ��� ������ �ѹ� ������ ������.
// 53.virtual_inheritance���� �߰��� ����