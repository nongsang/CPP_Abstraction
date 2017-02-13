#include <iostream>

using namespace std;

class CTest
{
	mutable int m_nData{ 0 };			// ��������� ���ͺ�� ����
public:
	CTest(int nParam) : m_nData(nParam) {};
	~CTest() {};

	int GetData() const
	{
		m_nData = 20;		// ����� �޼����ӿ��� ��������� ���� �Ҵ��Ѵ�?
		return m_nData;
	}

	int SetData(const int& nParam) { m_nData = nParam; }
};

void TestFunc(const int& nParam)
{
	// ����� ���������� �Ϲ� ������ ����ȯ
	int &nNewParam = const_cast<int&>(nParam);		// int ���������� const ����ȯ�� �߱� ������ ���� ���� ���
	nNewParam = 20;
}

int main()
{
	CTest a(10);
	cout << a.GetData() << endl;

	int nData = 10;
	TestFunc(nData);
	cout << nData << endl;
}
// 1. mutable
// 7��° ��
// ��������� mutable�� �����Ͽ���.
//
// 14��° ��
// ����� �޼����ӿ��� ��������� mutable�̱� ������ �� ������ �����ϴ�.

// 2. const_cast<>()
// 21��° ��
// �Ű������� const int ���������� ���ǵǾ� �ִ�.
//
// 24��° ��
// int ���������� nNewParam�� �����Ͽ� nData���� �ٲٴ� �۾��� �Ѵ�.
// ������ �Ű������� const�̹Ƿ� ���������� ������ �����ϴ°� �Ұ����ϴ�.
// const_cast<>()�� ����Ͽ� const���� ����ȯ�Ͽ� ������ �����ϰ� �ٲ۴�.
//
// 25��° ��
// const_cast<>()�� ����ȯ�� �Ǿ� �����ϸ� �������̹Ƿ� nData���� �ٲ�� �ȴ�.

// �� �ΰ��� ����� ���߿� ���������� ���� ����ϴ� ������ �Ϲ������� ������� �ʴ´�.