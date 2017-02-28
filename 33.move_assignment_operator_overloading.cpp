#include <iostream>

using namespace std;

class CTest
{
	int* m_npData{ nullptr };		// �����Ҵ��ϱ� ���ؼ� int*������ �س���.
public:
	explicit CTest(int nParam)
	{
		cout << "��ȯ ������" << endl;
		m_npData = new int(nParam);
	}

	~CTest()
	{
		cout << "�Ҹ���" << endl;
		if (nullptr != m_npData)
			delete[] m_npData;
	}

	operator int()
	{
		cout << "����ȯ ������" << endl;
		return *m_npData;
	}

	CTest(const CTest& rhs)// : m_nData(rhs.m_nData)	// ������ ���� ���� ������
	{
		cout << "���� ������" << endl;
		m_npData = new int(*rhs.m_npData);		// ������ ���� ���� �����ڿʹ� �ٸ���?
	}

	CTest operator+(const CTest& rhs)		// ���� ������ ����
	{
		/*CTest result(0);
		result.m_nData = this->m_nData + rhs.m_nData;	// ������ ���� ���� ������ ����
		return result;*/

		cout << "���� ������" << endl;
		return CTest(*m_npData + *rhs.m_npData);		// �̰͵� ���� �����Ŷ� �ٸ���
	}

	CTest& operator=(const CTest& rhs)
	{
		cout << "�ܼ� ���� ������" << endl;
		if (this == &rhs)
		{
			cout << "�������� ����" << endl;
			return *this;
		}

		if (nullptr != m_npData)
			delete[] m_npData;

		m_npData = new int(*rhs.m_npData);
		return *this;
	}

	CTest& operator+=(const CTest& rhs)
	{
		cout << "���� ���� ������" << endl;
		int *pnNewData = new int(*m_npData);

		*pnNewData += *rhs.m_npData;

		if (nullptr != m_npData)
			delete[] m_npData;

		m_npData = pnNewData;

		//*m_npData += *rhs.m_npData;		// �̰͸� �־ �����ѰŰ�����? �̰� �����Բ� ���庼��?

		return *this;
	}

	CTest& operator=(CTest&& rhs)
	//CTest(const CTest&& rhs) : m_nData(rhs.m_nData)		// ���� ���� �̵� ���� ������
	{
		cout << "�̵� ���� ������" << endl;

		m_npData = rhs.m_npData;		// rhs.m_npData�� �ּҰ��� ���� ���� �Ŀ�
		rhs.m_npData = nullptr;			// ���� ��ü�� �ּҰ��� ���� ���ϰ�

		return *this;
	}
};

int main()
{
	CTest a(0), b(3), c(4);

	a = b + c;		// �ӽð�ü�� �����Ǵµ�?

	cout << a << endl;

	a = b;			// �̰� �ӽð�ü ����

	cout << a << endl;
}

// �����Ҵ��ϱ� ���ؼ� int*�� �����ߴ�.
// �̰� �ϳ��� ������ �����ε� �Լ� ������ ��� �ٲ���� �˾ƺ���

// 28 ~ 32��° ��
// ���� �����ڸ� �������־���.
// ���� ���� ���� �����ڿʹ� ������ �ٸ���.
// ���� ���� ������ ��� �̴ϼȶ������� �̿��Ͽ� ���� �����ϴ� ���̾���.
// ������ ������ ���Ӱ� �����Ҵ��� �ϰ� �ִ�.
// �����Ҵ��� ��ǥ�̱� �����̴�.

// 34 ~ 42��° ��
// ���� �����ڸ� �������־���.
//
// 34��° �� CTest�� �Լ���� �Ϳ� �ָ�
// �ӽð�ü�� ��Ÿ���� �ڷ����̴�.
// �ӽð�ü�� ���� ��ȯ�Ѵٴ� ���̱� ������ CTest&�� �ƴϴ�.
// CTest&�� ���� �ȴٸ� ������ �ӽð�ü�� �������� ������ ������ ������?
// �ڼ��Ѱ� 30.addition_operator_overloading�� ���������� �о����
//
// 36 ~ 38��° ��
// ���Ӱ� ��ü�� �����ϰ� ���ο� ��ü �ȿ� ���� ���Ͽ� �� ���� ��ȯ�ϴ� ������.
// �̰� ���� ���� �ڵ��ε� ��������� int���� ���� ������.
// ������ �����Ҵ��� �ؾ��ϴ� ��Ȳ
//
// 41��° ��
// ������ �������� ���� ���Ͽ� ���Ӱ� ��ü�� �����Ѵ�.
// �׸��ϸ� �� ���� ���� ���� ���� ��ü�� ���Ӱ� �����Ҵ��� �ȴ�.
// �� ������ '�����Ҵ�'�̴�.
// ������ ���� �ڵ忡���� �����Ҵ��� �ȵǱ� ������ ��ü�� ���� �����ϴ� ���̴�.

// 77 ~ 86��° ��
// �̵� ���� �����ڸ� �������־���.
//
// 77��° �� CTest&������ �������־���.
// CTest������ �θ��� ���� �����ڰ� �Ҹ��� �ǹǷ� ����
//
// 78��° ��
// ������ ���� �ڵ��̴�.
// Ŭ�������� �ƴϾ��� ������ ��� �̴ϼȶ������� ����� �� �־���.
//
// 82, 83��° ��
// ���� ���縦 �ϰ� ������ ��ü�� ��������� ���� ���ϰ� nullptr�� �������.

// 93��° ��
// ���� �߿��� �κ��̴�.
// ���⼭ �ӽð�ü�� �̿��� ������ �̷������.
// ���� ���������� 82, 83��° �� ������ �̷������.
// �����ϴ� ��ü�� �ӽð�ü�� ���� ������ �̵� ���� ������ �Ǳ� ����
// ������ �ִ� �����ʹ� ���� �����Ѵ�.
// ���� �ٲ��ֱ� ���� ���������� ���� ��ü�� �������� �ּҰ��� �����Ͽ� �ִ´�.
// �׸��� ���������� ���� �����ʹ� ���� ���ϰ� nullptr�� ������ش�.
// ������ ������ ��ü�� �ӽð�ü�� ������ �� ������� ����
// ���� ����� �����Ҵ�� �ּҰ��� ����Ҷ� �����ϴ�.
// ���� �̵� ���� �����ڰ� �����ٸ� �ܼ� ���� �����ڰ� �ҷ��� ���̴�.
// ���� ���Ӱ� �Ҵ��ϴ� �ٺ����� ���� ��.
// ���ɿ��� �ǿ����� ������ ���̴�.
// �̵� ���� �����ڰ� �ҷȱ⿡ �ּҰ��� �ٲٴ� ������ �Ͽ� ������ ����÷ȴ�.

// 97��° ��
// �ܼ� ���� �����ڰ� �Ҹ���.
// ������ �����ϴ� ��ü������ �����̱� �����̴�.