#include <iostream>

using namespace std;

class CTest
{
	int m_nData;
public:
	explicit CTest(int nParam) : m_nData(nParam)
	{
		cout << "������" << endl;
	}

	operator int(void) { return m_nData; }		// ����ȯ ������
	//explicit operator int(void) { return m_nData; }	// ����� ����ȯ

	~CTest() { cout << "�Ҹ���" << endl; }

	int GetData() const { return m_nData; }
};

int main()
{
	cout << "main() ����" << endl;

	CTest a(10);		// ��ȯ������ ȣ��

	cout << a.GetData() << endl;	// �Ϲ��� ������� ���� ���
	cout << a << endl;				// ������ �ڷ��� ��ȯ
	cout << (int)a << endl;			// C ��Ÿ�� ����ȯ
	cout << static_cast<int>(a) << endl;	// C++ ��Ÿ�� ����ȯ
	
	cout << "main() ����" << endl;
}

// 14��° ��
// ����ȯ �����ڸ� �����ε��Ͽ���.
// ��ü�� ���� ����ȯ�� ����ȯ �����ڰ� �־�� �Ѵ�.

// 28��° ��
// �Ϲ������� ��������� �����ϴ� ����̴�.

// 29��° ��
// ���������� �ڷ��� ��ȯ�� �Ͽ� ����ϴ� ����̴�.
// ����ȯ �����ڰ� �����ؾ߸� ����ȯ�� �����ϴ�.
// �̴� ������ ��ȯ�̱� ������ 15��° �� ó�� ��������� ����ȯ ������ �����ε��� �ϸ� ����� �� ����.

// 30��° ��
// C ��Ÿ���� ����� ����ȯ�̴�.
// �� ����ȯ�� ����ȯ �����ε��� �ʼ���.

// 32��° ��
// C++ ��Ÿ���� ����ȯ�̴�.
// �� ��Ÿ���� �츮�� �����ؾ� �Ѵ�.
// �� ����ȯ�� ����ȯ �����ε��� �ʼ�.