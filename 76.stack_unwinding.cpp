#include <iostream>

using namespace std;

void TestFunc1()
{
	cout << "TestFunc1 ����" << endl;
	//throw 0;
	cout << "TestFunc1 ��" << endl;
}

void TestFunc2()
{
	cout << "TestFunc2 ����" << endl;
	TestFunc1();
	cout << "TestFunc2 ��" << endl;
}

void TestFunc3()
{
	cout << "TestFunc3 ����" << endl;
	TestFunc2();
	cout << "TestFunc3 ��" << endl;
}

int main()
{
	try
	{
		TestFunc3();
	}

	catch (...)
	{
		cout << "Exception handling" << endl;
	}
}

// 5 ~ 24�� ��
// �Լ��� ȣ���Ͽ� ���ÿ� �ϳ��� �״´�.
// ������ �Լ��� ��ȯ�Ϸ��� �������� ��ȯ�ϰԲ� ���α׷����ؾ� �Ѵ�.
// TestFunc3���� �����ؼ� TestFunc1���� ���ʷ� �Լ����� ȣ���ϴ� �Լ����̴�.
// ���������� �Լ������� �Լ��� ȣ���ϴ� ������� ����ȴ�.
// �̴�� ���� ���Լ����� �� ����Ǵ� ��ó�� ���δ�.

// 8�� ��
// 0�� ������.
// ���� 0�� ������ �Ǹ� catch�� ��� �ڷ����� �ްԲ� �Ǿ������Ƿ� TestFunc1()���� ����ó���� �߻��Ѵ�.
// ����ó���� �Ǹ� ���α׷��� ��ٷ� ����ȴ�.
// �׷� �Լ���ȯ�� ����� �̷������ �ƴѰ� ������ ����� ��ȯ�� �ȴ�.
// main()�� ���ÿ� �����ְ� ����� TestFunc3()���� TestFunc1()���� ��ȯ�� �ȴ�.
// �Ѹ���� TestFunc3()�� ȣ��Ǳ� ������ '�ǵ�������'��� ǥ���ϴ°� �����ϰڴ�.
// �̸� '���� Ǯ��'��� �Ѵ�.

// ��ó�� ������ ����ó���� �̿��ϸ� ������ �ڵ����� Ǯ���� �ڵ嵵 ����������.