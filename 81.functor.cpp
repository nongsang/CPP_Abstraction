#include <iostream>

using namespace std;

class Add
{
public:
	int operator()(int a, int b)
	{
		cout << "()(int a, int b)" << endl;
		return a + b;
	}

	double operator() (double a, double b)
	{
		cout << "()(double a, double b)" << endl;
		return a + b;
	}
};

void TestFunc(Add &add)				// Ŭ������ �Ķ���ͷ� ���� �Լ���.
{
	cout << "TestFunc()" << endl;
	cout << add(3, 4) << endl;
}

int main()
{	
	Add adder;

	cout << adder(3, 4) << endl;		// ���� ������� �ʳ�
	cout << adder(3.3, 4.4) << endl;	// �̰͵�
	TestFunc(adder);				// �̰� �Լ���ü
}

// 21 ~ 25�� ��
// Ŭ������ �Ķ���ͷ� �޴� �Լ���.
// �׸��� Ŭ������ ����Լ��� ȣ���Ѵ�.
// �߿��ϴ� ����صε���

// 31, 32�� ��
// Ŭ���� ��ü�� �����Ͽ� �����ε��� ����Լ��� ����Ѵ�.

// 33�� ��
// ���⼭ �Լ� ��ü(Functor)��� �θ���.
// �Լ��� ��ü�� �����Ͽ� ��ü�� ����Լ��� ȣ���ϴ� ����̴�.
// �Ѹ���� ��ɿ� �´� �Լ��� �����ϵ� �Լ� ������ ��ü�� ����� ������ �����ϴ� ���̴�.