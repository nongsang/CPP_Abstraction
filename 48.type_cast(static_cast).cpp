#include <iostream>

using namespace std;

class CTest
{
	int m_nData{ 0 };
public:
	CTest() { cout << "CTest() ������" << endl; }
	virtual ~CTest() { cout << "CTest �Ҹ���" << endl; }
	void SetData(int nParam)
	{
		cout << "setter" << endl;
		m_nData = nParam;
	}
	int GetData() const
	{
		cout << "getter" << endl;
		return m_nData;
	}
};

class CTestEx : public CTest
{
	//int m_nNewData{ 0 };
public:
	CTestEx() { cout << "CTestEx() ������" << endl; }
	~CTestEx() { cout << "CTestEx() �Ҹ���" << endl; }
	void SetData(int nParam)
	{
		if (nParam > 10)
			nParam = 10;
		
		CTest::SetData(nParam);
	}
	void PrintData()
	{
		cout << "PrintData() : " << GetData() << endl;
		//cout << "New Data : " << m_nNewData << endl;
	}
};

int main()
{
	CTest *pData = new CTestEx;		// ������������ ���
	//CTest *pData = new CTest;
	CTestEx *pNewData = nullptr;

	pData->SetData(15);		// CTest��

	pNewData = static_cast<CTestEx*>(pData);		// ����ȯ �� ���� �ִ� �������� �ּҰ� ����
	pNewData->PrintData();			// ���� �˻縦 ���� �ʴ´�.
	delete pData;
	pData = nullptr;
}

// 45�� ��
// �����Լ��� �Ҹ��ڹۿ� �����Ƿ� ������������ ����Ѵ�.

// 49�� ��
// pData�� CTest�� ������ �̹Ƿ� ���� ������ �˻����� �ʴ´�.

// 51�� ��
// CTest�� �������� pData�� CTestEx�� �����ͷ� ����ȯ���ְ� �ִ�.
// pData�� ������ CTestEx*������ ��ȯ�Ͽ� pNewData�� pData�� �� ��ġ�� ����Ű�� �ִ� ��.
// pNewData�� CTestEx*���̹Ƿ� �ּҰ��� �޾ƾ� �Ѵ�.
// pData�� �ּҰ��̹Ƿ� �ڷ����� CTestEx*�� ����ȯ�Ͽ� ���� ����� �����͸� ����Ű�� �ϴ� ���� �Ұ������� �ʴ�.
//
// ���⼭ �߿��� ���� CTestEx�� CTest�� '����'�ϸ鼭 �� ���� ����� �����Ѵ�.
// CTest �� CTestEx �̹Ƿ� ����ȯ�� ������ ���̴�.
//
// �ſ� �߿�~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 46�� �� ó�� CTest��ŭ�� ũ�⸦ ���� �����Ͽ��ٸ�,
// 51�� �ٿ��� ����ȯ�� �Ͽ� ���� ���������ϸ� ����� �ɸ��� ����.
// 47�� �ٿ��� nullptr�� �����ϴ� ���� ����Ű�� �����͸� �����Ѵٴ� ������ ����� ����ϰԲ� �����Ѵٴ� ���� �ƴϱ� ����
// �׷��� 51�� �ٿ����� CTest�� ������ ���� CTestEx�� ����� ����ϰԲ� ����ȯ �Ѵٴ� ������, CTestEx�� �޸𸮿� �����Ѵٴ� ���� �ƴϴ�. 
// �� ���Ŵ� CTestEx�� �����ڰ� �Ҹ��� �ʰ� �Ҹ��ڰ� �Ҹ��� �ʴ´�.
// �� �ܿ��� 25, 39�� �ٿ��� CTestEx���� ��������� �ʱ� ���� �����ְ� ����������� ����ε� ���� ������� ���Ѵ�.

// 52�� ��
// �ܼ��ϰ� CTestEx*���� pNewData�� �̿��� �޼����� ȣ���̴�.

// 50�� ��
// pData�� �����Ҵ��Ͽ����Ƿ� pData�� �޸� ����

// ���⼭ �߿��� ���� 51�� �� static_cast��.
// C++11������ ��������� ����ȯ�� �ϰԲ� �����Ѵ�.
// C��Ÿ�� ����ȯ ����ȯ�� C++������ ������� �ʴ� ���� ����.
// �ֳ��ϸ� ����ȯ�� �ؼ��� �ȵǴ� ���� �Ǵ� �κ��� �ֱ� �����̴�.
//
// ����ȯ�� ��Ģ�� �ִ�.
// 1. ����, �Ǽ�, ���� ���̿� ����ȯ�� ���� (���� ��µǰ� �ȵǰ�� ������ ����)
// 2. �ش� �ڷ������� �ڷ����� ������������ ����ȯ ���� ( ex : int* a = static_cast<int*>(&b); -> b�� int�� )
// 3. �ش� ������ �ڷ������� �ڷ������� ����ȯ �Ұ��� ( ex : int a = static_cast<int>(b); -> b�� int*�� )
// 4. static_cast�δ� ������ �ڷ������� �ٸ� ������ �ڷ������� ����ȯ �Ұ���
//		( ex : char * a = static_cast<char*>(&b); -> b�� int*�� )

// 4�� ��Ģ�� �ٸ��� ���ϸ� C��Ÿ�� ����ȯ�� ������ �ڷ������� �ٸ� ������ �ڷ������� ����ȯ�� �����ϴ�.
// static_cast�� �Ϻ��� ��Ÿ���� �ƴ����� ��� C��Ÿ�� ����ȯ���ٴ� �����ϰ� ����� �� �ִ�.
// ������ �����Ҵ��� �ƴ� ����ȯ�� static_cast�� �������.