#include <iostream>

using namespace std;

class CNode
{
private:
	char m_szName[32];			// 노드의 데이터
	CNode *pNext = nullptr;		// 다음 노드를 가리키는 포인터 변수
private:
	friend class CList;		// CList를 friend로 선언
public:
	explicit CNode(const char *pszName)
	{
		strcpy_s(m_szName, sizeof(m_szName), pszName);	// m_szName에 그 크기만큼 pszName을 복사한다.
	}
};

class CList
{
	CNode m_HeadNode;		// 스택에 헤드노드를 생성
public:
	CList() : m_HeadNode("Dummy Head") { }		// 생성자 호출하면 스택에 더미 헤드를 생성한다.
	~CList()
	{
		CNode *pNode = m_HeadNode.pNext;		// 노드를 가리키는 용도로 pNode 설정
		CNode *pDelete = nullptr;				// 삭제할 노드를 알리는 용도로 pDelete 설정

		while (pNode)		// pNode에 값이 존재한다면
		{
			pDelete = pNode;	// 노드를 사용하면 삭제할 것임을 알리기위해 pDelete가 pNode를 가리키게 한다. 
			pNode = pNode->pNext;		// 다음 노드를 찾기 위해 준비

			cout << pDelete->m_szName << endl;		// 여기서 중요.
			delete pDelete;				// 삭제할 노드를 삭제
		}

		m_HeadNode.pNext = nullptr;		// 마지막으로 남은 헤드노드가 아무것도 가리키지 않게 설정
	}

	void AddNewNode(const char *pszName)
	{
		CNode *pNode = new CNode(pszName);

		pNode->pNext = m_HeadNode.pNext;	// 새로운 노드가 가리키는 노드는 헤드노드가 가리키는 곳이다.
		m_HeadNode.pNext = pNode;		// 스택에 있는 헤드노드가 가리키는 노드는 새롭게 생성된 노드다.
	}
};

int main()
{
	CList list;			// 호출과 동시에 스택에 HeadNode가 생성
	list.AddNewNode("길동");
	list.AddNewNode("철수");
	list.AddNewNode("영희");

	return 0;
}

// 55번 줄
// 스택에 HeadNode를 생성한다.
// 여기서 HeadNode는 더미라는 것을 알려주며, 리스트의 시작 위치를 알려줄뿐 별 의미는 없다.
// 그리고 HeadNode의 포인터는 nullptr이다.

// 54 ~ 56번 줄
// 노드들을 하나씩 생성하는 작업을 하고있다.

// 41 ~ 47번 줄
// 새롭게 노드를 생성해내는 멤버변수의 정의이다.
// 실제 값을 집어넣어서 순서를 알아보자.
//
// 1. 길동이 들어오면 길동이라는 데이터를 가진 노드를 힙에 동적할당한다.
// 2. 동적할당된 길동노드의 포인터는 HeadNode의 포인터, 즉, nullptr로 설정한다.
// 3. HeadNode의 포인터는 새로 생성된 노드, 즉, 길동노드를 가리킨다.
// 4. 철수가 들어오면 철수라는 데이터를 가진 노드를 힙에 동적할당한다.
// 5. 동적할당된 철수노드의 포인터는 HeadNode의 포인터, 즉 길동을 가리키게 설정한다.
// 6. HeadNode의 포인터는 새로 생성된 노드, 즉, 철수노드를 가리킨다.
// 7. 영희도 같음.

// 24 ~ 39번 줄
// 노드 데이터를 출력하면서 노드를 삭제하는 소멸자의 정의이다.
//
// 1. 가리키는 용도로 pNode와 pDelete를 생성한다.
// 2. pNode는 HeadNode의 다음 노드 즉, 영희노드를 가리키게 한다.
// 3. pNode는 영희노드이며, 값이 존재하므로 삭제할 것을 알리는 뜻으로 pDelete가 pNode, 즉, 영희노드를 가리키게 한다.
// 4. pNode는 pNode의 다음 노드, 즉, 철수노드를 가리키게 한다.
// 5. pDelete의 값, 영희노드의 데이터 값을 출력하고 pDelete를 삭제하므로 영희노드를 없앤다. -> 매우 중요
// 6. pNode는 철수노드이며, 값이 존재하므로 삭제할 것을 알리는 뜻으로 pDelete가 pNode, 즉, 철수노드를 가리키게 한다.
// 7. pNode는 pNode의 다음 노드, 즉, 길동노드를 가리키게 한다.
// 8. pDelete의 값, 철수노드의 데이터 값을 출력하고 pDelete를 삭제하므로 철수노드를 없앤다.
// 9. 길동도 같음.

// 11번 줄
// 34번 줄과 같이 매우 중요한 문장이다.
// CNode안에 CList 클래스를 friend로 설정한 것.
// 한마디로 CList에서 CNode를 마음대로 휘저을 수 있게 해준다.
// 매우 위험한 발상아닌가?

// 34번 줄
// pDelete는 CNode 클래스형 변수다.
// 거기다 m_szName 멤버변수는 private로 설정이 되어 있다.
// CList 클래스에서 CNode의 private에 접근한 것.
// 상식적으로 private로 선언된 멤버변수에 다른 클래스가 접근하는 것은 말도 안된다.
// 하지만 CNode에서 CList를 friend로 선언하였으므로 CNode를 맘대로 접근할 수 있는 것이다.