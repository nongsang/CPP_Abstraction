#include <iostream>
using namespace std;

template<typename T>
class CMyArray
{
private:
	T *m_pData = nullptr;
	int m_nSize = 0;
public:
	explicit CMyArray(int nSize) : m_nSize(nSize)
	{
		m_pData = new T[nSize];		// ���ø��� �ڷ����� �����ָ� �� ũ�⸸ŭ �迭�� ����
	}

	~CMyArray() { delete[] m_pData; }

	CMyArray(const CMyArray &rhs)			// ���� ����
	{
		m_pData = new T[rhs.m_nSize];			// ���� �����ϰ�
		memcpy(m_pData, rhs.m_pData, sizeof(T)* rhs.m_nSize);	// ������ ����
		m_nSize = rhs.m_nSize;		// ũ�⵵ ������
	}

	CMyArray& operator=(const CMyArray &rhs)	// ���� ������
	{
		if (this == &rhs)		// �ڱ� �ڽ��� �����ϸ� �ƹ��͵� ����
			return *this;

		if(nullptr != m_pData)
			delete[] m_pData;			// ������ �����ʹ� ����
		m_pData = new T[rhs.m_nSize];	// ���Ӱ� �����Ҵ�
		memcpy(m_pData, rhs.m_pData, sizeof(T)* rhs.m_nSize);		// ������ ����
		m_nSize = rhs.m_nSize;		// ũ�⵵ ����

		return *this;
	}

	CMyArray(CMyArray &&rhs)	// �̵� ������
	{
		operator = (rhs);	// �̵� �����ڸ� �� ���� ������ �� �ִ�.
	}

	CMyArray& operator=(const CMyArray &&rhs)		// �̵� ���� ������
	{
		m_pData = rhs.m_pData;		// �̵� �����̴� ���� ����� ���ش�.
		m_nSize = rhs.m_nSize;		// �̰��� ������ ���� ����
		rhs.m_pData = nullptr;		// ������ ���� �Ⱦ��� nullptr��
		rhs.m_nSize = 0;			// ������� 0
	}

	T& operator[](int nIndex)		// �迭 ������, ���� ������ �� �Ҹ���.
	{
		if (nIndex < 0 || nIndex >= m_nSize)
		{
			cout << "ERROR: �迭�� ��踦 ��� �����Դϴ�." << endl;
			exit(1);
		}

		return m_pData[nIndex];
	}

	T& operator[](int nIndex) const			// ���ȭ�� �迭 ������, ���� ����� �� �Ҹ���.
	{
		return operator[](nIndex);
	}

	int GetSize() { return m_nSize; }	// �迭 ����� ������ ��ȯ
};

int main()
{
	CMyArray<int> arr(5);		// ũ�Ⱑ 5

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;

	for (int i = 0; i < 5; ++i)
		cout << arr[i] << ' ';

	cout << endl;

	CMyArray<int> arr2(3);		// ũ�Ⱑ 3
	arr2 = arr;				// ���⼭ �߿�
	for (int i = 0; i < 5; ++i)
		cout << arr2[i] << ' ';

	cout << endl;

	return 0;
}

// �迭 ���·� �����͸� �����ϴ� ���ø� Ŭ���� �迭�̴�.

// �⺻������ �����ε��� �ѹ��� �غô� �͵��̴�.
// ���ø����� Ŭ������ �����ϰ� �迭���·� ��������� ��

// 87�� ��
// ���Ⱑ ���� �߿��� �κ��̴�.
// arr�� ũ�Ⱑ 5, arr2�� ũ�Ⱑ 3�̴�.
// �׷��� ũ�Ⱑ 3�� arr2�� ũ�Ⱑ 5�� arr�� ���� �����Ѵ�?
// ���� �ȵ����� ���⼭�� �����ϴ�.

// 25 ~ 37�� ��
// ���Կ����ڿ��� ������ �ִ� �����͸� �����Ѵ�.
// �׸��� �����ϴ� �迭�� ũ�⸸ŭ ���ӵ� �����Ҵ��Ѵ�.
// ���⼭ ũ�Ⱑ �ٸ� �迭���� ������ ������ ���̴�.