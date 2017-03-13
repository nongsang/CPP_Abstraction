#include <iostream>
#include <functional>	// �̰�?

using namespace std;

int TestFunc(char* pszParam, function<int(char*,int)> param)	// ��?
{
	cout << pszParam << endl;
	return param("Hello", 10);		// �Ű������� ���� �ѱ��?
}

int main()
{
	cout << "main() ����" << endl;
	TestFunc("TestFunc()",
		[](char *pszParam, int nParam)->int
	{
		cout << pszParam << " : " << nParam << endl;
		return 0;
	}
	);

	cout << "main() ��" << endl;
}

// 2�� ��
// std::function�� ����ϱ� ���� ���̺귯��

// 6�� ��
// std::function<int (char*, int)> param ������ �Ű�������.
// ��Ȳ�������� ��¥��.
// std::function�� � �Լ��� �Ű������� ���� �� �ִ� Ŭ���� ���ø��̴�.
// <int (char*, int)> ���� ù��° int�� �Լ��� ��ȯ���� ��Ÿ����.
// ()���� �Ű����� ����̴�.

// 9�� ��
// �Ű������� ���� ��ȯ���ְ� �ִ�.

// 15 ~ 21�� ��
// TestFunc()���� �Ű������� ���ٷ� �������ְ� �ִ�.
// �ű�� ���� ����ִ°� �ƴϰ� �׳� ��¸� ���ְ� �ִ�.
// 9�� �ٿ��� �Լ��� ���� �Ű������� ���� ��ȯ���ִ� ������ ���� ����ִ´�.