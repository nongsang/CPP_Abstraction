#include <iostream>

using namespace std;

int main()
{
	int nData{ 10 };
	cout << nData << endl;

	auto TestFunc = [nData](void) -> void		// ���� ĸ��
	{
		cout << nData << endl;
	};

	TestFunc();
}

// 10�� ��
// ����ĸ�� ����̴�.
// ()�� �������� ���ٸ� ����Ͽ� ���ְ� �ִ�.
// auto������ ������־��µ� ���� �ڷ����� function<void(void)>���̴�.
// function<void()>�� ���൵ �ȴ�.
// ������ 4������ �ִ�.
// 1. auto TestFunc = [nData](void) -> void	ó�� ��� ����ϴ� ���
// 2. auto TestFunc = [nData](void)	ó�� ��ȯ���� ������ ��ȯ���� ����
// 3. auto TestFunc = [nData]()	ó�� ��ȯ���� ���� �Ķ���͵� ������ �Ѵ� ����
// 4. auto TestFunc = [nData] ó�� 3���� �� ������ �׳� ������ ���ִ� ���

// ĸ�� ������ 4������ �ִ�.
// 1. [nData](void)->voidó�� ����ϴ� ����ĸ��
// 2. [&nData](void)->voidó�� ����ϴ� ����ĸ��
// 3. [=](void)->voidó�� ����ϴ� ����Ʈ ����ĸ��
// 4. [&](void)->voidó�� ����ϴ� ����Ʈ ����ĸ��

// ����ĸ���� ���� �ܺ��� ������ �����Ͽ� �Լ��������� ���� ���� �� ������ ������ �� ����.
// const�� ����� ��ó�� �۵��ϴ� ��.

// ����ĸ���� ���� �ܺ��� ������ �����Ͽ� �Լ��������� ���� ���� �� ������ ���浵 �����ϴ�.
// ���� �ܺο� �ִ� ������ ���� ����ȴ�.