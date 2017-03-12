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
	CList &m_list;			// 여기서 aggregation 관계를 나타낸다.
public:
	CUI(CList &rList) : m_list(rList) {}		// composition과 달리 생성자가 있다.
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
				cout << "이름 : ";
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
	//CUI ui;		// CUI의 생성자가 CList의 파라미터를 가지므로 그냥 생성이 불가능하다.
	CList list;		// 자료구조를 따로 생성하고
	CUI ui(list);	// UI객체를 별도로 선언하고 연결한다.
	ui.Run();		// 그래야 사용가능
}

// 102번 줄
// CUI의 생성자가 생겼다.
// 디폴트 생성자가 아닌 변환생성자가 존재하므로 그냥 생성은 못한다.

// 103, 104번 줄
// 자료구조를 따로 생성하고 UI객체를 별도로 선언하여 연결한다.
// CList와 CUI는 서로 별개로 생성하고 서로 연결한다는 것은 둘 중 하나가 없어져도 둘 중 하나는 유지가 된다는 뜻이다.
// 이것이 aggregation의 특징이다.

// 59, 61번 줄
// CList를 참조형으로 선언하였다.
// 이는 CList는 이름만 가져가서 사용한다는 뜻이다.
// CUI를 사용하기 위해서는 CList를 따로 받아서 사용한다.

// aggregation 관계가 composition 관계보다 좋은 경우가 많다.
// 그것이 훨씬 객체지향의 개념에 부합하기 때문
// 프로그램의 제어 시스템, 사용자 인터페이스, 원본 데이터는 분리하는게 원칙이다.
// 자주 쓰일테니 잘 알아두도록