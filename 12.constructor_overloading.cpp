#include <iostream>

using namespace std;

class CMyData
{
	int m_nData;
public:
	// ����Ʈ �����ڴ� ����.
	CMyData(int nParam) : m_nData(nParam) {};	// �Ķ���Ͱ� �Ѱ� �ִ� ������
	CMyData(int x, int y) : m_nData(x + y) {};	// �Ķ���Ͱ� �ΰ� �ִ� ������
	int GetData() { return m_nData; }
};

int main()
{
	CMyData a(10);
	CMyData b(3, 4);
	//CMyData c;		// �Ұ���

	cout << a.GetData() << endl;
	cout << b.GetData() << endl;
}

// 10, 11��° ��
// �Ķ���͸� 1�� ��� �����ڿ� 2�� �޴� �����ڸ� �����Ͽ���.
// ����Ʈ �����ڸ� ������ �����ڸ� ������ �����ϴ� ���� '������ ���� ����', Ȥ�� '������ �����ε�'�̶�� �Ѵ�.

// 17, 18��° ��
// � �����ڸ� ȣ������ �����Ϸ��� �Ű������� ���� �ڵ����� �����Ѵ�.

// 19��° ��
// ����Ʈ �����ڰ� �����Ƿ� ������ ȣ�� �Ұ�