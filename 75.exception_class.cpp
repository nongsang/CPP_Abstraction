#include <iostream>

using namespace std;

class CException
{
	int m_nErrorCode;
	char m_szMsg[128];
public:
	CException(int nCode, const char *pszMsg) : m_nErrorCode(nCode)
	{
		strcpy_s(m_szMsg, sizeof(m_szMsg), pszMsg);
	}

	int GetErrorCode() const { return m_nErrorCode; }
	const char* GetMessage() { return m_szMsg; }
};

int main()
{
	try
	{
		int nInput = 0;
		cout << "���� ���� : ";
		cin >> nInput;

		if (nInput < 0)
		{
			CException exp(10, "���� ������ �Է��ؾ� �մϴ�.");	// ���⼭ ��ü ����
			throw exp;
		}
	}

	catch (CException &exp)		// Ŭ���� �ν��Ͻ��� �޴´�. ����������
	{
		cout << "ERROR CODE [" << exp.GetErrorCode() << "]" << exp.GetMessage() << endl;
	}
}

// 29�� ��
// �Է°��� �Ǵ��Ͽ� �����ڵ带 �����ִ� ��ü�� �����Ѵ�.
// �׸��� ��ü�� catch�� ��ü�� �����ش�.

// 34�� ��
// ��ü�� �޾Ƽ� ����ó���� �Ѵ�.
// ���⼭ �߿��� ���� ���������� �޴´ٴ� ���̴�.
// ��ü�� ũ�Ⱑ ũ�⶧���� ���������� �̸��� ����Ͽ� ȣ���ϴ� ���� �ξ� ����.

// ��ó�� ����ó�� Ŭ������ ����� ����ϸ� ���α׷� ���ο� ������ �ϴ� ��� ���� ������ �� Ŭ�������� ���� �� �ִ�.
// ���� ������ ������ ���� ��Ȳ���� ��å������ �����ϱ� �����ϸ� ������ϱ⵵ �ξ� �����ϴ�.
// ���� ������Ʈ�� ���� ���̶�� ���� �׷���.