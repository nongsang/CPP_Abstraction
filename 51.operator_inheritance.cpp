#include <iostream>

using namespace std;

class CTest
{
protected:
	int m_nData{ 0 };
public:
	CTest(int nParam) : m_nData(nParam) {}

	CTest operator+(const CTest &rhs)
	{
		return CTest(m_nData + rhs.m_nData);
	}

	CTest operator=(const CTest &rhs)
	{
		m_nData = rhs.m_nData;

		return *this;
	}

	operator int() { return m_nData; }
};

class CTestEx : public CTest
{
public:
	CTestEx(int nParam) : CTest(nParam) {}

	/*CTestEx operator+(const CTestEx &rhs)
	{
		return CTestEx(static_cast<int>(CTest::operator+(rhs)));
	}*/
	using CTest::operator+;
	using CTest::operator=;
};

int main()
{
	CTest a(3), b(4);
	cout << a + b << endl;		// CTest�� ���Կ����ڸ� �����ε����־����Ƿ� ������ ������ ���� �ʴ´�.

	CTestEx c(3), d(4), e(0);

	e = c + d;		// Ŭ������ �´� ���Կ����ڰ� ��� ������ ������ ����.
	cout << e << endl;
}

// 43�� ��
// CTest ���� ���ϴ� ���������ڸ� �����ε��Ͽ����Ƿ� ������ ������ �߻����� �ʴ´�.

// 47�� ��
// CTestEx ���� ���ϴ� ���Կ����ڰ� ��� ������ ������ �߻��Ѵ�.
// ���⼭ �߿��� ���� ���Կ����ڿ��� ������ ������ ���ٴ� ���̴�.
// CTest�� �ִ� ���������ڴ� �ڷ����� CTest�̴�.
// �̴� �ܼ� ������ r-value�� CTest���̶�� ��.
// ���� ������� �޴� �ڷ����� CTest���� �ϴ� ���̴�.
// ������ e�� CTestEx���̹Ƿ� ������ ���� ���̴�.
// �̸� �ذ��ϱ� ���ؼ��� CTestEx�� ���������� �����ε��� ���־�� �Ѵ�.

// 32 ~ 35�� ��
// CTestEx operator+(const CTestEx &rhs)�� �������ش�.
// operator+�� ȣ�����ְ� ���� ����� ����� CTestEx ��ü�� ��ȯ���ִ� ��.
// �̰� �±������� �� ���ϰ� �������� �� �ִ�.

// 36, 37�� ��
// �˸��̴� �θ�Ŭ������ ���� ����ϰ� �������̽��� ������ �� �ִ� ���.
// using���� ����Ŭ������ ������ �Լ����� �״�� �����Ѵٰ� �����ϴ� ���̴�.