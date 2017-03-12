#include <iostream>

using namespace std;

template<typename T>		// ���ø� ���
class CTest
{
	T m_Data;
public:
	CTest(T param) : m_Data(param) {}
	T GetData() const { return m_Data; }

	operator T() { return m_Data; }
	void SetData(T param) { m_Data = param; }
};

int main()
{
	CTest<int> a(5);		// �ڷ����� ����Ͽ���.
	cout << a << endl;

	CTest<double> b(123.45);
	cout << b << endl;		// �̰͵�

	CTest<char*> c("Hello World!");
	cout << c << endl;		// ��͵�
}

// 5�� ��
// T��� �̸��� �������� ���� �ڷ����� ���ø��̶� �Ѵ�.

// 6 ~ 15�� ��
// �� ��ҵ��� ���ø����� ���� T�� �������־���.
// �̷��� �� ������� Ŭ������ ���ø� Ŭ������� �Ѵ�.

// 19, 22, 25�� ��
// Ŭ������ ���ø����� �ν��Ͻ��� ������ �� ������ �´� �ڷ����� �����Ͽ���.
// ���⼭ ���� �ڵ�� �巯������ �ʰ� ���������θ� �����ȴ�.