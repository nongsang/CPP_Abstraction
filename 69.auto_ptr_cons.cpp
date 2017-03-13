#include <iostream>
#include <memory>

using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest ������" << endl; }
	~CTest() { cout << "CTest �Ҹ���" << endl; }
	void TestFunc() { cout << "CTest::TestFunc()" << endl; }
};

int main()
{
	auto_ptr<CTest> ptr(new CTest[3]);		// auto_ptr�� �迭����� �����ص� �迭���·� �Ҹ��� �ȵȴ�.

	auto_ptr<CTest> ptrTest(new CTest);
	auto_ptr<CTest>	ptrNew;

	cout << "0x" << ptrTest.get() << endl;		// auto_ptr�� �ּҰ� ��� ���

	ptrNew = ptrTest;						// ���� ����
	cout << "0x" << ptrTest.get() << endl;

	ptrTest->TestFunc();		// �̰� ���Ұ�
}

// 16�� ��
// auto_ptr�� ����ؼ� �迭���·� �����Ͽ���.
// ������ �迭���·� ���������� �迭���·� �Ҹ��� ���� �ʾƼ� ������ �߻��Ѵ�.

// 23�� ��
// ���� ���縦 ���ְ� �ִ�.
// ������ ���� ���縦 ���ָ鼭 ptrTest�� �ν��Ͻ��� ptrNew�� �������ְ� ptrTest�� NULL�� �ʱ�ȭ�ع����ٴ� ���̴�.

// 26�� ��
// ptrTest�� NULL�� �Ǹ鼭 ��������� ����� �� �������� �ȴ�.

// �����ϸ� auto_ptr�� ������
// 1. �迭���� �Ұ�
// 2. ���� ����� �ڽ� ���� �Ұ�