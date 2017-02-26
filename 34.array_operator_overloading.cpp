#include <iostream>

using namespace std;

class CArray
{
	int *m_npData;		// �迭 �޸�
	int m_nSize;		// �迭 ��� ����
public:
	CArray(int nSize)
	{
		cout << "�迭 ������" << endl;
		m_npData = new int[nSize];			// nSize ������ŭ �迭 ���·� �����Ҵ�
		memset(m_npData, 0, sizeof(int) * nSize);	// �����Ҵ��� �޸𸮸� 0���� intũ���� nSize ������ŭ �� �Ҵ�
	}

	~CArray()
	{
		cout << "�Ҹ���" << endl;
		if(nullptr != m_npData)
			delete[] m_npData;
	}

	int operator[](int nIndex) const		// ����Ҷ� �Ҹ�
	{
		cout << "���� �迭 ������" << endl;
		return m_npData[nIndex];
	}

	int& operator[](int nIndex)			// ���� ������ �� �Ҹ�
	{
		cout << "�Ϲ� �迭 ������" << endl;
		return m_npData[nIndex];
	}
};

void TestFunc(const CArray& arParam)
{
	cout << "TestFunc() ����" << endl;

	cout << arParam[3] << endl;

	cout << "TestFunc() ��" << endl;
}

int main()
{
	cout << "main() ����" << endl;

	CArray arr(5);
	const CArray& a = arr;

	for (int i = 0; i < 5; ++i)
		arr[i] = i * 10;

	cout << a[3] << endl;

	TestFunc(arr);

	cout << "main() ��" << endl;
}

// 7�� ��
// �迭�������� ���� �����Ҵ��� ���� ������ ����

// 8�� ��
// �迭�� ��� ������ ��� ����

// 13�� ��
// nSize��ŭ �迭���·� �����Ҵ�

// 14�� ��
// �����Ҵ�� �޸𸮸� intũ���� �޸� ������ŭ�� 0���� �����Ѵ�.

// 24 ~ 28�� ��
// ���� �迭 �����ڸ� �������־���.
// ���⼭ �߿��Ѱ� const�̴�.
// const�� ����Ͽ� ȣ���ϸ� �� �迭 ������ ȣ��ȴ�.
// �Ѹ���� r-value, �� ��������� �Ҹ��� ȣ��ȴٴ� ��.
// �̸� �� �����ִ°� 37, 41, 51, 58�� ���̴�.

// 30 ~ 34�� ��
// �Ϲ������� �迭 ������ �Ҹ���� ȣ��ȴ�.
// �̸� �����ִ°� 54�� ��

// 50�� ��
// �迭���·� �����ڰ� �Ҹ��� �ȴ�.

// 51�� ��
// const�� ������·� ���� ������ ������ �������.
// ���߿� ���̹Ƿ� ����صε���

// 54�� ��
// 50�� �ٿ��� ������ �Ϲ� �迭 ������ arr�� �ҷ����Ƿ� �Ϲ� �迭 �����ڰ� �Ҹ��� �ȴ�.
// �Դٰ� ���� ������ �� �����Ƿ� �� Ȯ���ϴ�.

// 56�� ��
// 51�� �ٿ��� const�� �Ҹ� a�� �ҷȴ�.
// �׷��Ƿ� ���� �迭 �����ڰ� �Ҹ��� �ȴ�.
// �������� ���̹Ƿ� �迭�� ���� �����´�.

// 58�� ��
// 37 ~ 44�� �ٿ��� ������ �Լ��� ȣ���Ѵ�.
// �Լ��� �Ķ���ʹ� const�� ���� �����̴�.
// ���⼭�� 56�� �ٰ� ���� ������·� ȣ���� �Ǿ����Ƿ� ���� �迭 �����ڰ� ȣ��ȴ�.