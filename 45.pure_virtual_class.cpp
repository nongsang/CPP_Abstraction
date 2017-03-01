#include <iostream>

using namespace std;

class CInterface
{
public:
	CInterface() { cout << "CInterface ������" << endl; }
	virtual ~CInterface() { cout << "CInterface �Ҹ���" << endl; }

	virtual int GetData() const = 0;				// ���� �����Լ�
	virtual void SetData(const int nParam) = 0;		// �������̵����θ� ��� �����ϰ� ����
};

class CTest : public CInterface
{
	int m_nData{ 0 };
public:
	CTest() { cout << "CTest ������" << endl; }
	~CTest() { cout << "CTest �Ҹ���" << endl; }

	int GetData() const { return m_nData; }					// �������̵�
	void SetData(const int nParam) { m_nData = nParam; }	// �̰͵�
};

int main()
{
	//CInterface a;		// ���� ���� Ŭ������ ���� �� ���� �Ұ�
	CTest a;
	a.SetData(5);
	cout << a.GetData() << endl;
}

// 11, 12�� ��
// ���� �����Լ���ν� �Լ����� ȣ���� �� ����.
// �� �Լ����� �������̵����θ� ����� �����ϴ�.
// �ݵ�� �����Ǹ� ����߸� �Ѵ�.

// 22, 23�� ��
// CInterface�� ���� �����Լ����� �������̵��Ͽ���.

// 28�� ��
// CInterface�� ���� �����Լ��θ� �̷���� �����Ƿ� ���� ���� Ŭ������.
// �׷��Ƿ� ���� ���� ���� Ŭ������ �����Ϸ� �õ��ϴ� ���̴�.
// ������ ���� ���� Ŭ������ ���������� ����� �� �ִ� �Լ��� �����Ƿ� ������ �Ұ����ϴ�.

// 29 ~ 31�� ��
// ��ӹ��� �ڽ�Ŭ���� CTest�� �����ϰ� ����, ȣ���ϰ� �ִ�.
// ���� 