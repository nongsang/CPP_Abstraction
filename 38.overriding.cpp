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
			CTest::SetData(0);		// �θ� Ŭ������ ��������� ȣ��

		else if (nParam > 10)
			CTest::SetData(10);		// �̰͵� ��������
	}
};

int main()
{
	CTest a;

	a.SetData(-10);
	cout << a.GetData() << endl;

	CTestEx b;

	b.SetData(15);
	cout << b.GetData() << endl;
}

// 24�� ��
// �������̵��� ����
// �θ� Ŭ�������� ���� �̸��� ����� �ϴ� ����Լ��� �����Ѵ�.
// ������ �ڽ� Ŭ������ ���� �̸��� ���� ����Լ��� ���Ӱ� �������־���.
// �ڽ� Ŭ������ �̿��Ͽ� �Լ��� ȣ���ϸ� ���Ӱ� ���ǵ� ����Լ��� �Ҹ��� �ȴ�.

// 27, 30�� ��
// �θ� Ŭ������ ��������� �ڽ� Ŭ���� ����������� ȣ���Ͽ� �������̵�(override) �ߴ�.
// ������ �ִ� �θ� Ŭ������ ����Լ��� �̿��Ͽ� ���������� �� �ִ�.
// �̿ܿ��� ���� ������� ������� ������ ���� �� �ִ�.

// 36�� ��
// �θ� Ŭ������ CTest�� �����ߴ�.

// 38�� ��
// a�� SetData()�� ����Ͽ� ���� �������ְ� �ִ�.
// -10�� �Է��Ͽ����Ƿ� -10�� �Էµȴ�.

// 41�� ��
// �ڽ� Ŭ������ CTestEx�� �����ߴ�.

// 43�� ��
// b�� SetData()�� ����Ͽ� ���� �������ְ� �ִ�.
// a������ SetData()�� �־����� �ڽ� Ŭ������ ���Ӱ� ���ǵ� SetData()�� �����Ƿ� �ڽ� Ŭ������ SetData()�� ȣ���Ѵ�.
// b�� SetData()�� ���� ������ �˻��ϴ� ���ο� ����� �������־����Ƿ� ������ �ͺ��� �� ���� ����� ����� �� �ִ�.

// 44�� ��
// �ڽ� Ŭ������ b�� ���ؼ� �θ� Ŭ������ GetData()�� ȣ���Ͽ���.
// b���� GetData()�� ���ǵǾ� ���� �ʱ⶧���� �θ� Ŭ������ GetData()�� ȣ���Ѵ�.