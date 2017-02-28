#include <iostream>

using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest()" << endl; }
	CTest(int nParam) { cout << "CTest(int)" << endl; }
	CTest(double dParam) { cout << "CTest(double)" << endl; }
};

class CTestEx : public CTest		// ���
{
public:
	CTestEx() { cout << "CTestEx()" << endl; }		// CTest�� ����Ʈ ������ ȣ��
	CTestEx(int nParam)	: CTest(nParam)		// CTest�� int ������ ȣ��
	{
		cout << "CTestEx(int)" << endl;
	}
	CTestEx(double dParam) : CTest(dParam)	// �̰͵� CTest�� double ������ ȣ��
	{
		cout << "CTestEx(double)" << endl;
	}
};

int main()
{
	CTestEx a;
	CTestEx b(5);
	CTestEx c(3.3);
}

// 8 ~ 10�� ��
// ����Լ� �����ε��� �Ͽ���.
// default, int, double���̴�.

// 13�� ��
// ����� �޾Ҵ�.

// 17�� ��
// ��� �̴ϼȶ����� ���·� CTest�� nParam���� �����Ͽ���.
// �̷ν� CTestEx�� int�� ��ȯ �����ڰ� ȣ��Ǹ� CTest�� int�� ��ȯ �����ڵ� ���� ȣ��ȴ�.

// 21�� ��
// �� ���� ��� �̴ϼȶ����� ���·� CTest�� dParam���� �����Ͽ���.
// �׷��⿡ CTestEx�� double�� ��ȯ �����ڰ� ȣ��Ǹ� CTest�� double�� ��ȯ �����ڵ� ���� ȣ��ȴ�.