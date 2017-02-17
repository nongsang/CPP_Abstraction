#include <iostream>

using namespace std;

class CTest
{
	int m_nData;
public:
	CTest() : m_nData(0) {};
	~CTest() {};

	int GetData() { return m_nData; }

	void SetData(int nParam) { m_nData = nParam; }		// �Լ� �̸��� SetData
	void SetData(double nParam) { m_nData = 0; }		// �̰͵� �Լ� �̸��� SetData
	void SetData(char nParam) = delete;					// ��ŵ� �Լ� �̸��� SetData
};

int main()
{
	CTest a;

	a.SetData(10);					// SetData ����Լ� �θ���
	cout << a.GetData() << endl;

	a.SetData(5.5);					// �̰͵� SetData ����Լ� �θ��µ�?
	cout << a.GetData() << endl;

	a.SetData('a');					// ��ŵ� SetData ����Լ� �θ�
	cout << a.GetData() << endl;
}

// 14 ~ 16��° ��
// �� �޼ҵ� �̸��� SetData�� ����.

// 23��° ��
// �޼ҵ带 �θ���.
// ������ int������ ���ڸ� �����ϰ� �ִ�.
// �׷��� ������ �ڵ����� int�� �Ķ���͸� ���� SetData �޼ҵ带 ã�Ƽ� �����Ѵ�.

// 26��° ��
// �̹����� double������ ���ڸ� �����Ѵ�.
// �׷��Ƿ� double�� �Ķ���͸� ���� SetData �޼ҵ带 �ڵ����� ã�Ƽ� �����Ѵ�.

// 29��° ��
// �̹����� char������ ���ڸ� �����Ѵ�.
// SetData �޼ҵ� �߿��� char�� �Ķ���͸� ���� �޼ҵ带 �ڵ����� ã�Ƽ� �����Ѵ�.
// ������ ����Ѽ��� delete ������ ���ǵǾ� �ִ�.
// ���� �����Ϸ��������� ������ ����Ű�� �ȴ�.

// 15��° �� �޼ҵ尡 ���ǵǾ� ���� �ʴٸ�?
// double������ ���ڸ� �Ѱ��� �� int������ ����ȯ�ؼ� �����ս��� �Ͼ��.
// �����ս��� ���̱� ���ؼ� �����ε��� ����.