#include <iostream>

using namespace std;

class CTestA
{
protected:
	char* m_npData{ nullptr };			// �����Ҵ�� ����
public:
	CTestA()
	{
		cout << "CTestA()" << endl;
		m_npData = new char[32];		// �����Ҵ�
	}
	~CTestA()
	{
		cout << "~CTestA()" << endl;
		delete[] m_npData;				// �޸� ����
	}
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
	~CTestC()
	{
		cout << "~CTestC()" << endl;
		delete[] m_npData;				// ���⵵ �޸� ����?
	}
};

int main()
{
	cout << "main() ����" << endl;
	CTestC data;
	cout << "main() ��" << endl;
}

// 8�� ��
// �����Ҵ������ ������ ������ �����Ͽ���.

// 13�� ��
// char�� 32�� ��ŭ �迭�� �����Ҵ� �Ͽ���.

// 18�� ��
// �����Ҵ� ������ �޸� ������ ���ְ� �ִ�.

// 36�� ��
// �ڽ� Ŭ�������� �޸𸮸� ���ش�.
// ���⼭ ���� �߻�
// �θ� Ŭ�������� �����Ҵ��Ͽ����� �ڽ� Ŭ�������� �Ҹ��ڰ� �Ҹ��鼭 �޸𸮸� �������� �� �ִ�.
// �ٸ� �θ� Ŭ������ �Ҹ��ڰ� ���߿� �Ҹ��鼭 �� �޸������� �ȴ�.
// �׷��� ������ ������ �߻��Ѵ�.

// ���⼭ 2���� ������ ��
// 1. �ڽ� Ŭ������ �θ� Ŭ������ ��������� ���⿬���ϸ� �ȵȴ�.
// 2. �ڽ� Ŭ���� �����ڿ��� �θ� Ŭ���� ��������� �ʱ�ȭ�ϸ� �ȵȴ�.
//
// ���������� �θ� Ŭ�������� ����� ������ �ڽ�Ŭ�������� �����ϸ� �ȵȴ�.