#include <iostream>

using namespace std;

class CTest
{
public:
	int m_nData1, m_nData2;
	CTest() : m_nData1(10), m_nData2(20)	// ��� �̴ϼȶ�����
	{
		cout << "����Ʈ ������" << endl;
	}

	void PrintData()
	{
		cout << m_nData1 << endl;
		cout << m_nData2 << endl;
	}
};

int main()
{
	CTest t;
	t.PrintData();
}

// 9��° ��
// ��� �̴ϼȶ������� �̿��Ͽ� ������ �Բ� �ʱ�ȭ�� �ϴ� ���̳ʸ� �ڵ带 �����Ѵ�.
// C++11���� �Ϲ����� ���� �ʱ�ȭ�� ����� ���ÿ� ��������� �ʱ�ȭ�� �� �ִ�.
// ������ �Բ� �ʱ�ȭ�� �ϱ� ������ ������ �ణ ����ϱ⿡ ��������� ������ ȣȯ�� ������ ����Ѵ�.
// �Ϲ����� ���� �ʱ�ȭó�� ����ص� ������ �Ȱ���.