#include <iostream>
using namespace std;

template<typename T>
class CTest
{
	T m_Data;
public:
	CTest(T param) : m_Data(param) { }

	T GetData() const { return m_Data; }
	void SetData(T param) { m_Data = param; }
};

template<>		// ���⼭���� ���ø� Ư��ȭ�� ������شٴ� �ǹ�
class CTest<char*>		// ���¸� �� ����	. ��������� Ư��ȭ�� ����ϰڴٴ� ��
{
	char *m_pData;
public:
	CTest(char *pszParam)
	{
		int nLen = strlen(pszParam);
		m_pData = new char[nLen + 1];
		strcpy_s(m_pData, nLen + 1, pszParam);
	}
	~CTest() { delete[] m_pData; }

	char* GetData() const { return m_pData; }
};

int main()
{
	CTest<char*> a("Hello");		// Ŭ���� ���ø� Ư��ȭ ���
	cout << a.GetData() << endl;
}

// 4 ~ 13�� ��
// �Ϲ����� ���ø� Ŭ������ �������־���.

// 15�� ��
// �������� ���ø� Ư��ȭ�� ����ϰڴٴ� �ǹ�

// 16�� ��
// Ŭ���� ���ø� Ư��ȭ�� ����ϴ� ����̴�.
// Ŭ���� �̸� ���� Ư���ϰ� ����� �ڷ����� �ٿ��ش�.

// 33�� ��
// Ŭ���� ���ø� Ư��ȭ�� ������ Ŭ������ ȣ��ȴ�.

// 65.template_specialization_summary���� �����غ���.