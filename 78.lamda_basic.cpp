#include <iostream>

using namespace std;

int TestFunc(int nParam)
{
	cout << "Function Pointer: " << nParam << endl;
	return nParam;
}

int main()
{
	auto Func = [](int nParam) -> int
	{
		cout << "Lamda : " << nParam << endl;
		return nParam;
	};
	Func(5);

	auto pfTest = TestFunc;
	pfTest(10);
}

// 13 ~ 18�� ��
// ���ٸ� ����ϴ� ����̴�.
// �Ķ���͸� int������ �޾Ƽ� ��ȯ������ int���� �Լ� �������� �� �� �ִ�.
// ���� ���ٴ� �̸��� �����Ƿ� �̸��� ����� ������ ���ǵǾ� �־�߸� �Ѵ�.
// �̴� auto������ ���ǵ� Func������ ����Ѵ�.
// �׸��� 18�� �ٿ��� ���� �����ϴ� �����̴�.

// 5 ~ 9��, 20, 21�� ��
// ���ٿ� ����� C��� ����� �����Ѵ�.
// TestFunc()���� �Լ��� �������ְ� �̸��� ����� pfTest������ ������ �Ѵ�.
// 21�� �ٿ��� TestFunc()�� ����ϴ� pfTest�� ���� �����ϴ� ����̴�.

// ���� �̷������� �� �������� �ʴ´�.
// �׳� ���� ����� ������ ���� ���̴�.