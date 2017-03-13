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

int main()
{
	cout << "main() ����" << endl;
	shared_ptr<CTest> ptr1(new CTest);	// shared_ptr ����

	cout << "Count : " << ptr1.use_count() << endl;		// ptr1�̶�� ��ü�� �ϳ� �����Ǿ� �����Ƿ� 1�̴�.
	{
		shared_ptr<CTest> ptr2(ptr1);		// ptr2 = ptr1�� ���� �ǹ�

		cout << "Count : " << ptr1.use_count() << endl;		// ptr2��� ��ü�� �����Ǿ� �����Ƿ� 2�̴�.
		cout << "Count : " << ptr2.use_count() << endl;		// �̰� ���� ��ü�� ���� �ִ°� �ƴѰŰ���.

		ptr2->TestFunc();
	}

	cout << "Count : " << ptr1.use_count() << endl;		// ptr2�� �Ҹ������Ƿ� 1�̴�.
	ptr1->TestFunc();
	cout << "main() ��" << endl;
}

// 17�� ��
// auto_ptr�� �Ȱ��� ����ϸ� �ȴ�.
// auto_ptr�� �ٸ����� ������ ��ü�� 1����� ���̴�.
// ������ ��ü�� 1������ �����͸� �����Ͽ� ���� �����Ͱ� 1���� ��ü�� �����ϴ� �����̴�.
// �׸��� ��ü�� �����ϴ� �������� ������ �����Ѵ�.
// ������ ������ 0�� �Ǹ� ��ü�� �Ҹ��ϰ� �ȴ�.

// 19�� ��
// ptr1�̶�� �����͸� ��ü�� �����ϰ� �����Ƿ� 1�� ��µȴ�.

// 21�� ��
// ptr1�� ����Ű�� ��ü�� ����Ű�� ptr2��� �����͸� �����Ѵٴ� ���̴�.
// �׷��Ƿ� ptr2 = ptr1�� ���� �ǹ��̴�.

// 23, 24�� ��
// �ϳ��� ��ü�� ptr1, ptr2�� ����Ű�� �����Ƿ� ��µǴ� ���� 2�̴�.

// 29�� ��
// ���� ptr2�� ������ �������� �����̴�.
// �׷��Ƿ� ptr2�� �����ǰ� ptr1�� ��ü�� ����Ű�� ���°� �ȴ�.
// ���� 1�� ��µȴ�.