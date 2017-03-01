#include <iostream>

using namespace std;

class CTest
{
	char* m_pszData{ nullptr };
public:
	CTest()
	{
		cout << "CTest ������" << endl;
		m_pszData = new char[32];		// CTest �����Ҵ�
	}
	virtual ~CTest()				// �Ҹ��ڸ� virtual�� �����Ͽ���.
	{
		cout << "CTest �Ҹ���" << endl;
		delete[] m_pszData;
		m_pszData = nullptr;
	}
};

class CTestEx :	public CTest
{
	int* m_pnData{ nullptr };
public:
	CTestEx()
	{
		cout << "CTestEx ������" << endl;
		m_pnData = new int;			// CTestEx���� �����Ҵ�
	}
	~CTestEx()				// CTestEx �Ҹ��� ����
	{
		cout << "CTestEx �Ҹ���" << endl;
		delete[] m_pnData;
		m_pnData = nullptr;
	}
};

int main()
{
	CTest *pData = new CTestEx;		// virtual�� ���� �ʾ����Ƿ� ���������� ����

	delete pData;			// ���⼭ ������ �߻�

	pData = nullptr;
}

// 12�� ��
// char������ CTest�� ��������� �����Ҵ� ���־���.

// 14�� ��
// �Ҹ��ڸ� �θ��鼭 �޸� ������ ���ְ� �ִ�.
// ���⼭ �ָ��� ���� �Ҹ��ڸ� virtual�� ����Ͽ� �����Լ��� ������ �־��ٴ� ��.
// 43�� �ٿ��� �ٽ� ����

// 29�� ��
// int������ CTestEx�� ��������� �����Ҵ� ���־���.

// 31�� ��
// �Ҹ��ڸ� ȣ���ϸ鼭 CTestEx�� �޸𸮸� �����ϰ� �ִ�.

// 41�� ��
// ���������� CTest, �������� CTestEx��.
// �����Լ��� ����� �Լ��� �Ҹ��ڹۿ� ����.

// 43�� ��
// ������ �����ϴ� ��~~~~~~~~
// ���⼭ ���������� CTest�� ���� pData�� �޸� �������ְ� �ִ�.
// ������ �޸� ũ��� CTestEx�� ������Ƿ� CTestEx�� �����ڰ� �Ҹ��ٴ� ���� ������.
// pData�� �޸� ������ �ϸ� CTest�� �Ҹ��ڰ� �Ҹ�����, CTestEx�� �Ҹ��ڰ� �Ҹ��� �ʴ´�.
// �׷��� ������ 14�� �� �Ҹ��ڸ� �����Լ��� �������� ���̴�.
// virtual�� ���ϴܿ� �ִ� �ڽ� Ŭ������ �������̵��� �Լ��� ����Ų��.
// �Ҹ��ڴ� ��� �̸��� ���� �ʴ��� �����Լ��� �Ͻɵ�ü�� �ȴٴ� ������ �ϸ� CTestEx�� �Ҹ��ڰ� �Ҹ��� ���� �翬�ϴ�.