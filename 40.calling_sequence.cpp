#include <iostream>

using namespace std;

class CTestA
{
public:
	CTestA() { cout << "CTestA()" << endl; }
	~CTestA() { cout << "~CTestA()" << endl; }
};

class CTestB : public CTestA
{
public:
	CTestB() { cout << "CTestB()" << endl; }
	~CTestB() { cout << "~CTestB()" << endl; }
};

class CTestC : public CTestB
{
public:
	CTestC() { cout << "CTestC()" << endl; }
	~CTestC() { cout << "~CTestC()" << endl; }
};

int main()
{
	cout << "main() ����" << endl;
	CTestC data;
	cout << "main() ��" << endl;
}

// 12�� ��
// CTestB�� ������ �� CTestA�� ����Ͽ���.

// 19�� ��
// CTestC�� ������ �� CTestB�� ����Ͽ���.

// 29�� ��
// ������ �ڽ� Ŭ������ CTestC�� �����Ͽ���.
// ���⼭ CTestC�� �����ں��� ������ �ȴ�.
// ������ �����ڴ� �ֻ��� �θ� Ŭ������ CTestA���� ȣ���� �ȴ�.
// �׸��� CTestB, CTestC������ �Ҹ��ڰ� �Ҹ���.
// ������ �Ҹ��ڴ� ������ �ڽ� Ŭ������ CTestC���� ȣ��ȴ�.
// ���ʷ� CTestB, CTestA������ �Ҹ��ڰ� �Ҹ��� �ȴ�.