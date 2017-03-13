#include <iostream>

using namespace std;


class CTest
{
	char *m_pszData;
public:
	CTest(int nSize)
	{
		m_pszData = new char[nSize];
	}
	~CTest()
	{
		delete[] m_pszData;
		cout << "���������� ��ü�� �Ҹ���" << endl;
	}
};

int main()
{
	try
	{
		int nSize;
		cout << "Input Size : ";
		cin >> nSize;

		CTest a(nSize);		// try ������ ��ü������ �ϰ� �ִ�.
	}

	catch (bad_alloc &exp)	// �޸� ����ó��
	//catch (exception &exp)
	{
		cout << exp.what() << endl;		// ���� �߻� ����
		cout << "ERROE : CTest()" << endl;
	}
}

// 29�� ��
// �Է¹��� ������ ��ü�� �����ϰ� �ִ�.
// ���� -1���� ������ �޸𸮴� int������ �Է��ص� unsined�� �ν��ϹǷ� 32��Ʈ���� ���� ū���� �ν��Ѵ�.
// ���� ������ ���� ���̴�.

// 32�� ��
// �޸� ����ó���� �ϱ� ���� catch�� �ۼ����̴�.
// bad_alloc Ŭ������ exception Ŭ������ �Ļ� Ŭ�����̸� �޸𸮰��� ����ó���� ����Ѵ�.
// ���� 33�� ��ó�� bad_alloc��ſ� exception�� ����ص� �ȴ�.

// 35�� ��
// what() �޼��带 ����ϸ� ���ܰ� �߻��� ������ �� �� �ִ�.