#include <iostream>

using namespace std;

template<class T>
class CTest
{
protected:
	T m_Data;
};

template<class T>
class CTestEx : public CTest<T>		// ���ø� Ŭ���� ����
{
public:
	T GetData() const { return m_Data; }
	void SetData(T param) { m_Data = param; }
};

int main()
{
	CTestEx<int> a;
	a.SetData(5);
	cout << a.GetData() << endl;
}

// 5 ~ 10�� ��
// �Ϲ� ���ø� Ŭ������ ���������.

// 12 ~ 18�� ��
// ���ø� Ŭ������ ����� �޾Ƽ� �����Ͽ���.
// 13�� �ٿ��� Ŭ�����̸��� ���ø��� �������ִ� ������ ���� ����� �� �ִ�.

// 22�� ��
// ���ø� Ŭ������ ����ϱ� ���ؼ� �ڷ����� �׻� ����ؾ� �Ѵ�.