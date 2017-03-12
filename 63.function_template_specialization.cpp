#include <iostream>
#include <memory>
using namespace std;

template<typename T>
T Add(T a, T b) { return a + b; }

template<>			// ���ø� Ư��ȭ
char* Add(char* pszLeft, char* pszRight)		// ���ø� Ư��ȭ�� ����ϱ� ���� ����
{
	int nLenLeft = strlen(pszLeft);
	int nLenRight = strlen(pszRight);
	char* pszResult = new char[nLenLeft + nLenRight + 1];

	strcpy_s(pszResult, nLenLeft + 1, pszLeft);		// �̰� �߿���
	strcpy_s(pszResult + nLenLeft, nLenRight + 1, pszRight);	// �̰͵�

	return pszResult;
}

int main()
{
	int nResult = Add<int>(3, 4);
	cout << nResult << endl;

	char* pszResult = Add<char*>("Hello", "World");
	cout << pszResult << endl;
	delete[] pszResult;
}

// 8�� ��
// ���ø��� ����ϵ� �ƹ��͵� ������ ���ߴ�.
// template<typename T>�̶�� ����ص� �������.
// �׳� ���ø� Ư��ȭ�� �����ϱ����ؼ� template<>��� ����ϴ����� ����.

// 9 ~ 19�� ��
// ���ø� Ư��ȭ�� ����� �Լ� ����
// ���⼭ �Լ��� ���� �κ��� ��������.
// ����Ǿ�� �ϴ� ���� 8�� ��ó�� ���ø� ������ �Ǿ�� �Ѵ�.
// �� �Ŀ� �Լ��� �̸��� ���ø� �Լ��� ������ ��ȯ��, �Ķ������ �ڷ����� ��� char*������ ������ �Ǿ�� ���ø� Ư��ȭ�� ����� �� �ִ�.
// �׷��� �ʴٸ� ���ø� Ư��ȭ�� �ν����� �ʴ´�.
// �ܼ��� �̸��� ���� �Լ��� �ν��ϹǷ� ������ �վ��.
//
// ������� ���ڿ����� ���ϴ� ����̴�.
// 1. �� �Ķ���ͷ� ���� ���ڿ��� ũ�⸦ ���Ѵ�.
// 2. �Ķ���ͷ� ���� ���ڿ��� ũ���� �� + 1��ŭ ���� �����Ҵ��Ѵ�.
// 3. �����Ҵ��� ���� ù��° ���ڿ� ũ�� + 1��ŭ �ִ´�. -> ������ \0�� ���Ƿ� �� ù ���ڿ���ŭ�� ����.
// 4. �����Ҵ��� ������ �����Ͽ� ù��° ���ڿ��� �� ��ġ�� �̵��Ѵ�.
// 5. �ι�° ���ڿ� ũ�� + 1��ŭ �ִ´�.
// 6. ���������� \0�� ���ԵǾ� ����