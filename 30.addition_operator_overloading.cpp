#include <iostream>

using namespace std;

class CTest
{
	int m_nData{ 0 };
public:
	CTest() { cout << "����Ʈ ������" << endl; }
	CTest(int nParam) : m_nData(nParam) { cout << "��ȯ ������" << endl; }
	~CTest() { cout << "�Ҹ���" << endl; }

	CTest(const CTest& rhs) : m_nData(rhs.m_nData)
	{
		cout << "���� ������" << endl;
	}

	CTest(const CTest&& rhs) : m_nData(rhs.m_nData)
	{
		cout << "�̵� ������" << endl;
	}

	operator int() const		// ����ȯ ������ ����
	{
		cout << "����ȯ ������" << endl;
		return this->m_nData;
	}

	CTest& operator=(const CTest& rhs)		// ���� ������ ����
	{
		cout << "���� ������" << endl;
		this->m_nData = rhs.m_nData;
		return *this;
	}

	CTest operator+(const CTest& rhs)		// ���� ������ ����
	{
		cout << "���� ������" << endl;
		CTest result(0);
		result.m_nData = this->m_nData + rhs.m_nData;
		return result;
	}
};

int main()
{
	CTest a(0), b(3), c(4);

	a = b + c;			// a = b.operator+(c); == a.operator=(b.operator+(c));

	cout << a << endl;
}

// 23��° ��
// ����ȯ �����ڸ� �������־���.

// 36��° ��
// ���� �����ڸ� �������־���.
// ���⼭ �߿��� ���� ���Կ����ڿʹ� �ٸ� ������ ���δٴ� ���̴�.
// �ڷ����� �������� �ƴ� Ŭ�������̴�.
// �Դٰ� 39��° �� ���ο� ��ü�� �����Ͽ���.
// ���ο� ��ü�� ���� ��������� ������ ��������� ���Ͽ� ������ ���ο� ��ü�� ��ȯ�Ѵ�.
// ������ �ִ� b, c ��ü�� ���ϴ� b = b + c; ���� ������ ������ �ʴ´�.
// �ֳ��ϸ� ���� ������ �� ���Ŀ��� �ӽð�ü�� �����ϱ� �����̴�.
// �׷��� ������ b = b + c;���� ������ ������ b�� ���� �ٲ� ���·� �����̵ȴ�.
// ���� a = b + c;�� �ϰ� �� ��� a�� b�� ���� ���� ���·� �����̵ȴ�.
// a�� a�̰� b�� b���� �Ѵ�.
// �׷��Ƿ� ��ü�� �����ϵ� ������ ����� ���̱� ������ �ƹ����Գ� ������ �س��� �Ѵ�.
// ���¸� �� �������.

// 49��° ��
// a = b.operator+(c);��� �ؼ��� �����ϴ�.
// �̴� a.operator=(b.operator+(c));��� �� �ؼ��� �����ϴ�.
// ���� �����ڿ� ���� �����ڰ� �Ҹ��� �ȴ�.

// 51��° ��
// 23��° �ٿ��� ����ȯ �����ڸ� �������־����Ƿ� a�� �ҷ��� static_cast<int>(a)�� �ڵ����� ȣ��Ǹ� ����Ѵ�.