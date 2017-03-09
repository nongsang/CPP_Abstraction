#include <iostream>

using namespace std;

class CTest
{
	int m_nData{ 0 };
public:
	int GetData() const
	{
		cout << "getter" << endl;
		return m_nData;
	}
	void SetData(const int nParam)
	{
		cout << "setter" << endl;
		m_nData = nParam;
	}
};

class CTestEx : public CTest
{
public:
	void SetData(const int nParam)
	{
		if (nParam < 0)
			CTest::SetData(0);

		else if (nParam > 10)
			CTest::SetData(10);
	}
};

int main()
{
	CTestEx a;
	CTest &rData = a;		// �̰� �̻��ϴ�.
	rData.SetData(15);		// � ����Լ��� ȣ���� �ǳ�? CTest? CTestEx?
	cout << rData.GetData() << endl;

	CTest *pData = new CTestEx;		// �̰� �̻��ϴ�?
	pData->SetData(12);
	cout << pData->GetData() << endl;
	delete pData;
	pData = nullptr;
}

// 36�� ��
// �������� �������� ��� ���ؼ� �ڽ� Ŭ������ CTestEx�� �����Ͽ���.
// �̸� '������'�̶�� �Ѵ�.

// 37�� ��
// �θ� Ŭ������ CTest�� ���������� �����ϸ� ������ a�̴�.
// �̸� '��������'�̶�� �Ѵ�.
// �ڽ� Ŭ������ �θ� Ŭ������� ���ϴ� ���� �̻��� ���� �ƴϴ�.
// ���� �θ� Ŭ������ '���'�̰�, �ڽ� Ŭ������ '��ũ���׽�'�϶�,
// '��ũ���׽��� ����̴�' ��� ���� Ʋ���� �ʱ� �����̴�.
// �������� �ƴ� CTest���̿��� �������� ����.
// ���� ���簡 �̷������ �͸� �ٸ� ��

// 38�� ��
// �θ� Ŭ������ �������� ������ �ڽ� Ŭ���������� �������� �޼���� �θ� Ŭ������ �޼���� �νĵȴ�.
// ���� �� ������ ���� ���� ���·� 15�� �״�� ������ �ȴ�.

// 41�� ��
// CTest�� ������ ������ �̿��Ͽ� CTestEX ũ�⸸ŭ �����Ҵ� �Ͽ���.
// ���⼭�� '������'�� pData�̹Ƿ�, pData Ŭ������ �޼ҵ带 ����ϰ� �ȴ�.
// ������ �̷� ������ ���� ������
// �ڽ� Ŭ������ CTestEx�� �Ҹ��ڰ� �Ҹ��� �ʱ⶧���̴�.
// �ذ���� 44.virtual_destructor���� �ٷ��.