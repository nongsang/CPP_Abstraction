#include <iostream>

using namespace std;

class CNode
{
private:
	char m_szName[32];
	CNode *pNext = nullptr;
private:
	friend class CList;
public:
	explicit CNode(const char *pszName)
	{
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}
};

class CList
{
	CNode m_HeadNode;
public:
	CList() : m_HeadNode("Dummy Head") {}
	~CList()
	{
		CNode *pNode = m_HeadNode.pNext;
		CNode *pDelete = nullptr;

		while (pNode)
		{
			pDelete = pNode;
			pNode = pNode->pNext;
			delete pDelete;
		}
		m_HeadNode.pNext = nullptr;
	}

	void AddNewNode(const char *pszName)
	{
		CNode *pNode = new CNode(pszName);

		pNode->pNext = m_HeadNode.pNext;
		m_HeadNode.pNext = pNode;
	}

	void Print()
	{
		CNode *pNode = m_HeadNode.pNext;
		while (pNode)
		{
			cout << pNode->m_szName << endl;	// ����� �����͸� ����ϰ�
			pNode = pNode->pNext;				// ���� ���� �̵�
		}
	}
};

class CUI
{
	CList m_list;			// ���⼭ composition ���踦 ��Ÿ����. 110�� �ٿ��� ����
public:
	int PrintMenu()
	{
		cout << "[1]Add\t" << "[2]Print\t" << "[3]clear\t" << "[0]Exit" << endl;
		cout.flush();
		int nInput = 0;
		cin >> nInput;

		return nInput;
	}

	void Run()
	{
		char szName[32];
		int nInput = 0;

		while ((nInput = PrintMenu()) > 0)
		{
			switch (nInput)
			{
			case 1:
				cout << "�̸� : ";
				cout.flush();
				cin >> szName;
				m_list.AddNewNode(szName);
				break;
			case 2:
				m_list.Print();
				break;
			case 3:
				system("cls");
				break;
			default:
				break;
			}
		}
	}
};

int main()
{
	CUI ui;
	ui.Run();
}

// 99 ~ 103�� ��
// main()�Լ� �ȿ� ���ǵ� Ŭ������ ����Ͽ���.
// �ʹ� �����ϴ�.
// �̰� ��ü���� ���α׷����� �����̴�.

// 59�� ��
// CUI�� ����� CList Ŭ������ �ν��Ͻ��� ����Ǿ���.
// �� Ŭ���� �ȿ��� �ٸ� Ŭ������ ����ϴ� ��.
// �װ͵� �������̳� ������������ ������� �ʾҴ�.
// �׳� Ŭ������ ����ϰڴٰ� �����ν� CUI�� �Ҹ��ϸ鼭 CList�� ���� �Ҹ��ϰ� �ȴ�.
// �̰� composition ������ Ư���̴�.

// 71 ~ 96�� ��
// ����Լ��� Run()�� �����̴�.
// �������� �̺�Ʈ�� �ݺ��� ���¸� ���ϰ� �ִ�.
// 76�� �ٿ��� ����ڰ� �Է��� Ű���� ���� Ȯ���ϰ� �� ���� �����ΰ��� ���� ������ ����� �۵��Ѵ�.
// 21�� ���� ���� ����Ǿ� �ִ°Ŷ� �� �ָ��ϴ�.