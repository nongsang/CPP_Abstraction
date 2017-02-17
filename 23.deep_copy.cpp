#include <iostream>

using namespace std;

class CTest
{
	int* m_npData{ nullptr };
public:
	CTest(int nParam)
	{
		cout << "������" << endl;
		m_npData = new int;
		*m_npData = nParam;
	}

	~CTest()
	{
		cout << "�Ҹ���" << endl;
		delete m_npData;
		m_npData = nullptr;			// �̺κ� �߿���
	}

	CTest(const CTest& rhs)
	{
		cout << "���������" << endl;
		m_npData = new int;			// ��������� ���� ����
		*m_npData = *rhs.m_npData;	// ���� ������ ��������� ���� �����Ͽ� ����
	}

	int GetData() const { return *m_npData; }
};

int main()
{
	CTest a(10);
	CTest b(a);

	cout << a.GetData() << endl;
	cout << b.GetData() << endl;
}

// 23��° ��
// ��������ڸ� �������־���.

// 26, 27��° ��
// ��������� Ŭ������ ��������� �����Ҵ��Ͽ���.
// �׸��� ���纻�� ��������� ���� Ŭ������ ��������� �����Ͽ� ���������Ѵ�.

// ���� ���縦 �ϰԵǸ� ���� ������ Ŭ������ ���� �����̵ȴ�.
// �׷��Ƿ� �Ҹ����� �޸� ������ �� �� �ְ� �ȴ�.

// 20��° ��
// m_npData�� �޸� ���� �Ҵ翡 ���Ǿ���.
// ������ �޸𸮰� ������ ���������� �����Ҵ� �Ǿ��� �� ������ ����Ű�� �ְԵȴ�.
// �� ������ ��۸� ������(dangling pointer)��� �Ѵ�.
// �׷��Ƿ� �Ŀ� �Ͼ ���� �̿��� �����ϱ� ���ؼ� nullptr�� �ƹ��͵� ����Ű�� �ʰ� ������ �Ѵ�.