#include <iostream>

using namespace std;

class CUSB
{
public:
	virtual int GetUsbVersion() = 0;		// ���������Լ�
	virtual int GetTransferRate() = 0;		// ���������Լ��� ����� �ִٰ� �˷��ִ� ��
};

class CSerial
{
public:
	virtual int GetSignal() = 0;		// �̰͵� ���������Լ�
	virtual int GetRate() = 0;			// �̰͵�
};

class CDevice : public CUSB, public CSerial		// ��������Ŭ�����θ� ���߻��
{
public:
	// USB �������̽�
	virtual int GetUsbVersion() { return 0; }
	virtual int GetTransferRate() { return 0; }

	// �ø��� �������̽�
	virtual int GetSignal() { return 0; }
	virtual int GetRate() { return 0; }
};

int main()
{
	CDevice dev;

	return 0;
}

// 5 ~ 10�� ��
// CUSB�� �Լ����� ���� ���������Լ��� �����Ͽ���.
// �׷��Ƿ� ��������Ŭ������ ź���Ͽ���.

// 12 ~ 17�� ��
// CSerial�� ���������� ���� ���������Լ��� �����Ͽ���.
// �̰͵� ��������Ŭ����

// 19 ~ 29�� ��
// ��������Ŭ�����θ� ���߻���� �Ͽ���.
// �׷��Ƿ� CDevice������ ���������Լ����� ���� �������̵����־�� ����� �����ϴ�.

// ���⼭ ���߻���� ����ص� ���� ������ ��Ȳ�� �����Ѵ�.
// �ٷ� �� �θ�Ŭ������ ���� ��������Ŭ������ ���.
// �θ�Ŭ������ �ڽ�Ŭ�������� ������������ϴ� �������̽��� ������ ���̴�.
// �Ѹ���� �� �ʿ��� ����� �˷��ְ� �ڽ�Ŭ�������� �����ϴ� ���̴�.
// �� �ܿ��� ���� ���߻���� ����ؼ� ��� ���� ����.
// ó�� ������ ���� ������ ���� ���������� ���������� ����� �����̴�.