#include <iostream>

using namespace std;

class CTest
{
	int* m_pnData{ nullptr };
public:
	explicit CTest(int nParam)
	{
		cout << "��ȯ ������" << endl;
		m_pnData = new int(nParam);
	}

	~CTest()
	{
		cout << "�Ҹ���" << endl;
		if (m_pnData != nullptr)
			delete[] m_pnData;

		m_pnData = nullptr;
	}

	operator int()
	{
		cout << "����ȯ ������" << endl;
		return *m_pnData;
	}

	CTest& operator=(const CTest& rhs)
	{
		cout << "�ܼ� ���� ������" << endl;
		if (this == &rhs)
		{
			cout << "�������� ����" << endl;
			return *this;
		}

		if (m_pnData != nullptr)
			delete[] m_pnData;

		m_pnData = new int(*rhs.m_pnData);
		return *this;
	}

	CTest& operator+=(const CTest& rhs)
	{
		cout << "���� ���� ������" << endl;

		int *pnNewData = new int(*m_pnData);	// �̰� �� ��򸱸� �ϴ�.

		*pnNewData += *rhs.m_pnData;

		if (m_pnData != nullptr)
			delete[] m_pnData;		// ������ �����Ҵ�� �޸� ����

		m_pnData = pnNewData;	// �����Ҵ� �� ��ġ�� ���ο� ������ ����

		//*m_npData += *rhs.m_npData;		// �̰͸� �־ �����ѰŰ�����? �̰� �����Բ� ���庼��?

		return *this;
	}

	int operator==(const CTest& rhs)
	{
		if (m_pnData != nullptr && rhs.m_pnData != nullptr)
			if (*m_pnData == *rhs.m_pnData)
				return 1;

		return 0;
	}

	int operator!=(const CTest& rhs)
	{
		if (m_pnData != nullptr && rhs.m_pnData != nullptr)
			if (*m_pnData != *rhs.m_pnData)
				return 1;

		return 0;
	}
};

int main()
{
	CTest a(3), b(3), c(4);

	if (a == b)
		cout << "same" << endl;
	if (a != c)
		cout << "different" << endl;
}

// 64 ~ 71�� ��
// operator==()�� �����ε� �Ͽ���.
// Ŭ������ ���� �ִ��� Ȯ���� �� ���� ���Ѵ�.
// ���� ������ 1 ��ȯ, �ٸ��� 0 ��ȯ

// 73 ~ 80�� ��
// operator!=()�� �����ε� �Ͽ���.
// ���������� Ŭ������ ���� �ִ��� Ȯ���� �� ���� ���Ѵ�.
// ���� ������ 0 ��ȯ, �ٸ��� 1 ��ȯ

// �� �Լ��� ��ȯ������ bool�� �ᵵ �� �� ������, ������ int���̶���.
// �˾Ƽ� �� ����.