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
			cout << pNode->m_szName << endl;
			pNode = pNode->pNext;
		}
	}
};

class CUI
{
	CList &m_list;			// ���⼭ aggregation ���踦 ��Ÿ����.
public:
	CUI(CList &rList) : m_list(rList) {}		// composition�� �޸� �����ڰ� �ִ�.
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
	//CUI ui;		// CUI�� �����ڰ� CList�� �Ķ���͸� �����Ƿ� �׳� ������ �Ұ����ϴ�.
	CList list;		// �ڷᱸ���� ���� �����ϰ�
	CUI ui(list);	// UI��ü�� ������ �����ϰ� �����Ѵ�.
	ui.Run();		// �׷��� ��밡��
}

// 102�� ��
// CUI�� �����ڰ� �����.
// ����Ʈ �����ڰ� �ƴ� ��ȯ�����ڰ� �����ϹǷ� �׳� ������ ���Ѵ�.

// 103, 104�� ��
// �ڷᱸ���� ���� �����ϰ� UI��ü�� ������ �����Ͽ� �����Ѵ�.
// CList�� CUI�� ���� ������ �����ϰ� ���� �����Ѵٴ� ���� �� �� �ϳ��� �������� �� �� �ϳ��� ������ �ȴٴ� ���̴�.
// �̰��� aggregation�� Ư¡�̴�.

// 59, 61�� ��
// CList�� ���������� �����Ͽ���.
// �̴� CList�� �̸��� �������� ����Ѵٴ� ���̴�.
// CUI�� ����ϱ� ���ؼ��� CList�� ���� �޾Ƽ� ����Ѵ�.

// aggregation ���谡 composition ���躸�� ���� ��찡 ����.
// �װ��� �ξ� ��ü������ ���信 �����ϱ� ����
// ���α׷��� ���� �ý���, ����� �������̽�, ���� �����ʹ� �и��ϴ°� ��Ģ�̴�.
// ���� �����״� �� �˾Ƶε���