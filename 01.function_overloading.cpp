#include <iostream>
using namespace std;

int Add(int a, int b)			// Add(int, int)
{
	cout << "Add(int, int) : ";
	return a + b;
}

int Add(int a, int b, int c)	// Add(int, int, int)
{
	cout << "Add(int, int, int) : ";
	return a + b + c;
}

double Add(double a, double b)	// Add(double, double)
{
	cout << "Add(double, double) : ";
	return a + b;
}

int main()
{
	cout << Add(1, 2) << endl;
	cout << Add(1, 2, 3) << endl;
	cout << Add(1.3, 2.5) << endl;
}

// 4, 10, 16��° ��
// �Լ��� �̸��� ���� �Ķ���͸� �ٸ���.
// C������ ���� �̸��� ���� �Լ��� ������ �ʴ´�.
// C++������ ���� �̸��� ���� �Լ���� �ϴ��� �Ķ���Ͱ� �ٸ��� ���ȴ�.
// �̸� '�Լ� �����ε�'�̶�� �Ѵ�.
//
// �Լ� �����ε��� ��ȯ��, �Լ� �̸��� ������ ���� �ʰ� �Ķ������ ����, �ڷ����� ������ �ش�.
// ���� ����Ʈ �Ķ���Ͷ� ���̸� ��ȣ���� �����Ѵ�.
// ���� C++������ '�Լ� ���ø�'�� �����Ѵ�.
// �ڼ��� ������ '�Լ� ���ø�'���� ����