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

	unique_ptr<CTest> ptr1(new CTest);	// �Ȱ��� ���� �ȴ�.

	//unique_ptr<CTest> ptr2(ptr1);		// �Ұ���
	//ptr2 = ptr1;						// �̰͵� �Ұ���

	cout << "main() ��" << endl;
}

// 18�� ��
// unique_ptr�� ������̴�.
// ���ݱ��� �ؿԴ� ���ó�� �Ȱ��� ����ϸ� �ȴ�.

// 20, 21�� ��
// shared_ptr�� �޸� �� ��ü�� ���� �����͸� ���� �� ���� ���� ���絵 �Ұ����ϴ�.
// �� ���� �� ��ü�� �ϳ��� �����͸� ��밡���ϴٴ� ���̴�.

// �̰� �̿ܿ� weak_ptr�� �ִ�.
// ������ �Ȱ���.
// shared_ptr���� ���Ǵµ� �ܼ��� ���������� ���̰� ��ü�� ������ ���� ����.
// shared_ptr�� ���� ī���Ϳ��� ���⵵ ����.
// �����Ϸ��� shared_ptr�� ��ȯ�ؾ� �ϹǷ� ���� ������� �ʴ´�.