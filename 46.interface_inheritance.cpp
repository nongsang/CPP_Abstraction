#include <iostream>

using namespace std;

class CObject
{
protected:
	int m_nDeviceID{ 0 };
public:
	CObject() { cout << "CObject ������" << endl; }
	virtual ~CObject() { cout << "COBject �Ҹ���" << endl; }

	virtual int GetDevice() const = 0;		// ��ӹ��� Ŭ�������� ���������� ������ �ִ� �Լ���°� �˸�
};

void PrintID(CObject* pObj)		// ���⼭ �߿�
{
	cout << "Device ID : " << pObj->GetDevice() << endl;// �ԷµǴ� � Ŭ������ �������� �ִ� GetDevice()�� ���� ����ϰڴ�. 
}

class CTV : public CObject			// CObject�� ���
{
public:
	CTV(int nID)
	{
		cout << "CTV ������" << endl;
		m_nDeviceID = nID;
	}
	~CTV() { cout << "CTV �Ҹ���" << endl; }
	int GetDevice() const
	{
		cout << "CTV::GetDivice()" << endl;
		return m_nDeviceID;
	}
};

class CPhone : public CObject		// CObject�� ���
{
public:
	CPhone(int nID)
	{
		cout << "CPhone ������" << endl;
		m_nDeviceID = nID;
	}
	~CPhone() { cout << "CPhone �Ҹ���" << endl; }
	int GetDevice() const
	{
		cout << "CPhone::GetDivice()" << endl;
		return m_nDeviceID;
	}
};

int main()
{
	CTV a(5);
	CPhone b(10);

	PrintID(&a);	// �������İ� ������
	PrintID(&b);	// ���⼭�� ���δ�.
}

// 13�� ��
// ���������Լ��� �����Ͽ���.
// �ٸ��� �����ϸ� ��ӹ��� �ڽ�Ŭ�������� �� �Լ��� ���������� ������ �ִٰ� ������ �� �ִ�.
// �Ѹ���� ��ӹ��� Ŭ�������� ���������� �����ִ� Ư¡���� ���� �θ�Ŭ������ ������, �θ�Ŭ������� �׷����� ���� �� �ִ�.

// 16 ~ 19�� ��
// CObject�� ������ ������ �Ķ���ͷ� �̿��Ͽ� ���� ����Ѵ�.
// ���⼭ �߿��� ������ CObject�� ������ ������ �Ķ���͸� �����ߴٴ� ��.
// 58, 59�� �ٿ��� �ٽ� ����

// 21, 37�� ��
// CObject��� �θ�Ŭ������ ��ӹ��� �ڽ�Ŭ�������̴�.
// ���������Լ��� �������̵��Ͽ� ����ϰ� �ִ�.

// 58, 59�� ��
// 16 ~ 19�� �ٰ� ���� �ſ� �߿��� �����̴�. ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// PrintID�Լ��� ȣ���ϸ� ���ڷ� �ּҰ��� �Ѱ��ְ� �ִ�.
// �Լ��� �Ķ���ͷ� CObject�� �����ͷ� �������־���.
// �� ��� CObject* pObj = (CTV)&a; �� �ȴ�.
// �̴� �������İ� �������� ���踦 ������.
// ���������� ��������Ŭ�����̹Ƿ� �������� �ڽ�Ŭ������ �Լ��� ������ �ȴ�.

// 18�� ��
// CObject�� �����ͺ����� pObj�� �̿��Ͽ� �Լ��� �����Ѵ�.
// �׷����� �������� Ǯ���ؾ��ϴ� ��Ȳ�̹Ƿ� �ڽ�Ŭ������ �Լ��� ȣ���� �ȴ�.
// �� �Լ��� �ٲ��� �ʾƵ� ���������� �ٸ� �ڽ�Ŭ������ ���� ������ �״�� ���� ����� �����Ѵ�.
// �̷������� interface�� ������ �� �ִ�.