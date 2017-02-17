#include <iostream>

using namespace std;

class CTest
{
	int m_nData{ 0 };
	
public:
	CTest(int nParam) : m_nData(nParam)
	{
		cout << "CTest(int)" << endl; 
	}

	~CTest() { cout << "�Ҹ���" << endl; }

	CTest(const CTest &rhs) : m_nData(rhs.m_nData)	// = delete;
	{
		cout << "���� ������" << endl;
	}

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
};

void TestFunc(CTest cParam)		// �Ű������� Ŭ�����̹Ƿ� ������� �߻�
//void TestFunc(CTest& cParam)
//void TestFunc(const CTest& cParam)
{
	cout << "TestFunc()" << endl;

	cParam.SetData(20);	// �Լ����� �ν��Ͻ��� ���� ����
}

int main()
{
	cout << "main() ����" << endl;

	CTest a(10);
	TestFunc(a);

	cout << "a : " << a.GetData() << endl;
	cout << "main() ��" << endl;
}

// 26��° ��
// �Ű������� Ŭ�����̹Ƿ� ��������� �߻��Ѵ�.

// 32��° ��
// �Լ� ������ ����Լ� ���� ������ �õ��ϰ� �ִ�.

// ���⼭�� �������� ��Ȯ�ϴ�.
// 1. �������� ��������� �߻�
// 2. call by value�̹Ƿ� ���� ������ ���� �ʴ´�.

// �� �������� �ذ��ϱ� ���ؼ��� ������ �ؾ� �ϴ°�

// 1. 27��° �� '������'�� �̿��Ͽ� ������� ����
// 2. 17��° �� 'delete'�� ������� ��õ ����
// 3. 28��° �� const '������'���� ����Ͽ� ���� ������ ������� �ʴ´�.

// ��������� �� ���� ������ �� ������ ������ ���̵ȴ�.