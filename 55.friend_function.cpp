#include <iostream>

using namespace std;

class CTest
{
private:
	int m_nData;		// private�� ����� ���������.
public:
	CTest(int nParam) : m_nData(nParam) {}
	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	friend void PrintData(const CTest &rData);		// �ܺο��� �����ϴ� �Լ��� friend�� ����, �Լ��� ������ �ᵵ ����.
};

void PrintData(const CTest& rData)
{
	cout << "PrintData() : " << rData.m_nData << endl;		// ���� �߿�
}

int main()
{
	CTest a(5);
	PrintData(a);
}

// 14�� ��
// �ܺο��� �����ϴ� �Լ��� friend�� �����Ͽ���.
// �Լ��� ������ �ᵵ ����.
// friend void PrintData(const CTest&)�� �ᵵ �ȴٴ� ���̴�.

// 19�� ��
// �ܺ� �Լ����� private����� ��������� �����Ͽ� ����ϰ� �ִ�.
// GetData()�� �ƴ϶� �ٷ� ������ ������ ���� friend�� ���̴�.

// �غ����� ��ü���� �����ߴµ� �� �����ִ� friend�� ����?
// ������ �����ϰ� �����ϰų�, �������ִ��� ���� ����ϴ� ������ friend�� ���� �� �ִ�.