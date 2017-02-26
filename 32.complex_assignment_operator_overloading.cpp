#include <iostream>

using namespace std;

class CTest
{
	int* m_npData{ nullptr };
public:
	explicit CTest(int nParam)
	{
		cout << "��ȯ ������" << endl;
		m_npData = new int(nParam);
	}

	~CTest()
	{
		cout << "�Ҹ���" << endl;
		if (m_npData != nullptr)
			delete[] m_npData;

		m_npData = nullptr;
	}

	operator int()
	{
		cout << "����ȯ ������" << endl;
		return *m_npData;
	}

	CTest& operator=(const CTest& rhs)
	{
		cout << "�ܼ� ���� ������" << endl;
		if (this == &rhs)
		{
			cout << "�������� ����" << endl;
			return *this;
		}

		if (m_npData != nullptr)
			delete[] m_npData;

		m_npData = new int(*rhs.m_npData);
		return *this;
	}

	CTest& operator+=(const CTest& rhs)
	{
		cout << "���� ���� ������" << endl;

		int *pnNewData = new int(*m_npData);	// �̰� �� ��򸱸� �ϴ�.

		*pnNewData += *rhs.m_npData;

		if (m_npData != nullptr)
			delete[] m_npData;		// ������ �����Ҵ�� �޸� ����

		m_npData = pnNewData;	// �����Ҵ� �� ��ġ�� ���ο� ������ ����

		//*m_npData += *rhs.m_npData;		// �̰͸� �־ �����ѰŰ�����? �̰� �����Բ� ���庼��?

		return *this;
	}
};

int main()
{
	CTest a(0), b(3), c(4);

	a += b;

	cout << a << endl;

	a += c;

	cout << a << endl;
}

// 46��° ��
// ���� ���� �����ڸ� �������־���.

// 50��° ��
// ���ο� ������ �����Ҵ��Ѵ�.
// �����Ҵ��ϸ� ���� ����µ� ���ÿ��� �����Ѵ��� �����Ҵ��ϸ� �ȵ�?
// ������ ��ü�� �̹� �����Ҵ��� �Ǿ� �ִ�.
// �׷��� ������ ���� ���ÿ��� ������ ������ ����.

// 52��° ��
// ���� ���ϰ� ���� �����Ϳ� �����Ѵ�.

// 54, 55��° ��
// ������ �ִ� ���� �Ҵ�� �����Ͱ� �ִٸ� �޸� �����Ѵ�.
// �ֳ��ϸ� �� �޸𸮿� �÷��� �ִ� pnNewData�� ��ġ�� ��ü�� ��ġ�� �����ϱ� ���ؼ���.

// 57��° ��
// �����Ҵ�� ��ġ�� ���Ӱ� �����Ҵ��ϰ� ���� ������ ������ �ּҰ��� �����Ͽ� ����ϱ� �����̴�.

// 59��° ��
// ���ݱ��� ������ ���ߴµ� �̰� �����̸� ���� ���� �����ڴ� �� ���ǰ� �Ȱ� �ƴѰ�?
// �׳� ������ �ִ� �����Ϳ� ������ �����͸� �����ؼ� �����Ѵٴ� ���ε�?
// ���� �̷��� ������ ������ �ֳ� �ʹ�.
// �����Բ� ���庸��

// 69, 73��° ��
// ���� ���� �����ڸ� �����Ͽ� ������ ���Ҵ�.
// 59��° �ٸ� �־ �������� ���ư���.
// ���������� ������ �ִ��� �����Բ� ���庸��.