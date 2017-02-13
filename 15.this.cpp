#include <iostream>

using namespace std;

class CMyData
{
	int m_nData;
public:
	CMyData(int n) : m_nData(n) {}
	void Print()					// void Print(CMyData *pData)
	{								// CMyData *this = pData;
		// m_nData�� ����
		cout << "m_nData : " << m_nData << endl;

		// CMyData�� ������� m_nData�� ����
		cout << "CMyData::m_nData : " << CMyData::m_nData << endl;

		// �޼��带 ȣ���� �ν��Ͻ��� m_nData�� ����
		cout << "this->m_nData : " << this->m_nData << endl;		// ������ ������ �Ǵ� �ڵ�

		// �޼��带 ȣ���� �ν��Ͻ��� CMyData�� ������� m_nData�� ����
		cout << "this->CMyData::m_nData : " << this->CMyData::m_nData << endl;
	}
};
int main()
{
	CMyData a(5), b(10);	// ����ó�� �ѹ��� a, b�� ���� ����

	cout << "a" << endl;
	a.Print();				// a.Print(&a);

	cout << endl;
	cout << "b" << endl;
	b.Print();				// b.Print(&b);
}

// 10, 11��° ��
// �������� �ɶ��� ������ �ּ�ó�� �ڵ����� �������� �ȴ�.
// �ٸ� ��� �ڵ����� �Ǳ� ������ �����ϴ� ��.
// ������ �̷��� ���� ���꼺�� �������Ƿ� ���� �ʴ°� ������ �� �˸´�.

// 13��° ��
// �Ϲ������� ��������� �����ϴ� ����̴�.
// ������ �̷��Ը� ���� �ڵ����� �����Ϸ��� 19��° ��ó�� �������Ͽ� �����Ѵ�.
// this �����͸� �Ƚᵵ ���ذ� �Ǵ� �ڵ��� this�� ���� �ʾƵ� ������, ��Ȯ�� �ؾ��� ��쿡�� 19��° ��ó�� �ڵ�����.

// 16��° ��
// ���� ���� ������(::)�� �̿��Ͽ� �Ҽ��� ��Ȯ�� �Ͽ� ��������� �����Ѵ�.

// 19��° ��
// this �����͸� �̿��Ͽ� �޼��带 ȣ���� �ν��Ͻ��� ��������� �����Ѵ�.
// �޼���� ����Լ��� ���� ���̴�.
// this�� Ŭ������ �ν��Ͻ��� ���Ѵٰ� ���� �ȴ�.
// �ٽø��� this�� �޼��尡 �����ִ� � Ŭ���� ��ü�� ���Ѵ�.

// 22��° ��
// this �����Ϳ� ���� ���� ������(::)�� �̿��ؼ� ��������� �Ҽ��� ��Ȯ�ϰ� �ϰ� �ִ�.

// 27��° ��
// Ŭ���� ������ �ʱ�ȭ�ϴ� �����̴�.
// ()�� �̿��Ͽ� �ʱ�ȭ�� �����ϸ�, �Ϲ� ����ó�� �� �ٿ� ���� ������ �����ϴ� ���� �����ϴ�.

// 30, 34��° ��
// 10, 11��° ���� �ּ�ó�� �ڵ����� �������� �ǹǷ� �ν��Ͻ��� �ּҸ� �Ѱ��ִ� �۾��� �ڵ����� �Ѵ�.
// ���� �̰͵� �����ϴ°� ����.


// ���ݱ��� �ڵ����� ������ �Ǵ� ���� �� ������� ���� ����Ǵ°� �ƴѰ� ����.
// �׳� �̷��� �����Ϸ��� �ؼ��Ѵٴ� �͸� �˾Ƶ���.
// ������ �Ƚᵵ ��뿡�� ������ ���...