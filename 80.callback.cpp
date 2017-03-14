#include <iostream>

using namespace std;

int CompareData(const void *pLeft, const void *pRight)
{
	return *(int*)pLeft - *(int*)pRight;
}

int main()
{	
	int aList[5]{ 30, 50, 10, 20, 40 };

	qsort(aList, 5, sizeof(int), CompareData);		// ���⼭ callback �߻�
	for (auto &n : aList)
		cout << n << " ";

	cout << endl;
}

// 5 ~ 8�� ��
// �� ���� ���� �� ���� ��ȯ�ϴ� �Լ��� �����ߴ�.

// 14�� ��
// qsort�� ����Ͽ� �迭�� �����Ѵ�.
// ���ڴ� �迭�̸�, ����, ����� ũ��, �� ������ �Ǵ� �Լ��� �ȴ�.
// ���⼭ �Լ��� �̸��� ���� �߿��ϴ�.
// qsort() �Լ� ���ο��� �� ��Ҹ� ���� ������ �� �ּҸ� ȣ���Ѵ�.
// �̺�Ʈ�� ���涧 ���� ȣ���ϴ� ���� callback(��ȣ��)�̶�� �Ѵ�.
// �Լ������� �� ���� ���� 0�̸� ���� ��, ����� �������� ũ��, ������ ������ �� ū ���̴�.
//
// ���� �� �Լ��� ���ٷ� ǥ���Ѵٸ� ���?

// ���� �̷��� �Լ��� ���� �ؾ��ϳ�?
// ������ ����� ���ڿ��̶�� ���ϱ� �����.
// �׷��Ƿ� �����Ϸ��� ��� ���� �� ����� ����ڰ� ��������� �Ѵ�.