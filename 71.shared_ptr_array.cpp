#include <iostream>
#include <memory>

using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest ������" << endl; }
	~CTest() { cout << "CTest �Ҹ���" << endl; }
	void TestFunc() { cout << "TestFunc()" << endl; }
};

void RemoveTest(CTest *pTest)		// �迭���������� ����
{
	cout << "RemoveTest()" << endl;
	delete[] pTest;
}

int main()
{
	cout << "main() ����" << endl;

	shared_ptr<CTest> ptr1(new CTest[3], RemoveTest);	// �迭������ �迭�Ҹ��� �����ϰԲ� �Ѵ�.

	shared_ptr<CTest> ptr2(new CTest);		// ���Ӱ� ����
	ptr2.reset();				// ����Ű�� ����� ��� ����

	cout << "main() ��" << endl;
}

// 14 ~ 18�� ��
// ��ü���������� �Լ��� �����Ͽ���.
// �Ķ���Ͱ� Ŭ���� ������������ ��������.
// �׸��� �迭�� �����ص� ������ ��ü�� ������ �Ұ����ϴ�.

// 24�� ��
// shared_ptr������ ��ü�� 3�� �����Ѵ�.
// �׸��� ��ü �Ҹ��� ���� ������ �� RemoveTest()�Լ��� ȣ���ϸ鼭 �Ҹ��ϰ� �ȴ�.

// 27�� ��
// ���� ���Ӱ� ������ ��ü�� ��� ������ �� �ִ�.