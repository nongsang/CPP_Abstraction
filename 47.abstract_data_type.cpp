#include <iostream>

using namespace std;

#define DEFAULT_FARE 1000

class CPerson
{
protected:
	unsigned m_nFare{ 0 };			// unsigned�� ���� �⺻������ unsigned int��
public:
	CPerson() { cout << "CPerson ������" << endl; }
	virtual ~CPerson() { cout << "CPerson �Ҹ���" << endl; }

	virtual void CalcFare() = 0;	// ����� ����ϴ� ���� �Լ�

	virtual unsigned GetFare() const { return m_nFare; }	// ����� �˷��ִ� �����Լ����� �߿��Ѱ� ���� ����
};

class CBaby : public CPerson
{
public:
	void CalcFare() { m_nFare = 0; }
};

class CChide : public CPerson
{
public:
	void CalcFare() { m_nFare = DEFAULT_FARE * 50 / 100; }
};

class CTeen : public CPerson
{
public:
	void CalcFare() { m_nFare = DEFAULT_FARE * 75 / 100; }
};

class CAdult : public CPerson
{
public:
	void CalcFare() { m_nFare = DEFAULT_FARE; }
};

int main()
{
	CPerson* arList[3]{ nullptr };
	int nAge = 0;

	for (auto &person : arList)
	{
		cout << "���� �Է� : " << endl;
		cin >> nAge;

		if (nAge < 8)
			person = new CBaby;

		else if (nAge < 14)
			person = new CChide;

		else if (nAge < 20)
			person = new CTeen;

		else
			person = new CAdult;

		person->CalcFare();
	}

	for (auto &person : arList)
		cout << person->GetFare() << "��" << endl;

	for (auto &person : arList)
	{
		delete person;
		person = nullptr;
	}
}

// 10�� ��
// unsigned�� ����Ͽ��� unsigned int�� ���� �ǹ��̴�.

// 15, 17�� ��
// virtual�� �����Ͽ� ����� �޴� Ŭ�������� ���� Ư���� �˷��ش�.
// ������ GetFare()�Լ��� virtual�� ���������� �������̵��� ���� �ʾҴ�.
// 70�� �ٿ��� �ٽ� ����

// 20, 26, 32, 38�� ��
// �� �ڽ� Ŭ�������� �θ�Ŭ������ Ư���� ��ӹ޴´�.
// Ŭ�������� CalcFunc()�� �������̵� ������, GetFare()�� �������̵����� �ʾҴ�.

// 49 ~ 67�� ��
// ������� ������ �̿��Ͽ� ������� �Է¿� ���� �����Ͽ� �ڽ�Ŭ������ �θ�Ŭ������ �����Ҵ��ϰ� �ִ�.
// ���⼭�� ���������� '��������'�� '������'�� ���� virtual�� ������ �Լ��� ȣ��ȴ�.
// ������� �Է¿� ���� ������ �����ڸ� ȣ���ϴ� ������ ���̰� �ִ�.
// �ʿ��� ��ü�� ������ �����ϴٴ� �ǹ��̴�.
// �̷��� ����� �����ϹǷ� ����س���.

// 69, 70�� ��
// ������� ������ �̿��� GetFare()�� ȣ���Ͽ� ���� ����Ѵ�.
// 17�� �ٿ��� GetFare()�� virtual�� �����Ͽ���.
// ������ GetFare()�� �������̵��� ���� �ʾ����Ƿ� CPerson�� GetFare()�� ȣ���� �ȴ�.