#include <iostream>

using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest ������" << endl; }

	virtual ~CTest() { cout << "CTest �Ҹ���" << endl; }
	virtual void TestFunc1() {}
	virtual void TestFunc2() {}
};

class CTestEx : public CTest
{
public:
	CTestEx() { cout << "CTestEx ������" << endl; }

	~CTestEx() { cout << "CTestEx �Ҹ���" << endl; }
	void TestFunc1() {}						// �������̵������� ���������� ����
	void TestFunc2() { cout << "TestFunc2()" << endl; }		// �������̵��ϸ鼭 �ؽ�Ʈ ���
};

int main()
{
	CTest *pData = new CTestEx;		// �����Լ��� �����ϹǷ� ������������ ���
	pData->TestFunc2();
	delete pData;
	pData = nullptr;
}

// ����� -> �ߴ��� ����/����(F9)�� �����ؼ� 8, 18�� �ٿ� �극��ũ ����Ʈ�� �����Ѵ�.

// ������Ʈ -> ������Ʈ�̸� �Ӽ� -> �����Ӽ� -> ��Ŀ -> ���� -> ���� ���� �ּ� -> �ƴϿ� �� �����Ѵ�.
// ������ �ü���� �����ϴ� ���� ���� �ּҸ� ������� �ʰ� �ϱ� �����̴�.
// ���� ���� �ּҴ� ���� �޸� �� �����ϴ� ���� �޸𸮵��� ���� �ּҸ� ������ �� ���� �������� �����ϴ� ����̴�.
// �̸� ����ϹǷν� �޷θ� ��ŷ�� �����ϴ� ��.
// �̸� ��� ���δ� ���̴�.

// F5�� ������� �ϰ� Ctrl + Alt + V, L�� ������ Ȯ���Ѵ�.

// this������ �Ʒ��� __vfptr�̶�� ���� ������ �����ϴµ�, �� ������ vtable �������̴�.
// F5�� ������ �����ϸ� __vfptr�� ���� �ٲ��.
// �׷��Ƿ� ����Ű�� �Լ� ������ �迭�� �޶�����.

// �������
// 1. 27�� �ٿ��� �ν��Ͻ��� �����Ǹ鼭 CTest�� vtable�� CTest�� �����Լ� �迭(���̺�)�� ó�� �����ּҸ� ����Ų��.
// 2. �ڽ�Ŭ������ �����ڰ� ����Ǹ鼭 CTest�� vtable�� CTestEx�� �����Լ� ���̺��� ����Ű�� �ȴ�.
// 3. �׷��Ƿ� CTest�� �����Լ� ���̺��� �ڽ�Ŭ������ ���̺��� ���� ����� �ȴ�.