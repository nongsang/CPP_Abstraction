#include <iostream>

using namespace std;

class CTest
{
private:				// ���� Ŭ���� �������� ���� ����
	int m_nData{ 0 };
protected:				// ��ӹ��� �ڽ� Ŭ������ ���� ����
	void PrintData()
	{
		cout << "���" << endl;
		cout << CTest::GetData() << endl;
	}
public:					// ��� ���� ����
	CTest() { cout << "CTest ������" << endl; }
	~CTest() { cout << "CTest �Ҹ���" << endl; }
	int GetData() const
	{
		cout << "getter" << endl;
		return m_nData;
	}
	void SetData(const int& nParam)
	{
		cout << "setter" << endl;
		this->m_nData = nParam;
	}
};

class CTestEx : public CTest		// ��� ���
{
public:
	CTestEx() { cout << "CTestEx ������" << endl; }
	~CTestEx() { cout << "CTestEx �Ҹ���" << endl; }
	void TestFunc()
	{
		PrintData();
		SetData(5);
		cout << CTest::GetData() << endl;
	}
};

int main()
{
	CTestEx data;

	data.SetData(10);
	cout << data.GetData() << endl;

	//CTestEx::GetData();

	data.TestFunc();
}

// 9�� ��
// protected��� Ű����� ��ӿ����� �ǹ̰� �ִ�.
// 30�� �ٰ� ���� �ִ�.

// 30�� ��
// public�� ����Ͽ� ����� �Ͽ���.
// ����� �θ�� �ڽİ���� ��Ÿ�� �� �ִµ�, ���α׷��ֿ����� ������ �ڵ带 '����'�Ѵٴ� �ǹ̿� ����.
// ��� ������ private, protected, public 3������ ����� �� �ִ�.

// 37 ~ 39�� ��
// �ſ� �߿��� ���� ~~~~~~~~
// �ڽ� Ŭ������ �θ� Ŭ�����κ��� public���� ��ӹ޾Ҵ�.
// �� ���� �θ� Ŭ������ public, protected ������ ���� �������, ����Լ��� �ڽ� Ŭ�������� ���� �����ϴٴ� �ǹ��̴�.
// protected�� ����ߴٸ� protected��, private�� ����ϸ� �ƹ��͵� ����� �� ����.
// �ڽ� Ŭ�������� ��ŭ�� ���ٱ����� �ο��ϴ����� ���� �����̴�.

// 45�� ��
// CTest�� public���� ��ӹ��� CTestEx�� �����Ͽ���.
// ���⼭ �Ѱ��� �̽��� �ִ�.
// �ڽ� Ŭ������ �����Ͽ����� �θ� Ŭ������ �����ڰ� ���� �ҷȴ�.
// ������ �ִ� �����ڰ� ���� �ҷ��� ���߿� ���ٿ��� Ŭ������ �ǹ̰� �ֱ� �����̴�.

// 47, 48�� ��
// CTestEx�� ������ data�� ���� SetData()�Լ��� ����Ͽ� ���� �����ϴ� ���̴�.
// �̰��� '����'�� �ǹ��̴�.
// �ڽ� Ŭ������ ���ؼ� �θ� Ŭ������ ��������� ����Ѵ�.

// 50�� ��
// �̷� ������ ���� ����� Ŭ���� �������� ����� �����ϴ�.
// main()���� �����ϱ� ���ؼ��� �����ڰ� ȣ���� �Ǿ��(�޸𸮿� �����Ǿ��)�Ѵ�.
// Ŭ������ ���� a�� �����ߴٰ� �����ϸ�, a.GetData(); �������θ� ������ �����ϴ�.