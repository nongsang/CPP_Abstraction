#include <iostream>
#include <memory>

using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest ������" << endl; }
	~CTest() { cout << "CTest �Ҹ���" << endl; }
};

int main()
{
	cout << "main() ����" << endl;
	{
		auto_ptr<CTest> ptrTest(new CTest);		// auto_ptr����
	}
	cout << "main() ��" << endl;
}

// 16 ~ 18�� ��
// auto_ptr�� ����ϴ� ����̴�.
// CTest�� ũ�⸸ŭ �����Ҵ��ϰ� ptrTest�� ���������� ��ü�� �ּҸ� ��� �ִ�.
// �׸��� ptrTest�� �Ҹ��ϸ鼭 �ڵ����� ����Ű�� ����� �����Ѵ�.
// ����ִ� ���� for���̳� if���� �ƴѵ� {}�� ����Ͽ� ������ ���̴�.
// ������ �Ѿ�鼭 �ڵ����� �Ҹ�ǵ��� �����ϱ������̴�.