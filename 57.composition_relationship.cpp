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
			cout << pNode->m_szName << endl;	// 노드의 데이터를 출력하고
			pNode = pNode->pNext;				// 다음 노드로 이동
		}
	}
};

class CUI
{
	CList m_list;			// 여기서 composition 관계를 나타낸다. 110번 줄에서 설명
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
	CUI ui;
	ui.Run();
}

// 99 ~ 103번 줄
// main()함수 안에 정의된 클래스만 사용하였다.
// 너무 간단하다.
// 이게 객체지향 프로그래밍으 장점이다.

// 59번 줄
// CUI의 멤버로 CList 클래스의 인스턴스가 선언되었다.
// 한 클래스 안에서 다른 클래스를 사용하는 것.
// 그것도 참조형이나 포인터형으로 사용하지 않았다.
// 그냥 클래스를 사용하겠다고 함으로써 CUI가 소멸하면서 CList도 같이 소멸하게 된다.
// 이게 composition 관계의 특성이다.

// 71 ~ 96번 줄
// 멤버함수인 Run()의 정의이다.
// 전형적인 이벤트형 반복문 형태를 취하고 있다.
// 76번 줄에서 사용자가 입력한 키보드 값을 확인하고 이 값이 무엇인가에 따라 적절한 기능이 작동한다.
// 21번 줄은 서로 연결되어 있는거라서 좀 애매하다.