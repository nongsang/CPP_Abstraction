#include <iostream>

using namespace std;

class CTest
{
	int m_nData;
	static int m_nCount;	// ���� ������� ����
public:
	CTest(int nParam) : m_nData(nParam) { m_nCount++; }
	~CTest() {};

	int GetData() { return m_nData; }
	void ResetCount() { m_nCount = 0; }

	static int GetCount() { return m_nCount; }	// ���� �޼��� ���� �� ����
};

int CTest::m_nCount = 0;	// CTest Ŭ������ ���� �⼭���� ����

int main()
{
	CTest a(5), b(10);	// Ŭ������ �ν��Ͻ� ����

	cout << a.GetCount() << endl;	// ���� ��������� ����
	b.ResetCount();				// ���� ��������� ����

	cout << CTest::GetCount() << endl;	// �ν��Ͻ��� ���� ���� ����
}

// 8��° ��
// ���� ������� ������ �Ͽ���.

// 10��° ��
// �ν��Ͻ��� ������ �� ���� ���� ��������� +1�� �Ѵ�.

// 16��° ��
// ���� �޼��� ���Ǹ� �Ͽ���.
// �̰� ���� ������ 28��° ���� ���� �ȴ�.

// 19��° ��
// �������� ����� ��������� Ŭ���� �ܺο����� ���ǰ� �����ϴ�.
// Ŭ���� ���ο��� ���ǰ� �Ұ���
// �ݴ�� ���� ������ �ȵ� m_nData ��������� �ܺο��� ���ǰ� �Ұ���

// 23��° ��
// �Ϲ������� Ŭ������ ������ ����Ѵٰ� ����� ���ÿ� �ν��Ͻ��� �������ִ� �����̴�.

// 25, 26��° ��
// �Ϲ������� ����Լ��� �����ϴ� ������� ���� ����Լ��� ������ ������ �����ϴ�.

// 28��° ��
// �������� ����� ����Լ��� �ν��Ͻ��� ������� �ʰ� ������ �����ϴ�.