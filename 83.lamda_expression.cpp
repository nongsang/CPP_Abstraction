#include <iostream>
#include <functional>

using namespace std;

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

	void Sort(function<int(int, int)> cmp)
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

int main()
{
	CTest data;

	data.Sort([](int a, int b)->int {return a - b;});	// sort�� ���� ����
	data.Print();

	data.Sort([](int a, int b)->int {return b - a;});	// sort�� ���� ����
	data.Print();
}

// �Լ� ��ü�� ���ٽ����� ����Ͽ���.
// �񱳿����� ����ߴ� �θ�Ŭ������ �����ϰ�
// �� ������ ��ü������ ���ϴ� �ڽ�Ŭ������ ������ �ʾҴ�.

// 27 ~ 43�� ��
// �θ�Ŭ������ �޾Ƽ� ���������� �̿��Ͽ� �����ϴ� �Լ��� ���������.
// ������ ������ function�� �޾Ƽ� ���ϰ� �����ϴ� �Լ��� �������.
// �׷��Ƿ� �񱳿����� Ŭ������ ������ �ʾƵ� �ȴ�.

// 50, 53�� ��
// CTestŬ������ �ִ� Sort�Լ��� ���ٸ� �����ϰ� �ִ�.
// ���⼭ Sort()�Լ��� �����ϸ鼭 ���޹��� ���ٸ� �������� ���� ���Ͽ� ������ �Ѵ�.

// ��ó�� �Լ����� ���ڷ� �Ѱ��ִ� ����� ���ٽ��̶�� �Ѵ�.
// ���� ���� �Լ����� ���ٽ��� �ޱ� ���ؼ��� functional�� include����� �Ѵ�.
// qsort()�� ���ʸ� �Լ��̹Ƿ� functional�� �ʿ����.
// qsort�� ����� ���Ŀ� ���ٸ� ����غ���.