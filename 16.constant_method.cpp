#include <iostream>

using namespace std;

class CTest
{
	int m_nData{ 0 };
public:
	CTest(int nParam) : m_nData(nParam) {};
	~CTest() {};

	int GetData() const { return m_nData; }		// ����� �޼���

	int SetData(int nParam) { m_nData = nParam; }	// ���ʹ� ��������� ��� �Ұ�
};

int main()
{
	CTest a(10);
	cout << a.GetData() << endl;
}

// 12��° ��
// �Լ� �ٷ� �ڿ� const�� ����Ͽ� �������� ������ �����ִ�.
// �׳� �б⸸ �ϱ� ���ؼ� const�� ����ϴ� ���̴�.
// const�� �󸶳� �� �����Ŀ� ���� ���α׷����� �Ƿ��� ������ �� �ִ�.

// 14��° ��
// ������ ��� ���� �Ҵ��� �ϱ� ������ const�� ���Ұ�