#include <iostream>

using namespace std;

class CCompareBase
{
public:
	virtual int operator()(int a, int b) const = 0;
};

class CTest
{
	int m_narray[5];
public:
	CTest()
	{
		m_narray[0] = 30;
		m_narray[1] = 10;
		m_narray[2] = 50;
		m_narray[3] = 20;
		m_narray[4] = 40;
	}

	void Print()
	{
		for (auto &n : m_narray)
			cout << n << '\t';

		cout << endl;
	}

	void Sort(const CCompareBase &cmp)
	{
		int nTemp;

		for (int i = 0; i < 4; ++i)
		{
			for (int j = i + 1; j < 5; ++j)
			{
				if (cmp(m_narray[i], m_narray[j]) < 0)
				{
					nTemp = m_narray[i];
					m_narray[i] = m_narray[j];
					m_narray[j] = nTemp;
				}
			}
		}
	}
};

class CCmpDesc : public CCompareBase
{
public:
	int operator()(int a, int b) const { return a - b; }
};

class CCmpAsce : public CCompareBase
{
public:
	int operator()(int a, int b) const { return b - a; }
};

int main()
{
	CTest data;

	CCmpDesc desc;
	data.Sort(desc);	// ���� ���
	data.Print();

	CCmpAsce asce;
	data.Sort(asce);	// ���� ���
	data.Print();
}

// 32 ~ 48�� ��
// ���Ĺ�� ����
// ���⼭ 40�� ���� �߿��ϴ�.
// CCompareBase���� ���ǵ� ������ ������ �ΰ��� ������ �Ѱ��ִ� ����̴�.

// 51 ~ 61�� ��
// CCompareBase�� ��ӹ޴� �ڽ�Ŭ�������� ������ �޾Ƽ� ������ ���Ƿ� ���� ���Ѵ�.
// �θ�Ŭ������ ��������Ŭ�����̹Ƿ� ��� CCompareBase�� ����ؼ� ���� ���ϴ� 40�� ����
// �ڽ�Ŭ������ ���ǿ� ���� ���� ���Ѵ�.

// 68, 72�� ��
// ����� ���͸� ����ؼ� ������ �Լ��� ȣ���Ѵ�.